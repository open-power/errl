/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <nfptypes.H>
#include <srcisubst.H>
#include <utilstream.H>
#include <srciutility.H>


/*****************************************************************************/
// Substructure header: default constructor
/*****************************************************************************/
SrciSubSt::Header::Header()
: iv_sid( 0 ), iv_len( 0 ),iv_flags( 0 )
{
}

/*****************************************************************************/
// Substructure header: constructor
/*****************************************************************************/
SrciSubSt::Header::Header( SSType i_type )
: iv_sid( i_type ), iv_len( 0 ),iv_flags( 0 )
{
}

/*****************************************************************************/
// Substructure header: copy-constructor
/*****************************************************************************/
SrciSubSt::Header::Header( const Header & i_right )
: iv_sid( i_right.iv_sid ), 
  iv_len( i_right.iv_len ),
  iv_flags( i_right.iv_flags )
{
}



/*****************************************************************************/
// Header import
/*****************************************************************************/
void SrciSubSt::Header::unflatten(
    UtilStream &i_stream
)
{
    i_stream >> iv_sid >> iv_len >> iv_flags;
}


/*****************************************************************************/
// Substructure constructor
// Invariant: Section Id
/*****************************************************************************/
SrciSubSt::SrciSubSt(
    SSType	i_type,
    ErrlBase &  i_parent
)
: ErrlBase( i_parent ),
  iv_header( i_type )
{
}


/*****************************************************************************/
// copy-constructor
/*****************************************************************************/
SrciSubSt::SrciSubSt(
    const SrciSubSt &	i_right,
    ErrlBase &		i_parent
)
: ErrlBase( i_parent ),
  iv_header( i_right.iv_header )
{
}



/*****************************************************************************/
// Import Constructor
/*****************************************************************************/
SrciSubSt::SrciSubSt(
    UtilStream &    i_input,
    const Header &  i_hdr,
    ErrlBase &	    i_parent
)
: ErrlBase( i_parent ),
  iv_header( i_hdr )
{
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciSubSt::~SrciSubSt()
{
}


