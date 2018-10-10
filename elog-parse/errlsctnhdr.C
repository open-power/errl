/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <cstdio>
#include <errlsctnhdr.H>
#include <utilstream.H>
#include <errlbase.H>
#include <cstring>
#include <errl_service_codes.H>

#include <errlparser.H>
#include <errltoolutils.H>

/*****************************************************************************/
// Default Constructor
/*****************************************************************************/
ErrlSctnHdr::ErrlSctnHdr()
: iv_sid( 0 ), iv_slen( 0 ), iv_ver( 0 ), iv_sst( 0 ), iv_compId( 0 )
{
}



/*****************************************************************************/
// Section Constructor
/*****************************************************************************/
ErrlSctnHdr::ErrlSctnHdr(
    errlSectionId i_sid, 
    errlslen_t i_slen, 
    errlver_t i_ver, 
    errlsubsec_t i_sst, 
    comp_id_t i_cid
)
: iv_sid( i_sid ),
  iv_slen( i_slen ), 
  iv_ver( i_ver ), 
  iv_sst( i_sst ), 
  iv_compId( i_cid )
{
}


/*****************************************************************************/
// Data Import
/*****************************************************************************/
void ErrlSctnHdr::unflatten(
    UtilStream &i_stream
)
{
    errlHndl_t	l_hndl = 0;
    uint32_t	l_ssize = 0;
    uint32_t	l_minsz = flatSize() + 4;
    
    i_stream >> iv_sid >> iv_slen >> iv_ver >> iv_sst >> iv_compId;
    
    l_ssize = i_stream.size() - i_stream.seek( 0, i_stream.CURRENT );

    // Impossible:
    // 0) Remaining buffer size is zero
    // 1) Section length is smaller than the header size + 4  bytes of data
    // 2) Data length is bigger than the remaining buffer size
    if ( ! l_ssize || iv_slen < l_minsz || ( iv_slen - flatSize() ) > l_ssize )
    {
	
	l_hndl = i_stream.getLastError();

	i_stream.setLastError( l_hndl );
    
    }
}



void ErrlSctnHdr::print(
    uint32_t	i_slen,
    ErrlParser &i_parser
)
{
    // Locals
    const char * l_label = "Created by";

    // Update the section length
    iv_slen = i_slen;

    // Adjust label
    if ( iv_sid == ERRL_SID_USER_HEADER )
	l_label = "Log Committed by";

    errl::PrintSectionHeader( i_parser, iv_sid );
    i_parser.PrintNumber("Section Version", "%i", iv_ver );
    i_parser.PrintNumber("Sub-section type", "%i", iv_sst );
    errl::PrintCompName( i_parser, l_label, iv_compId );  
}



