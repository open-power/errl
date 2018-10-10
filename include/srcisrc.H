/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcisrc.H $                                  */
/*                                                                        */
/* OpenPOWER errltool Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef SRCISRC_H
#define SRCISRC_H

/**
 *  @file srcisrc.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCISRC_H srcisrc.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 * @endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srci.H>
#include <errlbase.H>
#include <srciascstr.H>
#include <nl_types.h>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class UtilStream;
class SrciCallout;
struct SVPD_MenuItems;
class ErrlParser;

/*****************************************************************************/
// User Types
/*****************************************************************************/
                                                                                
/**
 *  @brief Flag to determine Procedure or Symbolic Fru Callout
 *
 *  The following constants are used to determine if the callout
 *  is a Procedure or Symbolic Fru
 *
 */
enum CalloutType
{
    SYMB_FRU            = 1,
    SYMB_FRU_WITH_LOC   = 2,  //Symbolic fru with location code
    PROCEDURE           = 3
};
                                                                                
/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class SrciSrc : public ErrlBase
{
public:


    /**
     *  @brief Generic SRC Constructor
     *
     *  Builds a generic SRC where none of the Hex Words have been
     *  architected and are instead copied verbatim from the caller.
     *  
     *  @param	i_attr
     *	    Attributes to set on the SRC's flags ( byte 1 )
     *
     *  @param	i_hexWords
     *	    Array of 32 bit words used to build the SRC.
     *	    -Word 0 is converted to a Hexastring and placed in the
     *	     ascii string portion of the SRC
     *	    -Remaining words are copied directly to word 2 - word 9
     *
     *  @param	i_numWords
     *	    Number of valid words provided by the input array
     *
     *  @return None
     *
     *  @note A known user of this interface is SPCN
     *  
     */
    SrciSrc(
	uint32_t	i_attr,
	const uint32_t	i_hexWords[],
	uint32_t	i_numWords
	);

    


    /**
     *  @brief Import Constructor
     *
     *  Rebuilds an SRC object using flat data.
     *  
     *  @param	i_srcData
     *	    A pointer to the source data ( must be a previously
     *	    flat SRC )
     *
     *  @param	o_status
     *	    Output status.  Used to denote the success or
     *	    failure of the import operation.
     *
     *  @return 
     *
     *  @note If the input data is found to be bad, an error
     *        log will be built and committed on behalf of the
     *        caller.
     *
     *  @note For maximum portability, the SRC object should be
     *	      considered a VARIABLE structure.  Do not be confused
     *	      by the srciSrcData_t structure which is only the base
     *	      portion of the SRC and used only to symbolize that the
     *	      input data should be a flat SRC.
     *  
     */
    SrciSrc(
	const srciSrcData_t *i_srcData,
	srcistatus_t	    &o_status
	);




    /**
     *  @brief Copy constructor
     *  
     *  @param	i_right
     *	    Source SRC object
     *
     *  @return None
     *
     */
    SrciSrc(
        const SrciSrc &i_right
    );

    


    /**
     *  @brief Assignment operator
     *  
     *  @param	i_right
     *	    Source SRC object
     *
     *  @return None
     *
     */
    SrciSrc& operator=(
        const SrciSrc& i_right
    );

    
    
    /**
     *  @brief Destructor
     *  
     *  Deletes any callouts currently owned by the object
     *
     *  @return None
     *
     */
    virtual ~SrciSrc();

    
    
    /**
     *  @brief Flat size of the SRC object
     *
     *  Number of bytes required to store the entire SRC object
     *  
     *  @return Amount of storage ( in bytes ) needed to store the object
     *  
     */
    uint32_t flattenedSize() const;

    
    
    
    /**
     *  @brief Data Import facility - stream based
     *
     *  The object is reconstructed based on the data input from the
     *  stream.  The stream must be positioned at the beginning of
     *  the flat object data.  Errors are reported 
     *  
     *  @param	i_stream
     *	    Input stream object
     *
     *  @return Status of the operation -- could be a failure
     *          depending on the state of the input data
     *
     *  @note Any failures are not handled by this interface
     *        ( although the status code will indicate a failure ) but
     *        rather the error is left on the stream to be handled by
     *        the caller.
     */
    srcistatus_t unflatten(
        UtilStream &i_stream
    );

    
    
    /**
     *  @brief Src type
     *
     *  The src type is delcared as one of the following:
     *  1) B1 - Error/Information
     *  2) C1 - Progress
     *  3) D1 - Diagnostic
     *  4) A1 - Attention
     *  
     */
    uint8_t type() const;



    
    
    
    /**
     *  @brief Src format specifier
     *
     *  The src format depends on the creating subsystem, for the
     *  FSP the format is currently equal to 0xF0.
     *  
     *  @note	SPCN uses it's own type eventhough it runs on the
     *          FSP
     */
    uint8_t format( ) const;
    
   
    
    /**
     *  @brief Structure version
     *
     */
    //srciSrcVersion getVersion() const;

    
    /**
     *  @brief Subsystem Identifier
     *  
     *  Internal subsystem setting for the SRC
     *
     *  @note	Return data valid only for FipS format
     *  
     */
    uint8_t SubSys() const;

    
    /**
     *  @brief Module Id
     *  
     *  8 bit identifier passed in during construction
     *
     *  @note	Return data valid only for FipS format
     *  
     */
    uint8_t moduleId() const;
   
    /**
     *  @brief Reason Code
     *
     *  16 bit passed parameter.  Unique range declared for
     *  all components in epub_service_codes.H
     *
     *  @note   Return data valid only for FipS format
     */
    uint16_t reasonCode() const;

 
    
    
    /**
     *  @brief Access to null terminated ascii string
     *
     *  The ascii string is composed of the src type + a one
     *  byte subsystem + 2 byte reason code in the FipS format.
     *  All other formats are allowed to declare the ascii string
     *  as they wish.
     *  
     *  @note Although valid for any format, the descriptions above
     *        are mostly for the FipS format
     *  
     */
    const char *getAsciiString() const;

    
    /**
     *  @brief Access to all of the hex words in the SRC
     *
     *  The fixed ortion of the SRC is componsed of 8 hex words. Although
     *  they're all present, they may not all be valid.
     *  
     *  @param	o_count
     *	    Output parameter: Number of valid words
     *
     *  @return Constant pointer to beginning of hex word array
     *
     */
    const uint32_t *getHexData(uint32_t &o_count) const;
    
    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    uint32_t readTermState() const;

    
    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    bool HypDump() const;





    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    bool I5SELogBit() const;



    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    bool SpcnFault( void ) const;

    
    
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    bool Deconfigured( void ) const;

    /**
     *  @brief Get the Reset Reload error bit
     *
     *  This function will get the SRC Hex Word Bit#8 which
     *  represents Error Due to Reset Reload
     *
     *  @param  None
     *
     *
     *  @return
     *          True or False based on the values of reset bit
     *
     */
    bool getResetReload( void ) const;



    /**
     *  @brief Get the Possible Reset Reload error bit
     *
     *  This function will get the SRC Hex Word Bit#11 which
     *  represents Error Due to Reset Reload
     *
     *  @param  None
     *
     *
     *  @return
     *          True or False based on the values of reset bit
     *
     */
    bool getPossibleRsrlBit( void ) const;



                                                                                
    /**
     *  @brief Get the FSP Termination error bit
     *
     *  This function will get the SRC Hex Word 5 Bit#9 which
     *  represents Error Due to FSP Termination (reset/reload count exceed)
     *
     *  @param  None
     *
     *  @return
     *          True or False based on the values of terminate bit
     *
     */
    bool getFspTerminate( void ) const;





     /**
     *  @brief Read the acknowlegde bit in the error log.
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    bool GetAckBit( void ) const;
   
    /**
     *  @brief 
     *  
     *  @param	
     *	    
     *
     *  @return 
     *
     *  @note 
     *  
     */
    bool Garded( void ) const;

    
    
    
    
    
    /**
     *  @brief Parse and display using the error log parser interface
     *
     *  By using the parser interface, the caller can choose the
     *  type of output to generate based on which parser is instantiated
     *  and subsequently passed in to this method
     *  
     *  @param	i_parser
     *	    Parser interface
     *
     *  @return None
     *
     */
    void print(
        ErrlParser &	i_parser
    ) const;
   
    
    
    
    
    
    /**
     *  @brief System Type
     *  
     *  Allow the query of the System Type from the given SRC
     *
     *  @return two byte system type ( actually system backplane ccin )
     *
     *  @note Only valid for F0 format SRCs ( i.e. FipS srcs )
     *  
     */
    uint16_t SystemType( ) const;




    /**
     *  @brief Default constructor 
     *  
     *  Builds an empty src object for the purposes of unflatten or
     *  assignment.
     *
     *  @return None
     *
     *  @note Use of this constructor for anything other than assignment
     *        or unflatten is UNDEFINED ( yes a sigsev is in this
     *        category )
     *  
     */
    SrciSrc();




    /**
     *  @brief Query Virtual attribute
     *
     *  Determine if the Virtual attribute is set for the given SRC.
     *  
     *  @return True/False dending on attribute
     *
     */
    bool VirtualSrc( void ) const
    {
	return ( iv_flags & SRCI_VIRTUAL_SRC );
    }



private:
    


    /**
     *  @brief Default constructor with explicit container
     *  
     *  Builds an empty src object for the purposes of unflatten or
     *  assignment.
     *
     *  @param	i_parent
     *	    The container from which memory should be drawn
     *
     *  @return None
     *
     *  @note Use of this constructor for anything other than assignment
     *        or unflatten is UNDEFINED ( yes a sigsev is in this
     *        category )
     *  
     */
    SrciSrc(
	ErrlBase & i_parent
    );


    
    
    /**
     *  @brief Container copy-constructor
     *  
     *  @param	i_right
     *	    Source SRC object
     *
     *  @param	i_parent
     *	    Parent reference to determine memory
     *	    container
     *
     *  @return None
     *
     */
    SrciSrc(
        const SrciSrc &	i_right,
	ErrlBase &	i_parent
    );

    



    uint8_t PartitionDumpStatus( ) const;

    uint8_t SysIplState( ) const;

    uint8_t ParitionIplType( ) const;

    uint8_t SpDumpStatus( ) const;

    uint8_t PlatformIplMode( ) const;

    uint8_t PlatformDumpStatus( ) const;

    void format( uint8_t i_val );


   void moduleId( uint8_t i_mid );

    bool FspA( void ) const;

    bool FspB( void ) const;

    uint32_t LastProgressCode( ) const;

    uint32_t ClockStates( void ) const;

    uint8_t ErrorCount( ) const;


    SrciCalloutSctn * getCoSctn();


    // Instance Variables
    uint8_t		iv_version;
    mutable uint8_t	iv_flags;
    uint8_t		iv_reserved0;
    uint8_t		iv_wordCount;
    uint16_t		iv_reserved1;
    mutable uint16_t	iv_srcLength;
    mutable uint32_t	iv_hexWords[SRCI_MAX_HEX_WORD_COUNT];
    SrciAsciiString	iv_asciiString;
    SrciCalloutSctn *	iv_callouts;


    // Trusted relationships
    friend class ErrlSrc;
    friend class ErrlEntry;
    friend class SrciTest;

};



#endif //SRCISRC_H
