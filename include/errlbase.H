#ifndef ERRLBASE_H
#define ERRLBASE_H


/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>


/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class UtilHeap;


/*****************************************************************************/
// Constants
/*****************************************************************************/
const uint32_t	ERRL_MAX_FILENAME	    = 64;

/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/

/*****************************************************************************/
// Synonyms
/*****************************************************************************/

/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class ErrlBase
{
public:

    
    /**
     *  @brief Container based constructor
     *  
     *  Included to force subclasses to distiniguish between
     *  memory containers by requiring that they explicitly
     *  pass in the container to be used or zero for global
     *
     *  @param	i_pHeap
     *	    Memory Container
     *
     *  @return None
     *
    */
    ErrlBase(
	UtilHeap * i_pHeap
    );

    
    
    /**
     *  @brief Copy-constructor
     *  
     *  Makes an exact copy of the source
     *
     *  @param	i_Base
     *	    Base reference of the source
     *
     *  @return None
     *
    */
    ErrlBase(
	const ErrlBase & i_Base
    );

    
    
    /**
     *  @brief Base destructor
     *  
     *  Currently no processing
     *
     *  @return None
     *
    */
    virtual ~ErrlBase();

    
    
    /**
     *  @brief Global Heap allocation request
     *
     *  A pass-through interface to the real operator new
     *  
     *  @param	i_size
     *	    Number of bytes requested
     *
     *  @return Allocated memory pointer
     *
     *  @note The default operator new from the global namespace
     *        raises a SIGABRT if it cannot allocate memory and
     *        exceptions have been disabled.
     *  
    */
    void* operator new(
        size_t i_size
    );

    
    
    
    /**
     *  @brief Container based delete
     *
     *  Uses the dead object to determine the type of container
     *  being used for memory allocation and deallocates the
     *  object from the proper container.
     *  
     *  @param	i_ptr
     *	    Dead object pointer
     *
     *  @return None
     *
     *  @note Follows normal operator delete semantics ( i.e. it
     *        returns immediately if the input pointer is null )
     *  
    */
    void operator delete(
        void* i_ptr
    );

    
    
    
    /**
     *  @brief Specific Container based memory allocation
     *  
     *	Uses the given container to draw memory prior to the object being
     *	created.
     *
     *  @param	i_size
     *	    Amount of storage being requested
     *
     *  @param	i_heap
     *	    A reference to the container which should be used
     *
     *  @return A pointer to the unborn object
     *
    */
    void* operator new(
        size_t i_size, 
        UtilHeap &i_heap
    );

    
    
    /**
     *  @brief Internal Object allocation
     *  
     *  Just a short-hand approach to create objects whose memory comes
     *  from the same container ( Global Heap or otherwise )
     *
     *  @param	i_size
     *	    Amount of bytes requested
     *
     *  @param	i_base
     *	    Base Reference which will be queried to determine container source
     *
     *  @return A pointer to the new block of memory
     *
     *  @note The interface will call percAbend if memory cannot be allocated
     *  
    */
    void* operator new(
        size_t i_size, 
        ErrlBase &i_base
    );

    

protected:

    
    /**
     *  @brief Container based memory allocation
     *  
     *  Short-hand notation for obtaining memory
     *
     *  @param	i_size
     *	    Number of bytes requested
     *
     *  @return A pointer to the new memory
     *
     *  @note 
     *  
     */
    void *alloc(
        size_t i_size
    );

    
    
    /**
     *  @brief Memory resize
     *  
     *  Short-hand container independent memory resize
     *
     *  @param	i_ptr
     *	    Pointer to be resized
     *
     *  @param	i_size
     *	    New data size in bytes
     *
     *  @return New pointer
     *
     *  @note Follows the same semantics as the glibc ::realloc
     *        ( i.e. a null pointer is valid on entry and will
     *        result in a call to malloc )
     *
     *        If a memory allocation fails, percAbend will be
     *        called.
     *  
     */
    void *realloc(
        void *i_ptr, 
        size_t i_size
    );

    
    
    /**
     *  @brief Memory release
     *  
     *  Short-hand container independent memory release
     *
     *  @param	i_ptr
     *	    Pointer to previously allocated memory
     *
     *  @return None
     *
     *  @note Tolerates null pointer releases
     *  
     */
    void free(
        void *i_ptr
    );

    
    

public:

    
private:

    static int	iv_RegLock;
    UtilHeap *	iv_pHeap;


    // Disabled
    ErrlBase & operator= (
	const ErrlBase & i_right
    );

};




/*****************************************************************************/
// Base constructor
/*****************************************************************************/
inline ErrlBase::ErrlBase(
    UtilHeap * i_pHeap
)
: iv_pHeap( i_pHeap )
{
}


/*****************************************************************************/
// Copy-constructor
/*****************************************************************************/
inline ErrlBase::ErrlBase(
    const ErrlBase & i_Base
)
: iv_pHeap( i_Base.iv_pHeap )
{
}


/*****************************************************************************/
// Short-hand for same container allocation
/*****************************************************************************/
inline void* ErrlBase::operator new(
    size_t i_size, 
    ErrlBase &i_base
)
{
    return i_base.alloc( i_size );
}


/*****************************************************************************/
// Internal based
/*****************************************************************************/
inline void * ErrlBase::alloc(
    size_t i_size
)
{
    return realloc( 0, i_size );
}


#endif //ERRLBASE_H
