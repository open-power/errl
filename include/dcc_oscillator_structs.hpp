// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_oscillator_structs.hpp 1.10.1.4 
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

#ifndef DCC_OSCILLATOR_STRUCTS_HPP
#define DCC_OSCILLATOR_STRUCTS_HPP


#include <dcc_oscillator_types.hpp>

#include <dcc_slotid.hpp>
#include <dcc_stl.hpp>


namespace dccosc
{
    typedef struct
    {
        SpreadingDirection_t direction;
        uint32_t value; // in tenth percentage
    } SpreadingStatus_t;

    typedef struct
    {
        uint32_t speed; // in pico seconds
        uint8_t outputEnabled;
        uint8_t inputLoss;
        uint8_t lockLoss;
        SpreadingStatus_t spreadingState; 
        uint8_t registers[DCC_OSC_PLL_NUM_REGISTERS];
    } PllStatus_t;

    typedef struct
    {
        uint8_t inputLoss;         // Input signal ok?
        uint8_t inputFreqFailure;
        uint8_t inputDisabled;     // Signal not valid, cannot be switched to
        uint8_t inputSelected;     // At the moment selected signal
    } CrcInputStatus_t;

    typedef struct
    {
        uint8_t outputEnabled;
        uint8_t crcBypass; // 0 in normal operation
        uint8_t lockLoss;
        uint8_t feedbackLoss;
        CrcInputStatus_t myPllStatus;
        CrcInputStatus_t otherPllStatus;
        CrcInputStatus_t otherCrcStatus;
        uint8_t registers[DCC_OSC_CRC_NUM_REGISTERS];
    } CrcStatus_t;

    typedef struct
    {
        ClockDomain_t clockDomain;
        uint8_t steeringMode;
        PllStatus_t pllStatus;
        CrcStatus_t crcStatus;
    } ClockDomainStatus_t;

    typedef struct
    {
        dcc::SlotId_t slotId;
        OscCardSet_t oscCardSet;
        PowerStatus_t cardStatus;
        uint32_t defective;
        uint32_t xtalError;
        dccstl::vector<ClockDomainStatus_t> clockDomainStatus;
    } OscCardStatus_t;

    typedef struct
    {
        uint8_t oscSwitchCntl0;
        uint8_t oscSwitchCntl1;
        SwitchoverPropagationMode_t propagationMode;
    } OscControlUnitStatus_t;

    typedef struct
    {
        uint8_t groupPowerAvailable;
        uint8_t outputsEnabled;
        dccstl::vector<OscControlUnitStatus_t> controlUnitStatus;
    } OscControlGroupStatus_t;

    typedef struct
    {
        dcc::SlotId_t slotId;
        OscSetMode_t setMode;
        uint8_t useOsc0;
        uint8_t useOsc1;
        dccstl::vector<OscControlGroupStatus_t> controlGroupStatus;
    } OscControlStatus_t;

    typedef struct
    {
        OscCardSet_t currentCardSet;
        OscSelectionMode_t currentSelectionMode;
        OscCardSet_t lastRequestedCardSet;
        OscSelectionMode_t lastRequestedSelectionMode;
        OscCardSet_t previousCardSet;
        timeval changedTime;
        uint8_t debugMode; /* 0: debug mode off, 1: debug mode on */
        dccstl::vector<OscCardStatus_t> oscCardStatus;
        OscControlStatus_t cardSet0Status;
        OscControlStatus_t cardSet1Status;
    } RedundantOscillatorStatus_t;

} // namespace dccosc

//std::string asString(const dcc::OscCardStatus_t& s);
//std::string asString(const dcc::OscCard_t& s);
//std::string asString(const dcc::PowerStatus_t& s);
std::string asString(const dccosc::OscSetMode_t& s);
//std::string asString(const dcc::SpreadingDirection_t& s);
//std::string asString(const dcc::SpreadingState_t& s);
//std::string asString(const dcc::PllStatus_t& s);
//std::string asString(const dcc::CrcInputStatus_t& s);
//std::string asString(const dcc::CrcStatus_t& s);
//std::string asString(const dcc::SwitchoverPropagationMode_t& s);
std::string asString(const dccosc::OscControlUnitStatus_t& s);
//std::string asString(const dcc::OscControlGroup_t& s);
/*
bool operator==(const dcc::OscCardStatus_t& s1, const dcc::OscCardStatus_t& s2);
bool operator!=(const dcc::OscCardStatus_t& s1, const dcc::OscCardStatus_t& s2);

bool operator==(const dcc::PllStatus_t& s1, const dcc::PllStatus_t& s2);
bool operator!=(const dcc::PllStatus_t& s1, const dcc::PllStatus_t& s2);
*/
bool operator==(const dccosc::SpreadingStatus_t& s1, const dccosc::SpreadingStatus_t& s2);
bool operator!=(const dccosc::SpreadingStatus_t& s1, const dccosc::SpreadingStatus_t& s2);

bool operator==(const dccosc::PllStatus_t& s1, const dccosc::PllStatus_t& s2);
bool operator!=(const dccosc::PllStatus_t& s1, const dccosc::PllStatus_t& s2);

bool operator==(const dccosc::CrcInputStatus_t& s1, const dccosc::CrcInputStatus_t& s2);
bool operator!=(const dccosc::CrcInputStatus_t& s1, const dccosc::CrcInputStatus_t& s2);

bool operator==(const dccosc::CrcStatus_t& s1, const dccosc::CrcStatus_t& s2);
bool operator!=(const dccosc::CrcStatus_t& s1, const dccosc::CrcStatus_t& s2);

bool operator==(const dccosc::ClockDomainStatus_t& s1, const dccosc::ClockDomainStatus_t& s2);
bool operator!=(const dccosc::ClockDomainStatus_t& s1, const dccosc::ClockDomainStatus_t& s2);

bool operator==(const dccosc::OscCardStatus_t& s1, const dccosc::OscCardStatus_t& s2);
bool operator!=(const dccosc::OscCardStatus_t& s1, const dccosc::OscCardStatus_t& s2);

bool operator==(const dccosc::OscControlUnitStatus_t& s1, const dccosc::OscControlUnitStatus_t& s2);
bool operator!=(const dccosc::OscControlUnitStatus_t& s1, const dccosc::OscControlUnitStatus_t& s2);

bool operator==(const dccosc::OscControlGroupStatus_t& s1, const dccosc::OscControlGroupStatus_t& s2);
bool operator!=(const dccosc::OscControlGroupStatus_t& s1, const dccosc::OscControlGroupStatus_t& s2);

bool operator==(const dccosc::OscControlStatus_t& s1, const dccosc::OscControlStatus_t& s2);
bool operator!=(const dccosc::OscControlStatus_t& s1, const dccosc::OscControlStatus_t& s2);

bool operator==(const dccosc::RedundantOscillatorStatus_t& s1, const dccosc::RedundantOscillatorStatus_t& s2);
bool operator!=(const dccosc::RedundantOscillatorStatus_t& s1, const dccosc::RedundantOscillatorStatus_t& s2);
/*
bool operator==(const dcc::CrcStatus_t& s1, const dcc::CrcStatus_t& s2);
bool operator!=(const dcc::CrcStatus_t& s1, const dcc::CrcStatus_t& s2);

bool operator==(const dcc::CrcInputStatus_t& s1, const dcc::CrcInputStatus_t& s2);
bool operator!=(const dcc::CrcInputStatus_t& s1, const dcc::CrcInputStatus_t& s2);

bool operator==(const dcc::OscControlGroup_t& s1, const dcc::OscControlGroup_t& s2);
bool operator!=(const dcc::OscControlGroup_t& s1, const dcc::OscControlGroup_t& s2);

bool operator==(const dcc::OscControlUnit_t& s1, const dcc::OscControlUnit_t& s2);
bool operator!=(const dcc::OscControlUnit_t& s1, const dcc::OscControlUnit_t& s2);
*/
/*
dcc::OscCardMode_t getModeForCard(const dcc::OscCard_t& f_oscCard, const dcc::OscCard_t& f_selectedOscCard, dcc::OscSelectionMode_t& f_oscSelectionMode);
dcc::OscCardStatus_t getSimOscCardStatus(const dcc::OscCard_t& f_card, const dcc::OscCardMode_t& f_cardMode);
*/
void getSimOscStatus(const dccosc::OscCardSet_t f_oscCardSet, const dccosc::OscSelectionMode_t f_oscSelectionMode, dccosc::RedundantOscillatorStatus_t& f_redOscStatus);

#endif // DCC_OSCILLATOR_STRUCTS_HPP

