// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgt_service_codes.H 1.11.16.74 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2005,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC:
// $Source: fips760 fsp/src/tmgt/fsp/tmgt_service_codes.H 2$

#ifndef TMGT_SERVICE_CODES_H
#define TMGT_SERVICE_CODES_H

/**
 *  @file tmgt_service_codes.H
 *
 *  @brief This file contains the definition of constants used to create SRCs
 *         and error logs.
 *
 */


#include <fips_comp_id.H>         // component identifiers


enum tmgtReturnCodes
{
    TMGT_RC_NONE                  = 0,                   // No Return Code?
    TMGT_RC_VPD_ERROR             = TMGT_COMP_ID | 0x00, // Could not read calibration data from VPD
    TMGT_RC_INTERNAL_ERROR        = TMGT_COMP_ID | 0x01, // Internal error with sending request to TMGT process
    TMGT_RC_INVALID_PROC_RID      = TMGT_COMP_ID | 0x03, // Processor FRU RID is not present in TMGT config tables
    TMGT_RC_BUFFER_TOO_SMALL      = TMGT_COMP_ID | 0x07, // Buffer passed to tmgt is not large enough for return data
    TMGT_RC_SPIF_CMD_FAIL         = TMGT_COMP_ID | 0x09, // Command to powr via spif failed.
    TMGT_RC_OCC_CHECKPOINT_ERROR  = TMGT_COMP_ID | 0x0E, // Error waiting for OCC initialization checkpoint
    TMGT_RC_NO_SUPPORT            = TMGT_COMP_ID | 0x0F, // Processor card VPD thermal index is 0x00 - no thermal support
    TMGT_RC_REGISTRY_READ_FAIL    = TMGT_COMP_ID | 0x14, // Registry read failure
    TMGT_RC_OCC_RESET             = TMGT_COMP_ID | 0x15, // OCCs being reset
    TMGT_RC_OCC_CRIT_FAILURE      = TMGT_COMP_ID | 0x16, // OCCs being held in reset
    TMGT_RC_SEND_FAIL             = TMGT_COMP_ID | 0x18, // I2C send failure
    TMGT_RC_CHECKSUM_FAIL         = TMGT_COMP_ID | 0x19, // I2C data checksum failure
    TMGT_RC_OCC_CMD_FAIL          = TMGT_COMP_ID | 0x1B, // OCC command failure
    TMGT_RC_TPMF_CMD_FAIL         = TMGT_RC_OCC_CMD_FAIL, // (used in IPMI)
    TMGT_RC_INVALID_LENGTH        = TMGT_COMP_ID | 0x1C, // Bad length specified
    TMGT_RC_OCC_ERROR_LOG         = TMGT_COMP_ID | 0x1D, // OCC error log entry for build error log in toif
    TMGT_RC_VPD_FAIL              = TMGT_COMP_ID | 0x1F, // SVPD_get_max_number_of_RIDs call failed
    TMGT_RC_OCC_COMM_FAILURE      = TMGT_COMP_ID | 0x22, // Communication failure to the OCC
    TMGT_RC_INVALID_DATA          = TMGT_COMP_ID | 0x23, // One or more parm values are not valid (also see OUT_OF_RANGE)
    TMGT_RC_OCC_UNAVAILABLE       = TMGT_COMP_ID | 0x24, // OCC is not is in the correct state
    TMGT_RC_TPMD_UNAVAILABLE      = TMGT_RC_OCC_UNAVAILABLE, // (used in HMCX)
    TMGT_RC_IPMI_FAIL             = TMGT_COMP_ID | 0x26, // Call to IPMI failed
    TMGT_RC_KEY_WORD_FAIL         = TMGT_COMP_ID | 0x27, // SVPD_findkeywordData call failed
    TMGT_RC_PRESENT_STATE_PROHIBITS = TMGT_COMP_ID | 0x28, // Cannot execute cmd in current state (IPMI 0xD5)
    TMGT_RC_PARAMETER_OUT_OF_RANGE  = TMGT_COMP_ID | 0x29, // One or more parms out of range (IPMI 0xC9)
    TMGT_RC_NOT_PRESENT           = TMGT_COMP_ID | 0x2A, // Requested sensor, data, or record is not present (IPMI 0xCB)
    TMGT_RC_REGISTRY_WRITE_FAIL   = TMGT_COMP_ID | 0x2C, // Registry write failure
    TMGT_RC_OVERSUBSCRIBED        = TMGT_COMP_ID | 0x2D, // OCC oversubscribed while in mnfg mode (used in CCMM)
    TMGT_RC_TPMF_DOWNLOAD         = TMGT_COMP_ID | 0x2E, // (used in IPMI)
    TMGT_RC_NO_CHANGE             = TMGT_COMP_ID | 0x2F, // No change to customer selected mode
    TMGT_RC_TURBO_DISABLED        = TMGT_COMP_ID | 0x30, // Turbo Frequency is not allowed
    TMGT_RC_NO_POWER_FOR_MEMORY   = TMGT_COMP_ID | 0x31, // Not enough power available for memory
    TMGT_RC_INVALID_MEM_THROTTLE  = TMGT_COMP_ID | 0x32, // Invalid memory throttle values were found
    TMGT_RC_SEQUENCE_MISMATCH     = TMGT_COMP_ID | 0x34,
    TMGT_RC_TIMEOUT               = TMGT_COMP_ID | 0x35,
    TMGT_RC_MODE_CHANGE_FAILURE   = TMGT_COMP_ID | 0x37,
    TMGT_RC_MODE_CHANGE_SUCCESS   = TMGT_COMP_ID | 0x38, // Mode change was successful - no error
    TMGT_RC_PARSER_ERROR          = TMGT_COMP_ID | 0x3E, // power_management def file parser error
    TMGT_RC_DEF_FILE_ERROR        = TMGT_COMP_ID | 0x3F, // invalid parameter specified in the def file
    TMGT_RC_OCC_RESET_FAILURE     = TMGT_COMP_ID | 0x40,
    TMGT_RC_OCC_LOADSTART_FAILURE = TMGT_COMP_ID | 0x41,
    TMGT_RC_INVALID_PARAMETER     = TMGT_COMP_ID | 0x45,
    TMGT_RC_CHIC_GET_MEMORY_ERROR = TMGT_COMP_ID | 0x4C,
    TMGT_RC_MISSING_DATA          = TMGT_COMP_ID | 0x4F,
    TMGT_RC_CIMP_FAIL             = TMGT_COMP_ID | 0x52,
    TMGT_RC_ECMD_DBUF_COPY_FAIL   = TMGT_COMP_ID | 0x53,
    TMGT_RC_TARGET_NOT_FUNCTIONAL = TMGT_COMP_ID | 0x54,
    TMGT_RC_FILE_ERROR            = TMGT_COMP_ID | 0x55, // File access error
    TMGT_RC_SYS_MODEL_ERROR       = TMGT_COMP_ID | 0x56, // Error from SM/MRW
    TMGT_RC_UNKNOWN_PCI_CARD      = TMGT_COMP_ID | 0x57, // Error from PHYP
    TMGT_RC_MAX_FAN_SPEED         = TMGT_COMP_ID | 0x58, // Max RPM increase request error
    TMGT_RC_TUN_PARM_TBL_OOB      = TMGT_COMP_ID | 0x60, // Value in TMGT DPS Tunable Parm Table has an out of bounds value
    TMGT_RC_TUN_PARM_UNIT_MISMATCH = TMGT_COMP_ID | 0x61, // Unit type in TMGT DPS Tunable Parm Table doesn't match tmgt/energyScaleTuningParms
    TMGT_RC_INVALID_TUN_PARM      = TMGT_COMP_ID | 0x62, // Invalid or missing parameter in tmgt/energyScaleTuningParms file
    TMGT_RC_INVALID_OCC_ELOG      = TMGT_COMP_ID | 0x63, // Invalid elog data from OCC
    TMGT_RC_HWSV_TARGET_MISSING   = TMGT_COMP_ID | 0x64, // getTopLevelTarget failed
    TMGT_RC_PCAP_CALC_COMPLETE    = TMGT_COMP_ID | 0xB9, // Powercap calculation/distribution has completed

    // The following errors are from the Client/Server communication errors
    TMGT_RC_DELIVERY_ERROR        = TMGT_COMP_ID | 0xD1, // NACK received
    TMGT_RC_NO_DAEMON             = TMGT_COMP_ID | 0xD2, // TMGT server daemon process does not exist or not ready in allowed time period
    TMGT_RC_IPC_ERROR             = TMGT_COMP_ID | 0xD3, // an error has occurred in the underlying IPC
    TMGT_RC_UNDEFINED_DAEMON_RESPONSE = TMGT_COMP_ID | 0xD4, // Response message from TMGTt notifier daemon is undefined

    TMGT_RC_ENERGYSCALE_FFDC      = TMGT_COMP_ID | 0xFD, // EnergyScale FFDC elog - generated on tmgtCollectOccFFDC()
};





/** @enum tmgtModId
 *        "Module ids" for tmgt SRCs
 *        Actually, these are ids assigned to each function/method within
 *        a module (.C file).  The ids must be unique across all component
 *        modules
 */
enum tmgtModId
{
    // tmgt.C - Client calls
    TMGT_MODID_TALK_TO_SERVER           = 0x01,
    TMGT_MODID_POWER_STATUS_REG         = 0x02,
    TMGT_MODID_POWER_HW_ERROR_REG       = 0x03,
    TMGT_MODID_COLLECT_FFDC             = 0x04,
    TMGT_MODID_ACTIVATE_PCAP            = 0x05,
    TMGT_MODID_GET_PWR_LIMIT            = 0x06,
    TMGT_MODID_PEX_PCAP                 = 0x07,
    TMGT_POWER_EXECUTIVE_PASS_THROUGH   = 0x08,
    TMGT_SET_CUST_REQUESTED_MODE        = 0x0A,
    TMGT_FAILED_TO_UNFLATTEN_ERROR      = 0x10,
    TMGT_CHANGE_SYS_PWR_MGT_MODE        = 0x11,
    TMGT_MODID_SET_PRE_SET_WATTS        = 0x13,
    TMGT_MODID_PEX_FIND_FW_INSTANCE     = 0x17,
    TMGT_MODID_PCAP                     = 0x18,
    TMGT_MODID_ATTEMPT_SAFE_MODE_EXIT   = 0x19,
    TMGT_MODID_SMS                      = 0x1A,
    TMGT_MODID_MAX_PCI                  = 0x1B,
    TMGT_MODID_TRAN_FILE_DISABLE_OCC    = 0x1C,
    TMGT_MODID_ADD_ES_USER_DETAILS      = 0x1D,
    TMGT_MODID_OCC_EXECUTE_COMMAND      = 0x1E,
    TMGT_MODID_GET_OCC_INSTANCES        = 0x1F,

    // tmgtserver.C
    TMGT_PERC_GET_ERROR_DATA            = 0x20,
    TMGT_INIT_DAEMON                    = 0x22,
    TMGT_PROCESS_REQUESTS               = 0x23,
    TMGT_MODID_GET_RESOURCE_INFO        = 0x31,
    TMGT_MODID_GET_SYS_TYPE             = 0x32,
    TMGT_MODID_GET_MBOX_TIMEOUTS        = 0x33,
    TMGT_MODID_GET_MAX_NODES            = 0x34,
    TMGT_MODID_GET_POWER_CAPS           = 0x35,
    TMGT_MODID_OPAL_MODE                = 0x36,
    TMGT_MODID_Set_PCAP                 = 0x37,

    // tmgtserverfunctions.C
    TMGT_MODID_EXIT_SAFE_MODE           = 0x39,
    TMGT_MODID_INIT_DPS_DEFAULT         = 0x3A,
    TMGT_MODID_SEND_AME_COMMAND         = 0x3B,
    TMGT_MODID_EHI_CFM                  = 0x3C,
    TMGT_MODID_REREAD_DEF_FILE          = 0x3D,
    TMGT_MODID_EHI_CMD                  = 0x3E,
    TMGT_MODID_UPDATE_FAN_FLOOR         = 0x3F,

    // tmgtutility.C AND  tmgtclient.C
    TMGT_MODID_P1_P2_FILE_READ_WRITE    = 0x43,
    TMGT_MODID_OPEN_POWERDEF_FILE       = 0x44,
    TMGT_MODID_GET_POWERDEF_FIELD       = 0x45,
    TMGT_MODID_AUTO_IPL_TEST            = 0x46,
    TMGT_MODID_PWRDEF_PARSER            = 0x47,
    TMGT_MODID_GET_PROC_FOLDING_DATA    = 0x48,
    TMGT_MODID_SEND_PROC_FOLDING_DATA   = 0x49,
    TMGT_TOOL_MAIN                      = 0x4A,
    TMGT_PERC_GET_ERROR_DATA2           = 0x4B,
    TMGT_MODID_GET_DEF_FILE_PARMS       = 0x4C,
    TMGT_MODID_CREATE_THREAD            = 0x4D,
    TMGT_MODID_UPDATE_PCI               = 0x4E,
    TMGT_MODID_GET_NODE_NUM_FROM_LOC_CODE = 0x4F,
    TMGT_MODID_GET_FAN_CONTROL_FRU_INFO = 0x50,

    TMGT_MODID_PROCESS_ALTITUDE         = 0x5D,
    TMGT_MODID_UPDATE_INT_CHARINDEX     = 0x5F,

    // TOIF/OCC
    TMGT_MODID_TCT_CONFIG               = 0x60,
    TMGT_MODID_PROCESS_ELOG             = 0x61,
    TMGT_MODID_PHASE_FAULT_CHECK        = 0x62,
    TMGT_MODID_GET_CPU_TEMP             = 0x63,

    TMGT_MODID_SEND_PROC_CFG_UPDATE     = 0x68,
    TMGT_MODID_PEX_MANAGER              = 0x6A,
    TMGT_MODID_PEX_ALTITUDE             = 0x6B,
    TMGT_MODID_POWER_METER_CFG_REG      = 0x6C,
    TMGT_MODID_PEX_POWER_SUPPLY         = 0x6E,
    TMGT_MODID_PEX_FILE_RW              = 0x6F,

    TMGT_MODID_LOAD_OCC                 = 0x70,
    TMGT_MODID_LOAD_OCC_STATUS          = 0x71,
    TMGT_MODID_RESET_OCC                = 0x72,
    TMGT_MODID_RESET_OCC_STATUS         = 0x73,
    TMGT_GET_TUNABLE_PARMS              = 0x74,
    TMGT_SET_TUNABLE_PARMS              = 0x75,
    TMGT_MODID_OCC_POLL                 = 0x76,
    TMGT_MODID_TOIF_INIT                = 0x77,
    TMGT_MODID_CHECKPOINT_DATA          = 0x78,
    TMGT_MODID_TOIF_SET_PCAP            = 0x79,
    TMGT_MODID_INITIATE_RESET           = 0x7A,
    TMGT_MODID_OCC_QFWLEVEL             = 0x7B,
    TMGT_MODID_OCC_GET_ERROR_LOG        = 0x7C,
    TMGT_MODID_BAD_FRU_CALLOUTS         = 0x7D,

    TMGT_MODID_EVENT_NOTIFY             = 0x7E,
    TMGT_MODID_MISMATCHING_SEVERITY     = 0x7F,
    TMGT_MODID_GET_PWR_AVAILABLE_PER_NODE = 0x80,

    // tmgt_hwsv.C
    TMGT_MODID_GET_OCCS                 = 0x82,
    TMGT_MODID_HWSV_SEND_OCC_CMD        = 0x84,
    TMGT_MODID_HWSV_READ_OCC_SRAM       = 0x85,

    TMGT_MODID_HWSV_PROCESS_QMSG        = 0x86,

    TMGT_MODID_HWSV_CALC_FREQ           = 0x87,
    TMGT_MODID_HWSV_ACCESS_ATTR         = 0x88,
    TMGT_MODID_GET_HUID                 = 0x8A,
    TMGT_MODID_APP_CALC_MEMPWR          = 0x8B,
    TMGT_MODID_GET_NUM_CORES            = 0x8C,
    TMGT_MODID_VALIDATE_MEM_THROTTLES   = 0x8D,

    TMGT_MODID_SEND_OCC_CMD             = 0x90,
    TMGT_MODID_WRITE_OCC_CMD            = 0x91,
    TMGT_MODID_CHECK_OCC_RSP            = 0x92,
    TMGT_MODID_PARSE_OCC_RSP            = 0x94,

    TMGT_MODID_POWER_FAULT_QUERY        = 0xA5,

    TMGT_MODID_CALCULATE_DIMMWATTAGE    = 0xAC,
    TMGT_MODID_GET_SYS_MEM_DATA         = 0xAE,
    TMGT_MODID_CALC_POWERCAP            = 0xAF,

    TMGT_MODID_SET_OCC_STATE            = 0xB6,
    TMGT_MODID_WAIT_READY               = 0xB7,
    TMGT_MODID_CHANGE_STATE_MODE        = 0xB8,
    TMGT_MODID_PCAP_HANDLER             = 0xB9,

    TMGT_MODID_HW_REG                   = 0xBA,

    // tmgt_occ_config.C
    TMGT_MODID_CFGDATA_FREQ_POINTS      = 0xC0,
    TMGT_MODID_CFGDATA_OCC_ROLE         = 0xC1,
    TMGT_MODID_CFGDATA_APSS_CFG         = 0xC2,
    TMGT_MODID_CFGDATA_MEM_CFG          = 0xC3,
    TMGT_MODID_CFGDATA_MEM_THROTTLE     = 0xC4,
    TMGT_MODID_CFGDATA_AVSBUS           = 0xC5,

    // tmgt_powermode.C
    TOIF_POLL_IPS_HANDLER               = 0xDB,
    TMGT_MODID_PWR_ON_PRESENCE_DETECT   = 0xDC,

    // tmgt_functions.C
    TMGT_MODID_POLLING_INTERVAL         = 0xE0,
    TMGT_MODID_GET_SNAPSHOT             = 0xE1,
    TMGT_MODID_PWR_HW_ERROR_REG         = 0xE2,

    TMGT_MODID_POWER_EVENT              = 0xEC,

    TMGT_MODID_GET_PS_TYPE_VOLTAGE      = 0xF9,
};



// Progress Code Range - D000 - D0FF
enum tmgtIplProgressCodes
{
    TMGT_IPL_MODE_CHANGE_A        =   0xD000,
    TMGT_IPL_MODE_CHANGE_B        =   0xD001,

    TMGT_IPL_UNKNOWN_A            =   0xD0FE,
    TMGT_IPL_UNKNOWN_B            =   0xD0FF,
};

#endif // TMGT_SERVICE_CODES_H
