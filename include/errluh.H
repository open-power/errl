#ifndef ERRLUH_H
#define ERRLUH_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlbase.H>
#include <errlsctnhdr.H>

//define the reserved1 field
#define AMMACK_BYTE 0
#define STATE_BYTE 1
#define HMCACK_BYTE 2

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
class ErrlUH : public ErrlBase
{
public:

    enum constants
    {
	SLEN	= 16,
	VER	= 1,
	SST	= 0
    };

    
    ErrlUH(
	ErrlBase & i_parent
    );
    

    ~ErrlUH();

    
    uint32_t flatSize() const;
    
    
    void unflatten(
        UtilStream &i_stream
    );

    void validate(
        UtilStream &i_stream
    );
    
    void print(
        ErrlParser & i_parser
    );

    

    void scope( errlScope i_scope );


    
    errlScope scope() const;


    
    errlSeverity severity() const;

    
    void setSeverity(
        errlSeverity i_sev
    );



    void setInformationalEvent(
        errlEventType i_etype
    );


    
    uint32_t RC() const;


    void RC(
        uint32_t i_rc
    );

    bool isSymptomSev(
        errlSeverity i_sev
    );

    
    uint16_t ActionFlags() const;

    

    comp_id_t committer() const;


private:

    /**
     *  @brief Method to retrieve if this log contains pels state information
     *  
     *  @param None	
     *
     *  @return bool
     *		True if caller is ASM or errl tool interface 
     *
     *  @note  This field is being used temporarily as
     *	       an internal indicator and data holder of 
     *	       an error logs state information.  This should
     *	       only be getting used when ASM or errl tool
     *	       retreives and error log and tries to display it
     *  
     */
    bool reserved1Valid( void );


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
    uint8_t	iv_ssid;
    uint8_t	iv_scope;
    uint8_t	iv_severity;
    uint8_t	iv_etype;
    uint32_t	iv_rc;
    uint8_t	iv_domain;    // Valid only for "Symptom" severity (0x7x)
    uint8_t	iv_vector;    // Valid only for "Symptom" severity (0x7x)
    uint16_t	iv_actions;
    uint32_t	iv_reserved1;


    // Disabled constructs
    ErrlUH(
	const ErrlUH & i_right
    );

    ErrlUH & operator=(
	const ErrlUH & i_right
    );

};



/*****************************************************************************/
// Constructor
/*****************************************************************************/
inline ErrlUH::ErrlUH(
    ErrlBase  & i_parent
)
: ErrlBase( i_parent ),
  iv_header( ERRL_SID_USER_HEADER, SLEN, VER, SST, 0),
  iv_ssid( 0 ),
  iv_scope( ERRL_SCOPE_PLATFORM ),
  iv_severity( 0 ),
  iv_etype( 0 ),
  iv_rc( 0 ),
  iv_domain( 0 ),
  iv_vector( 0 ),
  iv_actions( 0 ),
  iv_reserved1( 0 )
{
}



/*****************************************************************************/
// Destructor
/*****************************************************************************/
inline ErrlUH::~ErrlUH()
{
}


/*****************************************************************************/
// Export data size
/*****************************************************************************/
inline uint32_t ErrlUH::flatSize() const
{
    return ( iv_header.flatSize() + SLEN );
}



/*****************************************************************************/
// Change the scope
/*****************************************************************************/
inline void ErrlUH::scope( errlScope i_scope )
{
    iv_scope = i_scope;
}



/*****************************************************************************/
// Get the scope
/*****************************************************************************/
inline errlScope ErrlUH::scope() const
{
    return (errlScope) iv_scope;
}



/*****************************************************************************/
// Get the severity
/*****************************************************************************/
inline errlSeverity ErrlUH::severity() const
{
    return (errlSeverity)iv_severity;
}




/*****************************************************************************/
// Get the return code
/*****************************************************************************/
inline uint32_t ErrlUH::RC() const
{
    return iv_rc;
}


/*****************************************************************************/
// Set the return code
/*****************************************************************************/
inline void ErrlUH::RC(
    uint32_t i_rc
)
{
    iv_rc = i_rc;
}


/*****************************************************************************/
// Read action flags
/*****************************************************************************/
inline uint16_t ErrlUH::ActionFlags() const
{
    return iv_actions;
}



/*****************************************************************************/
// Get the committer
/*****************************************************************************/
inline comp_id_t ErrlUH::committer() const
{
    return iv_header.iv_compId;
}





#endif //ERRLUH_H
