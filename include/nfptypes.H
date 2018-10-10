/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/nfptypes.H $                                 */
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
#ifndef _NFPTYPES_H
#define _NFPTYPES_H
/* Copyright ***********************************************************
 * File nfptypes.H created by Ward Nelson at 09:31:06 on Fri Jun  6 2003.
 *
 * Classification:  IBM Confidential
 * (c) Copyright IBM Corp. 2003
 * Licensed material - Program property of IBM
 * Refer to copyright instructions form no. G1120-2083
 * End Copyright *******************************************************
 */

// System Includes
#ifdef _AIX
 #include <inttypes.h>  // AIX definition of basic integer types
#else  // Not _AIX
 #ifdef _WIN
  #include <netctypes.H>
 #else
  #ifndef _LINUX_TYPES_H
   #ifndef _STDINT_H
    #include <stdint.h>
   #endif  // _STDINT_H
  #endif  // _LINUX_TYPES_H
 #endif  // _WIN
#endif  // _AIX or not


#ifdef _WIN
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
#include <process.h>
#include <winsock.h>
#include <fcntl.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long  uint32_t;
typedef __int64 uint64_t;

typedef char  int8_t;
typedef short int16_t;
typedef long  int32_t;

#else
    /* define AIX header files here */

#endif

#endif /* _NFPTYPES_H  */
