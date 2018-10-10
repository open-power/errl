// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/powr/fsp/plugins/powrSrcParse.C 1.2 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2006,2015 
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

#include <errltypes.H>
#include <errlusrparser.H>
#include <errlutility.H>
#include <srcisrc.H>
#include <errlplugins.H>


typedef void (*parser_t) ( ErrlUsrParser & i_parser, const SrciSrc & i_src );


struct errlSrcParser
{
  uint32_t      iv_uid;
  parser_t      iv_parser;
};


void Parse_8720( ErrlUsrParser & i_parser, const SrciSrc & i_src );


errlSrcParser   g_ParserList[] =
{
  { 0x11001F02, Parse_8720 },
  { 0x11008720, Parse_8720 },
  { 0, 0 }
};


void Parse_8720( ErrlUsrParser & i_parser, const SrciSrc & i_src )
{
  const char    *l_src_string_ptr = i_src.getAsciiString();
  uint32_t      l_ref = 0;
  char l_string[255] = "";
  const uint32_t   *l_word_array = NULL;
  uint32_t	    l_wordcount = 0;

  sscanf(l_src_string_ptr, "%08X", &l_ref);

  sprintf(l_string, "%08X", l_ref);
  i_parser.PrintString("Ref Code", l_string);

  // Access user words 2-9 and get count
  l_word_array = i_src.getHexData(l_wordcount);

  if (l_wordcount > 0)
  {
    sprintf(l_string, "%04X", l_word_array[0] >> 8);
    i_parser.PrintString("Rack", l_string);
    sprintf(l_string, "%02X", l_word_array[0] & 0xFF);
    i_parser.PrintString("Unit", l_string);
  }
  if (l_wordcount > 1)
  {
    if ( (l_ref & 0xFFFF) == 0x1F00 )
    {
      sprintf(l_string, "%08X", l_word_array[1]);
      i_parser.PrintString("Untranslated SRC", l_string);
    }

    if (l_wordcount > 3)
    {
      sprintf(l_string, "%08X", l_word_array[4]);
      i_parser.PrintString("User Data 1", l_string);
    }
    if (l_wordcount > 4)
    {
      sprintf(l_string, "%08X", l_word_array[5]);
      i_parser.PrintString("User Data 2", l_string);
    }
    if (l_wordcount > 6)
    {
      sprintf(l_string, "%08X", l_word_array[6]);
      i_parser.PrintString("User Data 3", l_string);
    }
    if (l_wordcount > 7)
    {
      sprintf(l_string, "%08X", l_word_array[7]);
      i_parser.PrintString("User Data 4", l_string);
    }

  }
}


/* Function Specification *********************************************************************************************************/
/*                                                                                                                                */
/*  Name:       SrcDataParse                                                                                                      */
/*                                                                                                                                */
/*  Function:   Called by elog when there is an SRC to parse                                                                      */
/*                                                                                                                                */
/*  Owner:      Chris Cain                                                                                                        */
/*                                                                                                                                */
/*  References: Log Viewer Design (dept CMAA)                                                                                     */
/*                                                                                                                                */
/*  Parameters:                                                                                                                   */
/*         i_parser     Object used to print the output                                                                           */
/*         i_src        Pointer to data                                                                                           */
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
extern "C" bool SrcDataParse(
                             ErrlUsrParser & i_parser,
                             const SrciSrc & i_src
                             )
{
  uint32_t      l_index = 0;
  //uint32_t      l_uid = 0;
  bool          l_rc = false;

  g_ParserList[l_index].iv_parser( i_parser, i_src );

  #if 0
  // Since SPCN uses format 0x02, moduleId and reasonCode are not defined...
  //l_uid = ( i_src.moduleId() << 16 ) | i_src.reasonCode();

  const uint32_t *l_wa = NULL;
  uint32_t	    l_wordcount = 0;
  // Access user words
  l_wa = i_src.getHexData(l_wordcount);

  char l_string[256];
  sprintf(l_string, "0x%08X, w0=%X, w1=%X", l_uid, l_wa[0], l_wa[1]);
  i_parser.PrintString("l_uid", l_string);

  while ( g_ParserList[l_index].iv_uid )
  {
    if ( g_ParserList[l_index].iv_uid == l_uid )
    {
      g_ParserList[l_index].iv_parser( i_parser, i_src );
      l_rc = true;
      break;
    }
    l_index++;
  }
  #endif

  return l_rc;

} // SrcDataParse ( )  


/* Register the Src Data plugin with ERRL */ 
static errl::SrcPlugin  g_SrcPlugin( POWR_COMP_ID, SrcDataParse );
