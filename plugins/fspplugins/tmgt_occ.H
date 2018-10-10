// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgt_occ.H 1.77 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2012,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC:
// $Source: fips760 fsp/src/tmgt/fsp/tmgt_occ.H 1$


/**
 * @file tmgt_occ.H
 *
 * @brief This file contains the implementation of a daemon that processes
 *        thermal management requests.
 */

#ifndef TMGT_OCC_H_
#define TMGT_OCC_H_

// The following X86NFP check is required to prevent libE-2600.a compile failures under x86.nfp context
// Any code not required for this library/errl plugin should be ifdef'ed out in x86.nfp context
#if !defined(_X86NFP)
#include <hwsvTypes.H>
#include <tmgt.H>
#include <tmgtinternals.H>
#include <evenmgt.H>
#include <tmgt_occ_config.H>
#include <tmgt_occcmdlog.H>
#include <hwsvTmgtApplet.H>

#include <utilcond.H>

#define NON_WORKING_OCC   0xFFFFFFFF
#define TMGT_RESET_OCC_MAX_RETRIES   3
#define TMGT_WOF_RESET_MAX_RETRIES   3

#endif

extern uint8_t G_IPS_active;
extern bool IPS_error_logged;

const uint8_t OCC_STATUS_MASTER       = 0x80;
const uint8_t OCC_STATUS_CHANGE       = 0x10;
const uint8_t OCC_STATUS_ATTN_ENABLE  = 0x08;
const uint8_t OCC_STATUS_OBS_READY    = 0x02;
const uint8_t OCC_STATUS_ACTIVE_READY = 0x01;
// When new status bits are added, update tmgt_occcmdlog.C also
const uint8_t OCC_XSTATUS_SYNC_REQ    = 0x04;
const uint8_t OCC_XSTATUS_COOLING_REQ = 0x01;
const uint8_t OCC_XSTATUS_DVFS_PWR    = 0x40;
const uint8_t OCC_XSTATUS_DVFS_OT     = 0x80;

const uint8_t OCC_DVFS_BITMASK = (OCC_XSTATUS_DVFS_OT | OCC_XSTATUS_DVFS_PWR);


//NOTE: this index is stored per FRU type from interfaces spec "Temperature Sensors".
const uint32_t OCC_SECTION_NAME_TEMP = 0x54454D50;      //TEMP
//const uint32_t OCC_SECTION_NAME_FREQ = 0x46524551;    //FREQ
//const uint32_t OCC_SECTION_NAME_POWR = 0x504F5752;    //POWR
//const uint32_t OCC_SECTION_NAME_CAPS = 0x43415053;    //CAPS

const uint8_t PROCESSOR_FRUTYPE = 0x0;
const uint8_t CENTAUR_FRUTYPE   = 0x1;
const uint8_t DIMM_FRUTYPE      = 0x2;
const uint8_t VRM_FRUTYPE       = 0x3;
const uint8_t UNUSED1_FRUTYPE   = 0x4;
const uint8_t UNUSED2_FRUTYPE   = 0x5;
const uint8_t VRM_VDD_FRUTYPE   = 0x6;

const uint8_t BEGINNING_FRUTYPE      = PROCESSOR_FRUTYPE;
const uint8_t ENDING_FRUTYPE         = VRM_VDD_FRUTYPE;
const uint8_t TOTAL_FRU_SENSOR_TYPE_MAX = ENDING_FRUTYPE + 1;


enum toif_occRole
{
    TOIF_OCC_SLAVE = 0,
    TOIF_OCC_MASTER = 1,
    TOIF_OCC_BACKUP_MASTER = 2  // Only used by OCC Role Config Format
};

enum tmgtResetPrepReason
{
    NON_FAILURE = 0,
    FAILURE_DETECTED_ON_THIS_OCC                  = 0x01,
    FAILURE_DETECTED_ON_DIFF_OCC_WITHIN_SAME_NODE = 0x02,
    FAILURE_DETECTED_ON_DIFF_OCC_IN_DIFF_NODE     = 0x03,
    SYSTEM_POWER_OFF                              = 0xFF
};

struct occPollRspStruct_t
{
    uint8_t   status;
    uint8_t   extStatus;
    uint8_t   occsPresent;
    uint8_t   requestedCfg;
    uint8_t   state;
    uint8_t   mode;
    uint8_t   ipsStatus;
    uint8_t   errorId;
    uint32_t  errorAddress;
    uint16_t  errorLength;
    uint8_t   reserved[2];
    uint8_t   codeLevel[16];
    uint8_t   sensor[6];
    uint8_t   numberSensorBlocks;
    uint8_t   headerVersion;
    // Sensor Data Returned.
}  __attribute__((packed));


struct occSensorReading_t
{
    uint32_t     ID;
    uint8_t     FRUtype;
    uint8_t     Reading;
}  __attribute__((packed));

struct occPollRspTempSensorStruct_t
{
    occSensorReading_t  TempData[TOTAL_FRU_SENSOR_TYPE_MAX];
    occSensorReading_t  ErrorSensorData[TOTAL_FRU_SENSOR_TYPE_MAX];
}  __attribute__((packed));


const uint8_t TMGT_OCC_POLL_RSP_SIZE = sizeof(occPollRspStruct_t);
const uint16_t TMGT_OCC_POLL_SENSOR_RSP_SIZE = sizeof(occPollRspTempSensorStruct_t);

#if !defined(_X86NFP)
class ToifNode;

class Occ
{
    private:
        // Class variables (shared between all objects)
        static bool         cv_file_initialized;

        // Instance variables (unique to each object)
        bool                iv_needsReset;
        bool                iv_pollRequested;
        bool                iv_commEstablished;
        bool                iv_hasReachedCheckpoint;
        bool                iv_pollValid;
        bool                iv_skipFfdc;
        bool                iv_rspReady;
        bool                iv_masterCapable;
        bool                iv_failed;
        occStateId          iv_state;
        toif_occRole        iv_role;
        HWSV::HUID          iv_huid;
        uint8_t             iv_chipid;
        // Use util:Mutex to replace pthread_mutex_t
        util::Mutex         iv_rspLock;
        util::Mutex         iv_pollTimerLock;
        uint8_t             iv_instance;
        uint8_t             iv_seqNumber;
        uint8_t             iv_masterResetCount;
        uint8_t             iv_slaveResetCount;
        uint8_t             iv_wofResetCount;
        occ_cfg_data_format iv_requestedFormat;
        occPollRspStruct_t  iv_lastPollResponse;
        occPollRspTempSensorStruct_t iv_lastPollTempSensorResponse;
        ToifNode *          iv_toifNode;
        bool                iv_initialAttnReceived;
        uint32_t            iv_ips_enable_mismatch;
        uint32_t            iv_ips_active_invalid;
        uint8_t             iv_elog_retry_count;
        bool                iv_ignoreOvrSubErrorTraced;
        uint16_t            iv_lastCheckpoint;

        void elog_process_actions(const uint8_t i_actions,
                                  bool &o_occReset,
                                  errlSeverity &o_errlSeverity,
                                  errlActions &o_errlAction);

        void poll_rsp_ips_handler(const uint8_t i_IPS_poll_status);

        void assert_occ_error_events(uint32_t i_rc);
        void StoreOccSensorData( const uint8_t * i_poll_rsp);

    public:
        tracDesc_t          iv_toifTraceDesc;
        occConfigData       iv_configData;
        bool                iv_traceEnabled;
        occResetReason      iv_resetReason;

        Occ(ToifNode * i_toifNode,
            const TmgtApplet::OccResultRow i_occ);
        ~Occ();

        // Reset the tuning file init flag, so the next OCC will read new tuning parms from OCC
        static void resetTuningFileFlag() { cv_file_initialized = FALSE; }

        const occStateId getState() { return iv_state; };
        const HWSV::HUID getHuid() { return iv_huid; };
        const bool wasAttnReceived() { return iv_initialAttnReceived; };
        const bool isCommEstablished() { return iv_commEstablished; };
        const bool needsReset() { return iv_needsReset; };
        void clearNeedsReset() { iv_needsReset = FALSE; };
        uint8_t getWofResetCount() { return iv_wofResetCount; };
        const bool isMaster() { return (iv_role == TOIF_OCC_MASTER); };
        const bool isMasterCapable() { return iv_masterCapable; };
        const uint8_t getInstanceId() { return iv_instance; };
        const uint8_t getNextSeqNum() { return iv_seqNumber++; };
        const uint8_t getChipId() { return iv_chipid; };
        uint8_t getNode();
        ToifNode * getNodeInstance() { return iv_toifNode; }
        void trace(const OccLogType i_type, const uint8_t *i_buffer, const uint16_t i_length);

        void setState(const occStateId i_state);
        void setHuid(const HWSV::HUID i_homId);
        void poll(const bool i_flush_errors = FALSE);
        bool PollReturnOccSensorData(  occPollRspTempSensorStruct_t & o_rsp_data );
        occStateId attempt_poll();
        void collect_rsp_data();
        bool poll_rsp_handler(const uint8_t * i_poll_rsp, const bool i_check_for_timeout = FALSE);
        void pollForErrors(const bool i_flush_all_errors = FALSE);
        void pollRspCoolingRequest();
        void setAttnReceived();
        void setRspReady(const bool i_rspReady) { iv_rspReady = i_rspReady; };
        bool isSkipFfdc() { return iv_skipFfdc; };
        void setRole(const toif_occRole i_role = TOIF_OCC_SLAVE);
        void setFailedStatus(const bool i_failed) { iv_failed = i_failed; };
        bool isFailed() { return iv_failed; };
        bool cfgDataHandler();
        bool occ_poll_rsp_state_change(occStateId i_state);
        bool masterCapable();
        void clearResetCounts(const bool i_onlySlaves = FALSE);
        occResetStatus reset(const bool i_power_fault);
        void addResetData(errlHndl_t & l_err);
        void getResetData(UtilMem & o_buffer);
        void resetPrep(const occResetReason i_reason);
        bool isReadyForState(const occStateId i_state);
        bool verifyOccMode(const tmgtSysPwrMode i_desiredMode);

        void tunable_parm_handler( void );
        void process_tunable_parm_query_rsp(const uint8_t *i_rspData, const uint16_t i_rspLength);
        void write_tunable_parameters( void );
        void set_default_tunable_parameters( void );

        std::string dumpData();

        // Decrement the OCC poll timer and set expired if required
        void decrementPollTimer();

        // Disable the OCC and reset internal variables for next load request
        void disableOcc();

        // Check OCC FW level
        void occ_check_fw_level( const uint8_t* l_poll_fw_data );

        // Check OCC for CheckPoint
        bool wasCheckPointReceived(uint32_t & o_error);

        // Process elog info from poll response
        void occ_process_elog(const uint8_t i_id,
                              const uint32_t i_address,
                              const uint16_t i_length,
                              const bool i_flushingLogs = FALSE,
                              const bool i_check_for_timeout = FALSE);

        void setNeedsReset(void) { iv_needsReset = TRUE; };
        void setResetReason(const occResetReason i_reason) { iv_resetReason = i_reason; };
        occResetReason getResetReason() { return iv_resetReason; };
        void postLoadSetup();

        bool quick_pwr_drop_errors_check();

        // Add OCC traces to specified elog (ERR, IMP, INF)
        void addOccTrace(errlHndl_t & i_err);

        errlHndl_t SetUserPcap( const uint16_t i_Pcap );
};

void init_dps_default_from_def_file( void );

#endif

#endif /* TMGT_OCC_H_ */
