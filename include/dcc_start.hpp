// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_start.hpp 1.15.1.3 
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
//  LAST_VERSION_FROM_CC: 
// $Source: fips740 fsp/src/oscc/fsp/apollo/dcc/dcc_start.hpp 1$

//       SW041243 britson  added new domainType_t value athena
/*--------------------------- IBM - Confidential ----------------------------*

    (C) Copyright International Business Machines Corporation 2004
    All Rights Reserved
    Licensed Material  -  Program Property of I B M
    Refer to copyright instructions: Form G120-2083

 *---------------------------------------------------------------------------*/

#ifndef _DCC_START_HPP_
#define _DCC_START_HPP_

#include <dcc_slotid.hpp>

#include <string>
#include <set>

namespace dcc
{
    typedef enum
    {
        e_HE,
        e_MR_Drawer1,
        e_MR_Drawer2,
        e_IH_A, 
        e_IH_B,
        e_MR_Athena,
        e_MR_Athena_P7P,
        e_MR_Drawer1_P7P,
        e_MR_Drawer2_P7P,
    } DomainType_t;

    int32_t start(DomainType_t f_domainType, bool f_noTimeoutPAbend = false);
    int32_t stop(void);


    typedef enum
    {
        e_NotPlugged,
        e_Plugged_DoNotUse,
        e_Plugged_Functional
    } SlotStatus_t;
    int32_t send_card_plug(SlotId_t f_slotId, SlotStatus_t f_slotStatus);

    int32_t finish_initial_config(void);

    void getFunctionalCardSlots(std::set<SlotId_t> &f_cardSlots);
    void getDoNotUseCardSlots(std::set<SlotId_t> &f_cardSlots);
}

std::string asString(const dcc::DomainType_t& f_domainType);

#endif //_DCC_START_HPP_

