/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcioptsctn.H $                              */
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
#ifndef SRCIOPTSCTN_H
#define SRCIOPTSCTN_H

/**
 *  @file srcioptsctn.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCIOPTSCTN_H srcioptsctn.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srci.H>
#include <utilstream.H>


/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
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
class SrciOptSctn 
{

public:
    
    enum type 
    { 
	CALLOUT_SCTN = 0xC0 
    };


    SrciOptSctn( type i_type );
    
    
    type SectionType() const;

    
    uint32_t flatSize() const;

    
    void unflatten(
	UtilStream &i_stream
    );


    void print(
	ErrlParser & i_parser
	    ) const;

    uint32_t WordCount() const;

  
private:
    
    uint8_t	iv_sid;
    uint8_t	iv_flags;
    mutable uint16_t	iv_wordCount;
    
};

/*****************************************************************************/
// Optional section header: constructor
// Invariant: Section Id
/*****************************************************************************/
inline SrciOptSctn::SrciOptSctn( type i_type )
: iv_sid ( i_type ),
  iv_flags( 0 ),
  iv_wordCount( 0 )
{
}


/*****************************************************************************/
// Read the section type
/*****************************************************************************/
inline SrciOptSctn::type SrciOptSctn::SectionType() const
{
    return (type)iv_sid;
}




/*****************************************************************************/
// Flat Header size
/*****************************************************************************/
inline uint32_t SrciOptSctn::flatSize() const
{
    return 4;
}



/*****************************************************************************/
// Header import
/*****************************************************************************/
inline void SrciOptSctn::unflatten(
    UtilStream &i_stream
)
{
    i_stream >> iv_sid >> iv_flags >> iv_wordCount;
}


/*****************************************************************************/
// Word count
/*****************************************************************************/
inline uint32_t SrciOptSctn::WordCount() const
{
    return iv_wordCount;
}



#endif // SRCIOPTSCTN_H
