// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgtmsg.H 1.9.10.21 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2005,2016 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC:
// $Source: fips760 fsp/src/tmgt/fsp/tmgtmsg.H 3$

#ifndef TMGTMSG_H
#define TMGTMSG_H

/**
 * @file tmgtmsg.H
 *
 * @brief This file contains class definitions for messages that are sent
 *        from a client to the thermal management server daemon or vice
 *        versa.
 */

/**********************************************************************************************************************************/
/*                                                                                                                                */
/*  CHANGE ACTIVITY:                                                                                                              */
/*                                                                                                                                */
/*  Flag  Track   Release     Date     Userid    Comments                                                                         */
/*  ----- ------  ----------- -------- --------- -------------------------------------------------------------------------------- */
/*  @CC02   985122  fips860   05/11/16 cjcain    Enhance safe mode recovery                                                       */
/*                                                                                                                                */
/*  END CHANGE ACTIVITY                                                                                                           */
/**********************************************************************************************************************************/



/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <tmgt.H>
#include <tmgt_powermode.H>

#ifdef TMGT_LAB_DEBUG
#include <iostream>             // for debugging
#endif


/*-----------------------------------------------------------------------------*/
/* Constants                                                                   */
/*-----------------------------------------------------------------------------*/

/**
 * @brief This constant is the maximum size of any message defined in this file.
 *        The value is used to allocate message buffers at compile time as
 *        storage on the stack.
 */
const uint32_t TMGT_MAX_MSG_SIZE = 1024;
const uint32_t TMGT_MAX_LOC_CODE_SIZE = 0x50;

enum tmgtThreadType
{
    TMGT_THREAD_MAIN        = 0x00,
    TMGT_THREAD_TOIF        = 0x01,
    TMGT_THREAD_ENERGYSCALE = 0xE5,
};

/**
 * @enum tmgtMsgType
 *       Enumeration that defines the type of message being sent over a socket.
 *       Normally, one does not need tags for objects but when an object is sent
 *       over the socket, it becomes flattened and loses its objectness.
 *       The tag in the object allows the code receiving the socket data
 *       to cast the data back to an object.
 */
enum tmgtMsgType
{
    // 0x00-0x7F are reserved for the tmgt server
    TMGT_ACK                              = 0x01,  // positive acknowledgment message
    TMGT_NACK                             = 0x02,  // negative acknowledgment message
    TMGT_POWEREXECUTIVEPASSTHROUGH        = 0x09,
    TMGT_QUERYMODEANDFUNCTION             = 0x0B,
    TMGT_SETPOWERCAP                      = 0x0C,
    TMGT_XFILEDISABLE                     = 0x12,
    TMGT_GETCPUTEMPERATURE                = 0x16,

    TMGT_PEXFINDFWINSTANCE                = 0x1A,
    TMGT_RECALCULATEPCAP                  = 0x1B,
    TMGT_SENDAMBIENTANDFANSPEEDS          = 0x1C,
    TMGT_SETCUSTREQUESTEDMODE             = 0x1D,
    TMGT_MODECHANGEREQUIRED               = 0x1E,

    TMGT_QUERYPROCFOLDINGDATA             = 0x25,
    TMGT_QUERYMODEDURATION                = 0x28,
    TMGT_GETPCAPVALUES                    = 0x30,
    TMGT_REREADDEFFILE                    = 0x32,
    TMGT_FSPROLECHANGE                    = 0x33,

    TMGT_SETOCCSTATE                      = 0x39,
    TMGT_LOADOCC                          = 0x40,
    TMGT_LOADOCCSTATUS                    = 0x41,
    TMGT_RESETOCC                         = 0x42,
    TMGT_RESETOCCSTATUS                   = 0x43,

    TMGT_DEBUG_TRACING                    = 0x63,

    TMGT_GETRESOURCE_PCAPLVL              = 0x6E,
    TMGT_GETRESOURCE_FREQPOINT            = 0x6F,

    TMGT_EXITSAFEMODE                     = 0x70, // @CC02a

    TMGT_INTERNAL_DEBUG                   = 0x7F,

    TMGT_GETREG_PWRSTATUS                 = 0x80,
    TMGT_GETREG_HWERROR                   = 0x81,
};

enum tmgtFileStatus
{
    TMGT_FILE_NOT_INITIALIZED = 0x00,
    TMGT_FILE_INITIALIZED,
    TMGT_FILE_INITIALIZATION_COMPLETE,
};

struct tmgtGetCpuTemperature_t
{
    uint32_t  rid;
    uint8_t   core;
    uint8_t   chipNum;
    uint32_t  moduleIndex;
};

struct tmgtPciSlotEntry_ver1
{
    uint32_t p8_id;
    uint16_t slot;
    uint16_t reserved;
    uint16_t vendorID;
    uint16_t deviceID;
    uint16_t subSysVendorID;
    uint16_t subSysDeviceID;
}__attribute__((packed));

struct tmgtPciSlotEntry
{
    tmgtPciSlotEntry_ver1   entry;
    uint16_t                power;
    uint8_t                 coolingType;
    uint8_t                 reserved[5];
}__attribute__((packed));


const uint8_t TMGT_PCI_SLOTS_FILE_HEADER_SIZE = 16;
struct tmgtPciSlots
{
    uint8_t               version;
    uint8_t               fileStatus;
    uint16_t              numEntries;
    uint8_t               reserved[12];
    tmgtPciSlotEntry      entries[0];
}__attribute__((packed));


typedef struct
{
    uint8_t  ps_eff[2];
    uint8_t  bulk_pwr[2];
    uint8_t  min_pcap[2];
    uint8_t  max_pcap[2];
    uint8_t  upic_limit[2];
    uint8_t  frame_pwr[2];
    uint8_t  vdd_resist[2];
    uint8_t  vcs_resist[2];
    uint8_t  bpcNum;
} tmgtFramePower_t;


#endif // TMGTMSG_H

