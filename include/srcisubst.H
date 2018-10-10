/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/srcisubst.H $                                */
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
#ifndef SRCISUBST_H
#define SRCISUBST_H

/**
 *  @file srcisubst.H
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section SRCISUBST_H srcisubst.H
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
class SrciSubSt : public ErrlBase
{
public:
    
    enum SSType 
    { 
	SST_FRU_IDENTITY    = 0x4944,
	SST_FRU_PCE	    = 0x5045,
	SST_MRU		    = 0x4D52
    };

    
    struct Header
    {
        Header();

        Header( SSType i_type );

	Header( const Header & i_right );
	
	void unflatten(
	    UtilStream &i_stream
	);

	
	uint32_t flatSize() const
	{
	    return 4;
	}

        uint16_t	iv_sid;
        mutable uint8_t iv_len;
        uint8_t		iv_flags;

    };
    

    SrciSubSt(
	SSType	    i_type,
	ErrlBase &  i_parent
    );

    
    SrciSubSt(
	const SrciSubSt & i_right,
	ErrlBase  &	  i_parent
    );

    
    SrciSubSt(
	UtilStream &	i_input,
	const Header &  i_hdr,
	ErrlBase  &	i_parent
    );

    
    virtual ~SrciSubSt();

    
    SSType SectionType() const;

    
    virtual uint32_t flatSize() const = 0;
    
    
    virtual void print(
	ErrlParser & i_parser
	) const = 0;



protected:
    
    mutable Header iv_header;


private:

    // Disabled
    SrciSubSt(
	const SrciSubSt & i_right
    );

    SrciSubSt & operator= (
	const SrciSubSt & i_right
    );

    
};


/*****************************************************************************/
// Inlines
/*****************************************************************************/

/*****************************************************************************/
// Read section Id
/*****************************************************************************/
inline SrciSubSt::SSType SrciSubSt::SectionType() const
{
    return (SSType)iv_header.iv_sid;
}






#endif //SRCISUBST_H

