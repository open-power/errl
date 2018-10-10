// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/rtim/fsp/rtim_service_codes.H 1.6.19.18 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2002,2015 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC: 
// $Source: fips740 fsp/src/rtim/fsp/rtim_service_codes.H 6$

/* @(#)33       1.6.19.13  src/rtim/fsp/rtim_service_codes.H, esw_rtim, fips720 2/12/09 13:59:57  */

#ifndef RTIM_SERVICE_CODES_H
#define RTIM_SERVICE_CODES_H

/**
 *  @file rtim_service_codes.H
 *
 *  @brief This file contains the definition of constants used to create SRCs
 *         and error logs.
 */

// Change Log ******************************************************************/
//
// ch#  Feat/def#      Userid   Date     Description
// ---- --------- -------- -------- ---------------------------------------
// n/a  f 383685  twarne   09/16/02 ft322.2 - New file creation
// n/a  f 383840  twarne   09/25/02 ft322.3 - Changes for TPO
// n/a  f 383840  twarne   11/13/02 ft322.3 - Added new module IDs and
//                                              extended refcodes.
// n/a  f 391822  twarne   01/02/03 ft1345.28 - Updated for UtilReg calls.
// n/a  f 392615  twarne   02/14/03 ft322.4 - Added RTIM_CHECK_BATTERY_ALERT
//                                              and RTIM_ERC_GPIO_ERROR
// n/a  f 399234  twarne   03/25/03 ft1562 - Added module IDs for rtimexec.C
// n/a  f 399234  twarne   03/27/03 ft1562 - Added RTIM_ERC_BAD_ARG.
// n/a  f 416009  twarne   09/08/03 ft1680.2 - Redundant FSP and
//                                    serviceability changes.
// n/a  d 431260  twarne   01/27/04 Added RTIMUTILITY_SetSmgrStateData and
//                                    RTIMUTILITY_GetSmgrStateData.
// n/a  d 436455  twarne   02/19/04 Added RTIM_ERC_TOD_SIT_ADAL_READ_ERROR,
//                                    RTIM_ERC_TOD_SIT_ADAL_WRITE_ERROR,
//                                    RTIM_ERC_TOD_SIT_ADAL_WRITE_ERROR_1,
//                                    RTIM_ERC_REGISTRY_DATA_INITIALIZED,
//                                    RTIM_ERC_TIME_CHANGED_INFORMATIONAL,
//                                    RTIM_ERC_DAEMONLOCK_FAILED,
//                                    RTIM_ERC_RTIMINIT_FORK_FAILED.
// n/a  d 437730  twarne   02/26/04 Added RTIM_ERC_REGISTRY_READ_ERROR_2.
//                                    Pushed down values of #defines
//                                    to make room.
// n/a  d 438431  twarne   03/18/04 Added rtimFileId_enum.
// n/a  d 464419  twarne   07/28/04 Added RTIMINIT_SetBatteryAlertTime and
//                                    RTIMINIT_GetBatteryAlertTime.
// n/a  d 469264  twarne   08/24/04 Added RTIM_ERC_THREAD_CREATE_FAILURE.
// n/a  F 505241  whinery  05/20/05 Changed reason code range
// n/a  d 522060  twarne   10/18/05 Added RTIMINIT_CheckIplParmsTimeData,
//                                    RTIMINTERFACE_CheckIplParmsTimeData,
//                                    RTIM_ERC_TIME_COMPARISON_ERROR.
//                                  Expanded rtimUserDataVersion and
//                                    rtimUserDataType enums to encompass all
//                                    currently added elog user details sections.
// n/a  d 537641  twarne   02/28/06 Added RTIM_ERC_THREAD_CREATE_FAILURE_1.
// n/a  d 575591  twarne   10/19/06 Serviceability review changes.
//                                  Removed unused rtimExtRefCode_enum values.
//                                  Added RTIM_ERC_RTC_SETTIMEOFDAY_ERROR,
//                                    RTIM_ERC_RTIMINIT_FATAL_ERROR,
//                                    RTIM_ERC_PTHREAD_CREATE_MONREGWRITES,
//                                    RTIM_ERC_SETTIMEOFDAY_FAILURE,
//                                    RTIM_ERC_ERRL_UNFLATTEN_ERROR,
//                                    RTIM_ERC_PTHREAD_CREATE_RMGRSYNCS,
//                                    RTIM_ERC_LAST_REASON_CODE.
// n/a  f 594660  twarne   03/13/07 Added RTIMUTILITY_GetDeltaTime.
// n/a  f 619003  twarne   07/19/07 Added RTIMINIT_ClockAdjust,
//                                    RTIMINIT_MonitorUtilRegWrites,
//                                    RTIM_ERC_RTC_ADAL_ERROR.
// n/a  d 644489  bjs      01/16/08 Add full refcode to each rtimExtRefCode_enum
// bs01 d 651599  bjs      03/11/08 Add some iomux info to battery elog for debug
// bs02 d 668133  bjs      07/14/08 Add refcode/module id to log getTime temp fails
// bs03 f 684210  bjs      10/23/08 Add way for some dude like CCM to do battery test
// bs04 d 694442  bjs      02/03/09 Add new sync requests to be done in RTIM daemon
// nb01 D 748876  bofferdn 04/19/10 Add RTIM_ERC_PARTIAL_SUCCESS
//                                  Add module IDs
//
// ch#  Feat/def#      Activity      Userid   Date      Description
// ---- ----------     --------     -------- --------   --------------------------------------
// bs05 SW054566    AIXOS01742476     bjs   02/08/11    Start some real work on NTP support 
// bs06 SW056968    AIXOS01755763     bjs   02/17/11    Refcode for not allowing time set with NTP
// bs07 SW058068    AIXOS01762011     bjs   02/25/11    Data section for NTP logfile
// bs08 SW060246    AIXOS01772586     bjs   03/11/11    NTP info/pred logs whens starting ntpd
// bs09 SW065751    AIXOS01799303     bjs   04/06/11    Strange fatal type errors for NTP 
// bs10 SW067644    AIXOS01808353     bjs   04/13/11    NTP config now checking input parms
//    
// Flag PTR/DCR#  Userid   Date     Description
// ---- --------- -------- -------- -----------------------------------
// gb01 857780    gauravb  10/17/12 Change gpio, iic and uart to FDAL
// gb02 f 872271  gauravb  02/27/13 Replacing adal_rtc calls with fdal_rtc apis.
// //   d 958956  ratagupt 05/04/15 read the battery rid from system model.
//
// End Change Log **************************************************************/

/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <fips_comp_id.H>         // component identifiers
#include <epub_service_codes.H>   // reference codes


/*-----------------------------------------------------------------------------*/
/* Constants                                                                   */
/*-----------------------------------------------------------------------------*/

/** @enum rtimModId_enum
 *        Module IDs for each rtim function/method within a .C file
 */
enum rtimModId_enum
{
  // rtiminit.C
  RTIMINIT_MAIN                     = 0x01,
  RTIMINIT_percGetErrorData         = 0x02,
  RTIMINIT_GetSystemTime            = 0x02,
  RTIMINIT_SetSystemTime            = 0x03,
  RTIMINIT_SetIplParmsTimeData      = 0x04,
  RTIMINIT_SetDeltaYear             = 0x05,
  RTIMINIT_SetTpoData               = 0x06,
  RTIMINIT_GetTpoData               = 0x07,
  RTIMINIT_GetSmgrStateData         = 0x08,
  RTIMINIT_SetupTimer               = 0x09,
  RTIMINIT_ClockAdjust              = 0x0A,
  RTIMINIT_SynchronizeSibling       = 0x0B,
  RTIMINIT_ProcessTimeout           = 0x0C,
  RTIMINIT_ProcessMessage           = 0x0D,
  RTIMINIT_DisableTpo               = 0x0E,
  RTIMINIT_CheckBattery             = 0x0F,
  RTIMINIT_SetTimeOfDay             = 0x10,
  RTIMINIT_GetTimeOfDay             = 0x11,
  RTIMINIT_SetTimedPowerOn          = 0x12,
  RTIMINIT_GetTimedPowerOn          = 0x13,
  RTIMINIT_DisableTimedPowerOn      = 0x14,
  RTIMINIT_IplTimeParmsInit         = 0x15,
  RTIMINIT_SyncDataRecv             = 0x16,
  RTIMINIT_LogTimestamps            = 0x17,
  RTIMINIT_CalculateDeltaTime       = 0x18,
  RTIMINIT_SetBatteryAlertTime      = 0x19,
  RTIMINIT_GetBatteryAlertTime      = 0x1A,
  RTIMINIT_MonitorUtilRegWrites     = 0x1B,
  RTIMINIT_CheckBatteryNow          = 0x1C,  //bs03a
  RTIMINIT_NtpRestart               = 0x1D,  //bs05a
  RTIMINIT_NtpLogErrorIfNeeded      = 0x1E,  //bs08a
  // rtiminterface.C
  RTIMINTERFACE_SetTimeOfDay        = 0x20,
  RTIMINTERFACE_GetTimeOfDay        = 0x21,
  RTIMINTERFACE_ConvertTimeValToBCD = 0x22,
  RTIMINTERFACE_ConvertBCDtoTimeVal = 0x23,
  RTIMINTERFACE_CompareBCDtime      = 0x24,
  RTIMINTERFACE_SetTimedPowerOn     = 0x25,
  RTIMINTERFACE_GetTimedPowerOn     = 0x26,
  RTIMINTERFACE_DisableTimedPowerOn = 0x27,
  RTIMINTERFACE_GetBatteryStatus    = 0x28,
  RTIMINTERFACE_IplParmsInit        = 0x29,
  RTIMINTERFACE_CheckIplParmsTimeData  = 0x2A,
  RTIMINTERFACE_RemoteProcessMsg    = 0x2B,  //bs04a
  RTIMINTERFACE_SyncToBackup        = 0x2C,  //bs04a
  RTIMINTERFACE_SetNtpConfig        = 0x2D,  //bs10a
  // rtimutility.C
  RTIMUTILITY_GetIplParmsTimeData   = 0x40,
  RTIMUTILITY_GetDeltaYear          = 0x41,
  RTIMUTILITY_RtimdSendMsg          = 0x42,
  RTIMUTILITY_SyncInternalData      = 0x43,
  RTIMUTILITY_GetDeltaTime          = 0x44,
  // rtimRTC.C
  RTIMRTC_GetTime                   = 0x50,       //bs02a
  // rtimexec.C
  RTIMEXEC_MAIN                     = 0x60,
  RTIMEXEC_percGetErrorData         = 0x61,
  // rtimprocessmsg.C
  RTIM_PROCESS_MSG                  = 0x80,
  // rtimtest.C
  RTIMTEST_MAIN                     = 0xC0,

  //@nb01A>
  // src/smgr/asrv/fsp/tpoimplementation.C
  TPOIMPLEMENTATION_VerifyOperatingMode        = 0xD0,
  TPOIMPLEMENTATION_CreateSysTimeInvalidError  = 0xD1,
  TPOIMPLEMENTATION_VerifyChangeTpoPermissions = 0xD2,
  //<@nb01A
};

/** @enum rtimFileId_enum
 *        File IDs for each rtim .C file
 */
enum rtimFileId_enum
{
  RTIMINIT_FILE                     = 0x01,
  RTIMINTERFACE_FILE                = 0x02,
  RTIMUTILITY_FILE                  = 0x03,
  RTIMEXEC_FILE                     = 0x04,
  RTIMPROCESSMSG_FILE               = 0x05,
  RTIMBATTERY_FILE                  = 0x06,
  RTIMRTC_FILE                      = 0x07         //gb02a
};


/** @enum rtimExtRefCode_enum
 *        Extended reference codes for rtim SRCs.  Extended
 *        ref codes can be used in more than one location.  The combination
 *        of module id and extended ref code points to a unique piece of code.
 *        Therefore, if the same error can occur in multiple places within the
 *        same function/method, each error would need its own unique extended
 *        ref code.
 *
 *        The range is 0x3301 through 0x33FF
 */
enum rtimExtRefCode_enum
{
  RTIM_ERC_RTC_NOT_COUNTING                = RTIM_COMP_ID | 0x01, // 3301 The RTC hardware is not operational
  RTIM_ERC_RTC_SETTIMEOFDAY_ERROR          = RTIM_COMP_ID | 0x02, // 3302 The RTC hardware could not be set
  RTIM_ERC_SYS_TIME_INVALID                = RTIM_COMP_ID | 0x03, // 3303 Invalid system time detected
  RTIM_ERC_SEMAPHORE_ERROR                 = RTIM_COMP_ID | 0x04, // 3304 Error in getting rtim semaphore
  RTIM_ERC_BATTERY_FAILURE                 = RTIM_COMP_ID | 0x05, // 3305 The RTC/NVRAM battery has low voltage
  RTIM_ERC_INPUT_DATA_INVALID              = RTIM_COMP_ID | 0x06, // 3306 Caller passed in bad data
  RTIM_ERC_NO_PERMISSION                   = RTIM_COMP_ID | 0x07, // 3307 Caller lacks permission to perform op
  RTIM_ERC_GPIO_ERROR                      = RTIM_COMP_ID | 0x08, // 3308 GPIO read/write error
  RTIM_ERC_REGISTRY_READ_ERROR             = RTIM_COMP_ID | 0x09, // 3309 Registry read error
  RTIM_ERC_SETTIMEOFDAY_FAILURE            = RTIM_COMP_ID | 0x0A, // 330A settimeofday() failure
  RTIM_ERC_ERRL_UNFLATTEN_ERROR            = RTIM_COMP_ID | 0x0B, // 330B Unable to unflatten an error log
  RTIM_ERC_REGISTRY_WRITE_ERROR            = RTIM_COMP_ID | 0x0C, // 330C Registry write error
  RTIM_ERC_RTIMINIT_FATAL_ERROR            = RTIM_COMP_ID | 0x0D, // 330D rtiminit daemon fatal error
  RTIM_ERC_SOCKET_CREATION_ERROR           = RTIM_COMP_ID | 0x0E, // 330E Error in creating a unix socket
  RTIM_ERC_RTC_ADAL_ERROR                  = RTIM_COMP_ID | 0x0F, // 330F adal_rtc_xxxx error.
  RTIM_ERC_SOCKET_CONNECTION_ERROR         = RTIM_COMP_ID | 0x10, // 3310 Error in connecting to a unix socket
  RTIM_ERC_SOCKET_BIND_ERROR               = RTIM_COMP_ID | 0x11, // 3311 Error in binding to a unix socket
  RTIM_ERC_SOCKET_LISTEN_ERROR             = RTIM_COMP_ID | 0x12, // 3312 Error in listening to a unix socket
  RTIM_ERC_RESERVED_13                     = RTIM_COMP_ID | 0x13, // 3313 RESERVED
  RTIM_ERC_SOCKET_ACCEPT_ERROR             = RTIM_COMP_ID | 0x14, // 3314 Error in accepting a unix socket
  RTIM_ERC_SOCKET_SEND_ERROR               = RTIM_COMP_ID | 0x15, // 3315 Error in sending a msg on a unix socket
  RTIM_ERC_RESERVED_16                     = RTIM_COMP_ID | 0x16, // 3316 RESERVED
  RTIM_ERC_RESERVED_17                     = RTIM_COMP_ID | 0x17, // 3317 RESERVED
  RTIM_ERC_RESERVED_18                     = RTIM_COMP_ID | 0x18, // 3318 RESERVED
  RTIM_ERC_SOCKET_RECEIVE_ERROR            = RTIM_COMP_ID | 0x19, // 3319 Error in receiving a msg on a unix socket
  RTIM_ERC_RESERVED_1A                     = RTIM_COMP_ID | 0x1A, // 331A RESERVED
  RTIM_ERC_SOCKET_CLOSE_ERROR              = RTIM_COMP_ID | 0x1B, // 331B Error in closing a unix socket
  RTIM_ERC_INVALID_OPERATION               = RTIM_COMP_ID | 0x1C, // 331C An invalid operation was requested
  RTIM_ERC_RESERVED_1D                     = RTIM_COMP_ID | 0x1D, // 331D RESERVED
  RTIM_ERC_RESERVED_1E                     = RTIM_COMP_ID | 0x1E, // 331E RESERVED
  RTIM_ERC_RESERVED_1F                     = RTIM_COMP_ID | 0x1F, // 331F RESERVED
  RTIM_ERC_REGISTRY_DATA_INITIALIZED       = RTIM_COMP_ID | 0x20, // 3320 Default data was writen to a registry entry
  RTIM_ERC_TIME_CHANGED_INFORMATIONAL      = RTIM_COMP_ID | 0x21, // 3321 The system time has been changed
  RTIM_ERC_DAEMONLOCK_FAILED               = RTIM_COMP_ID | 0x22, // 3322 The rtiminit daemon could not get the lock
  RTIM_ERC_RTIMINIT_FORK_FAILED            = RTIM_COMP_ID | 0x23, // 3323 The rtiminit main() task failed to fork
  RTIM_ERC_TPO_DISABLED_TIME_INVALID       = RTIM_COMP_ID | 0x24, // 3324 The Timed Power On disabled due to invalid sys time
  RTIM_ERC_INVALID_DAEMON_COMMAND          = RTIM_COMP_ID | 0x25, // 3325 The rtiminit daemon received an invalid command
  RTIM_ERC_PTHREAD_CREATE_MONREGWRITES     = RTIM_COMP_ID | 0x26, // 3326 MonitorUtilRegWrites pthread_create
  RTIM_ERC_TIME_COMPARISON_ERROR           = RTIM_COMP_ID | 0x27, // 3327 Two times did not match
  RTIM_ERC_RESERVED_28                     = RTIM_COMP_ID | 0x28, // 3328 RESERVED
  RTIM_ERC_RESERVED_29                     = RTIM_COMP_ID | 0x29, // 3329 RESERVED
  RTIM_ERC_PTHREAD_CREATE_RMGRSYNCS        = RTIM_COMP_ID | 0x2A, // 332A PerformRmgrSyncs pthread_create
  RTIM_ERC_RTC_GETTIME_FAILURE             = RTIM_COMP_ID | 0x2B, // 332B adal_rtc_get_timeval failed      bs02a
  RTIM_ERC_SYNC_SYSTEM_TIME_FAILED         = RTIM_COMP_ID | 0x2C, // 332C sync of time on backup failed    bs04a
  RTIM_ERC_SYNC_GET_TODTIME_FAILED         = RTIM_COMP_ID | 0x2D, // 332D sync of time on backup failed    bs04a
  RTIM_ERC_PARTIAL_SUCCESS		       = RTIM_COMP_ID | 0x2E, // 332E operation partially successful   @nb01A
  RTIM_ERC_NTP_STARTUP                     = RTIM_COMP_ID | 0x2F, // 332F NTP startup failed               bs05a
  RTIM_ERC_NTP_FORK_FAILED                 = RTIM_COMP_ID | 0x30, // 3330 NTP fork failed                  bs05a
  RTIM_ERC_NTP_SETTIME_INVALID             = RTIM_COMP_ID | 0x31, // 3331 NTP running so can't set time    bs06a
  RTIM_ERC_NTP_DAEMON_STARTED              = RTIM_COMP_ID | 0x32, // 3332 NTP daemon has been (re)started  bs08a
  RTIM_ERC_NTP_SERVER_NOT_SYNCD            = RTIM_COMP_ID | 0x33, // 3333 NTP is not sync'd to server      bs08a
  RTIM_ERC_NTP_KILL_FAILURE                = RTIM_COMP_ID | 0x34, // 3334 NTP was not able to be killed    bs09a
  RTIM_ERC_NTP_EXECVP_FAILURE              = RTIM_COMP_ID | 0x35, // 3335 NTP is not sync'd to server      bs09a
  RTIM_ERC_NTP_CFG_INVALID_PARMS           = RTIM_COMP_ID | 0x36, // 3336 NTP bad parms to setconfig       bs10a
  RTIM_ERC_BATTERY_TESTPIN_NOT_LOW         = RTIM_COMP_ID | 0x37, // 3337 Battery Test Pin could not be set to low   gb01a
  RTIM_ERC_BATTERY_TESTPIN_NOT_HIGH        = RTIM_COMP_ID | 0x38, // 3338 Battery Test Pin could not be set to high  gb01a
  RTIM_ERC_RTC_FDAL_ERROR                  = RTIM_COMP_ID | 0x39, // 330F fdal_rtc_xxxx error              gb02a
  RTIM_ERC_SYS_MODEL_ERROR                 = RTIM_COMP_ID | 0x40, // Error in system model output
  RTIM_ERC_LAST_REASON_CODE                = RTIM_COMP_ID | 0x40  // Always equal to the value above       bs10c
}; 


/** @enum  rtimUserDataVersion
  *
  * Identifier for the version of user data in an error log.
  * This value is used in conjuction with the type field to format
  * the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the rtim component.
*/
enum rtimUserDataVersion
{
  RTIM_UDV_UNDEFINED  = 0x00,
  RTIM_UDV_DATA_VER_1 = 0x01,
  RTIM_UDV_DATA_VER_2 = 0x02,
  RTIM_UDV_DATA_VER_3 = 0x03,
  RTIM_UDV_DATA_VER_IOMUX = 0x04,    //bs01a
  RTIM_UDV_DATA_VER_NTP   = 0x05     //bs07a
};



/** @enum  rtimUserDataType
  *
  * Identifier for the user data type for the user data in an error log.
  * This value is used in conjuction with the version field to format
  * the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the rtim component.
*/
enum rtimUserDataType
{
  RTIM_UDT_UNDEFINED                 = 0x00,
  RTIM_UDT_BCD_COMPARE_DATA          = 0x01, // BCD comparison data
  RTIM_UDT_REG_KEY_DATA              = 0x02, // ASCII Registry Key data
  RTIM_UDT_ALL_REG_DATA              = 0x03, // All RTIM registry data
  RTIM_UDT_TOD_SIT_FFDC_DATA         = 0x04, // TOD/SIT FFDC data
  RTIM_UDT_GPIO_FFDC_DATA            = 0x05, // GPIO FFDC data
  RTIM_UDT_SET_TOD_TRACELOG_DATA     = 0x06, // SetTimeOfDay TraceLog data
  RTIM_UDT_RTIMD_MSG_DATA            = 0x07, // RTIMD message data
  RTIM_UDT_ELAPSED_TIME_COMPARE_DATA = 0x08, // Elapsed Time comparison data
  RTIM_UDT_FSPTRACE_DATA             = 0x09, // Binary fsp-trace data
  RTIM_UDT_RTC_FFDC_DATA             = 0x0A, // RTC FFDC data
  RTIM_UDT_IOMUX_FFDC_DATA           = 0x0B, // IOMUX data from dev driver       bs01a
  RTIM_UDT_NTP_LOGFILE_DATA          = 0x0C, // NTP logfile data                 bs07a
  RTIM_UDT_NTP_FSPCONFIG_DATA        = 0x0D, // NTP conf file on FSP             bs08a
  RTIM_UDT_NTP_CMECONFIG_DATA        = 0x0E  // NTP info from CME                bs08a
};

#endif // RTIM_SERVICE_CODES_H
