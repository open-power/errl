#ifndef ERRLTYPES_H
#define ERRLTYPES_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// STD C
#include <stdint.h>

#include <cstdio>

#include <nl_types.h>

/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/


/*****************************************************************************/
// User Types
/*****************************************************************************/

enum errlVerbosity 
{ 
    ERRL_VERBOSE_SHORT			    = 1, 
    ERRL_VERBOSE_FULL			    = 2
};


enum errlCreator 
{ 
    ERRL_CID_HMC			    = 'C', 
    ERRL_CID_SP				    = 'E', 
    ERRL_CID_HYP			    = 'H', 
    ERRL_CID_POWER			    = 'W', 
    ERRL_CID_FIRMWARE			    = 'L',
    ERRL_CID_SLIC			    = 'S',
    ERRL_CID_HOSTBOOT                       = 'B',
    ERRL_CID_OCC                            = 'T',
    ERRL_CID_IODRAWER                       = 'M',
    ERRL_CID_SAPPHIRE                       = 'K',
    ERRL_CID_POWERNV                        = 'P' 
};



enum errlSectionId 
{ 
    ERRL_SID_PRIVATE_HEADER		    = 0x5048, // PH
    ERRL_SID_USER_HEADER		    = 0x5548, // UH
    ERRL_SID_EXTENDED_HEADER                = 0x4548, // EH
    ERRL_SID_PRIMARY_SRC		    = 0x5053, // PS
    ERRL_SID_MACHINE_TYPE		    = 0x4D54, // MT 
    ERRL_SID_SECONDARY_SRC		    = 0x5353, // SS
    ERRL_SID_CALL_HOME		            = 0x4348, // CH 
    ERRL_SID_DUMP_LOCATOR		    = 0x4448, // DH 
    ERRL_SID_SOFTWARE_ERROR		    = 0x5357, // SW 
    ERRL_SID_PARTITION			    = 0x4C50, // LP 
    ERRL_SID_LOGICAL_RESOURCE		    = 0x4C52, // LR 
    ERRL_SID_HMC_ID			    = 0x484D, // HM 
    ERRL_SID_EPOW			    = 0x4550, // EP 
    ERRL_SID_IO_EVENT			    = 0x4945, // IE 
    ERRL_SID_MFG_INFORMATION		    = 0x4D49, // MI 
    ERRL_SID_USER_DEFINED		    = 0x5544, // UD
    ERRL_SID_EXT_USER_DEFINED               = 0x4544, // ED  
    ERRL_SID_ENV_INFO                       = 0x4549  // EI 
};



enum errlScope 
{ 
    ERRL_SCOPE_SINGLE_PART		    = 0x01,	///< Single partition
    ERRL_SCOPE_MULTIPLE_PART		    = 0x02,	///< Multiple partitions
    ERRL_SCOPE_PLATFORM			    = 0x03,	///< Entire Platform ( DEFAULT )
    ERRL_SCOPE_MULTI_PLATFORM		    = 0x04	///< Multiple platforms
};




enum errlSeverity 
{ 
    ERRL_SEV_INFORMATIONAL		    = 0, 
    ERRL_SEV_RECOVERED			    = 0x10,	///< Recovered Error, general
    ERRL_SEV_PREDICTIVE			    = 0x20,	///< Predictive Error, general
    ERRL_SEV_PREDICTIVE_DEGRADED	    = 0x21,	///< Predictive, degraded performance
    ERRL_SEV_PREDICTIVE_CORRECTABLE	    = 0x22,	///< Predictive, may correct after re-ipl
    ERRL_SEV_PREDICTIVE_CORRECTABLE2	    = 0x23,	///< Predictive, degraded perf, re-ipl correctable
    ERRL_SEV_PREDICTIVE_REDUNDANCY_LOST	    = 0x24,	///< Predictive, loss of redundancy
    ERRL_SEV_UNRECOVERABLE		    = 0x40,	///< Unrecoverable, general
    ERRL_SEV_UNRECOVERABLE1		    = 0x41,	///< Unrecoverable, bypassed w/degraded perf
    ERRL_SEV_UNRECOVERABLE2		    = 0x44,	///< Unrecoverable, bypassed w/loss of redundancy
    ERRL_SEV_UNRECOVERABLE3		    = 0x45,	///< Unrecoverable, bypassed w/loss of red+perf
    ERRL_SEV_UNRECOVERABLE4		    = 0x48,	///< Unrecoverable, bypassed w/loss of function
    ERRL_SEV_CRITICAL_FAIL_UNKNOWN          = 0x50,     ///< Critical, Scope of failure unknown
    ERRL_SEV_CRITICAL_SYS_TERM		    = 0x51,	///< Critical, System Termination
    ERRL_SEV_CRITICAL_SYS_FAIL		    = 0x52,	///< Critical, System Failure
    ERRL_SEV_CRITICAL_PART_TERM		    = 0x53,	///< Critical, Partition Termination
    ERRL_SEV_CRITICAL_PART_FAIL		    = 0x54,	///< Critical, Partition Failure
    ERRL_SEV_DIAGNOSTIC_ERROR1		    = 0x60,	///< Disagnostic test error
    ERRL_SEV_DIAGNOSTIC_ERROR2		    = 0x61,	///< Diagnostic test error, resource may produce bad results
    ERRL_SEV_SYMPTOM_RECOVERED	            = 0x71,	///< Symptom Recovered
    ERRL_SEV_SYMPTOM_PREDICTIVE             = 0x72,	///< Symptom Predictive
    ERRL_SEV_SYMPTOM_UNRECOV		    = 0x74,	///< Symptom Unrecoverable
    ERRL_SEV_SYMPTOM_DIAGERR		    = 0x76,	///< Symptom Diag Err
    ERRL_SEV_RESERVED			    = 0xFF	///< Reserved
};


enum errlEventType 
{ 
    ERRL_ETYPE_NOT_APPLICABLE		    = 0, 
    ERRL_ETYPE_MISCELLANEOUS		    = 1, 
    ERRL_ETYPE_TRACING			    = 2,
    ERRL_ETYPE_DUMP_NOTIFICATION	    = 8, 
    ERRL_ETYPE_ERROR_CORRECTED		    = 0x10, 
    ERRL_ETYPE_USER_DECONFIG		    = 0x20, 
    ERRL_ETYPE_SYS_DECONFIG		    = 0x21, 
    ERRL_ETYPE_DECONFIG_NOTE		    = 0x22, 
    ERRL_ETYPE_ENVIRONMENT_NORMAL	    = 0x30, 
    ERRL_ETYPE_CONCURRENT_MAINTENANCE	    = 0x40, 
    ERRL_ETYPE_CAPACITY_UPGRADE		    = 0x60, 
    ERRL_ETYPE_RESOURCE_SPARING		    = 0x70, 
    ERRL_ETYPE_DYNAMIC_RECONFIG		    = 0x80, 
    ERRL_ETYPE_NORMAL_SHUTDOWN		    = 0xD0, 
    ERRL_ETYPE_DIRTY_SHUTDOWN		    = 0xE0 
};




enum errlState 
{ 
    ERRL_STATE_READY			    = 'R', 
    ERRL_STATE_NONE			    = 'N', 
    ERRL_STATE_COMMITTED		    = 'C', 
    ERRL_STATE_PROCESSED		    = 'P', 
    ERRL_STATE_DONE			    = 'D', 
    ERRL_STATE_SENT			    = 'S', 
    ERRL_STATE_RECEIVED			    = 'V', 
    ERRL_STATE_PHYP_NOTIFIED		    = 'X', 
    ERRL_STATE_REPORTED			    = 'E',
    ERRL_STATE_NO_OS_REPORTED               = 'F'
};





/**
 *  @brief Platform Event Log actions
 *  
 *  Several action flags used to trigger various
 *  handling mechanisms for an event log such as
 *  calling home and sending to the hypervisor.
 *
 *  @note Any changes to this list will require changes
 *        to errlinternals.H
 *  
 */
enum errlActions 
{ 
    ERRL_ACTION_NONE			    = 0x0000,	///< No action required
    ERRL_ACTION_REPORT			    = 0x2000,	///< Report Externally (Send to HMC and Hypervisor)
    ERRL_ACTION_SA			    = 0x8000,	///< Service Action (Customer Notification) Required, Report bit automatically set
    ERRL_ACTION_HIDDEN			    = 0x4000,	///< Hidden Error - exclusive with SA Required, Report bit automatically set 
    ERRL_ACTION_REPORT_HMC_ONLY		    = 0x1000,	///< Report to HMC only (Only report to HMC), Report bit automatically set
    ERRL_ACTION_REPORT_HYP_ONLY             = 0x0200,   ///< Report to Hypervisor only  ri05a
    ERRL_ACTION_CALL_HOME		    = 0x0800,	///< Call Home Required 
    ERRL_ACTION_FNM_REQ			    = 0x0400,	///< Further Analysis Required
    ERRL_ACTION_SP_CALL_HOME		    = 0x0100,	///< The service processor should call home

    // The Following are internal actions and should NOT
    // be used by callers unless explicitly allowed.
    ERRL_ACTION_SKIP_ACK                    = 0x0001,	///< Override Error Logger's default ack wait
    ERRL_ACTION_DONT_TERMINATE		    = 0x0002,	///< Override Error Logger's termination call
    ERRL_ACTION_IGNORE_CONSISTENCY_CHECKS   = 0x0004	///< Error Logging infrastrucure will ignore consistency checking on this error log

};

/**
 * @brief Status values
 *
 * Error status values for the various interfaces
 *
*/
enum errlstatus_t
{
    ERRL_STATUS_SUCCESS			    = 0x0000, //
    ERRL_STATUS_CORRUPT			    = 0x0043, //'C'
    ERRL_STATUS_SHORT_SIZE		    = 0x007A, //'z'
    ERRL_STATUS_DUP_ENTRY		    = 0x0044, //'D'
};




/**
 *  @brief Host Response flags
 *  
 *  Host flags used by the hypervisor to communicate with
 *  the error log server through the mailbox interface.
 *
*/
enum errlHostFlags
{
    ERRL_HOST_PHYP		= 0x6870,	// hp - host phyp
    ERRL_HOST_HMC		= 0x6868,	// hh - host hmc
    ERRL_HOST_RTR		= 0x0001,	// Ready to receive
    ERRL_HOST_NRTR		= 0x0002,	// Not ready anymore :-)
    ERRL_HOST_RECEIVED		= 0x0010,	// rv - receivedq
    ERRL_HOST_RECORDED		= 0x0020,	// ro - recorded
    ERRL_HOST_NOTIFIED		= 0x0040,	// notified 
};


/*****************************************************************************/
// Constants
/*****************************************************************************/

/*****************************************************************************/
// Synonyms
/*****************************************************************************/

typedef uint16_t errlidx_t;


typedef uint16_t errlslen_t;


typedef uint8_t errlsubsec_t;


typedef uint8_t errlver_t;


typedef class ErrlEntry *errlHndl_t;

/*****************************************************************************/
// Macros
/*****************************************************************************/


/**
 *  @brief  Handle declaration macro
 *
 *  An error log handle should be declared using this macro to give the
 *  ensure it is properly initialized.  Since the handle is a pointer to
 *  an object this macro just declares it given the name and sets it equal
 *  to NULL.
 *
 *  EXAMPLE:
 *
 *  @code
 *  // Declare an error log handle
 *  ERRL_DECLARE_HANDLE(myHndl);
 *  ...
 *  // Use the handle (provided it is valid)
 *  myHndl->commit( ERRL_COMP_ID );
 *  ...
 *  // Delete the handle
 *  delete myHndl;
 *  @endcode
 *
*/




/*****************************************************************************/
// Prototypes
/*****************************************************************************/

/*****************************************************************************/
// Inlines
/*****************************************************************************/




#endif //ERRLTYPES_H

