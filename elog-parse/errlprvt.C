/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlprvt.H>
#include <cstring>
#include <memory>
#include <errl_service_codes.H>
#include <utilstream.H>
#include <utilbase.H>

#include <errlparser.H>
#include <errltoolutils.H>




/*****************************************************************************/
// Import constructor
/*****************************************************************************/
ErrlPrvt::ErrlPrvt(
    UtilStream & i_stream,
    ErrlBase &   i_parent
)
: ErrlBase( i_parent ),
  iv_header( (errlSectionId)0, 0, 0, 0, 0 ),
  iv_created(),
  iv_committed(),
  iv_cid( 0 ),
  iv_reserved0( 0 ),
  iv_commitflag( false ),
  iv_sctns( 0 ),
  iv_reserved1( 0 ),
  iv_plid( 0 ),
  iv_eid( 0 )
{
    // Clear out arrays
    memset( iv_cssver, 0, CSS_VER );

    // Read the data in
    unflatten( i_stream );
}



/*****************************************************************************/
// Data import
/*****************************************************************************/
void ErrlPrvt::unflatten(
    UtilStream &i_stream
)
{
    iv_header.unflatten( i_stream );
 
    i_stream >> iv_created >> iv_committed  >> iv_cid >> iv_reserved0;
    i_stream >> iv_commitflag >> iv_sctns >> iv_reserved1 >> iv_cssver;
    i_stream >> iv_plid >> iv_eid;

    Validate( i_stream );
}



/*****************************************************************************/
// Check the import data for validity
/*****************************************************************************/
void ErrlPrvt::Validate(
    UtilStream &    i_stream
)
{
    errlHndl_t	l_hndl = 0;

    if ( iv_header.iv_sid != ERRL_SID_PRIVATE_HEADER ||
         iv_header.iv_ver !=  VER ||
         iv_sctns <  MIN_SCTN_CNT
       )
    {
	l_hndl = i_stream.getLastError();

	i_stream.setLastError( l_hndl );
    }
}






/*****************************************************************************/
// Object parse
/*****************************************************************************/

void ErrlPrvt::print(
    ErrlParser & i_parser
) 
{
    // Print the header
    iv_header.print( flatSize(), i_parser );

    // Created timestamp
    i_parser.PrintTimeStamp( "Created at", iv_created );
    
    // Committed timestamp
    i_parser.PrintTimeStamp( "Committed at", iv_committed ); 

    // Creator SubSystem
    errl::PrintCreatorSubSystem( i_parser, iv_cid );

    i_parser.PrintString("CSSVER", (char *)iv_cssver );
    i_parser.PrintNumber("Platform Log Id", "0x%08X", iv_plid ); 
    i_parser.PrintNumber("Entry Id", "0x%08X", iv_eid ); 
}


