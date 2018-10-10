/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* fips911 src/tmgt/fsp/tmgt_pcap.H 1.9.1.18                              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* OBJECT CODE ONLY SOURCE MATERIALS                                      */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2017              */
/* All Rights Reserved                                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/*  LAST_VERSION_FROM_CC: */
/* $Source: fips740 fsp/src/tmgt/fsp/tmgt_pcap.H 4$ */

#ifndef TMGT_PCAP_H
#define TMGT_PCAP_H
 /**
 *  @file tmgt_pcap.H
 *
 *  @brief This file contains the definition of constants, macros, etc. that
 *         are internal to the TMGT component to manage the power caps
 *
 */

#ifndef _X86NFP
#include <tmgt_pexcmd.H>
#endif
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
/* Constants                                                                   */
/*-----------------------------------------------------------------------------*/
extern bool run_pcap_handler;
#ifndef _X86NFP
extern util::Mutex G_pcap_lock;
#endif
const float DEFAULT_PWR_SPLY_EFFICIENCY = 0.85;
extern bool G_mem_no_turbo;

/*-----------------------------------------------------------------------------*/
/* Type definitions                                                            */
/*-----------------------------------------------------------------------------*/
enum tmgtPcapActions
{
  TMGT_PCAP_CALCULATE                = 0x00,
  TMGT_PCAP_DISTRIBUTE               = 0x01,
  TMGT_PCAP_SEND_TO_TPMD             = 0x02,

  TMGT_PCAP_ACTION_SIZE
};

extern uint16_t G_pcap_actions[TMGT_PCAP_ACTION_SIZE];

#ifndef _X86NFP
/*-----------------------------------------------------------------------------*/
/* Functions                                                                   */
/*-----------------------------------------------------------------------------*/
void pcap_handler();
bool pcap_validate(uint16_t     & io_pcap_cur,
                   const uint16_t i_pcap_max,
                   uint16_t     & io_soft_pcap_min,
                   const uint8_t  i_node);
void tmgt_recalculate_pcap(const uint16_t i_node);

void tmgt_get_pcap_values(NetcMessage & i_msg);

errlHndl_t set_power_cap(uint16_t i_pcap, bool i_writeOnly = FALSE);

errlHndl_t pcap(pex_command_t & io_pex_cmd);
#endif

#endif // TMGT_PCAP_H
