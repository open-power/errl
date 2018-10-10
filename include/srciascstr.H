/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srciascstr.H $                               */
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
#ifndef SRCIASCSTR_H
#define SRCIASCSTR_H
/**
 *  @file srciascstr.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCIascstr_H srciascstr.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

#include <srci.H>

class UtilStream;


class SrciAsciiString
{
public:
    
    
    uint32_t flatSize() const
    {
	return SRCI_MAX_ASCII_BYTES;
    }

    
    void unflatten(
	UtilStream &i_stream
    );

    
    uint8_t Type() const;

    
    
    uint8_t SubSys(void) const;
    
    
    uint16_t ReasonCode() const;

    
    uint16_t ProgressCode() const;

    
    void setString( uint32_t i_word );
    
    
    const char * getString( void ) const;


  private:
    

    uint8_t getMiddle( void ) const;

    
    uint16_t getLast( void ) const;

    
    mutable char iv_string[SRCI_MAX_ASCII_BYTES+1];

};



#endif /* SRCIASCSTR_H_HEADER_INCLUDED_C1CF9A39 */

