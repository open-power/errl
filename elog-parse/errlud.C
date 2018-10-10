/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlud.H>
#include <utilstream.H>
#include <cstring>
#include <dlfcn.h>

#include <errlparser.H>


/*****************************************************************************/
// Default constructor
/*****************************************************************************/
ErrlUD::ErrlUD(
    ErrlBase &	 i_parent
)
: ErrlSctn( ERRL_SID_USER_DEFINED, 0, 0, 0, 0, i_parent ), iv_Data( 0 ),
  iv_Size( 0 )
{
}


/*****************************************************************************/
// Data Import
/*****************************************************************************/
ErrlUD::ErrlUD(
    UtilStream & i_stream,
    ErrlSctnHdr &i_hdr,
    ErrlBase &	 i_parent
)
: ErrlSctn( i_stream, i_hdr, i_parent ), iv_Data( 0 ), iv_Size( 0 )
{

    // Determine size of extra data
    iv_Size = iv_header.iv_slen - iv_header.flatSize();
    
    // Obtain memory
    iv_Data = (uint8_t*)realloc( iv_Data, iv_Size );

    // Copy from stream
    i_stream.read( iv_Data, iv_Size );

//    printf("UD section size : %d\n",iv_Size);
}



/*****************************************************************************/
// Copy-Constructor
/*****************************************************************************/
ErrlUD::ErrlUD(
    const ErrlUD& i_right,
    ErrlBase &	  i_parent
)
: ErrlSctn( i_right, i_parent ), iv_Data( 0 ), iv_Size( 0 )
{
}


/*****************************************************************************/
// Virtual Copy-Constructor
/*****************************************************************************/
ErrlUD *ErrlUD::clone( ErrlBase & i_owner ) const
{
    return new(i_owner) ErrlUD( *this, i_owner );
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlUD::~ErrlUD()
{
    free( iv_Data );
    iv_Data = 0;
}



/*****************************************************************************/
// Data Export size
/*****************************************************************************/
uint32_t ErrlUD::flatSize() const
{
    uint32_t	l_rc = 0;

    l_rc = iv_header.flatSize() + iv_Size;

    return l_rc;
}

/*****************************************************************************/
// User data parsing
/*****************************************************************************/
void ErrlUD::print(
    ErrlParser & i_parser
)
{
    print(i_parser, *this);
}

