// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/powr/fsp/plugins/powrLogParse.C 1.9 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2006,2017 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 

/*****************************************************************************************************************************
 *  CHANGE ACTIVITY:
 *
 *  Flag  Track    Release      Date     Userid    Comments
 *  ----- -------- -----------  -------- --------- -------------------------------
 *  @000  SW318447 fips910      08/14/15 minglw    Port 840 to 910
 *  
 *  END CHANGE ACTIVITY
*****************************************************************************************************************************/

#ifndef _X86NFP
#include <common.h> 
#endif
#include <ctype.h> // toupper
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errlusrparser.H>
#include <errlplugins.H>
#include <powr_service_codes.H>       // for sub-section types
#include <powrVrmTelemetryParser.H>   // for VrmTelemetryParser
#define powr_C
#define MAX_TRACE_BUFFER 32*1024
#include <powr_pte.h>

#ifndef _AIX
#define FALSE 0
#define TRUE (!FALSE)
#endif
// Put symbols in the powr namespace.  Otherwise they conflict with identical
// symbol names in other components when the errl plugin is built on x86.
namespace powr
{

void strupr(char *string);
uint32_t getHex(char * string, uint32_t len);
char *formatTimestamp(uint32_t timestamp);
uint32_t readErrlFile(char *name, ErrlUsrParser& i_parser);
void print_header(ErrlUsrParser& i_parser);
void print_entry(uint32_t timestamp, char *rack, char *unit, char *pte, ErrlUsrParser& i_parser);
char * get_pte_comment(char *pte);
void format_poll_flags(const uint8_t flags, char *results);
void format_cage_flags(const uint8_t flags, char *results);


uint32_t G_pte_file_info = FALSE; // Dump filename/function for PTE entries
uint32_t G_DEBUG = 0;


void strupr(char *string)
{

  for(uint32_t l_index = 0; l_index < strlen(string); l_index++)
    string[l_index] = toupper(string[l_index]);
}


uint32_t getHex(char * string, uint32_t len)
{
  char ch[64];
  uint32_t val;

  if (len > 4)
  {
    printf("powr_util.C:getHex(%s,%d) - invalid length\n", string, len);
    len = 4;
  }
  strncpy(ch, string, len*2);
  ch[len*2] = '\0';
  sscanf(ch, "%x", &val);
  // could use 	sscanf(s, "%2x%2x", &i, &j);

  return val;
}


char *formatTimestamp(uint32_t timestamp)
{
  uint32_t hh, mm, ss;
  static char time_string[32];
  static uint32_t previous_time = 0;

  if (timestamp != 0xFFFF)
  {
    hh = (timestamp / 3600);
    mm = (timestamp - (hh*3600)) / 60;
    ss = timestamp - (hh*3600) - (mm*60);

    sprintf(time_string, "%3d:%02d:%02d", hh, mm, ss);
  }
  else
  {
    sprintf(time_string, "  --------");
  }

  previous_time = timestamp;

  return time_string;
}


uint32_t readErrlFile(char *name, ErrlUsrParser& i_parser)
{

  print_header(i_parser);

  while (static_pte_entry_table[G_pte_entry_count].key[0] != '\0') G_pte_entry_count++;

  for (uint32_t l_index = 0; l_index < strlen(name); )
  {
    if ( getHex(&name[l_index+4],1) != 0xFE )
    {
      l_index += 2;
    }
    else
    {
      if (l_index <= strlen(name) - 24)
      {
        uint32_t timestamp = getHex(&name[l_index],2);
        print_entry(timestamp, &name[l_index+6], &name[l_index+10], &name[l_index+16], i_parser);
        if (strncmp(&name[l_index], &name[l_index+12], 4) != 0) printf("/\\__timestamp mismatch__/\\ (%.2s vs %.2s)\n", &name[l_index], &name[l_index+12]);
      }
      l_index += 24;
    }
  }
  return 0;
}


/* Returns true if thie PTE is an error (based on get_pte_color) */
bool is_error_pte(char *orig_pte)
{
  unsigned int index=0, jj, key_len;
  char pte[9];
  bzero(pte, sizeof(pte)); // @02A - zero the pte for safety with the strupr function

  strncpy(pte, orig_pte, 8);
  strupr(pte);

  for (index = 0; index < G_pte_entry_count; ++index)
  {
    key_len = strlen(static_pte_entry_table[index].key);

    for (jj = 0; jj < key_len; ++jj)
    {
      if ( (static_pte_entry_table[index].key[jj] != '*') &&
           (static_pte_entry_table[index].key[jj] != pte[jj]) )
      {
        break;
      }
    }
    if (jj < key_len) continue; // no match on this entry

    break; // match found
  }

  if (index < G_pte_entry_count)
  {
    return (static_pte_entry_table[index].color == C_ERROR);
  }

  return(FALSE);
}


void print_header(ErrlUsrParser& i_parser)
{
  char header[1024];
  sprintf(header, " ");
  i_parser.PrintString("", header);
  sprintf(header, "description");
  i_parser.PrintString(" hh:mm:ss rrrruupppppppp", header);
  sprintf(header, "------------------------------------------");
  i_parser.PrintString(" -----------------------", header); 
}


void print_entry(uint32_t timestamp, char *rack, char *unit, char *pte, ErrlUsrParser& i_parser)
{
  char label[1024];
  char descrip[1024];
  char error_flag = ' ';

  if ( is_error_pte(pte) )
  {
    error_flag = '*';
  }
  sprintf(label, "%s %.4s%.2s%.8s%c", formatTimestamp(timestamp), rack, unit, pte, error_flag);
  snprintf(descrip, sizeof(descrip), "%s", get_pte_comment(pte)); 
  i_parser.PrintString(label, descrip);
}


char * get_pte_comment(char *orig_pte)
{
  uint32_t l_index=0;
  uint32_t jj, arg_count;
  static uint32_t ls_ignore_lines = 0, ls_ignore_type = 0;
  static char comment[255], pte[64];

  bzero(pte, sizeof(pte)); // @02A - zero the pte for safety with the strupr function
  sprintf(comment, "Undefined");
  strncpy(pte, orig_pte, 8);
  strupr(pte);

  if (ls_ignore_lines > 0)
  {

    char priority_string[64] = "";

    if (G_DEBUG > 0) printf("DEBUG: get_pte_comment(%.8s): ignore_lines=%d - 8, type=0x%08X", orig_pte, ls_ignore_lines, ls_ignore_type);
    ls_ignore_lines -= 8;
    comment[0]='\0';
    switch(getHex(&pte[0], 1))
    {
      case 0x00: strcpy(priority_string, " Critical"); break;
      case 0x01: strcpy(priority_string, " Critical"); break;
      case 0x02: strcpy(priority_string, " Non-Critical"); break;
    }
    switch (ls_ignore_type)
    {
        // 1807 => powr_fsp_bpc_handlers.C, BPCRackClass::sendBpcSrcToElwq()
      case 0x1807: sprintf(comment, "BPC SRC (priority=0x%.2s%s, SRC=0x%.4s)", &pte[0], priority_string, &pte[4]); break;

        // 1820 => powr_fsp_bpc_handlers.C, BPCRackClass::handleBpcFipsLogResponse()
      case 0x1820: sprintf(comment, "BPC SRC being committed (priority=0x%.2s%s)", &pte[0], priority_string); break;
      default: ;
    }
  }
  else
  {
    uint32_t data0 = 0, data1 = 0 , data2 =0, data3 = 0;

    for (l_index = 0; l_index < G_pte_entry_count; ++l_index)
    {
      uint32_t key_len;

      key_len = strlen(static_pte_entry_table[l_index].key);
      for (jj = 0; jj < key_len; ++jj)
      {
        if ( (static_pte_entry_table[l_index].key[jj] != '*') &&
             (static_pte_entry_table[l_index].key[jj] != pte[jj]) )
        {
          break;
        }
      }
      if ((jj < key_len) || (static_pte_entry_table[l_index].format[0] == '\0') ) continue; // no match on this entry

      break; // match found
    }

    data0 = getHex(&pte[0], 1);
    data1 = getHex(&pte[2], 1);
    data2 = getHex(&pte[4], 1);
    data3 = getHex(&pte[6], 1);

    if (l_index < G_pte_entry_count)
    {
      // Matching PTE was found...

      /* 
       00175359.143898| 6285|POWR            | 280|3c00000018800a00
       00175359.144042| 6285|POWR            | 280|ffffffffffff0014
       00175359.144108| 6285|POWR            | 280|55393131382e3537
       00175359.144160| 6285|POWR            | 280|352e305351494832
       00175359.143822| 6285|POWR            | 280|322d503100306400
       00175359.143898| 6285|POWR            | 280|3c00000018800a00
       */
      if (strncmp(static_pte_entry_table[l_index].format, "HEX DUMP", 8) == 0)
      {
        ls_ignore_lines = data3;
        if ( ls_ignore_lines > 64 )
        {
          ls_ignore_lines = 64;
        }
        ls_ignore_type = 0;
      }

      /* 0x1807 - BPC SRC follows
       |   00000360     002FFE3C  0001002F  21502406  002FFE3C     ./.<.../!P$../.<   |
       |   00000370     0001002F  11001000  002FFE3C  0001002F     .../...../.<.../   |
       |   00000380     11001000  0032FE3C  00010032  21500A01     .....2.<...2!P..   |
       |   00000390     0032FE3C  00010032  27000A01  003DFE3C     .2.<...2'....=.<   |
       |   000003A0     0000003D  18000361  003DFE3C  0000003D     ...=...a.=.<...=   |
       |   000003B0     18204D61  003DFE3C  0000003D  18000461     . Ma.=.<...=...a   |
       |   000003C0     003EFE3C  0000003E  18204D61  003FFE3C     .>.<...>. Ma.?.<   |
       |   000003D0     007B003F  1807FF8D  003FFE3C  007B003F     .{.?.....?.<.{.?   |
       |   000003E0     02000072  003FFE3C  0000003F  18018DEF     ...r.?.<...?....   |
       |   000003F0     0040FE3C  00000040  182100EF               .@.<...@.!..       |
       */
      if ((data0 == 0x18) && (data1 == 0x07)) {
        ls_ignore_lines = 8;
        ls_ignore_type = 0x1807;
      }
      // 182000EF => BPC: Retrieve power error fips log rsp (status=0x00, cmd=0xEF)
      if ((data0 == 0x18) && (0x20 == (data1 & 0xFE)) && (data2 == 0x00) && (data3 == 0xEF)) {
        ls_ignore_lines = 8; // Only ignore PTE data if success (data2==0)
        ls_ignore_type = 0x1820;
      }

      arg_count = 0;
      for (jj = 0; jj < strlen(static_pte_entry_table[l_index].format); ++jj)
      {
        if (static_pte_entry_table[l_index].format[jj] == '%') arg_count++;
      }
      switch(arg_count)
      {
        case 1: sprintf(comment, static_pte_entry_table[l_index].format, data3); break;
        case 2: sprintf(comment, static_pte_entry_table[l_index].format, data2, data3); break;
        case 3: sprintf(comment, static_pte_entry_table[l_index].format, data1, data2, data3); break;
        default: strcpy(comment, static_pte_entry_table[l_index].format);
      }

      ////////////////////////////////////////////////
      // Exceptions/Modifications to trace entries
      ////////////////////////////////////////////////

      if ( (data0 == 0x18) && (data1 == 0xEC) )
      {
        // 18EC0308 => BPC: Failed Connection Status Changed (conn 3, status=0x08) (NETC Connect Timeout)
        switch(data3)
        {
          case 0x01: strcat(comment, " (NETC Connect Failure)"); break;
          case 0x02: strcat(comment, " (NETC GetVersion Failure)"); break;
          case 0x03: strcat(comment, " (NETC VerifyPassword Failure)"); break;
          case 0x04: strcat(comment, " (Connect Table Full Failure)"); break;
          case 0x05: strcat(comment, " (NETC Send Failure)"); break;
          case 0x06: strcat(comment, " (NETC Receive Failure)"); break;
          case 0x07: strcat(comment, " (NETC Receive Timeout)"); break;
          case 0x08: strcat(comment, " (NETC Connect Timeout)"); break;
          case 0x09: strcat(comment, " (NETC GetVersion Timeout)"); break;
          case 0x0A: strcat(comment, " (NETC VerifyPassword Timeout)"); break;
          default:
              if (data3 >= 0x80)
              {
                snprintf(comment, sizeof(comment), "%s (BPC Status: 0x%02X)", comment, data3 & 0x7F); 
              }
              break;
        }
      }
      if ( (data0 == 0x18) && ( (data1 & 0xFE) == 0x20) && (data2 != 0) )
      {
        // Flag any non-zero status from BPC response
        // 18214d81 ==> BPC: Power off rsp (status=0x4d, cmd=0x81) "PCI Initialization in Progress"
        char *stat_ptr = NULL;
        if ( (stat_ptr = strstr(comment, "status=")) != NULL)
        {
          char status_string[255] = "";

          switch(data2)
          {
                  // BPC Status Codes
              case 0x21: strcpy(status_string, "Cage Not Present/Configured"); break;
              case 0x22: strcpy(status_string, "FRU Not Present/Configured"); break;
              case 0x23: strcpy(status_string, "No Normal Power Boundary Requested"); break;
              case 0x24: strcpy(status_string, "Neither BPC can see all DCAs"); break;
              case 0x25: strcpy(status_string, "Invalid Destination"); break;
              case 0x26: strcpy(status_string, "Invalid Source"); break;
              case 0x30: strcpy(status_string, "Invalid Data from Host"); break;
              case 0x43: strcpy(status_string, "Invalid Indicator Op for this FRU"); break;
              case 0x45: strcpy(status_string, "No App Space Available"); break;
              case 0x46: strcpy(status_string, "FRU doesn't have Downloadable Code"); break;
              case 0x47: strcpy(status_string, "FRU doesn't have Downloadable Table"); break;
              case 0x48: strcpy(status_string, "No Cage Translation Data Available"); break;
              case 0x4A: strcpy(status_string, "Error in Sent Command"); break;
              case 0x4B: strcpy(status_string, "Invalid State for Command"); break;
              case 0x4C: strcpy(status_string, "PCI Data Invalid"); break;
              case 0x4D: strcpy(status_string, "PCI Initialization in Progress"); break;
              case 0x4E: strcpy(status_string, "No Master DCA"); break;
              case 0x4F: strcpy(status_string, "JTAG Error"); break;
              case 0x52: strcpy(status_string, "System Busy"); break;
              case 0x55: strcpy(status_string, "System Standby in Progress"); break;
              case 0x5A: strcpy(status_string, "System Timed Out"); break;
              case 0x73: strcpy(status_string, "Requested Log Not Available"); break;
              case 0x88: strcpy(status_string, "VPD Write Failed"); break;
              case 0x9C: strcpy(status_string, "Thermal Calibration in Progress"); break;
              case 0x9D: strcpy(status_string, "Current Balance in Progress"); break;
              case 0xFE: strcpy(status_string, "SPCN Never Sent Command"); break;
          }
          if (status_string[0] != '\0') snprintf(comment, sizeof(comment), "%s - %s", comment, status_string);
        }
      }

      // PTE: 1830xxxx
      if ( (data0 == 0x18) && (data1 == 0x30) && (data2 != 0) )
      {
        // Flag any BPC poll status changes
        // 1830A400 ==> BPC POLL status change (flags=0xA4, port=0)
        strcat(comment, "  ");
        format_poll_flags(data2, comment);
      }

      // PTE: 1803xxxx (Ethernet Comm failure)
      if ( (data0 == 0x18) && (data1 == 0x03) )
      {
        // 1803f721 => BPC: Comm failed (status=0xF7, cmd=POLL, fail_count|port=0x21) (RSP Timeout)
        switch(data2)
        {
                // sqh/powr_fsp_bpcdefs.h
            case 0xF1: strcat(comment, " (Eth Comm Failure)"); break;
            case 0xF5: strcat(comment, " (PTLIC Timeout)"); break;
            case 0xF6: strcat(comment, " (ACK Timeout)"); break;
            case 0xF7: strcat(comment, " (RSP Timeout)"); break;
            case 0xF8: strcat(comment, " (Unknown ACK Type)"); break;
            case 0xF9: strcat(comment, " (Busy)"); break;
            case 0xFE: strcat(comment, " (Command Not Sent)"); break;
            case 0xFF: strcat(comment, " (Processing)"); break;
        }
      }

      // PTE: 1805xxxx (UART Comm failure)
      if ( (data0 == 0x18) && (data1 == 0x05) )
      {
        // 1805E721 => BPC UART: Comm failure (status=0xE7, fail_count|port=0x21) (RSP Timeout)
        switch(data2)
        {
                // sqh/powr_fsp_bpcdefs.h
            case 0xE7: strcat(comment, " (RSP Timeout)"); break;
            case 0xE8: strcat(comment, " (Packet Incomplete)"); break;
            case 0xE9: strcat(comment, " (Bad CRC)"); break;
            case 0xFE: strcat(comment, " (UART Read Fail)"); break;
            case 0xFF: strcat(comment, " (Processing)"); break;
        }
      }
      if ( (data0 == 0x19) && (data2 != 0) )
      {
        // Flag any BPC poll cage status changes
        // 19017020 ==> BPC_POLL status change - cage=0x01, status=0x70, type|port=0x20 (0x70=Visible,Standby_Power_On,Power_On)
        strcat(comment, "  ");
        format_cage_flags(data2, comment);
      }

      // Add PTE Location if known (file/function)
      if (G_pte_file_info)
      {
        if (static_pte_entry_table[l_index].file[0] != '\0')
        {
          if (static_pte_entry_table[l_index].function[0] != '\0')
          {     
            snprintf(comment, sizeof(comment), "%s         => %s - %s", comment, static_pte_entry_table[l_index].file, static_pte_entry_table[l_index].function); 
          }
          else
          {
            snprintf(comment, sizeof(comment), "%s         => %s", comment, static_pte_entry_table[l_index].file); 
          }
        }
        else if (static_pte_entry_table[l_index].function[0] != '\0')
        {     
          snprintf(comment, sizeof(comment), "%s         => %s", comment, static_pte_entry_table[l_index].function); 
        }
      }
    }

    if ((data0 == 0x02) && (data1 == 0x42))
    {
      if (data2 != 0)
      {
        strcat(comment, "     (");
        if (data2 & 0x10) strcat(comment, "Control_Store_Preserved,");
        if (data2 & 0x20) strcat(comment, "Main_Store_Preserved,");
        if (data2 & 0x40) strcat(comment, "Code_Update,");
        if (comment[strlen(comment)-1] != '(')
        {
          if (comment[strlen(comment)-1] == ',') comment[strlen(comment)-1] = '\0';
          strcat(comment, ")");
        }
        else comment[strlen(comment)-1] = '\0';
      }   
    }
    if ((data0 == 0x02) && (data1 == 0x41))
    {
      switch ((data2 << 8) + data3)
      {
              // from smgr/fsp/smgr_ipltypes.H
              /********************************************************************/
              /*        IPL MAJOR TYPE 0x00                                       */ 
              /*  0xX0000000 - 0xX00000FF:  CEC POWER ON IPLs                     */
              /********************************************************************/
          case 0x0001: strcat(comment, " (Panel initiated power on)"); break;
          case 0x0002: strcat(comment, " (HMC initiated power on)"); break;
          case 0x0003: strcat(comment, " (Tool initiated power on)"); break;
          case 0x0004: strcat(comment, " (Menu initiated power on)"); break;
          case 0x0008: strcat(comment, " (Remote power on (ring indicate))"); break;
          case 0x0009: strcat(comment, " (Timed power on)"); break;
          case 0x000A: strcat(comment, " (Auto power on restart)"); break;
          case 0x000B: strcat(comment, " (Remote Pwr Ctl(RPC) power on)"); break;
          case 0x000C: strcat(comment, " (IPL by Steps power on)"); break;
              /********************************************************************/ 
              /*        IPL MAJOR TYPE 0x01                                       */ 
              /*  0xX0000100 - 0xX00001FF: CEC RE-IPLs (power not cycled)         */
              /********************************************************************/
          case 0x0101: strcat(comment, " (Panel initiated re-IPL (FCN3))"); break;
          case 0x0102: strcat(comment, " (HMC initiated re-IPL)"); break;
          case 0x0103: strcat(comment, " (Tool initiated re-IPL)"); break;
          case 0x0104: strcat(comment, " (Menu initiated re-IPL)"); break;
          case 0x0108: strcat(comment, " (Flash programmed IPL)"); break;
          case 0x0109: strcat(comment, " (Standby programmed IPL)"); break;
          case 0x010C: strcat(comment, " (Post Dump IPL)"); break;
          case 0x010D: strcat(comment, " (Platform reboot)"); break;
          case 0x010E: strcat(comment, " (Non memory preserving re-IPL)"); break;
              /********************************************************************/
              /*        IPL MAJOR TYPE 0x08                                       */ 
              /*  0xX0000800 - 0xX00008FF: STANDBY IPLs                           */ 
              /********************************************************************/
          case 0x0801: strcat(comment, " (Power on reset to STANDBY (AC power))"); break;
          case 0x0802: strcat(comment, " (Panel initiated reset to STANDBY (pin hole reset))"); break;
          case 0x0803: strcat(comment, " (Tool initiated reset to STANDBY)"); break;
          case 0x0804: strcat(comment, " (Parallel port initiated reset to STANDBY)"); break;
              /********************************************************************/
              /*        IPL MAJOR TYPE 0x09                                       */ 
              /*  0xX0000900 - 0xX00009FF: INTERNAL IPLs                          */ 
              /********************************************************************/
          case 0x0901: strcat(comment, " (Exit error state)"); break;
          case 0x0902: strcat(comment, " (Slave test)"); break;
          case 0x0903: strcat(comment, " (Slave test standby)"); break;
          case 0x0904: strcat(comment, " (Dump exit error state)"); break;
              /********************************************************************/
              /*        IPL MAJOR TYPE 0x0A                                       */ 
              /*  0xX0000A00 - 0xX0000AFF: CEC POWER OFF IPLs                     */ 
              /********************************************************************/
          case 0x0A01: strcat(comment, " (Panel initiated power off)"); break;
          case 0x0A02: strcat(comment, " (HMC initiated power off)"); break;
          case 0x0A03: strcat(comment, " (Tool initiated power off)"); break;
          case 0x0A04: strcat(comment, " (Menu initiated power off)"); break;
          case 0x0A05: strcat(comment, " (RPC initiated power off)"); break;
          case 0x0A08: strcat(comment, " (Panel initiated emergency power off (FCN8))"); break;
          case 0x0A09: strcat(comment, " (HMC initiated emergency power off)"); break;
          case 0x0A0A: strcat(comment, " (Tool initiated emergency power off)"); break;
          case 0x0A0B: strcat(comment, " (Menu initiated emergency power off)"); break;
          case 0x0A10: strcat(comment, " (Host OS initiated normal power off)"); break;
          case 0x0A11: strcat(comment, " (Host OS initiated quick power off)"); break;
          case 0x0A18: strcat(comment, " (SPCN initiated power off (power fault))"); break;
              /********************************************************************/
              /*        IPL MAJOR TYPE 0x0B                                       */ 
              /*  0xX0000B00 - 0xX0000BFF: Reset/Reload  Types                    */ 
              /********************************************************************/
          case 0x0B01: strcat(comment, " (Host initiated Reset/Reload to RUNTIME)"); break;
          case 0x0B02: strcat(comment, " (Fips initiated Reset/Reload to RUNTIME)"); break;
          case 0x0B03: strcat(comment, " (Fips initiated Reset/Reload to STANDBY)"); break;
          case 0x0B04: strcat(comment, " (Fips initiated Reset/Reload to TERM)"); break;
          case 0x0B05: strcat(comment, " (Fips initiated Reset/Reload to LIMITED RUNTIME)"); break;
          case 0x0B06: strcat(comment, " (Fips initiated Reset/Reload to GUARDED)"); break;
          case 0x0B08: strcat(comment, " (HMC initiated Reset to RUNTIME)"); break;
          case 0x0B09: strcat(comment, " (HMC initiated Reset to STANDBY)"); break;
          case 0x0B0A: strcat(comment, " (Fips initiated Reset to STANDBY)"); break;
          case 0x0B10: strcat(comment, " (Fips initiated Failover to STANDBY)"); break;
          case 0x0B11: strcat(comment, " (Fips initiated Failover to TERM)"); break;
          case 0x0B12: strcat(comment, " (Fips initiated Failover to LIMITED RUNTIME)"); break;
              /********************************************************************/
              /*        IPL MAJOR TYPE 0x0C (SMGR_MAJOR_FAILOVER)                 */ 
              /*  0xX0000C00 - 0xX0000CFF: CEC Failover Types @01A                */ 
              /********************************************************************/
          case 0x0C01: strcat(comment, " (Fips initiated Failover to TERM)"); break;
              /*
                 SMGR_FO_RT_OS       = 0x20000C05,  // Host init'd failover to runtime
                 SMGR_FO_ST_OS       = 0x20000C06,  // Host init'd failover to standby

                 SMGR_AFO_ST_SP      = 0x00000C0A,  // Fips init'd admin failover to standby
                 SMGR_AFO_ST_HMC     = 0x00000C0B,  // HMC init'd admin failover to standby
                 SMGR_AFO_RT_SP      = 0x00000C0C,  // Fips init'd admin failover to runtime
                 SMGR_AFO_RT_HMC     = 0x00000C0D,  // HMC init'd admin failover to runtime

                 SMGR_FO_SURV_RT_SP  = 0x20000C10,  // Fips init'd surv failover to runtime
                 SMGR_FO_SURV_RT_OS  = 0x20000C11,  // Host init'd surv failover to runtime
                 SMGR_FO_SURV_ST_SP  = 0x20000C12,  // Fips init'd surv failover to standby
                 SMGR_FO_SURV_TERM_SP= 0x20000C13,  // Fips init'd surv failover to termination
                 */
              /********************************************************************/
              /*        IPL MAJOR TYPE 0xFF                                       */ 
              /*  0xX000FF00 - 0xX000FFFF: State Manager Internal Types           */ 
              /********************************************************************/
      }
    }

  }

  return(comment);
}//get_pte_comment()


void format_poll_flags(const uint8_t flags, char *results)
{
  char comment[255];

  if (flags != 0)
  {
    sprintf(comment, "(");
    if (flags & 0x80) strcat(comment, "AC_Preset,");
    if (flags & 0x20) strcat(comment, "BPC_Standby,");
    if (flags & 0x10) strcat(comment, "Service_Complete,");
    if (flags & 0x08) strcat(comment, "Other_BPC_Offline,");
    if (flags & 0x04) strcat(comment, "BPC_MBox_Broken,");
    if (flags & 0x02) strcat(comment, "1st_Poll_Since_Reset,");
    if (flags & 0x01) strcat(comment, "Block_Power_On,");
    if (comment[strlen(comment)-1] == ',') comment[strlen(comment)-1] = '\0';
    strcat(comment, ")");

    strcat(results, comment);
  }
}


void format_cage_flags(const uint8_t flags, char *results)
{
  char comment[255];
  if (flags != 0)
  {
    sprintf(comment, "(%02x", flags);
    if (flags & 0x80) strcat(comment, "Block_Cage_Power_On,");
    if (flags & 0x40) strcat(comment, "Visible,");
    if (flags & 0x20) strcat(comment, "Standby_Power_On,");
    if (flags & 0x10) strcat(comment, "Power_On,");
    if (flags & 0x08) strcat(comment, "Critical_Fault,");
    if (flags & 0x04) strcat(comment, "Initialization_Status,");
    if (flags & 0x01) strcat(comment, "Power_On_When_Not_Intended,");
    if (comment[strlen(comment)-1] == ',') comment[strlen(comment)-1] = '\0';
    strcat(comment, ")");
    strcat(results, comment);
  }
}


bool parse_spcn_trace_data(ErrlUsrParser & i_parser,
                           void *          i_buffer,
                           uint32_t        i_buflen,
                           errlver_t       i_ver)
{
  char elog [MAX_TRACE_BUFFER];
  uint8_t * l_buffer = (uint8_t*) i_buffer;

  // zero out elog, reset G_pte_entry_count
  bzero(elog, sizeof(elog));  
  G_pte_entry_count = 0;      

  if (l_buffer)               
  {
    for (uint32_t l_index=0; l_index < i_buflen; l_index++)
    {
      sprintf(&elog[(l_index * 2)], "%02x", l_buffer[l_index]);
    }
  }

  readErrlFile(elog, i_parser);
  return true;
}


bool parse_vrm_telemetry_data(ErrlUsrParser & i_parser,
                              void *          i_buffer,
                              uint32_t        i_buflen,
                              errlver_t       i_ver)
{
  bool rc = false;

  if ((i_buffer != NULL) && (i_buflen > 0))
  {
    VrmTelemetryParser vrmTelemParser(i_parser, i_buffer, i_buflen, i_ver);
    rc = vrmTelemParser.parse();
  }

  return rc;
}


/* Function Specification *********************************************************************************************************/
/*                                                                                                                                */
/*  Name:       LogDataParse                                                                                                      */
/*                                                                                                                                */
/*  Function:   Called by elog when there is an SPCN error log to parse                                                           */
/*                                                                                                                                */
/*  Owner:      Chris Cain                                                                                                        */
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
/*  Notes:                                                                                                                        */
/*         To test new function, mk and then copy the libE-2700.so file to /nfs/lib/ and then use errl like normal                */
/*                                                                                                                                */
/*                                                                                                                                */
/*  Codestat: NC=P CC=08/14/15  UT=--/--/--  SI=@000 OW=TEAM                                                                      */
/*                                                                                                                                */
/* End Function Specification *****************************************************************************************************/
extern "C" bool LogDataParse(ErrlUsrParser & i_parser,
                             void *          i_buffer,
                             uint32_t        i_buflen,
                             errlver_t       i_ver,
                             errlsubsec_t    i_sst)
{
  bool l_rc = false;                                          

  // Parse this user data section based on the sub-section type
  switch (i_sst)
  {
    case POWR_TRACE_DATA:         // SPCN trace (ILOG) data
      l_rc = parse_spcn_trace_data(i_parser, i_buffer, i_buflen, i_ver);
      break;
    case POWR_VRM_TELEM_DATA:     // VRM telemetry data
      l_rc = parse_vrm_telemetry_data(i_parser, i_buffer, i_buflen, i_ver);
      break;
    default:                      // Unexpected sub-section type
      l_rc = false;
      break;
  }

  return l_rc;

} // LogDataParse ( )  


/* Register the Log Data plugin with ERRL */ 
static errl::DataPlugin g_DataPlugin( POWR_COMP_ID, LogDataParse );


}  // End powr namespace
