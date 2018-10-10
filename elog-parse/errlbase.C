/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdlib.h>
#include <errlbase.H>
#include <utilheap.H>

#include <sched.h>
#include <errlentry.H>
#include <errlutility.H>
#include <errl_service_codes.H>

#include <cstring>
#include <memory>
#include <errno.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/*****************************************************************************/
// Globals
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/

/*****************************************************************************/
// S t a t i c s
/*****************************************************************************/
int ErrlBase::iv_RegLock = -1;


/*****************************************************************************/
// Base destructor
/*****************************************************************************/
ErrlBase::~ErrlBase()
{
}


/*****************************************************************************/
// Normal Memory allocation
/*****************************************************************************/
void * ErrlBase::operator new(
    size_t i_size
)
{
    ErrlBase	l_base = 0;
    return l_base.alloc( i_size );
}


/*****************************************************************************/
// Container based memory allocation
/*****************************************************************************/
void *ErrlBase::operator new(
    size_t i_size, 
    UtilHeap &i_heap
)
{
    void * l_rc = NULL;
    l_rc = i_heap.allocate( i_size );

    
    return l_rc;
}


/*****************************************************************************/
// Memory release
/*****************************************************************************/
void ErrlBase::operator delete(
    void* i_ptr
)
{
    ErrlBase * l_p = reinterpret_cast< ErrlBase *> ( i_ptr );

    // Null check
    if ( i_ptr )
    {
	l_p->free( i_ptr );
    }
}


/*****************************************************************************/
// Internal memory re-allocation routine
/*****************************************************************************/
void *ErrlBase::realloc(
    void *i_ptr, 
    size_t i_size
)
{
    void *  l_rc = 0;
    
    // Realloc
    if ( i_ptr )
    {
	// Local Heap
	if ( iv_pHeap )
	{
	    l_rc = iv_pHeap->resize( i_ptr, i_size );
	}
	// Global heap
	else
	{
	    l_rc = ::realloc( i_ptr, i_size );
	}
    }
    // Malloc
    else
    {
	// Local Heap
	if ( iv_pHeap )
	{
	    l_rc = iv_pHeap->allocate( i_size );
	}
	// Global heap
	else
	{
	    l_rc = ::malloc( i_size );
	}
    }

    
    // Done
    return l_rc;
}



/*****************************************************************************/
// Memory release
/*****************************************************************************/
void ErrlBase::free(
    void *i_ptr
)
{
    // Null Check
    if ( i_ptr )
    {
	// Local Heap
	if ( iv_pHeap )
	{
	    iv_pHeap->free( i_ptr );
	}
	// Global Heap
	else
	{
	    ::free( i_ptr );
	}
    }
}

