/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srci.H>
#include <srcipce.H>
#include <cstring>
#include <memory>
#include <utilstream.H>
#include <utilheap.H>
#include <errlutility.H>
#include <srciutility.H>
#include <srcisrc.H>

#include <errlparser.H>


/*****************************************************************************/
// Constructor
/*****************************************************************************/
SrciPce::SrciPce(
    const char *    i_name,
    const ErrlMTMS &i_mtms,
    ErrlBase &	    i_parent
)
: SrciSubSt( SrciSubSt::SST_FRU_PCE, i_parent),
  iv_name( 0 ),
  iv_size( 0 ),
  iv_mtms( i_mtms )
{
    Name( i_name );
}


/*****************************************************************************/
// Copy-constructor
/*****************************************************************************/
SrciPce::SrciPce(
    const SrciPce & i_right,
    ErrlBase &	    i_parent
)
: SrciSubSt( i_right, i_parent ),
  iv_name( 0 ),
  iv_size( i_right.iv_size ),
  iv_mtms( i_right.iv_mtms )
{
    if(i_right.iv_size > 0)
    {
        iv_name = (char*)realloc( iv_name, iv_size );
        memcpy( iv_name, i_right.iv_name, iv_size );
    }
}


/*****************************************************************************/
// Import-constructor
/*****************************************************************************/
SrciPce::SrciPce(
    UtilStream &   i_input,
    const Header & i_hdr,
    ErrlBase &	   i_parent
)
: SrciSubSt( i_input, i_hdr, i_parent ),
  iv_name( 0 ),
  iv_size( 0 ),
  iv_mtms( 0, 0 )
{
    // Read the MTMS
    iv_mtms.unflatten( i_input );

    // Determine string length
    iv_size = iv_header.iv_len - iv_header.flatSize() - iv_mtms.flatSize();

    if ( iv_size )
    {
	// Obtain memory
	iv_name = (char*)realloc( iv_name, iv_size );

	// Read the data
	i_input.read( iv_name, iv_size );

	// Just in case
	iv_name[iv_size-1] = 0;
    }
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciPce::~SrciPce()
{
    if(iv_name)
    {
        free( iv_name );
        iv_name = 0;
    }
}


/*****************************************************************************/
// Set the name
/*****************************************************************************/
void SrciPce::Name( const char * i_name )
{
    if ( i_name )
    {
	// Length
	iv_size = strlen( i_name ) + 1;

	// Align 
	iv_size = UTIL_ALIGN_UP( iv_size, 4 );

	// Allocate memory
	iv_name = (char*)realloc( iv_name, iv_size );

	// Copy and null padd
	strncpy( iv_name, i_name, iv_size );

	// Just in case
	iv_name[iv_size-1] = 0;
    }
    else
    {
	free( iv_name );
	iv_name = 0;
    }
}



/*****************************************************************************/
// Export size
/*****************************************************************************/
uint32_t SrciPce::flatSize() const
{
    return ( iv_header.flatSize() + iv_mtms.flatSize() + iv_size );
}


/*****************************************************************************/
// Object print
/*****************************************************************************/
void SrciPce::print(
    ErrlParser & i_parser
    ) const
{

    if ( Name() )
    {
	i_parser.PrintPCEname( Name() );
    }
    
    i_parser.PrintMachineType( iv_mtms.MachineType() );
    i_parser.PrintSerialNumber( iv_mtms.SerialNumber() );
    
}



