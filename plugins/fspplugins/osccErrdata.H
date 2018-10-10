// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/osccErrdata.H 1.10.1.3 
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
 *  @file osccErrdata.H
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
 *  @section OSCCERRDATA_H osccErrdata.H
 *  @verbatim
 *
 ********************************** Change Log *********************************
 * Track      User          Date           Description
 * --------   -----------   ------------   -------------------------------------
 * F950657    dkodihal      02/16/2015     Created
 * D935500    sangeet2      03/26/2015     Enclose header files in <>
 * D1019784   ankidhin      10/27/2017     Add size check for error log
 * F1049363   manichow      03/22/2018     Added new registers to capture in log
 * @endverbatim
 */


#ifndef OSCCERRDATA_H
#define OSCCERRDATA_H

//******************************************************************************
// Includes
//******************************************************************************
#include <errltypes.H>
//#include <common.h>
//#include <utillib.H>
#include <utilerrlusrdata.H>
#include <utilfactory.H>
#include <utilmem.H>
//#include <utilreg.H>
#include <utilbase.H>
#include <errlusrparser.H>
#include <dcc_oscillator_structs.hpp>

namespace OSCC
{

/**
 * @brief Error logging user detail versions
 *
 * This definition controls the version of the error log user details
 * section.
 */
#define OSCC_USRDTL_SVC_CLOCK_CALLOUT_VER_1 (errlver_t)0x01

/**
 * @brief Error logging user detail section types
 *
 * This definition controls the section types for user details sections
 * in error logs.
 */
#define OSCC_USRDTL_SVC_CLOCK_CALLOUT         (errlsubsec_t)0x01

//******************************************************************************
// Types
//******************************************************************************

// Structure for chip register FFDC
struct chipRegFFDC_t
{
    uint32_t chipHUID;
    uint32_t chipRID;
    uint32_t chipEC;
    uint32_t reg1007;
    uint32_t reg2810;
    uint32_t reg2813;
    uint32_t reg2814;
    uint32_t reg2815;
    uint32_t reg2816;
    uint32_t reg2804;
    uint32_t reg281D0; //Content of 281D with bit 12:14 of 2815 set to 000
    uint32_t reg281D1; //Content of 281D with bit 12:14 of 2815 set to 001
    uint32_t reg281D2; //Content of 281D with bit 12:14 of 2815 set to 010
    uint32_t reg281D3; //Content of 281D with bit 12:14 of 2815 set to 011
    uint32_t reg281D4; //Content of 281D with bit 12:14 of 2815 set to 111
    uint32_t reg1020019;

    chipRegFFDC_t() :
    chipHUID(0xFFFFFFFF),
    chipRID(0),
    chipEC(0),
    reg1007(0),
    reg2810(0),
    reg2813(0),
    reg2814(0),
    reg2815(0),
    reg2816(0),
    reg2804(0),
    reg281D0(0),
    reg281D1(0),
    reg281D2(0),
    reg281D3(0),
    reg281D4(0),
    reg1020019(0)
    {}
};

struct clockCalloutFFDC_t
{
    std::vector<chipRegFFDC_t> chipRegs;
    dccosc::RedundantOscillatorStatus_t* pCardStatus;

    clockCalloutFFDC_t() :
    pCardStatus(NULL)
    {}
};

#ifndef PARSER

//******************************************************************************
// OSCCUDC_clockCallout class
//******************************************************************************
class OSCCUDC_clockCallout : public util::ErrlUsrDataCreator
{
public:
    /**
     *  @brief Constructor
     *
     *  Used to create an object to add OSCCUDC_clockCallout based user detail
     *  data to an error log
     *
     *  @param[in] i_data clockCalloutFFDC_t
     */
    OSCCUDC_clockCallout(const clockCalloutFFDC_t& i_data);


    /**
     *  @brief Get method for OSCCUDC Size
     *
     *  This method is used to get the size of the used data section
     *  being added to the error log, this is required to check if this
     *  UDC fits in the current error log or a new one needs to be created.
     */  
    uint32_t getOSCCUDC_Size()
    {
          return getUsrBufSize();
    }

    /**
     *  @brief Destructor
     */
    virtual ~OSCCUDC_clockCallout();

private:
    // Disabled
    OSCCUDC_clockCallout(const OSCCUDC_clockCallout&);
    OSCCUDC_clockCallout& operator=(const OSCCUDC_clockCallout&);
};

#else //PARSER

//******************************************************************************
// OSCCUDP_clockCallout class
//******************************************************************************
class OSCCUDP_clockCallout : public util::ErrlUsrDataParser
{
public:
    /**
     * @brief Constructor
     */
    OSCCUDP_clockCallout();

    /**
     * @brief Destructor
     */
    virtual ~OSCCUDP_clockCallout();

    /**
     * @brief Parses user detail data from an error log
     *
     * @par Detailed Description
     *     Parses the supplied user detail data and outputs info to i_parser.
     *     This overrides the pure virtual function in the base class
     *
     * @param  i_version[in] Version of the data
     * @param  i_parser[in] ErrlUsrParser object for outputting information
     * @param  i_pBuffer[in] Pointer to buffer containing detail data
     * @param  i_buflen[in] Length of the buffer
     *
     * @return None
     */
    virtual void parse(
        errlver_t i_version,
        ErrlUsrParser & i_parser,
        const void * i_pBuffer,
        const uint32_t i_buflen) const;

private:
    // Disabled
    OSCCUDP_clockCallout(const OSCCUDP_clockCallout&);
    OSCCUDP_clockCallout& operator=(const OSCCUDP_clockCallout&);
};

/**
 * @brief Parser Factory Class for the OSCC component
 *
 * This derives from Factory<ErrlUsrDataParser, int>, therefore it is a factory
 * that produces ErrlUsrDataParser objects and references each type of object
 * with an int.
 */
class osccErrlUserDataParserFactory :
                            public util::Factory<util::ErrlUsrDataParser, int>
{
public:

    /**
     *  @brief Constructor
     *
     *  Registers all possible types of parser object with the factory
     *
     */
    osccErrlUserDataParserFactory();

};

#endif // PARSER

} // namespace OSCC

#endif // OSCCERRDATA_H
