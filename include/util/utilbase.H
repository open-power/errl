/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/utilbase.H $                                 */
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
#ifndef UTILBASE_H
#define UTILBASE_H

/**
 *	@file <utilbase.H>
 *
 *	@brief	Base class for Utility
 *
 *	This file contains global initialization parameters utilized by the
 *      utility but obtained at library initialization.
 */
/**
 *	@page ChangeLogs Change Logs
 *	@section UTILBASE.H <utilbase.H>
 *	@verbatim
 *
 *	Flag PTR/DCR#   Userid    Date      Description
 *	---  ---------- --------  --------  --------------------------------------
 *	@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Linux includes
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>

#include <util_service_codes.H>
#include <sys/types.h>   //pid_t
#include <dlfcn.h>


/*****************************************************************************/
// M A C R O S
/*****************************************************************************/

#define DNFP( _X_ )


#define UTIL_FAILURE	-1

/**
 *  @brief  Retrieve a nibble
 *  
 *  Considering a nibble in Little Endian ( 7,6,5,4,3,2,1,0 ), this macro
 *  returns that nibble.
 *
 *  @param  _v_ Value
 *  @param  _n_ Nibble to retrieve
 *
*/
#define	UTIL_GET_NIBBLE(_v_,_n_)    ( ( _v_ & ( 0x0F << _n_ * 4 ) ) >> _n_ * 4 )



/**
 *  @brief  Set a byte ( 8 bits ) to a given value
 *  
 *  Considering a byte in Little Endian ( 3,2,1,0 ), this macro
 *  sets that to the given value.  The input value should be on
 *  the bottom byte.
 *
 *  @param  _b_ Byte
 *  @param  _o_ Output
 *  @param  _v_ Value to set to
 *
*/
#define	UTIL_SET_BYTE(_o_,_v_,_b_)				    \
	_o_ &= ( ~( 0xFF << _b_ * 8 ) );			    \
	_o_ |= ( ( _v_ & 0x000000FF ) << (  _b_ * 8 ) )



/**
 *  @brief  Retrieve a byte
 *  
 *  Considering a byte in Little Endian ( 3,2,1,0 ), this macro
 *  retrieves that byte from the input value
 *
 *  @param  _v_ Value
 *  @param  _b_ Byte
 *
*/
#define	UTIL_GET_BYTE(_v_,_b_)    ( ( _v_ & ( 0xFF << _b_ * 8 ) ) >> _b_ * 8 )


    
/**
 *  @brief  Retrieve a halfword
 *  
 *  Considering a byte in Little Endian ( 3,2,1,0 ), this macro
 *  retrieves that byte from the input value
 *
 *  @param  _v_ Value
 *  @param  _h_ Byte
 *
*/
#define	UTIL_GET_HWORD(_v_,_h_)    ( ( _v_ & ( 0xFFFF << _h_ * 16 ) ) >> _h_ * 16 )


namespace util {


    /**
     *  @brief Util Wrapper to provide the thread level locking 
     *            for dlopen call
     *
     *  The parameters and return type are same as for dlopen call.
     *  @param FileName for executable object file
     *  @param Mode for relocation
     *  @param Error Number while executing the dlopen call.
     *
     *  @return  NULL for failure
     *
    */

      void * dlopen(const char *file, int mode,uint16_t& o_errNum); 

    /**
     *  @brief Util Wrapper to provide the thread level locking
     *            for system  call
     *
     *  The parameters and return type are same as for global system call
     *  @param command need to be executed. 
     *  @param errno to indcate an error
     *
     *  @return exit status = 0 on success
     *                       non-zero on failure
     *                      
     *
    */

      int system(const char *command, uint16_t& o_errNum);


} // namespace util

#endif// UTIL_H

