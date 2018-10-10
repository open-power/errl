/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <utilstream.H>
#include <errlutility.H>
#include <cstring>
//#include <dlfcn.h>
#include <errlED.H>
#include <errlparser.H>
#include <errltoolutils.H>

/*****************************************************************************/
// Default constructor
/*****************************************************************************/
ErrlED::ErrlED(
    ErrlBase &	 i_parent
)
: ErrlSctn( ERRL_SID_EXT_USER_DEFINED, 0, 0, 0, 0, i_parent ), iv_Data( 0 ),
  iv_Size( 0 ),iv_CreatorSubSystem(ERRL_CID_SP),iv_Reserved1(0),iv_Reserved2(0),iv_Reserved3(0)
{
}

/*****************************************************************************/
// Copy-Constructor
/*****************************************************************************/
ErrlED::ErrlED(
    const ErrlED& i_right,
    ErrlBase &	  i_parent
)
: ErrlSctn( i_right, i_parent ), iv_Data( 0 ), iv_Size( 0 ),iv_CreatorSubSystem(ERRL_CID_SP),
  iv_Reserved1(0),iv_Reserved2(0),iv_Reserved3(0)
{
    iv_CreatorSubSystem = i_right.iv_CreatorSubSystem;
}

/*****************************************************************************/
// Data Import
/*****************************************************************************/
ErrlED::ErrlED(
    UtilStream & i_stream,
    ErrlSctnHdr &i_hdr,
    ErrlBase &	 i_parent
)
: ErrlSctn( i_stream, i_hdr, i_parent ), iv_Data( 0 ), iv_Size( 0 ),iv_CreatorSubSystem(ERRL_CID_SP),
  iv_Reserved1(0),iv_Reserved2(0),iv_Reserved3(0)
{
    // Read Creator Subsystem from the stream
    i_stream >> iv_CreatorSubSystem;
    // Move 3 Bytes(Reserved bytes)
    i_stream.seek(3,i_stream.CURRENT);
    // Determine size of extra data
    iv_Size = iv_header.iv_slen - iv_header.flatSize()-4;
    // Obtain memory
    iv_Data = (uint8_t*)realloc( iv_Data, iv_Size );

    // Copy from stream
    i_stream.read( iv_Data, iv_Size );

}
/*****************************************************************************/
// Virtual Copy-Constructor
/*****************************************************************************/
ErrlED *ErrlED::clone( ErrlBase & i_owner ) const
{
    return new(i_owner) ErrlED( *this, i_owner );
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlED::~ErrlED()
{
    free( iv_Data );
    iv_Data = 0;
}


/*****************************************************************************/
// Data Export size
/*****************************************************************************/
uint32_t ErrlED::flatSize() const
{
    uint32_t	l_rc = 0;

    l_rc = iv_header.flatSize() + iv_Size + sizeof(iv_CreatorSubSystem)
           + sizeof(iv_Reserved1) + sizeof(iv_Reserved2) + sizeof(iv_Reserved3);
    return l_rc;
}
/*****************************************************************************/
// User data parsing
/*****************************************************************************/
void ErrlED::print(
    ErrlParser & i_parser
)
{
    print(i_parser, *this);
}

/*****************************************************************************/
// User data parsing
/*****************************************************************************/


void ErrlED::print(
    ErrlParser & i_parser,
    ErrlED & i_obj
)
{
    // Locals
    bool    l_parsed = false;   // Parse success indicator

    // Print Header
    i_obj.iv_header.print( i_obj.flatSize(), i_parser );
    // Creator SubSystem
    errl::PrintCreatorSubSystem( i_parser, i_obj.iv_CreatorSubSystem );

    // Default behavior
    if ( l_parsed == false )
    {
        // Hex dump
        i_parser.PrintBlank();
        i_parser.PrintHexDump( i_obj.iv_Data, i_obj.iv_Size );
        i_parser.PrintBlank();
    }

    i_parser.PrintSectionEnd();

}

