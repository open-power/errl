// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_oscillator_debug.hpp 1.12.1.2 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2008,2009 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/*--------------------------- IBM - Confidential ----------------------------*

    (C) Copyright International Business Machines Corporation 2004
    All Rights Reserved
    Licensed Material  -  Program Property of I B M
    Refer to copyright instructions: Form G120-2083

 *---------------------------------------------------------------------------*/

#ifndef DCC_OSCILLATOR_DEBUG_HPP
#define DCC_OSCILLATOR_DEBUG_HPP

#include <stdint.h>

namespace dcc
{

	uint32_t i2c_write(
		uint32_t			f_card,
		uint32_t			f_link, 
		uint32_t			f_bus, 
		uint32_t			f_device_add, 
		uint32_t			f_offset, 
		const uint8_t*		        f_buffer, 
		uint32_t			f_len);

	uint32_t i2c_read(
		uint32_t			f_card,
		uint32_t			f_link, 
		uint32_t			f_bus, 
		uint32_t			f_device_add, 
		uint32_t			f_offset, 
		uint8_t*			f_buffer, 
		uint32_t&			f_len);

	uint32_t i2c_resetIrq(
		uint32_t			f_card, 
		uint32_t			f_link, 
		uint32_t			f_bus, 
		uint32_t			f_device_add, 
		uint32_t			f_offset, 
		const uint8_t*		f_pFlags, 
		uint32_t			f_len);

    uint32_t dio_writeLevel(
		uint32_t			f_osciNo, /* 0 or 1 */
		uint32_t			f_logicalLinkId,
		uint32_t			f_logicalEngineId,
		uint32_t			f_mask, 
		uint32_t			f_level); 

	uint32_t dio_readLevel(
		uint32_t			f_osciNo, /* 0 or 1 */
		uint32_t			f_logicalLinkId,
		uint32_t			f_logicalEngineId,
		uint32_t&			f_level); 

    uint32_t dio_pldSetConfig(
		uint32_t			f_osciNo, /* 0 or 1 */
		uint32_t			f_logicalLinkId,
		uint32_t			f_logicalEngineId,
		uint32_t			f_pldId, 
		uint32_t			f_configData);

	uint32_t dio_pldGetConfig(
		uint32_t			f_osciNo, /* 0 or 1 */
		uint32_t			f_logicalLinkId,
		uint32_t			f_logicalEngineId,
		uint32_t			f_pldId, 
		uint32_t&			f_configData);

    uint32_t dio_pldSetTableControl(
		uint32_t			f_osciNo, /* 0 or 1 */
		uint32_t			f_logicalLinkId,
		uint32_t			f_logicalEngineId,
		uint32_t			f_pldId, 
		uint32_t			f_mode); /* 1 - use table, 2 - table output high, 3 - table output low */


	uint32_t dio_pldGetTableControl(
		uint32_t			f_osciNo, /* 0 or 1 */
		uint32_t			f_logicalLinkId,
		uint32_t			f_logicalEngineId,
		uint32_t			f_pldId, 
		uint32_t			&f_mode); /* 1 - use table, 2 - table output high, 3 - table output low */

} //namespace dcc

#endif //DCC_OSCILLATOR_DEBUG_HPP


