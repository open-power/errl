/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* fips911 src/tmgt/fsp/tmgt_pcap_tables.H 1.22                           */
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


/**********************************************************************************************************************************/
/*                                                                                                                                */
/*  CHANGE ACTIVITY:                                                                                                              */
/*                                                                                                                                */
/*  Flag  Track   Release     Date     Userid    Comments                                                                         */
/*  ----- ------  ----------- -------- --------- -------------------------------------------------------------------------------- */
/*                                                                                                                                */
/*  END CHANGE ACTIVITY                                                                                                           */
/**********************************************************************************************************************************/

#ifndef _TMGT_POWERCAP_WATTS_H
#define _TMGT_POWERCAP_WATTS_H

#include <tmgt_pcap.H>


enum tmgt_dimmTypes
{
    TMGT_ISDIMM = 0,
    TMGT_SNDIMM = 1,
    TMGT_DWSNDIMM = 2,
    TMGT_MAX_DIMM_TYPE = 3
};

//Defines for dd/ec level.
enum tmgt_eclevel
{
    TMGT_EC_LEVEL_DD10 = 0x10,
    TMGT_EC_LEVEL_DD20 = 0x20,
};

#define TMGT_MEMCFG_TYPES 2   //Count of all possible tmgtMemConfig types below.
enum tmgtMemConfig
{
    memCfg_full     = 0x00,
    memCfg_partial  = 0x01,

    memCfg_all      = 0xFF, //This entry shold not be included in TMGT_MEMCFG_TYPES count.
};

struct tmgt_thermalData_t
{
    double              thermal;
    float               slope;
    float               intercept;
};

struct tmgt_thermal_power_data_t
{
    uint8_t             sysType;
    uint8_t             dimmSize;
    tmgt_thermalData_t  data[TMGT_MEMCFG_TYPES];
};




struct  tmgt_node_struct
{
    uint16_t numNodes;
    uint8_t node[TMGT_MAX_NUMBER_OF_NODES];
};


// Structure used to store power cap values for FFDC (per node)
struct tmgt_pcap_summary_t
{
  // Common
  uint16_t  countProc; // # processors
  uint16_t  totalProcPwr;
  uint16_t  totalTurboProcPwr;
  uint16_t  totalMinProcPwr;
  uint16_t  maxPwrPerNode;
  uint16_t  totalFixed;
  uint16_t  totalPCI;
  uint16_t  nominalMemPwr;
  uint16_t  turboMemPwr;
  uint16_t  powercapMemPwr;
//  uint16_t  countDIMM; // # DIMMS
//  uint16_t  totalDIMM;

  // Totals
  bool turboPcapSupport;
  uint16_t  pcapCurrent;
  uint16_t  pcapSoftMin;
  uint16_t  pcapMin;
  uint16_t  pcapMax;
  uint16_t  pcapOversub;
  uint16_t  pcapTurbo;
  uint16_t  pcapDvfsMin;
};

#ifndef _X86NFP
extern tmgt_pcap_summary_t G_pcapSummary[TMGT_MAX_NUMBER_OF_NODES];



void calc_and_update_pcaps(tmgt_node_struct *i_node_list);

double return_thermal_power_data (const uint8_t i_sysType,
                                  const tmgtMemConfig i_memCfg,
                                  const uint8_t i_dimmSize,
                                  tmgt_thermalData_t *o_thermalData = NULL);

uint8_t update_memory_throttle(const uint8_t i_percentage);

void remove_throttle_data(const uint8_t i_node);

errlHndl_t set_num_io_drawers(NetcMessage & i_msg);
errlHndl_t set_num_io_drawers_source(uint8_t i_num_io, uint8_t i_source);
#endif

#endif
