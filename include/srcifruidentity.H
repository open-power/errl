/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcifruidentity.H $                          */
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
#ifndef SRCIFRUIDENTITY_H
#define SRCIFRUIDENTITY_H

/**
 *  @file srcifruidentity.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCIFRUIDENTITY_H srcifruidentity.H
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
#include <srcisubst.H>
#include <srcisrc.H>

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
const uint32_t SRCI_FRU_PART_NUMBER_LEN	    = 8;
const uint32_t SRCI_FRU_CCIN_LEN	    = 4;
const uint32_t SRCI_FRU_SERIAL_LEN	    = 12;


/*****************************************************************************/
// Synonyms
/*****************************************************************************/

/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/
class SrciFruIdentity : public SrciSubSt
{
public:
    
    enum flags 
    { 
	FRU_PART_NUMBER_SUPPLIED    = 0x08, 
	CCIN_SUPPLIED		    = 0x04, 
	MAINTENANCE_PROC_SUPPLIED   = 0x02, 
	SERIAL_NUMBER_SUPPLIED	    = 0x01 
    };

    
    // Fru Callout
    SrciFruIdentity(
	const char * i_pn,
	const char * i_ccin,
	const char * i_sn,
	ErrlBase &   i_parent
    );


    // Procedure or symbolic fru Callout
    SrciFruIdentity(
	const char * i_proc,
        CalloutType i_calltype,
	ErrlBase &   i_parent
    );


    SrciFruIdentity(
	const SrciFruIdentity & i_right,
	ErrlBase &		i_parent
    );

    
    SrciFruIdentity(
	UtilStream &	i_input,
	const Header &  i_hdr,
	ErrlBase &	i_parent
    );

    
    ~SrciFruIdentity();
    
    
    virtual uint32_t flatSize() const;
   

    const char *PartNumber() const;

    
    const char *ProcedureNumber() const;

    
    const char *ccin() const;

    
    const char *SerialNumber() const;

    
    srcifct FailingCompType() const;
    
    void FailingCompType( srcifct i_type );

    
    virtual void print(
        ErrlParser & i_parser
    ) const;


private:
    
    void PartNumber(
        const char *i_part
    );

    void ProcedureNumber(
        const char *i_proc
    );

    void SymbolicFruNumber(
        const char *i_symbolicfru
    );

    void ccin(
        const char *i_ccin
    );

    void SerialNumber(
        const char *i_fsn
    );

    
    char iv_number[SRCI_FRU_PART_NUMBER_LEN];
    char iv_ccin[SRCI_FRU_CCIN_LEN + 1];
    char iv_serial[SRCI_FRU_SERIAL_LEN + 1];

};

/*****************************************************************************/
// Inlines
/*****************************************************************************/

/*****************************************************************************/
// Read the failing component type
/*****************************************************************************/
inline srcifct SrciFruIdentity::FailingCompType() const
{
    return (srcifct)( iv_header.iv_flags & 0xF0 );
}



#endif //SRCIFRUIDENTITY_H
