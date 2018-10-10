/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcimru.H $                                  */
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
#ifndef SRCIMRU_H
#define SRCIMRU_H

/**
 *  @file srcimru.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCIMRU_H srcimru.H
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
class ErrlParser;

/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/

/*****************************************************************************/
// Synonyms
/*****************************************************************************/

/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class SrciMru : public ErrlBase
{
public:

    SrciMru(
	srciPriority i_priority,
	uint32_t     i_mruId,
	ErrlBase  &  i_parent
    );

    
    SrciMru(
	const SrciMru & i_right,
	ErrlBase &   i_parent
    );

    
    ~SrciMru();
    
    
    void unflatten(
        UtilStream &i_stream
    );

    
    uint32_t flatSize() const;


    void print(
	ErrlParser & i_parser
	) const;


    srciPriority priority( void ) const;

    uint32_t mruId( void ) const;


    bool operator>( const SrciMru & i_right ) const;
    
    bool operator<( const SrciMru & i_right ) const;


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
    uint8_t	    iv_reserved0;
    uint8_t	    iv_reserved1;
    uint8_t	    iv_reserved2;
    srciPriority    iv_priority;
    uint32_t	    iv_mruId;
    uint32_t	    iv_oid;		// 32 Bit Object Id assigned at ctor


};



/*****************************************************************************/
// Inlines
/*****************************************************************************/

/*****************************************************************************/
// Export Size
/*****************************************************************************/
inline uint32_t SrciMru::flatSize() const
{
    return 8;
}

/*****************************************************************************/
// MRU Priority
/*****************************************************************************/
inline srciPriority SrciMru::priority( void ) const
{
    return (srciPriority)iv_priority;
}

/*****************************************************************************/
// MRU Identifier
/*****************************************************************************/
inline uint32_t SrciMru::mruId( void ) const
{
    return iv_mruId;
}


/*****************************************************************************/
// Access the object Id
/*****************************************************************************/
inline uint32_t SrciMru::ObjectId() const
{
    return iv_oid;
}



#endif //SRCIMRU_H
