// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgt_toif_elog.H 1.13 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2013,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 

/**
 * @file tmgt_toif_elog.H
 *
 * @brief This file contains the implementation of elog related functions
 */


/**********************************************************************************************************************************/
/*                                                                                                                                */
/*  CHANGE ACTIVITY:                                                                                                              */
/*                                                                                                                                */
/*  Flag    Track   Release   Date     Userid    Comments                                                                         */
/*  -----   ------  --------- -------- --------- -------------------------------------------------------------------------------- */
/*                                                                                                                                */
/*  END CHANGE ACTIVITY                                                                                                           */
/**********************************************************************************************************************************/

#ifndef TMGT_TOIF_ELOG_H_
#define TMGT_TOIF_ELOG_H_

// Error Severity
enum occSeverityType
{
    OCC_SEV_INFORMATIONAL   = 0x00,
    OCC_SEV_RECOVERABLE     = 0x01,
    OCC_SEV_UNRECOVERABLE   = 0x02
};


// Error Actions
enum tmgtErrlActionsType
{
    TMGT_ERRL_ACTIONS_CONSOLIDATE_ERRORS       = 0x01,
    TMGT_ERRL_ACTIONS_MANUFACTURING_ERROR      = 0x08,
    TMGT_ERRL_ACTIONS_UNRECOVERABLE_CPM_ERROR  = 0x10,
    TMGT_ERRL_ACTIONS_WOF_RESET_REQUIRED       = 0x20,
    TMGT_ERRL_ACTIONS_SAFE_MODE_REQUIRED       = 0x40,
    TMGT_ERRL_ACTIONS_RESET_REQUIRED           = 0x80,
};

// Type of Callout
enum occCalloutType
{
    OCC_CALLOUT_TYPE_HUID          = 0x01,
    OCC_CALLOUT_TYPE_COMPONENT_ID  = 0x02,
};

// TMGT-OCC Component Ids
enum occCompIdType
{
    OCC_COMPONENT_ID_FIRMWARE         = 0x01,
    OCC_COMPONENT_ID_OVER_TEMPERATURE = 0x04,
    OCC_COMPONENT_ID_OVERSUBSCRIPTION = 0x05,
    OCC_COMPONENT_ID_NONE             = 0xFF,
};

// Callout Data Type, this was ported forward from P7
enum tmgtCompxlateType
{
  TMGT_COMP_DATA_RID                 = 0x00,
  TMGT_COMP_DATA_PROC_RID            = 0x01,
  TMGT_COMP_DATA_PROCEDURE           = 0x02,
  TMGT_COMP_DATA_POWR_VRM_NUM        = 0x03,
  TMGT_COMP_DATA_MEMORY_TABLE_NUM    = 0x04,
  TMGT_COMP_DATA_POWR_DCA_NUM        = 0x05,
  TMGT_COMP_DATA_IOHUB_TABLE_NUM     = 0x06,
  TMGT_COMP_DATA_SYMBOLIC_FRU        = 0x07,
  TMGT_COMP_DATA_SN_TABLE_NUM        = 0x08,
  TMGT_COMP_DATA_VDD_PROC_RID        = 0x0A,
  TMGT_COMP_DATA_END_OF_TABLE        = 0xFF
};

struct occSrciPriorityXlate
{
  uint8_t      occPriority;
  srciPriority errlPriority;
} __attribute__ ((__packed__));
typedef struct occSrciPriorityXlate occSrciPriorityXlate_t;

const occSrciPriorityXlate_t occPriorityXlateTbl[] =
{
  {0x01, SRCI_PRIORITY_LOW},
  {0x02, SRCI_PRIORITY_MED},
  {0x03, SRCI_PRIORITY_HIGH},
};
const uint8_t OCC_SRCI_PRIORITY_XLATE_SIZE = (sizeof(occPriorityXlateTbl)/sizeof(occSrciPriorityXlate_t));

// OCC Usr Dtls Structure @3B5
struct occErrlUsrDtls
{
    uint8_t     iv_version;             // User Details Version
    uint8_t     iv_reserved;            // Reserved
    uint16_t    iv_modId;               // Module Id
    uint32_t    iv_fclipHistory;        // Frequency Clip History
    uint64_t    iv_timeStamp;           // Time Stamp
    uint8_t     iv_occId;               // OCC ID
    uint8_t     iv_occRole;             // OCC Role
    uint8_t     iv_operatingState;      // OCC State
    uint8_t     iv_committed;           // Log Committed?
    uint32_t    iv_userData1;           // User Data Word 1
    uint32_t    iv_userData2;           // User Data Word 2
    uint32_t    iv_userData3;           // User Data Word 3
    uint16_t    iv_entrySize;           // Log Size
    uint16_t    iv_userDetailEntrySize; // User Details Size
} __attribute__ ((__packed__));
typedef struct occErrlUsrDtls occErrlUsrDtls_t;

// OCC Callout Structure
struct occErrlCallout
{
    uint8_t     type;
    uint64_t    calloutValue;
    uint8_t     priority;
    uint16_t    reserved1;
} __attribute__ ((__packed__));
typedef struct occErrlCallout occErrlCallout_t;

// User Detail Entry Structure @3B5
struct occUserDetailsEntry
{
    uint8_t     iv_version; // User Details Entry Version
    uint8_t     iv_type;    // User Details Entry Type
                            // Note: Users must use ERRL_USR_DETAIL_TYPE enum
    uint16_t    iv_size;    // User Details Entry Size
} __attribute__ ((__packed__));
typedef struct occUserDetailsEntry occUserDetailsEntry_t;

#define ERRL_MAX_CALLOUTS 6

// OCC Error Log Structure
struct occErrlEntry
{
    // Log CheckSum
    uint16_t            checkSum;
    // Log Version
    uint8_t             version;
    // Log Entry ID
    uint8_t             entryId;
    // Log Reason Code
    uint8_t             reasonCode;
    // Log Severity
    uint8_t             severity;
    // Actions to process the errors
    uint8_t             actions;
    // Reserved
    uint16_t            reserved;
    // Extended Reason Code
    uint16_t            extendedRC;
    // Log Callout Number
    uint8_t             numCallouts;
} __attribute__ ((__packed__));
typedef struct occErrlEntry occErrlEntry_t;


// OCC Severity and Action
struct occSeverityActionXlate
{
  occSeverityType   occSeverity;
  errlSeverity occErrlSeverity;
  errlActions  occErrlAction;
};
typedef struct occSeverityActionXlate occSeverityActionXlate_t;

// Translate Severity and Actios
const occSeverityActionXlate_t occSeverityErrorActionXlate[] =
{
  {OCC_SEV_INFORMATIONAL,   ERRL_SEV_INFORMATIONAL,   ERRL_ACTION_HIDDEN},
  {OCC_SEV_RECOVERABLE,     ERRL_SEV_PREDICTIVE,      ERRL_ACTION_REPORT},
  {OCC_SEV_UNRECOVERABLE,   ERRL_SEV_UNRECOVERABLE,   ERRL_ACTION_REPORT},
};
const uint8_t OCC_SEV_ACTION_XLATE_SIZE = (sizeof(occSeverityErrorActionXlate)/sizeof(occSeverityActionXlate_t));

struct tmgtCompXlate
{
    uint8_t               compId;
    tmgtCompxlateType     dataType;
    uint32_t              data;
};
typedef struct tmgtCompXlate tmgtCompXlate_t;

const uint16_t TMGT_MAX_COMP_IDS = 4;

const uint32_t OVERTMP = 0x05;
const uint32_t TPMD_OV = 0x06;

#ifndef _X86NFP
const tmgtCompXlate_t tmgt_compXlateTable[TMGT_MAX_COMP_IDS] =
{
    // Table 0 - Tuleta
    /* Firmware                      */ { 0x01,  TMGT_COMP_DATA_PROCEDURE,     EPUB_PRC_SP_CODE},
    /* Over temperature              */ { 0x04,  TMGT_COMP_DATA_SYMBOLIC_FRU,           OVERTMP},
    /* Oversubscription Throttling   */ { 0x05,  TMGT_COMP_DATA_SYMBOLIC_FRU,           TPMD_OV},
    /* None                          */ { 0xFF,  TMGT_COMP_DATA_END_OF_TABLE,                 0},
};

/*-----------------------------------------------------------------------------*/
/* Prototypes                                                                  */
/*-----------------------------------------------------------------------------*/
bool elog_xlate_scriPriority(const uint8_t i_priority,
                             srciPriority &o_priority);

bool elog_add_callout(errlHndl_t & io_errlHndl,
                      const uint8_t i_node,
                      errlSeverity & io_severity,
                      const srciPriority i_priority,
                      const occErrlCallout_t i_callout,
                      uint8_t & io_callout_num);
#endif

#endif /* TMGT_TOIF_ELOG_H_ */
