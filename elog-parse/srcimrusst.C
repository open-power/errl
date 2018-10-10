/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcimrusst.H>
#include <srcimru.H>
#include <utilstream.H>
#include <cstring>
#include <srcisrc.H>

#include <srciutility.H>
#include <utilbase.H>
#include <cstdlib>
#include <errlparser.H>



/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
static int srciInvertedPrioritySort( const void * i_a, const void * i_b );
static int srciCreationSort( const void * i_a, const void * i_b );


/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/


/*****************************************************************************/
// Inverted priority sort
/*****************************************************************************/
int srciInvertedPrioritySort( const void * i_a, const void * i_b )
{
    const SrciMru &  l_a = **( const SrciMru ** )i_a;
    const SrciMru &  l_b = **( const SrciMru ** )i_b;

    return ( ( l_a < l_b ) - ( l_a > l_b ) );

}


/*****************************************************************************/
// Sort by creation
/*****************************************************************************/
int srciCreationSort( const void * i_a, const void * i_b )
{
    const SrciMru &  l_a = **( const SrciMru ** )i_a;
    const SrciMru &  l_b = **( const SrciMru ** )i_b;

    return ( ( l_a.ObjectId() > l_b.ObjectId() ) - ( l_a.ObjectId() < l_b.ObjectId() ) );

}



/*****************************************************************************/
// Constructor
/*****************************************************************************/
SrciMruSst::SrciMruSst(
    ErrlBase &	i_parent
)
: SrciSubSt( SST_MRU, i_parent ),
  iv_count( 0 ),
  iv_reserved( 0 )
{
    // Clear out the array
    memset( iv_mrus, 0, SRCI_MAXIMUM_MRU_COUNT );
}



/*****************************************************************************/
// Copy-Constructor
/*****************************************************************************/
SrciMruSst::SrciMruSst(
    const SrciMruSst &	i_right,
    ErrlBase &		i_parent
)
: SrciSubSt( SST_MRU, i_parent ),
  iv_count( i_right.iv_count ),
  iv_reserved( i_right.iv_reserved )
{
    // Clear out the array
    memset( iv_mrus, 0, SRCI_MAXIMUM_MRU_COUNT );

    // Copy the mrus
    for ( srciIdx_t i = 0; i < iv_count; i++ )
    {
	iv_mrus[i] = new(*this) SrciMru( *i_right.iv_mrus[i], *this );
    }
}



/*****************************************************************************/
// Import-constructor
/*****************************************************************************/
SrciMruSst::SrciMruSst(
    UtilStream &    i_input,
    const Header &  i_hdr,
    ErrlBase &	    i_parent
)
: SrciSubSt( i_input, i_hdr, i_parent ),
  iv_count( 0 ),
  iv_reserved( 0 )
{
    iv_count = UTIL_GET_NIBBLE( iv_header.iv_flags, 0 );

    i_input >> iv_reserved;
    
    if ( iv_count )
    {
	// Locals
	SrciMru	l_mru( SRCI_PRIORITY_LOW, 0, *this );

	for ( srciIdx_t i = 0; i < iv_count; i++ )
	{
	    // Unflatten
	    l_mru.unflatten( i_input );

	    // Copy
	    iv_mrus[i] = new(*this) SrciMru( l_mru, *this );

	}
    }
}



/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciMruSst::~SrciMruSst()
{
    // Delete all the mrus
    for ( srciIdx_t i = 0; i < iv_count; i++ )
    {
	delete iv_mrus[i];
	iv_mrus[i] = 0;
    }
}



/*****************************************************************************/
// Data Export Size
/*****************************************************************************/
uint32_t SrciMruSst::flatSize() const
{
    uint32_t l_rc = 0;

    l_rc = iv_header.flatSize();

    l_rc += sizeof(iv_reserved);
    
    for ( srciIdx_t i = 0; i < iv_count; i++ )
    {
	l_rc += iv_mrus[i]->flatSize();
    }

    return l_rc;
}


/*****************************************************************************/
// Class print
/*****************************************************************************/
void SrciMruSst::print(
    ErrlParser & i_parser
    ) const
{
    if ( iv_count == 0 )
    {
	return;
    }

    // 1. Create a local copy of the vector so we don't disturb the original
    srciIdx_t	l_count = iv_count;
     //rjk aix.nfp
    SrciMru **l_vector = new SrciMru * [ l_count ];

    memcpy( l_vector, iv_mrus, l_count * sizeof( SrciMru * ) );

    // 2. Sort the local vector by object Id ( creation )
    qsort( l_vector, l_count, sizeof( SrciMru * ), srciCreationSort );
    
    // 3. Sort the vector in reverse priority order
    qsort( l_vector, l_count, sizeof( SrciMru * ), srciInvertedPrioritySort );
    
    // 4. Print them out in reverse order
    for ( srciIdx_t i = 0; i < l_count; i++ )
    {
	l_vector[i]->print( i_parser );
    }
    delete [] l_vector; //rjk aix.nfp
}




