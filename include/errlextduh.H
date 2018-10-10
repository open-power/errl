#ifndef ERRLEXTDUH_H
#define ERRLEXTDUH_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errlbase.H>
#include <errlprvt.H>
#include <errlsctnhdr.H>
#include <errlsctn.H>
#include <errlmtms.H>
#include <errlusrparser.H>
#include <errlmtms.H>
#include <srcisrc.H>
     
#include<errlutility.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class ErrlParser;



/*****************************************************************************/
// Constants
/*****************************************************************************/
#define ERRL_SYMPID_LEN  80
#define ERRL_VER_LEN     16         //FW SubSystem and FW Drvier ver length

/*****************************************************************************/
// Synonyms
/*****************************************************************************/

/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class ErrlExtdUH : public ErrlSctn
{
public:

    ErrlExtdUH(
	ErrlBase & i_parent
    );

    
    ErrlExtdUH(
	const ErrlExtdUH & i_right,
	ErrlBase &	    i_parent
    );

    ErrlExtdUH(
        UtilStream & i_stream,
        ErrlSctnHdr &i_hdr,
        ErrlBase &   i_parent
    );

    virtual ErrlExtdUH *clone( ErrlBase & i_owner ) const;
    

    virtual ~ErrlExtdUH();
    
    
    virtual uint32_t flatSize() const;

    
    virtual void unflatten(
        UtilStream &o_stream
     );

    
    
    virtual void print(
	ErrlParser & i_parser
    );

    static void print(
        ErrlParser & i_parser,
        ErrlExtdUH & i_obj
    );




    /**
     *  @brief get Symptom Id
     *  
     *  @This function will return the symptom ID 
     *
     *  @param  nothing
     *
     *  @return const char
     *
     *  @note
     */
  
    const char * getSymptomStr();

    /**
     *  @brief get Symptom Id length
     *
     *  @param  nothing
     *
     *  @return uint8_t (symId Length)
     *
     *  @note
     */
    
    uint8_t SymIdLen();

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


    ErrlMTMS	iv_mtms;
    char        iv_FwReleasedVer[ERRL_VER_LEN+1];
    char        iv_FwSubSysDrvVer[ERRL_VER_LEN+1];
    uint32_t    iv_reserved0;
    BCD_time8_t iv_commnreftime;
    uint16_t    iv_reserved1;
    uint8_t     iv_reserved2;
    uint8_t     iv_symidlen;
    char        iv_symid[ERRL_SYMPID_LEN + 1];      //Null Terminated String

};


#endif //ERRLSYSMTMS_H
