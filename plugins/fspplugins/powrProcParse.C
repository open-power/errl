// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/powr/fsp/plugins/powrProcParse.C 1.4 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2012,2015 
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
#include <errlplugins.H>
#include <errlusrparser.H>
#include <string.h>

typedef struct
{
  const char * procedureID;
  const char * description;
} proc_description_t;

const proc_description_t PowrDescriptionList[] =
{
  {   "PWR1900",  "Contains a procedural index based on model." },
  {   "PWR1902",  "A system unit power supply load fault is occurring." },
  {   "PWR1903",  "A system unit power supply load fault is occurring." },
  {   "PWR1904",  "A power supply fault is occurring on the +12V/-12V line." },
  {   "PWR1905",  "A system unit power supply load fault is occurring." },
  {   "PWR1906",  "The server detected an error in the power system." },
  {   "PWR1907",  "A unit was dropped from the SPCN configuration." },
  {   "PWR1908",  "A power supply fault or load fault has occurred in a "
                  "5088 or 0588 expansion unit." },
  {   "PWR1909",  "A power supply load fault is occurring in a "
                  "system expansion unit or I/O tower." },
  {   "PWR1911",  "You are here because of a power problem on a dual line cord "
                  "system. If the failing unit does not have a dual line cord, "
                  "return to the procedure that sent you here or go to the next "
                  "item in the FRU list." },
  {   "PWR1912",  "The server detected an error in the power system." },
  {   "PWR1915",  "Use this procedure after observing a system "
                  "reference code (SRC) of 1XXX 8440 on a 520 with "
                  "Quiet Office Acoustic conversion or a 285." },
  {   "PWR1916",  "The server detected an error in the power system." },
  {   "PWR1917",  "Displaying or changing the Configuration ID." },
  {   "PWR1918",  "The server detected an error in the power system." },
  {   "PWR1920",  "Use this procedure to verify that the lights on "
                  "the server control panel and the display panel on "
                  "all attached I/O expansion units are operating correctly." },
  
  {   "PWR2402",  "The server detected an error in the power system." },
};




/* Function Specification ****************************************************/
/*                                                                           */
/*  Name:       PwrDataParse                                                 */
/*                                                                           */
/*  Function:   Called by elog when an SPCN log needs a PWRxxxx procedure    */
/*              description                                                  */
/*                                                                           */
/*  Owner:      Matt Derksen                                                 */
/*                                                                           */
/*  References:                                                              */
/*                                                                           */
/*  Parameters:                                                              */
/*         i_parser     Object used to print the output                      */
/*         i_pwr        Pointer to power procedure id                        */
/*                                                                           */
/*  Returns:                                                                 */
/*         true         if description was was added                         */
/*         false        unable to find a description                         */
/*                                                                           */
/*  Notes:                                                                   */
/*         To test new function, mk and then copy the libE-2700.so file to   */
/*         /nfs/lib/ and then use errl like normal                           */
/*                                                                           */
/*                                                                           */
/*  Codestat: NC=P CC=08/14/15  UT=--/--/--  SI=@000 OW=TEAM                 */
/*                                                                           */
/* End Function Specification ************************************************/
extern "C" bool PwrDataParse(ErrlUsrParser & i_parser, const char * i_pwr )
{
  bool l_rc = false;

  uint8_t i = 0;
  uint8_t max_list_entries = sizeof(PowrDescriptionList)/sizeof(proc_description_t);
  while (i < max_list_entries)
  {
    // Check for PWRxxxx procedure ID in description list
    if (strcmp(PowrDescriptionList[i].procedureID,i_pwr) == 0)
    {
      i_parser.PrintString("Description", PowrDescriptionList[i].description );
      l_rc = true;
      break;
    }
    i++;
  }

  return l_rc;

} // end PwrDataParse ( )


/* Register the Src Data plugin with ERRL */
static errl::PwrPlugin  g_PwrPlugin( POWR_COMP_ID, PwrDataParse );
