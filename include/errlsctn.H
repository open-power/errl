#ifndef ERRLSCTN_H
#define ERRLSCTN_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errlbase.H>
#include <errlsctnhdr.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class UtilStream;
class ErrlParser;


/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class ErrlSctn : public ErrlBase
{
public:
    

    /**
     * @brief	Factory method for section building
     *
     * All sections of the error log are reconstructed using this
     * factory method when a log is being read in from persistant
     * control store.
    */
    static ErrlSctn * Create(
	ErrlBase &   i_src,
	UtilStream & i_stream
    );
    
    

    /**
     * @brief	Factory method for section building of unknown sections
     *
     * Taking advantage of Linux's weak linkage.  This method provides
     * a convenient default section builder ( User Data ) for flash
     * critical code yet can be overridden by the command line tool
     * to create additional sections which need not be supported on
     * flash.
    */
    static ErrlSctn * CreateUnknown(
	ErrlBase &   i_src,
	UtilStream & i_stream,
	ErrlSctnHdr &i_hdr
    );

    
    
    /**
     * @brief	Default constructor
     *
     * Initializes the base object with all required header information
     *
    */
    ErrlSctn(
        errlSectionId	i_sid, 
        errlslen_t	i_slen, 
        errlver_t	i_ver, 
        errlsubsec_t	i_sst, 
        comp_id_t	i_cid,
	ErrlBase &	i_parent
    );


    
    /**
     * @brief	Import constructor
     *
     * Constructor for receiving external data at object
     * initialization
    */
    ErrlSctn(
	UtilStream &	i_stream,
	ErrlSctnHdr &	i_hdr,
	ErrlBase &	i_parent
    );

    
    
    
    /**
     *  @brief Container based Copy-constructor
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    ErrlSctn(
        const ErrlSctn& i_right,
	ErrlBase &	i_parent
    );

    
    
    
    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    virtual ErrlSctn *clone( ErrlBase & i_owner ) const = 0;


    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    virtual ~ErrlSctn();

    
    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    virtual uint32_t flatSize() const = 0;


    
    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    errlSectionId get_sid() const
    {
        return (errlSectionId)iv_header.iv_sid;
    }

    
    
    
    /**
     *  @brief Access section length
     *  
     *  @return # of flat bytes
     *
     *  @note The section length is updated
     *        upon a flatten so this # may not
     *        be correct
     *  
     */
    uint32_t size() const
    {
        return iv_header.iv_slen;
    }


    
    
    /**
     *  @brief Access section version
     *  
     *  @return Section version
     *
     */
    errlver_t version() const
    {
        return iv_header.iv_ver;
    }


    
    /**
     *  @brief Access the subsection type
     *  
     *  @return Subsection type for the section
     *
     */
    errlsubsec_t sst() const
    {
        return iv_header.iv_sst;
    }


    
    /**
     *  @brief Access the component Id for the section
     *  
     *  @return Component Id of the section creator
     *
     */
    comp_id_t compId() const
    {
	return iv_header.iv_compId;
    }


    
    /**
     *  @brief Set the component Id of the section
     *  
     *  @param	i_val
     *	    New component id
     *
     */
    void compId( comp_id_t i_val )
    {
	iv_header.iv_compId = i_val;
    }


    
    /**
     *  @brief Provides a default print for the optional sections
     *  
     */
    virtual void print(
	ErrlParser & i_parser
    );
    
    
    
    
    /**
     *  @brief Trim to fit a given size
     *  
     *  The default behavior here is to reject the request
     *  as most of the sections will not be able to alter
     *  their size.  The exception at this point is the
     *  User data section.
     *
     *  @param	i_size
     *	    New requested size
     *
     *  @return True/False depending on whether the request
     *          can be satisfied.
     *
     *  @note The default is false;
     *  
     */
    virtual bool Trim(
	uint32_t    i_size
    );


    
protected:

    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    void set_sid( errlSectionId i_sid )
    {
	iv_header.iv_sid = i_sid;
    }

    
    
    // Data
    ErrlSctnHdr	    iv_header;	    ///< Section header



private:

    // Disabled constructs
    ErrlSctn(
        const ErrlSctn& i_right
    );

    ErrlSctn & operator=(
	const ErrlSctn& i_right
    );

};



/*****************************************************************************/
// Constructor
/*****************************************************************************/
inline ErrlSctn::ErrlSctn(
    errlSectionId i_sid, 
    errlslen_t	i_slen, 
    errlver_t	i_ver, 
    errlsubsec_t i_sst, 
    comp_id_t	i_cid,
    ErrlBase &	i_parent
)
: ErrlBase( i_parent ),
  iv_header( i_sid, i_slen, i_ver, i_sst, i_cid )
{
}



/*****************************************************************************/
// Import constructor
/*****************************************************************************/
inline ErrlSctn::ErrlSctn(
    UtilStream & i_stream,
    ErrlSctnHdr &i_hdr,
    ErrlBase &	 i_parent
)
: ErrlBase( i_parent ),
  iv_header( i_hdr )
{
}

/*****************************************************************************/
// Copy-constructor
/*****************************************************************************/
inline ErrlSctn::ErrlSctn(
    const ErrlSctn& i_right,
    ErrlBase &	    i_parent
)
: ErrlBase( i_parent ),
  iv_header( i_right.iv_header )
{
}


/*****************************************************************************/
// Section destructor
/*****************************************************************************/
inline ErrlSctn::~ErrlSctn()
{
}


/*****************************************************************************/
// Default print
/*****************************************************************************/
inline void ErrlSctn::print(
    ErrlParser & i_parser
)
{
}

/*****************************************************************************/
// Trim the fat
/*****************************************************************************/
inline bool ErrlSctn::Trim(
    uint32_t    i_size
)
{
    return false;
}



#endif // ERRLSCTN_H
