// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/osc/osccErrdata.C 1.17.1.1 
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
/**
 *  @file osccErrdata.C
 *
 *  @brief Responsible for all error user data sections
 *
 *  Note that this file contains both the code to add the user
 *  data to an error log and to also parse and display that
 *  user data.
 *  Which part of the file goes where is
 *  controlled by a PARSER compile flag (defined in plugins/makefile)
 */

/**
 *  @page ChangeLogs Change Logs
 *  @section OSCCERRDATA_C osccErrdata.C
 *  @verbatim
 *
 *******************************************************************************
 * Track      User          Date           Description
 * --------   -----------   ------------   -------------------------------------
 * F950657    dkodihal      02/16/2015     Created
 * D956346    sangeet2      04/09/2015     Resolve beam errors
 * D991041    dkodihal      04/14/2016     Fixed bug in parsing code
 * D1010205   manichow      01/18/2017     FFDC enhancement
 * D1019538   manichow      04/13/2017     Reverted back the FFDC enhancement
 * F1049363   manichow      03/22/2018     Updated clock register info for p9
 * @endverbatim
 */


//******************************************************************************
// Includes
//******************************************************************************
#include <osccErrdata.H>

namespace OSCC
{

#ifndef PARSER

#include <yemtraceinterface.h>

/*****************************************************************************/
// OSCCUDC_clockCallout constructor
/*****************************************************************************/
OSCCUDC_clockCallout::OSCCUDC_clockCallout(const clockCalloutFFDC_t& i_data)
{
    iv_CompId = OSCC_COMP_ID;
    iv_Version = OSCC_USRDTL_SVC_CLOCK_CALLOUT_VER_1;
    iv_SubSection = OSCC_USRDTL_SVC_CLOCK_CALLOUT;

    ssize_t l_size = sizeof (uint32_t) + ((i_data.chipRegs.size()) * sizeof (chipRegFFDC_t));
    l_size +=
    sizeof (dccosc::OscCardSet_t) +
    sizeof (dccosc::OscSelectionMode_t) +
    sizeof (dccosc::OscCardSet_t) +
    sizeof (dccosc::OscSelectionMode_t);
    l_size += sizeof (uint32_t);
    for(uint32_t i = 0;
        i < ((i_data.pCardStatus)->oscCardStatus).size();
        ++i)
    {
        l_size += sizeof (dcc::SlotId_t) +
                  sizeof (dccosc::OscCardSet_t) +
                  sizeof (dccosc::PowerStatus_t);
        l_size += sizeof (uint32_t);
        for(uint32_t j = 0;
            j < ((i_data.pCardStatus)->oscCardStatus[i]).clockDomainStatus.size();
            ++j)
        {
            l_size += sizeof (dccosc::ClockDomain_t) +
                      sizeof (uint8_t) +
                      sizeof (dccosc::PllStatus_t) -
                      sizeof (dccosc::SpreadingStatus_t) +
                      sizeof (dccosc::CrcStatus_t);
        }
    }
    l_size += sizeof (dcc::SlotId_t) +
              sizeof (dccosc::OscSetMode_t) +
              sizeof (uint8_t) +
              sizeof (uint8_t);
    l_size += sizeof (uint32_t);
    for(uint32_t i = 0;         
        i < ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus.size();
        ++i)
    {
        l_size += sizeof (uint8_t) + sizeof (uint8_t);
        l_size += sizeof (uint32_t);
        for(uint32_t j = 0;
            j < ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[i].controlUnitStatus.size();
            ++j)
        {
            l_size += sizeof (uint8_t) + sizeof (uint8_t) + sizeof (dccosc::SwitchoverPropagationMode_t);
        }
    }
    l_size += sizeof (dcc::SlotId_t) +
              sizeof (dccosc::OscSetMode_t) +
              sizeof (uint8_t) +
              sizeof (uint8_t);
    l_size += sizeof (uint32_t);
    for(uint32_t i = 0;
        i < ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus.size();
        ++i)
    {
        l_size += sizeof (uint8_t) + sizeof (uint8_t);
        l_size += sizeof (uint32_t);
        for(uint32_t j = 0;
            j < ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[i].controlUnitStatus.size();
            ++j)
        {
            l_size += sizeof (uint8_t) + sizeof (uint8_t) + sizeof (dccosc::SwitchoverPropagationMode_t);
        }
    }

    // Allocate the data in an internal buffer
    void *l_dataBuf = allocUsrBuf(l_size);

    // Use UtilMem to easily serialize the data
    UtilMem l_mem(l_dataBuf,l_size);

    // Serialize whatever we want

    // No. of chips
    l_mem << i_data.chipRegs.size();

    // Registers for each chip
    for(uint32_t l_cnt = 0; l_cnt < i_data.chipRegs.size(); ++l_cnt)
    {
        l_mem << i_data.chipRegs[l_cnt].chipHUID
              << i_data.chipRegs[l_cnt].chipRID
              << i_data.chipRegs[l_cnt].chipEC
              << i_data.chipRegs[l_cnt].reg1007
              << i_data.chipRegs[l_cnt].reg2810
              << i_data.chipRegs[l_cnt].reg2813
              << i_data.chipRegs[l_cnt].reg2814
              << i_data.chipRegs[l_cnt].reg2815
              << i_data.chipRegs[l_cnt].reg2816
              << i_data.chipRegs[l_cnt].reg2804
              << i_data.chipRegs[l_cnt].reg281D0
              << i_data.chipRegs[l_cnt].reg281D1
              << i_data.chipRegs[l_cnt].reg281D2
              << i_data.chipRegs[l_cnt].reg281D3
              << i_data.chipRegs[l_cnt].reg281D4
              << i_data.chipRegs[l_cnt].reg1020019;
    }

    // Card information
    l_mem << (i_data.pCardStatus)->currentCardSet
          << (i_data.pCardStatus)->currentSelectionMode
          << (i_data.pCardStatus)->lastRequestedCardSet
          << (i_data.pCardStatus)->lastRequestedSelectionMode;

    // No. of cards
    l_mem << ((i_data.pCardStatus)->oscCardStatus).size();

    for(uint32_t l_cnt = 0;
        l_cnt < ((i_data.pCardStatus)->oscCardStatus).size();
        ++l_cnt)
    {
        // Card status
        l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).slotId
              << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).oscCardSet
              << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).cardStatus;

        // Clock domain info
        l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus.size();
        for(uint32_t l_dmnCnt = 0;
            l_dmnCnt < ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus.size();
            ++l_dmnCnt)
        {
            l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].clockDomain
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].steeringMode;

            // PLL status
            l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].pllStatus.speed
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].pllStatus.outputEnabled
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].pllStatus.inputLoss
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].pllStatus.lockLoss;

            // PLL registers
            for(uint32_t l_regCnt = 0; l_regCnt < DCC_OSC_PLL_NUM_REGISTERS; ++l_regCnt)
            {
                l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].pllStatus.registers[l_regCnt];
            }

            // CRC status
            l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.outputEnabled
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.crcBypass
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.lockLoss
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.feedbackLoss;

            //CRC input :  My PLL status
            l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.myPllStatus.inputLoss
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.myPllStatus.inputFreqFailure
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.myPllStatus.inputDisabled
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.myPllStatus.inputSelected;

            // CRC input : Other PLL status
            l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherPllStatus.inputLoss
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherPllStatus.inputFreqFailure
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherPllStatus.inputDisabled
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherPllStatus.inputSelected;

            // CRC input : Other CRC status
            l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherCrcStatus.inputLoss
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherCrcStatus.inputFreqFailure
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherCrcStatus.inputDisabled
                  << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.otherCrcStatus.inputSelected;

            // CRC registers
            for(uint32_t l_regCnt = 0; l_regCnt < DCC_OSC_CRC_NUM_REGISTERS; ++l_regCnt)
            {
                l_mem << ((i_data.pCardStatus)->oscCardStatus[l_cnt]).clockDomainStatus[l_dmnCnt].crcStatus.registers[l_regCnt];
            }
        }
    }

    // Card control information
    l_mem << ((i_data.pCardStatus)->cardSet0Status).slotId
          << ((i_data.pCardStatus)->cardSet0Status).setMode
          << ((i_data.pCardStatus)->cardSet0Status).useOsc0
          << ((i_data.pCardStatus)->cardSet0Status).useOsc1;
    l_mem << ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus.size();
    for(uint32_t l_grpCnt = 0;
        l_grpCnt < ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus.size();
        ++l_grpCnt)
    {
        l_mem << ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[l_grpCnt].groupPowerAvailable
              << ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[l_grpCnt].outputsEnabled
              << ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[l_grpCnt].controlUnitStatus.size();
        for(uint32_t l_unitCnt = 0;
            l_unitCnt < ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[l_grpCnt].controlUnitStatus.size();
            ++l_unitCnt)
        {
            l_mem << ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[l_grpCnt].controlUnitStatus[l_unitCnt].oscSwitchCntl0
                  << ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[l_grpCnt].controlUnitStatus[l_unitCnt].oscSwitchCntl1
                  << ((i_data.pCardStatus)->cardSet0Status).controlGroupStatus[l_grpCnt].controlUnitStatus[l_unitCnt].propagationMode;
        }
    }
    
    l_mem << ((i_data.pCardStatus)->cardSet1Status).slotId
          << ((i_data.pCardStatus)->cardSet1Status).setMode
          << ((i_data.pCardStatus)->cardSet1Status).useOsc0
          << ((i_data.pCardStatus)->cardSet1Status).useOsc1;
    l_mem << ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus.size();
    for(uint32_t l_grpCnt = 0;
        l_grpCnt < ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus.size();
        ++l_grpCnt)
    {
        l_mem << ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[l_grpCnt].groupPowerAvailable
              << ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[l_grpCnt].outputsEnabled
              << ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[l_grpCnt].controlUnitStatus.size();
        for(uint32_t l_unitCnt = 0;
            l_unitCnt < ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[l_grpCnt].controlUnitStatus.size();
            ++l_unitCnt)
        {
            l_mem << ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[l_grpCnt].controlUnitStatus[l_unitCnt].oscSwitchCntl0
                  << ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[l_grpCnt].controlUnitStatus[l_unitCnt].oscSwitchCntl1
                  << ((i_data.pCardStatus)->cardSet1Status).controlGroupStatus[l_grpCnt].controlUnitStatus[l_unitCnt].propagationMode;
        }
    }

    // Check for error during utilMem operation
    errlHndl_t l_errHdl = l_mem.getLastError();
    if(l_errHdl)
    {
        l_errHdl->commit(OSCC_COMP_ID, ERRL_ACTION_REPORT);
        delete l_errHdl;
        l_errHdl = NULL;
    }
}
/*****************************************************************************/
// OSCCUDC_clockCallout destructor
/*****************************************************************************/
OSCCUDC_clockCallout::~OSCCUDC_clockCallout(){}

#else //PARSER

/*****************************************************************************/
// OSCCUDP_clockCallout parser
/*****************************************************************************/
void OSCCUDP_clockCallout::parse(
    errlver_t i_version,
    ErrlUsrParser & i_parser,
    const void * i_pBuffer,
    const uint32_t i_buflen) const
{
    UtilMem l_mem((void *)i_pBuffer,i_buflen);

    i_parser.PrintBlank();
    i_parser.PrintHeading("OSCC CP Sense Information");
    i_parser.PrintBlank();

    uint32_t l_chipHUID;
    uint32_t l_chipRID = 0;
    uint32_t l_chipEC = 0;
    uint32_t l_reg1007 = 0;
    uint32_t l_reg2810 = 0;
    uint32_t l_reg2813 = 0;
    uint32_t l_reg2814 = 0;
    uint32_t l_reg2815 = 0;
    uint32_t l_reg2816 = 0;
    uint32_t l_reg2804 = 0;
    uint32_t l_reg281D0 = 0;
    uint32_t l_reg281D1 = 0;
    uint32_t l_reg281D2 = 0;
    uint32_t l_reg281D3 = 0;
    uint32_t l_reg281D4 = 0;
    uint32_t l_reg1020019 = 0;
    uint32_t l_noOfChips = 0;
    uint8_t l_reg = 0;

    l_mem >> l_noOfChips;
    for(uint32_t l_cnt = 0; l_cnt < l_noOfChips; ++l_cnt)
    {
        l_mem >> l_chipHUID
              >> l_chipRID
              >> l_chipEC
              >> l_reg1007
              >> l_reg2810
              >> l_reg2813
              >> l_reg2814
              >> l_reg2815
              >> l_reg2816
              >> l_reg2804
              >> l_reg281D0
              >> l_reg281D1
              >> l_reg281D2
              >> l_reg281D3
              >> l_reg281D4
              >> l_reg1020019;

        i_parser.PrintBlank();
        i_parser.PrintNumber("CP HUID", "0x%.8X", l_chipHUID);
        i_parser.PrintNumber("CP RID", "0x%.8X", l_chipRID);
        i_parser.PrintNumber("CP EC", "0x%.8X", l_chipEC);
        i_parser.PrintNumber("CP Reg 1007", "0x%.8X", l_reg1007);
        i_parser.PrintNumber("CP Reg 2810", "0x%.8X", l_reg2810);
        i_parser.PrintNumber("CP Reg 2813", "0x%.8X", l_reg2813);
        i_parser.PrintNumber("CP Reg 2814", "0x%.8X", l_reg2814);
        i_parser.PrintNumber("CP Reg 2815", "0x%.8X", l_reg2815);
        i_parser.PrintNumber("CP Reg 2816", "0x%.8X", l_reg2816);
        i_parser.PrintNumber("CP Reg 2804", "0x%.8X", l_reg2804);
        i_parser.PrintNumber("CP Reg 281D0", "0x%.8X", l_reg281D0);
        i_parser.PrintNumber("CP Reg 281D1", "0x%.8X", l_reg281D1);
        i_parser.PrintNumber("CP Reg 281D2", "0x%.8X", l_reg281D2);
        i_parser.PrintNumber("CP Reg 281D3", "0x%.8X", l_reg281D3);
        i_parser.PrintNumber("CP Reg 281D4", "0x%.8X", l_reg281D4);
        i_parser.PrintNumber("CP Reg 1020019", "0x%.8X", l_reg1020019);
    }

    i_parser.PrintBlank();
    i_parser.PrintHeading("OSCC Card Information");
    i_parser.PrintBlank();

    dccosc::OscCardSet_t l_currentCardSet = dccosc::e_OscUnknown;
    dccosc::OscSelectionMode_t l_currentSelectionMode = dccosc::e_OscSelectionMode_Unknown;
    dccosc::OscCardSet_t l_lastRequestedCardSet = dccosc::e_OscUnknown;
    dccosc::OscSelectionMode_t l_lastRequestedSelectionMode = dccosc::e_OscSelectionMode_Unknown;

    l_mem >> l_currentCardSet
          >> l_currentSelectionMode
          >> l_lastRequestedCardSet
          >> l_lastRequestedSelectionMode;
    i_parser.PrintNumber("Current Card Group", "0x%.8X", ntohl(l_currentCardSet));
    i_parser.PrintNumber("Current Selection Mode", "%d", ntohl(l_currentSelectionMode));
    i_parser.PrintNumber("Last Requested Card Group", "0x%.8X", ntohl(l_lastRequestedCardSet));
    i_parser.PrintNumber("Last requested Selection Mode", "%d", ntohl(l_lastRequestedSelectionMode));

    uint32_t l_noOfCards = 0;
    uint32_t l_noOfDomains = 0;
    dcc::SlotId_t l_slotId = 0;
    dccosc::OscCardSet_t l_oscCardSet = dccosc::e_OscUnknown;
    dccosc::PowerStatus_t l_cardStatus = dccosc::e_cardUnplugged;
    std::string l_powerState;
    std::string l_clockDomain;
    dccosc::ClockDomain_t l_domain = dccosc::e_ClockDomain_t_Undefined;
    uint8_t l_steeringMode = 0;
    uint32_t l_pllSpeed = 0;
    uint8_t l_pllOpEnabled = 0;
    uint8_t l_pllIpLoss = 0;
    uint8_t l_pllLockLoss = 0;
    uint8_t l_crcOpEnabled = 0;
    uint8_t l_crcBypass = 0;
    uint8_t l_crcLockLoss = 0;
    uint8_t l_crcFeedbackLoss = 0;
    uint8_t l_crcIpLoss = 0;
    uint8_t l_crcIpFreqFail = 0;
    uint8_t l_crcIpDisabled = 0;
    uint8_t l_crcIpSelected = 0;

    l_mem >> l_noOfCards;
    for(uint32_t l_cardCnt = 0; l_cardCnt < l_noOfCards; ++l_cardCnt)
    {
        l_mem >> l_slotId
              >> l_oscCardSet
              >> l_cardStatus;
        if(dccosc::e_cardUnplugged == ntohl(l_cardStatus))
        {
            //continue; //Ignore unplugged card slots
        }
        switch(ntohl(l_cardStatus))
        {
            case dccosc::e_cardPowerOn:
                l_powerState = "Powered on";
                break;

            case dccosc::e_cardPowerOff:
                l_powerState = "Powered off";
                break;

            case dccosc::e_cardPowerFail:
                l_powerState = "Power failure";
                break;

            default:
            /*Change to suppress Beam error:
              Default case should always be the last option in case statement.
              As of now commenting out "case dccosc::e_cardUnplugged" as the
              action taken is same as that of default case.
              Can be uncommented when a different action is needed.*/
            //case dccosc::e_cardUnplugged:
                l_powerState = "Card disabled";
                break;
        }

        i_parser.PrintBlank();
        i_parser.PrintHeading("OSCC Card Status");
        i_parser.PrintBlank();

        i_parser.PrintNumber("Slot id", "0x%.8X", l_slotId);
        i_parser.PrintNumber("Group", "0x%.8X", ntohl(l_oscCardSet));
        i_parser.PrintString("Power status", l_powerState.c_str());

        l_mem >> l_noOfDomains;
        for(uint32_t l_dmnCnt = 0; l_dmnCnt < l_noOfDomains; ++l_dmnCnt)
        {
            i_parser.PrintBlank();

            l_mem >> l_domain;
            switch(ntohl(l_domain))
            {
                case dccosc::e_cp:
                    l_clockDomain = "Processor";
                    break;

                case dccosc::e_optic:
                    l_clockDomain = "Optic";
                    break;

                case dccosc::e_gx:
                    l_clockDomain = "Gx";
                    break;

                case dccosc::e_mem:
                    l_clockDomain = "Memory";
                    break;

                case dccosc::e_mem_1:
                    l_clockDomain = "Memory drawer 1";
                    break;

                case dccosc::e_mem_2:
                    l_clockDomain = "Memory drawer 2";
                    break;

                case dccosc::e_mem_3:
                    l_clockDomain = "Memory drawer 3";
                    break;

                case dccosc::e_mem_4:
                    l_clockDomain = "Memory drawer 4";
                    break;

                case dccosc::e_mem_5:
                    l_clockDomain = "Memory drawer 5";
                    break;

                case dccosc::e_ClockDomain_t_Undefined:
                default:
                    l_clockDomain = "Unknown";
                    break;
            }
            i_parser.PrintString("Clock Domain", l_clockDomain.c_str());

            l_mem >> l_steeringMode;
            i_parser.PrintNumber("Steering mode", "0x%.2X", l_steeringMode);

            l_mem >> l_pllSpeed
                  >> l_pllOpEnabled
                  >> l_pllIpLoss
                  >> l_pllLockLoss;
            i_parser.PrintNumber("PLL speed", "0x%.8X", l_pllSpeed);
            i_parser.PrintNumber("PLL output enabled", "0x%.2X", l_pllOpEnabled);
            i_parser.PrintNumber("PLL input loss", "0x%.2X", l_pllIpLoss);
            i_parser.PrintNumber("PLL lock loss", "0x%.2X", l_pllLockLoss);
            for(uint32_t l_regCnt = 0; l_regCnt < DCC_OSC_PLL_NUM_REGISTERS; ++l_regCnt)
            {
                l_mem >> l_reg;
                i_parser.PrintNumber("PLL register value", "0x%.8X", l_reg);
            }

            l_mem >> l_crcOpEnabled
                  >> l_crcBypass
                  >> l_crcLockLoss
                  >> l_crcFeedbackLoss;
            i_parser.PrintNumber("CRC output enabled", "0x%.2X", l_crcOpEnabled);
            i_parser.PrintNumber("CRC bypass", "0x%.2X", l_crcBypass);
            i_parser.PrintNumber("CRC lock loss", "0x%.2X", l_crcLockLoss);
            i_parser.PrintNumber("CRC status, feedback loss", "0x%.2X", l_crcFeedbackLoss);

            l_mem >> l_crcIpLoss
                  >> l_crcIpFreqFail
                  >> l_crcIpDisabled
                  >> l_crcIpSelected;
            i_parser.PrintNumber("CRC myPLL I/P loss", "0x%.2X", l_crcIpLoss);
            i_parser.PrintNumber("CRC myPLL I/P frequency fail", "0x%.2X", l_crcIpFreqFail);
            i_parser.PrintNumber("CRC myPLL I/P disabled", "0x%.2X", l_crcIpDisabled);
            i_parser.PrintNumber("CRC myPLL I/P selected", "0x%.2X", l_crcIpSelected);

            l_mem >> l_crcIpLoss
                  >> l_crcIpFreqFail
                  >> l_crcIpDisabled
                  >> l_crcIpSelected;
            i_parser.PrintNumber("CRC otherPLL I/P loss", "0x%.2X", l_crcIpLoss);
            i_parser.PrintNumber("CRC otherPLL I/P frequency fail", "0x%.2X", l_crcIpFreqFail);
            i_parser.PrintNumber("CRC otherPLL I/P disabled", "0x%.2X", l_crcIpDisabled);
            i_parser.PrintNumber("CRC otherPLL I/P selected", "0x%.2X", l_crcIpSelected);

            l_mem >> l_crcIpLoss
                  >> l_crcIpFreqFail
                  >> l_crcIpDisabled
                  >> l_crcIpSelected;
            i_parser.PrintNumber("CRC otherCRC I/P loss", "0x%.2X", l_crcIpLoss);
            i_parser.PrintNumber("CRC otherCRC I/P frequency fail", "0x%.2X", l_crcIpFreqFail);
            i_parser.PrintNumber("CRC otherCRC I/P disabled", "0x%.2X", l_crcIpDisabled);
            i_parser.PrintNumber("CRC otherCRC I/P selected", "0x%.2X", l_crcIpSelected);

            for(uint32_t l_regCnt = 0; l_regCnt < DCC_OSC_CRC_NUM_REGISTERS; ++l_regCnt)
            {
                l_mem >> l_reg;
                i_parser.PrintNumber("CRC register value", "0x%.8X", l_reg);
            }
        }
    }

    dccosc::OscSetMode_t l_setMode = dccosc::e_initial;
    uint8_t l_useOsc0 = 0;
    uint8_t l_useOsc1 = 0;
    uint32_t l_noOfCtrlGrps = 0;
    uint8_t l_groupPowerAvailable = 0;
    uint8_t l_outputsEnabled = 0;
    uint32_t l_noOfCtrlUnits = 0;
    uint8_t l_oscSwitchCntl0 = 0;
    uint8_t l_oscSwitchCntl1 = 0;
    dccosc::SwitchoverPropagationMode_t l_propagationMode = dccosc::e_DisablePropagation;
    std::string l_prop;

    i_parser.PrintBlank();
    i_parser.PrintHeading("OSCC Card Set 0 Status");
    i_parser.PrintBlank();

    l_mem >> l_slotId
          >> l_setMode
          >> l_useOsc0
          >> l_useOsc1;
    i_parser.PrintNumber("Slot id", "0x%.8X", l_slotId);
    i_parser.PrintNumber("Set mode", "0x%.8X", ntohl(l_setMode));
    i_parser.PrintNumber("Use OSC 0", "0x%.2X", l_useOsc0);
    i_parser.PrintNumber("Use OSC 1", "0x%.2X", l_useOsc1);

    l_mem >> l_noOfCtrlGrps;
    for(uint32_t l_grpCnt = 0; l_grpCnt < l_noOfCtrlGrps; ++l_grpCnt)
    {
        i_parser.PrintBlank();
        i_parser.PrintNumber("Control group", "%d", l_grpCnt+1);
        l_mem >> l_groupPowerAvailable >> l_outputsEnabled;
        i_parser.PrintNumber("Power available", "0x%.8X", l_groupPowerAvailable);
        i_parser.PrintNumber("Outputs enabled", "0x%.8X", l_outputsEnabled);

        l_mem >> l_noOfCtrlUnits;
        for(uint32_t l_unitCnt = 0; l_unitCnt < l_noOfCtrlUnits; ++l_unitCnt)
        {
            i_parser.PrintNumber("Control unit", "%d", l_unitCnt+1);
            l_mem >> l_oscSwitchCntl0 >> l_oscSwitchCntl1 >> l_propagationMode;
            i_parser.PrintNumber("Switch control 0", "0x%.2X", l_oscSwitchCntl0);
            i_parser.PrintNumber("Switch control 1", "0x%.2X", l_oscSwitchCntl1);
            switch(ntohl(l_propagationMode))
            {
                case dccosc::e_DisablePropagation:
                    l_prop = "disabled";
                    break;

                case dccosc::e_EnablePropagation:
                    l_prop = "enabled";
                    break;

                default:
                    l_prop = "unknown";
                    break;
            }
            i_parser.PrintString("Propagation", l_prop.c_str());
        }
    }

    i_parser.PrintBlank();
    i_parser.PrintHeading("OSCC Card Set 1 Status");
    i_parser.PrintBlank();

    l_mem >> l_slotId
          >> l_setMode
          >> l_useOsc0
          >> l_useOsc1;
    i_parser.PrintNumber("Slot id", "0x%.8X", l_slotId);
    i_parser.PrintNumber("Set mode", "0x%.8X", ntohl(l_setMode));
    i_parser.PrintNumber("Use OSC 0", "0x%.2X", l_useOsc0);
    i_parser.PrintNumber("Use OSC 1", "0x%.2X", l_useOsc1);

    do{
    if(!l_useOsc0 && !l_useOsc1)
        break;
    l_mem >> l_noOfCtrlGrps;
    for(uint32_t l_grpCnt = 0; l_grpCnt < l_noOfCtrlGrps; ++l_grpCnt)
    {
        i_parser.PrintBlank();
        i_parser.PrintNumber("Control group", "%d", l_grpCnt+1);
        l_mem >> l_groupPowerAvailable >> l_outputsEnabled;
        i_parser.PrintNumber("Power available", "0x%.8X", l_groupPowerAvailable);
        i_parser.PrintNumber("Outputs enabled", "0x%.8X", l_outputsEnabled);

        l_mem >> l_noOfCtrlUnits;
        for(uint32_t l_unitCnt = 0; l_unitCnt < l_noOfCtrlUnits; ++l_unitCnt)
        {
            i_parser.PrintNumber("Control unit", "%d", l_unitCnt+1);
            l_mem >> l_oscSwitchCntl0 >> l_oscSwitchCntl1 >> l_propagationMode;
            i_parser.PrintNumber("Switch control 0", "0x%.2X", l_oscSwitchCntl0);
            i_parser.PrintNumber("Switch control 1", "0x%.2X", l_oscSwitchCntl1);
            switch(ntohl(l_propagationMode))
            {
                case dccosc::e_DisablePropagation:
                    l_prop = "disabled";
                    break;

                case dccosc::e_EnablePropagation:
                    l_prop = "enabled";
                    break;

                default:
                    l_prop = "unknown";
                    break;
            }
            i_parser.PrintString("Propagation", l_prop.c_str());
        }
    }
    }while(0);

#if 0
    // Be sure we didn't get an error
    errlHndl_t l_errHdl = l_mem.getLastError();
    if(l_errHdl)
    {
        i_parser.PrintHeading("Error log returned by UtilMem when trying to read in user data");
        l_errHdl->commit(OSCC_COMP_ID, ERRL_ACTION_REPORT);
        delete l_errHdl;
        l_errHdl = NULL;
    }
#endif
}
OSCCUDP_clockCallout::OSCCUDP_clockCallout(){}
OSCCUDP_clockCallout::~OSCCUDP_clockCallout(){}

/*****************************************************************************/
// osccErrlUserDataParserFactory constructor
/*****************************************************************************/
osccErrlUserDataParserFactory::osccErrlUserDataParserFactory()
{
    // Register all parsers with the factory
    Register<OSCCUDP_clockCallout>
            (OSCC_USRDTL_SVC_CLOCK_CALLOUT) == true;
}

#endif //PARSER

} //namespace OSCC
