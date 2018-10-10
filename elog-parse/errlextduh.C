/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/


#include <stdint.h>
#include <cstring>
#include <memory>
#include <errl_service_codes.H>
#include <utilstream.H>
#include <utilbase.H>

#include <errlextduh.H>
#include <errlentry.H>
#include <srcisrc.H>
#include <errlbase.H>
#include <stdlib.h>
#include <stdio.h>


#include <errlparser.H>

#include <utilfile.H>
#include <utilbase.H>
#include <utilheap.H>


/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/
const errlver_t     ERRL_EXTDUH_VER     = 1;
const errlsubsec_t  ERRL_EXTDUH_SST     = 0;
const errlslen_t    ERRL_EXTDUH_SLEN    = 68;


/*****************************************************************************/
// Import-constructor
/*****************************************************************************/
ErrlExtdUH::ErrlExtdUH(
    UtilStream & i_stream,
    ErrlSctnHdr &i_hdr,
    ErrlBase &   i_parent
)
: ErrlSctn( i_stream, i_hdr, i_parent ),
  iv_mtms(0,0),
  iv_reserved0(0),
  iv_commnreftime(),
  iv_reserved1(0),
  iv_reserved2(0),
  iv_symidlen(0)
{
    unflatten(i_stream );

}

ErrlExtdUH *ErrlExtdUH::clone( ErrlBase & i_owner ) const
{
//    return new(i_owner) ErrlExtdUH( *this, i_owner );  //smtodo1
    void *l_temp = NULL;

    return (ErrlExtdUH *)l_temp;
}



/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlExtdUH::~ErrlExtdUH()
{
}

/*****************************************************************************/
// Export data size
/*****************************************************************************/
uint32_t ErrlExtdUH::flatSize() const
{
    uint32_t l_rc = 0;
    
    l_rc = iv_header.flatSize() + ERRL_EXTDUH_SLEN + iv_symidlen;
    return l_rc;
}



/*****************************************************************************/
// Data import
/*****************************************************************************/
void ErrlExtdUH::unflatten(
    UtilStream &i_stream
 )
{
    //iv_header.unflatten( i_stream );
    iv_mtms.unflatten(i_stream);
    i_stream.read(iv_FwReleasedVer, ERRL_VER_LEN );
    i_stream.read(iv_FwSubSysDrvVer, ERRL_VER_LEN );
    i_stream >> iv_reserved0 >> iv_commnreftime >> iv_reserved1 >> iv_reserved2 >> iv_symidlen;
    if(iv_symidlen <= ERRL_SYMPID_LEN)
    {
        i_stream.read(iv_symid, iv_symidlen);
        Validate( i_stream );
        iv_symid[iv_symidlen] = 0;
    }
    iv_FwReleasedVer[ERRL_VER_LEN] = 0;
    iv_FwSubSysDrvVer[ERRL_VER_LEN] = 0;
}


/*****************************************************************************/
// Object print
/*****************************************************************************/
void ErrlExtdUH::print(
ErrlParser & i_parser
)
{
    print( i_parser, *this );
}

void ErrlExtdUH::print(
    ErrlParser &i_parser,
    ErrlExtdUH &i_obj
)
{
    bool flag = true;
    i_obj.iv_header.print( i_obj.flatSize(), i_parser );
    i_obj.iv_mtms.print( i_parser, flag );
    i_parser.PrintString( "FW Released Ver",i_obj.iv_FwReleasedVer);
    i_parser.PrintString( "FW SubSys Version",i_obj.iv_FwSubSysDrvVer);
    i_parser.PrintTimeStamp( "Common Ref Time", i_obj.iv_commnreftime );
    i_parser.PrintNumber( "Symptom Id Len", "%d",i_obj.iv_symidlen);
    i_parser.PrintString( "Symptom Id",i_obj.iv_symid);

}


/*****************************************************************************/
// Check the import data for validity
/*****************************************************************************/
void ErrlExtdUH::Validate(
    UtilStream &    i_stream
)
{
    errlHndl_t	l_hndl = 0;
    
    if (  iv_header.iv_sid   !=  ERRL_SID_EXTENDED_HEADER ||
          iv_header.iv_ver  != ERRL_EXTDUH_VER )
    {
       l_hndl = i_stream.getLastError(); 
    }
}
    

