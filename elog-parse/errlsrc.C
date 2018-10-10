/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlsrc.H>
#include <utilstream.H>
#include <errlparser.H>
#include <srcicallout.H>
#include <srcicalloutsctn.H>

#include <sys/types.h>
#include <unistd.h>
#include <dlfcn.h>
#include <cstring>


/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/
const errlver_t ERRL_SRC_VER = 1;
const errlsubsec_t ERRL_SRC_SST = 1;


/*****************************************************************************/
// Data Import
/*****************************************************************************/
ErrlSrc::ErrlSrc(
    UtilStream & i_stream,
    ErrlSctnHdr &i_hdr,
    ErrlBase &	 i_parent
)
: ErrlSctn( i_stream, i_hdr, i_parent ),
  iv_src( 0 )
{
    iv_src = new(*this) SrciSrc( i_parent );
    iv_src->unflatten( i_stream );
}


/*****************************************************************************/
// Copy-constructor
/*****************************************************************************/
ErrlSrc::ErrlSrc(
    const ErrlSrc&  i_right,
    ErrlBase &	    i_parent
)
: ErrlSctn( i_right, i_parent )
{
    // Copy the src
    iv_src = new(*this) SrciSrc( *i_right.iv_src, i_parent );
}



/*****************************************************************************/
// Virtual copy-constructor
/*****************************************************************************/
ErrlSrc *ErrlSrc::clone( ErrlBase & i_owner ) const
{
    return new(i_owner) ErrlSrc( *this, i_owner );
}



/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlSrc::~ErrlSrc()
{
    delete iv_src;
    iv_src = 0;
}



/*****************************************************************************/
// Export size
/*****************************************************************************/
uint32_t ErrlSrc::flatSize() const
{
    uint32_t	l_rc = 0;

    l_rc = iv_header.flatSize() + iv_src->flattenedSize();

    return l_rc;
}

/*****************************************************************************/
// Object parse
/*****************************************************************************/
void ErrlSrc::print(
    ErrlParser & i_parser
)
{
    print(i_parser, *this);
}


/*****************************************************************************/
// Object parse
/*****************************************************************************/
 

