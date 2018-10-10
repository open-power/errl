/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Linux includes
#include <utilmem.H>
#include <utilbase.H>
#include <cstdlib>
#include <cstring>
#include <srcisrc.H>
#include <errlentry.H> 
#include <errlusrparser.H>
#include <unistd.h>
#include <utilfile.H>


/*****************************************************************************/
// Default Constructor
/*****************************************************************************/
UtilMem::UtilMem()
: iv_memStart( 0 ), iv_offset( 0 ), iv_size( 0 ), iv_autoGrow( true ),
iv_autoCleanup( true )
{
}

/*****************************************************************************/
// Constructor with Size parameter
/*****************************************************************************/
UtilMem::UtilMem(uint32_t i_size)
: iv_memStart( 0 ), iv_offset( 0 ), iv_size( i_size ), iv_autoGrow( false ),
iv_autoCleanup( true )
{
    iv_memStart = (uint8_t *)malloc(i_size);

    if ( iv_memStart )
    {
	// Clean it out
	reset( 0 );
    }

}

/*****************************************************************************/
// Constructor with Buffer and Size parameters
/*****************************************************************************/
UtilMem::UtilMem(void * i_buffer, uint32_t i_size)
: iv_memStart( (uint8_t*)i_buffer ), iv_offset( 0 ), iv_size( i_size ), 
iv_autoGrow( false ), iv_autoCleanup( false )
{
}


/*****************************************************************************/
// Assignment operator
/*****************************************************************************/
UtilMem & UtilMem::operator = ( const UtilMem & i_right )
{
    if ( &i_right != this )
    {
	// Base assignment
	UtilStream::operator=( i_right );

	// Cleanup
	if ( iv_autoCleanup )
	{
	    free(iv_memStart);
	}

	// Setup
	iv_offset = i_right.iv_offset;
	iv_size = i_right.iv_size;
	iv_autoGrow = i_right.iv_autoGrow;
	iv_autoCleanup = i_right.iv_autoCleanup;
	
	if ( i_right.iv_autoCleanup )
	{
	    iv_memStart = (uint8_t*)malloc( i_right.iv_size );
	    memcpy(iv_memStart,i_right.iv_memStart,iv_size);
	}
	else
	{
	    iv_memStart = i_right.iv_memStart;
	}
	
	
    }
    
    return *this;

}

/*****************************************************************************/
// UtilFile assignment
/*****************************************************************************/
UtilMem & UtilMem::operator = ( const UtilFile & i_right )
{
    UtilFile & l_file = const_cast<UtilFile &> ( i_right );

    l_file.read( iv_memStart, iv_size );

    return *this;
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
UtilMem::~UtilMem()
{
    if (iv_autoCleanup)
    {
	free(iv_memStart);
	iv_memStart = 0;
    }
}

/*****************************************************************************/
// Read the file
/*****************************************************************************/
uint32_t UtilMem::read(
    void *	o_buffer,
    uint32_t	i_size
    )
{
    uint32_t	    l_rc = 0;

    if ( ! iv_memStart )		    // Invalid pointer
    {
    }
    else if ( iv_eof )			    // Not at EOF
    {
    }
    else if ( i_size && ! iv_lastError )    // Size > 0 && no errors
    {
        l_rc = i_size;

        if ( ( iv_offset + i_size )  > iv_size )
	{
            // Recalculate i_size
            l_rc = iv_size - iv_offset;

            // Set EOF
            iv_eof = true;
	}

        // Copy memory
        memcpy( o_buffer, (iv_memStart + iv_offset), l_rc );

        // Set the new current position
        iv_offset += l_rc;

    }


    return l_rc;
}


/*****************************************************************************/
// Write the file
/*****************************************************************************/
uint32_t UtilMem::write(
    const void *i_buffer,
    uint32_t	i_size
    )
{
    uint32_t	    l_rc = 0;


    if ( ! iv_memStart && ! iv_autoGrow )   // Invalid pointer
    {
    }
    else if ( iv_eof && ! iv_autoGrow )	    // Not at EOF
    {
	
    }
    else if ( i_size && ! iv_lastError )   // Size > 0 && no errors
    {
        l_rc = i_size;

        if ( ( iv_offset + i_size ) > iv_size )
	{
            if (iv_autoGrow)
	    {
                iv_size = iv_offset + i_size;
                iv_memStart = (uint8_t *)realloc( iv_memStart, iv_size );

	    } 
                // Recalculate i_size
                l_rc = iv_size - iv_offset;

                // Set EOF
                iv_eof = true;
	}

        // Copy memory
        memcpy((iv_memStart + iv_offset), i_buffer, l_rc);/*operating on NULL*/

        // Set the new current position
        iv_offset += l_rc;

    }


    return l_rc;

}

/*****************************************************************************/
// Seek the file
/*****************************************************************************/
uint32_t UtilMem::seek(
    int	    i_pos,
    whence  i_whence
    )
{
    int	l_offset = 0;
    uint32_t l_origin = 0;

    if (!iv_lastError)
    {
        if ( i_whence == START )
	{
            // Set the origin
            l_origin = 0;
	}
        else if (i_whence == CURRENT)
	{
            // Set the current position
            l_origin = iv_offset;
	}
        else if ( i_whence == END )
	{
            l_origin = iv_size;
	}

        l_offset = l_origin + i_pos;

        if (l_offset < 0)
	{
            // Set the offset to the beginning
            iv_offset = 0;
	}
        else if (l_offset > (int)iv_size)
	{
            iv_offset = iv_size - 1;
	}
        else
	{
            iv_offset = l_offset;
	}

        // Clear the EOF indicator
        iv_eof = false;
    }

    return iv_offset;
}



/*****************************************************************************/
// Reset the object
/*****************************************************************************/
void UtilMem::reset( int i_c )
{
    memset( iv_memStart, i_c, iv_size );
    iv_offset = 0;
    delete getLastError();
}



/*****************************************************************************/
// Output a hexdump of the file
/*****************************************************************************/
void UtilMem::print( FILE * o_stream ) const
{
    if ( iv_memStart )
    {
	ErrlUsrParser	l_parser( o_stream );
	l_parser.PrintHexDump( iv_memStart, iv_size );
    }
}






