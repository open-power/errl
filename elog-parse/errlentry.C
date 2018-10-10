/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlentry.H>
#include <errlinternals.H>
#include <errlextduh.H>
#include <errlED.H>
#include <errlsrc.H>
#include <errlud.H>
#include <srcisrc.H>
#include <errl_service_codes.H>
#include <stdlib.h>
#include <utilmem.H>
#include <sys/vfs.h>    
#include <utilfile.H>
#include <srcicallout.H>
#include <signal.h>                     


#include <ctime>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <errlparser.H>
#include <errlusrparser.H>

#include <errltoolutils.H>


/*****************************************************************************/
// Defines
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/

/*****************************************************************************/
// Invalid object constructor
/*****************************************************************************/
ErrlEntry::ErrlEntry()
: ErrlBase( 0 ),
  iv_optionals( 0 ),
  iv_optCount( 0 ),
  iv_prisrc( 0 ),
  iv_prvt( 0 ),
  iv_usrhdr( 0 ),
  iv_logDeleted(false),
  iv_jedec(false),
  iv_hwCallout(false),
  iv_fwProcCallout(false),
  iv_extduh( 0 )
{
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlEntry::~ErrlEntry()
{
    
    // Cleanup
    delete iv_prvt;	iv_prvt = 0;
    delete iv_usrhdr;	iv_usrhdr = 0;
    delete iv_prisrc;   iv_prisrc = 0;
    delete iv_extduh;   iv_extduh = 0;

    // Optional Sections
    for( uint32_t i = 0; i < iv_optCount; i++ )
    {
	delete iv_optionals[i];
	iv_optionals[i] = 0;
    }

    free( iv_optionals );
    iv_optionals = 0;
    iv_logDeleted = true;
    iv_jedec = true;
    iv_hwCallout = true;
    iv_fwProcCallout = true;

}


uint32_t ErrlEntry::flattenedSize() const
{


    uint32_t    l_rc = 0;

    l_rc += iv_prvt->flatSize();
    l_rc += iv_usrhdr->flatSize();

    if ( iv_prisrc )
    {
        l_rc  += iv_prisrc->flatSize();
    }

    if ( iv_extduh )
    {
        l_rc += iv_extduh->flatSize();
    }

    for( uint32_t i = 0; i < iv_optCount; i++ )
    {
        l_rc += iv_optionals[i]->flatSize();
    }

    return l_rc;


}

/*****************************************************************************/
// Data Import
/*****************************************************************************/
errlstatus_t ErrlEntry::unflatten(
    UtilStream &i_stream,
    bool	i_commit
)
{
    // Locals
    ErrlSctn *	    l_p = 0;
    errlstatus_t    l_rc = ERRL_STATUS_SUCCESS;
    uint8_t	    i;


    // Clean out required
    delete iv_prisrc;	iv_prisrc = 0;
    delete iv_extduh;	iv_extduh = 0;

    // Release optionals
    for ( uint32_t i=0; i < iv_optCount; i++ )
    {
	delete iv_optionals[i];
    }
    
    free ( iv_optionals ); 
    iv_optionals = 0;
    iv_optCount = 0;

    if ( ! iv_prvt )
    {
	iv_prvt = new(*this) ErrlPrvt(i_stream, *this);
    }
    else
    {
	iv_prvt->unflatten( i_stream );
    }
    if ( ! iv_usrhdr )
    {
	iv_usrhdr= new(*this) ErrlUH(*this);
    }
    
    iv_usrhdr->unflatten( i_stream );


    for ( i = 2; i < iv_prvt->sections(); i++ )
    {
	l_p = ErrlSctn::Create( *this, i_stream );

	// Exit on error
	if ( ! l_p )
	{
	    break;
	}
	// Process section
	else
	{
	    if ( l_p->compId() == 0 )
	    {
		l_p->compId( iv_prvt->creator() );
	    }

	    if ( l_p->get_sid() == ERRL_SID_PRIMARY_SRC )
	    {
		if ( ! iv_prisrc )
		{
		    iv_prisrc = (ErrlSrc*)l_p;
		}
		else
		{
		    delete l_p;
		    l_p = 0;

		    l_rc = ERRL_STATUS_DUP_ENTRY;
		}
	    }
	    else if ( l_p->get_sid() == ERRL_SID_EXTENDED_HEADER )
	    {
                if ( ! iv_extduh )
                {
                    iv_extduh = (ErrlExtdUH*)l_p;
                }
                else
                {
                    delete l_p;
                    l_p = 0;
                                                                                
                    l_rc = ERRL_STATUS_DUP_ENTRY;
                }  
            }
            else
            {
		iv_optCount++;
		iv_optionals = (ErrlSctn**)realloc(
			iv_optionals, 
			iv_optCount * sizeof(iv_optionals) 
			);
		iv_optionals[iv_optCount-1] = l_p;
	    }
	}
    }
    
    
    // Handle failures
    if ( l_rc != ERRL_STATUS_SUCCESS  )
    {
	l_rc = ERRL_STATUS_CORRUPT;
    }

    return l_rc;

}



/*****************************************************************************/
// Read Platform Log Id
/*****************************************************************************/
uint32_t ErrlEntry::plid()
{
    return iv_prvt->plid();
}



/*****************************************************************************/
// Read Entry Id ( unique )
/*****************************************************************************/
uint32_t ErrlEntry::eid() const
{
    return iv_prvt->eid();
}


/*****************************************************************************/
// Obtain the creator subsystem identifier
/*****************************************************************************/
errlCreator ErrlEntry::creatorSubSys() const
{
    return iv_prvt->creatorSubSys();
}


void ErrlEntry::print( ErrlParser & i_parser, bool i_dispFull )             
{
    // Establish parent relationship
    i_parser.setParent( this );
   
    // Header
    i_parser.PrintDivider();
    i_parser.Begin( "%s - 0x%08X", i_parser.LoadMsg( ERRL_MSG_PEL_HDR ), eid() );
    
    // Private ( which includes divider above and below )
    iv_prvt->print( i_parser );

    i_parser.PrintNumber( "Total Log Size", "%d", flattenedSize() );
    i_parser.PrintSectionEnd();

    // User
    iv_usrhdr->print( i_parser );
    i_parser.PrintSectionEnd();

    // SRC
    if ( iv_prisrc )
    {
	iv_prisrc->print( i_parser );
    }

    // Extended User Header
    if ( iv_extduh )
    {
        iv_extduh->print( i_parser );
    }
    
    // Other
    for ( uint32_t i = 0; i < iv_optCount; i++ )
    {
        if (i_dispFull)                                                       
        {
            iv_optionals[i]->print( i_parser );
            i_parser.PrintSectionEnd();
        }
        else
        {
            if(!(iv_optionals[i]->compId()==ERRL_COMP_ID && (iv_optionals[i]->sst()==ERRL_UDT_TRACE || iv_optionals[i]->sst()==ERRL_UDT_HB_TRACE)  ))   
            {
                iv_optionals[i]->print( i_parser );
                i_parser.PrintSectionEnd();
            }                                                                   
        }
    }

    // Footer
         i_parser.End();
    
    
}


/*****************************************************************************/
// Number of user data sections
/*****************************************************************************/
errlidx_t ErrlEntry::usrDtlCount( void ) const
{

    errlidx_t	l_scount = 0;

    for( uint32_t i=0; i< iv_optCount; i++ )
    {
	if ( iv_optionals[i]->get_sid() == ERRL_SID_USER_DEFINED )
	{
	    l_scount++;

	}
    }

    return l_scount;
}


const void * ErrlEntry::getUsrDtls(
    errlslen_t &    o_len,
    comp_id_t	&   o_cid,
    errlsubsec_t &  o_sst,
    errlver_t    &  o_ver,
    errlidx_t	    i_idx
)
{
    const void * l_rc = 0;

    if ( i_idx == 0 )
    {
	// Look for last one
	i_idx = usrDtlCount();
    }

    for( uint32_t i=0; i< iv_optCount; i++ )
    {
	if ( iv_optionals[i]->get_sid() == ERRL_SID_USER_DEFINED )
	{
	    i_idx--;

	    if ( i_idx == 0 )
	    {
		ErrlUD *l_p = (ErrlUD*)iv_optionals[i];
		l_rc = l_p->data();
		o_len = l_p->dataSize();
		o_cid = l_p->compId();
		o_ver = l_p->version();
		o_sst = l_p->sst();
		break;
	    }
	}
    }

    return l_rc;
}
