// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/powr/fsp/powr_service_codes.H 1.24 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2006,2017 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC: 
// $Source: fips750 fsp/src/powr/fsp/mcp6/powr_service_codes.H 2$

/******************************************************************************/

#ifndef POWR_SERVICE_CODES_H
#define POWR_SERVICE_CODES_H

/**
 *  @file powr_service_codes.H
 *
 *  @brief POWR defined service codes
 *
 *  This file contains all the POWR defined extended service ref codes in
 *	the range specified by epub_service_codes.H.
*/

/******************************************************************************/
/** @page ChangeLogs Change Logs
 * @section POWR_SERVICE_CODES_H powr_service_codes.H
 * @verbatim
 *  CHANGE ACTIVITY:
 *
 *  Flag  Track    Release      Date     Userid    Comments
 *  ----- -------- -----------  -------- --------- -------------------------------
 *  @000  SW318447 fips910      08/14/15 minglw    Port 840 to 910
 *
 *
 *  END CHANGE ACTIVITY
 * @endverbatim
 *
 ******************************************************************************/

/* standard library includes */

/* Other component includes */
#include <fips_comp_id.H>         // component identifiers

/* powr includes */

/**
 *  @enum POWR module IDs
 *
 *  @note POWR defined module ID's.
 */
enum powrModId
{
  // Client Library/Server ModIds
  POWR_MODID_TALK_TO_SERVER             = 0x00,
  POWR_MODID_FAILED_TO_UNFLATTEN_ERROR  = 0x01,
  POWR_MODID_TOOL_MAIN                  = 0x02,
  POWR_MODID_PERC_GET_ERROR_DATA        = 0x03,
  POWR_MODID_PERC_DATA_2                = 0x04,
  POWR_MODID_PROCESS_REQUESTS           = 0x05,
  POWR_MODID_POWR_FAULT_QUERY           = 0x06,
  POWR_MODID_QUERY_SS_PWR_STAT          = 0x07,
  POWR_MODID_GET_NODE_PWR_STAT          = 0x08,
  POWR_MODID_PWR_PRESENT_QUERY          = 0x09,

  POWR_MODID_CIM_FAN_RESOURCE           = 0x0A,
  POWR_MODID_CIM_THERMAL_RESOURCE       = 0x0B,
  POWR_MODID_CIM_POWER_SUPPLY_RESOURCE  = 0x0C,
  POWR_MODID_CIM_PS_REDUNDANCY_RESOURCE = 0x0D,
  POWR_MODID_CIM_CEC_DRAWER_RESOURCE    = 0x0E,
  POWR_MODID_CIM_RACK_RESOURCE          = 0x0F,
  POWR_MODID_CIM_GET_RESOURCE           = 0x10,

  POWR_MODID_POWER_CYCLES               = 0x11,
  POWR_MODID_CIM_ALTITUDE_RESOURCE      = 0x12,

  POWR_MODID_GET_RESOURCE_DATA          = 0x20,
  POWR_MODID_GET_FAN_RESOURCE_DATA      = 0x21,
  POWR_MODID_GET_THERMAL_RESOURCE_DATA  = 0x22,
  POWR_MODID_GET_PS_RESOURCE_DATA       = 0x23,
  POWR_MODID_GET_PS_RS_RESOURCE_DATA    = 0x24,
  POWR_MODID_GET_ALTITUDE_RESOURCE_DATA = 0x25,
  POWR_MODID_GET_VRM_RESOURCE_DATA      = 0x26,
  POWR_MODID_GET_INPUT_POWER            = 0x27,
  POWR_MODID_GET_POWER_SUPPLY_READING   = 0x28,

  POWR_MODID_DPSS_DEV_OPEN              = 0x30,

  POWR_MODID_ENABLE_MEM                 = 0x40,
  POWR_MODID_DISABLE_MEM                = 0x41,

  POWR_MODID_SET_CZ_RPM_FLOOR           = 0x42,
  POWR_MODID_REQUEST_CZ_RPM_INCREASE    = 0x43,
  POWR_MODID_POWR_FANS                  = 0x44,
  POWR_MODID_FAN_MACK                   = 0x45,

  POWR_MODID_ADJUST_MEM                 = 0x46,
  POWR_MODID_ADJUST_PROC                = 0x47,
  POWR_MODID_REQUEST_CZ_RPM_CHANGE      = 0x48,

  // SPIF interface
  POWR_CMD_LINE_HANDLER         = 0xB0,
  POWR_CMD_LINE_FORMAT00        = 0xB1,
  SEND_ACTIVATE_DEACTIVATE      = 0xB3,

  // CCM functions
  POWR_CCM_NODE_PWR_CTRL        = 0xC0,
  POWR_PNU_CCM                  = 0xC1,
  POWR_PFU_CCM                 	= 0xC2,
  POWR_CCM_HEALTH_CHECK         = 0xC3,
  POWR_PFU_OCT                  = 0xC4,

  // TMGT Voltage Control
  POWR_VOLTAGE_CTRL             = 0xD0,

  // VRM vpd request
  POWR_VRM_VPD_REQUEST          = 0xE3,

  // CXXTEST module
  POWR_MODID_CXXTEST            = 0xE4,

  // Placeholder for last one
  POWR_LAST_ONE                 = 0xFF
};

/**
 *  @enum POWR return codes
 *
 *  @note POWR defined return codes.
 */
enum powrReturnCodes
{
  POWR_RC_SUCCESS               = 0x00000000,    // Success.

  POWR_RC_RID_NOT_FOUND         = 0x000000A0,   // RID parameter not found/valid
  POWR_RC_RID_COM_FAIL          = 0x000000A1,   // Failed to read softswitch RID
  POWR_RC_DEVICES_NOT_REPORTING = 0x000000A2,   // All power devices are not reporting
  POWR_RC_TYPE_NOT_VALID        = 0x000000A3,   // Type parameter not valid
};

/**
 * @enum POWR extended refcodes
 *
 * @note As defined by the epub_service_codes.H file, the POWR has been
 *      designated with the ref code range from 0xC100 - 0xC1FF
 */
enum powrExtRefCode
{
  POWR_ERC_NONE                 = 0x0000,                ///< None

  POWR_ERC_BAD_PARM             = POWR_COMP_ID | 0x01,  // Bad parameter passed to a function

  // Client Library/Server Return Codes
  POWR_RC_INTERNAL_ERROR        = POWR_COMP_ID | 0x02,
  POWR_RC_IPC_ERROR             = POWR_COMP_ID | 0x03,
  POWR_RC_DELIVERY_ERROR        = POWR_COMP_ID | 0x04,
  POWR_RC_NO_DAEMON             = POWR_COMP_ID | 0x05,
  POWR_RC_UNDEFINED_RESPONSE    = POWR_COMP_ID | 0x06,
  POWR_RC_NOT_READY             = POWR_COMP_ID | 0x07,

  POWR_RC_CIM_RID_NOT_IN_TABLE      = POWR_COMP_ID | 0x08,
  POWR_RC_CIM_FAILED_UTILMEM_WRITE  = POWR_COMP_ID | 0x09,
  POWR_RC_CIM_RESOURCE_NOT_FOUND    = POWR_COMP_ID | 0x0A,
  POWR_RC_CIM_INVALID_INPUT         = POWR_COMP_ID | 0x0B,
  POWR_RC_CIM_BAD_TYPE              = POWR_COMP_ID | 0x0C,
  POWR_RC_CIM_NOT_SUPPORTED         = POWR_COMP_ID | 0x0D,
  POWR_RC_PRESENT_STATE_PROHIBITS   = POWR_COMP_ID | 0x0E,
  POWR_RC_NO_ENTRIES                = POWR_COMP_ID | 0x0F,

  POWR_RC_VOLT_CHANGE_FAILURE   = POWR_COMP_ID | 0x10,
  POWR_RC_SEC_SEQ_FAIL          = POWR_COMP_ID | 0x11,
  POWR_RC_DIMM_VID_FAIL         = POWR_COMP_ID | 0x12,

  POWR_RC_INVALID_CZ_NUM               = POWR_COMP_ID | 0x13,
  POWR_RC_INVALID_RPM_FLOOR            = POWR_COMP_ID | 0x14,
  POWR_RC_SET_CZ_RPM_FLOOR_FAIL        = POWR_COMP_ID | 0x15,
  POWR_RC_REQUEST_CZ_RPM_INCREASE_FAIL = POWR_COMP_ID | 0x16,
  POWR_RC_INVALID_RID                  = POWR_COMP_ID | 0x17,
  POWR_INVALID_FAN_NUMBER              = POWR_COMP_ID | 0x18,
  // END Client Library/Server Return Codes

  POWR_FAN_REDUNDANT_PATH_FAILED       = POWR_COMP_ID | 0x19, // @xxx jk

  POWR_RC_REQUEST_CZ_RPM_CHANGE_FAIL   = POWR_COMP_ID | 0x1A,

  POWR_ERC_CCM_ERROR            = POWR_COMP_ID | 0xC0,  // CCM operation failed

  POWR_ERC_LAST_ONE             = POWR_COMP_ID | 0xFF   // Not used: indicates range limit
};

/**
 * @enum POWR reason codes
 *
 * @note POWR defined reason codes
 */
enum powrProgressCodes
{
  POWR_IPL_NO_CODE                                      = 0x0000,
  POWR_IPL_STARTING_POWER_UP                            = 0xC100,
  POWR_IPL_INIT_NETWORK_COMPLETE                        = 0xC102,
  POWR_IPL_WAITING_FOR_PROC_VPD1                        = 0xC102,
  POWR_IPL_WAITING_FOR_PROC_VPD2                        = 0xC103,
  POWR_IPL_PROCESSOR_VPD_COLLECTION_COMPLETE            = 0xC104,
  POWR_IPL_NUMBER_OF_PROCESSORS_CHECK_COMPLETE          = 0xC106,
  POWR_IPL_WAITING_FOR_SENSOR_VPD1                      = 0xC106,
  POWR_IPL_WAITING_FOR_SENSOR_VPD2                      = 0xC107,
  POWR_IPL_SENSOR_VPD_COLLECTION_COMPLETE               = 0xC108,
  POWR_IPL_WAITING_FOR_ETHERNET_IP_ADDRESS1             = 0xC10A,
  POWR_IPL_WAITING_FOR_ETHERNET_IP_ADDRESS2             = 0xC10B,

  POWR_IPL_WAIT_FOR_SERIAL_POLL1                        = 0xC110,
  POWR_IPL_WAIT_FOR_SERIAL_POLL2                        = 0xC111,

  POWR_IPL_COLLECT_TMS_COMPLETE                         = 0xC112,



  POWR_IPL_MIN_OFF_DELAY_WAIT1                          = 0xC120,
  POWR_IPL_MIN_OFF_DELAY_WAIT2                          = 0xC121,
  POWR_IPL_MIN_OFF_DELAY_COMPLETE                       = 0xC122,



  POWR_IPL_VOLTAGE_ADJUST_CHECK                         = 0xC140,
  POWR_IPL_VOLTAGE_ADJUST_CHECK_WAIT                    = 0xC141,
  POWR_IPL_VOLTAGE_ADJUST_CHECK_COMPLETE                = 0xC142,
  POWR_IPL_VOLTAGE_ADJUST_WAIT1                         = 0xC14E,
  POWR_IPL_VOLTAGE_ADJUST_WAIT2                         = 0xC14F,
  POWR_IPL_VRM_VOLTAGE_ADJUST_CHECK                     = 0xC150,
  POWR_IPL_VRM_VOLTAGE_ADJUST_WAIT1                     = 0xC152,
  POWR_IPL_VRM_VOLTAGE_ADJUST_WAIT2                     = 0xC153,
  POWR_IPL_VRM_VOLTAGE_ADJUST_CHECK_COMPLETE            = 0xC154,

  POWR_IPL_POWER_CHECK                                  = 0xC160,
  POWR_IPL_PS_POWER_ON                                  = 0xC162,
  POWR_IPL_PS_POWER_ON_WAIT1                            = 0xC164,
  POWR_IPL_PS_POWER_ON_WAIT2                            = 0xC165,
  POWR_IPL_REGS_POWER_ON                                = 0xC166,
  POWR_IPL_REGS_POWER_ON_WAIT0                          = 0xC167,
  POWR_IPL_REGS_POWER_ON_WAIT1                          = 0xC168,
  POWR_IPL_REGS_POWER_ON_WAIT2                          = 0xC169,

  POWR_IPL_MEM_VRMS_POWER_ON                            = 0xC170,
  POWR_IPL_MEM_VRMS_POWER_ON_WAIT1                      = 0xC172,

  POWR_IPL_ACTIVATE_PGOODS                              = 0xC180,
  POWR_IPL_ACTIVATE_PGOODS2                             = 0xC181,
  POWR_IPL_POWER_ON_DELAY_WAIT1                         = 0xC182,
  POWR_IPL_POWER_ON_DELAY_WAIT2                         = 0xC183,
  POWR_IPL_POWER_ON_DELAY_COMPLETE                      = 0xC184,

  POWR_IPL_PGOOD_DELAY_WAIT1                            = 0xC1A0,
  POWR_IPL_PGOOD_DELAY_WAIT2                            = 0xC1A1,
  POWR_IPL_PGOOD_DELAY_COMPLETE                         = 0xC1A2,

  POWR_IPL_PDOWN_DELAY_WAIT1                            = 0xC1B0,
  POWR_IPL_PDOWN_DELAY_WAIT2                            = 0xC1B1,
  POWR_IPL_PDOWN_DELAY_COMPLETE                         = 0xC1B2,
  POWR_IPL_PDOWN_DEVICE_OFF_WAIT1                       = 0xC1B4,
  POWR_IPL_PDOWN_DEVICE_OFF_WAIT2                       = 0xC1B5,
  POWR_IPL_PDOWN_WAITING_FOR_IP_ADDRESS1                = 0xC1B4,
  POWR_IPL_PDOWN_WAITING_FOR_IP_ADDRESS2                = 0xC1B5,
  POWR_IPL_PDOWN_DEVICE_OFF_COMPLETE                    = 0xC1B6,
  POWR_IPL_PDOWN_STATE_COMPLETE                         = 0xC1BE,


  POWR_IPL_CEC_POWER_OFF_REQUEST_COMPLETE               = 0xC1B8,


  /* Following codes (0xC1D0, 0xC1D1) are used by the softswitch
   * command line program if its waiting for spif-spcn communications
   * to be ready.
   */
  POWR_WAITING_FOR_SPIF_READY_WAIT1                     = 0xC1D0,
  POWR_WAITING_FOR_SPIF_READY_WAIT2                     = 0xC1D1,

  POWR_IPL_CCM_HEALTH_CHECK_START                       = 0xC1E0,
  POWR_IPL_CCM_HEALTH_CHECK_WAIT1                       = 0xC1E1,
  POWR_IPL_CCM_HEALTH_CHECK_WAIT2                       = 0xC1E2,
  POWR_IPL_CCM_HEALTH_CHECK_COMPLETE                    = 0xC1EE,

  POWR_IPL_CRITICAL_FAULT_DOWN                          = 0xC1CF,
  POWR_IPL_PGOOD_TO_PANEL_SET                           = 0xC1FF,


};

/** @enum  powrUserDataVersion
 *
 * Identifier for the version of user data in an error log.
   * This value is used in conjuction with the type field to format
   * of the additional data in an error log.  Versions and type should
   * be unique across subcomponents of the POWR component.
   */
enum powrUserDataVersion
{
  POWR_DEFAULT_VER	= 0x0001,   // Default version
};


/** @enum  powrUserDataType
  *
  * Identifier for the user data type for the user data in an error log.
  * This value is used in conjuction with the version field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the POWR component.
  *
  * Note: Need to keep in sync with user data types in powr_fips_log.H
*/
enum powrUserDataType
{
    POWR_TRACE_DATA                     = 0x0000, ///< SPCN (ILOG) trace data
    POWR_FILE_NAME_DATA                 = 0x0001, ///< Data is a file system path name
    POWR_VRM_TELEM_DATA                 = 0x0004, ///< VRM telemetry data
};

#endif /* POWR_SERVICE_CODES_H */

/* End of file powr_service_codes.h */
