/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcicallout.H>
#include <srcifruidentity.H>
#include <srcipce.H>
#include <srcimrusst.H>
#include <srcimru.H>
#include <utilstream.H>
#include <memory>
#include <utilheap.H>
#include <srcisrc.H>

#include <srciutility.H>
#include <errlutility.H>
#include <errlparser.H>
#include <srci_service_codes.H>

#include <string.h>


/*****************************************************************************/
// F O R W A R D S
/*****************************************************************************/
static void srciPrintFailingComponentType( ErrlParser & i_parser, uint8_t i_type );


HASH_ITEM_TABLE( Fct )
	{   SRCI_FCT_RESERVED,		    ERRL_MSG_RES_VAL_ERR    },
	{   SRCI_FCT_NORMAL_HW_FRU,	    ERRL_MSG_NORMAL_HW_FRU  },
	{   SRCI_FCT_CODE_FRU,		    ERRL_MSG_CODE_FRU	    },
	{   SRCI_FCT_CONFIG_ERR_PROC_REQ,   ERRL_MSG_CONFIG_ERR	    },
	{   SRCI_FCT_MAINTENANCE_PROC_REQ,  ERRL_MSG_MAINTENCE_PROC },
	{   SRCI_FCT_EXTERNAL_FRU,	    ERRL_MSG_EXT_FRU	    },
	{   SRCI_FCT_EXTERNAL_CODE_FRU,	    ERRL_MSG_EXT_CODE_FRU   },
	{   SRCI_FCT_TOOL_FRU,		    ERRL_MSG_TOOL_FRU	    },
	{   SRCI_FCT_SYMBOLIC_FRU,	    ERRL_MSG_SYMBOLIC_FRU   },
	{   SRCI_FCT_SYMBOLIC_FRU_WITH_LOC, ERRL_MSG_SYMB_FRU_LOC   }
HASH_TABLE_END( Fct )


/*****************************************************************************/
// Some friends of the header
/*****************************************************************************/

inline UtilStream & operator >> ( UtilStream & i_left, SrciCallout::header & i_right )
{
    return ( i_left >> i_right.iv_len >> i_right.iv_flags >> i_right.iv_priority >> i_right.iv_locCodeLen );
}



/*****************************************************************************/
// Copy-constructor
/*****************************************************************************/
SrciCallout::SrciCallout(
    const SrciCallout & i_right,
    ErrlBase &		i_parent
)
: ErrlBase( i_parent ),
  iv_hdr( i_right.iv_hdr ),
  iv_locCode( 0 ),
  iv_pFid( 0 ),
  iv_pPce( 0 ),
  iv_pMrus( 0 ),
  iv_type ( i_right.iv_type ),
  iv_oid ( i_right.iv_oid )
{
    if ( iv_hdr.iv_locCodeLen )
    {
	iv_locCode = (char*)realloc(iv_locCode, iv_hdr.iv_locCodeLen);
	memcpy( iv_locCode, i_right.iv_locCode, iv_hdr.iv_locCodeLen );
    }
    if ( i_right.iv_pFid )
    {
	iv_pFid = new(*this) SrciFruIdentity( *i_right.iv_pFid, *this );
    }
    if ( i_right.iv_pPce )
    {
	iv_pPce = new(*this) SrciPce( *i_right.iv_pPce, *this );
    }
    if ( i_right.iv_pMrus )
    {
	iv_pMrus = new(*this) SrciMruSst( *i_right.iv_pMrus, *this );
    }
}


/*****************************************************************************/
// Import constructor
/*****************************************************************************/
SrciCallout::SrciCallout(
    UtilStream &i_input,
    ErrlBase &	i_parent
)
: ErrlBase( i_parent ),
  iv_hdr(),
  iv_locCode( 0 ),
  iv_pFid( 0 ),
  iv_pPce( 0 ),
  iv_pMrus( 0 ),
  iv_type( HW_CALLOUT ),
  iv_oid ( StampObjectId() )
{
    unflatten( i_input );
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciCallout::~SrciCallout()
{
    Reset();
}


/*****************************************************************************/
// Export size
/*****************************************************************************/
uint32_t SrciCallout::flatSize() const
{
    uint32_t	l_rc = SRCI_FRU_BASELEN + iv_hdr.iv_locCodeLen;
    
    if ( iv_pFid )  l_rc += iv_pFid->flatSize();
    if ( iv_pPce )  l_rc += iv_pPce->flatSize();
    if ( iv_pMrus ) l_rc += iv_pMrus->flatSize();
    
    return l_rc;
}



/*****************************************************************************/
// Data Import
/*****************************************************************************/
void SrciCallout::unflatten(
    UtilStream &i_stream
)
{
    SrciSubSt::Header   l_sstHdr;
    uint32_t		l_erc = 0;

    Reset();
    
    // Re-Establish unique Id
    iv_oid = StampObjectId();

    // Load the header
    i_stream >> iv_hdr;

    // Convert the priority
    iv_hdr.iv_priority = srciPrioritize( iv_hdr.iv_priority );

    // Location code
    if ( iv_hdr.iv_locCodeLen )
    {
	iv_locCode = (char*)realloc( iv_locCode, iv_hdr.iv_locCodeLen );
	i_stream.read( iv_locCode, iv_hdr.iv_locCodeLen );
    }

    // Validate the header data
    if ( ( iv_hdr.iv_flags & 0xF0 ) != FRU_TYPE_2  )
    {
	l_erc = SRCI_ERC_INVALID;
    }
    else if ( iv_hdr.iv_len < sizeof(iv_hdr ) )
    {
	l_erc = SRCI_ERC_BAD_SIZE;
    }
    else
    {
	// Setup the consumption:
	// 1) Available bytes is equal to the header field minus the header size
	// 2) Consumed bytes is equal to the location code length ( since it's
	//    already been consumed )
	uint8_t	    l_avail = iv_hdr.iv_len - sizeof(iv_hdr);
	uint8_t	    l_consumed = iv_hdr.iv_locCodeLen;
	SrciSubSt * l_pSST = 0;

	while ( l_consumed < l_avail && i_stream.peekLastError() == false )
	{
	    // Read in the section identifier
	    l_sstHdr.unflatten( i_stream );
	    
	    if ( l_sstHdr.iv_sid == SrciSubSt::SST_FRU_IDENTITY )
	    {
                if(iv_pFid)
                {
                   delete iv_pFid;
                   iv_pFid = NULL;
                }

		l_pSST = iv_pFid = new(*this) SrciFruIdentity( i_stream, l_sstHdr, *this );
	    }
	    else if ( l_sstHdr.iv_sid == SrciSubSt::SST_FRU_PCE )
	    {
                if(iv_pPce)
                {
                    delete iv_pPce;
                    iv_pPce = NULL;
                }

		l_pSST = iv_pPce = new(*this) SrciPce( i_stream, l_sstHdr, *this );
	    }
	    else if ( l_sstHdr.iv_sid == SrciSubSt::SST_MRU )
	    {
                if(iv_pMrus)
                {
                    delete iv_pMrus;
                    iv_pMrus = NULL;
                }

		l_pSST = iv_pMrus = new(*this) SrciMruSst( i_stream, l_sstHdr, *this );
	    }
	    else
	    {
		l_erc = SRCI_ERC_BAD_ID;
		break;
	    }

	    // Accumulate the bytes consumed
	    l_consumed += l_pSST->flatSize();
	}
    }


    // Error checking
    if ( l_erc )
    {
	if ( ! l_erc )
	    l_erc = SRCI_ERC_STREAM;

    }
    else
    {
	// Adjust the type accordingly
	// Note: If the Callout has a location code it is considered
	//       a hardware callout; however, since the location code
	//       can be blank, we also check the part number field of
	//       the Fru Identity
	if ( iv_locCode || ( iv_pFid && iv_pFid->PartNumber() ) )
	{
	    iv_type = HW_CALLOUT;
	}
	else
	{
	    iv_type = PROC_CALLOUT;
	}
    }
}


/*****************************************************************************/
// Default part number
/*****************************************************************************/
const char *SrciCallout::PartNumber( void ) const
{
    return ( iv_pFid ? iv_pFid->PartNumber() : 0 );
}


/*****************************************************************************/
// Default ccin 
/*****************************************************************************/
const char *SrciCallout::ccin( void ) const
{
    return ( iv_pFid ? iv_pFid->ccin() : 0 );
}


/*****************************************************************************/
// Default serial number
/*****************************************************************************/
const char *SrciCallout::SerialNumber( void ) const
{
    return ( iv_pFid ? iv_pFid->SerialNumber() : 0 );
}



/*****************************************************************************/
// Object print
/*****************************************************************************/
void SrciCallout::print(
    ErrlParser & i_parser
    ) const
{
    
    srciPrintFailingComponentType( i_parser, iv_pFid ? iv_pFid->FailingCompType() : 0 );

    i_parser.PrintCalloutPriority( Priority() );

    if ( iv_locCode )	i_parser.PrintLocCode( iv_locCode );
    if ( iv_pFid )	iv_pFid->print( i_parser );
    if ( iv_pPce )	iv_pPce->print( i_parser );
    if ( iv_pMrus )	iv_pMrus->print( i_parser );
}





/*****************************************************************************/
// Priority greater than operator
/*****************************************************************************/
bool SrciCallout::operator>( const SrciCallout & i_right ) const
{
    uint8_t l_left = iv_hdr.iv_priority;
    uint8_t l_right = i_right.iv_hdr.iv_priority;

    if ( l_left > SRCI_PRIORITY_LOW && l_left < SRCI_PRIORITY_HIGH )
    {
	l_left = SRCI_PRIORITY_MED;
    }
    
    if ( l_right > SRCI_PRIORITY_LOW && l_right < SRCI_PRIORITY_HIGH )
    {
	l_right = SRCI_PRIORITY_MED;
    }

    return ( l_left > l_right );
}


/*****************************************************************************/
// Priority less than operator
/*****************************************************************************/
bool SrciCallout::operator<( const SrciCallout & i_right ) const
{
    uint8_t l_left = iv_hdr.iv_priority;
    uint8_t l_right = i_right.iv_hdr.iv_priority;

    if ( l_left > SRCI_PRIORITY_LOW && l_left < SRCI_PRIORITY_HIGH )
    {
	l_left = SRCI_PRIORITY_MED;
    }
    
    if ( l_right > SRCI_PRIORITY_LOW && l_right < SRCI_PRIORITY_HIGH )
    {
	l_right = SRCI_PRIORITY_MED;
    }

    return ( l_left < l_right );
}


/*****************************************************************************/
// Clear out all allocated resources
/*****************************************************************************/
inline void SrciCallout::Reset()
{
    free( iv_locCode );	    iv_locCode = 0; iv_hdr.iv_locCodeLen = 0;
    delete iv_pFid;	    iv_pFid = 0;
    delete iv_pPce;	    iv_pPce = 0;
    delete iv_pMrus;	    iv_pMrus = 0;
}


/*****************************************************************************/
// Print the failing component type
/*****************************************************************************/
void srciPrintFailingComponentType( ErrlParser & i_parser, uint8_t i_type )
{
    FctTableItem_t *l_pItem = 0;
    const char *    l_msg = 0;

    if ( ! i_type )
    {
	i_type = SRCI_FCT_NORMAL_HW_FRU;
    }

    l_pItem = errl::TableLookup( (uint32_t)i_type, FctTable, FctTableSz );

    if ( ! l_pItem )
    {
	char	l_tmp[64];
	snprintf( l_tmp, 64,"0x%02X - %s", i_type, i_parser.LoadMsg( ERRL_MSG_UNKNOWN_TYPE ) );
	l_tmp[63] = 0;
	l_msg = l_tmp;
    }
    else
    {
	l_msg = i_parser.LoadMsg( l_pItem->iv_Val );
    }
    
    i_parser.PrintHeading( l_msg );
}




/*****************************************************************************/
// Generate a unique object Id
/*****************************************************************************/
uint32_t SrciCallout::StampObjectId()
{
    static uint32_t l_oid = 0;

    return l_oid++;
}


