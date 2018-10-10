/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/utilheap.H $                                 */
/*                                                                        */
/* OpenPOWER errltool Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef UTILHEAP_H
#define UTILHEAP_H

/**
 * @file utilheap.H
 *
 * @brief   Localized heap object
 *
 * Applications requiring increased performance during memory allocations or
 * those restricted to no memory allocations in particular scenarios can
 * utilize this facility to allocate memory.  Furthermore, objects wishing
 * to be created on a localized heap can also make use of this object with
 * an overloaded new operator by subclassing from utilbase.
 *
*/
/**
 * @page ChangeLogs Change Logs
 * @section UTILHEAP_H utilheap.H
 * @verbatim
 *
 * Flag PTR/DCR#   Userid    Date      Description
 * ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <utilbase.H>			// Basic types


/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/
const uint8_t UTIL_MEM_CLEAR 	=	'C';	///< Cleared section ( new )
const uint8_t UTIL_MEM_DATA 	=	'D';	///< Data section ( used )
const uint8_t UTIL_MEM_TRASH	=	'T';	///< Deleted section


/*****************************************************************************/
// Synonyms
/*****************************************************************************/

/*****************************************************************************/
// Macros
/*****************************************************************************/
/**
 *  @brief	Rounds a figure up to ensure it is aligned to a given factor
 *  
 *  When a figure needs to be aligned to a particular factor, this macro is
 *  called to round the figure up to next whole factor amount.
 *  
*/
#define UTIL_ALIGN_UP(_size_, _factor_) ( _size_ % _factor_ ? \
					_factor_ - _size_ % _factor_ + _size_ : \
					_size_ )


/**
 *  @brief	Rounds a figure DOWN to ensure it is aligned to a given factor
 *  
 *  When a figure needs to be aligned to a particular factor, this macro is
 *  called to round the figure down to previous whole factor amount.
 *  
*/
#define UTIL_ALIGN_DOWN(_size_, _factor_) ( _size_ % _factor_ ? \
					  _size_ - _size_ % _factor_  : \
					  _size_ )


/**
 *  @brief	Even division
 *  
 *  When a figure needs to be evenly divided by a factor, this macro is
 *  called to perform both the alignment and then the division.
 *  
*/
#define UTIL_EVEN_DIV(_size_, _factor_)	 ( UTIL_ALIGN_UP(_size_,_factor_)	\
					 / _factor_ )

/*****************************************************************************/
// Prototypes
/*****************************************************************************/

/*****************************************************************************/
// Error Log Heap Class
/*****************************************************************************/
/**
 *  @brief	Localized heap object
 *  
 *  Provides a light-weight memory management facility for applications
 *  requiring increased performance during multiple memory allocations or
 *  for usage in scenarios where memory allocation is a constraint.
 *  
*/
class UtilHeap
{
public:


    /**
     *  @brief Default constructor
     *  
     *  Allocates all the bookkeping information needed to maintain a heap
     *  object and allocates a chunk of the global heap to match the requested
     *  localized heap size.  Bookkeeping includes a heap structure and a
     *  memory map.
     *  
     *  @return	Because constructors cannot return a value, this interface
     *			returns	it's creation status in the o_result variable.  If all
     *			the required memory can successfully be allocated to create the
     *  		object, a value of true is returned, otherwise, false is
     *			returned and the object is worthless.
     *  
    */
    UtilHeap(
	bool &	 o_result,		///< Construction result
	uint32_t i_heapSz = 4096,	///< Default heap size
	uint32_t i_blockSz = 16		///< Default block size
	);

    
		    
    /**
     *  @brief	Virtual Destructor
     *  
     *  The destructor will be called at object death and will
     *  perform any necessary cleanup.
     *
    */
    ~UtilHeap();


    
    /**
     *  @brief	Allocate a chunk of memory from the heap object
     *  
     *  Requests a chunk of memory from the localized heap object.  The
     *	interface searches the memory map for a contiguous chunk of space big
     *	enough to satisfy the request.
     *
    */
    void * allocate(
	uint32_t size		    ///< Requested size
	);



    /**
     *  @brief	Release a previously allocated pointer
     *  
     *  Memory allocated from a heap object can be released using this inter-
     *	face.  If the pointer is invalid, the interface will just ignore it.
     *
    */
    void free(
	void * i_ptr		    ///< Pointer to memory to be released
	);



    /**
     *  @brief	Resize an existing pointer
     *  
     *  Gives the caller the ability to modify the size of an existing
     *	chunk of memory.  This interface is similar to the realloc from
     *	the std c-library
     *
     *	@return	A pointer to the new block
     *	@retval	A valid pointer on success
     *	@retval	A null pointer on failure
     *
     *	@note	If a new pointer is assigned, the old data will be
     *			moved to the new location.
     *
    */
    void * resize(
	void * i_ptr,		    ///< Existing interface pointer
	size_t i_size		    ///< New size requested
	);
    
    
    
    /**
     *  @brief	Pointer Validation
     *  
     *  In some instances, the user wants to know if a pointer is owned
     *  by a given heap object and if it's valid.
     *
    */
    bool ValidPointer( void * i_ptr ) const;




    /**
     *  @brief	Returns the total size of the heap object
     *  
     *  Because the map used to keep track of the entries is a linear map,
     *	this interface returns the map size times the block size to yield the
     *	total size of the heap object
     *
     *	@return	Total heap size
     *
    */
    uint32_t getSize(void);
    

    
    /**
     *  @brief	Free space remaining
     *  
     *  Returns the amnt of non-contiguous free space remaining in the object.
     *  This is not necessarily the max amnt that can be allocated.
     *
     *	@return	Free space
     *
    */
    uint32_t getFree(void);
    


    /**
     *  @brief	Prints out the object data 
     *  
     *  The object data is printed to stdout for analysis
     *
    */
    void print( void ) const;
    
    

    /**
     *  @brief Heap memory region pointer
     *  
     *	Heap memory region pointer
     *  
    */
    typedef uint8_t *	hpp_t;
    
    
    /**
     *  @brief Heap memory map entry
     *  
     *	The memory map mainted by a heap object uses this type of data for
     *	each entry on the map.
     *  
    */
    typedef uint8_t	mapEntry_t;

    

private:


    /**
     *  @brief	Pointer to memory map conversion
     *  
     *  Retrieves the memory map index and number of blocks a given
     *	pointer currently owns.
     *
     *	@return True/False
     *	@retval True = the pointer was found on the map and the
     *			variables contain the requested data.
     *	@retval False = the pointer was not found on the map.
     *
    */
    bool ptr2map(
	void *	   i_ptr,	///< Existing pointer
	uint32_t & o_mapIdx,	///< Map Index reference
	uint32_t & o_blksUsed	///< # of blocks used by pointer
	) const;



    // Bookkeeping
    uint32_t	iv_heapSz;		///< Heap size of this object
    uint32_t	iv_blockSz;		///< Block size of this object
    uint32_t	iv_usedblocks;		///< Blocks used in this heap

    // Identification
    hpp_t	iv_top;			///< Top of the memory region
    hpp_t 	iv_bot;			///< Bottom of the memory region

    // Memory map
    mapEntry_t *iv_mmap;		///< Memory map
    uint32_t	iv_mapSz;		///< Memory map size
    
};


#endif //UTILHEAP_H

