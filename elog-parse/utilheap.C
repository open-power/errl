
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <utilheap.H>
#include <utilbase.H>
#include <cstring>
#include <errlusrparser.H>
#include <errlentry.H>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <iostream>
/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/
const UtilHeap::mapEntry_t  UTIL_BLK_USED = (UtilHeap::mapEntry_t)-1;
const UtilHeap::mapEntry_t  UTIL_BLK_FREE = 0;


/*****************************************************************************/
// C o n s t r u c t o r
/*****************************************************************************/
UtilHeap::UtilHeap(
    bool & o_result,
    uint32_t i_heapSz,
    uint32_t i_blockSz
    )
: iv_heapSz( 0 ),
  iv_blockSz( 0 ),
  iv_usedblocks( 0 ),
  iv_top( 0 ),
  iv_bot( 0 ),
  iv_mmap( 0 ),
  iv_mapSz( 0 )
{
    // Locals
    void * tmp = 0;

    // Assume failure
    o_result = false;

    iv_mmap = NULL;
    
    if ( i_heapSz && i_blockSz && i_heapSz >= i_blockSz )	// Make sure they're > 0
    {
	// Store the block size
	iv_blockSz = UTIL_ALIGN_UP(i_blockSz, sizeof(uint32_t));

	// Create the memory map
	// Whenver the heap is not evenly divisible by the block size
	// we must create an extra block.  Therefore, the user will be
	// able to allocate slightly more than he requested as a heap
	// size.
	iv_mapSz = UTIL_EVEN_DIV( i_heapSz, iv_blockSz );

	// Calculate the real heap size
	iv_heapSz = iv_mapSz * iv_blockSz;

	// Allocate enough memory to hold both the heap and the memory map
	tmp = mmap(0, iv_mapSz + iv_heapSz, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
	
	// Validate pointer
	if ( tmp != MAP_FAILED )
	{
	    // Store my specifics
	    iv_mmap = ( mapEntry_t *)tmp;
	    iv_top = ( ( hpp_t )iv_mmap + iv_mapSz );
	    iv_bot = iv_top + iv_heapSz;
	    

	    // Set the return code
	    o_result = true;
	    
	}
    }
    else
    {
	errno = EINVAL;
	
    }
    
}


/*****************************************************************************/
// D e s t r u c t o r
/*****************************************************************************/
UtilHeap::~UtilHeap()
{
    if ( iv_mmap )
    {
	iv_mmap = 0;
    }
}


/*****************************************************************************/
// A l l o c a t i o n
/*****************************************************************************/
void * UtilHeap::allocate( uint32_t i_size )
{
    uint32_t	l_blks;
    uint32_t	l_cntr;
    uint32_t	l_freeBlks;
    uint32_t	l_start;
    bool	l_found;
    void *	l_pBlk = NULL;				// Assume failure

    // Determine how many blocks
    l_blks = UTIL_EVEN_DIV( i_size , iv_blockSz );

    // Set Initial conditions
    l_cntr = 0;
    l_freeBlks = 0;
    l_found = false;

    // Assume that if no blocks are used, the heap
    // is new and therefore we should level set
    // the region as the first step
    if ( 0 == iv_usedblocks )
    {
	memset(iv_mmap, UTIL_BLK_FREE, iv_mapSz);
	memset(iv_top, UTIL_MEM_CLEAR, iv_heapSz);
    }

    // Find empty blocks satisfying the request.
    // This while runs as long as:
    //	1) found = false
    //	2) we don't overrun the map
    //	3) blks > 0
    while ( l_cntr < iv_mapSz && l_blks && ! l_found )
    {

	switch ( iv_mmap[l_cntr] )
	{
	    case UTIL_BLK_FREE:
		l_freeBlks++;
		if ( l_freeBlks == l_blks )
		{
		    l_found = true;		// FORCE LOOP EXIT
		}
		else
		{
		    l_cntr++;
		}
		break;

	    case UTIL_BLK_USED:			// Shouldn't happen
		l_cntr++;
		l_freeBlks = 0;
		break;

	    default:
		l_cntr += iv_mmap[l_cntr];	// Skip used
		l_freeBlks = 0;

	}//switch

    }//while

    if ( l_found )
    {
	// Find starting block
	l_start = l_cntr - ( l_blks - 1 );

	// Set blocks used
	iv_mmap[ l_start ] = l_blks;
	
	// Mark the rest as used
	memset( &iv_mmap[ l_start + 1 ], UTIL_BLK_USED, l_blks -1 );

	// Generate 32 bit pointer
	l_pBlk = ( void * ) ( (char *)iv_top + l_start * iv_blockSz );

	// Mark data section ( Debugging )
	memset( l_pBlk, UTIL_MEM_DATA, l_blks * iv_blockSz );

	// Increment used block count
	iv_usedblocks += l_blks;


    }
    else
    {
	// We don't have enough room to satisfy the request
	errno = ENOMEM;
	
    }

    return l_pBlk;
}

/*****************************************************************************/
// R e l e a s e
/*****************************************************************************/
void UtilHeap::free( void * i_ptr )
{
    uint32_t	l_start;
    uint32_t	l_blks;
    bool	l_rc;

    // Deal with a null pointer
    if ( ! i_ptr )
	return;
    
    // Obtain the map location and # of blocks
    l_rc = ptr2map( i_ptr, l_start, l_blks );
    
    // Proceed only if there's no error
    if ( l_rc )
    {

	// Mark the map entries as unused.
	memset( &iv_mmap[ l_start ], UTIL_BLK_FREE, l_blks );

	// Mark the memory as trash
	memset( i_ptr, UTIL_MEM_TRASH, l_blks * iv_blockSz );

	// Decrement the used block count
	iv_usedblocks -= l_blks;

    }
}



/*****************************************************************************/
// Pointer resize
/*****************************************************************************/
void * UtilHeap::resize( void * i_ptr, size_t i_size )
{    
    uint32_t    l_cntr;
    uint32_t    l_freeBlks;
    bool        l_found;
    uint32_t    l_start;
    uint32_t    l_blks;
    uint32_t    l_reqBlks;
    uint32_t    l_memsize;
    bool        l_conversion;
    void *      l_rc = NULL;

    // If i_ptr is NULL then allocate memory
    if( !i_ptr )
    {
	l_rc = allocate( i_size );
    }
    else
    {
	// Obtain the map location and # of blocks
	l_conversion = ptr2map( i_ptr, l_start, l_blks );

	// Proceed only if there's no error
	if ( l_conversion )
	{
	    // Calculate the current memory usage
	    l_memsize = l_blks * iv_blockSz;

	    // If the current amount already satisfies the request we
	    // have nothing to do, otherwise we'll have to attempt to
	    // allocate a new block and copy the data from the current
	    // block to the new one.
	    if ( i_size > l_memsize )
	    {

		// Determine how many blocks
		l_reqBlks = UTIL_EVEN_DIV( i_size , iv_blockSz );

		// How many extra blocks required
		l_reqBlks = l_reqBlks - l_blks;

		// Set Initial conditions
		l_cntr = l_start+ l_blks;               // Release the old pointer
		l_freeBlks = 0;
		l_found = false;

		// Find empty blocks satisfying the request.
		// This while runs as long as:
		//  1) found = false
		//  2) we don't overrun the map
		//  3) reqBlks > 0
		// pb1
		for( l_cntr = l_start+l_blks;( l_cntr < iv_mapSz )&& l_reqBlks;l_cntr++)
		{
		    if( iv_mmap[l_cntr] == UTIL_BLK_FREE )
		    {
			if( ++l_freeBlks == l_reqBlks )
			{
			    l_found = true;
			    break;
			}
		    }
		    else
		    {
			break;
		    }
		}
				
		 
		if ( l_found )
		{
	     
		    // Set blocks used
		    iv_mmap[ l_start ] = l_reqBlks + l_blks;

		    l_start = l_cntr - ( l_reqBlks - 1 );

		    // Mark the rest as used
		    memset( &iv_mmap[ l_start ], UTIL_BLK_USED, l_reqBlks);

		    // Mark data section ( Debugging )
		    memset( (char *)i_ptr + l_memsize, UTIL_MEM_DATA, l_reqBlks * iv_blockSz );

		    //return the modified pointer
		    l_rc = i_ptr;

		    // Increment used block count
		    iv_usedblocks += l_reqBlks;

		}
		else
		{
		    // Allocate a new chunk
		    l_rc = allocate( i_size );

		    // Copy the old data and release the old pointer
		    // Note: if the allocation failed, errno has been set
		    //       and l_rc should be null so we can just bail
		    if ( l_rc )
		    {
			// Copy the data
			memcpy( l_rc, i_ptr, l_blks * iv_blockSz );

			// Release the old pointer
			free( i_ptr );

		    }
		}
	    }
	    else
	    {
		// The current chunk is big enough, so give the application
		// the freedom to continue with the current block
		l_rc = i_ptr;
	    }
	}
    }
    
    return l_rc;
}



/*****************************************************************************/
// Pointer to map translation
/*****************************************************************************/
bool UtilHeap::ptr2map(
    void *	i_ptr,
    uint32_t &	o_mapIdx,
    uint32_t &	o_blksUsed
    ) const
{
    hpp_t	l_cptr;
    uint32_t	l_cntr;
    bool	l_rc = false;

    // Bad Pointer
    if ( ! i_ptr )
    {
	errno = EFAULT;
    }
    // No memory region has been mapped
    else if ( 0 == iv_usedblocks )
    {
	errno = EFAULT;
    }
    // Proceed with lookup
    else
    {
	// Cast the input pointer
	l_cptr = (hpp_t) i_ptr;

	//Check if the pointer belongs to correct heap
	if( l_cptr >= iv_top && l_cptr < iv_bot )
	{
	    // Determine the initial map entry
	    o_mapIdx = ( l_cptr - iv_top ) / iv_blockSz;

	    // Setup the counter just past the first entry.
	    l_cntr = o_mapIdx + 1;

	    // Check for a valid map entry at the beginning
	    if ( iv_mmap[ o_mapIdx ] == UTIL_BLK_FREE ||
		 iv_mmap[ o_mapIdx ] == UTIL_BLK_USED	)
	    {
		// Set errno
		errno = EIO;
	    }
	    else
	    {
		// Cycle through the map to find the last entry.
		while ( l_cntr < iv_mapSz && 
			iv_mmap[ l_cntr ] == UTIL_BLK_USED )
		{
		    l_cntr++;
		}

		// How many blocks.
		o_blksUsed = l_cntr - o_mapIdx;
	
		// Signal success
		l_rc = true;
	
	    }
	}
    }
    
    return l_rc;
}



/*****************************************************************************/
// Size of the Heap
/*****************************************************************************/
uint32_t UtilHeap::getSize(void)
{
    uint32_t l_space;

    // Since the map size equals the # of blocks
    l_space = iv_mapSz * iv_blockSz;

    return l_space;
}



/*****************************************************************************/
// Free space on the heap
/*****************************************************************************/
uint32_t UtilHeap::getFree(void)
{
    uint32_t l_space;

    l_space = getSize() - iv_usedblocks * iv_blockSz;

    return l_space;
}


/*****************************************************************************/
// Determine if the pointer is in this heap and valid
/*****************************************************************************/
bool UtilHeap::ValidPointer( void * i_ptr ) const
{
    uint32_t	l_start;
    uint32_t	l_blks;

    // Obtain the map location and # of blocks
    return ptr2map( i_ptr, l_start, l_blks );
}
    

