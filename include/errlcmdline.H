#ifndef ERRLCMDLINE_H
#define ERRLCMDLINE_H

/**
 *  @file errlcmdline.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section ERRLCMDLINE_H errlcmdline.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#ifndef _AIX
#include <argp.h> 
#endif
#include<errlutility.H>
#include <rtim.H>

/**
 *  @brief Set of operations supported by parser
 *
 *  The following set of operations are supported by the error
 *  log command line executable
 *  
 */
enum ops
{
    NONE,	    ///< No operation selected
    DISPLAY,	    ///< Decode a single event log
    VERSION,        ///< Display version of the tool
    LASTONE	    ///< Invalid 
};

struct opsAscii_t
{
    ops	iv_operation;
    const char * iv_name;
};

static const opsAscii_t OperationToAscii[] =
{
    { NONE, "None Specified"},
    { DISPLAY, "Display Log"}, 
    { LASTONE, "INVALID"} 
};

    
/**
 *  @brief Level of detail when decoding a log ( obsolete )
 *
 *  The level of detail is always full so these values are no
 *  longer useful but kept for legacy reasons
 *  
 */
enum parseType
{
    FULL,
    RAW
};



/**
 *  @brief Create log structure
 *
 *  Set of parameters used in constructing a log
 *  
 */
struct c_log
{
    bool	iv_Comp;	// bool for comp id
    uint16_t	iv_comp;	// component id
    uint8_t	iv_css;		// Creator SubSystem
    uint8_t     iv_fss;         // Failing SubSystem
    uint8_t	iv_sev;		// severity
    uint8_t	iv_etype;	// event type
    bool	iv_commit;	// bool for committing
    uint16_t	iv_actions;	// actions for committing
    bool	iv_Rcode;	// bool for reason code
    uint16_t	iv_rcode;	// reason code
    uint8_t	iv_mod;		// module id
    uint16_t	iv_refcode;	// ref code
    uint32_t	iv_w1;		// word 1
    uint32_t	iv_w2;		// word 2		    
    uint32_t	iv_w3;		// word 3
    uint32_t	iv_w4;		// word 4
    
    bool	iv_ss;		// secondary src
    bool	iv_dh;		// dump locator
    bool	iv_sw;		// firmware error
    bool	iv_lp;		// Impacted Partition Identifier
    bool	iv_lr;		// Logical Resource Identification
    bool	iv_hm;		// HMC ID
    bool	iv_ep;		// EPOW
    bool	iv_ie;		// IO event

};



/**
 *  @brief Arguments structure
 *
 *  Contains the result of parsing through all the command
 *  line parameters.  The convention used is zero for default
 *  which translates into bool false
 *  
 */
struct arguments
{
    ops		iv_operation;	///< Operation requested
    char *	iv_address;	///< IP address if any
    char *	iv_repository;	///< Location of physical file
    bool	iv_binary;	///< Binary dump of log detail
    bool	iv_xmlStarted;	///< XML start header
    bool	iv_xml;		///< XML dump of log detail
    bool	iv_dump;	///< Capture logs ( dump them )
    bool	iv_dall;	///< Dump all logs
    bool        iv_segsafe;     ///< Segmentation fault safe --seg-safe
    bool	iv_creator;	///< Filter using creator ( vs committer )
    comp_id_t *	iv_components;	///< Array of components to filter on
    uint32_t	iv_cidCount;	///< Size of component array filter
    BCD_time8_t	iv_dates[2];	///< Set of filtering dates
    uint32_t	iv_dateCount;	///< Number of valid dates in filter
    bool	iv_info;	///< Filter flags -- informational
    bool	iv_hidden;	///<              -- Hidden
    bool	iv_hmc_ack;	///<              -- HMC acknowledged
    bool        iv_amm_ack;     ///<              -- AMM acknowledged
    bool	iv_hyp_ack;	///<              -- Hypervisor ack'd
    bool	iv_all;		///<              -- Show all
    bool        iv_etype;        ///<              -- Tracing Event
    bool	iv_deleted;	///<              -- Deleted logs
    bool	iv_log_num;	///< Include Event/anchor link numbering when displaying ( for web parsing )
    bool	iv_asc;		///< Reverse sort order ( default is descending )
    uint8_t     iv_Etype;       ///< Enter event type ID
    uint32_t	iv_listmax;	///< Max # of entries to show
    const char *	iv_filename;	///< Display log from file          
    bool        iv_location;    ///< Display Location Code for an entry
    char *	iv_filescrub;	///< I have no idea !
    uint32_t	iv_eid;		///< Identifier ( log id, hom id, etc )
    char *      iv_Src;         ///< SRC               
    uint32_t	iv_WaitForSrv;	///< Wait for ErrlSrv; value in seconds
    parseType	iv_ptype;	///< Parse detail
    char *	iv_trace;	///< Location of trexStringFile
    bool	iv_on;		///< Generic on/off switch for some commands
    c_log	iv_cl;		///< Log creation flags
    bool	iv_skipTrace;	///< Don't display fsp trace after error log
    uint32_t	iv_slevel;	///< Level of status information user wants
    uint32_t	iv_nfssz;	///< Size of history.log on NFS in megabytes
    uint32_t    iv_dlevel;      ///< Mention the debug tracing level 0/1  
    bool        iv_ltrace;      ///< option to display the hexdump of trace 
    const char * iv_outdir;
};


/*****************************************************************************/
// Constants
/*****************************************************************************/
extern const char *argp_program_version;

extern const char *argp_program_bug_address;

extern struct argp argp;

extern int g_ErrlDebugLevel;

/*****************************************************************************/
// Prototypes
/*****************************************************************************/
#ifndef _AIX
error_t parse_opt(int key, char *arg, struct argp_state *state);   
#endif

#endif //ERRLCMDLINE_H
