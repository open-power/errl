
#ifndef ERRLINTERNALS_H
#define ERRLINTERNALS_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlentry.H>
#include <errlprvt.H>
#include <errluh.H>
#include <errlextduh.H>
#include <errlsrc.H>
#include <srcisrc.H>
#include <errno.h>
#include <errl_service_codes.H>
#include <utilfile.H>

// ERRL INTERNAL ACTION FLAGS
const uint16_t ERRL_ACTION_ALL	    = ERRL_ACTION_REPORT	    |
				      ERRL_ACTION_SA		    |
				      ERRL_ACTION_HIDDEN	    |
				      ERRL_ACTION_REPORT_HMC_ONLY   |
				      ERRL_ACTION_CALL_HOME	    |
				      ERRL_ACTION_FNM_REQ	    |
				      ERRL_ACTION_SP_CALL_HOME	    |
				      ERRL_ACTION_SKIP_ACK	    |
				      ERRL_ACTION_DONT_TERMINATE;

// Actions allowed for informationals
// Note: Not allowed to use the "HMC_ONLY" flag since FipS logs should
//       not be using that feature.
const uint16_t ERRL_ACTION_INFO_ONLY= ERRL_ACTION_REPORT	    |
                                      ERRL_ACTION_HIDDEN            |
				      ERRL_ACTION_SKIP_ACK          |
				      ERRL_ACTION_DONT_TERMINATE;

// Actions allowed for hidden
const uint16_t ERRL_ACTION_HIDDEN_ONLY= ERRL_ACTION_REPORT	    |
                                      ERRL_ACTION_HIDDEN            |
				      ERRL_ACTION_SKIP_ACK          |
				      ERRL_ACTION_DONT_TERMINATE;


// Severity Categories
enum errlSevCat
{
    ERRL_SEVCAT_RECOVERED	= 1,
    ERRL_SEVCAT_PREDICTIVE	= 2,
    ERRL_SEVCAT_UNRECOVERABLE	= 4,
    ERRL_SEVCAT_CRITICAL	= 5,
    ERRL_SEVCAT_DIAGNOSTIC	= 6,
    ERRL_SEVCAT_SYMPTOM		= 7
};
    

// Subsystem Categories
enum errlSsdCat
{
    ERRL_SSDCAT_PROCESSOR	= 1,
    ERRL_SSDCAT_MEMORY		= 2,
    ERRL_SSDCAT_IOHUB		= 3,
    ERRL_SSDCAT_IOADAPTER	= 4,
    ERRL_SSDCAT_CEC_HW		= 5,
    ERRL_SSDCAT_POWER	 	= 6,
    ERRL_SSDCAT_OTHERS   	= 7,
    ERRL_SSDCAT_FIRMWARE 	= 8,
    ERRL_SSDCAT_SOFTWARE 	= 9,
    ERRL_SSDCAT_ENVIRONMENT	= 10,
    ERRL_SSDCAT_RESERVED   	= 11
};
    
// As per the findings in defect 500709, pfw appends 24 bytes of header
// to any fsp error logs, thus we need to subtract this from our max of 2K
const uint32_t ERRL_PFW_HDR_SIZE = 24;
    
const uint32_t ERRL_ENTRY_MAX = 16384;


/*****************************************************************************/
// Total sections in the log ( required + optional )
/*****************************************************************************/
inline uint8_t ErrlEntry::sections() const
{
    uint8_t l_rc = 2;   //Default required section PH,UH

    if ( iv_prisrc )
    {
	l_rc++;
    }
    if ( iv_extduh )
    {
	l_rc++;
    }

    l_rc += iv_optCount;

    return l_rc;
}



/*****************************************************************************/
// Read created timestamp
/*****************************************************************************/
inline const BCD_time8_t &ErrlEntry::created() const
{
    return iv_prvt->created();
}



/*****************************************************************************/
// Read creator Id of the entire log
/*****************************************************************************/
inline comp_id_t ErrlEntry::committer() const
{
    return iv_usrhdr->committer();
}
#endif //ERRLINTERNALS_H
