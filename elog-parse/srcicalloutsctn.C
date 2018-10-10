/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcisrc.H>
#include <srciutility.H>
#include <srci_service_codes.H>
#include <srcicalloutsctn.H>

#include <errlentry.H>
#include <errlparser.H>
#include <srci_service_codes.H>
#include <srcicallout.H>

#include <cstring>
#include <cstdlib>


/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
static int srciInvertedPrioritySort( const void * i_a, const void * i_b );
static int srciCreationSort( const void * i_a, const void * i_b );



/*****************************************************************************/
// Inverted priority sort
/*****************************************************************************/
int srciInvertedPrioritySort( const void * i_a, const void * i_b )
{
    const SrciCallout &  l_a = **( const SrciCallout ** )i_a;
    const SrciCallout &  l_b = **( const SrciCallout ** )i_b;

    return ( ( l_a < l_b ) - ( l_a > l_b ) );

}



/*****************************************************************************/
// Sort by creation
/*****************************************************************************/
int srciCreationSort( const void * i_a, const void * i_b )
{
    const SrciCallout &  l_a = **( const SrciCallout ** )i_a;
    const SrciCallout &  l_b = **( const SrciCallout ** )i_b;

    return ( ( l_a.ObjectId() > l_b.ObjectId() ) - ( l_a.ObjectId() < l_b.ObjectId() ) );

}



/*****************************************************************************/
// Copy constructor
/*****************************************************************************/
SrciCalloutSctn::SrciCalloutSctn(
    const SrciCalloutSctn & i_right,
    ErrlBase &		    i_parent
)
: ErrlBase( i_parent ),
  iv_header( i_right.iv_header ),
  iv_callout( 0 ),
  iv_count( i_right.iv_count )
{
    if ( iv_count )
    {
	iv_callout = (SrciCallout**)realloc( iv_callout, iv_count * sizeof(iv_callout) );

	for ( srciIdx_t i = 0; i < iv_count; i++ )
	{
	    iv_callout[i] = new(*this) SrciCallout( *i_right.iv_callout[i], *this );
	}
    }
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciCalloutSctn::~SrciCalloutSctn()
{
    Reset();
}



/*****************************************************************************/
// Import
/*****************************************************************************/
void SrciCalloutSctn::unflatten(
    UtilStream &i_stream
)
{
    // Locals
    uint32_t	    l_available;
    uint32_t	    l_consumed = 0;
    SrciCallout *   l_pCout = 0;
    uint32_t	    l_erc = 0;


    // Clean out
    Reset();

    // Retrieve the header
    iv_header.unflatten( i_stream );

    // Get the length
    l_available = iv_header.WordCount() * 4;

    if ( iv_header.SectionType() != iv_header.CALLOUT_SCTN )     /*constant condition*/
    {
	l_erc = SRCI_ERC_INVALID;
    }
    else if ( l_available > iv_header.flatSize() )
    {
	l_available -= iv_header.flatSize();

	// Pick up Callouts
	while ( l_consumed < l_available && i_stream.peekLastError() == false  )
	{
	    l_pCout = new(*this) SrciCallout( i_stream, *this );
	    Append( *l_pCout );
	    l_consumed += l_pCout->flatSize();

	}
    }
    else
    {
	l_erc = SRCI_ERC_BAD_SIZE;
    }



    if ( l_erc )
    {
//	if ( ! l_erc )
	    l_erc = SRCI_ERC_STREAM;


    }
}


/*****************************************************************************/
// Object flat size
/*****************************************************************************/
uint32_t SrciCalloutSctn::flatSize() const
{
    uint32_t l_rc = 0;

    l_rc = iv_header.flatSize();

    for ( srciIdx_t i = 0; i < iv_count; i++ )
    {
	l_rc += iv_callout[i]->flatSize();
    }

    return l_rc;

}



/*****************************************************************************/
// Object print
/*****************************************************************************/
void SrciCalloutSctn::print(
    ErrlParser & i_parser
) const
{
    if ( iv_count == 0 )
    {
	return;
    }

    // 1. Create a local copy of the vector so we don't disturb the original
    srciIdx_t	    l_count = iv_count;
    SrciCallout **   l_vector = new SrciCallout * [l_count];

    memcpy( l_vector, iv_callout, l_count * sizeof( SrciCallout * ) );

    // 2. Sort the local vector by object Id ( creation )
    qsort( l_vector, l_count, sizeof( SrciCallout * ), srciCreationSort );

    // 3. Sort the vector in reverse priority order
    qsort( l_vector, l_count, sizeof( SrciCallout * ), srciInvertedPrioritySort );

    // 4. Print out the generic section information
    iv_header.print( i_parser );

    // 5. Print the count
    i_parser.PrintCalloutCnt( l_count );

    // 6. Print the Callouts from highest to lowest
    for ( srciIdx_t i = 0; i < l_count; i++ )
    {
	i_parser.PrintBlank();
	l_vector[i]->print( i_parser );
	i_parser.PrintSectionEnd( true );
    }
    delete [] l_vector;
}


/*****************************************************************************/
// Reset the section
/*****************************************************************************/
inline void SrciCalloutSctn::Reset()
{
    for ( srciIdx_t i = 0; i < iv_count; i++ )
    {
	delete iv_callout[i];
    }
    free( iv_callout );
    iv_callout = 0;
    iv_count = 0;
}


/*****************************************************************************/
// Append a callout to the section
/*****************************************************************************/
inline void SrciCalloutSctn::Append(
    SrciCallout & i_cout
)
{
    iv_callout = (SrciCallout**)realloc( iv_callout, ++iv_count * sizeof(iv_callout) );
    iv_callout[iv_count-1] = &i_cout;
}



