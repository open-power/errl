// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_slotid.hpp 1.13.1.2 
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

    (C) Copyright International Business Machines Corporation 2007
    All Rights Reserved
    Licensed Material  -  Program Property of I B M
    Refer to copyright instructions: Form G120-2083

 *---------------------------------------------------------------------------*/
#ifndef _DCC_SLOTID_H
#define _DCC_SLOTID_H

#include <stdint.h>

typedef uint32_t PihType;

namespace dcc
{
typedef uint32_t SlotId_t;
typedef uint16_t NodeId_t;
typedef uint32_t ChipId_t;
}

#define PIH_INVALID 0
#define NODEID_INVALID 0xFFFFL
#define SLOTID_INVALID 0
#define DOMAIN_SLOT 0x00010000L
#endif

