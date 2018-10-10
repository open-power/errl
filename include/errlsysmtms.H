#ifndef ERRLSYSMTMS_H
#define ERRLSYSMTMS_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlmtms.H>
#include <errlsctn.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
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
class ErrlSysMtms : public ErrlSctn
{
public:

    ErrlSysMtms(
	UtilStream & i_stream,
	ErrlSctnHdr &i_hdr,
	ErrlBase &   i_parent
    );


    ErrlSysMtms(
        const ErrlSysMtms & i_right,
        ErrlBase &          i_parent
    );

    
    virtual ErrlSysMtms *clone( ErrlBase & i_owner ) const;


    virtual ~ErrlSysMtms();


    virtual uint32_t flatSize() const;
 
    
    void print(
	ErrlParser & i_parser,
	ErrlSysMtms& i_obj
	);	


    virtual void print(
        ErrlParser & i_parser
    );

    
    const char *MachineType(void) const;

    
    const char *SerialNumber(void) const;


private:

    ErrlMTMS	iv_mtms;

    
};



/*****************************************************************************/
// Get machine type
/*****************************************************************************/
inline const char *ErrlSysMtms::MachineType(void) const
{
    return iv_mtms.MachineType();
}

/*****************************************************************************/
// Get Serial Number
/*****************************************************************************/
inline const char *ErrlSysMtms::SerialNumber(void) const
{
    return iv_mtms.SerialNumber();
}


#endif //ERRLSYSMTMS_H
