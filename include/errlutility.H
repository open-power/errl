#ifndef ERRLUTILITY_H
#define ERRLUTILITY_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

#include <errltypes.H>
#include <errl_service_codes.H> 


#include <utilstream.H>
#include <signal.h>			// Signal constants
#include <sys/time.h>        // timeval

/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/
const int	ERRL_MAX_STR_SZ  = 50;			///< Lookup output sz

namespace errl {

    
/*****************************************************************************/
// Prototypes
/*****************************************************************************/

/**
 *  @brief Hash Item
 *
 *  Templated hash item entry.  The current implementation is
 *  limited to an array of these items passed in to the hash
 *  class for 
 *  
 */
template< class Key, class Val >
struct HashItem
{
    typedef Key	key_t;
    typedef Val	val_t;

    friend inline bool operator == ( const HashItem< Key, Val > & i_Left, const Key & i_Key )
    {
	return ( i_Left.iv_Key == i_Key );
    }

    friend inline bool operator == ( const Key & i_Key, const HashItem< Key, Val > & i_Right )
    {
	return ( i_Right.iv_Key == i_Key );
    }

    Key	iv_Key;
    Val	iv_Val;
};


template< class Key, class Val >
struct HashFlagItem
{
    typedef Key	key_t;
    typedef Val	val_t;

    friend inline bool operator == ( const HashFlagItem< Key, Val > & i_Left, const Key & i_Key )
    {
	return ( i_Left.iv_Key & i_Key );
    }

    friend inline bool operator == ( const Key & i_Key, const HashFlagItem< Key, Val > & i_Right )
    {
	return ( i_Right.iv_Key & i_Key );
    }


    Key	iv_Key;
    Val	iv_Val;
};


#define HASH_TABLE(_T_,_NAME_)					    \
typedef const errl::_T_< uint32_t, const char * >  _NAME_##TableItem_t;   \
static _NAME_##TableItem_t  _NAME_##Table[] = {



#define HASH_FLAG_TABLE(_NAME_)	HASH_TABLE(HashFlagItem,_NAME_)
#define HASH_ITEM_TABLE(_NAME_)	HASH_TABLE(HashItem,_NAME_)
#define HASH_TABLE_END(_NAME_)					    \
};								    \
const int _NAME_##TableSz = sizeof(_NAME_##Table)/sizeof(_NAME_##TableItem_t);



/**
 *  @brief Default equality functor for table lookup
 *
 *  The table lookup method uses a functor for comparison and
 *  this template provides the default functor which is nothing
 *  more than an equality comparison
 *  
 */
template< class K, class T >
class TableCmp
{
public:
    inline bool operator() ( const K & i_Left, const T & i_right ) const
    {
	return ( i_Left == i_right );
    }
};




/**
 *  @brief Generic Table Lookup
 *  
 *  @param  i_Key
 *	Matching Key.  Used in comparing to lookup table
 *
 *  @param  i_Table
 *	Pointer to table
 *
 *  @param  i_Sz
 *	Table Size
 *
 *  @return Pointer to table item or 0 if not found
 *
 */
template< class K, class T >
inline const T * TableLookup(

    K	    i_Key,
    const T *	    i_Table,
    int	    i_Sz
)
{
    return TableLookup( i_Key, i_Table, i_Sz, TableCmp< K, T >() );
}



/**
 *  @brief Generic Table Lookup w/replaceable compare
 *  
 *  @param  i_Key
 *	Matching Key.  Used in comparing to lookup table
 *
 *  @param  i_Table
 *	Pointer to table
 *
 *  @param  i_Sz
 *	Table Size
 *
 *  @param  i_Cmp
 *	Table Comparison functor
 *
 *  @return Pointer to table item or 0 if not found
 *
 */
template< class K, class T, class Cmp >
inline const T * TableLookup(

    K	    i_Key,
    const T *	    i_Table,
    int	    i_Sz,
    Cmp	    i_Cmp
)
{
    for( int i = 0; i < i_Sz; i++ )
    {
	if ( i_Cmp( i_Key, i_Table[i] ) )
	    return &i_Table[i];
    }
    return 0;
}

} // namespace
#endif //ERRLUTILITY_H
