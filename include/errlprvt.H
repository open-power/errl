#ifndef ERRLPRVT_H
#define ERRLPRVT_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlbase.H>
#include <errlsctnhdr.H>
#include <rtim.H>
#include <errlutility.H>
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
class ErrlPrvt : public ErrlBase
{
public:
    
    enum constants
    {
	MIN_SCTN_CNT	= 2,
	SLEN		= 40,
	VER		= 1,
	SST		= 0,
	CSS_VER		= 8
    };

    
    /**
     *  @brief Import Constructor
     *  
     *  Constructs and unflattens in one shot
     *
     *  @param	i_stream
     *	    Data source
     *
     *  @param	i_parent
     *	    Object parent
     *
     *  @return None
     *
     */
    ErrlPrvt(
	UtilStream & i_stream,
	ErrlBase &   i_parent
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
    ~ErrlPrvt();

    
    
    
    
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
    uint32_t flatSize() const;

    
    
    
    
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
    void unflatten(
        UtilStream &i_stream
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
    uint32_t plid();


    
    
    
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
    uint32_t eid() const;


    
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
    void creator(
	comp_id_t i_val
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
    comp_id_t creator() const;

    
    
    
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
    errlCreator creatorSubSys() const;


    
    
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
    BCD_time8_t const& created() const;


    
    
    
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
    uint8_t & sections();


    
    
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
    void print(
	ErrlParser & i_parse
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
    bool isCommitted() const;
   
    
    /**
     *  @brief Used to set cssver field in prvt section 
     *  
     *  @param	const char * string
     *	    
     *
     *  @return none 
     *
     *  @note  This field is not in use by anything other
     *	       than to keep track of the logs committed
     *	       due to the registry key errl/CommitAll 
     *  
     */
    void setCssVer( const char * i_val );


private:

    /**
     *  @brief Checks the freshly imported data for correctness
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    void Validate(
	UtilStream &i_stream
    );

    
    

    ErrlSctnHdr	iv_header;
    BCD_time8_t	iv_created;
    BCD_time8_t iv_committed;
    uint8_t	iv_cid;
    uint8_t	iv_reserved0;
    bool	iv_commitflag;
    uint8_t	iv_sctns;
    uint32_t	iv_reserved1;
    uint8_t	iv_cssver[CSS_VER];
    uint32_t	iv_plid;
    uint32_t	iv_eid;

    
    // Disabled constructs
    ErrlPrvt(
	const ErrlPrvt & i_right
    );

    ErrlPrvt & operator=(
	const ErrlPrvt & i_right
    );
};



/*****************************************************************************/
// Destructor
/*****************************************************************************/
inline ErrlPrvt::~ErrlPrvt()
{
}


/*****************************************************************************/
// Export data size
/*****************************************************************************/
inline uint32_t ErrlPrvt::flatSize() const
{
    return ( iv_header.flatSize() + SLEN );
}

/*****************************************************************************/
// Get plid
/*****************************************************************************/
inline uint32_t ErrlPrvt::plid()
{
    return iv_plid;
}




/*****************************************************************************/
// Get Entry Id
/*****************************************************************************/
inline uint32_t ErrlPrvt::eid() const
{
    return iv_eid;
}



/*****************************************************************************/
// Creator access
/*****************************************************************************/
inline void ErrlPrvt::creator(
    comp_id_t i_val
)
{
    iv_header.iv_compId = i_val;
}



/*****************************************************************************/
// Creator access
/*****************************************************************************/
inline comp_id_t ErrlPrvt::creator() const
{
    return iv_header.iv_compId;
}




/*****************************************************************************/
// Creator subsystem
/*****************************************************************************/
inline errlCreator ErrlPrvt::creatorSubSys() const
{
    return ( errlCreator ) iv_cid;
}



/*****************************************************************************/
// Created timestamp
/*****************************************************************************/
inline BCD_time8_t const& ErrlPrvt::created() const
{
    return iv_created;
}




/*****************************************************************************/
// Section count
/*****************************************************************************/
inline uint8_t & ErrlPrvt::sections()
{
    return iv_sctns;
}


/*****************************************************************************/
// Committed flag check
/*****************************************************************************/
inline bool ErrlPrvt::isCommitted() const
{
    return iv_commitflag;
}


#endif //ERRLPRVT_H
