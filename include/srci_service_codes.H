/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srci_service_codes.H $                       */
/*                                                                        */
/* OpenPOWER errltool Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef SRCI_SERVICE_CODES_H
#define SRCI_SERVICE_CODES_H

/**
 *  @file srci_service_codes.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCI_SERVICE_CODES_H srci_service_codes.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/
#include <fips_comp_id.H>

typedef unsigned short  comp_id_t;
//const comp_id_t SRCI_COMP_ID     = 0x8200;

/** @enum evenModId
 *        "Module ids" for the SRC utility SRCs.
 *        Actually, these are ids assigned to each function/method within
 *        a module (.C file).  The ids must be unique across all component
 *        modules
 */
enum srciModId
{
    // srcitraceitr.C
    SRCI_TRC_ITR_CTOR              = 0x01,
    SRCI_TRC_ITR_GET_SRC           = 0x02,

    // srcicleariplsrc.C
    SRCI_CL_MAIN                   = 0x20,
    PERC_GET_ERROR_DATA2           = 0x21,

    // srcicopyiplsrc.C
    SRCI_CO_MAIN                   = 0x30,
    PERC_GET_ERROR_DATA3           = 0x31,

    // srcidisplaystatussrc.C
    SRCI_DS_MAIN                   = 0x40,
    SRCI_DS_DISPLAY_SRC            = 0x41,
    PERC_GET_ERROR_DATA4           = 0x42,

    // srcidisplaytermsrc.C
    SRCI_DT_MAIN                   = 0x50,
    PERC_GET_ERROR_DATA5           = 0x51,

    // srciutility.C
    SRCI_BLD_SORTED_ARRAY          = 0x60,
    SRCI_GET_FILE_CNT              = 0x61,
    SRCI_GET_PATH                  = 0x62,

    // srcisrc.C
    SRCI_COPY_CURR_IPL_SRC_TO_PREV = 0x70,
    SRCI_CLEAR_IPL_SRC             = 0x71,
    SRCI_MID_UNFLATTEN             = 0x72,
    SRCI_MID_IMPORT_CTOR           = 0x73,

    // srcitrace.C
    SRCI_TRACE_ENTRY		   = 0x80,
    SRCI_DELETE_OLDEST		   = 0x81,
    SRCI_MID_FLSCAN		   = 0x82,
    SRCI_MID_ADD_TRACE		   = 0x83,

    // srcitarget
    SRCI_MID_PROCESS_MSG	   = 0x90,
    SRCI_MID_GET_SRC		   = 0x91,

    // srcicalloutsctn.C
    SRCI_MID_CALLOUT_SCTN	   = 0xA0,
    SRCI_MID_CALLOUT_SCTN_UNFLATTEN= 0xA1,

    // srcicallout.C
    SRCI_MID_CALLOUT		   = 0xB0,

    // srci tool
    SRCI_MID_TOOL_CLEAR_IPL_SRC	   = 0xC0,
    SRCI_MID_TOOL_DISPLAY_IPL_SRC  = 0xC1,
    SRCI_MID_TOOL_DISPLAY_TERM_SRC = 0xC2,
    SRCI_MID_TOOL_SHIFT_SRC	   = 0xC3,
    SRCI_MID_TOOL_PRINT_SRC	   = 0xC4,
    SRCI_MID_TOOL_LIST_SRCS	   = 0xC5,

    // srci perc
    SRCI_MID_PERC_ERROR		   = 0xC6

};


/** @enum srciExtRefCode
 *        Extended reference codes for the SRC utility SRCs.  Extended
 *        ref codes can be used in more than one location.  The combination
 *        of module id and extended ref code points to a unique piece of code.
 *        Therefore, if the same error can occur in multiple places within the
 *        same function/method, each error would need its own unique extended
 *        ref code.
 */
enum srciExtRefCode
{
    SRCI_ERC_READ_FILE     = SRCI_COMP_ID | 0x01,  // File read() error
    SRCI_ERC_STG_ALLOC     = SRCI_COMP_ID | 0x02,  // malloc() error
    SRCI_ERC_OPEN          = SRCI_COMP_ID | 0x03,  // File open() error
    SRCI_ERC_INDEX         = SRCI_COMP_ID | 0x04,  // Invalid array index error
    SRCI_ERC_OPEN_DIR      = SRCI_COMP_ID | 0x05,  // opendir() error
    SRCI_ERC_READ_DIR      = SRCI_COMP_ID | 0x06,  // readdir() error
    SRCI_ERC_FORK          = SRCI_COMP_ID | 0x07,  // fork() error
    SRCI_ERC_DISPLAY_SRC   = SRCI_COMP_ID | 0x08,  // error returned from SrciSrc::display()
    SRCI_ERC_CLEAR_IPL_SRC = SRCI_COMP_ID | 0x09,  // error returned from SrciSrc::clearIplSrc
    SRCI_ERC_TOO_FEW_PARMS = SRCI_COMP_ID | 0x0A,  // too few parameters for an executable
    SRCI_ERC_BAD_PARM      = SRCI_COMP_ID | 0x0B,  // invalid parameter for an executable
    SRCI_ERC_COPY_IPL_SRC  = SRCI_COMP_ID | 0x0C,  // error returned from SrciSrc::copyCurrIplSrcToPrev
    SRCI_ERC_SIGNAL        = SRCI_COMP_ID | 0x0D,  // process received unexpected signal
    SRCI_ERC_REG_SIZEOF    = SRCI_COMP_ID | 0x0E,  // reg_size_of() error
    SRCI_ERC_REG_READ      = SRCI_COMP_ID | 0x0F,  // reg_read() error
    SRCI_ERC_GET_PATH_ERR  = SRCI_COMP_ID | 0x10,  // error returned from srciGetPath()
    SRCI_ERC_GET_SRC       = SRCI_COMP_ID | 0x11,  // Iterator error
    SRCI_ERC_NOT_SUPPORTED = SRCI_COMP_ID | 0x12,  // Process Message
    SRCI_ERC_UNEXPECTED    = SRCI_COMP_ID | 0x13,  // Unexpected result
    SRCI_ERC_INVALID	    = SRCI_COMP_ID | 0x14,  // Invalid data ( input or otherwise )
    SRCI_ERC_BAD_SIZE      = SRCI_COMP_ID | 0x15,  // Bad input size
    SRCI_ERC_STREAM	    = SRCI_COMP_ID | 0x16,  // Stream error
    SRCI_ERC_FLATTEN	    = SRCI_COMP_ID | 0x17,  // Flatten Failure
    SRCI_ERC_BAD_ID        = SRCI_COMP_ID | 0x18,  // Bad Identifier
    SRCI_ERC_SIGNAL_RCVD   = SRCI_COMP_ID | 0x19,  // Unknown signal received

    SRCI_ERC_LAST_ONE	    = SRCI_COMP_ID | 0xFF   // Indicates last one - not used

};




/** @enum Extended reference code modifiers
 *
 *	Because extended reference codes are sometimes still a broad
 *	category for a more specific error, these enums will be
 *	placed in word 5 (User defined word 1) of the SRC as a final code point.
 *
 *  @note	cast to uint32_t
 *
*/
enum srciExtRefCodeModifier
{
    SRCI_ERCM_NONE	    = 0,
    SRCI_ERCM_MEM_ALLOC	    = 1,
    SRCI_ERCM_FLAT_FAIL	    = 2
};




/**
 *  @enum File ID
 *
 *  File ID is used while adding software error section
 *  to the ErrlEntry. There are IDs assigned to each file in ERRL component.
 *  The are (mostly) listed in order of class hiearchy.
 *  @note   cast to uint32_t
 *
*/
enum srciFileId
{
    SRCI_FILEID_NONE	    = 0,
    SRCI_FILEID_TRACE	    = 1,
    SRCI_FILEID_TARGET	    = 2
};



// Counts error SRCs since last IPL
const char 	SRCI_REG_ERROR_COUNT[]		= "srci/ErrSrcCount";
const uint32_t	SRCI_REGSZ_ERROR_COUNT		= 1;

// Number of SRC entries in the diagnostic trace
const char 	SRCI_REG_DIAG_TRACE[]		= "srci/DiagSrcTrace";
const uint32_t	SRCI_REGSZ_DIAG_TRACE		= 1;

// Number of SRC entries in the error trace
const char 	SRCI_REG_ERROR_TRACE[]		= "srci/ErrSrcTrace";
const uint32_t	SRCI_REGSZ_SRC_TRACE		= 1;

// Number of SRC entries in the system trace
const char    SRCI_REG_SYS_TRACE[]        = "srci/SysSrcTraceExt";
const uint32_t    SRCI_REGSZ_SYS_TRACE        = 2;

// Number of SRC entries in the CEC Term trace
const char 	SRCI_REG_CEC_TRACE[]		= "srci/CecTermSrcTrace";
const uint32_t	SRCI_REGSZ_CEC_TRACE		= 1;

// Number of SRC entries in the current IPL trace
const char 	SRCI_REG_CUR_IPL_TRACE[]	= "srci/CurrIplSrcTrace";
const uint32_t	SRCI_REGSZ_CUR_IPL_TRACE	= 1;

// Number of SRC entries in the previous IPL trace
const char 	SRCI_REG_PREV_IPL_TRACE[]	= "srci/PrevIplSrcTrace";
const uint32_t	SRCI_REGSZ_PREV_IPL_TRACE	= 1;



/** @enum  srciUserDataVersion
  *
  * Identifier for the version of user data in an error log.
  * This value is used in conjuction with the type field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the errl component.
*/
enum srciUserDataVersion
{
    SRCI_UDV_DEFAULT_VER_1  = 0x0001    ///< Version 1, default info
};



/** @enum  srciUserDataType
  *
  * Identifier for the user data type for the user data in an error log.
  * This value is used in conjuction with the version field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the errl component.
*/
enum srciUserDataType
{
    SRCI_UDT_FLAT_SRC	    = 0x0001,   ///< Flat src data
    SRCI_UDT_PATH	    = 0x0002,   ///< Path
    SRCI_UDT_ASCSTR	    = 0x0003	///< Ascii String
};


#endif //SRCI_SERVICE_CODES_H
