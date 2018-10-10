/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcipce.H $                                  */
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
#ifndef SRCIPCE_H
#define SRCIPCE_H

/**
 *  @file srcipce.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCIPCE_H srcipce.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlmtms.H>
#include <srcisubst.H>


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
class SrciPce : public SrciSubSt
{

public:

    
    SrciPce(
	const char *	i_name,
	const ErrlMTMS &i_mtms,
	ErrlBase &	i_parent
    );
    
   
    SrciPce( 
	const SrciPce & i_right,
	ErrlBase &	i_parent
    );

    
    SrciPce(
	UtilStream &	i_input,
	const Header &	i_hdr,
	ErrlBase &	i_parent
    );

    
    virtual ~SrciPce();

    

    
    void Name( const char * i_name );
    
    
    const char *Name() const;

    
    virtual uint32_t flatSize() const;


    virtual void print(
	ErrlParser & i_parser
	    ) const;


private:

    char *   iv_name;
    uint32_t iv_size;
    ErrlMTMS iv_mtms;

};


/*****************************************************************************/
// Inlines
/*****************************************************************************/


/*****************************************************************************/
// Read the name
/*****************************************************************************/
inline const char *SrciPce::Name() const
{
    return iv_name;
}


#endif //SRCIPCE_H
