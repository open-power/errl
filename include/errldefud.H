#ifndef ERRLDEFUD_H
#define ERRLDEFUD_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <inttypes.h>
#include <unistd.h>
#include <errlmtms.H>


/*****************************************************************************/
// F O R W A R D S
/*****************************************************************************/
class ErrlUsrParser;


/*****************************************************************************/
// Constants
/*****************************************************************************/
const uint32_t ERRL_MAX_PATH_LEN = 256;
const size_t ERRL_MAX_BACKTRACE = 256;
const size_t ERRL_DEFAULT_PATH_SZ = 84;


/**
 *  @brief  Default User Details Section added to every log class.
 *  
 *  This class contains all the logic neede to add a default user details
 *  section to every log.  Such things added at this time are process id,
 *  process name, and driver name.
 *
*/
class Errldata2
{
public:
	
    /**
     * @brief	Init
     *
     * Collects all of the structure's information
     *
    */
    Errldata2();

    
    /**
     * @brief	Print function used by log parser - version 2
     *
     *	Short-cut to parse & display the contents of
     *	the section.  Declared here but only defined in
     *	the error log tool.
     *  
     *  @param	i_Parser
     *      Output device
     *
     *  @return None
     *
    */
    void Print(
	ErrlUsrParser & i_Parser
    );
  

    /**
     *  @brief Access the code level
     *
     *	Short-hand access to the code level
     *
     */
    char * driverName( void )
    {
	return iv_CodeLevel;
    }

    /**
     *  @brief Generic way to acquire process name via a pid
     *  
     *  @param  i_pid
     *	pid of process name to acquire
     *
     *  @param  i_size
     *	size of buffer provided	
     *
     *  @param  o_Data
     *	output buffer
     *
     *  @return None 
     *
     */
    static int CollectProcName( pid_t i_Pid, size_t i_Size, char o_Data[] );


    
private:
    
    
    //Data Members 
    uint32_t	    iv_pid;		///< Process id
    char	    iv_ProcName[ERRL_DEFAULT_PATH_SZ];    ///< Process name
    char	    iv_CodeLevel[32];   ///< Driver name
    fspRole	    iv_Role;		///< System Role
    siblingState    iv_SiblingState;	///< State of sibling
    smgrIplTypeEnum iv_FspIplType;	///< FSP Ipl Type
    smgrIplTypeEnum iv_CecIplType;	///< CEC Ipl Type
    smgrStateEnum   iv_SmgrState;	///< Current State
    bool            iv_isRedundancyEnabled;     ///< Redundancy policy state


    // Disabled
    void * operator new( size_t );
};


#endif //ERRLDEFUD_H
