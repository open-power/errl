#ifndef ERRLSWV2_H
#define ERRLSWV2_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errlsctn.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class ErrlParser;


/*****************************************************************************/
// User Types
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
class ErrlSwV2 : public ErrlSctn
{
public:

    
    ErrlSwV2(
        UtilStream & i_stream,
	ErrlSctnHdr &i_hdr,
	ErrlBase &   i_parent
    );
    
    
    ErrlSwV2(
        comp_id_t   i_cid, 
        uint32_t    i_rc, 
        uint16_t    i_fileId, 
        uint16_t    i_codeloc, 
        uint32_t    i_objId,
	ErrlBase &  i_parent
    );

    
    
    ErrlSwV2(
        const ErrlSwV2& i_right,
	ErrlBase &	i_parent
    );

    
    
    virtual ErrlSwV2 *clone( ErrlBase & i_owner ) const;


    
    virtual ~ErrlSwV2();

    
    
    virtual uint32_t flatSize() const;

    
    
    virtual void print(
	ErrlParser & i_parser
    );
    
    
    
    static void print(
        ErrlParser & i_parse,
	ErrlSwV2 & i_obj
    );


    /**
     *  @brief Returns the currently stored return code
     *
    */
    uint32_t getrc( void ) const;



    /**
     *  @brief Change the return code
     *
    */
    void setrc( uint32_t i_rc );



    /**
     *  @brief Return the current code location
     *
    */
    uint16_t getcodeloc( void ) const;




    /**
     *  @brief Returns the file Id in the form of a constant char *
     *
    */
    uint16_t getfileId( void ) const;



private:

    uint32_t iv_rc;
    uint16_t iv_fileId;
    uint16_t iv_codeloc;
    uint32_t iv_objId;


};



/*****************************************************************************/
// Inlines
/*****************************************************************************/


/*****************************************************************************/
// Return code
/*****************************************************************************/
inline uint32_t ErrlSwV2::getrc( void ) const
{
    return iv_rc;
}



/*****************************************************************************/
// Change return code
/*****************************************************************************/
inline void ErrlSwV2::setrc( uint32_t i_rc )
{
    iv_rc = i_rc;
}



/*****************************************************************************/
// Get location code
/*****************************************************************************/
inline uint16_t ErrlSwV2::getcodeloc( void ) const
{
    return iv_codeloc;
}



/*****************************************************************************/
// Get file Identifier
/*****************************************************************************/
inline uint16_t ErrlSwV2::getfileId( void ) const
{
    return iv_fileId;
}







#endif //ERRLSWV2_H

