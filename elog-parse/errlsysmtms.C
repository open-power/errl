/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlsysmtms.H>
#include <utilstream.H>
#include <errlutility.H>
#include <errlbase.H>

/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/
const errlver_t	    ERRL_SYSMTMS_VER	= 1;
const errlsubsec_t  ERRL_SYSMTMS_SST	= 0;

/*****************************************************************************/
// Import-constructor
/*****************************************************************************/
ErrlSysMtms::ErrlSysMtms(
    UtilStream & i_stream,
    ErrlSctnHdr &i_hdr,
    ErrlBase &	 i_parent
)
: ErrlSctn( i_stream, i_hdr, i_parent ),
  iv_mtms( i_stream )
{
}


/*****************************************************************************/
// Copy-constructor
/*****************************************************************************/
ErrlSysMtms::ErrlSysMtms(
    const ErrlSysMtms & i_right,
    ErrlBase &          i_parent
)
: ErrlSctn( i_right, i_parent ),
  iv_mtms( i_right.iv_mtms )
{
}

/*****************************************************************************/
// Virtual copy-constructor
/*****************************************************************************/
ErrlSysMtms *ErrlSysMtms::clone( ErrlBase & i_owner ) const
{
    return new(i_owner) ErrlSysMtms( *this, i_owner );
}


/*****************************************************************************/
// Export data size
/*****************************************************************************/
uint32_t ErrlSysMtms::flatSize() const
{
    uint32_t l_rc;

    l_rc = iv_header.flatSize() + iv_mtms.flatSize();

    return l_rc;
}

/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlSysMtms::~ErrlSysMtms()
{
}

/*****************************************************************************/
// Object print
/*****************************************************************************/
void ErrlSysMtms::print(
    ErrlParser & i_parser
)
{
    print( i_parser, *this );
}
    

