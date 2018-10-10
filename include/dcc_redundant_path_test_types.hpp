// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_redundant_path_test_types.hpp 1.11.1.3 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2008,2009 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/*--------------------------- IBM - Confidential ----------------------------*

    (C) Copyright International Business Machines Corporation 2006
    All Rights Reserved
    Licensed Material  -  Program Property of I B M
    Refer to copyright instructions: Form G120-2083

 *---------------------------------------------------------------------------*/
#ifndef _DCC_REDUNDANT_PATH_TEST_TYPES_HPP_
#define _DCC_REDUNDANT_PATH_TEST_TYPES_HPP_

#include <slotid.h>

#pragma pack(1)

#define RPT_MAX_LINK_INFOS  70

namespace rpt
{

    // unplugged frus are not reported
    typedef enum
    {
        e_NotInitialized=0,
        e_Defective=1,
        e_Plugged=2,
        e_LinkState_t_ForceEnumTo32bit = 0xFFFFFFFF
    } LinkState_t;

    typedef struct 
    {
        SlotId_t    slotId;     /*2B*/
        uint16_t    linkId;     /*2B*/
        LinkState_t linkState;  /*4B*/
    } LinkInfo_t;

    typedef struct
    {
        uint32_t cageId;
        uint32_t nodeId;
        uint32_t side; /* 0: A side (left), 1: B side (right), 2: undef */
        uint32_t role; /* 0: become slave, 1: slave, 2: become master, 3: master */
        uint32_t numLinkInfos; /* number infos contained in linkInfos[] */
        LinkInfo_t linkInfos[RPT_MAX_LINK_INFOS];
    } RptInfo_t;
}
#pragma pack()

#endif //_DCC_REDUNDANT_PATH_TEST_TYPES_HPP_

