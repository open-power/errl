// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips860 src/fstp/fsp/fips_comp_id.H 1.12.19.58 
//  
// Licensed Materials - Property of IBM 
//  
// Restricted Materials of IBM 
//  
// COPYRIGHT International Business Machines Corp. 2002,2015 
// All Rights Reserved 
//  
// US Government Users Restricted Rights - Use, duplication or 
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC:
// $Source: fips760 fsp/src/fstp/fsp/fips_comp_id.H 1$

// $Id: @(#)04       1.12.19.25  src/fstp/fsp/fips_comp_id.H, esw_fstp, fips710 2/16/09 04:27:54
//

#ifndef FIPS_COMP_ID_H
#define FIPS_COMP_ID_H

/** @file fips_comp_id.H
 *
 * @brief This file contains the component identifier definitions for
 * FipS applications.
 */

// Change Log*****************************************************************/
//
// ch#  Feat/def#      Userid   Date     Description
// ---- -------------- -------- -------- -------------------------------------
// n/a  FT xxx         movall   01/03/02 Created
// n/a  FT 357545      langford 01/17/02 fix typo and change strings to arrays
// n/a  FT 357545      wfenlon  01/31/02 Add ccws and cpci IDs
// n/a  FT 369530      v2aicsc  06/05/02 Add ctrm ID
// n/a  F379041        swerbner 08/13/02 Add new dada constants
// n/a  ft1206         whinery  08/14/02 Added sink ID
// n/a  ft1186.1       whinery  08/14/02 Added hysr ID
// n/a  d881397        anirbanc 08/29/02 Renamed HSCX comp id to HMCX
// n/a  ft1201.1       boecker  09/16/02 Add VLOC and VLED
// n/a  f386012        swerbner 10/08/02 Eliminate DIAL_COMP_* constants
// n/a  f385406        nmiller  10/08/02 Add IRPC and REMP.
// n/a  D387266        vmena    10/15/02 Add UTIL
// n/a  D388570        whinery  12/16/02 Added plck ID
// n/a  f391587        anirbanc 01/06/03 Added snop ID
// n/a  f393304        langford 01/24/03 Added surv ID
//      d397123        anirbanc 02/14/03 Added powr ID
//      d398544        anirbanc 03/12/03 Added rsrl ID
//      f398265        mkalmba  03/21/03 Added scod ID
//      f400322        v2aicuk  03/27/03 Added vpnl ID
//      f400649        anirbanc 03/31/03 Made fips and fips1 files common
//      d401563        anirbanc 04/08/03 Added mnfg ID
//      d401778        anirbanc 04/14/03 Added dscv ID
//      f398465        nmiller  04/28/03 Added apor ID
//      d404123        anirbanc 05/05/03 Added rmgr ID
//      d404937        anirbanc 05/13/03 Added bdmp ID
//      d405660        anirbanc 05/20/03 Added fstp ID
//      d408447        anirbanc 06/27/03 Added rbot ID
//      d410181        anirbanc 07/17/03 Added sync ID
//      d415723        anirbanc 09/12/03 Added hvsi ID
//      d416685        vmena    09/13/03 corrected above hvsi compname build break
//      d472043        anirbanc 08/27/04 Added test ID
//      d481508        anirbanc 11/01/04 Added hclk ID
//      f484364        anirbanc 11/19/04 Added ecmd ID
//      f486410        anirbanc 01/14/05 Added ccmm ID
//      d490657        anirbanc 01/28/05 Added tmgt ID
//      f501998        thi      04/28/05 Added hcsi ID
// n/a  f505241        whinery  05/23/05 Changed ids for reason code ranges
//      d524589        mdickens 10/20/05 Added upsi ID
// n/a  f526809        whinery  11/02/05 Moved upsi to new value
//      f535890        sbroyles 01/24/06 Added frum
//      F537905        vmena    03/03/06 Added rdal
//      d549949        britson  05/02/06 Added oscc
//      F561934        alejrodr 07/19/06 Added cimp
//      F553642        vniranja 08/21/06 Added perf
//      F567173        jbreese  08/24/06 Added ffdc and vadj
//	D567614	       mdickens 08/28/06 Add HLTH comp ID
//      F576166        nmiller  11/13/06 Added bpnl ID
//	F592166	       mdickens 05/14/07 Moved FSTP component to a 4300
//      F649005        boecker  02/26/08 Added ibus ID
//      d658293        cjcain   04/15/08 Replaced upsi w/tlks
//      d695875        gururaja 16/02/08 Added HCDB
//      F721324        minamdar 9/11/08  Added TPMD
//      F731997        besawn   11/20/09 Added lnmc ID
//      F746966        nnithin  03/22/10 Support for new component "Wrap"
//      F754820        nmiller  06/01/10 Added pres
//      d769318        britson  08/29/10 Added osce, dcce
//      SW108171       muqahmed 10/30/11 Added hardware Server support
//      820896         eggler   01/25/12 move fwd changes from 740/760
//      820858         v2cib530 02/07/12 Add dpdl component ID
//      826234         chintans 03/01/12 Add fmbx component ID
//      828364         rajadas2 03/23/12 Add Targeting Dump Service Comp Id
//      831322         muqahmed 04/13/12 Add HWPF Comp Id
//      831072         bofferdn 04/09/12 Add TARG component
//      831072         bofferdn 04/09/12 Made TARG ID 16 bitst
//      839791         brianh   06/19/12 Add HWAS; move dups
//      SW156210       boecker  08/02/12 Add FDAL
//      858097         rickylie 10/19/12 Convert GPIO functions to FDAL interfaces (Delete tpmd from 810)
//      F855990        nguyenp  10/20/12 Add Hostboot comp id
//      F862604        gauravb  11/29/12 Comps SBCU and PPIN removed.
//      F857917        gauravb  11/29/12 Changing RPON to TPON - Timed Power on. RPON comp removed.
//      F865431        aravnair 01/15/13 Add HWCO
//      F878551        kansal   04/29/13 Add ERPR
//      F879772        dpeterso 04/24/13 Add CORR
//      F883511        gkeishin 05/17/13 Remove NMGR usage
//      SW210369       jthomas7 06/20/13 Add CBLV
//      F894032        ailutsar 08/16/13 Remove #V and proc vrm update support
//      899880         mgloff   09/18/13 Add epcf component ID
//      900549         alvinwan 09/30/13 Add thrm component ID
//      927046         sadevale 06/25/14 Add hwhs component ID
//      965231         nayna    06/20/15 Add psec component ID
// End Change Log*************************************************************/

typedef unsigned short  comp_id_t;

/*---------------------------------------------------------------------------*/
/* Constants                                                                 */
/*---------------------------------------------------------------------------*/

    /** @brief NOTE:
     *  All component reason code ranges will be in the range of its component
     *  id. Due to this, all component id values must have the last byte as 00.
     *  For example: If XXXX_COMP_ID = 0xFE00, then component XXXX has a
     *  reason code range of 0xFE01 - 0xFEFF.  This way, reason code ranges will
     *  not have to be assigned for a component.
     */

//----------------------------------------------------------------------
// EDAL  ---------------------------------------------------------------
//----------------------------------------------------------------------

/** @name DMAE
 *  Direct Memory Access (DMA) End Device DAL
 */
//@{
const comp_id_t DMAE_COMP_ID     = 0x1000;
const char      DMAE_COMP_NAME[] = "dmae";
//@}

/** @name IPNL
 *  I2C Op Panel End Device DAL
 */
//@{
const comp_id_t IPNL_COMP_ID     = 0x1100;
const char      IPNL_COMP_NAME[] = "ipnl";
//@}

/** @name IVPD
 *  I2C VPD End Device DAL
 */
//@{
const comp_id_t IVPD_COMP_ID     = 0x1300;
const char      IVPD_COMP_NAME[] = "ivpd";
//@}

/** @name IRPT
 *  RPC End/Connection Device DAL
 */
//@{
const comp_id_t IRPC_COMP_ID     = 0x1400;
const char      IRPC_COMP_NAME[] = "irpc";
//@}

/** @name SCED
 *  Smart Chip VPD End Device DAL
 */
//@{
const comp_id_t SCED_COMP_ID     = 0x1500;
const char      SCED_COMP_NAME[] = "sced";
//@}

//----------------------------------------------------------------------
// POWER  --------------------------------------------------------------
//----------------------------------------------------------------------

/** @name SPIF
 *  System Power Interface
 */
//@{
const comp_id_t SPIF_COMP_ID     = 0x2000;
const char      SPIF_COMP_NAME[] = "spif";
//@}

/** @name REMP
 *  RPC Application
 */
//@{
const comp_id_t REMP_COMP_ID     = 0x2100;
const char      REMP_COMP_NAME[] = "remp";
//@}

/** @name PLCK
 *  IPL Lock
 */
//@{
const comp_id_t PLCK_COMP_ID     = 0x2200;
const char      PLCK_COMP_NAME[] = "plck";
//@}

/** @name APOR
 *  Auto Power Restart Interface
 */
//@{
const comp_id_t APOR_COMP_ID     = 0x2300;
const char      APOR_COMP_NAME[] = "apor";
//@}

/** @name TPON
 *  Timed Power On
 */
//@{
const comp_id_t TPON_COMP_ID     = 0x2400;
const char      TPON_COMP_NAME[] = "tpon";
//@}

/** @name BPAA
 *  Bulk Power Assembly - no reason codes currently
 */
//@{
const comp_id_t BPAA_COMP_ID     = 0x2500;
const char      BPAA_COMP_NAME[] = "bpaa";
//@}

/** @name TMGT
 *  Thermal Management
 */
//@{
const comp_id_t TMGT_COMP_ID     = 0x2600;
const char      TMGT_COMP_NAME[] = "tmgt";
//@}

/** @name POWR
 *  Power (SPCN) - no reason codes currently
 */
//@{
const comp_id_t POWR_COMP_ID     = 0x2700;
const char      POWR_COMP_NAME[] = "powr";
//@}

/** @name TLKS
 *  TMGT I2C Bus Lock Server
 */
//@{
const comp_id_t TLKS_COMP_ID     = 0x2800;
const char      TLKS_COMP_NAME[] = "tlks";
//@}

/** @name OCCC
 *  Thermal Power Management
 */
//@{
const comp_id_t OCCC_COMP_ID     = 0x2A00;
const char      OCCC_COMP_NAME[] = "occc";
//@}

/** @name DPDL
 * Digital Power Systems Sweep chip Download
 */
//@{
const comp_id_t DPDL_COMP_ID     = 0x2B00;
const char      DPDL_COMP_NAME[] = "dpdl";
//@}

/** @name EPCF
 * Embedded Power Control Firmware
 */
//@{
const comp_id_t EPCF_COMP_ID     = 0x2C00;
const char      EPCF_COMP_NAME[] = "epcf";
//@}

/** @name THRM
 * Temperature Monitoring
 */
//@{
const comp_id_t THRM_COMP_ID     = 0x2D00;
const char      THRM_COMP_NAME[] = "thrm";
//@}

//----------------------------------------------------------------------
// INFRASTRUCTURE  -----------------------------------------------------
//----------------------------------------------------------------------

/** @name CUPD
 *  Code Update
 */
//@{
const comp_id_t CUPD_COMP_ID     = 0x3000;
const char      CUPD_COMP_NAME[] = "cupd";
//@}

/** @name ERRL
 *  Error Logging
 */
//@{
const comp_id_t ERRL_COMP_ID     = 0x3100;
const char      ERRL_COMP_NAME[] = "errl";
//@}

/** @name IPLP
 *  IPL Parameters
 */
//@{
const comp_id_t IPLP_COMP_ID     = 0x3200;
const char      IPLP_COMP_NAME[] = "iplp";
//@}

/** @name RTIM
 *  RTC Applications
 */
//@{
const comp_id_t RTIM_COMP_ID     = 0x3300;
const char      RTIM_COMP_NAME[] = "rtim";
//@}

/** @name SMGR
 *  State Manager
 */
//@{
const comp_id_t SMGR_COMP_ID     = 0x3400;
const char      SMGR_COMP_NAME[] = "smgr";
//@}

/** @name DSCV
 *  Discovery
 */
//@{
const comp_id_t DSCV_COMP_ID     = 0x3500;
const char      DSCV_COMP_NAME[] = "dscv";
//@}

/** @name BOOT
 *  Boot Plugin
 */
//@{
const comp_id_t BOOT_COMP_ID     = 0x3700;
const char      BOOT_COMP_NAME[] = "boot";
//@}

/** @name FRUM
 *  FRU Manager
 */
//@{
const comp_id_t FRUM_COMP_ID     = 0x3800;
const char      FRUM_COMP_NAME[] = "frum";
//@}

/** @name RDAL
 *  Remote device layer
 */
//@{
const comp_id_t RDAL_COMP_ID     = 0x4100;
const char      RDAL_COMP_NAME[] = "rdal";
//@}


/** @name FFDC                             
 *  First Failure Data Capture utilities - TODO: Depricate/Replaced by FDAL
 */
//@{
const comp_id_t FFDC_COMP_ID     = 0x4200;
const char      FFDC_COMP_NAME[] = "ffdc";
//@}

/** @name FSTP
 *  FSP Setup
 */
//@{
const comp_id_t FSTP_COMP_ID     = 0x4300;
const char      FSTP_COMP_NAME[] = "fstp";
//@}

/** @name BFMK
 *  Base Framework
 */
//@{
const comp_id_t BFMK_COMP_ID     = 0x4400;
const char      BFMK_COMP_NAME[] = "bfmk";
//@}

/** @name IBUS
 *  IIC Bus Interfaces
 */
//@{
const comp_id_t IBUS_COMP_ID     = 0x4500;
const char      IBUS_COMP_NAME[] = "ibus";
//@}

/** @name FORB
 *  FSP CORBA (ORB) Framework
 */
//@{
const comp_id_t FORB_COMP_ID     = 0x4600;
const char      FORB_COMP_NAME[] = "forb";
//@}


/** @name FORB
 *  FSP CORBA (ORB) Framework
 */
//@{
const comp_id_t PRES_COMP_ID     = 0x4700;
const char      PRES_COMP_NAME[] = "pres";
//@}


/** @name FDAL
 *  FSP Device Abstraction Layer utilities
 */
//@{
const comp_id_t FDAL_COMP_ID     = 0x4800;
const char      FDAL_COMP_NAME[] = "fdal";
//@}

/** @name CBLV
 *  Cable Verification framework
 */
//@{
const comp_id_t CBLV_COMP_ID     = 0x4900;
const char      CBLV_COMP_NAME[] = "cblv";
//@}

//----------------------------------------------------------------------
// HWServer   ----------------------------------------------------------
//----------------------------------------------------------------------
 
/** @name HWAS
 *  HWAS code
 */
//@{
const comp_id_t HWAS_COMP_ID     = 0x5000;
const char      HWAS_COMP_NAME[] = "hwas";
//@}

/** @name HWPF
 *  HW Procedure Framework component
 */
//@{
const comp_id_t HWPF_COMP_ID = 0x5100;
const char HWPF_COMP_NAME[] = "hwpf";
//@}

/** @name TARG
 *  Targeting code
 */
//@{
const comp_id_t TARG_COMP_ID     = 0x5200;
const char      TARG_COMP_NAME[] = "targ";
//@}


//----------------------------------------------------------------------
// UTILITIES  ----------------------------------------------------------
//----------------------------------------------------------------------

/** @name SRCI
 *  SRC Interface
 */
//@{
const comp_id_t SRCI_COMP_ID     = 0x8200;
const char      SRCI_COMP_NAME[] = "srci";
//@}

/** @name CTRM
 *  CEC Termination Library
 */
//@{
const comp_id_t CTRM_COMP_ID     = 0x8300;
const char      CTRM_COMP_NAME[] = "ctrm";
//@}

/** @name NETS
 *  Network Message Server
 */
//@{
const comp_id_t NETS_COMP_ID     = 0x8400;
const char      NETS_COMP_NAME[] = "nets";
//@}

/** @name EVEN
 *  Event Notification
 */
//@{
const comp_id_t EVEN_COMP_ID     = 0x8500;
const char      EVEN_COMP_NAME[] = "even";
//@}

/** @name PERC
 *  Process Error Context
 */
//@{
const comp_id_t PERC_COMP_ID     = 0x8600;
const char      PERC_COMP_NAME[] = "perc";
//@}

/** @name NETC
 *  Network Client Library
 */
//@{
const comp_id_t NETC_COMP_ID     = 0x8700;
const char      NETC_COMP_NAME[] = "netc";
//@}

/** @name HYSR
 *  Hypervisor Service Routine
 */
//@{
const comp_id_t HYSR_COMP_ID     = 0x8800;
const char      HYSR_COMP_NAME[] = "hysr";
//@}

/** @name SINK
 *  Process Synchronization
 */
//@{
const comp_id_t SINK_COMP_ID     = 0x8900;
const char      SINK_COMP_NAME[] = "sink";
//@}

/** @name UTIL
 *  FipS Utility Library
 */
//@{
const comp_id_t UTIL_COMP_ID     = 0x8A00;
const char      UTIL_COMP_NAME[] = "util";
//@}


/** @name NCFG
 *  FipS Network Configuration
 */
//@{
const comp_id_t NCFG_COMP_ID     = 0x8B00;
const char      NCFG_COMP_NAME[] = "ncfg";
//@}


/** @name NETV
 *  FipS Network Validation
 */
//@{
const comp_id_t NETV_COMP_ID     = 0x8C00;
const char      NETV_COMP_NAME[] = "netv";
//@}


/** @name HCDB
 *  FipS Hardware Control Database
 */
//@{
const comp_id_t HCDB_COMP_ID     = 0x8D00;
const char      HCDB_COMP_NAME[] = "hcdb";
//@}


/** @name LNMC
 *  Local Network Management Controller
 */
//@{
const comp_id_t LNMC_COMP_ID     = 0x8E00;
const char      LNMC_COMP_NAME[] = "lnmc";
//@}

/** @name PSEC
 *  Power Security Interfaces
 */
//@{
const comp_id_t PSEC_COMP_ID     = 0x8F00;
const char      PSEC_COMP_NAME[] = "psec";
//@}

//----------------------------------------------------------------------
// EXTERNAL INTERFACES  ------------------------------------------------
//----------------------------------------------------------------------

/** @name HDAT
 *  Hypervisor Data Initialization
 */
//@{
const comp_id_t HDAT_COMP_ID     = 0x9000;
const char      HDAT_COMP_NAME[] = "hdat";
//@}

/** @name HVSI
 *  Host Virtual Serial Interface
 */
//@{
const comp_id_t HVSI_COMP_ID     = 0x9200;
const char      HVSI_COMP_NAME[] = "hvsi";
//@}

/** @name MBOX
 *  Mailbox Handling
 */
//@{
const comp_id_t MBOX_COMP_ID     = 0x9500;
const char      MBOX_COMP_NAME[] = "mbox";
//@}

/** @name SCOD
 *  SP Capacity Upgrade on Demand
 */
//@{
const comp_id_t SCOD_COMP_ID     = 0x9900;
const char      SCOD_COMP_NAME[] = "scod";
//@}

/** @name PANL
 *  Op Panel Display
 */
//@{
const comp_id_t PANL_COMP_ID     = 0xA000;
const char      PANL_COMP_NAME[] = "panl";
//@}

/** @name VPNL
 *  Virtual Panel
 */
//@{
const comp_id_t VPNL_COMP_ID     = 0xA200;
const char      VPNL_COMP_NAME[] = "vpnl";
//@}

/** @name SVPD
 *  System VPD
 */
//@{
const comp_id_t SVPD_COMP_ID     = 0xA400;
const char      SVPD_COMP_NAME[] = "svpd";
//@}

/** @name VLOC
 *  VPD - Location Code
 */
//@{
const comp_id_t VLOC_COMP_ID     = 0xA600;
const char      VLOC_COMP_NAME[] = "vloc";
//@}

/** @name VLED
 *  VPD - LED Access
 */
//@{
const comp_id_t VLED_COMP_ID     = 0xA700;
const char      VLED_COMP_NAME[] = "vled";
//@}

/** @name FWDB
 *  Firmware Database Access
 */
//@{
const comp_id_t FWDB_COMP_ID     = 0xA800;
const char      FWDB_COMP_NAME[] = "fwdb";
//@}

/** @name MENU
 *  SP Menus
 */
//@{
const comp_id_t MENU_COMP_ID     = 0xD000;
const char      MENU_COMP_NAME[] = "menu";
//@}

/** @name ATTN
 *  Attention Handling
 */
//@{
const comp_id_t ATTN_COMP_ID     = 0xD100;
const char      ATTN_COMP_NAME[] = "attn";
//@}

/** @name MNFG
 *  Manufacturing Interface
 */
//@{
const comp_id_t MNFG_COMP_ID     = 0xD200;
const char      MNFG_COMP_NAME[] = "mnfg";
//@}

/** @name HMCX
 *  HMC Interface
 */
//@{
const comp_id_t HMCX_COMP_ID     = 0xD300;
const char      HMCX_COMP_NAME[] = "hmcx";
//@}

/** @name CIMP
 *  CIM Providers
 */
//@{
const comp_id_t CIMP_COMP_ID     = 0xD400;
const char      CIMP_COMP_NAME[] = "cimp";
//@}


/** @name IPMI
 * Fips IPMI interface component (Intellectual Platform Management Interface)  to the Management Module on P6 Blades
 */
//@{
const comp_id_t IPMI_COMP_ID     = 0xD500;
const char      IPMI_COMP_NAME[] = "ipmi";
//@}

/** @name BPNL
 * P6 Blade Front Panel.
 */
//@{
const comp_id_t BPNL_COMP_ID     = 0xD600;
const char      BPNL_COMP_NAME[] = "bpnl";
//@}

/** @name CTLR
 *  (MVC) Controller
 */
//@{
const comp_id_t CTLR_COMP_ID     = 0xD700;
const char      CTLR_COMP_NAME[] = "ctlr";
//@}

/** @name CLIF
 *  (SSH based) Command Line Interface
 */
//@{
const comp_id_t CLIF_COMP_ID     = 0xD800;
const char      CLIF_COMP_NAME[] = "clif";
//@}

//----------------------------------------------------------------------
// RAS  ----------------------------------------------------------------
//----------------------------------------------------------------------

/** @name CALL
 *  Call-in / Call-out
 */
//@{
const comp_id_t CALL_COMP_ID     = 0xE000;
const char      CALL_COMP_NAME[] = "call";
//@}

/** @name SNOP
 *  Snoop
 */
//@{
const comp_id_t SNOP_COMP_ID     = 0xE100;
const char      SNOP_COMP_NAME[] = "snop";
//@}

/** @name RBOT
 *  Reboot Policy
 */
//@{
const comp_id_t RBOT_COMP_ID     = 0xE200;
const char      RBOT_COMP_NAME[] = "rbot";
//@}

/** @name LEDS
 *  LED Management
 */
//@{
const comp_id_t LEDS_COMP_ID     = 0xE300;
const char      LEDS_COMP_NAME[] = "leds";
//@}

/** @name SURV
 *  Surveillance Library
 */
//@{
const comp_id_t SURV_COMP_ID     = 0xE400;
const char      SURV_COMP_NAME[] = "surv";
//@}

/** @name PRDF
 *  PRD Framework
 */
//@{
const comp_id_t PRDF_COMP_ID     = 0xE500;
const char      PRDF_COMP_NAME[] = "prdf";
//@}

/** @name RMGR
 *  Redundancy Manager
 */
//@{
const comp_id_t RMGR_COMP_ID     = 0xE600;
const char      RMGR_COMP_NAME[] = "rmgr";
//@}

/** @name SYNC
 *  FSP Data Synchronization
 */
//@{
const comp_id_t SYNC_COMP_ID     = 0xE700;
const char      SYNC_COMP_NAME[] = "sync";
//@}

/** @name SDMP
 *  SMA Dump
 */
//@{
const comp_id_t SDMP_COMP_ID     = 0xE800;
const char      SDMP_COMP_NAME[] = "sdmp";
//@}

/** @name RSRL
 *  Reset/Reload
 */
//@{
const comp_id_t RSRL_COMP_ID     = 0xE900;
const char      RSRL_COMP_NAME[] = "rsrl";
//@}

/** @name CCMM
 *  Concurrent Maintenance
 */
//@{
const comp_id_t CCMM_COMP_ID     = 0xEA00;
const char      CCMM_COMP_NAME[] = "ccmm";
//@}

/** @name CORR
 *  Corrosion Sensor
 */
//@{
const comp_id_t CORR_COMP_ID     = 0xEB00;
const char      CORR_COMP_NAME[] = "corr";
//@}

/** @name BDMP
 *  Fips Dump (Belly-up Dump)
 */
//@{
const comp_id_t BDMP_COMP_ID     = 0xEF00;
const char      BDMP_COMP_NAME[] = "bdmp";
//@}

/** @name DUMP
 *  Platform Dump
 */
//@{
const comp_id_t DUMP_COMP_ID     = 0xF000;
const char      DUMP_COMP_NAME[] = "dump";
//@}


/** @name HLTH
 *  Health Monitor
 */
//@{
const comp_id_t HLTH_COMP_ID     = 0xF100;
const char      HLTH_COMP_NAME[] = "hlth";
//@}

/** @name PSIE
 *  PSI Error Analysis
 */
//@{
const comp_id_t PSIE_COMP_ID     = 0xF200;
const char      PSIE_COMP_NAME[] = "psie";
//@}

/** @name ERPR
 *  EREPAIR TOOLS
 */
//@{
const comp_id_t ERPR_COMP_ID     = 0xF300;
const char      ERPR_COMP_NAME[] = "erpr";
//@}

//----------------------------------------------------------------------
// HOM   ---------------------------------------------------------------
//----------------------------------------------------------------------

/** @name HJTG
 *  HOM JTAG Interface
 */
//@{
const comp_id_t HJTG_COMP_ID     = 0xB000;
const char      HJTG_COMP_NAME[] = "hjtg";
//@}

/** @name HPKU
 *  HOM Packaging Units
 */
//@{
const comp_id_t HPKU_COMP_ID     = 0xB100;
const char      HPKU_COMP_NAME[] = "hpku";
//@}

/** @name HFUG
 *  HOM Groups
 */
//@{
const comp_id_t HFUG_COMP_ID     = 0xB200;
const char      HFUG_COMP_NAME[] = "hfug";
//@}

/** @name HREG
 *  HOM Scan Rings
 */
//@{
const comp_id_t HREG_COMP_ID     = 0xB300;
const char      HREG_COMP_NAME[] = "hreg";
//@}

/** @name HCLK
 *  HOM Clock support
 */
//@{
const comp_id_t HCLK_COMP_ID     = 0xB400;
const char      HCLK_COMP_NAME[] = "hclk";
//@}

/** @name RULE
 *  HOM Rules
 */
//@{
const comp_id_t RULE_COMP_ID     = 0xB500;
const char      RULE_COMP_NAME[] = "rule";
//@}

/** @name RTBL
 *  HOM Rules Tables - no reason codes currently
 */
//@{
const comp_id_t RTBL_COMP_ID     = 0xB600;
const char      RTBL_COMP_NAME[] = "rtbl";
//@}

/** @name HUTL
 *  HOM Utilities
 */
//@{
const comp_id_t HUTL_COMP_ID     = 0xB700;
const char      HUTL_COMP_NAME[] = "hutl";
//@}

/** @name HFUS
 *  HOM Functional Units
 */
//@{
const comp_id_t HFUS_COMP_ID     = 0xB800;
const char      HFUS_COMP_NAME[] = "hfus";
//@}

/** @name HCSI
 *  HOM Chip Scan Interface
 */
//@{
const comp_id_t HCSI_COMP_ID     = 0xB900;
const char      HCSI_COMP_NAME[] = "hcsi";
//@}
// __HWSV_INCLUDE__ Included as part of HWSV suport

  /** @name HWSV
   *  Hardware Server
   */

//@{
const comp_id_t HWSV_COMP_ID     = 0xBA00;
const char      HWSV_COMP_NAME[] = "hwsv";
//@}

/** @name HWOM
*  Hardware Object Module
*/
//@{
const comp_id_t HWOM_COMP_ID     = 0xBB00;
const char      HWOM_COMP_NAME[] = "hwom";
//@}

/** @name HWIL
*  Hardware Object Module
*/
//@{
const comp_id_t HWIL_COMP_ID     = 0xBC00;
const char      HWIL_COMP_NAME[] = "hwil";
//@}

/** @name HWTM
 *  Hardware Targeting Model
 */
//@{
const comp_id_t HWTM_TARG_ID     = 0xBD00;
const char      HWTM_COMP_NAME[] = "hwtm";
//@}

/** @name FMBX
*  FSI MailBox
*/
//@{
const comp_id_t FMBX_COMP_ID     = 0xBE00;
const char      FMBX_COMP_NAME[] = "fmbx";
//@}

/** @name TARGETINGDUMP
*  Targetgin Dump Service
*/
//@{
const comp_id_t TARGETINGDUMP_COMP_ID     = 0xBF00;
const char      TARGETINGDUMP_COMP_NAME[] = "TargetingDump";
//@}

/** @name HOSTBOOT
 *  Hostboot Error Service
 */
//@{
const comp_id_t HOSTBOOT_COMP_ID     = 0xD900;
const char      HOSTBOOT_COMP_NAME[] = "hbfw";
//@}

/** @name HWSV CHIP OPERATIONS SERVICE
 *  Hardware Server Chip Ops Service
 */
//@{
const comp_id_t HWCO_COMP_ID     = 0xDA00;
const char      HWCO_COMP_NAME[] = "hwco";
//@}

/** @name HWSV HOST SERVICE
 *  Hardware Server Host Service
 */
//@{
const comp_id_t HWHS_COMP_ID     = 0xDB00;
const char      HWHS_COMP_NAME[] = "hwhs";
//@}
//----------------------------------------------------------------------
// CEC   ---------------------------------------------------------------
//----------------------------------------------------------------------

/** @name CINI
 *  CEC I/O Initialization
 */
//@{
const comp_id_t CINI_COMP_ID     = 0xC000;
const char      CINI_COMP_NAME[] = "cini";
//@}

/** @name DADA
 *  Display / Alter
 */
//@{
const comp_id_t DADA_COMP_ID     = 0xC100;
const char      DADA_COMP_NAME[] = "dada";
//@}

/** @name ECMD
 *  eServer Command Interface - no reason codes currently
 */
//@{
const comp_id_t ECMD_COMP_ID     = 0xC200;
const char      ECMD_COMP_NAME[] = "ecmd";
//@}

/** @name CHIC
 *  CEC Hardware Interface
 */
//@{
const comp_id_t CHIC_COMP_ID     = 0xC300;
const char      CHIC_COMP_NAME[] = "chic";
//@}

/** @name CECC
 *  CEC Commands - no reason codes currently
 */
//@{
const comp_id_t CECC_COMP_ID     = 0xC400;
const char      CECC_COMP_NAME[] = "cecc";
//@}

/** @name ABST
 *  ABIST - no reason codes currently
 */
//@{
const comp_id_t ABST_COMP_ID     = 0xC500;
const char      ABST_COMP_NAME[] = "abst";
//@}

/** @name LBST
 *  LBIST
 */
//@{
const comp_id_t LBST_COMP_ID     = 0xC600;
const char      LBST_COMP_NAME[] = "lbst";
//@}

/** @name MDIA
 *  CEC Memory Diagnostics
 */
//@{
const comp_id_t MDIA_COMP_ID     = 0xC700;
const char      MDIA_COMP_NAME[] = "mdia";
//@}

/** @name WIRE
 *  Wiretest
 */
//@{
const comp_id_t WIRE_COMP_ID     = 0xC800;
const char      WIRE_COMP_NAME[] = "wire";
//@}

/** @name RAPI
 *  Ring API (CEC Utility) - no reason codes currently
 */
//@{
const comp_id_t RAPI_COMP_ID     = 0xC900;
const char      RAPI_COMP_NAME[] = "rapi";
//@}

/** @name GARD
 *  Resource Guard
 */
//@{
const comp_id_t GARD_COMP_ID     = 0xCA00;
const char      GARD_COMP_NAME[] = "gard";
//@}

/** @name VPOC
 *  Virtual Power On
 */
//@{
const comp_id_t VPOC_COMP_ID     = 0xCB00;
const char      VPOC_COMP_NAME[] = "vpoc";
//@}

/** @name OSCC
 *  Oscillator clock control
 */
//@{
const comp_id_t OSCC_COMP_ID     = 0xCC00;
const char      OSCC_COMP_NAME[] = "oscc";
//@}


/** @name WRAP
 *  Torrent ELCT/PRBS
 */
//@{
const comp_id_t WRAP_COMP_ID     = 0xCD00;
const char      WRAP_COMP_NAME[] = "wrap";
//@}

/** @name OSCE
 *  Oscillator clock error
 */
//@{
const comp_id_t OSCE_COMP_ID     = 0xCE00;
const char      OSCE_COMP_NAME[] = "osce";
//@}

/** @name DCCE
 *  Oscillator clock error
 */
//@{
const comp_id_t DCCE_COMP_ID     = 0xCF00;
const char      DCCE_COMP_NAME[] = "dcce";
//@}

//******************************************************************************
// The following component ids do not use reason codes
//******************************************************************************

/** @name PERF
 *  Perofrmance Componet
 */
//@{
const comp_id_t PERF_COMP_ID     = 0xFFE8;
const char      PERF_COMP_NAME[] = "perf";
//@}

/** @name SBAT
 *  SIBATs - no reason codes
 */
//@{
const comp_id_t SBAT_COMP_ID     = 0xFFE9;
const char      SBAT_COMP_NAME[] = "sbat";
//@}

/** @name CINP
 *  CEC CPU & Caches Initialization - no reason codes
 */
//@{
const comp_id_t CINP_COMP_ID     = 0xFFEA;
const char      CINP_COMP_NAME[] = "cinp";
//@}

/** @name CINM
 *  CEC Memory Initialization - no reason codes
 */
//@{
const comp_id_t CINM_COMP_ID     = 0xFFEB;
const char      CINM_COMP_NAME[] = "cinm";
//@}

/** @name CCSP
 *  CPU Controls - no reason codes
 */
//@{
const comp_id_t CCSP_COMP_ID     = 0xFFEC;
const char      CCSP_COMP_NAME[] = "ccsp";
//@}

/** @name CCWS
 *  CPU Controls GUI - no reason codes
 */
//@{
const comp_id_t CCWS_COMP_ID     = 0xFFED;
const char      CCWS_COMP_NAME[] = "ccws";
//@}

/** @name CRNS
 *  Cronus - no reason codes
 */
//@{
const comp_id_t CRNS_COMP_ID     = 0xFFEE;
const char      CRNS_COMP_NAME[] = "crns";
//@}

/** @name CPCI
 *  Common Portable Client Interface Library - no reason codes
 */
//@{
const comp_id_t CPCI_COMP_ID     = 0xFFEF;
const char      CPCI_COMP_NAME[] = "cpci";
//@}

/** @name DISS
 *  DSS - no reason codes
 */
//@{
const comp_id_t DISS_COMP_ID     = 0xFFF1;
const char      DISS_COMP_NAME[] = "diss";
//@}

/** @name PRDP
 *  PRD for CPU - no reason codes
 */
//@{
const comp_id_t PRDP_COMP_ID     = 0xFFF2;
const char      PRDP_COMP_NAME[] = "prdp";
//@}

/** @name PRDM
 *  PRD for Memory - no reason codes
 */
//@{
const comp_id_t PRDM_COMP_ID     = 0xFFF3;
const char      PRDM_COMP_NAME[] = "prdm";
//@}

/** @name PRDI
 *  PRD for I/O - no reason codes
 */
//@{
const comp_id_t PRDI_COMP_ID     = 0xFFF4;
const char      PRDI_COMP_NAME[] = "prdi";
//@}

/** @name PRDN
 *  PRD for NUMA - no reason codes
 */
//@{
const comp_id_t PRDN_COMP_ID     = 0xFFF5;
const char      PRDN_COMP_NAME[] = "prdn";
//@}

/** @name ILED
 *  I2C LED End Device DAL - no reason codes
 */
//@{
const comp_id_t ILED_COMP_ID     = 0xFFF6;
const char      ILED_COMP_NAME[] = "iled";
//@}

/** @name ITHM
 *  Thermal sensor End Device DAL - no reason codes
 */
//@{
const comp_id_t ITHM_COMP_ID     = 0xFFF7;
const char      ITHM_COMP_NAME[] = "ithm";
//@}

/** @name PWRX
 *  Power Control End Device DAL - no reason codes
 */
//@{
const comp_id_t PWRX_COMP_ID     = 0xFFF8;
const char      PWRX_COMP_NAME[] = "pwrx";
//@}

/** @name TEST
 *  Testcase code - no reason codes
 */
//@{
const comp_id_t TEST_COMP_ID     = 0xFFF9;
const char      TEST_COMP_NAME[] = "test";
//@}

/** @name SYSL
 *  System Log daemon - no reason codes
 */
//@{
const comp_id_t SYSL_COMP_ID     = 0xFFFA;
const char      SYSL_COMP_NAME[] = "sysl";
//@}

/** @name TRAC
 *  Trace - no reason codes
 */
//@{
const comp_id_t TRAC_COMP_ID     = 0xFFFB;
const char      TRAC_COMP_NAME[] = "trac";
//@}

/** @name PNLI
 *  Op Panel Input - no reason codes
 */
//@{
const comp_id_t PNLI_COMP_ID     = 0xFFFC;
const char      PNLI_COMP_NAME[] = "pnli";
//@}

/** @name DIAL
 *  Old Display / Alter - no reason codes
 */
//@{
const comp_id_t DIAL_COMP_ID     = 0xFFFD;
const char      DIAL_COMP_NAME[] = "dial";
//@}

/** @name STTR
 *  State Transition - no reason codes
 */
//@{
const comp_id_t STTR_COMP_ID     = 0xFFFE;
const char      STTR_COMP_NAME[] = "sttr";
//@}

/** @name NVRI
 *  NVRAM Initialization - no reason codes
 */
//@{
const comp_id_t NVRI_COMP_ID     = 0xFFFF;
const char      NVRI_COMP_NAME[] = "nvri";
//@}

#endif // FIPS_COMP_ID_H
