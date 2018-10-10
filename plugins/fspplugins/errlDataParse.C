// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/errl/fsp/plugins/errlDataParse.C 1.1.9.21 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2003,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/**
 *  @file errlDataParse.C
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section ERRLDATAPARSE_C errlDataParse.C
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *  ---  ----???    vmena     10/15/03  Created
 *  ---  441925     tapiar    03/10/04  added print for syslog structure
 *  ---  441683     tapiar    03/12/04  added better displaying to syslog::print
 *  ---  441683     vmena     03/12/04  Code Review:
 *					-Probably better to check for iv_name
 *					 than iv_val
 *  ---  450044     tapiar    04/23/04  Upd: fix pid endianness problem
 *  ---  D452741    vmena     06/03/04  NFP Updates
 *                                      -Use ERRL_TOOLS for objects needing a
 *                                       recompile in the tools directory
 *                                      -Modified makefile hierarchy to allow
 *                                       the proper compilation of plugins +
 *                                       parser into static form
 *                                      -Modified parser to accept binary data
 *                                       through redirection as well as piping
 *                                      -Added debug level output to the parser
 *                                       from the library code
 *  ---  F460449    vmena     06/30/04  FSP Call Home + Performance
 *  ---  F451952    vmena     08/31/04  Upd: Parse out the backtrace
 *  ---  F473401    vmena     09/20/04  Update the backtrace parse ( disable )
 *  ---  F480309    vmena     04/21/05  Redundant FSP Support:
 *                                      -Parse out new ver 2 data section
 *  ---  D565441    tapiar    08/21/06  Upd: hide rfsp info if log comes from BPC
 *  ---  D588957    tapiar    08/11/07  Upd: add user default section 3 parsing
 *  ---  D626174    tapiar    08/28/07  Upd: add nc role to ud3
 *  ---  D573819    tapiar    09/21/07  Upd: add parser for fsp states ud
 *  ---  D636286    vishal1   11/16/07  Add: SMGR IPL type parser data
 *  ---  D649906    minamdar  03/14/08  Add: SMGR IPL type parser data
 *  ---  D684920    minamdar  10/30/08  Upd: Add Redundancy Policy status to ud2
 *  ---  F685130    minamdar  24/12/08  Upd: Print Hypervisor Mode status in ud2
 *  ---  D696420    minamdar  02/18/09  Upd: Add nfp library condition for smgr
 *  mi01 SW136582   minamdar  05/10/12  Add: x86.nfp errl compilation error    
 *  mi02 SW133501   minamdar  07/08/12  Upd: Remove nmgr dependency
 *  mi03 SW169620   minamdar  10/15/12  Upd: Remove Errldata3 for x86
 *  mi04 D865952    minamdar  01/21/13  Upd: Sibling State Update for PEL Events
 *  ri01 F909809    rilonapp  01/06/14  Add: DPSS smgr ipl types
 *  ri02 SW249776   rilonapp  02/23/14  Add: DisplayDebugTracing 
 *  ri03 SW254953   rilonapp  04/11/14  Rem: DPSS SMGR types
 *  fk01 D923085    fmkassem  04/23/14  Corr: Add parser for corrosion sensor data.
 *  sm01 SW265397   sampmisr  08/27/14  Add: DPSS smgr ipl types
 *  sm02 SW283416   sampmisr  11/05/14  Fix Beam errors
 *       SW411728   manojeda  02/06/18  Remove Support for ExtractExitError
 *
 *  @endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlplugins.H>
#include <errlusrparser.H>
#include <errlutility.H>
#include <errl_service_codes.H>
#include <srcisrc.H>
#include <rtim.H>
#include <errlDataParse.H> //@fk01a
#include <errlxmlparser.H>            // for ErrlXmlParser

//#include <string>
#include <string.h>         //mi01C


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
static errl::DataPlugin    g_DataPlugin( ERRL_COMP_ID, LogDataParse );

/*****************************************************************************/
// Given a uint32_t unixTime (number of seconds since unix base date), this
// function returns a string of the formatted corresponding date.
/*****************************************************************************/
char * errlGetTimeStamp(uint32_t i_unixTime)
{
    uint32_t l_timeStamp = ntohl(i_unixTime); //making sure that byte order is correct.
    time_t l_tempTime = (time_t) l_timeStamp;
    char *l_charFormattedDateTime = ctime(&l_tempTime);
    //Replace new line with end of line.
    memcpy (&l_charFormattedDateTime[24],"\0",1);

    return l_charFormattedDateTime;
}

//@fk01a
/*****************************************************************************/
// Parse Corrosion sensor entries
/*****************************************************************************/
void parseCorrDataEntry (ErrlUsrParser  &i_parser, corrosionData_t i_corrEntry, bool i_isoutputxml)
{
    float l_tempFloat = 0;
    float l_tempF = 0;
    char *l_formattedDateTime = errlGetTimeStamp(i_corrEntry.timestamp);
    char l_string[68 + (sizeof(float)*3) + sizeof(l_formattedDateTime) + sizeof(i_corrEntry.thicknessConsumed) ];
    
    if (ntohs(i_corrEntry.temperature) < 0xFF00)
    {
	    l_tempFloat = ntohs(i_corrEntry.temperature) * CORR_TEMP_MULTIPLER;
	    l_tempF = l_tempFloat * 9 / 5 + 32;
    }
      float l_tmpResist = i_parser.HandleFloatNumber(i_corrEntry.resistance);
    if(!i_isoutputxml)
    {
    //                 Resistance          Temp(C/F)           Thickness
      snprintf(l_string, sizeof(l_string), "|  %6.6f    |   %6.2f/%6.2f  |    %d", 
           l_tmpResist, l_tempFloat, l_tempF, ntohs(i_corrEntry.thicknessConsumed));
      i_parser.PrintString(l_formattedDateTime,l_string);
      switch (ntohs(i_corrEntry.temperature))
      {
	case CORR_TEMPERATURE_DEVICE_ERROR:
	    i_parser.PrintString(">>>> Error: CORR_TEMPERATURE_DEVICE_ERROR", NULL);
	    break;
	case CORR_SEEPROM_DEVICE_ERROR:
	    i_parser.PrintString(">>>> Error: CORR_SEEPROM_DEVICE_ERROR", NULL);
	    break;
	case CORR_CORROSION_DEVICE_ERROR:
	    i_parser.PrintString(">>>> Error: CORR_CORROSION_DEVICE_ERROR", NULL);
	    break;
	case CORR_SENSOR_END_OF_LIFE:
	    i_parser.PrintString(">>>> Error: CORR_SENSOR_END_OF_LIFE", NULL);
	    break;
	default:
	    break;
      };
    }
    else
    {
      i_parser.PrintHeading("Corrosion Reading");
      i_parser.PrintString("Timestamp",l_formattedDateTime);
      i_parser.PrintFloatNumber("Resistance","%f",l_tmpResist);
      i_parser.PrintFloatNumber("Temperature(C)","%f",l_tempFloat);
      i_parser.PrintFloatNumber("Temperature(F)","%f",l_tempF);
      i_parser.PrintFloatNumber("Thickness","%f",i_corrEntry.thicknessConsumed);
      i_parser.PrintSectionEnd(true);
    }

}

//@fk01a
/*****************************************************************************/
// Parse Corrosion sensor user data (ERRL_UDT_CORR)
/*****************************************************************************/
bool parseCorrData( ErrlUsrParser  &i_parser,
                    void           *i_buffer,
                    uint32_t        i_buflen,
                    errlver_t       i_ver,
                    errlsubsec_t    i_sst,
                    bool            i_outputisxml)
{
    bool    l_rc = true;
    char l_string[64];
    uint16_t l_index = 0;

    if ((i_buffer == NULL) && (i_buflen == 3700))
    {
        i_parser.PrintNumber("Buffer size is invalid:", "%d bytes", i_buflen); 
        l_rc = false;
    }
    else if ( i_buffer == NULL )                                                        //sm02a
    {
         i_parser.PrintString("Buffer is"," NULL");
         l_rc = false;
    }
    else
    {
        if(!i_outputisxml)
        {
          corrosionHistoryFile_t *l_corrData = (corrosionHistoryFile_t *) i_buffer;

          i_parser.PrintNumber("BufferSize", "%d bytes", i_buflen);                                                       //Buffer Size
          i_parser.PrintBlank();
          i_parser.PrintHeading("CORROSION DATA HEADER");                                                                 //Header

          sprintf(l_string, "%x", ntohs(l_corrData->header.dataLayoutVersion));                                                  //EyeCatcher/version
          i_parser.PrintString("Eyecatcher/version",l_string);          
          i_parser.PrintTimeStamp("Genesis reading timestamp", (l_corrData->header.initialTimestamp) );                     //Genesis timestamp.

          //Used to show the base time of the host system.
        
          i_parser.PrintString("Host Base Time",errlGetTimeStamp(0x00));

          sprintf(l_string, "%x", ntohs(l_corrData->header.thicknessConsumedPrevCards));                                         //thicknessConsumedPrevCards
          i_parser.PrintString("Thickness consumed on prev Cards", l_string);
          i_parser.PrintDivider();
          i_parser.PrintHeading("INITIAL READING FROM CURRENT CARD");
          i_parser.PrintString("Date/time          ","| Resistance   |    Temp(C/F)     | Thickness");
          i_parser.PrintString("-------------------","| -----------  |    ---------     | -------------");
          parseCorrDataEntry(i_parser, l_corrData->header.initialReading,false);
          i_parser.PrintDivider();
          i_parser.PrintHeading("TWO HOUR READINGS");
          i_parser.PrintString("Date/time          ","| Resistance   |    Temp(C/F)     | Thickness");
          i_parser.PrintString("-------------------","| -----------  |    ---------     | -------------");
          for( l_index = 0; (l_index < CORR_TWO_HOUR_READING_TBL_SIZE) && (l_corrData->twoHourReadings[l_index].timestamp != 0); l_index++ )
          {
            parseCorrDataEntry(i_parser, l_corrData->twoHourReadings[l_index],false );
          }
          i_parser.PrintDivider();
          i_parser.PrintHeading("DAILY AVERAGE READINGS");
          i_parser.PrintString("Date/time          ","| Resistance   |    Temp(C/F)     | CorrosionRate");
          i_parser.PrintString("-------------------","| -----------  |    ---------     | -------------");
          for( l_index = 0; (l_index < CORR_DAILY_READING_TBL_SIZE) && (l_corrData->dailyAverages[l_index].timestamp != 0); l_index++ )
          {
            parseCorrDataEntry(i_parser, l_corrData->dailyAverages[l_index],false );
          }

          i_parser.PrintDivider();
          i_parser.PrintHeading("WEEKLY AVERAGE READINGS");
          i_parser.PrintString("Date/time          ","| Resistance   |    Temp(C/F)     | CorrosionRate");
          i_parser.PrintString("-------------------","| -----------  |    ---------     | -------------");
          for( l_index = 0; (l_index < CORR_WEEKLY_READING_TBL_SIZE) && (l_corrData->weeklyAverages[l_index].timestamp != 0); l_index++ )
          {
            parseCorrDataEntry(i_parser, l_corrData->weeklyAverages[l_index],false);
          }

          //The last 9 entries in weeklyAverages are populated with raw data from the last reading made unless
          //the corrosion sensor has 250 weeks worth of data, thus the entries are used for those weekly entries instead.

          //Make sure we haven't reached the 250 week marker, if not then display the raw data for the last read.
          if (l_corrData->weeklyAverages[250].timestamp == 0)
          {
            corrosionReadings_t *l_lastReadings = (corrosionReadings_t *)(void *)&(l_corrData->weeklyAverages[251]);
            i_parser.PrintDivider();
            i_parser.PrintHeading("LAST ENTRY RAW DATA");

            i_parser.PrintString("Date/time of reading", errlGetTimeStamp(l_lastReadings->timestamp));
            i_parser.PrintNumber("Raw temperature reading","%X", ntohs(l_lastReadings->tempRawReading));
            i_parser.PrintNumber("Corrosion sensor read attempts","%d", ntohs(l_lastReadings->corrReadAttempts));
            i_parser.PrintHeading("Raw resistance readings");
            for( l_index = 0; (l_index < 20); l_index+=4 )
            {
                snprintf(l_string, sizeof(l_string), " %X,   %X,   %X,   %X", 
                        ntohl(l_lastReadings->corrRawReadings[l_index]), ntohl(l_lastReadings->corrRawReadings[l_index+1]),
                        ntohl(l_lastReadings->corrRawReadings[l_index+2]),ntohl(l_lastReadings->corrRawReadings[l_index+3]));
                char l_labelStr[64];
                snprintf(l_labelStr, sizeof(l_labelStr),"Values %2d to %2d", l_index+1, l_index+4);
                i_parser.PrintString(l_labelStr, l_string);
            }
          }
        }
        else //XML version of parser output
        {
          corrosionHistoryFile_t *l_corrData = (corrosionHistoryFile_t *) i_buffer;

          i_parser.PrintHeading("CORROSION DATA");                                                                 //Header
          i_parser.PrintHeading("CORROSION DATA HEADER");                                                                 //Header

          sprintf(l_string, "%x", ntohs(l_corrData->header.dataLayoutVersion));                                                  //EyeCatcher/version
          i_parser.PrintString("Eyecatcher/version",l_string);          
          i_parser.PrintTimeStamp("Genesis_reading_timestamp", (l_corrData->header.initialTimestamp) );                     //Genesis timestamp.

          //Used to show the base time of the host system.
        
          i_parser.PrintString("Host Base Time",errlGetTimeStamp(0x00));

          i_parser.PrintNumber("Thickness_consumed_on_prev_Cards","%d",ntohs(l_corrData->header.thicknessConsumedPrevCards) );
          i_parser.PrintSectionEnd(true);
          i_parser.PrintHeading("INITIAL READING FROM CURRENT CARD");
          parseCorrDataEntry(i_parser, l_corrData->header.initialReading,true);
          i_parser.PrintSectionEnd(true);
          i_parser.PrintHeading("TWO_HOUR_READINGS");
          for( l_index = 0; (l_index < CORR_TWO_HOUR_READING_TBL_SIZE) && (l_corrData->twoHourReadings[l_index].timestamp != 0); l_index++ )
          {
            parseCorrDataEntry(i_parser, l_corrData->twoHourReadings[l_index],true );
          }
          i_parser.PrintSectionEnd(true);
          i_parser.PrintHeading("DAILY_AVERAGE_READINGS");
          for( l_index = 0; (l_index < CORR_DAILY_READING_TBL_SIZE) && (l_corrData->dailyAverages[l_index].timestamp != 0); l_index++ )
          {
            parseCorrDataEntry(i_parser, l_corrData->dailyAverages[l_index],true );
          }
          i_parser.PrintSectionEnd(true);
          i_parser.PrintHeading("WEEKLY_AVERAGE_READINGS");
          for( l_index = 0; (l_index < CORR_WEEKLY_READING_TBL_SIZE) && (l_corrData->weeklyAverages[l_index].timestamp != 0); l_index++ )
          {
            parseCorrDataEntry(i_parser, l_corrData->weeklyAverages[l_index],true);
          }
          i_parser.PrintSectionEnd(true);

          //The last 9 entries in weeklyAverages are populated with raw data from the last reading made unless
          //the corrosion sensor has 250 weeks worth of data, thus the entries are used for those weekly entries instead.

          //Make sure we haven't reached the 250 week marker, if not then display the raw data for the last read.
          if (l_corrData->weeklyAverages[250].timestamp == 0)
          {
            corrosionReadings_t *l_lastReadings = (corrosionReadings_t *)(void *)&(l_corrData->weeklyAverages[251]);
            i_parser.PrintHeading("LAST_ENTRY_RAW_DATA");

            i_parser.PrintString("Timestamp", errlGetTimeStamp(l_lastReadings->timestamp));
            i_parser.PrintNumber("Raw_temperature_reading","%X", ntohs(l_lastReadings->tempRawReading));
            i_parser.PrintNumber("Corrosion_sensor_read_attempts","%d", ntohs(l_lastReadings->corrReadAttempts));
            i_parser.PrintHeading("Raw_resistance_readings");
            for( l_index = 0; (l_index < 20); l_index++ )
            {
                i_parser.PrintNumber("Raw_reading","%X",ntohl(l_lastReadings->corrRawReadings[l_index]));
            }
            i_parser.PrintSectionEnd(true);
            i_parser.PrintSectionEnd(true);
          }
            i_parser.PrintSectionEnd(true);
        }
    }



    return l_rc;
}

/*****************************************************************************/
// Plugin entry point
/*****************************************************************************/
bool LogDataParse(
    ErrlUsrParser & i_parser,
    void *	    i_buffer,
    uint32_t	    i_buflen,
    errlver_t	    i_ver,
    errlsubsec_t    i_sst
)
{
    // Locals
    bool	    l_rc = true;
    bool            l_outputIsXml = false;

    // Decode
    switch( i_sst )
    {

    case ERRL_UDT_CORR:
     {
        l_outputIsXml = (dynamic_cast<ErrlXmlParser*>(&i_parser)); 
        l_rc = parseCorrData(i_parser, i_buffer, i_buflen, i_ver, i_sst, l_outputIsXml );
     } 
        break;

	default:
	    l_rc = false;
    }

    return l_rc;

}

