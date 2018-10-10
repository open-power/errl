#ifndef ERRLPLUGINS_H
#define ERRLPLUGINS_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include<errlutility.H>


/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class ErrlUsrParser;
class SrciSrc;



namespace errl {



    
/**
 *  @brief Base Plugin class
 *  
 *  Defines some basic methods for the plugins
 *
 *  @note 
 *  
 */
class Plugin
{
protected:
    
    
    /**
     *  @brief Type of plugin
     *  
     *  Used to provide equality among the various
     *  types of plugins
     *  
     */
    enum type
    {
	DATA,
	SRC,
	MRU,
        PWR
    };


    /**
     *  @brief Constructor
     *  
     *  Initialize internal data
     *
     *  @param	i_cid
     *	    Component Id for the plugin
     *
     *  @return None
     *
     */
    Plugin(
	comp_id_t   i_cid,
	type	    i_type,
        errlCreator i_ssid 
    )
    : iv_cid( i_cid ), iv_type( i_type ), iv_ssid( i_ssid )
    {
    }


    
    
    /**
     *  @brief Destructor
     *
     *  No-op
     *  
     *  @return None
     *
     */
    virtual ~Plugin();



public:

    
    /**
     *  @brief Plugin Comparison for sorting
     *
     *  Since the plugins are all grouped together into a single
     *  container, this method is used to compare two plugins
     *  based on their component Id to create a sorted list
     *  
     *  @param	i_right
     *	    Constant reference to compared object
     *
     *  @return True/False if the component Id is less than the
     *          other one.
     *
     *  @note Comparison is based on the component Id only
     *  
     */
    bool operator < ( const Plugin & i_right ) const
    {
	return ( iv_cid < i_right.iv_cid );
    }



    
    
    /**
     *  @brief Plugin Equality
     *
     *  Used to find a matching parser for a given
     *  component.
     *  
     *  @param	i_right
     *	    Constant reference to compared object
     *
     *  @return True/False if the component Id equal to
     *          the other one.
     *
     *  @note Comparison is based on the component Id and
     *	      the type
     *  
     */
    bool operator == ( const Plugin & i_right ) const
    {
	return ( iv_cid == i_right.iv_cid && 
		 iv_type == i_right.iv_type &&
		 iv_ssid == i_right.iv_ssid);
    }




    /**
     *  @brief Data Plugin access
     *  
     *  Convenient access to the contained entry point for the plugin
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
     *  @return True/False to indicate if the Ver/SST combo was handled
     *
     */
    virtual bool operator() (
	ErrlUsrParser & i_parser,
	void *		i_buffer,
	uint32_t	i_buflen,
	errlver_t	i_ver,
	errlsubsec_t	i_sst
    );




    /**
     *  @brief Src Plugin access
     *  
     *  Convenient access to the contained entry point for the plugin
     *
     *  @param	i_parser
     *	    User Parser reference
     *
     *  @param	i_src
     *	    A const reference to an SrciSrc object
     *
     *  @return True/False to indicate if the data was handled
     *
     */
    virtual bool operator() (
	ErrlUsrParser & i_parser,
	const SrciSrc & i_src
    );




    /**
     *  @brief Mru Plugin access
     *  
     *  Convenient access to the contained entry point for the plugin
     *
     *  @param	i_parser
     *	    User Parser reference
     *
     *  @param	i_mru
     *	    32 bit Manufacturing Replaceable Unit Id
     *
     *  @return True/False to indicate if the data was handled
     *
     */
    virtual bool operator() (
	ErrlUsrParser & i_parser,
	uint32_t	i_mru
    );

    /**
     *  @brief Pwr Plugin access
     *
     *  Convenient access to the contained entry point for the plugin
     *
     *  @param  i_parser
     *      User Parser reference
     *
     *  @param  i_pwr
     *      char * Power procedure ID 
     *
     *  @return True/False to indicate if the data was handled
     *
     */

    virtual bool operator() (
        ErrlUsrParser & i_parser,
        const char * i_pwr
    );



public:


    // Data
    comp_id_t	iv_cid;	    ///< Component Id for plugin
    type	iv_type;    ///< Specific type of plugin
    errlCreator iv_ssid;    ///< Creator Subsystem Id

};

    
    



/**
 *  @brief Data Parser Plugin registrar
 *
 *  Object used to register a plug-in's data parse entry point in a static lib.
 *  The suggested usage is to create a instance of the class at global scope
 *  in the object file containing the entry point with the component id and 
 *  the proper entry point as parameters.
 *  i.e.
 *
 *  errl::DataPlugin	g_DataPlugin( ERRL_COMP_ID, LogDataParse );
 *
 *  @note Plugin Equality is based on the component Id and thus will not allow
 *        duplicates
 *
 */
class DataPlugin : public Plugin
{
public:

    
    typedef  bool (*func_t) ( ErrlUsrParser & i_parser, void * i_buffer, uint32_t i_buflen, errlver_t i_ver, errlsubsec_t i_sst);

    
    
    /**
     *  @brief Constructor
     *
     *  The purpose of this object is simply to register the existance
     *  of a data parser from a given component.
     *  
     *  @param	i_cid
     *	    Component Id registering the service
     *
     *  @param	i_func
     *	    Plugin entry point to be registered
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *
     *  @return None
     *
     */
    DataPlugin(
	comp_id_t   i_cid,
	func_t	    i_func,
        errlCreator i_ssid = ERRL_CID_SP
    );



    
    
    /**
     *  @brief Destructor
     *
     *  Deregisters the plugin entry point from the central
     *  plugin repository
     *  
     *  @return None
     *
     */
    ~DataPlugin();



    
    
    /**
     *  @brief Function call method
     *  
     *  Convenient access to the contained entry point for the plugin
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
     *  @return True/False to indicate if the Ver/SST combo was handled
     *
     */
    virtual bool operator() (
	ErrlUsrParser & i_parser,
	void *		i_buffer,
	uint32_t	i_buflen,
	errlver_t	i_ver,
	errlsubsec_t	i_sst
    );



private:

    
    // Data Items
    func_t  iv_pFunc;	///< Function Pointer

};





/**
 *  @brief Src Parser Plugin registrar
 *
 *  Object used to register a plug-in's src parse entry point in a static lib.
 *  The suggested usage is to create a instance of the class at global scope
 *  in the object file containing the entry point with the component id and 
 *  the proper entry point as parameters.
 *  i.e.
 *
 *  errl::SrcPlugin	g_SrcPlugin( ERRL_COMP_ID, SrcDataParse );
 *
 *  @note Plugin Equality is based on the component Id and thus will not allow
 *        duplicates
 *
 */
class SrcPlugin : public Plugin
{
public:

    typedef  bool (*func_t) ( ErrlUsrParser & i_parser, const SrciSrc & i_src );

    
    
    /**
     *  @brief Constructor
     *
     *  The purpose of this object is simply to register the existance
     *  of a data parser from a given component.
     *  
     *  @param	i_cid
     *	    Component Id registering the service
     *
     *  @param	i_func
     *	    Plugin entry point to be registered
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *
     *  @return None
     *
     */
    SrcPlugin(
	comp_id_t   i_cid,
	func_t	    i_func,
	errlCreator i_ssid = ERRL_CID_SP
    );

    
    
    
    /**
     *  @brief Destructor
     *
     *  Deregisters the plugin entry point from the central
     *  plugin repository
     *  
     *  @return None
     *
     */
    ~SrcPlugin();



    
    
    /**
     *  @brief Function call method
     *  
     *  Convenient access to the contained entry point for the plugin
     *
     *  @param	i_parser
     *	    User Parser reference
     *
     *  @param	i_src
     *	    A const reference to an SrciSrc object
     *
     *  @return True/False to indicate if the data was handled
     *
     */
    virtual bool operator() (
	ErrlUsrParser & i_parser,
	const SrciSrc & i_src
    );




private:


    // Data Items
    func_t  iv_pFunc;	///< Function Pointer

};




/**
 *  @brief Mru Parser Plugin registrar
 *
 *  Object used to register a plug-in's mru parse entry point in a static lib.
 *  The suggested usage is to create a instance of the class at global scope
 *  in the object file containing the entry point with the component id and 
 *  the proper entry point as parameters.
 *  i.e.
 *
 *  errl::MruPlugin	g_MruPlugin( ERRL_COMP_ID, MruDataParse );
 *
 *  @note Plugin Equality is based on the component Id and thus will not allow
 *        duplicates
 *
 */
class MruPlugin : public Plugin
{
public:

    typedef  bool (*func_t) ( ErrlUsrParser & i_parser, uint32_t i_mru);

    
    
    /**
     *  @brief Constructor
     *
     *  The purpose of this object is simply to register the existance
     *  of a data parser from a given component.
     *  
     *  @param	i_cid
     *	    Component Id registering the service
     *
     *  @param	i_func
     *	    Plugin entry point to be registered
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *
     *
     *  @return None
     *
     */
    MruPlugin(
	comp_id_t   i_cid,
	func_t	    i_func,
	errlCreator i_ssid = ERRL_CID_SP
    );

    
    
    /**
     *  @brief Destructor
     *
     *  Deregisters the plugin entry point from the central
     *  plugin repository
     *  
     *  @return None
     *
     */
    ~MruPlugin();



    
    
    /**
     *  @brief Function call method
     *  
     *  Convenient access to the contained entry point for the plugin
     *
     *  @param	i_parser
     *	    User Parser reference
     *
     *  @param	i_mru
     *	    32 bit Manufacturing Replaceable Unit Id
     *
     *  @return True/False to indicate if the data was handled
     *
     */
    virtual bool operator() (
	ErrlUsrParser & i_parser,
	uint32_t	i_mru
    );



private:


    // Data Items
    func_t  iv_pFunc;	///< Function Pointer


};

/**
 *  @brief Pwr Parser Plugin registrar
 *
 *  Object used to register a plug-in's pwr parse entry point in a static lib.
 *  The suggested usage is to create a instance of the class at global scope
 *  in the object file containing the entry point with the component id and
 *  the proper entry point as parameters.
 *  i.e.
 *
 *  errl::PwrPlugin     g_PwrPlugin( ERRL_COMP_ID, PwrDataParse );
 *
 *  @note Plugin Equality is based on the component Id and thus will not allow
 *        duplicates
 *
 */
class PwrPlugin : public Plugin
{
public:

    typedef  bool (*func_t) ( ErrlUsrParser & i_parser, const char * i_pwr );



    /**
     *  @brief Constructor
     *
     *  The purpose of this object is simply to register the existance
     *  of a data parser from a given component.
     *
     *  @param  i_cid
     *      Component Id registering the service
     *
     *  @param  i_func
     *      Plugin entry point to be registered
     *
     *  @param  i_ssid
     *      Creator subsystem id
     *
     *
     *  @return None
     *
     */
    PwrPlugin(
        comp_id_t   i_cid,
        func_t      i_func,
	errlCreator i_ssid = ERRL_CID_SP
    );



    /**
     *  @brief Destructor
     *
     *  Deregisters the plugin entry point from the central
     *  plugin repository
     *
     *  @return None
     *
     */
    ~PwrPlugin();


    /**
     *  @brief Function call method
     *
     *  Convenient access to the contained entry point for the plugin
     *
     *  @param  i_parser
     *      User Parser reference
     *
     *  @param  i_pwr
     *      char * Power Procedure ID
     *
     *  @return True/False to indicate if the data was handled
     *
     */
    virtual bool operator() (
    ErrlUsrParser & i_parser,
    const char * i_pwr
    );



private:


    // Data Items
    func_t  iv_pFunc;   ///< Function Pointer


};






} // namespace errl
#endif //ERRLPLUGINS_H
