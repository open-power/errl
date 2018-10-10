/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcimrusst.H $                               */
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
#ifndef SRCIMRUSST_H
#define SRCIMRUSST_H

/**
 *  @file srcimrusst.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCIMRUSST_H srcimrusst.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcisubst.H>
#include <srci.H>

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
class SrciMru;
class ErrlParser;

/*****************************************************************************/
// User Types
/*****************************************************************************/

/*****************************************************************************/
// Constants
/*****************************************************************************/
const srciIdx_t SRCI_MAXIMUM_MRU_COUNT			= 15;

/*****************************************************************************/
// Synonyms
/*****************************************************************************/

/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class SrciMruSst : public SrciSubSt
{
public:

    
    SrciMruSst(
	ErrlBase & i_parent
    );
    
    
    SrciMruSst( 
	const SrciMruSst &  i_right,
	ErrlBase &	    i_parent
    );

   
    SrciMruSst(
	UtilStream &	i_input,
	const Header &	i_hdr,
	ErrlBase &	i_parent
    );


    virtual ~SrciMruSst();

    
    virtual uint32_t flatSize() const;


    virtual void print(
	ErrlParser & i_parser
	) const;

    

private:

    srciIdx_t	iv_count;
    uint32_t	iv_reserved;
    SrciMru *	iv_mrus[SRCI_MAXIMUM_MRU_COUNT];

};

/*****************************************************************************/
// Inlines
/*****************************************************************************/



#endif //SRCIMRUSST_H
