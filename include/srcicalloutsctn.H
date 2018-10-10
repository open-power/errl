/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcicalloutsctn.H $                          */
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
#ifndef SRCICALLOUTSCTN_H
#define SRCICALLOUTSCTN_H

/**
 *  @file srcicalloutsctn.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCICALLOUTSCTN_H srcicalloutsctn.H
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
#include <srcioptsctn.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class ErrlParser;

/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// C o n s t a n t s
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
class SrciCalloutSctn : public ErrlBase
{
public:

    SrciCalloutSctn(
	ErrlBase & i_parent
    );

    
    SrciCalloutSctn(
	const SrciCalloutSctn & i_right,
	ErrlBase &		i_parent
    );


    ~SrciCalloutSctn();

    
    srciIdx_t CalloutCount( void ) const;

    
    SrciCallout ** Callouts( void );

    
    void unflatten(
        UtilStream &i_stream
    );

    
    uint32_t flatSize() const;


    void print(
	ErrlParser & i_parser
    ) const;


private:

    void Reset();

    void Append(
	SrciCallout & i_cout
    );


    SrciOptSctn	    iv_header;
    SrciCallout **  iv_callout;
    srciIdx_t	    iv_count;


    // Disabled
    SrciCalloutSctn(
	const SrciCalloutSctn & i_right
    );
    SrciCalloutSctn & operator=(
	const SrciCalloutSctn & i_right
    );

};


/*****************************************************************************/
// Default constructor
// Invariant: Section Id
/*****************************************************************************/
inline SrciCalloutSctn::SrciCalloutSctn(
    ErrlBase & i_parent
)
: ErrlBase( i_parent ),
  iv_header( iv_header.CALLOUT_SCTN ),
  iv_callout( 0 ),
  iv_count( 0 )
{
}


/*****************************************************************************/
// Callout Count
/*****************************************************************************/
inline srciIdx_t SrciCalloutSctn::CalloutCount( void ) const
{
    return iv_count;
}

/*****************************************************************************/
// Access callout array
/*****************************************************************************/
inline SrciCallout ** SrciCalloutSctn::Callouts()
{
    return iv_callout;
}









#endif // SRCICALLOUTSCTN_H
