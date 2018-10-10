/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcicallout.H $                              */
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
#ifndef SRCICALLOUT_H
#define SRCICALLOUT_H

/**
 *  @file srcicallout.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCICALLOUT_H srcicallout.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlbase.H>
#include <srci.H>


/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class UtilStream;
class SrciFruIdentity;
class SrciPce;
class SrciMruSst;
class SrciMru;
class ErrlParser;


/*****************************************************************************/
// Constants
/*****************************************************************************/
const uint32_t SRCI_FRU_BASELEN = 4;


/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class SrciCallout : public ErrlBase
{
public:

    /**
     *  @brief "Purists" callout type
     *  
     *  The architecture has a loophole by which a callout cannot be clearly
     *  identified ( is it a fru or a proc? ).  The reason for this is that
     *  the fru identity was made optional in the base callout even though
     *  location code is a part of the base.
     *
    */
    enum type
    {
	HW_CALLOUT	    = 'H',  ///< Hardware Callout
	PROC_CALLOUT	    = 'P'   ///< Procedure Callout
    };
    
    
    /**
     *  @brief Callout Structure identifier
     *
     *  Currently this is the only callout structure supported
     *  
    */
    enum CalloutVersion
    { 
	FRU_TYPE_2	    = 0x20  ///< Callout type 2
    };

    
    
    /**
     *  @brief Object Flat Size
     *
     *  Amount of storage required to store structure; includes 
     *  the size of all the fields ( base structure, location code,
     *  fru identity, pce, mru substructure )
     *  
     *  @return Bytes required
     *
     *  @note 
     *  
    */
    uint32_t flatSize() const;

    
    
    
    /**
     *  @brief Import flat data into object
     *  
     *  Expects a flat representation of the Squadrons Structure v1.5d
     *  callout and rebuilds the object hierchy used to represent it
     *
     *  @param	i_stream
     *	    Input stream used as the data source
     *
     *  @return None
     *
     *  @note The output stream is a carrier of error information
     *  
    */
    void unflatten(
        UtilStream &i_stream
    );

    
    
    /**
     *  @brief Callout version report
     *  
     *  @return CalloutVersion constant
     *
     *  @note Currently the only version handled is Callout 2
     *        as reported in the Arch Structures
     *  
    */
    CalloutVersion Version() const;
    
    
    
    
    
    /**
     *  @brief Callout Priority
     *  
     *  @return srciPriority enum values found in srci.H
     *
     *  @note A source of confusion ( at least to me ) was the 3 medium
     *        priorities defined in the architecture.  It is my understanding
     *        that none of the 3 mediums are more important than the other.
     *  
    */
    srciPriority Priority() const;

    
    
    /**
     *  @brief Read-only Access to the location code
     *  
     *  @return Constant character pointer
     *
     *  @note The data pointed to by the return value must not
     *        be altered in any way nor should the pointer be
     *        released by the caller as it is not owned by the
     *        caller.
     *  
    */
    const char *LocationCode() const;
    
    
    
    /**
     *  @brief Read-only Access to the part number
     *  
     *  The part number is only available if the Fru Identity
     *  substructure has been supplied and it is not marked as
     *  a procedure.
     *
     *  @return Constant character pointer
     *
     *  @note Of course the fru identity could be present, marked
     *        as a non-procedure and still no part number
     *  
    */
    const char *PartNumber( void ) const;

    
    
    /**
     *  @brief Read-only Access to the ccin
     *  
     *  The ccin is only available if the Fru Identity
     *  substructure has been supplied and it is not marked as
     *  a procedure.
     *
     *  @return Constant character pointer
     *
     *  @note See PartNumber for more information
     *  
    */
    const char *ccin( void ) const;

    
    
    /**
     *  @brief Read-only Access to the Serial Number
     *  
     *  The Serial Number is only available if the Fru Identity
     *  substructure has been supplied and it is not marked as
     *  a procedure.
     *
     *  @return Constant character pointer
     *
     *  @note See PartNumber for more information
     *  
    */
    const char *SerialNumber( void ) const;



    /**
     *  @brief Callout display method
     *
     *  The method is used to parse and display object contents
     *  to stdout using the command line tool or ASM. It is called
     *  indirectly as part of the SRC print method.
     *  
     *  @param	i_parser
     *	    Parse object reference; this is the output device
     *
     *  @return None
     *
    */
    void print(
	ErrlParser & i_parser
    ) const;




    /**
     *  @brief Base callout structure header
     *
     *  The fields contained in this structure form the top portion
     *  of a callout
     *  
    */
    struct header
    {
	header();

	header(
	    uint8_t i_priority
	);

	uint8_t iv_len;
	uint8_t iv_flags;
	uint8_t	iv_priority;
	uint8_t	iv_locCodeLen;

	friend UtilStream & operator >> ( UtilStream & i_left, header & i_right );
    };
    
    
private:
    
    
    
    /**
     *  @brief Existance bits for the header
     *  
     *  The following constants are used to set the corresponding
     *  bits in the callout header flags.
     *
    */
    enum existance
    { 
	FRU_IDENTITY	    = 0x08, ///< Fru Identity present
	MRU_SST		    = 0x04, ///< Mru Substructure present
	PCE_PRESENT	    = 0x03, ///< Pce Substructure present
	PCE_NOT_DESCRIBED   = 0x02, ///< No Pce available
	PCE_IN_LAST_FRU	    = 0x01, ///< Pce in last callout
	PCE_SAME_AS_FAILING = 0x00  ///< Pce is the same as the failing fru
    };


    
    /**
     *  @brief Copy-constructor
     *  
     *  Used when moving callouts around
     *
     *  @param	i_right
     *	    Callout copy source
     *
     *  @return None
     *
    */
    SrciCallout(
	const SrciCallout & i_right,
	ErrlBase &	    i_parent
    );

    
    
    /**
     *  @brief Import constructor
     *
     *  Uses stream data to build the object
     *  
     *  @param	i_input
     *	    Source stream
     *
     *  @return None
     *
     *  @note Initializes the object to default and then
     *        call unflatten to rebuild the object.
     *  
    */
    SrciCallout(
	UtilStream &i_input,
	ErrlBase &  i_parent
    );

    
    
    /**
     *  @brief Destructor
     *
     *  Releases all allocated resources
     *  
     *  @return None
     *
    */
    virtual ~SrciCallout();

    
    
public:

    
    /**
     *  @brief Greater than comparison
     *
     *  The comparison is based on the callout priority and is
     *  used in sorting the callout list
     *  
     *  @param	i_right
     *	    Right-hand comparison
     *
     *  @return True/False
     *
    */
    bool operator>( const SrciCallout & i_right ) const;
    
    
    
    
    /**
     *  @brief Less than comparison
     *
     *  The comparison is based on the callout priority and is
     *  used in sorting the callout list
     *  
     *  @param	i_right
     *	    Right-hand comparison
     *
     *  @return True/False
     *
    */
    bool operator<( const SrciCallout & i_right ) const;



    
    /**
     *  @brief Inline access to Object Id
     *  
     *  Object Id is used to uniquely identify the instance
     *  of the class.  Mainly for sorting purposes.
     *
     *  @return Object Id
     *
     */
    uint32_t ObjectId() const;


    
private:

    /**
     *  @brief Clear all handles contained in the object
     *
     *  Resets the object by deleting all allocated resources
     *  
     *  @return None
     *
    */
    void Reset();

    
    
    /**
     *  @brief Object Id Generator
     *
     *  Called by constructors to assign a unique Object Id to
     *  each instance of the class.
     *  
     *  @return Unique Object Id
     *
     *  @note Used by the sorting algorithm to determine initial
     *        add order
     *  
     */
    static uint32_t StampObjectId();


    
    // Data
    mutable header	iv_hdr;
    char *		iv_locCode;
    SrciFruIdentity *	iv_pFid;
    SrciPce *		iv_pPce;
    SrciMruSst *	iv_pMrus;
    type		iv_type;
    uint32_t		iv_oid;		// 32 Bit Object Id assigned at ctor


    // Friends 4 ever
    friend class SrciCalloutSctn;
    friend class SrciSrc;
    friend class SrciTest;


};


/*****************************************************************************/
// Inlines
/*****************************************************************************/


/*****************************************************************************/
// Header default constructor
/*****************************************************************************/
inline SrciCallout::header::header()
: iv_len( sizeof(header) ),
  iv_flags( FRU_TYPE_2 ),
  iv_priority( SRCI_PRIORITY_LOW ),
  iv_locCodeLen( 0 )
{
}

/*****************************************************************************/
// Header priority constructor
/*****************************************************************************/
inline SrciCallout::header::header(
    uint8_t i_priority
)
: iv_len( sizeof(header) ),
  iv_flags( FRU_TYPE_2 ),
  iv_priority( i_priority ),
  iv_locCodeLen( 0 )
{
}

/*****************************************************************************/
// FRU version
/*****************************************************************************/
inline SrciCallout::CalloutVersion SrciCallout::Version() const
{
    return (CalloutVersion)( iv_hdr.iv_flags & 0xF0 );
}



/*****************************************************************************/
// Callout Priority
/*****************************************************************************/
inline srciPriority SrciCallout::Priority() const
{
    return (srciPriority)iv_hdr.iv_priority;
}



/*****************************************************************************/
// Read the location code
/*****************************************************************************/
inline const char *SrciCallout::LocationCode() const
{
    return iv_locCode;
}


/*****************************************************************************/
// Access the object Id
/*****************************************************************************/
inline uint32_t SrciCallout::ObjectId() const
{
    return iv_oid;
}



#endif //SRCICALLOUT_H
