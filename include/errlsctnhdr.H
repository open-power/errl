#ifndef ERRLSCTNHDR_H
#define ERRLSCTNHDR_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errlutility.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class UtilStream;

class ErrlParser;


/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class ErrlSctnHdr
{
public:
    
    
    ErrlSctnHdr();

    
    
    ErrlSctnHdr(
        errlSectionId i_sid, 
        errlslen_t i_slen, 
        errlver_t i_ver, 
        errlsubsec_t i_sst, 
        comp_id_t i_cid
    );


    
    void unflatten(
        UtilStream &i_stream
    );

    
    static inline uint32_t flatSize()
    {
        return 8;
    }

    
    void print(
	uint32_t i_slen,
	ErrlParser & i_parse
    );

    // Data
    uint16_t	    iv_sid;
    errlslen_t	    iv_slen;
    errlver_t	    iv_ver;
    errlsubsec_t    iv_sst;
    comp_id_t	    iv_compId;

    // Disabled
    void * operator new( size_t );

};




#endif /* ERRLSCTNHDR_H */
