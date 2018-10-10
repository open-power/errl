#ifndef ERRLSRC_H
#define ERRLSRC_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errlsctn.H>
#include <srcisrc.H>

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
class ErrlSrc : public ErrlSctn
{
public:
    
    
    /**
     * @brief	Import constructor
     *
     * Constructor for when receiving external data at object
     * initialization
    */
    ErrlSrc(
	UtilStream & i_stream,
	ErrlSctnHdr &i_hdr,
	ErrlBase &   i_parent
    );

    
    ErrlSrc(
        comp_id_t	i_cid, 
        const SrciSrc & i_src,
	bool		i_primary,
	ErrlBase &	i_parent
    );

    
    ErrlSrc(
        const ErrlSrc&	i_right,
	ErrlBase &	i_parent
    );


    virtual ErrlSrc *clone( ErrlBase & i_owner ) const;

    
    virtual ~ErrlSrc();

    
    virtual uint32_t flatSize() const;

    
    virtual void print(
	ErrlParser & i_parser
    );
    
    
    static void print(
	ErrlParser & i_parser,
	ErrlSrc	   & i_obj
    );
    
    
    SrciSrc * SRC();

    

private:

    
    SrciSrc *iv_src;

};



/*****************************************************************************/
// Return the src
/*****************************************************************************/
inline SrciSrc * ErrlSrc::SRC()
{
    return iv_src;
}



#endif //ERRLSRC_H

