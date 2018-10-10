#ifndef ERRLPLUGINCENTER_H
#define ERRLPLUGINCENTER_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlplugins.H>
#include <list>


/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/


namespace errl {


    
/**
 *  @brief 
 *  
 *
 *
 *  @note 
 *  
 */
class PluginCenter
{
public:

    
    /**
     *  @brief Singleton Instance for Plugin Center
     *  
     *  Individual Plugins register their entry points at this
     *  plugin center using the register/deregister methods. There is
     *  only one center available at any time.
     *
     *  @return Instance Pointer
     *
     */
    static PluginCenter * Instance();




    /**
     *  @brief Register plugin
     *  
     *  Registers a plugin for service by adding it to the
     *  list
     *
     *  @param	i_plugin
     *	    Reference to the new plugin
     *
     *  @return None
     *
     */
    void Register( Plugin & i_plugin );

    

    
    /**
     *  @brief Deregister plugin
     *  
     *  Removes a registered plugin from the list
     *
     *  @param	i_plugin
     *	    Reference to the plugin
     *
     *  @return None
     *
     */
    void Deregister( Plugin & i_plugin );

    

    
    /**
     *  @brief Call Data Plugin to parse a set of data
     *  
     *  Loads ( if necessary ) the required plugin and transfers
     *  control to it if it is found to be registered on the list
     *
     *  @param	i_cid
     *	    Component Id
     *
     *  @param	i_parser
     *	    User Parser reference
     *
     *  @param	i_buffer
     *	    Data pointer
     *
     *  @param	i_buflen
     *	    Data length
     *
     *  @param	i_ver
     *	    Data Version as stored in the section
     *
     *  @param	i_sst
     *	    Data subsection type
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *
     *  @return True/False to indicate if the Ver/SST combo was handled
     *
     */
    bool CallDataPlugin(
	comp_id_t	i_cid,
	ErrlUsrParser & i_parser,
	void *		i_buffer,
	uint32_t	i_buflen,
	errlver_t	i_ver,
	errlsubsec_t	i_sst,
        errlCreator     i_ssid
    );




    /**
     *  @brief Call Src Plugin to parse a set of data
     *  
     *  Loads ( if necessary ) the required plugin and transfers
     *  control to it if it is found to be registered on the list
     *
     *  @param	i_cid
     *	    Component Id
     *
     *  @param	i_parser
     *	    User Parser reference
     *
     *  @param	i_src
     *	    A const reference to an SrciSrc object
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *  @return True/False to indicate if the data was handled
     *
     */
    bool CallSrcPlugin(
	comp_id_t	i_cid,
	ErrlUsrParser & i_parser,
	const SrciSrc & i_src,
        errlCreator     i_ssid
    );





    /**
     *  @brief Call Mru Plugin to parse a set of data
     *  
     *  Loads ( if necessary ) the required plugin and transfers
     *  control to it if it is found to be registered on the list
     *
     *  @param	i_cid
     *	    Component Id
     *
     *  @param	i_parser
     *	    User Parser reference
     *
     *  @param	i_mru
     *	    32 bit Manufacturing Replaceable Unit Id
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *
     *  @return True/False to indicate if the data was handled
     *
     */
    bool CallMruPlugin(
	comp_id_t	i_cid,
	ErrlUsrParser & i_parser,
	uint32_t	i_mru,
        errlCreator     i_ssid
    );


/**
     *  @brief Call Pwr Plugin to get description of power ID
     *
     *  Loads ( if necessary ) the required plugin and transfers
     *  control to it if it is found to be registered on the list
     *
     *  @param  i_cid
     *      Component Id
     *
     *  @param  i_parser
     *      User Parser reference
     *
     *  @param  i_pwr
     *      char * Power procedure Id
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *
     *  @return True/False to indicate if the data was handled
     *
     */
    bool CallPwrPlugin(
        comp_id_t       i_cid,
        ErrlUsrParser & i_parser,
        const char *    i_pwr,
        errlCreator     i_ssid
    );




    /**
     *  @brief Load Plugin
     *
     *  In the ppc and x86.sim contexts, plugins are
     *  actually shared objects which are dynamically loaded
     *  at runtime through this method.
     *  
     *  @param	i_ssid
     *	    Creator Subsystem Id
     *
     *  @param	i_cid
     *	    Component Id for the requested plugin
     *
     *  @return True/False whether the plugin was loaded or not
     *
     *  @note In the NFP contexts, this method is a NO-OP
     *  
     */
    bool LoadPlugin(
	errlCreator i_ssid,
	comp_id_t   i_cid
    );




private:

    typedef std::list< Plugin * >   list_t;
    typedef list_t::iterator	    itr_t;
    void *    l_libhndl;                       // Dynamic lib handle

    
    /**
     *  @brief Default constructor
     *
     *  No special processing done other than the automatic
     *  container initialization.
     *  
     *  @return None
     *
     */
    PluginCenter()
    {
    }


    
    /**
     *  @brief Destructor
     *  
     *	Nothing special going on here
     *
     *  @return None
     *
     */
    ~PluginCenter();



    /**
     *  @brief Find a plugin on the list
     *  
     *  Traverses the list until the first instance
     *  of the given plugin is found
     *
     *  @param	i_plugin
     *	    A const reference to the plugin
     *
     *  @return An iterator to first instance of the plugin
     *          if found or an iterator to the end if not
     *
     *  @note There are multiple plugins by the same component
     *        ( one for each entry point ) and will typically
     *        be stored back to back on the list.
     *  
     */
    itr_t Find( const Plugin & i_plugin );


    
    
    // Containers
    list_t  iv_Plugins;

};





} // namespace errl
#endif // ERRLPLUGINCENTER_H
