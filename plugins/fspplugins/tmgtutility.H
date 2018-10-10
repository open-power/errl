// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgtutility.H 1.9.10.6 
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
// $Source: fips740 fsp/src/tmgt/fsp/tmgtutility.H 1$


#ifndef TMGTUTILITY_H
#define TMGTUTILITY_H

/**
 * @file tmgtutility.H
 *
 * @brief This file contains various utility functions used internally by the
 *        thermal management component.
 */

#include <string>
#include <tmgt.H>
#include <tmgtmsg.H>
#include <tmgt_elog_parser.H>
#ifndef _X86NFP
#include <sstream>
#include <iomanip>
#include <tmgt_toifnode.H>
#include <applet/tmgtApplet.H>
#endif

#include <errlentry.H>             // ErrlEntry class

#ifndef _X86NFP
#include <pthread.h>
#include <utilmutex.H>
#include <utilscopelock.H>
#include <smgr_ipltypes.H>
#include <smgr_registry.H>
#include <utilfile.H>

// helpfull trace macros
extern tracDesc_t   g_tmgtTraceDesc;
extern tracDesc_t   iv_toifTraceDesc;
extern tracDesc_t   g_tmgtHwsvTraceDesc;
#endif

extern char TOIF_DAEMON_NAME[TMGT_MAX_NUMBER_OF_NODES][14];

const char TOIF_TRACE_COMP_NAME[TMGT_MAX_NUMBER_OF_NODES][6] =
{
    { "TOIF0" },
    { "TOIF1" },
    { "TOIF2" },
    { "TOIF3" }
};

#ifdef _X86NFP
#define TRUE 1
#define FALSE 0
#endif

#define TO_5SEC  0x1388
#define TO_10SEC 0x2710
#define TO_15SEC 0x3A98
#define TO_20SEC 0x4E20
//Add C> for client side traces
#ifdef TMGT_CLIENT_FILES

#define    TMGT_DBG( _fmt_, _args_...)             TRACDCOMP( g_tmgtTraceDesc, "C>D>" _fmt_, ##_args_ )
#define    TMGT_INF( _fmt_, _args_...)             TRACFCOMP( g_tmgtTraceDesc, "C>" _fmt_, ##_args_ )
#define    TMGT_WRN( _fmt_, _args_...)             TRACFCOMP( g_tmgtTraceDesc, "C>W>" _fmt_, ##_args_ )
#define    TMGT_ERR( _fmt_, _args_...)             TRACFCOMP( g_tmgtTraceDesc, "C>E>" _fmt_, ##_args_ )
#define    TMGT_DBG_BIN( _fmt_, _args_...)         TRACDBIN( g_tmgtTraceDesc, "C>D>" _fmt_, ##_args_ )
#define    TMGT_BIN( _fmt_, _args_...)             TRACFBIN( g_tmgtTraceDesc, "C>" _fmt_, ##_args_ )

#else

#define    TMGT_DBG( _fmt_, _args_...)             TRACDCOMP( g_tmgtTraceDesc, "D>" _fmt_, ##_args_ )
#define    TMGT_INF( _fmt_, _args_...)             TRACFCOMP( g_tmgtTraceDesc,  _fmt_, ##_args_ )
#define    TMGT_WRN( _fmt_, _args_...)             TRACFCOMP( g_tmgtTraceDesc, "W>" _fmt_, ##_args_ )
#define    TMGT_ERR( _fmt_, _args_...)             TRACFCOMP( g_tmgtTraceDesc, "E>" _fmt_, ##_args_ )
#define    TMGT_DBG_BIN( _fmt_, _args_...)         TRACDBIN( g_tmgtTraceDesc, "D>" _fmt_, ##_args_ )
#define    TMGT_BIN( _fmt_, _args_...)             TRACFBIN( g_tmgtTraceDesc, _fmt_, ##_args_ )

#endif

#define    TOIF_INF( _fmt_, _args_...)             TRACFCOMP( iv_toifTraceDesc,      _fmt_, ##_args_ )
#define    TOIF_WRN( _fmt_, _args_...)             TRACFCOMP( iv_toifTraceDesc, "W>" _fmt_, ##_args_ )
#define    TOIF_ERR( _fmt_, _args_...)             TRACFCOMP( iv_toifTraceDesc, "E>" _fmt_, ##_args_ )
#define    TOIF_BIN( _fmt_, _args_...)             TRACFBIN( iv_toifTraceDesc,       _fmt_, ##_args_ )
#define    TOIF_DBG( _fmt_, _args_...)             TRACDCOMP( iv_toifTraceDesc, "D>" _fmt_, ##_args_ )
#define    TOIF_DBG_BIN( _fmt_, _args_...)         TRACDBIN( iv_toifTraceDesc,  "D>" _fmt_, ##_args_ )

#define    TMGT_HWSV_INF( _fmt_, _args_...)        TRACFCOMP( g_tmgtHwsvTraceDesc,      _fmt_, ##_args_ )
#define    TMGT_HWSV_WRN( _fmt_, _args_...)        TRACFCOMP( g_tmgtHwsvTraceDesc, "W>" _fmt_, ##_args_ )
#define    TMGT_HWSV_ERR( _fmt_, _args_...)        TRACFCOMP( g_tmgtHwsvTraceDesc, "E>" _fmt_, ##_args_ )
#define    TMGT_HWSV_BIN( _fmt_, _args_...)        TRACFBIN( g_tmgtHwsvTraceDesc,       _fmt_, ##_args_ )
#define    TMGT_HWSV_DBG( _fmt_, _args_...)        TRACDCOMP( g_tmgtHwsvTraceDesc, "D>" _fmt_, ##_args_ )
#define    TMGT_HWSV_DBG_BIN( _fmt_, _args_...)    TRACDBIN( g_tmgtHwsvTraceDesc,  "D>" _fmt_, ##_args_ )


/******************************************************************************/
/*            P1 and P2 File Read Write Functions and Defines                 */
/*                                                                            */
/* Functions below are for writing to the p1/p2 file which is replacing       */
/* registry entries due to the ridiculous amount of data we have to save.     */
/*                                                                            */
/* NOTE: This code must work for all executable/library functions which is    */
/*       why it is located in tmgt_common_server_functions.                   */
/******************************************************************************/
const uint16_t TMGT_P1_FILE = 0x00;
const uint16_t TMGT_P2_FILE = 0x01;

const uint16_t TMGT_MAX_RETRIES = 4;
enum tmgtP1P2FileAction
{
    ACTION_FILE_READ              = 0x00,
    ACTION_FILE_WRITE             = 0x01,
};

enum tmgtP1P2FileItem
{
    TMGT_FILE_VERSION                  = 0x00,
    TMGT_FILE_OVERSUBSCRIPTION_PCAP    = 0x01,
    TMGT_FILE_SMS_ENCODE               = 0x02,
    TMGT_FILE_CURR_POWER_CAP           = 0x03,
    TMGT_FILE_PCAP_MAX                 = 0x04,
    TMGT_FILE_PCAP_MIN                 = 0x05,
    TMGT_FILE_SOFT_PCAP_MIN            = 0x06,
    TMGT_FILE_PS_EFF                   = 0x07,
    TMGT_FILE_RESERVED08               = 0x08,
    TMGT_FILE_SYSTEM_PCAP_MAX          = 0x09,
    TMGT_FILE_SYSTEM_PCAP_MIN          = 0x0A,
    TMGT_FILE_SYSTEM_SOFT_PCAP_MIN     = 0x0B,
    TMGT_FILE_RESERVED0C               = 0x0C,
    TMGT_FILE_RESERVED0D               = 0x0D,
    TMGT_FILE_RESERVED0E               = 0x0E,
    TMGT_FILE_NODE_CURR_PCAP           = 0x0F,
    TMGT_FILE_RESERVED10               = 0x10,
    TMGT_FILE_AC_PCAP_MAX              = 0x11,
    TMGT_FILE_AC_PCAP_MIN              = 0x12,
    TMGT_FILE_AC_SOFT_PCAP_MIN         = 0x13,
    TMGT_FILE_AC_CURR_POWER_CAP        = 0x14,
    TMGT_FILE_RESERVED15               = 0x15,
    TMGT_FILE_RESERVED16               = 0x16,
    TMGT_FILE_RESERVED17               = 0x17,
    TMGT_FILE_RESERVED18               = 0x18,
    TMGT_FILE_RESERVED19               = 0x19,
    TMGT_FILE_RESERVED1A               = 0x1A,
    TMGT_FILE_RESERVED1B               = 0x1B,
    TMGT_FILE_PCAP_FLAGS               = 0x1C,
    TMGT_FILE_PCAP_TURBO               = 0x1D,
    TMGT_FILE_DVFS_PCAP_MIN            = 0x1E,
    TMGT_FILE_PCAP_MAX_CURR            = 0x1F,
    TMGT_FILE_PCAP_MIN_CURR            = 0x20,
    TMGT_FILE_AC_PCAP_TURBO            = 0x21,
    TMGT_FILE_CUST_SET_MODE            = 0x22,

    // Reserved
    TMGT_FILE_RESERVED_BYTES           = 0xFE,

    // End flag
    TMGT_FILE_END                      = 0xFF,
};

const char tmgtP1P2FileItemString[35][35] =
{
    "Version",
    "OversubscriptionPcap",
    "SmsEncode",
    "CurrentPowerCap",
    "PcapMax",
    "PcapMin",
    "PcapSoftMin",
    "PSEff",
    "Reserved08",
    "SystemPcapMax",
    "SystemPcapMin",
    "SystemPcapSoftMin",
    "Reserved0C",
    "Reserved0D",
    "Reserved0E",
    "NodeCurrPcap",
    "Reserved10",
    "AcPcapMax",
    "AcPcapMin",
    "AcPcapSoftMin",
    "AcCurrentPowerCap",
    "Reserved15",
    "Reserved16",
    "Reserved17",
    "Reserved18",
    "Reserved19",
    "Reserved1A",
    "Reserved1B",
    "PcapFlags",
    "PcapTurbo",
    "PcapDVFSMin",
    "PcapMaxCurr",
    "PcapMinCurr",
    "AcPcapTurbo"
    "CustSetMode"
};

struct p1_p2_file_table_t
{
    tmgtP1P2FileItem item;        // Version, Oversubscription Pcap, etc
    uint8_t node;                 // Node
    uint8_t file;                 // P1 or P2 file
    uint8_t size;                 // Size of entry
    uint16_t index;                // Location in file
};

extern const p1_p2_file_table_t G_p1_p2_file_table[];

struct p1_p2_file_item_t
{
    tmgtP1P2FileItem item_name;   // Version, Oversubscription Pcap, etc
    uint8_t length;               // Size of entry
    uint8_t value[4];             // value to write
    uint8_t node;                 // Node
};


uint16_t get_item_offset(const tmgtP1P2FileItem i_item, const uint8_t i_node);

#ifndef _X86NFP
errlHndl_t p1_p2_file_read(UtilFile *i_file,
                           const uint16_t  i_table_index,
                           p1_p2_file_item_t & io_data);

errlHndl_t p1_p2_file_read_data(p1_p2_file_item_t *io_items,
                                const uint16_t i_num_items);
#endif
/*-----------------------------------------------------------------------------*/
/* const values                                                                */
/*-----------------------------------------------------------------------------*/
const uint8_t P0_REGISTRY_PATH      = 0;
const uint8_t P1_REGISTRY_PATH      = 1;
const uint8_t P2_REGISTRY_PATH      = 2;
const uint8_t P3_REGISTRY_PATH      = 3;
const uint32_t TMGT_USLEEP_1mSEC        =   1000;
const uint32_t TMGT_USLEEP_10mSEC       =  10000;
const uint32_t TMGT_USLEEP_100mSEC      = 100000;

const uint16_t PCAP_ALL_NODES           = 0xFFFF;
const uint32_t TMGT_IF_WATCHDOG_TIMEOUT = 1200; // in seconds
const uint32_t TMGT_IF_MINIMUM_SINK_TIMEOUT = 0; // 0 = 1 microsecond

#define TRACE_ALL_TOIF_NODES    0xFF
#define TRACE_NO_TOIF_NODES     0xF0

#define UINT16_GET(__uint8_ptr)   ((uint16_t)((*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1)))
#define UINT32_GET(__uint8_ptr)   ((uint32_t)((uint32_t)(UINT16_GET(__uint8_ptr) << 16) | UINT16_GET((((const uint8_t *)(__uint8_ptr)) + 2))))

#define UINT16_PUT(dest, value) { ((uint8_t*)dest)[0]=((value)&0xFF00)>>8; ((uint8_t*)dest)[1]=((value)&0xFF); }
#define UINT32_PUT(dest, value) { ((uint8_t*)dest)[0]=((value)&0xFF000000)>>24; ((uint8_t*)dest)[1]=((value)&0xFF0000)>>16; ((uint8_t*)dest)[2]=((value)&0xFF00)>>8; ((uint8_t*)dest)[3]=((value)&0xFF); }

#define HEX(value,width)  std::uppercase << std::setfill('0') << std::setw(width) << std::hex << uint32_t(value)
#define DEC(value)        std::dec << uint32_t(value)

const uint16_t  TMGT_PROC_FOLDING_DATA_SIZE = 8;

const int32_t TMGT_SUCCESS = 0;
const int32_t TMGT_FAILURE = -1;

// Default for trace buffer size
const uint32_t TMGT_DEFAULT_BUFFER_SIZE = 0;


// File name used for daemon and client interface synchronization
const char TMGT_SINK_FILE[] = "tmgt.sync";

// File name for the thermal management daemon socket.  A period is
// used after "tmgt" rather than an underscore to ensure we
// don't get a collision with temporary generated names for the
// other sockets.
const char TMGT_DAEMON_IPC_FILE_NAME[] = "tmgt.daemon_";

// File name used for daemon and client interface synchronization
const char TMGT_ENERGY_SCALE_SINK_FILE_NAME[] = "tmgt_es.sync";

// File name for the thermal management daemon socket.  A period is
// used after "tmgt" rather than an underscore to ensure we
// don't get a collision with temporary generated names for the
// other sockets.
const char TMGT_ENERGY_SCALE_IPC_FILE_NAME[] = "tmgt.daemon_es_";

const char TOIF_SYNC_NAME[TMGT_MAX_NUMBER_OF_NODES][12] =
{
    { "toif0.sync" },
    { "toif1.sync" },
    { "toif2.sync" },
    { "toif3.sync" }
};

// Enumeration defining reasons TMGT is disabling WOF
enum disable_wof_rc
{
    WOF_MISSING_ULTRA_TURBO     = 0x0000,
    WOF_SYSTEM_DISABLED         = 0x0001,
    WOF_RESET_COUNT_REACHED     = 0x0002,
    WOF_UNSUPPORTED_FREQ        = 0x0003
};

/*-----------------------------------------------------------------------------*/
/* Registry defines - used by SVPD to default values based on system type      */
/*-----------------------------------------------------------------------------*/
const uint8_t TMGT_OTHER_SYSTEM         = 0x00;
const uint8_t TMGT_HV4_SYSTEM           = 0x01;
const uint8_t TMGT_HV8_SYSTEM           = 0x02;
const uint8_t TMGT_HV1_SYSTEM           = 0x03;
const uint8_t TMGT_IH_SYSTEM            = 0x04;
const uint8_t TMGT_H_SYSTEM             = 0x05;
const uint8_t TMGT_L4_SYSTEM            = 0x06;
const uint8_t TMGT_VOYAGEURS_SYSTEM     = 0x07;
const uint8_t TMGT_M2_SYSTEM            = 0x06;                 // $temp - Change when putting in TMGT support for M2
const uint8_t TMGT_P7_HV8_TTM_SYSTEM    = 0x08;
const uint8_t TMGT_P7_MR_SYSTEM         = 0x09;

const uint8_t TMGT_P7_HV16_SYSTEM       = 0x0C;
const uint8_t TMGT_P7_JUNO_SYSTEM       = 0x0D;
const uint8_t TMGT_P7_IH_SYSTEM         = 0x0E;

const uint8_t TMGT_P7_MR_FO_SYSTEM      = 0x10;
const uint8_t TMGT_P7_MR_FO_DU_SYSTEM   = 0x11;


const uint8_t TMGT_P7_ATHENA_SYSTEM     = 0x14;
const uint8_t TMGT_P7_HV16_IOC_SYSTEM   = 0x15;
const uint8_t TMGT_P7_JUNO_IOC_SYSTEM   = 0x16;
const uint8_t TMGT_THORAD_SYSTEM        = TMGT_P7_ATHENA_SYSTEM;


const uint8_t TMGT_HOLD_OCC_IN_RESET_AME_VALUE = 0xF0;
const uint8_t TMGT_IGNORE_SMGR_STATE_AME_VALUE = 0xE0;
const uint8_t TMGT_OTHER_AME_VALUE      = 0x00;
const uint8_t TMGT_HV4_AME_VALUE        = 0x01;

const uint8_t TMGT_HV8_AME_VALUE        = 0x03;
const uint8_t TMGT_VOYAGEURS_AME_VALUE  = 0x02;
const uint8_t TMGT_HV8_PLUS_AME_VALUE   = 0x04;
const uint8_t TMGT_P7_HV8_TTM_AME_VALUE = 0x05;
const uint8_t TMGT_P7_MR_AME_VALUE      = 0x06;

const uint8_t TMGT_P7_HE_AME_VALUE      = 0x08;
const uint8_t TMGT_P7_IH_AME_VALUE      = 0x09;
const uint8_t TMGT_P7_HV16_AME_VALUE    = 0x0A;
const uint8_t TMGT_P7_JUNO_AME_VALUE    = 0x0B;
const uint8_t TMGT_P7_MR_FO_AME_VALUE   = 0x0C;



const uint8_t TMGT_P7_ATHENA_AME_VALUE      = 0x11;
const uint8_t TMGT_P7_HV16_IOC_AME_VALUE    = 0x0F;
const uint8_t TMGT_P7_JUNO_IOC_AME_VALUE    = 0x10;
const uint8_t TMGT_THORAD_AME_VALUE     = TMGT_HOLD_OCC_IN_RESET_AME_VALUE;


/* Files - Note these have the full /opt/pX path in the define since they are files, not
 * registry entries.  In the case of tmgtP1Data, we're the only ones that know it even
 * exists since P1 does not require any code changes from fstp.
 */
#define TMGT_tmgtP1Data                 "/opt/p1/tmgt/tmgtP1Data"
#define TMGT_tmgtP2Data                 "/opt/p2/tmgt/tmgtP2Data"

#define TMGT_SIZE_OF_P1_AND_P2_FILES    512


struct pcap_data_t
{
    uint16_t pcap_cur;
    uint16_t pcap_max;
    uint16_t pcap_min;
    uint16_t pcap_over;
    uint16_t soft_pcap_min;
    uint16_t pcap_turbo;
    uint16_t dvfs_min_pcap;
};

// Flags to modify the tmgt client/server communication .
enum TmgtCommPolicyFlags
{
    TMGT_COMM_STANDARD                          = 0,
    TMGT_COMM_IGNORE_SINK_ERRORS                = 1,
};

struct string_data_t
{
    uint8_t       str_num;
    const char    *str_data;
};

tmgtEmpathFunction get_occ_status();

#ifndef _X86NFP
errlHndl_t get_sink_path(const char *i_sink_name, char *&o_sink_path);

errlHndl_t tmgtSyncServer(uint32_t i_daemonWait, const char *i_sink_name);

errlHndl_t tmgtTalkToServer(NetcMessage     & i_msg,
                            NetcMessage     * io_respMsg,
                            const char      * i_daemon_file_name,
                            const uint32_t    i_resp_timeout = TMGT_IF_WATCHDOG_TIMEOUT);

errlHndl_t forward_cmd(NetcMessage    & i_msg,
                       NetcMessage    * o_respMsg,
                       const uint32_t   i_resp_timeout,
                       const TmgtCommPolicyFlags i_commFlags,
                       const char*      i_sink_name,
                       const char*      i_daemon_file_name,
                       const uint32_t   i_sink_timeout = TMGT_IF_MINIMUM_SINK_TIMEOUT);

errlHndl_t forward_cmd_to_es_thread(tmgtMsgType i_msg,
                                    const void        * i_data_ptr,
                                    const uint16_t      i_data_length,
                                    NetcMessage       * o_respMsg,
                                    const uint32_t      i_resp_timeout = TMGT_IF_WATCHDOG_TIMEOUT,
                                    const TmgtCommPolicyFlags i_commFlags = TMGT_COMM_STANDARD,
                                    const uint32_t      i_sink_timeout = TMGT_IF_MINIMUM_SINK_TIMEOUT);

void detach_cmd_to_es_thread(NetcMessage * i_msg);

errlHndl_t forward_cmd_to_toif_thread(const uint8_t       i_node,
                                      const uint8_t       i_occ,
                                      const toifWorkItemTask    i_task,
                                      const void        * i_data_ptr,
                                      const uint16_t      i_data_length,
                                      NetcMessage       * o_respMsg,
                                      const uint32_t      i_resp_timeout = TMGT_IF_WATCHDOG_TIMEOUT,
                                      const TmgtCommPolicyFlags i_commFlags = TMGT_COMM_STANDARD,
                                      const uint32_t      i_sink_timeout = TMGT_IF_MINIMUM_SINK_TIMEOUT,
                                      const bool          i_blocking = TRUE);

errlHndl_t forward_cmd_to_tmgt_thread(NetcMessage&        i_msg,
                                      NetcMessage       * o_respMsg,
                                      const uint32_t      i_resp_timeout = TMGT_IF_WATCHDOG_TIMEOUT,
                                      const TmgtCommPolicyFlags i_commFlags = TMGT_COMM_STANDARD,
                                      const uint32_t      i_sink_timeout = TMGT_IF_MINIMUM_SINK_TIMEOUT);



errlHndl_t forward_cmd_to_server(tmgtMsgType i_msg, void *i_data_ptr, uint16_t i_data_length, NetcMessage & o_respMsg);

errlHndl_t read_mode_reg(const char *i_regname, tmgtSysPwrMode & o_mode);


uint8_t get_number_of_nodes();



void tmgtGetPcapValues(uint8_t    i_node,
                       uint16_t & o_pcap_cur,
                       uint16_t & o_pcap_max,
                       uint16_t & o_pcap_min,
                       uint16_t & o_pcap_over,
                       uint16_t & o_soft_pcap_min,
                       const bool i_ac = false);

TmgtApplet_var *getTmgtAppletOpRef(void);
#endif


enum tmgtSysTypeBits_t
{
    SYSTYPE_KVM         = 0x80,
    SYSTYPE_RESERVE6    = 0x40,
    SYSTYPE_RESERVE5    = 0x20,
    SYSTYPE_RESERVE4    = 0x10,
    SYSTYPE_RESERVE3    = 0x08,
    SYSTYPE_RESERVE2    = 0x04,
    SYSTYPE_SINGLE_NODE = 0x01
};

// NOTE: SINGLE_NODE / MULTI_NODE are all exclusive types
#define SYSTEM_IS_SINGLE_NODE (((G_system_type & SYSTYPE_SINGLE_NODE) == SYSTYPE_SINGLE_NODE))
#define SYSTEM_IS_MULTI_NODE ((! SYSTEM_IS_SINGLE_NODE))
#define SYSTEM_IS_KVM ((G_system_type & SYSTYPE_KVM) == SYSTYPE_KVM)
#define SYSTEM_IS_NOT_KVM (! SYSTEM_IS_KVM)
uint8_t get_system_type();
uint8_t get_max_nodes();

#define IS_VALID_OCC_STATE(occ_state)   ((OCC_STATE_ACTIVE == occ_state) || (OCC_STATE_OBSERVATION == occ_state) || (OCC_STATE_CHARACTERIZATION == occ_state))
#define STATE_IS_RESET(occ_state)       ((OCC_STATE_RESET == occ_state) || (OCC_STATE_UNKNOWN == occ_state))
#define STATE_IS_NOT_RESET(occ_state)   (! STATE_IS_RESET(occ_state))

// Internal utility function to convert the occ reset status to a string
const char *occ_reset_status_string(const occResetStatus i_state);

#ifndef _X86NFP
// Internal utility function to convert the mode change reason to a string
const char *mode_reason_string(const tmgtModeChangeReason i_reason);
#endif

// Internal utility function to convert the tpmf state to a string
const char *state_string(const occStateId i_reason);

// Internal utility function to convert the mode to a string
const char *mode_string(const tmgtSysPwrMode i_mode);

#ifndef _X86NFP
// Internal utility to convert OOC command type to a string
const char *command_string(occCommandType i_cmd);
#endif

/**
 * @brief Commit an error log entry.
 *
 * @pre None
 *
 * @post An error log entry is returned in i_errlHndl
 *
 * @param i_errlHndl - input/output parameter - The error log handle
 * @param i_tmgtModId - input parameter - The error log severity
 * @param i_tmgtReturnCode ut parameter - How to report the error log
 * @param i_srcData1 - input parameter - Goes in hexword field
 * @param i_srcData2 - input parameter - Goes in hexword field
 * @param i_srcData3 - input parameter - Goes in hexword field
 * @param i_srcData4 - input parameter - Goes in hexword field
 * @param i_errlSeverity - input parameter - (default is ERRL_SEV_PREDICTIVE)
 * @param i_skipTrace - Flag indicating if trace should be skipped (default is not to skip the trace)
 * @param i_node_num - which TOIF node to trace (default is ALL TOIF nodes)
 * @param i_comp_id - component ID for SRC (default is TMGT_COMP_ID)
 */
void tmgtBldErrLog(errlHndl_t &i_errlHndl,
                   tmgtModId i_tmgtModId,
                   tmgtReturnCodes i_tmgtReturnCode,
                   uint32_t i_srcData1 = 0,
                   uint32_t i_srcData2 = 0,
                   uint32_t i_srcData3 = 0,
                   uint32_t i_srcData4 = 0,
                   errlSeverity i_errlSeverity = ERRL_SEV_PREDICTIVE,
                   bool i_skipTrace = FALSE,
                   const uint8_t i_node_num = TRACE_ALL_TOIF_NODES,
                   const comp_id_t i_comp_id = TMGT_COMP_ID);


/**
 * @brief Commit an error log entry.
 *
 * @pre None
 *
 * @post An error log entry is committed, the entry is deleted, and the handle is set to NULL
 *
 * @param io_errlHndl - input/output parameter - The error log handle
 * @param i_sev       - input parameter - The error log severity
 * @param i_action    - input parameter - How to report the error log
 */
void tmgtCmtErrLog(errlHndl_t &io_errlHndl,
                   const errlSeverity i_sev = ERRL_SEV_PREDICTIVE,
                   const errlActions i_action = ERRL_ACTION_REPORT,
                   const comp_id_t i_comp_id = TMGT_COMP_ID);

/* Use the following if you don't want to change the severity */
void tmgtCmtErrLogWithNoSeverityChange(errlHndl_t &io_errlHndl,
                                       errlActions i_action = ERRL_ACTION_REPORT);

// Gets the PX rootpath where X is 0/1/2/3
uint8_t get_pX_root_path(const uint8_t ROOT_PATH, char *root_path_string);

// Spin off a new task for a function.  Function should return and accept a void *.
int create_thread(void *function, void *param = NULL, pthread_t * i_task = NULL);

// Hex dump to screen
void dump_hex(const void *data, uint32_t size, const char *header = NULL);

#ifndef _X86NFP
// CEC and FSP ipl type reads from smgr registry values
errlHndl_t readCecIplType(smgrIplTypeEnum &ipl_type);
errlHndl_t readFspIplType(smgrIplTypeEnum &ipl_type);
#endif

occStateId current_occ_state();


#ifndef _X86NFP
// Add a user details section to an error log containing information about a network message.
void tmgtAddUsrDtls_msg(errlHndl_t i_errl,
                        const NetcMessage& i_msg,
                        const tmgtThreadType i_thread,
                        const uint8_t i_node = 0);
#endif

bool find_memtable_from_comp_xlate_table(uint16_t & o_memTblIdx, uint8_t node );

/**
 * @brief Read 8 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[out] o_value        Value read from registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if read was successful
 *
 */
bool read_uint8_reg(const char *i_reg, uint8_t & o_value, const errlActions i_severity=ERRL_ACTION_REPORT);

/**
 * @brief Write 8 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[in]  i_value        Value to write to registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if write was successful
 *
 */
bool write_uint8_reg(const char *i_reg, const uint8_t & i_value, const errlActions i_severity=ERRL_ACTION_REPORT);

/**
 * @brief Read 16 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[out] o_value        Value read from registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if read was successful
 *
 */
bool read_uint16_reg(const char *i_reg, uint16_t & o_value, const errlActions i_severity=ERRL_ACTION_REPORT);

/**
 * @brief Write 16 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[in]  i_value        Value to write to registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if write was successful
 *
 */
bool write_uint16_reg(const char *i_reg, const uint16_t & i_value, const errlActions i_severity=ERRL_ACTION_REPORT);

/**
 * @brief Read 32 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[out] o_value        Value read from registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if read was successful
 *
 */
bool read_uint32_reg(const char *i_reg, uint32_t & o_value, const errlActions i_severity=ERRL_ACTION_REPORT);

/**
 * @brief Write 32 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[in]  i_value        Value to write to registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if write was successful
 *
 */
bool write_uint32_reg(const char *i_reg, const uint32_t & i_value, const errlActions i_severity=ERRL_ACTION_REPORT);



errlHndl_t tmgtDebugTrace(const uint32_t & i_data);


/** @brief Return the duration the system has been in the current mode,
 *        as well as the current mode.
 *
 * @param[out]         o_current_mode  Current power mode of the system.
 * @returns            duration of time (in seconds) that they system has been
 *                     running in the current mode, or 0 on error
 */
uint32_t tmgtQueryModeDuration(tmgtSysPwrMode & o_current_mode);

errlHndl_t tmgtRereadDefFile();

errlHndl_t tmgtInternalDebug(const uint8_t   i_data_length,
                             const uint8_t * i_data,
                             std::string   * o_result_string);

void tmgtPwrOnPresenceDetect();

errlHndl_t validate_ffo_freq(const uint16_t i_ffo_freq);

uint32_t remove_files_with_wildcard(std::string i_path, std::string i_pattern);

#ifndef _X86NFP
smgrStateEnum read_smgr_state();
#endif

void read_proc_options(tmgtProcDefParams_t & o_procOption);

void get_proc_def_params(tmgtProcDefParams_t & o_procParams);

#ifndef _X86NFP
uint8_t get_fan_control_fru_info( std::vector<tctConfigDataSet_t> &o_data);
#endif



#define AVP_FLAGS (FLAG_LOAD_REQUEST_DISABLED | FLAG_TERMINATE_ON_ERROR | FLAG_RESET_DISABLED)
#define AVP_ENABLED     (int_flags_set(AVP_FLAGS))
#define AVP_NOT_ENABLED (FALSE == int_flags_set(AVP_FLAGS))

// Return TRUE if the OS (PHYP/Sapphire) is ready for requests
bool os_ready_for_requests();

// Scan system config and set tmgt/internalFlags as required (AVP, Sapphire, etc...)
void update_internal_flags();

// Return TRUE if MNFG_POWER_SAVE_CAPABLE mfg policy flag is set
// This flag will force TMGT to use the min frequency when running in Static Power Save mode
bool mfg_use_min_for_ps();

// Return TRUE if KVM has been enabled through ASM
bool kvm_enabled();

// Call SVPD to determine the CCIN of one processor
bool read_proc_ccin(char * o_ccin);

// Add TMGT details to errorlog
const uint16_t TMGT_SUBSECTION_VERSION = 1;
void add_tmgt_elog_data(errlHndl_t i_err);
void add_occ_scom_data(errlHndl_t io_err, uint32_t i_huid);
void pci_lock();
void pci_unlock();

#endif // TMGTUTILITY_H
