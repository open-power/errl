// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/occc/fsp/plugins/occcDataParse.C 1.22 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2013,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/**
 *  @file occcDataParse.C
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <unistd.h>

#include <utilfile.H>
#include <errlplugins.H>
#include <errlusrparser.H>
#include <errlxmlparser.H>
#include <errlutility.H>

#include <occcSrcParse.H>
#include <occcDataParse.H>
#include <tmgt_toif_elog.H>

using namespace errl;
using namespace std;

/*****************************************************************************/
// Forward
/*****************************************************************************/
static bool LogDataParse(
    ErrlUsrParser & i_parser,
    void *	    i_buffer,
    uint32_t	    i_buflen,
    errlver_t	    i_ver,
    errlsubsec_t    i_sst
);

/*****************************************************************************/
// Globals
/*****************************************************************************/
static errl::DataPlugin    g_DataPlugin( OCCC_COMP_ID, LogDataParse );


/*****************************************************************************/
// OCCC Severity Parser
/*****************************************************************************/
static void PrintSeverity(
    ErrlUsrParser & i_parser,
    uint8_t         i_sev
)
{
    // NOTE: These must ALWAYS match up to
    //       whats defined in src/occc/405/occ/errl/errl.h

    switch ( i_sev )
    {
        case 0x00:
            i_parser.PrintString("Severity",    "Informational" );
            break;

        case 0x01:
            i_parser.PrintString("Severity",    "Predictive" );
            break;

        case 0x02:
            i_parser.PrintString("Severity",    "Unrecoverable" );
            break;

        case 0x03:
            i_parser.PrintString("Severity",    "CallHome Data" );
            break;

        default:
            i_parser.PrintNumber("Severity",    "0x%02X", i_sev );

    }
}


/*****************************************************************************/
// OCCC Actions Parser
/*****************************************************************************/
static void PrintActions(
    ErrlUsrParser & i_parser,
    uint8_t         i_actions
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/errl/errl.h
    const uint32_t  FLAGS_CNT = 4;
    string          l_flags[FLAGS_CNT];
    uint32_t        l_parsed = 0;

    if ( i_actions & 0x01 )
    {
        l_flags[l_parsed++] = "Consolidate Errors";
    }
    if ( i_actions & 0x08 )
    {
        l_flags[l_parsed++] = "Manufacturing Error";
    }
    if ( i_actions & 0x80 )
    {
        l_flags[l_parsed++] = "Reset Required";
    }

    if ( l_parsed == 0 )
    {
        i_parser.PrintNumber("Actions Flags", "0x%02x", i_actions );
    }
    else
    {
        for ( uint32_t x=0; x < l_parsed; x++)
        {
            if ( x == 0)
            {
                i_parser.PrintString("Actions Flags",   l_flags[x].c_str() );
            }
            else
            {
                i_parser.PrintString("",   l_flags[x].c_str() );
            }
        }
    }
}

/*****************************************************************************/
// OCCC Callout Type Parser
/*****************************************************************************/
static void PrintCalloutType(
    ErrlUsrParser & i_parser,
    uint8_t         i_type
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/errl/errl.h

    switch ( i_type )
    {
        case 0x01:
            i_parser.PrintString("Type",    "HOM Unit ID" );
            break;

        case 0x02:
            i_parser.PrintString("Type",    "OCC SubComponent ID" );
            break;

        default:
            i_parser.PrintNumber("Type",    "0x%02X", i_type );

    }
}

/*****************************************************************************/
// OCCC Callout Priority Parser
/*****************************************************************************/
static void PrintCalloutPriority(
    ErrlUsrParser & i_parser,
    uint8_t         i_priority
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/errl/errl.h

    switch ( i_priority )
    {
        case 0x00:
            i_parser.PrintString("Priority",    "Invalid" );
            break;

        case 0x01:
            i_parser.PrintString("Priority",    "Low" );
            break;

        case 0x02:
            i_parser.PrintString("Priority",    "Medium" );
            break;

        case 0x03:
            i_parser.PrintString("Priority",    "High" );
            break;

        default:
            i_parser.PrintNumber("Priority",    "0x%02X", i_priority );

    }
}

/*****************************************************************************/
// OCCC Role Parser
/*****************************************************************************/
static void PrintOccRole(
    ErrlUsrParser & i_parser,
    uint8_t         i_role
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/dcom/dcom.h

    switch ( i_role )
    {
        case 0:
            i_parser.PrintString("Role",    "Slave" );
            break;

        case 1:
            i_parser.PrintString("Role",    "Master" );
            break;

        case 2:
            i_parser.PrintString("Role",    "Backup Master" );
            break;

        default:
            i_parser.PrintNumber("Role",    "0x%02X", i_role );

    }
}

/*****************************************************************************/
// OCCC Sub Component Id Parser
/*****************************************************************************/
static void PrintOccCompId(
    ErrlUsrParser & i_parser,
    uint16_t         i_modId
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/incl/comp_ids.h

    uint16_t    l_compId = i_modId & 0xFF00;
    string      l_label = "OCC Logging Component";
    string      l_compString;


    switch ( l_compId )
    {
        case MAIN_COMP_ID:
            l_compString = MAIN_COMP_NAME;
            break;

        case ERRL_COMP_ID:
            l_compString = ERRL_COMP_NAME;
            break;

        case TRAC_COMP_ID:
            l_compString = TRAC_COMP_NAME;
            break;

        case RTLS_COMP_ID:
            l_compString = RTLS_COMP_NAME;
            break;

        case THRD_COMP_ID:
            l_compString = THRD_COMP_NAME;
            break;

        case SNSR_COMP_ID:
            l_compString = SNSR_COMP_NAME;
            break;

        case APLT_COMP_ID:
            l_compString = APLT_COMP_NAME;
            break;

        case PSS_COMP_ID:
            l_compString = PSS_COMP_NAME;
            break;

        case TMER_COMP_ID:
            l_compString = TMER_COMP_NAME;
            break;

        case DCOM_COMP_ID:
            l_compString = DCOM_COMP_NAME;
            break;

        case PROC_COMP_ID:
            l_compString = PROC_COMP_NAME;
            break;

        case AMEC_COMP_ID:
            l_compString = AMEC_COMP_NAME;
            break;

        case CENT_COMP_ID:
            l_compString = CENT_COMP_NAME;
            break;

        case CMDH_COMP_ID:
            l_compString = CMDH_COMP_NAME;
            break;

        default:
            i_parser.PrintNumber("OCC Component",    "0x%04X", l_compId );

    }

    if ( l_compString.size() )
    {
        i_parser.PrintString(l_label.c_str(), l_compString.c_str() );
    }

}

/*****************************************************************************/
// OCCC State Parser
/*****************************************************************************/
static void PrintOccState(
    ErrlUsrParser & i_parser,
    uint8_t         i_state
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/state.h

    switch ( i_state )
    {
        case 0x00:
            i_parser.PrintString("State",   "No Change" );
            break;

        case 0x01:
            i_parser.PrintString("State",   "Standby" );
            break;

        case 0x02:
            i_parser.PrintString("State",   "Observation" );
            break;

        case 0x03:
            i_parser.PrintString("State",   "Active" );
            break;

        case 0x04:
            i_parser.PrintString("State",   "Safe" );
            break;

        case 0x05:
            i_parser.PrintString("State",   "Reset" );
            break;

        case 0x06:
            i_parser.PrintString("State",   "Standby Observation" );
            break;


        default:
            i_parser.PrintNumber("State",    "0x%02X", i_state );

    }
}


/*****************************************************************************/
// OCCC Power mode Parser
/*****************************************************************************/
static void PrintPwrMode(ErrlUsrParser & i_parser, const char * i_string, const uint8_t i_mode)
{
    switch (i_mode)
    {
        case 0x01:
            i_parser.PrintString(i_string, "Nominal" );
            break;

        case 0x05:
            i_parser.PrintString(i_string,  "Static Power Save" );
            break;

        case 0x06:
            i_parser.PrintString(i_string,  "Dynamic Power Save - Favor Energy" );
            break;

        case 0x0A:
            i_parser.PrintString(i_string,  "Dynamic Power Save - Favor Performance" );
            break;

        case 0x0B:
            i_parser.PrintString(i_string,  "Fixed Frequency Override" );
            break;

        default:
            i_parser.PrintNumber(i_string,  "0x%02X", i_mode);

    }
}


/*****************************************************************************/
// OCCC State Parser
/*****************************************************************************/
static void PrintCalloutComponentId(
    ErrlUsrParser & i_parser,
    uint64_t        i_val
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/errl/errl.h

    uint8_t l_id = (uint8_t) i_val;

    switch ( l_id )
    {
        case 0x01:
            i_parser.PrintString("Component Id",    "Firmware" );
            break;

        case 0x04:
            i_parser.PrintString("Component Id",    "Over Temperature" );
            break;

        case 0x05:
            i_parser.PrintString("Component Id",    "OverSubscription" );
            break;

        default:
            char l_tmp[19] = {0};
            sprintf(l_tmp, "0x%016llX", i_val);
            i_parser.PrintString("Component Id", l_tmp);

    }
}

/*****************************************************************************/
// OCCC User Details Type Parser
/*****************************************************************************/
static void PrintUDType(
    ErrlUsrParser & i_parser,
    uint8_t         i_type
)
{
    // note: these must always match up to
    //       whats defined in src/occc/405/occ/errl/errl.h
    string  l_label = "User Detail Type";
    string  l_type;

    switch ( i_type )
    {
        case 0x01:
            l_type = "Trace Data";
            break;

        case 0x02:
            l_type = "CallHome Data";
            break;

        case 0x03:
            l_type = "Binary Data";
            break;

        case 0x04:
            l_type = "Error History Data";
            break;

        default:
            i_parser.PrintNumber(l_label.c_str(), "0x%02X", i_type );
    }

    if ( l_type.size() )
    {
        i_parser.PrintString(l_label.c_str(), l_type.c_str() );
    }
}

/*****************************************************************************/
// OCCC Print Trace Data from User Details
// Returns true if data was parsed successfully
/*****************************************************************************/
static bool PrintTraceData(ErrlUsrParser & i_parser,
                           uint16_t        i_checkSum,
                           void *          i_buffer,
                           uint32_t        i_len,
                           const bool      i_updateLength = false)
{
    bool l_traceParsed = false;

    do
    {
        ostringstream  l_fileStr;

        l_fileStr << "/tmp/" << hex << i_checkSum << "-" << dec << getpid() << ".trace";

        if (i_updateLength)
        {
            // fsp-trace requires trace length to match buffer length
            uint8_t * l_bufPtr = (uint8_t*)i_buffer;
            const uint16_t traceLength = l_bufPtr[22] << 8 | l_bufPtr[23];
            if (i_len != traceLength)
            {
                cerr << "Updating trace length from 0x" << hex << traceLength << " to 0x" << hex << i_len << endl;
                l_bufPtr[22] = (i_len >> 8) & 0xFF;
                l_bufPtr[23] = i_len & 0xFF;
            }
        }

        // Write trace buffer to file
        ofstream   out( l_fileStr.str().c_str(), ios::binary );
        if ( !out )
        {
          cerr << "E> Error writing " << l_fileStr.str() << "aborting attempt to parse trace" << endl;
          break;
        }
        else
        {
          out.write( (char *)i_buffer, i_len );
          out.close();
        }

        // Find the string file (current directory, /maint/test, /maint, /nfs/test, /nfs/, or build)
        string         l_strName   = "occStringFile";
        string         l_mainttest = "/maint/test/" + l_strName;
        string         l_maint     = "/maint/" + l_strName;
        string         l_nfstest   = "/nfs/test/" + l_strName;
        string         l_nfs       = "/nfs/" + l_strName;
        string         l_nfsBB     = "/esw/fips910/Builds/built/src/occc/fsp/trexStringFile";
        string         l_strFile;
        if ( UtilFile::exists(l_strName.c_str()) ) // current directory
        {
            l_strFile = l_strName;
        }
        else if ( UtilFile::exists(l_mainttest.c_str()) )
        {
            l_strFile = l_mainttest;
        }
        else if ( UtilFile::exists(l_maint.c_str()) )
        {
            l_strFile = l_maint;
        }
        else if ( UtilFile::exists(l_nfstest.c_str()) )
        {
            l_strFile = l_nfstest;
        }
        else if ( UtilFile::exists(l_nfs.c_str()) )
        {
            l_strFile = l_nfs;
        }
        else if ( UtilFile::exists(l_nfsBB.c_str()) )
        {
            l_strFile = l_nfsBB;
        }

        if ( l_strFile.empty() )
        {
            cerr << "No stringFile found ... aborting attempt to parse trace" << endl;
            break;
        }
        i_parser.PrintString("StringFile", l_strFile.c_str());

        // Build command to parse the trace
        ostringstream  l_cmd;
        l_cmd << "fsp-trace -s " << l_strFile << " " << l_fileStr.str().c_str();

        // Execute command
        FILE * p = popen(l_cmd.str().c_str(), "r");
        if( p == NULL )
        {
            int l_urc = pclose(p);
            printf("E> popen() failed cmdline='%s', status=%i\n", l_cmd.str().c_str(), WEXITSTATUS(l_urc) );
            break;
        }

        // Read output of command
        const int   BUFFERSIZE = 1024;
        char    buffer[BUFFERSIZE];
        int     n = -1;
        n = fread(buffer,1,BUFFERSIZE,p);
        if ( n > 0 )
        {
            while ( n > 0 )
            {
                // dump output out to stdout
                fwrite(buffer, 1, n, stdout);
                n = fread(buffer, 1, BUFFERSIZE, p);
            };

            pclose(p);
            l_traceParsed = true;
        }
        else
        {
            // Cleanup
            int l_urc = pclose(p);
            printf("E> pclose() failed cmdline='%s', status=%i\n", l_cmd.str().c_str(), WEXITSTATUS(l_urc) );
        }

        // remove temp file
        remove( l_cmd.str().c_str() );

    } while ( 0 );

    return l_traceParsed;

} // end PrintTraceData()


/*****************************************************************************/
// Print sensor name/sample/avg/min/max for a single sensor on a single line
/*****************************************************************************/
static void PrintSensorData(ErrlUsrParser & i_parser,
                            const char * i_name, const ChomSensor_t i_sensor)
{
    std::stringstream l_sensor;
    bool l_isxmlparser = (dynamic_cast<ErrlXmlParser*>(&i_parser));

    if(!l_isxmlparser)
    {
      l_sensor << "|   "<<left<<setfill(' ')<<setw(20)<<i_name<<right;
      l_sensor << " Sample:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.sample)<<"]";
      l_sensor << " Avg:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.average)<<"]";
      l_sensor << " Min:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.sampleMin)<<"]";
      l_sensor << " Max:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.sampleMax)<<"]" << "    |\n";

      printf(l_sensor.str().c_str());
    }
    else
    {
      i_parser.PrintHeading(i_name);
      i_parser.PrintNumber("Sample","%d",ntohs(i_sensor.sample));
      i_parser.PrintNumber("Avg","%d",ntohs(i_sensor.average));
      i_parser.PrintNumber("Sample Min","%d",ntohs(i_sensor.sampleMin));
      i_parser.PrintNumber("Sample Max", "%d",ntohs(i_sensor.sampleMax));
      i_parser.PrintSectionEnd(true);
    }
}

/*****************************************************************************/
// Print frequency clip history data for a single slave OCC
/*****************************************************************************/
static void PrintFClipHistory( ErrlUsrParser & i_parser,
                               const char * i_name,
                               const uint32_t i_fclipHist )
{
    std::stringstream l_stream;
    bool l_isxmlparser = (dynamic_cast<ErrlXmlParser*>(&i_parser));

    if(!l_isxmlparser)
    {
      l_stream << "|    "<<left<<setfill(' ')<<setw(20)<<i_name<<right;
      l_stream << "FClip History:[";
      l_stream<<setfill('0')<<setw(8)<<hex<<i_fclipHist;
      l_stream<<"]" << "                              |\n";
      printf(l_stream.str().c_str());
    }
    else
    {
      i_parser.PrintHeading(i_name);
      i_parser.PrintNumber("FClip History","%d",i_fclipHist);
      i_parser.PrintSectionEnd(true);
    }
}

/*****************************************************************************/
// Print error history data for a single slave OCC
/*****************************************************************************/
static void PrintErrorHistory(ErrlUsrParser & i_parser,const char * i_name,
                               const error_history_count_t * errhData )
{
    std::stringstream l_streamName;
    std::stringstream l_streamData;
    std::stringstream l_stream;

    char l_id[2];
    char l_count[2];
    bool l_isxmlparser = (dynamic_cast<ErrlXmlParser*>(&i_parser));

    l_streamName << "|    "<<left<<setfill(' ')<<setw(20)<<i_name<<right;
    l_streamName << "ERRHIST Counts:[";

    for(int i = 0; i < MAX_NUM_ERRH_ENTRIES; i++)
    {
      sprintf(l_id, "%02X", errhData[i].error_id);
      sprintf(l_count, "%02X", errhData[i].error_count );
      l_streamData<<l_id<<l_count;
    }

    l_stream<< l_streamName << l_streamData << "]" << "                     |\n";

    if(!l_isxmlparser)
    {
      printf(l_stream.str().c_str());
    }
    else
    {
      i_parser.PrintHeading(i_name);
      i_parser.PrintString("ERRHIST Counts",l_streamData.str().c_str());
      i_parser.PrintSectionEnd(true);
    }
}



/*****************************************************************************/
// Print APSS sensor data for call home log
/*****************************************************************************/
static void PrintCallHomeAPSSSensor(ErrlUsrParser & i_parser,
                                   const char * i_name,
                                   const ChomSensor_t i_sensor,
                                   const uint8_t i_channelFuncId )
{
    std::stringstream l_sensor;
    uint16_t channel = i_channelFuncId;
    bool l_isxmlparser = (dynamic_cast<ErrlXmlParser*>(&i_parser));

    if(!l_isxmlparser)
    {
      l_sensor << "|  "<<left<<setfill(' ')<<setw(15)<<i_name<<right;
      l_sensor << " FID:["<<setfill('0')<<setw(2)<<ntohs(channel)<<"]";
      l_sensor << " Sample:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.sample)<<"]";
      l_sensor << " Avg:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.average)<<"]";
      l_sensor << " Min:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.sampleMin)<<"]";
      l_sensor << " Max:["<<setfill('0')<<setw(5)<<ntohs(i_sensor.sampleMax)<<"]" << " |\n";

      printf(l_sensor.str().c_str());
    }
    else
    {
      i_parser.PrintHeading(i_name);
      i_parser.PrintNumber("FID","%d",ntohs(channel));
      i_parser.PrintNumber("Sample","%d",ntohs(i_sensor.sample));
      i_parser.PrintNumber("Avg","%d",ntohs(i_sensor.average));
      i_parser.PrintNumber("Sample Min","%d",ntohs(i_sensor.sampleMin));
      i_parser.PrintNumber("Sample Max", "%d",ntohs(i_sensor.sampleMax));
      i_parser.PrintSectionEnd(true);
    }
}

/*****************************************************************************/
// OCCC Print Call Home Sensor data
/*****************************************************************************/
static void PrintCallHomeSensorData(ErrlUsrParser & i_parser,const char * i_name, 
                                    const uint16_t i_sample, const uint16_t i_average,
                                    const uint16_t i_min, const uint16_t i_max)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    std::stringstream l_sensor;


    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    bool l_isxmlparser = (dynamic_cast<ErrlXmlParser*>(&i_parser));

    if(!l_isxmlparser)
    {
      l_sensor << "|------------------------------------------------------------------------------|\n";
      l_sensor << "| Sensor Name              : "<<left<<setfill(' ')<<setw(20)<<i_name<<right<<"                              |\n";
      l_sensor << "| Sample:["<<setfill('0')<<setw(5)<<i_sample<<"] "<<"Histogram Avg:["<<setfill('0')<<setw(5)<<i_average<< "] ";
      l_sensor << "Sample Min:["<<setfill('0')<<setw(5)<<i_min<<"] "<<"Max:["<<setfill('0')<<setw(5)<<i_max<<"]"<< "          |\n";

      printf(l_sensor.str().c_str());
    }
    else
    {
      i_parser.PrintHeading(i_name);
      i_parser.PrintNumber("Sample","%d",i_sample);
      i_parser.PrintNumber("Histogram Avg","%d",i_average);
      i_parser.PrintNumber("Sample Min","%d",i_min);
      i_parser.PrintNumber("Max", "%d",i_max);
      i_parser.PrintSectionEnd(true);
    }
}


/*****************************************************************************/
// Print Call home data - Version 0
/*****************************************************************************/
static void PrintCallHomeSensors_v0(ErrlUsrParser & i_parser,
                                     const ChomLogData_v0_t * i_chom,
                                     uint32_t i_len,
                                     uint8_t i_modes )
{
    uint8_t i = 0;
    i_parser.PrintHeading("Call Home Sensor Data v0");
// Do sanity check on the function inputs
    if (sizeof(ChomLogData_v0_t) == i_len)
    {
        do
        {
            i_parser.PrintHeading("Call Home Sensor Data");
            i_parser.PrintDivider();
            i_parser.PrintString("Sensor Data", i == 0 ? "Current Power Mode": "Previous Power Mode");
            PrintPwrMode(i_parser, "Power Saving Mode", i_chom->sensorData[i].pwrMode.mode);
            i_parser.PrintNumber("Number of Samples", "%d", ntohs(i_chom->sensorData[i].pwrMode.numOfSamples));
            // Node total power (DC)
            PrintCallHomeSensorData(i_parser,"CHOMPWR", ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWR].sample),
                                               ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWR].average),
                                               ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWR].sampleMin),
                                               ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWR].sampleMax));
            i_parser.PrintDivider();
            // Socket power
            i_parser.PrintString("Socket Power", "");
            PrintSensorData(i_parser,"CHOMPWRS0", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS0]);
            PrintSensorData(i_parser,"CHOMPWRS1", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS1]);
            PrintSensorData(i_parser,"CHOMPWRS2", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS2]);
            PrintSensorData(i_parser,"CHOMPWRS3", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS3]);
            PrintSensorData(i_parser,"CHOMPWRS4", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS4]);
            PrintSensorData(i_parser,"CHOMPWRS5", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS5]);
            PrintSensorData(i_parser,"CHOMPWRS6", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS6]);
            PrintSensorData(i_parser,"CHOMPWRS7", i_chom->sensorData[i].sensor[VER_0::CHOMPWRS7]);
            i_parser.PrintDivider();
            // Memory power
            i_parser.PrintString("Memory Power", "");
            PrintSensorData(i_parser,"CHOMPWRM0", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM0]);
            PrintSensorData(i_parser,"CHOMPWRM1", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM1]);
            PrintSensorData(i_parser,"CHOMPWRM2", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM2]);
            PrintSensorData(i_parser,"CHOMPWRM3", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM3]);
            PrintSensorData(i_parser,"CHOMPWRM4", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM4]);
            PrintSensorData(i_parser,"CHOMPWRM5", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM5]);
            PrintSensorData(i_parser,"CHOMPWRM6", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM6]);
            PrintSensorData(i_parser,"CHOMPWRM7", i_chom->sensorData[i].sensor[VER_0::CHOMPWRM7]);
            // Fan power
            PrintCallHomeSensorData(i_parser,"CHOMPWRFAN", ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWRFAN].sample),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWRFAN].average),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWRFAN].sampleMin),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMPWRFAN].sampleMax));

            i_parser.PrintDivider();

            // Processor frequency
            i_parser.PrintString("Processor Frequency", "");
            PrintSensorData(i_parser,"CHOMFREQP0",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP0]);
            PrintSensorData(i_parser,"CHOMFREQP1",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP1]);
            PrintSensorData(i_parser,"CHOMFREQP2",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP2]);
            PrintSensorData(i_parser,"CHOMFREQP3",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP3]);
            PrintSensorData(i_parser,"CHOMFREQP4",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP4]);
            PrintSensorData(i_parser,"CHOMFREQP5",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP5]);
            PrintSensorData(i_parser,"CHOMFREQP6",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP6]);
            PrintSensorData(i_parser,"CHOMFREQP7",i_chom->sensorData[i].sensor[VER_0::CHOMFREQP7]);

            i_parser.PrintDivider();
            // Processor utilization sensor
            i_parser.PrintString("Processor utilization", "");
            PrintSensorData(i_parser,"CHOMUTILP0", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP0]);
            PrintSensorData(i_parser,"CHOMUTILP1", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP1]);
            PrintSensorData(i_parser,"CHOMUTILP2", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP2]);
            PrintSensorData(i_parser,"CHOMUTILP3", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP3]);
            PrintSensorData(i_parser,"CHOMUTILP4", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP4]);
            PrintSensorData(i_parser,"CHOMUTILP5", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP5]);
            PrintSensorData(i_parser,"CHOMUTILP6", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP6]);
            PrintSensorData(i_parser,"CHOMUTILP7", i_chom->sensorData[i].sensor[VER_0::CHOMUTILP7]);
            // Max core temperature for all processors in the node
            PrintCallHomeSensorData(i_parser,"CHOMTEMPPROC", ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPPROC].sample),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPPROC].average),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPPROC].sampleMin),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPPROC].sampleMax));
            // Max Centaur temperature for all Centaurs in the node
            PrintCallHomeSensorData(i_parser,"CHOMTEMPCENT", ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPCENT].sample),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPCENT].average),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPCENT].sampleMin),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPCENT].sampleMax));
            // Max Dimm temperature for all Dimms in the node
            PrintCallHomeSensorData(i_parser,"CHOMTEMPDIMM", ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPDIMM].sample),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPDIMM].average),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPDIMM].sampleMin),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMTEMPDIMM].sampleMax));
            // Instructions per second sensor
            PrintCallHomeSensorData(i_parser,"CHOMIPS", ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMIPS].sample),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMIPS].average),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMIPS].sampleMin),
                                     ntohs(i_chom->sensorData[i].sensor[VER_0::CHOMIPS].sampleMax));
            i_parser.PrintDivider();
            // Memory bandwidth for process memory controller
            i_parser.PrintString("Memory bandwidth", "");
            PrintSensorData(i_parser,"CHOMBWP0M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M0]);
            PrintSensorData(i_parser,"CHOMBWP0M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M1]);
            PrintSensorData(i_parser,"CHOMBWP0M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M2]);
            PrintSensorData(i_parser,"CHOMBWP0M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M3]);
            PrintSensorData(i_parser,"CHOMBWP0M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M4]);
            PrintSensorData(i_parser,"CHOMBWP0M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M5]);
            PrintSensorData(i_parser,"CHOMBWP0M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M6]);
            PrintSensorData(i_parser,"CHOMBWP0M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP0M7]);
            PrintSensorData(i_parser,"CHOMBWP1M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M0]);
            PrintSensorData(i_parser,"CHOMBWP1M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M1]);
            PrintSensorData(i_parser,"CHOMBWP1M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M2]);
            PrintSensorData(i_parser,"CHOMBWP1M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M3]);
            PrintSensorData(i_parser,"CHOMBWP1M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M4]);
            PrintSensorData(i_parser,"CHOMBWP1M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M5]);
            PrintSensorData(i_parser,"CHOMBWP1M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M6]);
            PrintSensorData(i_parser,"CHOMBWP1M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP1M7]);
            PrintSensorData(i_parser,"CHOMBWP2M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M0]);
            PrintSensorData(i_parser,"CHOMBWP2M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M1]);
            PrintSensorData(i_parser,"CHOMBWP2M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M2]);
            PrintSensorData(i_parser,"CHOMBWP2M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M3]);
            PrintSensorData(i_parser,"CHOMBWP2M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M4]);
            PrintSensorData(i_parser,"CHOMBWP2M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M5]);
            PrintSensorData(i_parser,"CHOMBWP2M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M6]);
            PrintSensorData(i_parser,"CHOMBWP2M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP2M7]);
            PrintSensorData(i_parser,"CHOMBWP3M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M0]);
            PrintSensorData(i_parser,"CHOMBWP3M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M1]);
            PrintSensorData(i_parser,"CHOMBWP3M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M2]);
            PrintSensorData(i_parser,"CHOMBWP3M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M3]);
            PrintSensorData(i_parser,"CHOMBWP3M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M4]);
            PrintSensorData(i_parser,"CHOMBWP3M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M5]);
            PrintSensorData(i_parser,"CHOMBWP3M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M6]);
            PrintSensorData(i_parser,"CHOMBWP3M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP3M7]);
            PrintSensorData(i_parser,"CHOMBWP4M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M0]);
            PrintSensorData(i_parser,"CHOMBWP4M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M1]);
            PrintSensorData(i_parser,"CHOMBWP4M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M2]);
            PrintSensorData(i_parser,"CHOMBWP4M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M3]);
            PrintSensorData(i_parser,"CHOMBWP4M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M4]);
            PrintSensorData(i_parser,"CHOMBWP4M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M5]);
            PrintSensorData(i_parser,"CHOMBWP4M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M6]);
            PrintSensorData(i_parser,"CHOMBWP4M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP4M7]);
            PrintSensorData(i_parser,"CHOMBWP5M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M0]);
            PrintSensorData(i_parser,"CHOMBWP5M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M1]);
            PrintSensorData(i_parser,"CHOMBWP5M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M2]);
            PrintSensorData(i_parser,"CHOMBWP5M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M3]);
            PrintSensorData(i_parser,"CHOMBWP5M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M4]);
            PrintSensorData(i_parser,"CHOMBWP5M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M5]);
            PrintSensorData(i_parser,"CHOMBWP5M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M6]);
            PrintSensorData(i_parser,"CHOMBWP5M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP5M7]);
            PrintSensorData(i_parser,"CHOMBWP6M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M0]);
            PrintSensorData(i_parser,"CHOMBWP6M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M1]);
            PrintSensorData(i_parser,"CHOMBWP6M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M2]);
            PrintSensorData(i_parser,"CHOMBWP6M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M3]);
            PrintSensorData(i_parser,"CHOMBWP6M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M4]);
            PrintSensorData(i_parser,"CHOMBWP6M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M5]);
            PrintSensorData(i_parser,"CHOMBWP6M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M6]);
            PrintSensorData(i_parser,"CHOMBWP6M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP6M7]);
            PrintSensorData(i_parser,"CHOMBWP7M0", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M0]);
            PrintSensorData(i_parser,"CHOMBWP7M1", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M1]);
            PrintSensorData(i_parser,"CHOMBWP7M2", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M2]);
            PrintSensorData(i_parser,"CHOMBWP7M3", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M3]);
            PrintSensorData(i_parser,"CHOMBWP7M4", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M4]);
            PrintSensorData(i_parser,"CHOMBWP7M5", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M5]);
            PrintSensorData(i_parser,"CHOMBWP7M6", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M6]);
            PrintSensorData(i_parser,"CHOMBWP7M7", i_chom->sensorData[i].sensor[VER_0::CHOMBWP7M7]);
            i++;
            i_parser.PrintSectionEnd(true);
        } while (i < i_modes);
    }
    else // unmatched length, dump HEX
    {
        i_parser.PrintString("Unexpected Chom len v0", "");
        i_parser.PrintNumber("Bad Length", "%d", i_len);
        i_parser.PrintNumber("Expected", "%d", sizeof(ChomLogData_v0_t));
        i_parser.PrintHexDump((uint8_t *)i_chom, i_len);
    }
    i_parser.PrintSectionEnd(true);
}

/*****************************************************************************/
// Print shared call home sensors
/*****************************************************************************/
static void PrintCallHomeSensors( ErrlUsrParser & i_parser,
                                  const ChomLogData_v1_t * i_chom,
                                  uint8_t i_mode_idx)
{
    i_parser.PrintHeading("Call Home Sensor Data");
    i_parser.PrintDivider();
    i_parser.PrintString("Sensor Data", i_mode_idx == 0 ? "Current Power Mode": "Previous Power Mode");
    PrintPwrMode(i_parser, "Power Saving Mode", i_chom->sensorData[i_mode_idx].pwrMode.mode);
    i_parser.PrintNumber("Number of Samples", "%d", ntohs(i_chom->sensorData[i_mode_idx].pwrMode.numOfSamples));

    // Node total power (DC)
    PrintCallHomeSensorData(i_parser,"CHOMPWR",
                ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWR].sample),
                ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWR].average),
                ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWR].sampleMin),
                ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWR].sampleMax));

    i_parser.PrintDivider();

    // APSS Channel information
    i_parser.PrintHeading("APSS Channels");
    i_parser.PrintString("APSS Channels", "");
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH0",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH0],
                            i_chom->nodeData.channelFuncIds[0]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH1",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH1],
                            i_chom->nodeData.channelFuncIds[1]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH2",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH2],
                            i_chom->nodeData.channelFuncIds[2]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH3",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH3],
                            i_chom->nodeData.channelFuncIds[3]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH4",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH4],
                            i_chom->nodeData.channelFuncIds[4]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH5",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH5],
                            i_chom->nodeData.channelFuncIds[5]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH6",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH6],
                            i_chom->nodeData.channelFuncIds[6]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH7",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH7],
                            i_chom->nodeData.channelFuncIds[7]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH8",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH8],
                            i_chom->nodeData.channelFuncIds[8]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH9",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH9],
                            i_chom->nodeData.channelFuncIds[9]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH10",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH10],
                            i_chom->nodeData.channelFuncIds[10]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH11",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH11],
                            i_chom->nodeData.channelFuncIds[11]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH12",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH12],
                            i_chom->nodeData.channelFuncIds[12]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH13",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH13],
                            i_chom->nodeData.channelFuncIds[13]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH14",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH14],
                            i_chom->nodeData.channelFuncIds[14]);
    PrintCallHomeAPSSSensor(i_parser,"CHOMPWRAPSSCH15",
                            i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMPWRAPSSCH15],
                            i_chom->nodeData.channelFuncIds[15]);
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);

    // Processor frequency
    i_parser.PrintHeading("Processor Frequency");
    i_parser.PrintString("Processor Frequency", "");
    PrintSensorData(i_parser,"CHOMFREQP0",i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMFREQP0]);
    PrintSensorData(i_parser,"CHOMFREQP1",i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMFREQP1]);
    PrintSensorData(i_parser,"CHOMFREQP2",i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMFREQP2]);
    PrintSensorData(i_parser,"CHOMFREQP3",i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMFREQP3]);
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);

    // Processor utilization sensor
    i_parser.PrintHeading("Processor utilization");
    i_parser.PrintString("Processor utilization", "");
    PrintSensorData(i_parser,"CHOMUTILP0", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMUTILP0]);
    PrintSensorData(i_parser,"CHOMUTILP1", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMUTILP1]);
    PrintSensorData(i_parser,"CHOMUTILP2", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMUTILP2]);
    PrintSensorData(i_parser,"CHOMUTILP3", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMUTILP3]);
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);

    // Max core temperature for all processors in the node
    i_parser.PrintHeading("Processor Temperatures");
    i_parser.PrintString("Processor Temperatures", "");
    PrintSensorData(i_parser,"CHOMTEMPPROC0",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPPROC0]);
    PrintSensorData(i_parser,"CHOMTEMPPROC1",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPPROC1]);
    PrintSensorData(i_parser,"CHOMTEMPPROC2",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPPROC2]);
    PrintSensorData(i_parser,"CHOMTEMPPROC3",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPPROC3]);
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);

    // Centaur temperatures
    i_parser.PrintHeading("Centaur Temperatures");
    i_parser.PrintString("Centaur Temperatures", "");
    PrintSensorData(i_parser,"CHOMTEMPCENT0",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPCENTP0]);
    PrintSensorData(i_parser,"CHOMTEMPCENT1",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPCENTP1]);
    PrintSensorData(i_parser,"CHOMTEMPCENT2",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPCENTP2]);
    PrintSensorData(i_parser,"CHOMTEMPCENT3",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPCENTP3]);
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);

    // DIMM temperatures
    i_parser.PrintHeading("DIMM Temperatures");
    i_parser.PrintString("DIMM Temperatures", "");
    PrintSensorData(i_parser,"CHOMTEMPDIMMP0",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPDIMMP0]);
    PrintSensorData(i_parser,"CHOMTEMPDIMMP1",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPDIMMP1]);
    PrintSensorData(i_parser,"CHOMTEMPDIMMP2",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPDIMMP2]);
    PrintSensorData(i_parser,"CHOMTEMPDIMMP3",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPDIMMP3]);
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);

    //VRM VDD temperatures
    i_parser.PrintHeading("VRM VDD Temperatures");
    i_parser.PrintString("VRM VDD Temperatures", "");
    PrintSensorData(i_parser,"CHOMTEMPVDDP0",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPVDDP0]);
    PrintSensorData(i_parser,"CHOMTEMPVDDP1",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPVDDP1]);
    PrintSensorData(i_parser,"CHOMTEMPVDDP2",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPVDDP2]);
    PrintSensorData(i_parser,"CHOMTEMPVDDP3",
                     i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMTEMPVDDP3]);
    
    // Instructions per second sensor
    PrintCallHomeSensorData(i_parser,"CHOMIPS",
            ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMIPS].sample),
            ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMIPS].average),
            ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMIPS].sampleMin),
            ntohs(i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMIPS].sampleMax));
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);

    // Memory bandwidth for process memory controller
    i_parser.PrintHeading("Memory Bandwidth");
    i_parser.PrintString("Memory bandwidth", "");
    PrintSensorData(i_parser,"CHOMBWP0M0", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M0]);
    PrintSensorData(i_parser,"CHOMBWP0M1", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M1]);
    PrintSensorData(i_parser,"CHOMBWP0M2", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M2]);
    PrintSensorData(i_parser,"CHOMBWP0M3", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M3]);
    PrintSensorData(i_parser,"CHOMBWP0M4", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M4]);
    PrintSensorData(i_parser,"CHOMBWP0M5", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M5]);
    PrintSensorData(i_parser,"CHOMBWP0M6", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M6]);
    PrintSensorData(i_parser,"CHOMBWP0M7", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP0M7]);
    PrintSensorData(i_parser,"CHOMBWP1M0", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M0]);
    PrintSensorData(i_parser,"CHOMBWP1M1", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M1]);
    PrintSensorData(i_parser,"CHOMBWP1M2", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M2]);
    PrintSensorData(i_parser,"CHOMBWP1M3", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M3]);
    PrintSensorData(i_parser,"CHOMBWP1M4", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M4]);
    PrintSensorData(i_parser,"CHOMBWP1M5", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M5]);
    PrintSensorData(i_parser,"CHOMBWP1M6", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M6]);
    PrintSensorData(i_parser,"CHOMBWP1M7", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP1M7]);
    PrintSensorData(i_parser,"CHOMBWP2M0", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M0]);
    PrintSensorData(i_parser,"CHOMBWP2M1", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M1]);
    PrintSensorData(i_parser,"CHOMBWP2M2", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M2]);
    PrintSensorData(i_parser,"CHOMBWP2M3", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M3]);
    PrintSensorData(i_parser,"CHOMBWP2M4", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M4]);
    PrintSensorData(i_parser,"CHOMBWP2M5", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M5]);
    PrintSensorData(i_parser,"CHOMBWP2M6", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M6]);
    PrintSensorData(i_parser,"CHOMBWP2M7", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP2M7]);
    PrintSensorData(i_parser,"CHOMBWP3M0", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M0]);
    PrintSensorData(i_parser,"CHOMBWP3M1", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M1]);
    PrintSensorData(i_parser,"CHOMBWP3M2", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M2]);
    PrintSensorData(i_parser,"CHOMBWP3M3", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M3]);
    PrintSensorData(i_parser,"CHOMBWP3M4", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M4]);
    PrintSensorData(i_parser,"CHOMBWP3M5", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M5]);
    PrintSensorData(i_parser,"CHOMBWP3M6", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M6]);
    PrintSensorData(i_parser,"CHOMBWP3M7", i_chom->sensorData[i_mode_idx].sensor[VER_1::CHOMBWP3M7]);
    i_parser.PrintDivider();
    i_parser.PrintSectionEnd(true);
}

/*****************************************************************************/
// Print Call Home Data - Version 1
/*****************************************************************************/
static void PrintCallHomeSensors_v1( ErrlUsrParser & i_parser,
                                     const ChomLogData_v1_t * i_chom,
                                     uint32_t i_len,
                                     uint8_t i_modes )
{
    uint8_t i = 0;
    // Do sanity check on the function inputs
    i_parser.PrintHeading("Call Home Sensor Data v1");
    i_parser.PrintNumber("Chomlog expected len", "%d", ntohs(sizeof(ChomLogData_v1_t)));
    if (sizeof(ChomLogData_v1_t) == i_len)
    {
        do
        {
            PrintCallHomeSensors( i_parser, i_chom, i );

            // Error history counts for the slaves
            i_parser.PrintString("Slave Error History Counts", "");

            PrintErrorHistory(i_parser,"Slave 1",
                               i_chom->nodeData.errhCounts[0] );
            PrintErrorHistory(i_parser,"Slave 2",
                               i_chom->nodeData.errhCounts[1] );
            PrintErrorHistory(i_parser,"Slave 3",
                               i_chom->nodeData.errhCounts[2] );

            i++;
        } while (i < i_modes);
    }
    else // unmatched length, dump HEX
    {
        i_parser.PrintString("Unexpected Chom len v1", "");
        i_parser.PrintNumber("Bad Length", "%d", i_len);
        i_parser.PrintNumber("Expected", "%d", sizeof(ChomLogData_v1_t));
        i_parser.PrintHexDump((uint8_t *)i_chom, i_len);
    }
    i_parser.PrintSectionEnd(true);
}

/*****************************************************************************/
// Print Call Home Data - Version 2
/*****************************************************************************/
static void PrintCallHomeSensors_v2( ErrlUsrParser & i_parser,
                                     const ChomLogData_v2_t * i_chom,
                                     uint32_t i_len,
                                     uint8_t i_modes )
{
    uint8_t i = 0;
    i_parser.PrintHeading("Call Home Sensor Data v2");
    if(sizeof(ChomLogData_v2_t) == i_len)
    {
        do
        {
            PrintCallHomeSensors(i_parser,
                                 (ChomLogData_v1_t*)i_chom,
                                 i );

            // Error history counts for the slaves
            i_parser.PrintString("Slave Error History Counts", "");

            PrintErrorHistory(i_parser,"Slave 1",
                               i_chom->nodeData.errhCounts[0] );
            PrintErrorHistory(i_parser,"Slave 2",
                               i_chom->nodeData.errhCounts[1] );
            PrintErrorHistory(i_parser,"Slave 3",
                               i_chom->nodeData.errhCounts[2] );

            // Frequency clip history for the slaves
            i_parser.PrintDivider();
            i_parser.PrintString("Slave Frequency Clip History", "");
            PrintFClipHistory(i_parser,"Slave 1",
                              i_chom->nodeData.fClipHist[0] );
            PrintFClipHistory(i_parser,"Slave 2",
                              i_chom->nodeData.fClipHist[1] );
            PrintFClipHistory(i_parser,"Slave 3",
                              i_chom->nodeData.fClipHist[2] );


            i++;
        } while (i < i_modes);
    }
    else // unmatched length, dump HEX
    {
        i_parser.PrintString("Unexpected Chom len v2", "");
        i_parser.PrintNumber("Bad Length", "%d", i_len);
        i_parser.PrintNumber("Expected", "%d", sizeof(ChomLogData_v2_t));
        i_parser.PrintHexDump((uint8_t*)i_chom, i_len);
    }
    i_parser.PrintSectionEnd(true);
}
/*****************************************************************************/
// OCCC Print Call Home data
/*****************************************************************************/
static void PrintCallHomeData(ErrlUsrParser & i_parser, void * i_buffer, uint32_t i_len)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    uint8_t l_modes = 0;
    // Use version 0 just to get the initial fields to then check version
    const ChomLogData_v0_t * l_chom = (ChomLogData_v0_t *) i_buffer;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    // Determine the number of power modes to be displayed
    l_modes = (l_chom->nodeData.modeInLog > 2 ? 2 : l_chom->nodeData.modeInLog) ;

    i_parser.PrintBlank();
    i_parser.PrintHeading("OCC FFDC Data");
    i_parser.PrintBlank();
    i_parser.PrintNumber("Version", "0x%02X", l_chom->nodeData.version);
    PrintPwrMode(i_parser, "Current Power Mode", l_chom->nodeData.curPwrMode);
    i_parser.PrintNumber("Total Time (seconds)", "%d", ntohs(l_chom->nodeData.totalTime));
    i_parser.PrintNumber("Modes in Log", "%d", l_chom->nodeData.modeInLog);
    i_parser.PrintNumber("Number of Sensors", "%d", ntohs(l_chom->nodeData.numSensors));
    i_parser.PrintNumber("Data Length", "%d", ntohs(i_len));
    // Check the version number
    if( l_chom->nodeData.version == CHOMLOGDATA_VER_0 )
    {
        PrintCallHomeSensors_v0( i_parser, l_chom, i_len, l_modes );
    }
    else if( l_chom->nodeData.version == CHOMLOGDATA_VER_1 )
    {
        const ChomLogData_v1_t * l_chom_1 = (ChomLogData_v1_t *) i_buffer;
        PrintCallHomeSensors_v1( i_parser, l_chom_1, i_len, l_modes);
    }
    else if( l_chom->nodeData.version == CHOMLOGDATA_VER_2 )
    {
        const ChomLogData_v2_t * l_chom_2 = (ChomLogData_v2_t*) i_buffer;
        PrintCallHomeSensors_v2( i_parser, l_chom_2, i_len, l_modes);
    }
    else
    {
        i_parser.PrintString("Invalid Call Home Version Number. Dumping Hex", "");
        i_parser.PrintHexDump((uint8_t*)i_buffer, i_len );
    }
    i_parser.PrintSectionEnd(true);
} // end PrintCallHomeData()


/*****************************************************************************/
// OCCC Display Log Detail Parser
/*****************************************************************************/
static void DisplayOccLog(
    ErrlUsrParser & i_parser,
    void *	    i_buffer,
    uint32_t	    i_buflen
)
{
    const occErrlEntry_t    *l_elog   = (occErrlEntry_t *) i_buffer;
    const occErrlUsrDtls_t  *l_uDtls  = (occErrlUsrDtls_t *)((uint8_t*)l_elog+sizeof(occErrlEntry_t)+(l_elog->numCallouts * sizeof(occErrlCallout_t)) );

    i_parser.PrintBlank();
    char l_tmp[80] ={0};
    sprintf(l_tmp, "OCC Error Log - 0x%02X", l_elog->entryId );
    i_parser.PrintHeading( l_tmp );
    i_parser.PrintBlank();
    i_parser.PrintString("Header",          "" );
    i_parser.PrintNumber("CheckSum",        "0x%04X", ntohs(l_elog->checkSum) );
    i_parser.PrintNumber("Version",         "0x%02X", l_elog->version );
    i_parser.PrintNumber("Entry Id",        "0x%02X", l_elog->entryId );
    i_parser.PrintNumber("Reason Code",     "0x%02X", l_elog->reasonCode );
    PrintSeverity( i_parser, l_elog->severity );
    i_parser.PrintNumber("Extended RC",     "0x%04X", ntohl(l_elog->extendedRC));
    PrintActions( i_parser, l_elog->actions );
    i_parser.PrintNumber("Callout Count",   "0x%02X", l_elog->numCallouts );
    i_parser.PrintBlank();

    i_parser.PrintString("Callout(s)",      "" );
    for (uint32_t x=0; x< l_elog->numCallouts; x++)
    {
        const occErrlCallout_t  *l_co  = (occErrlCallout_t *)((uint8_t*)l_elog+sizeof(occErrlEntry_t)+(x * sizeof(occErrlCallout_t)) );

        if (l_co->type && l_co->priority)
        {
            PrintCalloutType(  i_parser, l_co->type );
            if ( l_co->type == 0x02 )
            {
                PrintCalloutComponentId( i_parser, ntohll(l_co->calloutValue));
            }
            else
            {
                /*no effect*/  memset( l_tmp, sizeof(l_tmp), 0);
                sprintf(l_tmp, "0x%016llX", l_co->calloutValue);
                i_parser.PrintString("Value", l_tmp);
            }
            PrintCalloutPriority( i_parser, l_co->priority );
        }
    }

    i_parser.PrintBlank();
    i_parser.PrintString("User Detail",     "" );
    i_parser.PrintNumber("Version",         "0x%02X", l_uDtls->iv_version );
    i_parser.PrintNumber("Module Id",       "0x%04X", ntohs(l_uDtls->iv_modId));
    PrintOccCompId( i_parser, ntohs(l_uDtls->iv_modId));
    i_parser.PrintNumber("FClip History",  "0x%08X", l_uDtls->iv_fclipHistory);
    /*no effect*/ memset( l_tmp, sizeof(l_tmp), 0);
    sprintf(l_tmp, "0x%016llX", ntohll(l_uDtls->iv_timeStamp));
    i_parser.PrintString("TimeStamp", l_tmp);
    i_parser.PrintNumber("OCC Id",          "0x%02X", l_uDtls->iv_occId );
    PrintOccRole( i_parser, l_uDtls->iv_occRole);
    PrintOccState( i_parser, l_uDtls->iv_operatingState);
    i_parser.PrintString("Committed",        l_uDtls->iv_committed ? "True":"FALSE" );
    i_parser.PrintNumber("User Data 1",     "0x%08X", ntohl(l_uDtls->iv_userData1));
    i_parser.PrintNumber("User Data 2",     "0x%08X", ntohl(l_uDtls->iv_userData2));
    i_parser.PrintNumber("User Data 3",     "0x%08X", ntohl(l_uDtls->iv_userData3));
    i_parser.PrintNumber("Total Log Size",   "%d", ntohs(l_uDtls->iv_entrySize));
    i_parser.PrintNumber("User Details Size","%d", ntohs(l_uDtls->iv_userDetailEntrySize));

    int32_t l_dataLeft = ntohs(l_uDtls->iv_userDetailEntrySize);

    uint8_t *l_p  = (uint8_t*)l_elog+sizeof(occErrlEntry_t)+(l_elog->numCallouts * sizeof(occErrlCallout_t))+ sizeof(occErrlUsrDtls_t);
    while ( (l_dataLeft > 0) && (l_dataLeft > sizeof(occUserDetailsEntry_t)) )
    {
         occUserDetailsEntry_t  *l_UDEntry  = (occUserDetailsEntry_t *) l_p;
         const uint16_t l_detailSize = ntohs(l_UDEntry->iv_size);
         uint8_t *l_detailPtr  = (uint8_t *)(l_UDEntry)+4;

        i_parser.PrintBlank();
        i_parser.PrintString( "User Detail Entry", "" );
        i_parser.PrintNumber("Version", "0x%02X", l_UDEntry->iv_version );
        PrintUDType(  i_parser, l_UDEntry->iv_type );
        i_parser.PrintNumber("Size",    "%d", l_detailSize );

        if ( l_UDEntry->iv_type == 0x01)
        {
            bool l_isxmlparser = (dynamic_cast<ErrlXmlParser*>(&i_parser));
            if(!l_isxmlparser)
            {
              const bool l_traceParsed = PrintTraceData( i_parser, l_elog->checkSum, l_detailPtr, l_detailSize );
              // If trace was not parsed, just dump the hex data
              if (!l_traceParsed)
              {
                i_parser.PrintString("Unparsed OCC trace data", "" );
                i_parser.PrintHexDump(l_detailPtr, l_detailSize);
              }
            }
        }
        else if (l_UDEntry->iv_type == 0x02)
        {
            PrintCallHomeData(i_parser, l_detailPtr, l_detailSize);
        }
        else
        {
            i_parser.PrintHexDump( l_detailPtr, l_detailSize );
        }

        l_dataLeft = l_dataLeft - (sizeof(occUserDetailsEntry_t) + l_detailSize);
        l_p += sizeof(occUserDetailsEntry_t) + l_detailSize;
    }

} // end DisplayOccLog()


void printExceptionString(ErrlUsrParser & i_parser, uint8_t i_exception)
{
    string desc = "";
    switch (i_exception)
    {
        case 0xE0: // ERRL_RC_PANIC
            desc = "Panic";
            break;
        case 0xE1: // ERRL_RC_INIT_CHCKPNT
            desc = "Init Checkpoint";
            break;
        case 0xE2: // ERRL_RC_WDOG_TIMEOUT
            desc = "Watchdog Timeout";
            break;
        case 0xE3: // ERRL_RC_OCB_TIMER
            desc = "OCB Timeout";
            break;
        case 0xE4: // ERRL_RC_OCC_HW_ERROR
            desc = "OCC HW Error";
            break;
        case 0xE5: // ERRL_RC_INIT_FAILURE
            desc = "Init Failure";
            break;
    }
    if (desc != "")
    {
        i_parser.PrintString("", desc.c_str());
    }
}

/*****************************************************************************/
// OCCC Display Log Detail Parser
/*****************************************************************************/
static void PrintExceptionData(ErrlUsrParser & i_parser,
                               void *	    i_buffer,
                               uint32_t	    i_buflen)
{
    uint8_t * l_bufPtr = (uint8_t *)i_buffer;
    uint32_t l_index = 0;

    i_parser.PrintBlank();
    i_parser.PrintHeading("OCC Exception Data");
    i_parser.PrintBlank();
    i_parser.PrintNumber("Sequence", "0x%02X", l_bufPtr[l_index++]);
    i_parser.PrintNumber("Command", "0x%02X", l_bufPtr[l_index++]);
    i_parser.PrintNumber("Exception Code", "0x%02X", l_bufPtr[l_index]);
    printExceptionString(i_parser, l_bufPtr[l_index++]);
    i_parser.PrintNumber("Length", "%d", ntohs(*(uint16_t*)&l_bufPtr[l_index]));
    l_index += 2;
    i_parser.PrintNumber("reserved", "0x%02X", l_bufPtr[l_index++]);
    i_parser.PrintNumber("Checkpoint", "0x%04X", ntohs(*(uint16_t*)&l_bufPtr[l_index]));
    l_index += 2;
    i_parser.PrintNumber("SSX Panic Code", "0x%08X", ntohl(*(uint32_t*)&l_bufPtr[l_index]));
    l_index += 4;
    i_parser.PrintNumber("Panic Address", "0x%08X", ntohl(*(uint32_t*)&l_bufPtr[l_index]));
    l_index += 4;
    // Dump all data in hex (so offsets match code)
    i_parser.PrintString( "Exception Data", "" );
    i_parser.PrintHexDump(i_buffer, i_buflen);
}


/*****************************************************************************/
// Plugin entry point
// If this function returns false, the raw hex data will be displayed by errl
/*****************************************************************************/
bool LogDataParse(ErrlUsrParser & i_parser,
                  void *	    i_buffer,
                  uint32_t	    i_buflen,
                  errlver_t	    i_ver,
                  errlsubsec_t    i_sst)
{
    bool l_parsedData = false;

    // Decode
    switch( i_sst )
    {
        //Usr Details Section
        case OCC_FULL_ELOG_TYPE:
            if ( i_ver == OCC_FULL_ELOG_TYPE_VER1 )
            {
                DisplayOccLog( i_parser, i_buffer, i_buflen );
                l_parsedData = true;
            }
            break;

        case 0x02: // OCC_TRACE TYPE
           {
            bool l_isxmlparser = (dynamic_cast<ErrlXmlParser*>(&i_parser));
            if(!l_isxmlparser)
            {
              i_parser.PrintNumber("OCC Trace Size", "%d", i_buflen);
              l_parsedData = PrintTraceData(i_parser, 0x1234, (uint8_t*)i_buffer, ntohs(i_buflen), true /* update length */);
            }
           }
           break;

        default:
            if ((i_sst & 0xE0) == 0xE0) // OCC Exception
            {
                PrintExceptionData(i_parser, (uint8_t*)i_buffer, ntohs(i_buflen));
                l_parsedData = true;
            }

            break;
    }

    return l_parsedData;

}

