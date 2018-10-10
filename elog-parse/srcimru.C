/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcimru.H>
#include <utilstream.H>
#include <cstring>
#include <srcisrc.H>

#include <srciutility.H>
#include <errlparser.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
extern srciPriority srciPrioritize( uint8_t i_priority );
extern uint8_t srciPrioritize( srciPriority i_priority );


/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/


/*****************************************************************************/
// Constructor
/*****************************************************************************/
SrciMru::SrciMru(
    srciPriority i_priority,
    uint32_t	 i_mruId,
    ErrlBase &	 i_parent
)
: ErrlBase( i_parent ),
  iv_reserved0( 0 ),
  iv_reserved1( 0 ),
  iv_reserved2( 0 ), 
  iv_priority( i_priority ),
  iv_mruId( i_mruId ),
  iv_oid ( StampObjectId() )
{
}

/*****************************************************************************/
// Copy-Constructor
/*****************************************************************************/
SrciMru::SrciMru(
    const SrciMru & i_right,
    ErrlBase &	    i_parent
)
: ErrlBase( i_parent ),
  iv_reserved0( i_right.iv_reserved0 ),
  iv_reserved1( i_right.iv_reserved1 ), 
  iv_reserved2( i_right.iv_reserved2 ),
  iv_priority( i_right.iv_priority ), 
  iv_mruId( i_right.iv_mruId ),
  iv_oid ( i_right.iv_oid )
{
}

/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciMru::~SrciMru()
{
}


/*****************************************************************************/
// Data Import
/*****************************************************************************/
void SrciMru::unflatten(
    UtilStream &i_stream
)
{
    uint8_t l_tmp;

    i_stream >> iv_reserved0 >> iv_reserved1 >> iv_reserved2;
    i_stream >> l_tmp >> iv_mruId;

    // Convert priority
    iv_priority = srciPrioritize( l_tmp );
  
    // Re-Establish unique Id
    iv_oid = StampObjectId();
}


/*****************************************************************************/
// Class print
/*****************************************************************************/
void SrciMru::print(
    ErrlParser & i_parser
    ) const
{
}


/*****************************************************************************/
// MRU comparison based on priority
/*****************************************************************************/
bool SrciMru::operator>( const SrciMru & i_right ) const
{
    uint8_t l_left = iv_priority;
    uint8_t l_right = i_right.iv_priority;

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
// MRU comparison based on priority
/*****************************************************************************/
bool SrciMru::operator<( const SrciMru & i_right ) const
{
    uint8_t l_left = iv_priority;
    uint8_t l_right = i_right.iv_priority;

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
// Generate a unique object Id
/*****************************************************************************/
uint32_t SrciMru::StampObjectId()
{
    static uint32_t l_oid = 0;

    return l_oid++;
}




