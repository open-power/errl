// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/occc/fsp/plugins/occcSrcParse.H 1.289.1.2 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2013,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
// includes from occ code base 
// /afs/austin.ibm.com/projects/esw/occ/occ920/Builds/occ920_180307a/occ/src 
#ifndef _COMP_IDS_H 
#define _COMP_IDS_H 
 
#define COMP_NAME_SIZE       4 
 
#define MAIN_COMP_ID         0x0100 
#define MAIN_COMP_NAME       "MAIN" 
 
 
#define ERRL_COMP_ID         0x0200 
#define ERRL_COMP_NAME       "ERRL" 
 
#define TRAC_COMP_ID         0x0300 
#define TRAC_COMP_NAME       "TRAC" 
 
#define RTLS_COMP_ID         0x0400 
#define RTLS_COMP_NAME       "RTLS" 
 
#define THRD_COMP_ID         0x0500 
#define THRD_COMP_NAME       "THRD" 
 
#define SNSR_COMP_ID         0x0600 
#define SNSR_COMP_NAME       "SNSR" 
 
// Applet Manager 
#define APLT_COMP_ID         0x0700 
#define APLT_COMP_NAME       "APLT" 
 
#define PSS_COMP_ID          0x0800 
#define PSS_COMP_NAME        "PSS" 
 
#define TMER_COMP_ID         0x0900 
#define TMER_COMP_NAME       "TMER" 
 
#define DCOM_COMP_ID         0x0A00 
#define DCOM_COMP_NAME       "DCOM" 
 
// Proc data 
#define PROC_COMP_ID         0x0B00 
#define PROC_COMP_NAME       "PROC" 
 
// Amec data 
#define AMEC_COMP_ID         0x0C00 
#define AMEC_COMP_NAME       "AMEC" 
 
// Centaur data 
#define CENT_COMP_ID         0x0D00 
#define CENT_COMP_NAME       "CENT" 
 
// Command Handler 
#define CMDH_COMP_ID         0x0E00 
#define CMDH_COMP_NAME       "CMDH" 
 
// DIMM State Manager 
#define DIMM_COMP_ID         0x0F00 
#define DIMM_COMP_NAME       "DIMM" 
 
// MEMORY Control 
#define MEM_COMP_ID          0x1000 
#define MEM_COMP_NAME        "MEM" 
 
// Workload Optimize Frequency 
#define WOF_COMP_ID          0x1100 
#define WOF_COMP_NAME        "WOF" 
 
// PGPE Interface 
#define PGPE_COMP_ID         0x1200 
#define PGPE_COMP_NAME       "PGPE" 
 
// GPU Interface 
#define GPU_COMP_ID          0x1300 
#define GPU_COMP_NAME        "GPU" 
 
#endif 
 
#ifndef _AMEC_SERVICE_CODES_H_ 
#define _AMEC_SERVICE_CODES_H_ 
 
/*----------------------------------------------------------------------------*/ 
/* Includes                                                                   */ 
/*----------------------------------------------------------------------------*/ 
 
/*----------------------------------------------------------------------------*/ 
/* Constants                                                                  */ 
/*----------------------------------------------------------------------------*/ 
 
/*----------------------------------------------------------------------------*/ 
/* Globals                                                                    */ 
/*----------------------------------------------------------------------------*/ 
 
/*----------------------------------------------------------------------------*/ 
/* Defines                                                                    */ 
/*----------------------------------------------------------------------------*/ 
 
/*----------------------------------------------------------------------------*/ 
/* Typedef / Enum                                                             */ 
/*----------------------------------------------------------------------------*/ 
enum occAmecModuleId 
{ 
    AMEC_INITIALIZE_FW_SENSORS        =    AMEC_COMP_ID | 0x00, 
    AMEC_UPDATE_FW_SENSORS            =    AMEC_COMP_ID | 0x01, 
    AMEC_VECTORIZE_FW_SENSORS         =    AMEC_COMP_ID | 0x02, 
    AMEC_AMESTER_INTERFACE            =    AMEC_COMP_ID | 0x03, 
    AMEC_PCAP_CONN_OC_CONTROLLER      =    AMEC_COMP_ID | 0x04, 
    AMEC_MST_CHECK_PCAPS_MATCH        =    AMEC_COMP_ID | 0x05, 
    AMEC_MST_CHECK_UNDER_PCAP         =    AMEC_COMP_ID | 0x06, 
    AMEC_SLAVE_CHECK_PERFORMANCE      =    AMEC_COMP_ID | 0x07, 
    AMEC_HEALTH_CHECK_PROC_TEMP       =    AMEC_COMP_ID | 0x08, 
    AMEC_HEALTH_CHECK_DIMM_TEMP       =    AMEC_COMP_ID | 0x09, 
    AMEC_HEALTH_CHECK_CENT_TEMP       =    AMEC_COMP_ID | 0x10, 
    AMEC_HEALTH_CHECK_DIMM_TIMEOUT    =    AMEC_COMP_ID | 0x11, 
    AMEC_HEALTH_CHECK_CENT_TIMEOUT    =    AMEC_COMP_ID | 0x12, 
    AMEC_HEALTH_CHECK_VRFAN_TIMEOUT   =    AMEC_COMP_ID | 0x13, 
    AMEC_HEALTH_CHECK_PROC_TIMEOUT    =    AMEC_COMP_ID | 0x14, 
    AMEC_CALC_DTS_SENSORS             =    AMEC_COMP_ID | 0x16, 
    AMEC_SET_FREQ_RANGE               =    AMEC_COMP_ID | 0x17, 
    AMEC_UPDATE_APSS_GPIO             =    AMEC_COMP_ID | 0x18, 
    AMEC_GPU_PCAP_MID                 =    AMEC_COMP_ID | 0x19, 
    AMEC_HEALTH_CHECK_VRM_VDD_TEMP    =    AMEC_COMP_ID | 0x1A, 
    AMEC_HEALTH_CHECK_VRM_VDD_TIMEOUT =    AMEC_COMP_ID | 0x1B, 
}; 
 
/*----------------------------------------------------------------------------*/ 
/* Function Prototypes                                                        */ 
/*----------------------------------------------------------------------------*/ 
 
#endif /* #ifndef _AMEC_SERVICE_CODES_H_ */ 
 
#ifndef _CENTAUR_DATA_SERVICE_CODES_H_ 
#define _CENTAUR_DATA_SERVICE_CODES_H_ 
 
//************************************************************************* 
// Includes 
//************************************************************************* 
 
//************************************************************************* 
// Externs 
//************************************************************************* 
 
//************************************************************************* 
// Macros 
//************************************************************************* 
 
//************************************************************************* 
// Defines/Enums 
//************************************************************************* 
enum centModuleId 
{ 
    CENT_TASK_DATA_MOD       = CENT_COMP_ID | 0x00, 
    CENTAUR_INIT_MOD         = CENT_COMP_ID | 0x01, 
    CENT_CONTROL_MOD         = CENT_COMP_ID | 0x02, 
    CENT_RECOVERY_MOD        = CENT_COMP_ID | 0x03, 
}; 
 
//************************************************************************* 
// Structures 
//************************************************************************* 
 
//************************************************************************* 
// Globals 
//************************************************************************* 
 
//************************************************************************* 
// Function Prototypes 
//************************************************************************* 
 
//************************************************************************* 
// Functions 
//************************************************************************* 
 
#endif /* #ifndef _CENTAUR_DATA_SERVICE_CODES_H_ */ 
 
#ifndef CMDH_SERVICE_CODES_H 
#define CMDH_SERVICE_CODES_H 
 
 
enum occCmdhModuleId 
{ 
    DATA_STORE_GENERIC_DATA             =  CMDH_COMP_ID | 0x00, 
    DATA_STORE_FREQ_DATA                =  CMDH_COMP_ID | 0x01, 
    DATA_STORE_PCAP_DATA                =  CMDH_COMP_ID | 0x02, 
    CMDH_GENERIC_CMD_FAILURE            =  CMDH_COMP_ID | 0x04, 
    DATA_STORE_SYS_DATA                 =  CMDH_COMP_ID | 0x05, 
    DATA_STORE_APSS_DATA                =  CMDH_COMP_ID | 0x06, 
    DATA_GET_THRM_THRESHOLDS            =  CMDH_COMP_ID | 0x08, 
    DATA_STORE_IPS_DATA                 =  CMDH_COMP_ID | 0x09, 
    DATA_GET_IPS_DATA                   =  CMDH_COMP_ID | 0x0A, 
    DATA_GET_RESET_PREP_ERRL            =  CMDH_COMP_ID | 0x0B, 
    CMDH_OCC_INTERRUPT_TYPE             =  CMDH_COMP_ID | 0x0C, 
}; 
#endif 
 
#ifndef _DCOM_SERVICE_CODES_H_ 
#define _DCOM_SERVICE_CODES_H_ 
 
 
enum dcomModuleId 
{ 
    DCOM_MID_INIT_ROLES             =  DCOM_COMP_ID | 0x00, 
    DCOM_MID_TASK_RX_SLV_INBOX      =  DCOM_COMP_ID | 0x01, 
    DCOM_MID_TASK_TX_SLV_INBOX      =  DCOM_COMP_ID | 0x02, 
    DCOM_MID_INIT_PBAX_QUEUES       =  DCOM_COMP_ID | 0x03, 
    DCOM_MID_TASK_RX_SLV_OUTBOX     =  DCOM_COMP_ID | 0x04, 
    DCOM_MID_TASK_TX_SLV_OUTBOX     =  DCOM_COMP_ID | 0x05, 
    DCOM_MID_SLV_OUTBOX_TX_DOORBELL =  DCOM_COMP_ID | 0x06, 
    DCOM_MID_TASK_WAIT_FOR_MASTER   =  DCOM_COMP_ID | 0x07, 
    DCOM_MID_ERROR_CHECK            =  DCOM_COMP_ID | 0x08, 
    DCOM_MID_WAIT_FOR_MASTER        =  DCOM_COMP_ID | 0x09, 
    DCOM_MID_PBAX_ERROR_HANDLER     =  DCOM_COMP_ID | 0x0A, 
    DCOM_MID_BUILD_SLV_INBOX        =  DCOM_COMP_ID | 0x0B, 
}; 
 
#endif /* #ifndef _DCOM_SERVICE_CODES_H_ */ 
 
#ifndef _DIMM_SERVICE_CODES_H_ 
#define _DIMM_SERVICE_CODES_H_ 
 
 
enum dimmModuleId 
{ 
    DIMM_MID_STATE_MACHINE         =  DIMM_COMP_ID | 0x00, 
    DIMM_MID_NIMBUS_INIT           =  DIMM_COMP_ID | 0x01, 
    DIMM_MID_DIMM_SM               =  DIMM_COMP_ID | 0x02, 
    DIMM_MID_MARK_DIMM_FAILED      =  DIMM_COMP_ID | 0x03, 
}; 
 
#endif /* #ifndef _DIMM_SERVICE_CODES_H_ */ 
 
#ifndef _GPU_SERVICE_CODES_H_ 
#define _GPU_SERVICE_CODES_H_ 
 
 
enum gpuModuleId 
{ 
    GPU_MID_INIT                      =  GPU_COMP_ID | 0x00, 
    GPU_MID_GPU_SM                    =  GPU_COMP_ID | 0x01, 
    GPU_MID_MARK_GPU_FAILED           =  GPU_COMP_ID | 0x02, 
    GPU_MID_GPU_SCHED_REQ             =  GPU_COMP_ID | 0x03, 
    GPU_MID_GPU_SCHED_RSP             =  GPU_COMP_ID | 0x04, 
    GPU_MID_GPU_RESET_SM              =  GPU_COMP_ID | 0x05, 
    GPU_MID_GPU_READ_TEMP             =  GPU_COMP_ID | 0x06, 
    GPU_MID_GPU_READ_MEM_TEMP         =  GPU_COMP_ID | 0x07, 
    GPU_MID_GPU_READ_MEM_TEMP_CAPABLE =  GPU_COMP_ID | 0x08, 
    GPU_MID_GPU_CHECK_DRIVER_LOADED   =  GPU_COMP_ID | 0x09, 
    GPU_MID_GPU_READ_PWR_LIMIT        =  GPU_COMP_ID | 0x0A, 
    GPU_MID_GPU_SET_PWR_LIMIT         =  GPU_COMP_ID | 0x0B, 
    GPU_MID_GPE_GPU_INIT_SCHED_REQ    =  GPU_COMP_ID | 0x0C, 
}; 
 
#endif /* #ifndef _GPU_SERVICE_CODES_H_ */ 
 
#ifndef _MEMORY_SERVICE_CODES_H 
#define _MEMORY_SERVICE_CODES_H 
 
//************************************************************************* 
// Includes 
//************************************************************************* 
 
 
enum memModuleId 
{ 
    MEM_MID_TASK_MEMORY_CONTROL    = MEM_COMP_ID | 0x00, 
    MEM_MID_MEMORY_INIT            = MEM_COMP_ID | 0x01, 
    MEM_MID_MEM_INIT_POWER_CONTROL = MEM_COMP_ID | 0x02, 
    MEM_MID_GPE_MEM_POWER_CONTROL  = MEM_COMP_ID | 0x03, 
}; 
 
#endif // _MEMORY_SERVICE_CODES_H 
 
#ifndef _OCC_SERVICE_CODES_H_ 
#define _OCC_SERVICE_CODES_H_ 
 
 
// Error log reason codes. 
enum occReasonCode 
{ 
    /// Generic OCC firmware error log with extended srcs. 
    INTERNAL_FAILURE                = 0x00, 
    /// Informational periodic call home log 
    GEN_CALLHOME_LOG                = 0x01, 
    /// Failure within the OCC Complex of the processor 
    PREP_FOR_RESET                  = 0x02, 
    /// Invalid Input Data received from FSP 
    INVALID_INPUT_DATA              = 0x03, 
    /// Oversubscription was asserted 
    OVERSUB_ALERT                   = 0x05, 
    /// Failure to maintain a hard power cap 
    POWER_CAP_FAILURE               = 0x06, 
    /// Timed out reading a FRU temperature 
    FRU_TEMP_TIMEOUT                = 0x09, 
    /// Processor reached error threshold 
    PROC_ERROR_TEMP                 = 0x10, 
    /// Timed out reading processor temperature 
    PROC_TEMP_TIMEOUT               = 0x11, 
    // OCI write did not retain value 
    OCI_WRITE_FAILURE               = 0x12, 
    /// Processor SCOM failure 
    PROC_SCOM_ERROR                 = 0x16, 
    /// Any failure coming from the SSX RTOS code 
    SSX_GENERIC_FAILURE             = 0x17, 
    /// Failure to handshake with an external fw entity (HB, FSP, PHYP, etc) 
    EXTERNAL_INTERFACE_FAILURE      = 0x18, 
    /// VRM Vdd reached error temperature threshold 
    VRM_VDD_ERROR_TEMP              = 0x20, 
    /// VR_FAN  - AVS Bus over-temperature reported 
    VRM_VRFAN_WARNING               = 0x22, 
    /// GPIO_VR_HOT_MEM_PROC signal from APSS asserted 
    VR_HOT_MEM_PROC_ASSERTED        = 0x23, 
    /// DIMM reached error threshold 
    DIMM_ERROR_TEMP                 = 0x30, 
    /// Frequency limited due to oversubscription condition 
    OVERSUB_LIMIT_ALERT             = 0x33, 
    /// Invalid configuration data (MRW, etc.) 
    INVALID_CONFIG_DATA             = 0x34, 
    /// Centaur reached error threshold 
    CENT_ERROR_TEMP                 = 0x40, 
    /// Centaur in-band scom failure 
    CENT_SCOM_ERROR                 = 0x41, 
    /// Centaur FIR bit set 
    CENT_LFIR_ERROR                 = 0x42, 
    AVSBUS_TIMEOUT                  = 0x50, 
    AVSBUS_ERROR                    = 0x51, 
    AVSBUS_CRC_ERROR                = 0x52, 
    /// Throttle in nominal or turbo mode due to the bulk power limit being reached with both power supplies good 
    PCAP_THROTTLE_POWER_LIMIT       = 0x61, 
    /// Firmware Failure: equivalent to assertion failures 
    INTERNAL_FW_FAILURE             = 0xA0, 
 
    /// Build problem, gpe1 image doesn't support GPU interface 
    GPU_NO_GPE_SUPPORT              = 0xA1, 
    /// Error with GPU tasks 
    GPU_FAILURE                     = 0xA2, 
    /// GPU core reached error threshold 
    GPU_ERROR_TEMP                  = 0xA3, 
    /// GPU memory reached error threshold 
    GPU_MEMORY_ERROR_TEMP           = 0xA4, 
 
    /// Failure within the OCC Complex of the processor 
    INTERNAL_HW_FAILURE             = 0xB0, 
    /// OCC GPE halted due to checkstop 
    OCC_GPE_HALTED                  = 0xB1, 
    /// Data passed as an argument or returned from a function is invalid 
    INTERNAL_INVALID_INPUT_DATA     = 0xB3, 
    /// RTL detected a system checkstop 
    OCC_SYSTEM_HALTED               = 0xB5, 
    ///  Reset PBA Queue due to PBAX Read Failure 
    PBAX_QUEUE_RESET                = 0xBA, 
    ///  Request to read APSS data failed. 
    APSS_GPE_FAILURE                = 0xC0, 
    /// AVS Bus output over-current reported 
    VRM_OVER_CURRENT_WARNING        = 0xC1, 
    /// Slave OCC failed to receive new APSS data over a short time interval 
    APSS_SLV_SHORT_TIMEOUT          = 0xC3, 
    /// Slave OCC failed to receive new APSS data over a long time interval 
    APSS_SLV_LONG_TIMEOUT           = 0xC4, 
    /// APSS failed to return data or returned bad data over a long time interval 
    APSS_HARD_FAILURE               = 0xC5, 
    ///  Request to read redundant APSS data failed 
    REDUNDANT_APSS_GPE_FAILURE      = 0xCB, 
    MEMORY_INIT_FAILED              = 0xD1, 
    DIMM_INVALID_STATE              = 0xD2, 
 
    // PGPE Generic RC 
    PGPE_FAILURE                    = 0xD3, 
 
    /// GPE IPC TASK RCs 
    GPE_REQUEST_CREATE_FAILURE      = 0xD4, 
    GPE_REQUEST_SCHEDULE_FAILURE    = 0xD5, 
    GPE_REQUEST_TASK_TIMEOUT        = 0xD6, 
    GPE_REQUEST_TASK_NOT_IDLE       = 0xD7, 
    GPE_REQUEST_RC_FAILURE          = 0xD8, 
 
    WOF_DISABLED_RC                 = 0xDA, 
    INVALID_MAGIC_NUMBER            = 0xDC, 
    INVALID_FREQUENCY               = 0xDE, 
    WOF_RE_ENABLED                  = 0xDF, 
 
 
// NOTE: 0xE0 - 0xEF can NOT be used these are reserved for critical 
// OCC errors.  (H)TMGT will be looking for 0xEy ERRL_RC in cmd response RC 
// and create an OCC error log with OCC component ID and 0xEy RC if found 
 
    SENSOR_MAIN_MEM_ERROR           = 0xF0,  // Error copying sensors to main memory 
    INBAND_CMD_ERROR                = 0xF1, 
    OPAL_TABLE_UPDATE_ERROR         = 0xF2, 
 
    /// Success! 
    OCC_SUCCESS_REASON_CODE         = 0xFF, 
}; 
 
// Extended reason codes 
enum occExtReasonCode 
{ 
    OCC_NO_EXTENDED_RC                          = 0x0000, 
 
    ERC_GENERIC_TIMEOUT                         = 0x0001, 
    ERC_INVALID_INPUT_DATA                      = 0x0002, 
    ERC_MMU_MAP_FAILURE                         = 0x0003, 
    ERC_MMU_UNMAP_FAILURE                       = 0x0004, 
    ERC_BCE_REQUEST_CREATE_FAILURE              = 0x0005, 
    ERC_BCE_REQUEST_SCHEDULE_FAILURE            = 0x0006, 
 
    ERC_RUNNING_SEM_PENDING_FAILURE             = 0x0007, 
    ERC_RUNNING_SEM_POSTING_FAILURE             = 0x0008, 
    ERC_WAKEUP_SEM_PENDING_FAILURE              = 0x0009, 
    ERC_WAKEUP_SEM_POSTING_FAILURE              = 0x000a, 
    ERC_FINISHED_SEM_PENDING_FAILURE            = 0x000b, 
    ERC_FINISHED_SEM_POSTING_FAILURE            = 0x000c, 
    ERC_CALLER_SEM_POSTING_FAILURE              = 0x000d, 
    ERC_CREATE_SEM_FAILURE                      = 0x000e, 
 
    ERC_LOW_CORE_GPE_REQUEST_CREATE_FAILURE     = 0x000f, 
    ERC_HIGH_CORE_GPE_REQUEST_CREATE_FAILURE    = 0x0010, 
 
    ERC_SSX_IRQ_SETUP_FAILURE                   = 0x0012, 
    ERC_SSX_IRQ_HANDLER_SET_FAILURE             = 0x0013, 
    ERC_PPC405_WD_SETUP_FAILURE                 = 0x0014, 
    ERC_OCB_WD_SETUP_FAILURE                    = 0x0015, 
    ERC_ARG_POINTER_FAILURE                     = 0x0016, 
 
    ERC_PSS_GPIO_INIT_FAIL                      = 0x0017, 
    ERC_PSS_COMPOSITE_MODE_FAIL                 = 0x0019, 
 
    ERC_PROC_CONTROL_TASK_FAILURE               = 0x001a, 
 
    ERC_CENTAUR_PORE_FLEX_CREATE_FAILURE        = 0x0021, 
    ERC_CENTAUR_PORE_FLEX_SCHEDULE_FAILURE      = 0x0022, 
    ERC_CENTAUR_INTERNAL_FAILURE                = 0x0023, 
 
    ERC_APSS_GPIO_OUT_OF_RANGE_FAILURE          = 0x0024, 
    ERC_APSS_GPIO_DUPLICATED_FAILURE            = 0x0025, 
    ERC_APSS_ADC_OUT_OF_RANGE_FAILURE           = 0x0026, 
    ERC_APSS_ADC_DUPLICATED_FAILURE             = 0x0027, 
    ERC_APSS_NO_VALID_DATA                      = 0x0028, 
    ERC_APSS_RESET_FAILURE                      = 0x0029, 
 
    ERC_AMEC_PCAPS_MISMATCH_FAILURE             = 0x002A, 
    ERC_AMEC_UNDER_PCAP_FAILURE                 = 0x002B, 
 
    ERC_AMEC_SLAVE_OVS_STATE                    = 0x002D, 
    ERC_AMEC_SLAVE_POWERCAP                     = 0x002E, 
 
    ERC_AMEC_PROC_ERROR_OVER_TEMPERATURE        = 0x002F, 
 
    ERC_AMEC_VRM_VDD_TEMP_TIMEOUT               = 0x0030, 
    ERC_AMEC_DIMM_TEMP_TIMEOUT                  = 0x0031, 
    ERC_AMEC_CENT_TEMP_TIMEOUT                  = 0x0032, 
 
    ERC_CMDH_MBOX_REQST_FAILURE                 = 0x0040, 
    ERC_CMDH_INTERNAL_FAILURE                   = 0x0041, 
    ERC_CMDH_THRM_DATA_MISSING                  = 0x0042, 
    ERC_CMDH_IPS_DATA_MISSING                   = 0x0043, 
    ERC_CMDH_INVALID_ATTN_DATA                  = 0x0044, 
 
    ERC_CHIP_IDS_INVALID                        = 0x0050, 
    ERC_GETSCOM_FAILURE                         = 0x0051, 
    ERC_GETSCOM_TPC_GP0_FAILURE                 = 0x0052, 
    ERC_PNOR_OWNERSHIP_NOT_AVAILABLE            = 0x0053, 
 
    ERC_HOMER_MAIN_ACCESS_ERROR                 = 0x0060, 
    ERC_HOMER_MAIN_SSX_ERROR                    = 0x0061, 
 
    ERC_APSS_SCHEDULE_FAILURE                   = 0x0062, 
    ERC_APSS_COMPLETE_FAILURE                   = 0x0063, 
 
    ERC_PROC_CONTROL_INIT_FAILURE               = 0x0064, 
    ERC_PROC_PSTATE_INSTALL_FAILURE             = 0x0065, 
    ERC_PROC_CORE_DATA_EMPATH_ERROR             = 0x0066, 
    ERC_NEST_DTS_GPE_REQUEST_CREATE_FAILURE     = 0x0067, 
 
    ERC_BCE_REQ_CREATE_READ_FAILURE             = 0x0070, 
    ERC_BCE_REQ_SCHED_READ_FAILURE              = 0x0071, 
    ERC_BCE_REQ_CREATE_INPROG_FAILURE           = 0x0072, 
    ERC_BCE_REQ_SCHED_INPROG_FAILURE            = 0x0073, 
    ERC_BCE_REQ_CREATE_WRITE_FAILURE            = 0x0074, 
    ERC_BCE_REQ_SCHED_WRITE_FAILURE             = 0x0075, 
    ERC_BCE_REQ_CALLBACK_TIMEOUT                = 0x0076, 
 
    ERC_DIMM_SCHEDULE_FAILURE                   = 0x0080, 
    ERC_DIMM_COMPLETE_FAILURE                   = 0x0081, 
 
    ERC_MEM_CONTROL_SCHEDULE_FAILURE            = 0x0080, 
    ERC_MEM_CONTROL_COMPLETE_FAILURE            = 0x0081, 
 
    ERC_FW_ZERO_FREQ_LIMIT                      = 0x0090, 
 
    ERC_TLB_ENTRY_CREATION_FAILURE              = 0x00A0, 
 
    ERC_AVSBUS_VDD_VOLTAGE_FAILURE              = 0x00AA, 
    ERC_AVSBUS_VDD_CURRENT_FAILURE              = 0x00AB, 
    ERC_AVSBUS_VDN_VOLTAGE_FAILURE              = 0x00AC, 
    ERC_AVSBUS_VDN_CURRENT_FAILURE              = 0x00AD, 
    ERC_AVSBUS_STATUS_FAILURE                   = 0x00AE, 
    ERC_AVSBUS_VDD_TEMPERATURE_FAILURE          = 0x00AF, 
 
    ERC_PGPE_BEACON_TIMEOUT                     = 0x00B0, 
    ERC_PGPE_CLIP_NOT_IDLE                      = 0x00B1, 
    ERC_PGPE_SET_PMCR_NOT_IDLE                  = 0x00B2, 
    ERC_PGPE_START_SUSPEND_NOT_IDLE             = 0x00B3, 
    ERC_PGPE_SET_PMCR_FAILURE                   = 0x00B4, 
    ERC_PGPE_START_SUSPEND_FAILURE              = 0x00B5, 
    ERC_PGPE_SET_NOMINAL_FAILURE                = 0x00B6, 
    ERC_PGPE_CLIP_FAILURE                       = 0x00B7, 
    ERC_PGPE_PPMR_OPPB_SIZE_MISMATCH            = 0x00B8, 
    ERC_PGPE_ACTIVE_TO_OBSERVATION_TIMEOUT      = 0x00B9, 
    ERC_PGPE_TASK_TIMEOUT                       = 0x00BA, 
    ERC_PGPE_INVALID_ADDRESS                    = 0x00BB, 
 
    ERC_WOF_QUAD_COUNT_FAILURE                  = 0x00C0, 
    ERC_WOF_CONTROL_ERROR                       = 0x00C1, 
 
    ERC_24X7_GPE_CREATE_FAILURE                 = 0x00D0, 
    ERC_24X7_GPE_SCHEDULE_FAILURE               = 0x00D1, 
 
    ERC_SMGR_NO_VALID_MODE_TRANSITION_CALL      = 0x00E0, 
    ERC_SMGR_NO_VALID_STATE_TRANSITION_CALL     = 0x00E1, 
 
    ERC_GPU_COMPLETE_FAILURE                    = 0x00F0, 
    ERC_GPU_SCHEDULE_FAILURE                    = 0x00F1, 
    ERC_GPU_RESET_FAILURE                       = 0x00F2, 
    ERC_GPU_RESET_TIMEOUT                       = 0x00F3, 
    ERC_GPU_READ_TEMP_TIMEOUT                   = 0x00F4, 
    ERC_GPU_READ_MEM_TEMP_TIMEOUT               = 0x00F5, 
    ERC_GPU_READ_MEM_TEMP_CAPABLE_FAILURE       = 0x00F6, 
    ERC_GPU_INVALID_GPU_OPERATION               = 0x00F7, 
    ERC_GPU_N_MODE_PCAP_CALC_FAILURE            = 0x00F8, 
    ERC_GPU_N_PLUS_1_MODE_PCAP_CALC_FAILURE     = 0x00F9, 
    ERC_GPU_NO_GPE_SUPPORT                      = 0x00FF, 
    ERC_GPU_CHECK_DRIVER_LOADED_FAILURE         = 0x0100, 
    ERC_GPU_READ_PWR_LIMIT_FAILURE              = 0x0101, 
    ERC_GPU_SET_PWR_LIMIT_FAILURE               = 0x0102, 
 
    ERC_STATE_FROM_OBS_TO_ACT_FAILURE           = 0x0123, 
    ERC_STATE_FROM_ACT_TO_CHR_FAILURE           = 0x0124, 
    ERC_STATE_FROM_CHR_TO_ACT_FAILURE           = 0x0125, 
    ERC_STATE_FROM_CHR_TO_OBS_FAILURE           = 0x0126, 
    ERC_STATE_FROM_OBS_TO_CHR_FAILURE           = 0x0127, 
    ERC_STATE_FROM_STB_TO_CHR_FAILURE           = 0x0128, 
    ERC_STATE_FROM_STB_TO_OBS_FAILURE           = 0x0129, 
 
    ERC_STATE_HEARTBEAT_CFG_FAILURE             = 0x0180, 
    ERC_RTL_TIME_EXCEEDED                       = 0x0190, 
}; 
 
// Error log Module Ids 
enum occModuleId 
{ 
    MAIN_MID                        =  MAIN_COMP_ID | 0x01, 
    MAIN_THRD_ROUTINE_MID           =  MAIN_COMP_ID | 0x02, 
    MAIN_THRD_TIMER_MID             =  MAIN_COMP_ID | 0x03, 
    MAIN_THRD_SEM_INIT_MID          =  MAIN_COMP_ID | 0x04, 
    MAIN_STATE_TRANSITION_MID       =  MAIN_COMP_ID | 0x05, 
    MAIN_MODE_TRANSITION_MID        =  MAIN_COMP_ID | 0x06, 
    MAIN_SYSTEM_HALTED_MID          =  MAIN_COMP_ID | 0x07, 
    OCC_IPC_SETUP                   =  MAIN_COMP_ID | 0x08, 
    GETSCOM_FFDC_MID                =  MAIN_COMP_ID | 0x0a, 
    PUTSCOM_FFDC_MID                =  MAIN_COMP_ID | 0x0b, 
    HMON_ROUTINE_MID                =  MAIN_COMP_ID | 0x0c, 
    FIR_DATA_MID                    =  MAIN_COMP_ID | 0x0e, 
    CMDH_DBUG_MID                   =  MAIN_COMP_ID | 0x0f, 
    I2C_LOCK_UPDATE                 =  MAIN_COMP_ID | 0x10, 
    CREATE_TLB_ENTRY                =  MAIN_COMP_ID | 0x11, 
    READ_PGPE_HEADER                =  MAIN_COMP_ID | 0x12, 
    READ_PPMR_HEADER                =  MAIN_COMP_ID | 0x13, 
    READ_OPPB_PARAMS                =  MAIN_COMP_ID | 0x14, 
    MAIN_SMGR_MID                   =  MAIN_COMP_ID | 0x15, 
    READ_WOF_HEADER                 =  MAIN_COMP_ID | 0x16, 
}; 
 
enum occUserDataType 
{ 
    OCC_FULL_ELOG_TYPE              =   0x0000,                 // complete error log data 
    OCC_TRACE_TYPE                  =   0x0002,                 // OCC trace (from TMGT) 
    OCC_EXCEPTION_TYPE              =   0x00E0,                 // OCC exception data (from TMGT) 
}; 
 
enum occUserDataVersion 
{ 
    OCC_FULL_ELOG_TYPE_VER1         =   0x0001,                 // complete error log data ver 1 
}; 
 
#endif /* #ifndef _OCC_SERVICE_CODES_H_ */ 
 
#ifndef _PGPE_SERVICE_CODES_H_ 
#define _PGPE_SERVICE_CODES_H_ 
 
 
enum pgpeModuleId 
{ 
    PGPE_INIT_CLIPS_MOD              = PGPE_COMP_ID | 0x00, 
    PGPE_INIT_PMCR_MOD               = PGPE_COMP_ID | 0x01, 
    PGPE_INIT_START_SUSPEND_MOD      = PGPE_COMP_ID | 0x02, 
    PGPE_INIT_WOF_CONTROL_MOD        = PGPE_COMP_ID | 0x03, 
    PGPE_INIT_WOF_VFRT_MOD           = PGPE_COMP_ID | 0x04, 
    PGPE_CLIP_UPDATE_MOD             = PGPE_COMP_ID | 0x05, 
    PGPE_START_SUSPEND_MOD           = PGPE_COMP_ID | 0x06, 
    PGPE_PMCR_SET_MOD                = PGPE_COMP_ID | 0x07, 
    PGPE_SET_CLIP_RANGES_MOD         = PGPE_COMP_ID | 0x08, 
    PGPE_SET_CLIP_BLOCKING_MOD       = PGPE_COMP_ID | 0x09, 
    PGPE_START_SUSPEND_CALLBACK_MOD  = PGPE_COMP_ID | 0x0A, 
}; 
 
 
#endif /* #ifndef _PGPE_SERVICE_CODES_H_ */ 
 
#ifndef _PROC_DATA_SERVICE_CODES_H_ 
#define _PROC_DATA_SERVICE_CODES_H_ 
 
 
enum procModuleId 
{ 
    PROC_TASK_CORE_DATA_MOD         = PROC_COMP_ID | 0x00, 
    PROC_CORE_INIT_MOD              = PROC_COMP_ID | 0x01, 
    PROC_TASK_FAST_CORE_DATA_MOD    = PROC_COMP_ID | 0x02, 
    PROC_GPST_INIT_FAILURE_MOD      = PROC_COMP_ID | 0x03, 
    PROC_ENABLE_PSTATES_SMH_MOD     = PROC_COMP_ID | 0x04, 
    PROC_PSTATE_KVM_SETUP_MOD       = PROC_COMP_ID | 0x05, 
    PROC_TASK_NEST_DTS_MOD          = PROC_COMP_ID | 0x06, 
    PROC_NEST_DTS_INIT_MOD          = PROC_COMP_ID | 0x07, 
    PROC_24X7_MOD                   = PROC_COMP_ID | 0x08, 
    PROC_POP_OPAL_TBL_TO_MEM_MOD    = PROC_COMP_ID | 0x09, 
    PROC_CHECK_FOR_OPAL_UPDATES_MOD = PROC_COMP_ID | 0x0A, 
}; 
 
#endif /* #ifndef _PROC_DATA_SERVICE_CODES_H_ */ 
 
#ifndef _PSS_SERVICE_CODES_H_ 
#define _PSS_SERVICE_CODES_H_ 
 
 
enum pssModuleId 
{ 
    PSS_MID_APSS_INIT              =  PSS_COMP_ID | 0x00, 
    PSS_MID_APSS_START_MEAS        =  PSS_COMP_ID | 0x01, 
    PSS_MID_APSS_CONT_MEAS         =  PSS_COMP_ID | 0x02, 
    PSS_MID_APSS_COMPLETE_MEAS     =  PSS_COMP_ID | 0x03, 
    PSS_MID_DPSS_INIT              =  PSS_COMP_ID | 0x04, 
    PSS_MID_DPSS_OVS_IRQ_INIT      =  PSS_COMP_ID | 0x05, 
    PSS_MID_DPSS_RD_STATUS         =  PSS_COMP_ID | 0x06, 
    PSS_MID_DO_APSS_RECOVERY       =  PSS_COMP_ID | 0x07, 
    PSS_MID_AVSBUS_READ            =  PSS_COMP_ID | 0x08, 
    PSS_MID_APSS_RESET             =  PSS_COMP_ID | 0x09, 
}; 
 
#endif /* #ifndef _PSS_SERVICE_CODES_H_ */ 
 
#ifndef _RTLS_SERVICE_CODES_H_ 
#define _RTLS_SERVICE_CODES_H_ 
 
 
enum rtlsModuleId 
{ 
    RTLS_OCB_INIT_MOD                 = RTLS_COMP_ID | 0x00, 
    RTLS_DO_TICK_MOD                  = RTLS_COMP_ID | 0x01, 
    RTLS_START_TASK_MOD               = RTLS_COMP_ID | 0x02, 
    RTLS_STOP_TASK_MOD                = RTLS_COMP_ID | 0x03, 
    RTLS_TASK_RUNABLE_MOD             = RTLS_COMP_ID | 0x04, 
    RTLS_SET_TASK_DATA_MOD            = RTLS_COMP_ID | 0x05, 
    RTLS_TASK_CORE_DATA_CONTROL_MOD   = RTLS_COMP_ID | 0x06, 
}; 
 
#endif /* #ifndef _RTLS_SERVICE_CODES_H_ */ 
 
#ifndef _SENSOR_SERVICE_CODES_H_ 
#define _SENSOR_SERVICE_CODES_H_ 
 
 
enum occSensorModuleId 
{ 
    // Sensors 
    SENSOR_QUERY_LIST                = SNSR_COMP_ID | 0x00, 
    SENSOR_INITIALIZE                = SNSR_COMP_ID | 0x01, 
 
    // Main memory sensors 
    MM_SENSORS_INIT_MOD              = SNSR_COMP_ID | 0x10, 
    MM_SENSORS_UPDATE_MOD            = SNSR_COMP_ID | 0x11, 
    MM_SENSORS_BCE_COPY_MOD          = SNSR_COMP_ID | 0x12, 
    MM_SENSORS_IS_BCE_REQ_IDLE_MOD   = SNSR_COMP_ID | 0x13, 
    MM_SENSORS_WRITE_DATA_HDR_MOD    = SNSR_COMP_ID | 0x14, 
    MM_SENSORS_VALIDATE_DATA_HDR_MOD = SNSR_COMP_ID | 0x15, 
    MM_SENSORS_WRITE_NAMES_MOD       = SNSR_COMP_ID | 0x16, 
    MM_SENSORS_WRITE_READINGS_MOD    = SNSR_COMP_ID | 0x17, 
    MM_SENSORS_VALIDATE_READINGS_MOD = SNSR_COMP_ID | 0x18, 
 
    // Inband commands 
    INBAND_CMD_IS_BCE_REQ_IDLE_MOD   = SNSR_COMP_ID | 0x20, 
    INBAND_CMD_BCE_COPY_MOD          = SNSR_COMP_ID | 0x21, 
    INBAND_CMD_HANDLER_MOD           = SNSR_COMP_ID | 0x22, 
    INBAND_CMD_CHECK_MOD             = SNSR_COMP_ID | 0x23, 
 
    // Get time of day task 
    GET_TOD_IS_REQ_IDLE_MOD          = SNSR_COMP_ID | 0x30, 
    GET_TOD_HNDL_REQ_RSLT_MOD        = SNSR_COMP_ID | 0x31, 
    GET_TOD_SCHED_REQ_MOD            = SNSR_COMP_ID | 0x32, 
}; 
 
#endif /* #ifndef _SENSOR_SERVICE_CODES_H_ */ 
 
#ifndef _THREAD_SERVICE_CODES_H_ 
#define _THREAD_SERVICE_CODES_H_ 
 
 
enum thrdModuleId 
{ 
    THRD_MID_INIT_THREAD_SCHDLR     =  THRD_COMP_ID | 0x00, 
    THRD_MID_THREAD_SWAP_CALLBACK   =  THRD_COMP_ID | 0x01, 
    THRD_MID_GEN_CALLHOME_LOG       =  THRD_COMP_ID | 0x02, 
    THRD_THERMAL_VRM_FAN_CONTROL    =  THRD_COMP_ID | 0x03, 
    THRD_THERMAL_MAIN               =  THRD_COMP_ID | 0x04, 
}; 
 
#endif /* #ifndef _THREAD_SERVICE_CODES_H_ */ 
 
#ifndef _TIMER_SERVICE_CODES_H_ 
#define _TIMER_SERVICE_CODES_H_ 
 
//************************************************************************* 
// Includes 
//************************************************************************* 
 
//************************************************************************* 
// Externs 
//************************************************************************* 
 
//************************************************************************* 
// Macros 
//************************************************************************* 
 
//************************************************************************* 
// Defines/Enums 
//************************************************************************* 
enum occTimerModuleId 
{ 
    INIT_WD_TIMERS                  =  TMER_COMP_ID | 0x00, 
    POKE_WD_TIMERS                  =  TMER_COMP_ID | 0x01, 
}; 
 
//************************************************************************* 
// Structures 
//************************************************************************* 
 
//************************************************************************* 
// Globals 
//************************************************************************* 
 
//************************************************************************* 
// Function Prototypes 
//************************************************************************* 
 
//************************************************************************* 
// Functions 
//************************************************************************* 
 
#endif /* #ifndef _TIMER_SERVICE_CODES_H_ */ 
 
#ifndef _TRAC_SERVICE_CODES_H_ 
#define _TRAC_SERVICE_CODES_H_ 
 
//************************************************************************* 
// Includes 
//************************************************************************* 
 
//************************************************************************* 
// Externs 
//************************************************************************* 
 
//************************************************************************* 
// Macros 
//************************************************************************* 
 
//************************************************************************* 
// Defines/Enums 
//************************************************************************* 
enum tracReasonCodes 
{ 
    TRAC_ERROR_BLOCK_ALLOCATE                       =  TRAC_COMP_ID | 0x00, 
    TRAC_ERROR_COMP_NOT_FOUND                       =  TRAC_COMP_ID | 0x01, 
    TRAC_MEM_ALLOC_FAIL                             =  TRAC_COMP_ID | 0x02, 
    TRAC_MEM_BUFF_TOO_SMALL                         =  TRAC_COMP_ID | 0x03, 
    TRAC_INVALID_PARM                               =  TRAC_COMP_ID | 0x04, 
    TRAC_DATA_SIZE_TOO_LARGE                        =  TRAC_COMP_ID | 0x05, 
    TRAC_DATA_SIZE_LESS_THAN_HEADER_SIZE            =  TRAC_COMP_ID | 0x06, 
    TRAC_CIRCULAR_BUFF_FULL                         =  TRAC_COMP_ID | 0x07, 
}; 
 
//************************************************************************* 
// Structures 
//************************************************************************* 
 
//************************************************************************* 
// Globals 
//************************************************************************* 
 
//************************************************************************* 
// Function Prototypes 
//************************************************************************* 
 
//************************************************************************* 
// Functions 
//************************************************************************* 
 
#endif /* #ifndef _TRAC_SERVICE_CODES_H_ */ 
 
#ifndef _WOF_SERVICE_CODES_H_ 
#define _WOF_SERVICE_CODES_H_ 
 
 
enum wofModuleId 
{ 
    DISABLE_WOF                         =  WOF_COMP_ID | 0x01, 
    ENABLE_WOF                          =  WOF_COMP_ID | 0x02, 
    SET_CLEAR_WOF_DISABLED              =  WOF_COMP_ID | 0x03, 
}; 
 
 
 
 
 
#endif /* #ifndef _WOF_SERVICE_CODES_H_ */ 
 
