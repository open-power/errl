#ifndef ERRLSWERR_H
#define ERRLSWERR_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlsctn.H>

/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class UtilStream;
class ErrlParser;


/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/

class ErrlSwErr : public ErrlSctn
{

public:


    ErrlSwErr(
        UtilStream & i_stream,
	ErrlSctnHdr &i_hdr,
	ErrlBase &   i_parent
    );

    
    ErrlSwErr(
        comp_id_t   i_cid, 
        uint32_t    i_rc, 
        const char *i_fileId, 
        uint32_t    i_codeloc, 
        uint32_t    i_objId,
	ErrlBase &  i_parent
    );

    

    ErrlSwErr(
        const ErrlSwErr& i_right,
	ErrlBase &	 i_parent
    );

    
    virtual ErrlSwErr *clone( ErrlBase & i_owner ) const;


    
    virtual ~ErrlSwErr();

    
    
    virtual uint32_t flatSize() const;

    
    virtual void print(
	ErrlParser & i_parser
    );
    

    static void print(
	ErrlParser & i_parser,
	ErrlSwErr  & i_obj
    );
    
    void setfileId( const char * i_new );


private:

    // Private data
    uint32_t	iv_rc;
    uint32_t	iv_codeloc;
    uint32_t	iv_objId;
    uint8_t	iv_fidSize;
    char *	iv_strFileId;


};


/*****************************************************************************/
// Inlines
/*****************************************************************************/


#endif //ERRLSWERR_H
