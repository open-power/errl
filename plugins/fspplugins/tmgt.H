// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgt.H 1.11.23.29 
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
// $Source: fips760 fsp/src/tmgt/fsp/tmgt.H 2$

#ifndef TMGT_H
#define TMGT_H


/**
 *  @file tmgt.H
 *
 *  @brief This file contains the definition of constants, enums, and function
 *         prototypes that are needed external to the TMGT component.
 *         They are documented in "TMGT Component HLD/LLDD" (https://mcdoc.boeblingen.de.ibm.com/out/out.ViewDocument.php?documentid=537).
 *
 */


#include <tmgt_service_codes.H>
#include <stdint.h>

#ifndef _X86NFP
#include <svpdextinterface.H>
#include <AttnEnums.H>
#include <cimptypes.H>
#include <hwsvTypes.H>
#endif

const uint32_t TMGT_VOLT_CHANGE_TIMEOUT = 19 * 60;  // 19 minutes


/*-----------------------------------------------------------------------------*/
/* Registry defines                                                            */
/*-----------------------------------------------------------------------------*/
#define TMGT_thermalThrottle            "tmgt/thermalThrottle"
#define TMGT_currentTpmfState           "tmgt/currentState"                 // Used by ipmi
#define TMGT_currentPwrMode             "tmgt/currentPwrMode"               // Used by ipmi
#define TMGT_custReqMode                "tmgt/custReqMode"                  // Used by tmgtclient.C
#define TMGT_currentVoltSetting         "tmgt/currentVoltSetting"
#define TMGT_overrideDefFile            "tmgt/overrideDefFile"              // Used by tmgtclient.C
#define TMGT_loadPwrMgtDefFile          "tmgt/loadPwrMgtDefFile"
#define TMGT_factoryPwrDefFile          "tmgt/factoryDefFile"
#define TMGT_activeNodes                "tmgt/activeNodes"
#define TMGT_currentState               "tmgt/currentState"
#define TMGT_oversubscription           "tmgt/oversubscription"
#define TMGT_throttleStatus             "tmgt/throttleStatus"
#define TMGT_procCCIN                   "tmgt/procCCIN"
#define TMGT_timeInMode                 "tmgt/timeInMode"
#define TMGT_pciLookup                  "tmgt/pciLookup"
#define TMGT_CodeUpdate                 "tmgt/CodeUpdate"
#define TMGT_mnfgOpalMode               "tmgt/mnfgOpalMode"
#define HWSV_EnableHFTrading_key        "hwsv/EnableHFTrading"
/*-----------------------------------------------------------------------------*/
/* Registry Files (more than 4 bytes long)
 * These have the full /opt/pX path since they are files, not registry keys                                                */
/*-----------------------------------------------------------------------------*/
#define TMGT_pciConfigFile              "/opt/p1/tmgt/pciConfigFile"

// IPMI is using the following constant and is specific to P6 Blades
#define TMGT_P6_BLADE_PEX_VERSION       0x0205

// Processor Power Cycle Limit (0x09FB which is once per day for 7 years)
#define TMGT_WARRANTIED_POWER_TRANSITIONS 0x09FB

const uint16_t MAX_NUMBER_OF_ZONES = 8;

/*-----------------------------------------------------------------------------*/
/* Enums                                                                       */
/*-----------------------------------------------------------------------------*/

enum tmgtSysPwrMode
{
    TMGT_SYS_PWR_MODE_NO_CHANGE         = 0x00, // No change to current mode
    TMGT_SYS_PWR_MODE_NOMINAL           = 0x01, // Nominal Mode
    TMGT_SYS_PWR_MODE_TURBO             = 0x03, // Static Turbo mode
    TMGT_SYS_PWR_MODE_SAFE              = 0x04, // Safe mode, (not valid for customer to set)
    TMGT_SYS_PWR_MODE_POWER_SAVE        = 0x05, // Static power save mode
    TMGT_SYS_PWR_MODE_DYNAMIC_P_SAVE    = 0x06, // Dynamic power save (not valid for customer to set)
    TMGT_SYS_PWR_MODE_MIN_FREQUENCY     = 0x07, // Internal use - min freq allowed (not valid for customer)
    TMGT_SYS_PWR_MODE_NOMINAL_DYNAMIC   = 0x08, // Nominal Dynamic Performance Mode (NO LONGER VALID)
    TMGT_SYS_PWR_MODE_MAXIMUM_DYNAMIC   = 0x09, // Maximum Dynamic Performance Mode (NO LONGER VALID)
    TMGT_SYS_PWR_MODE_DYNAMIC_PERF      = 0x0A, // Dynamic Performace
    TMGT_SYS_PWR_MODE_DPS_FP            = TMGT_SYS_PWR_MODE_DYNAMIC_PERF,
    TMGT_SYS_PWR_MODE_FFO               = 0x0B, // Fixed Frequency Override
    TMGT_SYS_PWR_MODE_MAX_PERF          = 0x0C, // Fixed Maximum Frequency mode.
    TMGT_SYS_PWR_MODE_FMF               = TMGT_SYS_PWR_MODE_MAX_PERF,
    TMGT_MAXIMUM_NUMBER_MODES           = 0x0D, // Maximum number of modes defined
    // As new modes are added, remember to update mode_string(() in tmgt.C
    TMGT_SYS_PWR_MODE_FAILURE           = 0xE0, // Previous mode change failed (only used by G_current_mode)
    TMGT_SYS_PWR_MODE_IN_TRANSITION     = 0xFF, // In the process of changing
};

enum occStateId
{
    // tmgt_ttif_server.C
    OCC_STATE_NO_CHANGE                = 0x00,
    OCC_STATE_STANDBY                  = 0x01,
    OCC_STATE_OBSERVATION              = 0x02,
    OCC_STATE_ACTIVE                   = 0x03,
    OCC_STATE_SAFE                     = 0x04,
    OCC_STATE_CHARACTERIZATION         = 0x05,
    // following states are internal to TMGT
    OCC_STATE_RESET                    = 0x85,
    OCC_STATE_IN_TRANSITION            = 0x87,
    OCC_STATE_LOADING                  = 0x88,
    OCC_STATE_UNKNOWN                  = 0x89,
    // As new states are added, remember to update state_string() in tmgtutility.C
};

enum occResetReason
{
    OCC_RESET_REASON_NONE              = 0x00,
    OCC_RESET_REASON_CRIT_FAILURE      = 0x01,
    OCC_RESET_REASON_PWR_ON_FAIL       = 0x02,
    OCC_RESET_REASON_ERROR             = 0x03,
    OCC_RESET_REASON_POWER_FAULT       = 0x04,
    OCC_RESET_REASON_DIFF_OCC          = 0x05,
    OCC_RESET_REASON_OCC_REQUEST       = 0x06,
    OCC_RESET_REASON_OCC_AFO           = 0x07,
    OCC_RESET_REASON_CODE_UPDATE       = 0x08,
    OCC_RESET_REASON_OCC_IN_DIFF_NODE  = 0x09,
    OCC_RESET_REASON_MANUAL_RESET      = 0x0A,
    OCC_RESET_REASON_ATTR_CHANGE       = 0x0B,
    OCC_RESET_REASON_WOF_RESET         = 0x0C,
    OCC_RESET_REASON_POWER_OFF         = 0xFF,
};


enum occResetStatus
{
    OCC_RESET_STATUS_SUCCESS          = 0x00,
    OCC_RESET_STATUS_MASTER_FAIL      = 0x01,
    OCC_RESET_STATUS_MAX_RESETS       = 0x02,
};

enum tmgtEmpathFunction
{
    TMGT_EMPATH_FUNC_DISABLE      = 0x00, // All empath functionality is disabled.  OCC is held in reset
    TMGT_EMPATH_FUNC_ACTIVE       = 0x01, // Empath full function.  Monitoring and actuation are enabled
    TMGT_EMPATH_FUNC_OBSERVATION  = 0x02, // Only monitoring of thermal/power data is enabled
    TMGT_EMPATH_FUNC_DOWNLOAD     = 0xE0, // Empath firmware is in the process of being downloaded
    TMGT_EMPATH_FUNC_NOT_PRESENT  = 0xE1, // Empath not present, but system is empath capable
    TMGT_EMPATH_FUNC_NOT_APPLICABLE = 0xE2, // System is not empath capable
};


enum tmgtSensorNum
{
    TMGT_SENSOR0                  =  0,
    TMGT_SENSOR1                  =  1,
    TMGT_SENSOR2                  =  2,
    TMGT_SENSOR3                  =  3,
    TMGT_SENSOR4                  =  4,
    TMGT_SENSOR5                  =  5,
    TMGT_SENSOR6                  =  6,
    TMGT_SENSOR7                  =  7,
    TMGT_SENSOR8                  =  8,
    TMGT_SENSOR9                  =  9,
    TMGT_SENSOR10                 = 10,
    TMGT_SENSOR11                 = 11,
    TMGT_SENSOR12                 = 12,
    TMGT_SENSOR13                 = 13,
    TMGT_SENSOR14                 = 14,
    TMGT_SENSOR15                 = 15,
    TMGT_SENSOR16                 = 16,
    TMGT_SENSOR17                 = 17,
    TMGT_SENSOR18                 = 18,
    TMGT_SENSOR19                 = 19,
    TMGT_SENSOR20                 = 20,
    TMGT_SENSOR21                 = 21,
    TMGT_SENSOR22                 = 22,
    TMGT_SENSOR23                 = 23,

    // Below sensors are kept for HOM compilation
    TMGT_SENSOR24                 = 24,
    TMGT_SENSOR25                 = 25,
    TMGT_SENSOR26                 = 26,
    TMGT_SENSOR27                 = 27,
    TMGT_SENSOR28                 = 28,
    TMGT_SENSOR29                 = 29,
    TMGT_SENSOR30                 = 30,
    TMGT_SENSOR31                 = 31,

    // And now back to data in HLD
    TMGT_MAX_SENSORS              = 0x18,
    TMGT_SENSOR_TRIP_INDICATIONS  = 0xE000,
    TMGT_ALL_SENSORS              = 0xF000
};


enum tmgtProcessorStatus
{
    TMGT_PROCESSOR_SUCCESS = 0x00,
    TMGT_PROCESSOR_SCOM_FAIL      // Failure processing request due to a SCOM failure to this processor chip
};


#define TMGT_MAX_CORES          8

enum tmgtCoreStatus
{
    TMGT_CORE_NON_FUNCTIONAL  = 0x00, // The Core is not functional, i.e. gard
    TMGT_CORE_FUNCTIONAL      = 0x01, // The core is functional
    TMGT_CORE_SCOM_FAIL       = 0x02, // Cannot determine status due to failure.
    TMGT_CORE_IPC_THROTTLED   = 0x03, // The core is in IPC mode.
    TMGT_CORE_RUN_HOLD_ZERO   = 0x04, // Run count and hold count are both zero
    TMGT_CORE_NOT_PRESENT     = 0xDD, // The core is not present
    TMGT_CORE_ECO             = 0xEC  // Extended Cache Option
};


enum tmgt_thmonitor_ctrl_flags
{
    TMGT_THMON_TMGT_CNTRLD     = 0x80,
    TMGT_THMON_HOM_CNTRLD      = 0x40,
    TMGT_THMON_ALL_CNTRLD      = 0x80|0x40, // Both TMGT and HOM
    //Bits 4 - 0 reserved for future use.
};


enum tmgt_toif_alert_types
{
    TOIF_ALERT_FSP_RESP_READY = 1,
    TOIF_ALERT_FSP_SERVICE_REQD = 2,
};

typedef struct tmgt_thermal_limit_event_data
{
    uint8_t     cpu;    // Indicates which OCC/CPU reached the ERROR threshold
    uint32_t    temp;   // Indicates what the ERROR threshold is
} tmgt_thermal_limit_event_data_t;

struct tmgtEmpathFunc_t
{
    tmgtEmpathFunction    occStatus;
    bool                  powerSave;        // True indicates Power Save is supported regardless of presence or state of OCC
    bool                  powerCap;         // True indicates Power Cap may be set if OCC is present and functional
    bool                  dynamicPwrSave;   // True indicates DPS mode (non-FP) is supported
    bool                  dynamicPwrSaveFP; // True indicates DPS FP is supported
    bool                  FFO;              // TRUE indicates Fixed Frequency Override mode is supported
    bool                  reserved4;    	// Removed ips mode.
    bool                  FMF;              // True indicates that Fixed Maximum Frequency is supported.
    bool                  nominalDynamic;   // True indicates that Nominal Dynamic Performance Mode is supported
    bool                  maximumDynamic;   // True indicates that Maximum Dynamic Performance Mode is supported
    bool                  reserved8;
    bool                  reserved9;
    bool                  reserved10;
};


// Used by chic/fsp/chicclientlib.C
struct tmgtProcessorAddress_t
{
    uint32_t  rid;        // SVPD Resource ID of the processor fru
    uint32_t  moduleIndex; // indicates which module within a processor FRU.  In terms of module VPD this is equivalent to SVPDs i_module_index to read module.  If only one module in the processor FRU this will be 0.
    uint8_t   chipNum;    // indicates which chip within a module.  For SCMs this is always 0.  In terms of module VPD this is equivalent to the x in CRPx record.
    uint8_t   i2cAddress; // I2C address for this processor chip
    tmgtProcessorStatus status;   // status of carrying out the enable or disable for this processor chip.
};


// Used by chic/fsp/chicclientlib.C
struct tmgtProcessorCoreStatus_t
{
    uint32_t      rid;            // SVPD Resource ID of the processor fru
    uint32_t      moduleIndex;    // indicates which module within a processor FRU.  In terms of module VPD this is equivalent to SVPDs i_module_index to read module.  If only one module in the processor FRU this will be 0.
    uint8_t       chipNum;        // indicates which chip within a module.  For SCMs this is always 0.  In terms of module VPD this is equivalent to the x in CRPx record.
    uint8_t       coreStatus[TMGT_MAX_CORES]; // Array of core status in the processor chip, [0] = core 0 status, [1] = core 1 status, etc...
};


struct tmgtFindFwInstance_t
{
    uint8_t  numInstances;
    uint8_t  majorVersion;
    uint8_t  minorVersion;
    uint8_t  moduleHandle;
    uint16_t recordId;
};


enum tmgtOversubscriptionEventEnum
{
    TMGT_OVERSUBSCRIPTION_EXIT            = 0x00,
    TMGT_OVERSUBSCRIPTION_UNTHROTTLED     = 0x01,
    TMGT_OVERSUBSCRIPTION_THROTTLED       = 0x11,
};


// Used by ccmm/test/ccmmHijack.H
enum tmgtCCMEnableStatus
{
    TMGT_CCM_ENABLE_STATUS_SUCCESS = 0x00,
    TMGT_CCM_ENABLE_STATUS_FAILED  = 0x01,
};


// Used by cimp
enum tmgtModuleHandle_t
{
    TMGT_MODULE_HANDLE0 = 0x20,
    TMGT_MODULE_HANDLE1 = 0x21,
    TMGT_MODULE_HANDLE2 = 0x22,
    TMGT_MODULE_HANDLE3 = 0x23,
    TMGT_MODULE_HANDLE4 = 0x24,
    TMGT_MODULE_HANDLE5 = 0x25,
    TMGT_MODULE_HANDLE6 = 0x26,
    TMGT_MODULE_HANDLE7 = 0x27
};

// Used by powr
enum tmgtAltitudeStatus
{
    TMGT_ALTITUDE_NOT_AVAILABLE   = 0x00,
    TMGT_ALTITUDE_VALID           = 0x01,
    TMGT_ALTITUDE_ERROR           = 0x02          // Supported, but error reading sensor
};

// Used by ccmm
enum tmgtCCMNodeOpEnum
{
    TMGT_CCM_NODE_OP_REMOVE       = 0x00,         // Node is being removed.
    TMGT_CCM_NODE_OP_ADD          = 0x01,         // Node is being added.
    TMGT_CCM_GX_OP_REMOVE         = 0x02,         // GX card is being removed.
    TMGT_CCM_GX_OP_ADD            = 0x03,         // GX card is being added.
};

// Used by powr
struct tmgtFanSpeeds_t
{
    uint8_t  node;                                // node the zone covers(0 = drawer 1, etc...)
    uint8_t  zone;                                // zone number
    uint16_t zoneFloor;                           // current floor RPM for zone
    uint16_t zoneTarget;                          // target RPM for zone
    uint16_t zoneLow;                             // lowest RPM of all fans in the zone
    uint16_t zoneHigh;                            // highest RPM of all fans in the zone
} __attribute__ ((packed)) ;



#define TMGT_MAX_NUMBER_OF_NODES        4  //Max number of nodes per system
#define TMGT_MAX_NUMBER_OF_OCCS         8  //Max number of OCCs per node
//Max number of Memory controllers per system
#define TMGT_MASTER_OCC                 0xFF
#define TMGT_ALL_NODES                  0xFF




#define TMGT_MAX_TUNABLE_PARAMS	30
#define TMGT_MAX_IDLEPOWERSAVE_PARAMS	5

enum tmgtTunableParameterID
{
  TMGT_ES_PARM_ID_1	              = 0x01,	// Tunable Parameter 1
  TMGT_ES_PARM_ID_2	              = 0x02,	// Tunable Parameter 2
  TMGT_ES_PARM_ID_3	              = 0x03,	// Tunable Parameter 3
  TMGT_ES_PARM_ID_4	              = 0x04,	// Tunable Parameter 4
  TMGT_ES_PARM_ID_5	              = 0x05,	// Tunable Parameter 5
  TMGT_ES_PARM_ID_6	              = 0x06,	// Tunable Parameter 6
  TMGT_ES_PARM_ID_7	              = 0x07,	// Tunable Parameter 7
  TMGT_ES_PARM_ID_8	              = 0x08,	// Tunable Parameter 8
  TMGT_ES_PARM_ID_9	              = 0x09,	// Tunable Parameter 9
  TMGT_ES_PARM_ID_10              = 0x0A,	// Tunable Parameter 10
  TMGT_ES_PARM_ID_11              = 0x0B,	// Tunable Parameter 11
  TMGT_ES_PARM_ID_12              = 0x0C,	// Tunable Parameter 12
  TMGT_ES_PARM_ID_13              = 0x0D,	// Tunable Parameter 13
  TMGT_ES_PARM_ID_14              = 0x0E,	// Tunable Parameter 14
  TMGT_ES_PARM_ID_15              = 0x0F,	// Tunable Parameter 15
  TMGT_ES_PARM_ID_16              = 0x10,	// Tunable Parameter 16
  TMGT_ES_PARM_ID_17              = 0x11,	// Tunable Parameter 17
  TMGT_ES_PARM_ID_18              = 0x12,	// Tunable Parameter 18
  TMGT_ES_PARM_ID_19              = 0x13,	// Tunable Parameter 19
  TMGT_ES_PARM_ID_20              = 0x14,	// Tunable Parameter 20
  TMGT_ES_PARM_ID_21              = 0x15,	// Tunable Parameter 21
  TMGT_ES_PARM_ID_22              = 0x16,	// Tunable Parameter 22
  TMGT_ES_PARM_ID_23              = 0x17,	// Tunable Parameter 23
  TMGT_ES_PARM_ID_24              = 0x18,	// Tunable Parameter 24
  TMGT_ES_PARM_ID_25              = 0x19,	// Tunable Parameter 25
  TMGT_ES_PARM_ID_26              = 0x1A,	// Tunable Parameter 26
  TMGT_ES_PARM_ID_27              = 0x1B,	// Tunable Parameter 27
  TMGT_ES_PARM_ID_28              = 0x1C,	// Tunable Parameter 28
  TMGT_ES_PARM_ID_29              = 0x1D,	// Tunable Parameter 29
  TMGT_ES_PARM_ID_30	            = 0x1E, // Tunable Parameter 30

  // THe following parms are only for Ide Power Saver
  TMGT_ES_PARM_ID_IPS_ENABLE      = 0x50,	// Idle Power Saver enabled/disabled
  TMGT_ES_PARM_ID_IPS_ENTER_TIME	= 0x51,	// Delay time to enter Idle Power Saver
  TMGT_ES_PARM_ID_IPS_ENTER_UTIL	= 0x52,	// Utilization threshold to enter Idle Power Saver
  TMGT_ES_PARM_ID_IPS_EXIT_TIME	  = 0x53,	// Delay time to exit Idle Power Saver
  TMGT_ES_PARM_ID_IPS_EXIT_UTIL	  = 0x54,	// Utilization threshold to exit Idle Power Saver
};

enum tmgtTunableParamUnit
{
  TMGT_ES_PARM_UNIT_FLAG	  = 0x00,	// Parameter can only be either 1 (enabled) or 0 (disabled)
  TMGT_ES_PARM_UNIT_SECONDS	= 0x01,	// Parameter is time in seconds i.e. 10 = 10 seconds
  TMGT_ES_PARM_UNIT_PERCENT	= 0x02, // Parameter is a percentage  i.e. 10 = 10%
  TMGT_ES_PARM_UNIT_TENTHPERCENT	= 0x03,	// Parameter is in 10ths of a percent  i.e. 15 = 1.5%
  TMGT_ES_PARM_UNIT_NUMBER 	= 0x04	// Parameter is an integer
};

enum tmgtESParmStatus
{
  TMGT_ES_PARM_STATUS_SUCCESS	= 0x00,	// Parameter was successfully set
  TMGT_ES_PARM_STATUS_FAIL	  = 0x01,	// Parameter is valid but the value to set was bad i.e. out of the allowable range
  TMGT_ES_PARM_STATUS_INVALID	= 0x02	// Given parameter is invalid or not supported
};


// Starting in 840 the tmgtTunableParameter_t structure size must NOT change (RTC 125398)
#define TMGT_TUNING_PARM_MAX_NAME_SIZE 60
struct tmgtTunableParameter_t
{
  uint32_t parameterID;	                // ID number for this tunable parameter
  char parmName[TMGT_TUNING_PARM_MAX_NAME_SIZE]; // Text for parameter name to be displayed to the user
  uint32_t unitType;	                // The unit the values are in for this parameter
  uint16_t currValue;	                // Current value of this parameter
  uint16_t minValue;	                // Minimum value that may be set for this parameter
  uint16_t maxValue;	                // Maximum value that may be set for this parameter
} __attribute__ ((packed)) ;


struct tmgtSetESParameter_t
{
  tmgtTunableParameterID parameterID;	// Tunable parameter newValue is for
  uint16_t newValue;	                // New value to assign to this parameter
  tmgtESParmStatus parameterStatus;	  // Status of setting the newValue for this parameter
};



//Processor Parameters read from def file or HWSV.
struct tmgtProcDefParams_t
{
  float     freqMax;
  float     raw_core_dts_weight;
  float     raw_quad_dts_weight;
  uint8_t   tenths_core_dts_weight;
  uint8_t   tenths_quad_dts_weight;
};

#define TMGT_internalFlags "tmgt/internalFlags"
enum tmgtInternalFlags_t
{
    //FLAG_OCC_SRC_RESERVED     = 0xFF000000, // reserved for SRC when using HALT_ON_OCC_SRC
    FLAG_HALT_ON_OCC_SRC        = 0x00800000,
    FLAG_SEND_MEM_CONFIG        = 0x00000800, // Not currently used, retain for Centaur bringup
    FLAG_ONLY_ENABLE_OCC0       = 0x00000400, // Only OCC0 will be enabled (other OCCs will be ignored)
    FLAG_SKIP_MBOX_CALLS        = 0x00000200, // MBOX calls to load/reset the OCCs will be skipped (bringup only)
    FLAG_HALT_ON_OCC_RESET_FAIL = 0x00000100,
    //FLAG_EXT_RESET_DISABLED   = 0x00000080, // reserved for HTMGT
    FLAG_DISABLE_MEM_THROTTLE   = 0x00000040,
    FLAG_IGNORE_OCC_STATE       = 0x00000020,
    FLAG_HOLD_OCCS_IN_RESET     = 0x00000010,
    FLAG_LOAD_REQUEST_DISABLED  = 0x00000008,
    FLAG_TERMINATE_ON_ERROR     = 0x00000004,
    FLAG_RESET_DISABLED         = 0x00000002,
    FLAG_EXTERNAL_OVERRIDE      = 0x00000001
};

#ifndef _X86NFP
//////////////////////////////////////////////////////////////////////////////
// EXTERNAL SHARED LIBRARY FUNCTIONS
//
// Defined in TMGT Component HLD/LLDD for Px:    x = processor number 7,8,9, etc.
// https://mcdoc.boeblingen.de.ibm.com/out/out.ViewFolder.php?folderid=253
//////////////////////////////////////////////////////////////////////////////



/**
 * @brief Set the requested system power mode.  Function is non-blocking and
 *        TMGT will make mode change when possible.
 *        The caller can verify current power mode with tmgtQueryModeAndFunction()
 *
 * @param[in] i_customerSysPwrMode - Customer requested power mode
 * @param[in] i_FFOfreq            - Fixed Frequencey in Mhz (FFO mode only)
 *
 * @note Called by ASM and CIMP
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_INVALID_DATA             - Invalid mode specified
 * @retval TMGT_RC_PARAMETER_OUT_OF_RANGE   - Invalid Fixed Frequency
 * @retval TMGT_RC_MISSING_DATA             - i_FFOfreq was 0
 * @retval TMGT_RC_PRESENT_STATE_PROHIBITS  - Current state does not allow change
 * @retval TMGT_RC_NO_CHANGE                - Already in specified mode (no mode change will be made)
 **/
errlHndl_t tmgtSetCustRequestedMode(tmgtSysPwrMode i_customerSysPwrMode,
                                    uint16_t       i_FFOfreq = 0);



/**
 * @brief Query the system power mode and EnergyScale functionality
 *
 * @param[out] o_currSysPwrMode     - Current system power mode
 * @param[out] o_customerSysPwrMode - Customer requested power mode
 * @param[out] o_currVoltageSetting - Current power mode (voltage/frequency setting)
 * @param[out] o_currEmpathFunc     - Current status of OCC functionality and support
 * @param[in,out] o_freqPoint       - if not NULL, desired frequency point that was set (non-Dynamic modes only)
 *
 * @note Called by ASM and HMCX
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 **/
errlHndl_t tmgtQueryModeAndFunction(tmgtSysPwrMode & o_currSysPwrMode,
                                    tmgtSysPwrMode & o_customerSysPwrMode,
                                    tmgtSysPwrMode & o_currVoltageSetting,
                                    tmgtEmpathFunc_t & o_currEmpathFunc,
                                    uint16_t         * o_freqPoint = NULL);



/**
 * @brief Send an AMESTER command to an OCC for processing
 *
 * @param[in] i_sendData      - Pointer to data buffer with the AMESTER request data <cmd byte><resv byte><cmd data>
 * @param[in] i_sendSize      - Size of buffer pointed to by i_sendData
 * @param[in] i_recvData      - Pointer to data buffer for returning the AMESTER response data
 * @param[in,out] io_recvSize - Size of buffer pointed to by i_recvData, and amount of data actually returned
 * @param[in] i_node          - Target node for the command (0 = first physical node)
 * @param[in] i_occ           - Target OCC for the command (0 = first physical OCC within node, 0xFF = master OCC)
 *
 * @note Called by IPMI and HMCX from AMESTER
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_OCC_CMD_FAIL     - OCC had a failure processing the command
 * @retval TMGT_RC_CMD_TIMEOUT
 * @retval TMGT_RC_OCC_UNAVAILABLE  - Current OCC state does not allow command to be sent (OCC may not be present)
 * @retval TMGT_RC_BUFFER_TOO_SMALL - i_recvData is too small for specific response data
 **/
#define TMGT_AMESTER_MAX_RECV_SIZE      1024
errlHndl_t tmgtSendAmeCommand(const void     * i_sendData,
                              const uint16_t   i_sendSize,
                              void           * io_recvData,
                              uint16_t       & io_recvSize,
                              const uint8_t    i_node = 0,
                              const uint8_t    i_occ = 0xFF);



/**
 * @brief Send a command to an OCC for processing
 *
 * @param[in] i_occCmd         - OCC command to send
 * @param[in] i_dataBuffer     - Pointer to the command data buffer
 * @param[in] i_dataLength     - Size of buffer pointed to by i_dataBuffer
 * @param[in] io_rspBuffer     - Pointer to data buffer for returning the response data
 * @param[in,out] io_rspLength - Size of buffer pointed to by io_rspBuffer, and amount of data actually returned
 * @param[in] i_node           - Target node for the command (0 = first physical node)
 * @param[in] i_occ            - Target OCC for the command (0 = first physical OCC within node, 0xFF = master OCC)
 *
 * @note Used by MNFG, occtool and for internal debug and testing
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_OCC_CMD_FAIL     - OCC had a failure processing the command
 * @retval TMGT_RC_CMD_TIMEOUT
 * @retval TMGT_RC_OCC_UNAVAILABLE  - Current OCC state does not allow command to be sent (OCC may not be present)
 * @retval TMGT_RC_BUFFER_TOO_SMALL - io_rspBuffer is too small for specific response data
 **/
errlHndl_t tmgtOCCExecuteCommand(const uint8_t    i_occCmd,
                                 const uint8_t  * i_dataBuffer,
                                 const uint16_t   i_dataLength,
                                 uint8_t        * io_rspBuffer,
                                 uint16_t       & io_rspLength,
                                 const uint8_t    i_node = 0,
                                 const uint8_t    i_occ = 0xFF);


/**
 * @brief Get HUID of Master OCC for the specified node
 *
 * @param[in] i_node           - Target node (0 = first physical node)
 * @param[out] o_occInstance   - Master OCC instance number
 * @param[out] o_occHuid       - Master OCC HWSV::HUID value
 *
 * @note Used by MNFG, occtool and for internal debug and testing
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 **/
errlHndl_t tmgtGetMasterOCC(const uint8_t         i_node,
                            uint8_t             & o_occInstance,
                            uint32_t            & o_occHuid);
/**
 * @brief Return Firmware instance, module handle and version
 *
 * @param[in] i_instanceNumber - Firmware module instance number (starting at 0)
 * @param[in] i_moduleTypeId   - Module type (unused)
 * @param[out] &o_numInstances - number of instances of this module type
 * @param[out] &o_majorVersiom - major version of commands supported
 * @param[out] &o_minorVersion - minor version of commands supported
 * @param[out] &o_moduleHandle - Module handle (lower nibble is the node number)
 * @param[out] &o_recordId     - generic system type
 *
 * @note Called by CIMP and HMCX
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_NO_SUPPORT
 **/
errlHndl_t tmgtPexFindFwInstance(uint8_t    i_instanceNumber,
                                 uint16_t   i_moduleTypeId,
                                 uint8_t  & o_numInstances,
                                 uint8_t  & o_majorVersion,
                                 uint8_t  & o_minorVersion,
                                 uint8_t  & o_moduleHandle,
                                 uint16_t & o_recordId);



/**
 * @brief Used to initiate the Load and Start OCC command
 *
 * @param[in] i_node - Node for which the OCCs will be started (0xFF = all)
 *
 * @note Called by Transition file, MNFG
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_INVALID_DATA     - Invalid i_node specified
 **/
errlHndl_t tmgtLoadOcc(const uint8_t i_node);



/**
 * @brief Used to report the status of the OCC Load and Start Command send to PHYP
 *
 * @param[in] i_sequenceID - Number which correlates to the Load and Start request
 * @param[in] i_status     - Status of Load/Start command (0 = SUCCESS)
 * @param[in] i_chipID     - HW Chip ID of the OCC being loaded on non-SUCCESS
 *
 * @note Called by MBOX
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_INVALID_DATA     - No request for specified sequence number
 **/
errlHndl_t tmgtLoadOccStatus(const uint32_t i_sequenceID,
                             const uint8_t i_status,
                             const uint8_t i_chipID);



/**
 * @brief Return number of OCCs and their instance number for a specified node
 *
 * @param[in] i_node                - Node number (0 = first physical node)
 * @param[in,out] &io_occArraySize  - Size of io_occArray and number of OCCs returned
 *                                    (constant TMGT_MAX_NUMBER_OF_OCCS is the max OCCs per node)
 * @param[in,out] io_occArray       - Pointer to array of OCC instance IDs (0 = first physical OCC)
 *
 * @note Called by HMCX
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_INVALID_DATA     - Invalid node specified
 * @retval TMGT_RC_BUFFER_TOO_SMALL - io_occArray is too small to contain all instance IDs
 * @retval TMGT_RC_NO_SUPPORT
 **/
errlHndl_t tmgtGetOccInstances(const uint8_t   i_node,
                               uint8_t       & io_occArraySize,
                               uint8_t       * io_occArray);



/**
 * @brief Used to initiate an OCC Reset
 *
 * @param[in] i_node - Node for which the OCCs will be reset (0xFF = all)
 * @param[in] i_clear_reset_count - Clear reset counts in OCC
 *
 * @note Called by MNFG
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_PRESENT_STATE_PROHIBITS
 * @retval TMGT_RC_INVALID_DATA     - Invalid i_node specified
 **/
errlHndl_t tmgtResetOcc(const uint8_t i_node, const bool i_clear_reset_count = FALSE);



/**
 * @brief Used to report the status of the OCC Reset Command send to PHYP
 *
 * @param[in] i_sequenceID - Number which correlates to the Reset request
 * @param[in] i_status     - Status of Reset command (0 = SUCCESS)
 * @param[in] i_chipID     - HW Chip ID of the OCC being reset on non-SUCCESS
 *
 * @note Called by MBOX
 *
 * @return On success, NULL will be returned, otherwise pointer to error handle
 *
 * @retval NULL - Success.
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_INVALID_DATA     - No request for specified sequence number
 **/
errlHndl_t tmgtResetOccStatus(const uint32_t i_sequenceID,
                              const uint8_t i_status,
                              const uint8_t i_chipID);

// Use TMGT_MAX_RECV_SIZE instead of TMGT_POWER_EXEC_MAX_RECV_SIZE
#define TMGT_POWER_EXEC_MAX_RECV_SIZE      TMGT_MAX_RECV_SIZE
#define TMGT_MAX_RECV_SIZE             0x0800
errlHndl_t tmgtPassThrough(uint8_t i_elementId,
                           uint8_t i_methodNumber,
                           void * i_sendPtr,
                           uint16_t i_sendSize,
                           void * i_recvPtr,
                           uint16_t & io_recvSize,
                           uint8_t i_moduleHandle = TMGT_MODULE_HANDLE0);


errlHndl_t tmgtGetCPUTemperature(uint8_t   i_proc,
                                 uint8_t & o_temperature);

errlHndl_t tmgtSendAmbientAndFanSpeeds(const uint8_t            i_ambient,
                                       const tmgtAltitudeStatus i_altitudeStatus,
                                       const uint16_t           i_altitude,
                                       const uint8_t            i_numZones,
                                       const tmgtFanSpeeds_t   *i_fanZoneArray,
                                       const bool               i_outsideEnvWindow = FALSE);

errlHndl_t tmgtQueryProcFoldingData(void *o_recvPtr, uint16_t & io_recvSize);


#ifndef _X86NFP
/**
 * @brief Add user detail section containing information about EnergyScale mode
 *
 * @param[in,out] io_err        Error log to add user data to
 * @param[in]     i_occHuid     HUID of the OCC to add data (default = Master OCC)
 *
 * @note Called by HUTL
 *
 * @return None.  On registry errors, secondary SRC will be added to i_err.
 */
void tmgtAddEnergyScaleUserDetails(errlHndl_t       io_err,
                                   const uint32_t   i_occHuid = HWSV::HWSV_HUID_INVALID);
#endif


/** @brief Collect OCC FFDC data into informational error logs.
 *
 * @param None.
 * @returns None.
 */
void tmgtCollectOccFFDC(void);


/*****************************************************************************/
/** @brief Notify TMGT that there has been a change that may effect the minimum power cap.
 *         i_rid: RID of the node/drawer that had a config change due to a CM operation and
 *                thus requires a pcap recalculate. 0xFFFF indicates that a Pcap recalculate
 *                should be done on all nodes.
 * @returns NULL if successful, otherwise a pointer to an error handle with return code field set to TMGT_RC_INTERNAL_ERROR is returned.
 * */
extern "C" errlHndl_t tmgtRecalculatePcap(uint32_t i_rid = 0x00);

/******************************************************************************/
/* OTHER EXTERNAL FUNCTIONS                                                   */
/******************************************************************************/
errlHndl_t tmgtXFileDisable(const bool i_ignore_ipl_type);





/** @brief Send the PCI power information for CEC and IO drawers.  This information is used to calculate
 * a system power cap.  Until this command is received, TMGT will assume the the maximum power as
 * defined in the power management def file.
 *
 * Version 0x01 is used by MBOX to pass thru a Hypervisor to FSP mailbox cmd to TMGT.
 * The entry format is defined in the FipS PHYP Mailbox Interface (MyDMS document id 503)
 * This function is called after startup when PHYP has determined the status of all PCI slots or anytime
 * thereafter when PHYP has determined the status of a slot has changed.
 *
 * Version 0xF0 is used by POWR/SPCN to give a list of location codes for present IO drawers (24" only)
 *
 * @param[in]           i_version        Version of command (1 = from MBOX, 0xF0 = from POWR)
 * @param[in]           i_num_entries    Number of PCI Slot Power entries.
 * @param[in]           i_entry_size     Number of bytes for each entry.
 * @param[in]           i_entry_ptr      Pointer to array of entries.  An entry consists of a 4 byte power usage
 *                                       in W followed by a 0x50 byte null terminated location code
 *
 * @return A NULL error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval              TMGT_RC_INTERNAL_ERROR
 */
errlHndl_t tmgtMaxPciPower( const uint32_t i_version,
                            const uint32_t i_num_entries,
                            const uint32_t i_entry_size,
                            const uint8_t* i_entry_ptr );


/**
 * @brief Used by CIMP to set and enable a power cap limit
 *
 * @param[in]    i_pcap          The desired power cap in Watts
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval TMGT_RC_PARAMETER_OUT_OF_RANGE
 * @retval TMGT_RC_PRESENT_STATE_PROHIBITS
 */
errlHndl_t tmgtSetPowerCap(const uint16_t i_pcap, uint8_t i_writeOnly = FALSE);

/**
   * @brief Retrieve power cap
   *
   * @param[i/o]   io_dataSz        Size of the o_dataPtr
   * @param[out]   o_dataPtr        Buffer to hold power cap data
   * @param[out]   o_tmgtPcapFlags  Flags associated to pcap data
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   * @retval TMGT_RC_NO_SUPPORT
   * @retval TMGT_RC_BUFFER_TOO_SMALL
   * @retval TMGT_RC_INTERNAL_ERROR
   * @retval TMGT_RC_PRESENT_STATE_PROHIBITS
   */
errlHndl_t tmgtGetPowerCaps(uint32_t & io_dataSz,
                            uint8_t  * o_dataPtr,
                            uint8_t  & o_tmgtPcapFlags);


#ifndef _X86NFP
/**
 * @brief Used by CIMP to get frequency points for fixed freq overwrite, or
 *        the power cap range
 *
 * @param[in]    i_resource      Which resource to return
 * @param[out]   o_buffer        Memory buffer with return data (format in CIM LLDD)
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval TMGT_RC_INTERNAL_ERROR
 * @retval TMGT_RC_INVALID_DATA
 */
errlHndl_t tmgtGetResourceInfo(const CimpResource_t & i_resource,
                               UtilMem              & o_buffer);
#endif


bool get_settable_ips_parms(uint16_t &  o_ips_enable,
                            uint16_t &  o_enter_time,
                            uint16_t &  o_enter_utilization,
                            uint16_t &  o_exit_time,
                            uint16_t &  o_exit_utilization);


/**
   * @brief Query the the list of supported tunable parameters including Idle Power Saver
   *        - Idle Power Saver is supported on ASM
   *        - Tunable Parameters outside of Idle Power Save are NOT supported,
   *          CIMP must only call this with i_idlePowerSaveOnly = TRUE
   *        - ASMI supports all tunable parameters and should call this with i_idlePowerSaveOnly = FALSE to
   *          get the complete list of all tunable parameters (including Idle Power Save) that are supported
   *
   * @param[in]  io_numParameters - size of o_tunableParamArray (Caller may use TMGT_MAX_TUNABLE_PARAMS to know the maximum)
   * @param[out] io_numParameters - number of parameters returned in o_tunableParamArray
   * @param[out] o_tunableParamArray - Array of supported tunable parameters
   * @param[in]  i_idlePowerSave - When FALSE, o_tunableParamArray will return tunable parameters
   *                               When TRUE, o_tunableParamArray will contain Idle Power Saver parameters
   *                               CIMP must call with this TRUE.
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   * @retval TMGT_RC_INTERNAL_ERROR
   * @retval TMGT_RC_BUFFER_TOO_SMALL
   */
errlHndl_t tmgtGetTunableParametersList(uint8_t & io_numParameters,
                                        tmgtTunableParameter_t* o_tunableParamArray,
                                        const bool i_idlePowerSaveOnly);


/**
   * @brief Used to set Idle Power Saver, and EnergyScale tunable parameters.

   * @param[in] i_numParameters - Number of parameters that are to be set.  This is the size of i_tunableParametersArray
   * @param[in] i_tunableParametersArray - Array of tmgtSetESParameter_t structs.  The size of this array is i_numParameters.
   *                                       Caller to fill in the parameterName and newValue fields for each entry.
   *                                       TMGT will fill in the parameterStatus field to return to caller.
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   * @retval TMGT_RC_INVALID_DATA
   * @retval TMGT_RC_NO_SUPPORT
   */
errlHndl_t tmgtSetTunableParameters(const uint8_t i_numParameters,
                                    tmgtSetESParameter_t* io_tunableParametersArray,
                                    const bool i_restoreIPSDefaults = FALSE,
                                    const bool i_restoreTunableParmDefaults = FALSE);

/**
   * @brief Called by manufacturing to change the state of all OCCs in the system.
   *
   * @param[in] i_state - Supported states are: OBSERVATION (2), or ACTIVE (3)
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   * @retval TMGT_RC_INVALID_DATA
   * @retval TMGT_RC_PRESENT_STATE_PROHIBITS
   */
errlHndl_t tmgtSetOccState(const occStateId i_state);


/**
   * @brief Called by CIMP to retrieve the Power Status Register
   *
   * @return NULL on success or error handle on failure
   */
errlHndl_t tmgtPowerStatusReg(uint8_t & o_statusReg);


/**
   * @brief Called by CIMP to retrieve the Power Hardware Error Register
   *
   * @return NULL on success or error handle on failure
   */
errlHndl_t tmgtPowerHwErrorReg(uint8_t & o_hwErrorReg);

/**
   * @brief Called by IPMI to activate or disable the power cap
   *
   * @return NULL on success or error handle on failure
   */
errlHndl_t tmgtActivatePowerCap(uint8_t i_activation);

/**
   * @brief Called by MFG to activate or disable Opal Mode
   *
   * @return NULL on success or error handle on failure
   */
errlHndl_t tmgtOpalMode(uint8_t i_activation);

/**
   * @brief Called by IPMI to get the current power cap and its state of activation
   *
   * @return NULL on success or error handle on failure
   */
errlHndl_t tmgtGetPowerLimit(uint16_t &o_pcap, uint8_t &o_activation);

/******************************************************************************/
/* TMGT INTERNAL USE ONLY                                                     */
/******************************************************************************/

errlHndl_t tmgtRoleChange();


/**
 * @brief Process attention from an OCC
 *
 * @par Description:
 *      Interface for TMGT internal use that processes an attention from an OCC
 *
 * @param[in] i_buffer    A buffer containing information from the OCC
 */
errlHndl_t tmgtProcessOccAttn(const uint8_t* i_buffer, const uint8_t i_data_length);



// Constant still used by ipmi/fsp/ipmiThermalModule.C
#define TPMF_STATE_DOWNLOAD 0x04


void send_cfg_data_to_occs(const uint8_t *i_formats, const uint8_t i_num_formats, const uint8_t i_node = TMGT_ALL_NODES, const bool i_blocking = TRUE);

// Return TRUE if all specified flags are set in tmgt/internalFlags registry key
bool int_flags_set(const uint32_t i_mask);


/**
 * @brief Attempt to bring the system out of safe mode.
 *        This call is non-blocking and will return after starting the
 *        safe mode recovery process.
 *
 * @note If the condition that caused safe mode still exists, then the errors
 *       will be re-committed when the system re-enters safe mode.
 *       Depending on the cause, the system may not immediately re-enter safe mode;
 *       It could re-enter safe mode at some later point (if condition was not resolved)
 *
 * @return On success, NULL will be returned, otherwise error handle
 *
 * @retval NULL - Success
 * @retval TMGT_RC_PRESENT_STATE_PROHIBITS - System is not currently in safe mode
 **/
errlHndl_t tmgtAttemptSafeModeExit();
#endif

#endif // TMGT_H
