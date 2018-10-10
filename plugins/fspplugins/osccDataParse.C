// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/plugins/osccDataParse.C 1.4 
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
 *  @file osccDataParse.C
 *
 *  @brief Provides an interface to ERRL to parse OSCC's user data sections
 */

/**
 *  @page ChangeLogs Change Logs
 *  @section OSCCDATAPARSE osccDataParse.C
 *  @verbatim
 *
 ********************************** Change Log *********************************
 * Track      User          Date           Description
 * --------   -----------   ------------   -------------------------------------
 * F950657    dkodihal      02/16/2015     Created
 * @endverbatim
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcisrc.H>
#include <errlentry.H>
#include <errlplugins.H>
#include <errlusrparser.H>
#include <fips_comp_id.H>
#include <osccErrdata.H>

/*****************************************************************************/
// Forward
/*****************************************************************************/
static bool LogDataParse(ErrlUsrParser &i_parser,
                         void          *i_buffer,
                         uint32_t       i_buflen,
                         errlver_t      i_ver,
                         errlsubsec_t   i_sst);

static errl::DataPlugin g_DataPlugin(OSCC_COMP_ID, LogDataParse);

/*****************************************************************************/
// Plugin entry point
/*****************************************************************************/
bool LogDataParse(ErrlUsrParser &i_parser,
                  void *         i_buffer,
                  uint32_t       i_buflen,
                  errlver_t      i_ver,
                  errlsubsec_t   i_sst)
{
    bool l_rc = false;

    // Create a osccErrlUsrDataParserFactory object
    OSCC::osccErrlUserDataParserFactory l_factory;

    // Use the factory to create the correct UsrDtlDataParser object
    util::ErrlUsrDataParser * l_pUsrDtlDataParser = l_factory.Create(i_sst);

    if (l_pUsrDtlDataParser)
    {
        l_rc = true;

        l_pUsrDtlDataParser->parse(i_ver, i_parser, i_buffer, i_buflen);

        delete l_pUsrDtlDataParser;
        l_pUsrDtlDataParser = NULL;
    }

    return l_rc;
}
