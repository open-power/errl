// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_oscillator_types.hpp 1.10.3.1 
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

    (C) Copyright International Business Machines Corporation 2004
    All Rights Reserved
    Licensed Material  -  Program Property of I B M
    Refer to copyright instructions: Form G120-2083

 *---------------------------------------------------------------------------*/



#ifndef DCC_OSCILLATOR_TYPES_HPP
#define DCC_OSCILLATOR_TYPES_HPP


/* Number of readable i2c registers in the pll */
/* 4 byte allignment required */
#define DCC_OSC_PLL_NUM_REGISTERS 4

/* Number of readable i2c registers in the crc */
/* only 10 needed, using 12 to enforce 4 byte allignment */
#define DCC_OSC_CRC_NUM_REGISTERS 12


namespace dccosc
{
    typedef enum
    {
        e_ClockDomain_t_Undefined = 0x00000000,
        e_cp        = 0x00000001,
        e_optic     = 0x00000002,
        e_gx        = 0x00000004,
        e_mem       = 0x000000F8,
        e_mem_1     = 0x00000008,
        e_mem_2     = 0x00000010,
        e_mem_3     = 0x00000020,
        e_mem_4     = 0x00000040,
        e_mem_5     = 0x00000080,
        e_ClockDomain_t_ForceEnumTo32bit = 0xFFFFFFFF
    } ClockDomain_t;

    typedef enum
    { 
        e_OscUnknown = 0x00,
        e_OscSet_0   = 0x10,
        e_OscSet_1   = 0x20,
        e_OscAll     = 0x30, // only for oscillator_select with e_oscSelectionMode_Disable
        e_OscCardSet_t_ForceEnumTo32bit = 0xFFFFFFFF
    } OscCardSet_t;

    typedef enum
    { 
        e_OscSelectionMode_Unknown   = 0,
        e_OscSelectionMode_Preferred = 1,
        e_OscSelectionMode_Force     = 2,
        e_OscSelectionMode_Disable   = 3, // use in oscillator_select with e_OscAll
        e_OscSelectionMode_t_ForceEnumTo32bit = 0xFFFFFFFF
    } OscSelectionMode_t;

    typedef enum
    {
        e_DisablePropagation = 0,
        e_EnablePropagation = 1,
        e_SwitchoverPropagationMode_t_ForceEnumTo32bit = 0xFFFFFFFF
    } SwitchoverPropagationMode_t;

    typedef enum
    {
        e_cardUnplugged,
        e_cardPowerOn,   // Power is ok
        e_cardPowerOff,  // Power is off
        e_cardPowerFail, // Power fail but card still activated
        e_PowerStatus_t_ForceEnumTo32bit = 0xFFFFFFFF
    } PowerStatus_t;

    typedef enum
    {
        e_initial = 0, // from EPO or after power-off 
        e_primary = 1,
        e_secondary = 2,
        e_only = 3,
        e_disabled = 4,
        e_OscSetMode_t_ForceEnumTo32bit = 0xFFFFFFFF
    } OscSetMode_t;

    typedef enum
    {
        e_spreadOff = 0,
        e_spreadUp,
        e_spreadDown,
        e_spreadCenter,
        e_SpreadingDirection_t_ForceEnumTo32bit = 0xFFFFFFFF
    } SpreadingDirection_t;
    
    typedef enum
    { 
        e_OscDrawer0 = 0,
        e_OscDrawer1 = 1,
        e_OscDrawer2 = 2,
        e_OscDrawer3 = 3,
        e_OscDrawerUnknown = 0xFFFFFFFF,
        e_OscDrawerMax = e_OscDrawer3,
    } OscDrawerId_t;

    typedef enum
    { 
        e_OscDrawer0_Slot0 = 0x10,
        e_OscDrawer0_Slot1 = 0x11,
        e_OscDrawer1_Slot0 = 0x20,
        e_OscDrawer1_Slot1 = 0x21,
        e_OscDrawer2_Slot0 = 0x30,
        e_OscDrawer2_Slot1 = 0x31,
        e_OscDrawer3_Slot0 = 0x40,
        e_OscDrawer3_Slot1 = 0x41,
        e_OscSlotUnknown = 0xFFFFFFFF,
        e_OscSlotId_Max = e_OscDrawer3_Slot1,
    } OscSlotId_t;

} // namespace dccosc

#endif // DCC_OSCILLATOR_TYPES_HPP

