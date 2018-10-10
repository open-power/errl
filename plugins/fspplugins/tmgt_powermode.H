/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* fips911 src/tmgt/fsp/tmgt_powermode.H 1.37.2.18                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* OBJECT CODE ONLY SOURCE MATERIALS                                      */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2007,2017              */
/* All Rights Reserved                                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/*  LAST_VERSION_FROM_CC: */
/* $Source: fips740 fsp/src/tmgt/fsp/tmgt_powermode.H 1$ */

#ifndef TMGT_POWERMODE_H
#define TMGT_POWERMODE_H


/**********************************************************************************************************************************/
/*                                                                                                                                */
/*  CHANGE ACTIVITY:                                                                                                              */
/*                                                                                                                                */
/*  Flag  Track   Release     Date     Userid    Comments                                                                         */
/*  ----- ------  ----------- -------- --------- -------------------------------------------------------------------------------- */
/*                                                                                                                                */
/*  END CHANGE ACTIVITY                                                                                                           */
/**********************************************************************************************************************************/



/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <tmgtinternals.H>

/*-----------------------------------------------------------------------------*/
/* Enums                                                                       */
/*-----------------------------------------------------------------------------*/
enum tmgtCappingMethod
{
  TMGT_CAP_METHOD_THROTTLING                    = 0x00,
  TMGT_CAP_METHOD_DVFS                          = 0x01
};

enum tmgtFreqChangeStatus
{
  FREQ_CHANGE_SUCCESS           = 0,
  FREQ_CHANGE_FAIL              = 1,
  FREQ_CHANGE_FAIL_NOT_RUNTIME  = 2,
  FREQ_CHANGE_TPMD_FAILURE      = 3
};

enum tmgtModeChangeStatus
{
    MODE_CHANGE_SUCCESS     = 0,
    MODE_CHANGE_TIMEOUT     = 1,
    MODE_CHANGE_OCC_FAILURE = 2,
    MODE_CHANGE_NOT_SENT    = 3,
    MODE_CHANGE_FAIL        = 4
};

enum tmgtModeChangeReason
{
    TMGT_MODE_REASON_UNKNOWN      = 0x00,
    TMGT_MODE_REASON_NORMAL       = 0x01,
    TMGT_MODE_REASON_PWR_ON       = 0x02,
    TMGT_MODE_REASON_RE_IPL       = 0x03,
    TMGT_MODE_REASON_OCC_FAILURE  = 0x04,
    TMGT_MODE_REASON_SAFE_MODE    = 0x06,
    TMGT_MODE_REASON_POWER_FAULT  = 0x07,
    TMGT_MODE_REASON_FSP_FAILURE  = 0x08,
    // As new reasons are added, remember to update mode_reason_string() in tmgtutilty.C
};

enum tmgtModeChangeAction
{
    TMGT_MODE_ACTION_ENTER = 0x00,
    TMGT_MODE_ACTION_EXIT  = 0x01,
};


#ifndef _X86NFP
/*-----------------------------------------------------------------------------*/
/* Functions                                                                   */
/*-----------------------------------------------------------------------------*/
void determine_mode_change_support(tmgtSysPwrMode i_requested_mode, bool & o_change_supported);
void mode_change_handler(tmgtModeChangeReason i_reason);
void read_cust_modes(tmgtSysPwrMode & o_custMode, tmgtSysPwrMode & o_currentCustMode);
void determine_power_limit_attribute(tmgtSysPwrMode i_cust_mode);
void determine_power_limit_attribute(tmgtSysPwrMode i_cust_mode, bool &o_attributeFailure, bool &o_resetNeeded);

void safe_mode_complete(const bool i_clear_reset_count = FALSE);

bool frequency_lookup();
errlHndl_t get_proc_folding_data(uint8_t *o_data_buffer, uint16_t & io_data_length);
void send_proc_folding_data();
tmgtFreqChangeStatus fsp_mode_change(tmgtSysPwrMode & io_new_mode, bool i_ctrm_error, tmgtModeChangeReason i_reason);
tmgtFreqChangeStatus fsp_mode_change2(tmgtSysPwrMode & io_new_mode, bool i_ctrm_error, tmgtModeChangeReason i_reason);

errlHndl_t power_capping_enabled(bool & o_enabled, bool & o_soft_pcap);

/**
   * @brief Query number of seconds the system has been in the current mode
   *
   * @param[out] o_msg - Data will be stored in this NETC message object
   *
   * @return none
   **/
void tmgt_query_mode_duration(NetcMessage & o_msg);

errlHndl_t power_event(NetcMessage & l_msg);

errlHndl_t set_cust_requested_mode(NetcMessage & i_msg);
void set_cust_requested_mode(uint16_t l_ffo_freq, tmgtSysPwrMode l_cust_mode);
void create_safe_mode_log();

#endif
/*-----------------------------------------------------------------------------*/
/* Global variables                                                            */
/*-----------------------------------------------------------------------------*/
extern Flag mode_change_required;
extern Flag mode_changes_enabled;
extern Flag frequency_look_up_required;
extern tmgtSysPwrMode G_saved_old_cust_mode;

#endif
