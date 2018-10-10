/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srci.H $                                     */
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
#ifndef SRCI_H
#define SRCI_H

/**
 *  @file srci.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCI_H srci.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 * @endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
// STD C
#include <nfptypes.H>

#include <stdint.h>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class SrciSrc;
class SrciCallout;
class UtilStream;
class SrciCalloutSctn;


/*****************************************************************************/
// User Types
/*****************************************************************************/

enum srciSrcVersion 
{ 
    SRCI_FIPS_VERSION1		    = 2,	///< ONLY SUPPORTED FSP VERSION
    SRCI_FIPS_VER_INVAL		    = 0xFF	///< FOR INTERNAL USE ONLY! 
};


enum srciSrcFormats 
{ 
    SRCI_FIPS_FORMAT		    = 0xF0,
    SRCI_HBT_FORMAT                 = 0xE0
};



enum srciTermState 
{ 
    SRCI_TERM_STATE_NO_FLAGS	    = 0x00000000,
    SRCI_TERM_HW_CHECKSTOP	    = 0x80000000, 
    SRCI_TERM_STATE_SOFT	    = 0x20000000, 
    SRCI_TERM_STATE_LOWRES	    = 0x08000000, 
    SRCI_TERM_STATE_MNFG	    = 0x10000000,
    SRCI_TERM_STATE_RSRL            = 0x00800000,
    SRCI_TERM_STATE_TERMINATE       = 0x00400000,
    SRCI_TERM_STATE_ALL_FLAGS	    =	SRCI_TERM_HW_CHECKSTOP |
					SRCI_TERM_STATE_SOFT   |
					SRCI_TERM_STATE_LOWRES |
					SRCI_TERM_STATE_MNFG   |
                                        SRCI_TERM_STATE_RSRL   |
                                        SRCI_TERM_STATE_TERMINATE 
};



/**
 *  @brief Allowable trace types
 *
 *  These constants are used when sending an src to a trace bucket
 *  
 *  @note The value of these constants must be kept in sync with
 *        the array of strings in srcitrace.C -- if the two
 *        are different, chaos will occur.
 *  
*/
enum srciTraceType 
{ 
    SRCI_DONT_TRACE		    = -1, 
    SRCI_SYSTEM_TRACE		    = 0, 
    SRCI_DIAG_TRACE		    = 1, 
    SRCI_CURR_IPL_TRACE		    = 2, 
    SRCI_PREV_IPL_TRACE		    = 3, 
    SRCI_TERM_CEC_IPL_TRACE	    = 4,
    SRCI_ERROR_TRACE		    = 5
};


enum srciType 
{ 
    SRCI_INTERVENTION_REQ	    = 0xA1,
    SRCI_MACH_CHECK		    = 0xB1, 
    SRCI_ERR_INFO		    = 0xB1, 
    SRCI_IPL_STATUS		    = 0xC1, 
    SRCI_GENERAL_STATUS		    = 0xD1,
    SRCI_DUMP_STATUS		    = 0xD1,
    
    HBT_INTERVENTION_REQ           = 0xAC,
    HBT_MACH_CHECK                 = 0xBC,
    HBT_ERR_INFO                   = 0xBC,
    HBT_IPL_STATUS                 = 0xCC,
    HBT_GENERAL_STATUS             = 0xDC,
    HBT_DUMP_STATUS                = 0xDC
};

// These attributes may impact 1 or more
// fields in the actual structure.
enum srciAttributes 
{ 
    SRCI_NO_ATTR		    = 0, 
    SRCI_SPCN_FAULT		    = 0x02,
    SRCI_HYPR_DUMP		    = 0x04,
    SRCI_HYPR_LOG_SE		    = 0x10,
    SRCI_VIRTUAL_SRC		    = 0x80,

    SRCI_ATTR_MASK		    = SRCI_SPCN_FAULT	|
	                              SRCI_HYPR_DUMP	|
	                              SRCI_HYPR_LOG_SE	|
				      SRCI_VIRTUAL_SRC
};


enum srciPriority 
{ 
    SRCI_PRIORITY_LOW		    = 1,
    SRCI_PRIORITY_MEDC		    = 2,
    SRCI_PRIORITY_MEDB		    = 3,
    SRCI_PRIORITY_MEDA		    = 4,
    SRCI_PRIORITY_MED		    = 5,
    SRCI_PRIORITY_HIGH		    = 6
};



enum srcistatus_t
{
    SRCI_STATUS_FAILURE		    = -1,
    SRCI_STATUS_SUCCESS		    = 0,
    SRCI_STATUS_CORRUPT		    = 1,
    SRCI_STATUS_SHORT_SIZE	    = 3,
    SRCI_STATUS_INVALID		    = 4,
    SRCI_STATUS_NOT_FOUND	    = 5
};



enum srciFormatPrint
{
    SRCI_FP_PANEL		    = 'p'
};




/**
 *  @brief Failing Component Type Constants for FRUs
 *
 *  FRU's can have different types and these are the constants
 *  
 *  @note Taken from Architectural Spec V 1.5d
 *  
*/
enum srcifct 
{ 
    SRCI_FCT_RESERVED		    = 0,	//< Not used
    SRCI_FCT_NORMAL_HW_FRU	    = 0x10,	//< Normal Hardware FRU
    SRCI_FCT_CODE_FRU		    = 0x20,	//< Code FRU
    SRCI_FCT_CONFIG_ERR_PROC_REQ    = 0x30,	//< Config error, config proc
    SRCI_FCT_MAINTENANCE_PROC_REQ   = 0x40,	//< Maintenance proc required
    SRCI_FCT_EXTERNAL_FRU	    = 0x90,	//< External FRU
    SRCI_FCT_EXTERNAL_CODE_FRU	    = 0xA0,	//< External code FRU
    SRCI_FCT_TOOL_FRU		    = 0xB0,	//< Tool FRU
    SRCI_FCT_SYMBOLIC_FRU	    = 0xC0,	//< Symbolic FRU
    SRCI_FCT_SYMBOLIC_FRU_WITH_LOC  = 0xE0	//< Symbolic FRU with trusted location code
};



/**
 *  @brief Set of misc flags used internally by srci
 *
 *  Most of these flags are internal constants only used
 *  in parsing and for encoding
 *  
 *  @note Taken from Architectural Spec V 1.5d
 *  
*/
enum srciMiscFlags
{
    SRCI_ESF_FLAG_MFG		= 0x10000000,
    SRCI_ESF_FLAG_DECON		= 0x02000000,
    SRCI_ESF_FLAG_GARD		= 0x01000000,
    SRCI_CS_IO_BRIDGE_DOMAIN	= 0x00008000,
    SRCI_CS_PROCESSOR_CLOCK	= 0x00000400,
    SRCI_CS_IO_CLOCKS		= 0x00000200,
    SRCI_CS_MAINSTORE_CLOCK	= 0x00000100
};


/*****************************************************************************/
// Constants
/*****************************************************************************/

const uint32_t SRCI_BASELEN			    = 72;

const uint32_t SRCI_HEADER_LEN			    = 8;

const uint32_t SRCI_MAX_HEX_WORD_COUNT		    = 8;

const uint32_t SRCI_MAX_ASCII_BYTES		    = 32;

const uint32_t SRCI_MAX_LOC_CODE_SIZE		    = 80;

const uint32_t SRCI_MAX_SIZE			    = 1024;

const uint32_t SRCI_DEF_TRACE_AMT		    = 256;
/*****************************************************************************/
// Synonyms
/*****************************************************************************/

typedef int16_t		srciIdx_t;



/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/

/*****************************************************************************/
// Inlines
/*****************************************************************************/



// Data structure for an SRC object or flattened data
struct srciSrcData_t
{
    uint8_t     iv_version;
    uint8_t	iv_attributes;
    uint8_t     iv_reserved2;
    uint8_t     iv_hexSize;
    uint16_t    iv_reserved3;
    uint16_t    iv_totalSize;
    uint32_t    iv_hexWords[SRCI_MAX_HEX_WORD_COUNT];
    char        iv_asciiString[SRCI_MAX_ASCII_BYTES];
};



#endif //SRCI_H

