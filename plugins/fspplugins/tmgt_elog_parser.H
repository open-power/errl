/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* fips911 src/tmgt/fsp/tmgt_elog_parser.H 1.9                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* OBJECT CODE ONLY SOURCE MATERIALS                                      */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2017              */
/* All Rights Reserved                                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//  LAST_VERSION_FROM_CC:
// $Source: fips740 fsp/src/tmgt/fsp/tmgtutility.H 1$


#ifndef TMGT_ELOG_PARSER_H
#define TMGT_ELOG_PARSER_H

/**
 * @file tmgt_elog_parser.H
 *
 * @brief This file contains structures / defines used by the error log data parser
 */

#include <tmgt.H>
#include <tmgt_occ.H>

// Data version identifier for error log user details
const uint16_t TMGT_VERSION = 1;  // version of data defined below in tmgtDataTypes

// An enumeration to tag the data type of user details data added to
// an error log entry.
enum tmgtElogDataTypes
{
    TMGT_MSG_DATA_TYPE          = 0x01, // A message sent between a client and the daemon
    TMGT_ERROR_DATA_TYPE        = 0x06, // tmgt error specific data
    TMGT_ENERGYSCALE_DATA_TYPE  = 0x08, // EnergyScale details
    //TMGT_SPIF_CMD_DATA_TYPE    = 0x09, // Spif command
    TMGT_OCC_ELOG_DATA_TYPE     = 0x0A, // OCC error log data
    TMGT_OCC_FFDC_DATA_TYPE     = 0x0B, // OCC field FFDC data (last freq / voltage)
    TMGT_MSG_DATA_TRUNCATED     = 0x0C, // A truncated client/server message.
    TMGT_OCC_CMD_DATA           = 0x0D, // OCC Command Data
    TMGT_OCC_RSP_DATA           = 0x0E, // OCC Response Data
    TMGT_FOM_DATA_TYPE          = 0x0F,
    TMGT_ELOG_TYPE_TOIF_RESET   = 0x10, // TOIF error log data
    TMGT_ELOG_TYPE_OCC_RESET    = 0x11, // OCC error log data
    TMGT_ELOG_TYPE_PCAP_DATA    = 0x12, // Power Cap data
    TMGT_ELOG_TYPE_THERMAL_DATA = 0x13, // Ambient, fan speeds, temperatures
    TMGT_PROC_SCOM_REGISTERS    = 0x14, // Processor scom register data
    TMGT_ELOG_TYPE_OCC_TRACE    = 0x15, // OCC trace buffer
};

struct toifResetData_t
{
    uint8_t node;
    uint8_t mode;
    uint8_t state;
    uint8_t needsReset;
    uint8_t safeMode;
};

struct occResetData_t
{
    uint8_t     node;
    uint8_t     instance;
    uint8_t     role;
    uint8_t     capable;
    uint32_t    huid;
    uint8_t     state;
    uint8_t     failed;
    uint8_t     needsReset;
    uint8_t     resetCountM;
    uint8_t     resetCountS;
    uint8_t     commEst;
    uint8_t     pollValid;
    uint8_t     lastPollRsp[TMGT_OCC_POLL_RSP_SIZE];
    uint32_t    iplResetCount;
};

#endif // TMGT_ELOG_PARSER_H
