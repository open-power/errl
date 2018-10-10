#ifndef ERRLTOOL_H
#define ERRLTOOL_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>

#include <utilstream.H>
#include <list>

namespace errl {
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
// F O R W A R D S
/*****************************************************************************/

class Tool
{
public:
    
    // access Instance Variable
    static Tool * Instance( void );
   
    // set timeout
    virtual void setTimeOut( uint32_t i_wait )
    {

    }; 

    // acquire list
    virtual errlstatus_t List(
	uint32_t   &	io_start,
	uint32_t	i_flags,
	uint32_t   &	io_max
	) = 0; 

    // read one log
    virtual errlstatus_t Read(
	uint32_t	i_which,
	void *		o_pBuf,
	uint32_t  &	io_sz
	) = 0;
    
    // read one log
    errlstatus_t Read(
	uint32_t	i_eid,		///< Entry Id
	errlHndl_t	io_hndl		///> Output Handle
	);


    virtual ~Tool()
    {
    };
    
protected:
    
    // Default Constructor
    Tool()
    {
    };

    static Tool * cv_instance;	    // static pointer to connection type

};



};

#endif //ERRLTOOL_H
