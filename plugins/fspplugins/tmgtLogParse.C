// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/plugins/tmgtLogParse.C 1.23.1.36 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2008,2017 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC:
// $Source: fips760 fsp/src/tmgt/fsp/plugins/tmgtLogParse.C 1$


#include <tmgtutility.H>
#include <errlusrparser.H>
#include <errlplugins.H>
#include <tmgtLogParse.H>
#include <iostream>
#include <cstring>
#include <tmgt_elog_parser.H>
#include <tmgt_pcap_tables.H>
#include <assert.h>

// Create a tmgtErrlUsrDataParserFactory object
static tmgtErrlUsrDataParserFactory G_factory;
// In order to fix errl utility failed to load library due to that it included tmgtutility.C into this library
#ifndef _X86NFP
tracDesc_t g_tmgtTraceDesc;
#endif

/* Function Specification *********************************************************************************************************/
/*                                                                                                                                */
/*  Name:       TmgtLogDataParse                                                                                                  */
/*                                                                                                                                */
/*  Function:   Called by elog when there is an SPCN error log to parse                                                           */
/*                                                                                                                                */
/*  References: Log Viewer Design (dept CMAA)                                                                                     */
/*                                                                                                                                */
/*  Parameters:                                                                                                                   */
/*         i_parser     Object used to print the output                                                                           */
/*         i_buffer     Pointer to data                                                                                           */
/*         i_buflen     Length of data                                                                                            */
/*         i_ver        Sub-section Version                                                                                       */
/*         i_sst        Sub-section Type                                                                                          */
/*                                                                                                                                */
/*  Returns:                                                                                                                      */
/*         true         if data was parsed                                                                                        */
/*         false        unable to parse data                                                                                      */
/*                                                                                                                                */
/*  Notes: To test new function, mk and then copy the libE-2600.so file to /nfs/lib/ and then use errl like normal                */
/*                                                                                                                                */
/* End Function Specification *****************************************************************************************************/
/******************************************************************************/
// Plugin entry point
/******************************************************************************/
extern "C" bool TmgtLogDataParse(ErrlUsrParser & i_parser,   // put parsed results
                                 void * i_buffer,         // data to parse
                                 uint32_t i_buflen,          // length of data
                                 errlver_t i_ver,        // version of data
                                 errlsubsec_t i_sst) // subsection of data
{
    bool l_rc = false;

    // Use the factory to create the correct UsrDtlDataParser object
    util::ErrlUsrDataParser *l_pUsrDtlDataParser = G_factory.Create(i_sst);

    if (l_pUsrDtlDataParser)
    {
        l_rc = true;

        // Parse the data
        l_pUsrDtlDataParser->parse(i_ver, i_parser, i_buffer, i_buflen);
    }

    return l_rc;
}
/*****************************************************************************/
// tmgtErrlUsrDataParserFactory constructor
/*****************************************************************************/
tmgtErrlUsrDataParserFactory::tmgtErrlUsrDataParserFactory()
{
    // Register TMGT_ENERGYSCALE_DATA_TYPE parser
    if (Register<tmgtENERGYSCALE_DATA_TYPE>(TMGT_ENERGYSCALE_DATA_TYPE) != true)
    {
        std::cerr << "tmgtErrlUsrDataParserFactory: failed to register TMGT_ENERGYSCALE_DATA_TYPE parser";
        assert(false);
    }
    // Register TMGT_OCC_ELOG_DATA_TYPE parser
    if (Register<tmgtOCC_ELOG_DATA_TYPE>(TMGT_OCC_ELOG_DATA_TYPE) != true)
    {
        std::cerr << "tmgtErrlUsrDataParserFactory: failed to register TMGT_OCC_ELOG_DATA_TYPE parser";
        assert(false);
    }
    // Register TMGT_MSG_DATA_TRUNCATED parser
    if (Register<tmgtMSG_DATA_TRUNCATED>(TMGT_MSG_DATA_TRUNCATED) != true)
    {
        std::cerr << "tmgtErrlUsrDataParserFactory: failed to register TMGT_MSG_DATA_TRUNCATED parser";
        assert(false);
    }
    // Register TMGT_ELOG_TYPE_TOIF_RESET parser
    if (Register<tmgtTMGT_ELOG_TYPE_TOIF_RESET>(TMGT_ELOG_TYPE_TOIF_RESET) != true)
    {
        std::cerr << "tmgtErrlUsrDataParserFactory: failed to register TMGT_ELOG_TYPE_TOIF_RESET parser";
        assert(false);
    }
    // Register TMGT_ELOG_TYPE_OCC_RESET parser
    if (Register<tmgtTMGT_ELOG_TYPE_OCC_RESET>(TMGT_ELOG_TYPE_OCC_RESET) != true)
    {
        std::cerr << "tmgtErrlUsrDataParserFactory: failed to register TMGT_ELOG_TYPE_OCC_RESET parser";
        assert(false);
    }
    // Register TMGT_ELOG_TYPE_PCAP_DATA parser
    if (Register<tmgtTMGT_ELOG_TYPE_PCAP_DATA>(TMGT_ELOG_TYPE_PCAP_DATA) != true)
    {
        std::cerr << "tmgtErrlUsrDataParserFactory: failed to register TMGT_ELOG_TYPE_PCAP_DATA parser";
        assert(false);
    }
    // Register TMGT_ELOG_TYPE_THERMAL_DATA parser
    if (Register<tmgtTMGT_ELOG_TYPE_THERMAL_DATA>(TMGT_ELOG_TYPE_THERMAL_DATA) != true)
    {
        std::cerr << "tmgtErrlUsrDataParserFactory: failed to register TMGT_ELOG_TYPE_THERMAL_DATA parser";
        assert(false);
    }
}
/*****************************************************************************/
// tmgtErrlUsrDataParserFactory destructor
/*****************************************************************************/
tmgtErrlUsrDataParserFactory::~tmgtErrlUsrDataParserFactory()
{
    util::ErrlUsrDataParser *l_pUsrDtlDataParser = NULL;
    l_pUsrDtlDataParser = Create(TMGT_ENERGYSCALE_DATA_TYPE);
    if (l_pUsrDtlDataParser)
    {
        // Delete the TMGT_ENERGYSCALE_DATA_TYPE UsrDtlData object to prevent memory leak
        delete l_pUsrDtlDataParser;
        Unregister(TMGT_ENERGYSCALE_DATA_TYPE);
    }
    l_pUsrDtlDataParser = Create(TMGT_OCC_ELOG_DATA_TYPE);
    if (l_pUsrDtlDataParser)
    {
        // Delete the TMGT_OCC_ELOG_DATA_TYPE UsrDtlData object to prevent memory leak
        delete l_pUsrDtlDataParser;
        Unregister(TMGT_OCC_ELOG_DATA_TYPE);
    }
    l_pUsrDtlDataParser = Create(TMGT_MSG_DATA_TRUNCATED);
    if (l_pUsrDtlDataParser)
    {
        // Delete the TMGT_MSG_DATA_TRUNCATED UsrDtlData object to prevent memory leak
        delete l_pUsrDtlDataParser;
        Unregister(TMGT_MSG_DATA_TRUNCATED);
    }
}
/*****************************************************************************/
// TMGT_ENERGYSCALE_DATA_TYPE parser
/*****************************************************************************/
void tmgtENERGYSCALE_DATA_TYPE::parse(errlver_t i_ver,
                                      ErrlUsrParser &i_parser,
                                      const void *i_buffer,
                                      const uint32_t i_buflen) const
{

    if ((i_buffer != NULL) && (i_buflen >= 11))
    {
        uint8_t *l_data = (uint8_t*)i_buffer;
        uint16_t l_freq = 0;
        uint16_t l_index = 0;
        char l_string[64];

        // Sub-Section Type 0 => EnergyScale data

        // Modes
        sprintf(l_string, "0x%02X  (%s)", l_data[l_index], mode_string(tmgtSysPwrMode(l_data[l_index])));
        i_parser.PrintString("System Required Mode", l_string);
        l_index++;
        sprintf(l_string, "0x%02X  (%s)", l_data[l_index], mode_string(tmgtSysPwrMode(l_data[l_index])));
        i_parser.PrintString("Target Mode", l_string);
        l_index++;
        sprintf(l_string, "0x%02X  (%s)", l_data[l_index], mode_string(tmgtSysPwrMode(l_data[l_index])));
        i_parser.PrintString("Customer Mode", l_string);
        l_index++;
        sprintf(l_string, "0x%02X  (%s)", l_data[l_index], mode_string(tmgtSysPwrMode(l_data[l_index])));
        i_parser.PrintString("Current Customer Setting", l_string);
        l_index++;
        uint32_t l_time = UINT32_GET(&l_data[l_index]) / 60;
        l_index += 4;
        if (0 == l_time)
        {
            i_parser.PrintString("Time in Mode", "Unavailable");
        }
        else
        {
            if (l_time < 4*60) // < 4 hours?
            {
                i_parser.PrintNumber("Time in Mode (minutes)", "%d", l_time);
            }
            else if (l_time < 4*24*60) // < 4 days?
            {
                l_time /= 60;
                i_parser.PrintNumber("Time in Mode (hours)", "%d", l_time);
            }
            else
            {
                l_time /= 24*60;
                i_parser.PrintNumber("Time in Mode (days)", "%d", l_time);
            }
        }

        // Frequencies
        l_freq = UINT16_GET(&l_data[l_index]);
        if (l_freq != 0)
        {
            i_parser.PrintNumber("Min Frequency", "%d MHz", l_freq);
        }
        else
        {
            i_parser.PrintString("Min Frequency", "0 MHz  (undefined until IPL)");
        }
        l_index += 2;

        l_freq = UINT16_GET(&l_data[l_index]);
        if (l_freq != 0)
        {
            i_parser.PrintNumber("Power Save Frequency", "%d MHz", l_freq);
        }
        else
        {
            i_parser.PrintString("Power Save Frequency", "0 MHz  (undefined until IPL)");
        }
        l_index += 2;

        l_freq = UINT16_GET(&l_data[l_index]);
        if (l_freq != 0)
        {
            i_parser.PrintNumber("Nominal Frequency", "%d MHz", l_freq);
        }
        else
        {
            i_parser.PrintString("Nominal Frequency", "0 MHz  (undefined until IPL)");
        }
        l_index += 2;

        l_freq = UINT16_GET(&l_data[l_index]);
        if (l_freq != 0)
        {
            i_parser.PrintNumber("Turbo Frequency", "%d MHz", l_freq);
        }
        else
        {
            i_parser.PrintString("Turbo Frequency", "0 MHz");
        }
        l_index += 2;

        l_freq = UINT16_GET(&l_data[l_index]);
        if (l_freq != 0)
        {
            i_parser.PrintNumber("Ultra Turbo Frequency", "%d MHz", l_freq);
        }
        else
        {
            i_parser.PrintString("Ultra Turbo Frequency", "0 MHz");
        }
        l_index += 2;

        l_freq = UINT16_GET(&l_data[l_index]);
        if (l_freq != 0)
        {
            i_parser.PrintNumber("FFO Frequency", "%d MHz", l_freq);
        }
        l_index += 2;

        i_parser.PrintString("OCC State",
                             state_string((occStateId)l_data[l_index++]) );

        const bool l_cappingEnabled = l_data[l_index++];
        i_parser.PrintBool("Power Capping Enabled", l_cappingEnabled);

        i_parser.PrintNumber("Current Power Cap", "%d W", UINT16_GET(&l_data[l_index]));
        l_index += 2;

        const bool l_opalEnabled = l_data[l_index++];
        i_parser.PrintString("Firmware Configuration", l_opalEnabled ? "OPAL" : "PowerVM");

        if (i_buflen > l_index)
        {
            // Note: errl will pads the user data to a word boundary
            i_parser.PrintHeading("Additional Data");
            i_parser.PrintHexDump(&l_data[l_index], i_buflen - l_index);
        }
    }
    // else data too short or unknown type (just dumps hex)
} // TmgtLogDataParse ( )

/*****************************************************************************/
// TMGT_OCC_ELOG_DATA_TYPE parser
/*****************************************************************************/
void tmgtOCC_ELOG_DATA_TYPE::parse(errlver_t i_ver,
                                   ErrlUsrParser &i_parser,
                                   const void *i_buffer,
                                   const uint32_t i_buflen) const
{

    if ((i_buffer != NULL) && (i_buflen >= 11))
    {
        uint8_t *l_data = (uint8_t*)i_buffer;
        uint16_t l_index = 0;
        char l_string[64];

        // Sub-Section Type 0 => EnergyScale data
        sprintf(l_string, "0x%02X", l_data[l_index]);
        i_parser.PrintString("Node number", l_string);
        l_index++;
        sprintf(l_string, "0x%02X", l_data[l_index]);
        i_parser.PrintString("TPMD number", l_string);
        l_index++;
        sprintf(l_string, "%s", state_string((occStateId)l_data[l_index]));
        i_parser.PrintString("OCC state", l_string);
        l_index++;

        sprintf(l_string, "{%i,%i}", l_data[l_index], l_data[l_index+1]);
        i_parser.PrintString("Reset count", l_string);
        l_index += 2;

        sprintf(l_string, "0x%02X", l_data[l_index]);
        i_parser.PrintString("Unthrottle bit", l_string);
        l_index++;

        i_parser.PrintString("OCC poll response", "11 bytes");

        sprintf(l_string, "0x%02X, (poll response byte 0)", l_data[l_index]);
        i_parser.PrintString("Status", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 1)", l_data[l_index]);
        i_parser.PrintString("Configuration Data Needed", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 2)", l_data[l_index]);
        i_parser.PrintString("Current OCC State", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 3)", l_data[l_index]);
        i_parser.PrintString("Current system power management mode", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 4)", l_data[l_index]);
        i_parser.PrintString("Reserved", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 5)", l_data[l_index]);
        i_parser.PrintString("OCC state change request", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 6)", l_data[l_index]);
        i_parser.PrintString("Error log ID", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 7)", l_data[l_index]);
        i_parser.PrintString("Extended status", l_string);
        l_index++;

        sprintf(l_string, "0x%02X, (poll response byte 8)", l_data[l_index]);
        i_parser.PrintString("DCA reset request", l_string);
        l_index++;

        sprintf(l_string, "0x%02X%02X, (poll response byte 9-10)", l_data[l_index],l_data[l_index+1]);
        i_parser.PrintString("Reserved", l_string);
        l_index+=2;
    }
    // else data too short or unknown type (just dumps hex)
} // end tmgtParseTtif()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       tmgtParseClientMsg                                            */
/*                                                                            */
/*  Function:   Parse messages from TMGT/TTIF clients to the servers.         */
/*              Message types are defined in tmgtmsg.H and tmgt_ttif_msg.H    */
/*                                                                            */
/* End Function Specification *************************************************/
/*****************************************************************************/
// TMGT_MSG_DATA_TRUNCATED parser
/*****************************************************************************/
void tmgtMSG_DATA_TRUNCATED::parse(errlver_t i_ver,
                                   ErrlUsrParser &i_parser,
                                   const void *i_buffer,
                                   const uint32_t i_buflen) const
{

    if ((i_buffer != NULL) && (i_buflen >= 4))
    {
        const uint8_t *l_data = (uint8_t*)i_buffer;
        uint16_t l_index = 0;

        // Sub-Section Type 0 => EnergyScale data
        i_parser.PrintNumber("Message Type", "0x%04X", UINT16_GET(&l_data[l_index]));
        l_index += 2;
        i_parser.PrintNumber("Data Length", "%d", UINT16_GET(&l_data[l_index]));
        l_index += 2;
        if (l_data[l_index] != 0xFF)
        {
            i_parser.PrintNumber("OCC Instance", "%d", l_data[l_index]);
        }
        else
        {
            i_parser.PrintString("OCC Instance", "Master");
        }
        l_index++;
        i_parser.PrintNumber("Node", "%d", l_data[l_index++]);
        const char * l_threadName = "UNKNOWN";
        switch(l_data[l_index++])
        {
            case TMGT_THREAD_MAIN:
                l_threadName = "main";
                break;
            case TMGT_THREAD_ENERGYSCALE:
                l_threadName = "EnergyScale";
                break;
            case TMGT_THREAD_TOIF:
                l_threadName = "TOIF";
                break;
        }
        i_parser.PrintString("Thread", l_threadName);
        i_parser.PrintNumber("Reserved", "0x%02X", l_data[l_index++]);

        if (i_buflen > l_index)
        {
            // Note: errl will pads the user data to a word boundary
            i_parser.PrintHeading("Data (may be truncated)");
            i_parser.PrintHexDump(&l_data[l_index], i_buflen - l_index);
        }
    }
    // else data too short or unknown type (just dumps hex)
} // end tmgtParseClientMsg()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       parse TMGT_ELOG_TYPE_TOIF_RESET                               */
/*                                                                            */
/* End Function Specification *************************************************/
void tmgtTMGT_ELOG_TYPE_TOIF_RESET::parse(errlver_t i_ver,
                                          ErrlUsrParser &i_parser,
                                          const void *i_buffer,
                                          const uint32_t i_buflen) const
{

    const uint32_t l_dataLength = sizeof(toifResetData_t);
    const toifResetData_t *l_data = (toifResetData_t*) i_buffer;
    if ((i_buffer != NULL) && (i_buflen >= l_dataLength))
    {
        char l_string[64];
        i_parser.PrintNumber("Node", "0x%02X", l_data->node);
        sprintf(l_string, "0x%02X  (%s)", l_data->state, state_string(occStateId(l_data->state)));
        i_parser.PrintString("State", l_string);
        i_parser.PrintBool("Needs reset?", l_data->needsReset);
        i_parser.PrintBool("Safe mode?", l_data->safeMode);

        if (i_buflen > l_dataLength)
        {
            // Note: errl will pads the user data to a word boundary
            i_parser.PrintHeading("Data (may be truncated)");
            i_parser.PrintHexDump(&l_data[l_dataLength], i_buflen - l_dataLength);
        }
    }

} // end parse TMGT_ELOG_TYPE_TOIF_RESET


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       parse TMGT_ELOG_TYPE_OCC_RESET                                */
/*                                                                            */
/* End Function Specification *************************************************/
void tmgtTMGT_ELOG_TYPE_OCC_RESET::parse(errlver_t i_ver,
                                          ErrlUsrParser &i_parser,
                                          const void *i_buffer,
                                          const uint32_t i_buflen) const
{

    const uint32_t l_dataLength = sizeof(occResetData_t);
    const occResetData_t *l_data = (occResetData_t*) i_buffer;
    if ((i_buffer != NULL) && (i_buflen >= l_dataLength))
    {
        char l_string[64];
        i_parser.PrintNumber("Node", "0x%02X", l_data->node);
        i_parser.PrintNumber("OCC Instance", "0x%02X", l_data->instance);
        i_parser.PrintString("Role", (l_data->role == TOIF_OCC_MASTER) ? "MASTER" : ((l_data->role == TOIF_OCC_SLAVE) ? "SLAVE" : "UNKNOWN"));
        i_parser.PrintBool("Master Capable?", l_data->capable);
        i_parser.PrintNumber("HUID", "0x%08X", l_data->huid);
        sprintf(l_string, "0x%02X  (%s)", l_data->state, state_string(occStateId(l_data->state)));
        i_parser.PrintString("State", l_string);
        i_parser.PrintBool("Failed?", l_data->failed);
        i_parser.PrintBool("Needs reset?", l_data->needsReset);
        i_parser.PrintNumber("Reset Count as Master", "%d", l_data->resetCountM);
        i_parser.PrintNumber("Reset Count as Slave", "%d", l_data->resetCountS);
        i_parser.PrintNumber("Reset Count since IPL", "%d", l_data->iplResetCount);
        i_parser.PrintBool("Comm Established?", l_data->commEst);
        i_parser.PrintBool("Poll valid?", l_data->pollValid);
        i_parser.PrintHeading("Last Poll Response");
        i_parser.PrintHexDump(l_data->lastPollRsp, TMGT_OCC_POLL_RSP_SIZE);

        if (i_buflen > l_dataLength)
        {
            // Note: errl will pads the user data to a word boundary
            i_parser.PrintHeading("Data (may be truncated)");
            i_parser.PrintHexDump(&l_data[l_dataLength], i_buflen - l_dataLength);
        }
    }

} // end parse TMGT_ELOG_TYPE_OCC_RESET



/* Function Specification *****************************************************/
/*                                                                            */
/*  Function:   Parse Power Cap data                                          */
/*                                                                            */
/* End Function Specification *************************************************/
void tmgtTMGT_ELOG_TYPE_PCAP_DATA::parse(errlver_t i_ver,
                                         ErrlUsrParser &i_parser,
                                         const void *i_buffer,
                                         const uint32_t i_buflen) const
{
    bool l_rc = FALSE;

    if ((i_buffer != NULL) && (i_buflen >= 4))
    {
        uint32_t l_index = 0;
        const uint8_t *l_data = (uint8_t*)i_buffer;

        const uint32_t l_pcapDataSize = sizeof(tmgt_pcap_summary_t);
        uint8_t l_node = 0;
        while ((l_index + l_pcapDataSize) <= i_buflen)
        {
            tmgt_pcap_summary_t *pcapData = (tmgt_pcap_summary_t*)&l_data[l_index];

            i_parser.PrintDivider();

            char string[64];
            sprintf(string, "Node %d Power Values", l_node);
            i_parser.PrintHeading(string);

            i_parser.PrintNumber("Number of processors",          "%d", pcapData->countProc);
            i_parser.PrintNumber("Total Nominal Proc Power",      "%5dW", pcapData->totalProcPwr);
            i_parser.PrintNumber("Total Turbo Proc Power",        "%5dW", pcapData->totalTurboProcPwr);
            i_parser.PrintNumber("Total Min Proc Power",          "%5dW", pcapData->totalMinProcPwr);
            i_parser.PrintNumber("Total Nominal Mem Power",       "%5dW", pcapData->nominalMemPwr);
            i_parser.PrintNumber("Total Turbo Mem Power",         "%5dW", pcapData->turboMemPwr);
            i_parser.PrintNumber("Total Powercap Mem Power",      "%5dW", pcapData->powercapMemPwr);
            i_parser.PrintNumber("Max Power Per Node",            "%5dW", pcapData->maxPwrPerNode);
            i_parser.PrintNumber("Fixed resources",               "%5dW", pcapData->totalFixed);
            i_parser.PrintNumber("PCI Power",                     "%5dW", pcapData->totalPCI);
            //i_parser.PrintNumber("DIMMs",                         "%5dW", pcapData->totalDIMM);
            i_parser.PrintBlank();

            // Results
            i_parser.PrintNumber("DVFS Min Cap",                  "%5dW", pcapData->pcapDvfsMin);
            i_parser.PrintNumber("Soft Min Cap",                  "%5dW", pcapData->pcapSoftMin);
            i_parser.PrintNumber("Min Cap",                       "%5dW", pcapData->pcapMin);
            i_parser.PrintNumber("Max Cap",                       "%5dW", pcapData->pcapMax);
            i_parser.PrintNumber("Oversubscription Cap",          "%5dW", pcapData->pcapOversub);
            i_parser.PrintNumber("Turbo Cap",                     "%5dW", pcapData->pcapTurbo);
            if (pcapData->pcapCurrent > 0)
            {
                i_parser.PrintNumber("Current Power Cap",           "%5dW", pcapData->pcapCurrent);
            }
            else
            {
                i_parser.PrintString("Current Power Cap",           "disabled");
            }

            l_index += l_pcapDataSize;
            l_node++;
        }

        if (i_buflen > l_index)
        {
            // Note: errl will pads the user data to a word boundary
            i_parser.PrintHeading("Additional data");
            i_parser.PrintHexDump(&l_data[l_index], i_buflen - l_index);
        }

        l_rc = TRUE;
    }
    // else data too short or unknown type (just dumps hex)

} // end tmgtParsePcapData()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Function:   Parse Thermal data                                            */
/*                                                                            */
/* End Function Specification *************************************************/
void tmgtTMGT_ELOG_TYPE_THERMAL_DATA::parse(errlver_t i_ver,
                                            ErrlUsrParser &i_parser,
                                            const void *i_buffer,
                                            const uint32_t i_buflen) const
{
    bool l_rc = FALSE;

    if ((i_buffer != NULL) && (i_buflen >= 4))
    {
        uint32_t l_index = 0;
        const uint8_t *l_data = (uint8_t*)i_buffer;

        uint16_t l_altitude = 0;
        uint16_t l_altitude_reg_ver = 0;

        // Ambient
        if (0xFF != l_data[l_index])
        {
            i_parser.PrintNumber("Ambient", "%d C", l_data[l_index]);
        }
        else
        {
            i_parser.PrintString("Ambient", "Unavailable");
        }
        l_index++;
        i_parser.PrintBool("Outside Environment Window",      l_data[l_index++]);

        // Altitude @425a
        if ( i_ver >= 2 )
        {
            l_altitude_reg_ver = UINT16_GET(&l_data[l_index]);
            l_altitude = UINT16_GET(&l_data[l_index+2]);
            l_index += 4;
            if ( l_altitude_reg_ver != 0x0002 )
            {
                i_parser.PrintString("Altitude", "N/A");
            }
            else
            {
                i_parser.PrintNumber("Altitude", "%d meters", l_altitude);
            }
        }

        // Fans
        const uint8_t l_numZones = l_data[l_index++];
        for (uint8_t l_zone = 0; l_zone < l_numZones; ++l_zone)
        {
            i_parser.PrintBlank();
            i_parser.PrintNumber("Fan Zone",    "%d", l_data[l_index++]);
            uint16_t l_rpm = UINT16_GET(&l_data[l_index]);
            if (0xFFFF != l_rpm)
            {
                i_parser.PrintNumber("Floor", "%5d RPM", l_rpm);
            }
            else
            {
                // 0xFFFF indicates no floor has been set
                i_parser.PrintString("Floor", "N/A");
            }
            l_index += 2;
            l_rpm = UINT16_GET(&l_data[l_index]);
            if (0xFFFF != l_rpm)
            {
                i_parser.PrintNumber("Target", "%5d RPM", l_rpm);
            }
            else
            {
                // 0xFFFF indicates no floor has been set
                i_parser.PrintString("Target", "N/A");
            }
            l_index += 2;
            char string[32];
            sprintf(string, "%5d - %d RPM", UINT16_GET(&l_data[l_index]), UINT16_GET(&l_data[l_index+2]));
            i_parser.PrintString("Current",     string);
            l_index += 4;
        }

        // Thermal Sensors
        const uint8_t l_numSensors = l_data[l_index++];
        for (uint8_t l_sIndex = 0; l_sIndex < l_numSensors; ++l_sIndex)
        {
            i_parser.PrintBlank();
            uint8_t l_len = l_data[l_index++];
            i_parser.PrintString("Name",        (char *)&l_data[l_index]);
            l_index += l_len;
            l_len = l_data[l_index++];
            i_parser.PrintString("Type",        (char *)&l_data[l_index]);
            l_index += l_len;
            i_parser.PrintNumber("Current",     "%2d C", l_data[l_index++]);
            i_parser.PrintNumber("Minimum",     "%2d C", l_data[l_index++]);
            i_parser.PrintNumber("Maximum",     "%2d C", l_data[l_index++]);
            i_parser.PrintNumber("Average",     "%2d C", l_data[l_index++]);
        }

        if (i_buflen > l_index)
        {
            i_parser.PrintBlank();

            // Note: errl will pads the user data to a word boundary
            i_parser.PrintHeading("Additional data");
            i_parser.PrintHexDump(&l_data[l_index], i_buflen - l_index);
        }

        l_rc = TRUE;
    }
    // else data too short or unknown type (just dumps hex)

} // end tmgtTMGT_ELOG_TYPE_THERMAL_DATA()



/* Register the Log Data plugin with ERRL */
static errl::DataPlugin g_DataPlugin( TMGT_COMP_ID, TmgtLogDataParse );

