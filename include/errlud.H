#ifndef ERRLUD_H
#define ERRLUD_H


/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errlsctn.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class UtilStream;
class ErrlParser;


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
class ErrlUD : public ErrlSctn
{
protected:
    
    /**
     *  @brief Default Constructor
     *
     *  Used by subclasses to build a user data
     *  section which encapsulates data of a
     *  certain type
     *  
     *  @param	i_parent
     *	    Base pointer for memory allocation
     *
     */
    ErrlUD(
	ErrlBase &  i_parent
    );

    
public:

    
    /**
     *  @brief Import constructor
     *
     *  Rebuilds an object from flat input data
     *  
     *  @param	i_stream
     *	    Data source
     *
     *  @param	i_hdr
     *	    Previously read section header
     *
     *  @param	i_parent
     *	    Base pointer
     *
     *  @note Failures are returned in the
     *        incoming stream
     *  
     */
    ErrlUD(
	UtilStream & i_stream,
	ErrlSctnHdr &i_hdr,
	ErrlBase &   i_parent
    );


    
    
    /**
     *  @brief Constructor
     *
     *  Create a user data section with the given
     *  input data.
     *  
     *  @param	i_data
     *	    Data source
     *
     *  @param	i_size
     *	    Data length
     *
     *  @param	i_cid
     *	    Creator of the section
     *
     *  @param	i_ver
     *	    User supplied version
     *
     *  @param	i_sst
     *	    User supplied section type
     *
     *  @param	i_parent
     *	    Base pointer
     *
     *  @note Failures are returned in the
     *        incoming stream
     *  
     */
    ErrlUD(
        const void *i_data, 
        uint32_t    i_size, 
        comp_id_t   i_cid, 
        errlver_t   i_ver, 
        errlsubsec_t i_sst,
	ErrlBase &  i_parent
    );

    
    
    
    /**
     *  @brief Copy-constructor
     *  
     *  Custom copy constructor takes into account
     *  the caller's parent pointer to use it's
     *  memory allocation
     *
     *  @param	i_right
     *	    Source
     *
     *  @param	i_parent
     *	    Base pointer
     *
     */
    ErrlUD(
        const ErrlUD&	i_right,
	ErrlBase &	i_parent
    );


    
    /**
     *  @brief Virtual copy-constructor
     *
     *  Allows for the copy of polymorphic objects
     *  without the need to know the concrete type
     *  
     *  @param	i_owner
     *	    Base Pointer for memory allocation
     *
     *  @return A copy of the object
     *
     */
    virtual ErrlUD *clone(
	ErrlBase & i_owner
    ) const;

    
    
    /**
     *  @brief Cleanup ( destructor )
     *
     *  Releases allocated resources
     *  
     */
    virtual ~ErrlUD();

    
    
    /**
     *  @brief Data Export Size
     *
     *  Amount of flat storage ( in bytes ) required to
     *  store the object.
     *  
     *  @return Export size
     *
     */
    virtual uint32_t flatSize() const;

    
    
    /**
     *  @brief Object formatted display
     *
     *  Correctly formats and displays the contents of
     *  the object in a state usable to ASM.  The method
     *  actually forwards the request to the static print
     *  which can be overridden in linux by library
     *  interception.
     *  
     *  @param	i_parser
     *	    The parser object used to display the output
     *
     */
    virtual void print(
	ErrlParser & i_parser
    );
    

    
    
    /**
     *  @brief Static format display
     *
     *  Method to allow linux library interception
     *  in ppc and conditional compile in the tools
     *  directory.
     *
     *  The need arose to format objects in two different
     *  ways:
     *  1. For flash code asm display ( minimal )
     *  2. For tool driven display
     *
     *  @param	i_parser
     *	    The parser object used to display the output
     *
     *  @param	i_obj
     *	    The object in question
     *
     */
    static void print(
	ErrlParser & i_parser,
	ErrlUD & i_obj 
    );
    
    
    
    /**
     *  @brief Appends data to the section
     *
     *  Grows the section by the given amount
     *  
     *  @param	i_data
     *	    Source data
     *
     *  @param	i_size
     *	    Additional size
     *
     *  @return None
     *
     */
    void addData(
        const void *i_data, 
        uint32_t    i_size
    );

    
    
    /**
     *  @brief Accessor: Component Id
     *
     *  Short-hand notation to the creator id
     *  for the section
     *  
     *  @return Creator Id
     *  
     */
    comp_id_t creator() const;

    
    
    /**
     *  @brief Data size of the section
     *
     *  The distinction is made between data size
     *  and object flat size.  This method returns
     *  the size of the data only
     *  
     *  @return Length
     *
     */
    uint32_t dataSize( void ) const;

    
    
    /**
     *  @brief Data access
     *
     *  Direct Access to the data of the object
     *  ( dangerous - use with caution )
     *  
     *  @return Data pointer
     *
     */
    void * data( void ) const;

    
    
protected:

    uint8_t *	iv_Data;    ///< Data Pointer
    uint32_t	iv_Size;    ///< Data Length

};


/*****************************************************************************/
// Creator Id access
/*****************************************************************************/
inline comp_id_t ErrlUD::creator() const
{
    return iv_header.iv_compId;
}


/*****************************************************************************/
// Get data size
/*****************************************************************************/
inline uint32_t ErrlUD::dataSize( void ) const
{
    return iv_Size;
}


/*****************************************************************************/
// Data access pointer
/*****************************************************************************/
inline void * ErrlUD::data( void ) const
{
    return iv_Data;
}


#endif /* ERRLUD_H */
