/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/util_service_codes.H $                       */
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
#ifndef UTIL_SERVICE_CODES_H
#define UTIL_SERVICE_CODES_H

/**
 *	@file util_service_codes.H
 *
 *	@brief	<Brief Description of this file>
 *
 *	<Detailed description of what this file does, functions it includes,
 *	etc,>
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section UTIL_SERVICE_CODES_H util_service_codes.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>		// for uint32_t

#ifdef __HOSTBOOT_MODULE
#include <hbotcompid.H>
#else
#include <fips_comp_id.H>
#endif

/*****************************************************************************/
// User Types
/*****************************************************************************/
typedef unsigned short  comp_id_t;
//const comp_id_t UTIL_COMP_ID     = 0x8A00;


struct UTIL_UDT_MEM_ALLOC_t
{
    UTIL_UDT_MEM_ALLOC_t( uint32_t i_requested )
    : iv_requested( i_requested) , iv_pointer( 0 )
    {
    }

    uint32_t	iv_requested;	///< Amount of bytes requested
    void *	iv_pointer;	///< Existing pointer if available
};

/*****************************************************************************/
// Constants
/*****************************************************************************/

/** @enum utilModId
 *
 *  "Module ids" for util SRCs.  Each module Id corresponds to a particular
 *  method in a class or an individual function.
 *
*/
enum utilModId
{
    UTIL_BCDTIME_FLTN		= 0x01,
    UTIL_BCDTIME_UNFLTN		= 0x02,
    UTIL_MID_REG_READ		= 0x03,
    UTIL_MID_REG_WRITE		= 0x04,
    UTIL_MID_REG_PATH		= 0x05,
    UTIL_MID_MEM_CTOR_2		= 0x06,
    UTIL_MID_MEM_READ		= 0x07,
    UTIL_MID_MEM_WRITE		= 0x08,
    UTIL_MID_FILE_CTOR		= 0x09,
    UTIL_MID_FILE_OPEN		= 0x0A,	    // UtilFile::Open( mode )
    UTIL_MID_FILE_CLOSE		= 0x0B,
    UTIL_MID_FILE_READ		= 0x0C,
    UTIL_MID_FILE_WRITE		= 0x0D,
    UTIL_MID_FILE_SEEK		= 0x0E,
    UTIL_MID_FILE_SIZE		= 0x0F,
    UTIL_MID_FILE_LOCK		= 0x10,
    UTIL_MID_FILE_UNLOCK	= 0x11,
    UTIL_MID_FILE_MAP		= 0x12,
    UTIL_MID_FILE_UNMAP		= 0x13,
    UTIL_MID_FILE_REMOVE_STATIC	= 0x14,
    UTIL_MID_FILE_REMOVE	= 0x15,
    UTIL_MID_SEM_CTOR		= 0x16,	    // Semaphore constructor
    UTIL_MID_SEM_CONTROL	= 0x17,	    // Semaphore operation
    UTIL_MID_REG_PS		= 0x18,	    // Platform Specific Registry
    UTIL_MID_REG_REDWRITE	= 0x19,	    // Redundant Registry Write
    UTIL_MID_REG_SIGNAL		= 0x1A,	    // Event Signal for regwrite
    UTIL_LIB_EXTRACT		= 0x1B,
    UTIL_MID_FILE_STAT		= 0x1C,	    // UtilFile Stat
    UTIL_MID_FILE_SCANF		= 0x1D,	    // UtilFile scanf
    UTIL_MID_REG_SYNC  		= 0x1E,	    // Sync Immediate key
    UTIL_MID_SEM_GET_VAL	= 0x1F,	    // UtilSem::getValue
    UTIL_MID_FILE_OPEN_2	= 0x20,	    // UtilFile::Open( name, mode )
    UTIL_MID_FILE_FGETS		= 0x21,	    // UtilFile::fgets
    UTIL_MID_FILE_SYNC		= 0x22,	    // UtilFile::Sync
    UTIL_MID_FILE__READ		= 0x23,	    // internal UtilFile read
    UTIL_BASE_REG_SET		= 0x24,     // mdiaSetNewDimmAddedRegistry() 
    UTIL_BASE_REG_RESET         = 0x25,     // mdiaResetNewDimmAddedRegistry()
    UTIL_MID_FILE_MRID          = 0x26,     // util::Get_List_Of_Mrids()
    UTIL_MID_HEAP_MAP           = 0x27,     // UtilHeap::Map for object
    UTIL_MID_DIR_MAKE           = 0x28,     // make directory call or function in util 
    UTIL_MID_DIR_REMOVE         = 0x29,     // remove directory 
    UTIL_MID_FILE_CREATELOG     = 0x2A,     // Create log function for P1 out of space
    UTIL_MID_REG_BUILDERROR     = 0x2B,     // Build log function for P1 out of space
    UTIL_MID_FILE_SYNCWRITE     = 0x2C,     // Util SyncWrite
    UTIL_MID_REG_READ_HRMOR     = 0x2D,     // Reading HRMOR registry 
    UTIL_MID_SEMA_INIT          = 0x2E,     // UtilSemaphore initialization
    UTIL_MID_SEMA_GET_VAL       = 0x2F,     // UtilSemaphore get value 
    UTIL_MID_SEMA_CHECK_INIT    = 0x30,     // UtilSemaphore check init
    UTIL_MID_SEMA_CONTROL       = 0x31,     // UtilSemaphore control 
    UTIL_MID_BSEMA_UNLOCK       = 0x32,     // UtilBinSemaphore unlock
    UTIL_MID_APP_CMDLINE_CHECK  = 0x33,     // AppCmdLine::CheckArgs
    UTIL_MID_INOTIFY_DESTRUCTOR = 0x34,     // Inotify Destructor
    UTIL_MID_INOTIFY_ADD_WATCH  = 0x35,     // Inotify::AddWatch
    UTIL_MID_INOTIFY_REM_WATCH  = 0x36,     // Inotify::RemoveWatch
    UTIL_MID_INOTIFY_RETRIEVE   = 0x37,     // Inotify::RetrieveEvent
    UTIL_MID_THPOOL_DISPATCH    = 0x38,     // ThreadPool::Dispatch
    UTIL_MID_XMLPARSE           = 0x39,     // XML Parser
    UTIL_MID_SHMEM_INIT         = 0x3A,     // ShMem::Init
    UTIL_MID_SHMEM_RDLOCK       = 0x3B,     // ShMem::ReadLock
    UTIL_MID_SHMEM_TRYRDLOCK    = 0x3C,     // ShMem::TryReadLock
    UTIL_MID_SHMEM_WRLOCK       = 0x3D,     // ShMem::WriteLock
    UTIL_MID_SHMEM_TRYWRLOCK    = 0x3E,     // ShMem::TryWriteLock
    UTIL_MID_SHMEM_UNLOCK       = 0x3F,     // ShMem::UnLock
    UTIL_MID_SHMEM_GET          = 0x40,     // ShMem::Get
    UTIL_MID_SHMEM_ATTACH       = 0x41,     // ShMem::Attach
    UTIL_MID_SHMEM_REMOVE       = 0x42,     // ShMem::Remove
    UTIL_MID_FILE_FTELL			= 0x43,     // UtilFile::fpos
    UTIL_MID_FILE_GET_LINE      = 0x44,     // UtilFile::getLine
	UTIL_MID_FILE_EOF           = 0x45,		// UtilFile::eof
	UTIL_MID_FILE_SIZE_TILL_EOF = 0x46,		// UtilFile::sizeTillEOF
    UTIL_MID_LAST_ONE		= 0xFF	    // Placeholder for last one
};



/** @enum  utilExtRefCode
  *
  * Extended reference codes for utility. Extended ref
  * codes can be used in more than one location.  The combination
  * of module id and extended ref code points to a unique piece of
  * code. Therefore, if the same error can occur in multiple places
  * within the same function/method, each error would need its own
  * unique extended ref code.
*/
enum utilExtRefCode
{
    UTIL_ERC_NONE		=0x0000,    ///< None

    UTIL_ERC_INVALID_SZ		= UTIL_COMP_ID | 0x01,    ///< Passed invalid size
    UTIL_ERC_INVALID_KEY	= UTIL_COMP_ID | 0x02,    ///< The key parameter is invalid or does not exist
    UTIL_ERC_SIZE_MISMATCH      = UTIL_COMP_ID | 0x03,    ///< The amt requested does not match the registry value.
    UTIL_ERC_BB_REG_FAIL_WRITE	= UTIL_COMP_ID | 0x04,    ///< Underlying registry failure when calling reg_write
    UTIL_ERC_DETERMINE_PS_FIELD = UTIL_COMP_ID | 0x05,    ///< Determining platform specific field
    UTIL_ERC_REDUNDANT_WRITE    = UTIL_COMP_ID | 0x06,    ///< Redundant Write Failure
    UTIL_ERC_EVENT_SIGNAL	= UTIL_COMP_ID | 0x07,    ///< Write Event signal failure
    UTIL_ERC_INVALID_EVENT_ID   = UTIL_COMP_ID | 0x08,    ///< Event Id specified in special field is invalid
    UTIL_ERC_FS_FAILURE		= UTIL_COMP_ID | 0x09,    ///< File System failure
    UTIL_ERC_BB_REG_FAIL_SZOF	= UTIL_COMP_ID | 0x0A,    ///< Underlying registry failure
    UTIL_ERC_REG_PATH		= UTIL_COMP_ID | 0x0B,    ///< Error in forming registry path
    UTIL_ERC_FTELL_FAILED	= UTIL_COMP_ID | 0x0C,    ///< ftell failure
    UTIL_ERC_ALLOC_FAIL		= UTIL_COMP_ID | 0x0D,    ///< Allocation Failed
    UTIL_ERC_OP_FAILED		= UTIL_COMP_ID | 0x0E,    ///< Requested Operation Failed
    UTIL_ERC_FILE_NOT_OPEN	= UTIL_COMP_ID | 0x0F,    ///< File Not Open
    UTIL_ERC_FILE_EOF		= UTIL_COMP_ID | 0x10,    ///< EOF reached
    UTIL_ERC_BAD_PTR		= UTIL_COMP_ID | 0x11,    ///< Invalid memory pointer
    UTIL_ERC_EOF		= UTIL_COMP_ID | 0x12,    ///< General End of File
    UTIL_ERC_FILE_REMOVE	= UTIL_COMP_ID | 0x13,    ///< File remove failure
    UTIL_ERC_FILE_FCNTL		= UTIL_COMP_ID | 0x14,    ///< File Control
    UTIL_ERC_SEM		= UTIL_COMP_ID | 0x15,    ///< General semaphore operation
    UTIL_ERC_SEM_GET		= UTIL_COMP_ID | 0x16,    ///< Semaphore acquisition failure
    UTIL_ERC_SEM_CTL		= UTIL_COMP_ID | 0x17,    ///< Semaphore control failure
    UTIL_ERC_SEM_OP		= UTIL_COMP_ID | 0x18,    ///< Semaphore operation failure
    UTIL_ERC_FTOK		= UTIL_COMP_ID | 0x19,    ///< File tokenizer failure
    UTIL_LIB_DLOPEN		= UTIL_COMP_ID | 0x1A,
    UTIL_LIB_DLSYM		= UTIL_COMP_ID | 0x1B,
    UTIL_ERC_REG_SYNC		= UTIL_COMP_ID | 0x1C,    ///< Failed in immediate sync
    UTIL_ERC_SEM_GET_VAL	= UTIL_COMP_ID | 0x1D,    ///< Failed in UtilSem::getValue
    UTIL_ERC_BB_REG_FAIL_READ	= UTIL_COMP_ID | 0x1E,    ///< Underlying registry failure when calling reg_read
    UTIL_ERC_BB_REG_FAIL_UDATA	= UTIL_COMP_ID | 0x1F,    ///< Underlying registry failure when calling reg_udata
    UTIL_ERC_RMGRSYNC_FAIL	= UTIL_COMP_ID | 0x20,    ///< Underlying RMGR sync call failed
    UTIL_ERC_OP_FAILED_READ	= UTIL_COMP_ID | 0x21,    ///< Requested Operation Failed internal read (_read)
    UTIL_ERC_FILE_NOT_EXISTS    = UTIL_COMP_ID | 0x22,    ///< The file path does not exists 
    UTIL_ERC_COMP_NO_EXISTS     = UTIL_COMP_ID | 0x23,    ///< Some part of the path does not exists
    UTIL_ERC_COMP_NOT_DIR       = UTIL_COMP_ID | 0x24,    ///< Some part of the path is not a directory
    UTIL_ERC_NO_ACCESS          = UTIL_COMP_ID | 0x25,    ///< The directory does not have access
    UTIL_ERC_DIR_NO_EXISTS      = UTIL_COMP_ID | 0x26,    ///< The directory does not exists
    UTIL_ERC_NOT_DIR            = UTIL_COMP_ID | 0x27,    ///< The name may be existing as a file already
    UTIL_ERC_DIR_ERROR          = UTIL_COMP_ID | 0x28,    ///< Some error occured in directory related call
    UTIL_ERC_IN_CURR_DIR        = UTIL_COMP_ID | 0x29,    ///< Cannot remove current directory 
    UTIL_ERC_DIR_EXISTS         = UTIL_COMP_ID | 0x2A,    ///< The directory already exists
    UTIL_ERC_DIR_NOSPC          = UTIL_COMP_ID | 0x2B,    ///< No space to create directory
    UTIL_ERC_ADAL_OPEN_FAILED   = UTIL_COMP_ID | 0x2C,    ///< The adal opened failed
    UTIL_ERC_DISR_WRITE_FAILED  = UTIL_COMP_ID | 0x2D,    ///< Disr bit was not written properly
    UTIL_ERC_SYNC_WRITE_FAILED  = UTIL_COMP_ID | 0x2E,    ///< Sync write fail   
    UTIL_ERC_SEM_ALREADY_INIT   = UTIL_COMP_ID | 0x2F,    ///< UtilSemaphore already inited
    UTIL_ERC_SEM_NOT_INIT       = UTIL_COMP_ID | 0x30,    ///< Semaphore not initialized
    UTIL_ERC_FILE_LOCK_FAIL     = UTIL_COMP_ID | 0x31,    ///< File lock failure
    UTIL_ERC_BSEM_UNLOCKED      = UTIL_COMP_ID | 0x32,    ///< Binary semaphore already unlocked
    UTIL_ERC_INOTIFY_EACCESS    = UTIL_COMP_ID | 0x33,    ///< EACCESS from iNotify. No read access to file
    UTIL_ERC_INOTIFY_EINVAL     = UTIL_COMP_ID | 0x34,    ///< EINVAL from Inotify system call
    UTIL_ERC_INOTIFY_CALLBACK   = UTIL_COMP_ID | 0x35,    ///< Inotify object in callback mode
    UTIL_ERC_INOTIFY_NO_WATCH   = UTIL_COMP_ID | 0x36,    ///< No initial AddWatch call for Inotify object
    UTIL_ERC_THPOOL_OVERFLOW    = UTIL_COMP_ID | 0x37,    ///< Thread Pool Overflow
    UTIL_ERC_STREAM_ERROR       = UTIL_COMP_ID | 0x38,    ///< Stream read/write error
    UTIL_ERC_XML_INCOMPLETE_TAG = UTIL_COMP_ID | 0x39,    ///< XML Tag without terminating ">" character
    UTIL_ERC_XML_VAL_NO_ELEM    = UTIL_COMP_ID | 0x3A,    ///< XML Value detected outside of element
    UTIL_ERC_XML_BAD_TAG        = UTIL_COMP_ID | 0x3B,    ///< Unrecognised XML Tag
    UTIL_ERC_XML_BAD_CLOSE      = UTIL_COMP_ID | 0x3C,    ///< XML Close Tag without preceeding Open Tag
    UTIL_ERC_XML_MISMATCH_CLOSE = UTIL_COMP_ID | 0x3D,    ///< XML Close Tag does not match preceeding Open Tag
    UTIL_ERC_XML_ATTR_NO_NAME   = UTIL_COMP_ID | 0x3E,    ///< XML attribute with no name
    UTIL_ERC_XML_ATTR_NO_EQUALS = UTIL_COMP_ID | 0x3F,    ///< XML attribute without =" characters
    UTIL_ERC_XML_NO_ATTR_VAL    = UTIL_COMP_ID | 0x40,    ///< XML attribute without value 
    UTIL_ERC_XML_INCOMPLETE_DOC = UTIL_COMP_ID | 0x41,    ///< Incomplete XML document
    UTIL_ERC_XML_EMPTY_DOC      = UTIL_COMP_ID | 0x42,    ///< Empty XML document
    UTIL_ERC_FD_CLOSE_FAILURE   = UTIL_COMP_ID | 0x43,    ///< Error closing file descriptor
    UTIL_ERC_SHMEM_ALREADY_INIT = UTIL_COMP_ID | 0x44,    ///< Shared Memory object already initialized.
    UTIL_ERC_SHMEM_TOO_SMALL    = UTIL_COMP_ID | 0x45,    ///< shmget returned EINVAL - existing mem too small
    UTIL_ERC_SHMEM_BAD_SIZE     = UTIL_COMP_ID | 0x46,    ///< shmget returned EINVAL - bad size requested
    UTIL_ERC_SHMEM_UNINIT       = UTIL_COMP_ID | 0x47,    ///< Shared Memory object uninitialized
    UTIL_ERC_SHMEM_NO_MEM       = UTIL_COMP_ID | 0x48,    ///< shm* returned EINVAL. No Shared Memory
    UTIL_ERC_SHMEM_UNLOCKED     = UTIL_COMP_ID | 0x49,    ///< Shared Memory object unlocked
    UTIL_ERC_OP_FAILED_GETLINE  = UTIL_COMP_ID | 0x4A,    ///< File Getline failed
    UTIL_ERC_LAST_ONE           = UTIL_COMP_ID | 0xFF     // Not used: indicates range limit
}; 



/** @enum  utilUserDataVersion
  *
  * Identifier for the version of user data in an error log.
  * This value is used in conjuction with the type field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the util component.
*/
enum utilUserDataVersion
{
    UTIL_UDV_DEFAULT_VER	= 0x0001,   // Default version
    UTIL_UDV_STREAM_VER_1	= 0x0001,   // Version 1 of Stream Data
    UTIL_UDV_MEM_ALLOC		= 0x0001,   // Version 1 of Memory Failures
    UTIL_UDV_REG_KEYS_1		= 0x0001,   // Version 1 of Reg keys
    UTIL_UDV_REG_DATA_1		= 0x0001,   // Version 1 of Reg key data
    UTIL_UDV_FILENAME_1		= 0x0001,   // Version 1 of File Name
    UTIL_UDV_FLOCK_1		= 0x0001,   // Version 1 of the flock struct
    UTIL_UDV_SEMAPHORE_1	= 0x0001,   // Version 1 of the semaphore class
    UTIL_UDV_SEMAPHORE_2	= 0x0002,   // Version 2 of the semaphore class
    UTIL_UDV_DIRNAME_1  	= 0x0001    // Version 1 of the Directory Name
};



/** @enum  utilUserDataType
  *
  * Identifier for the user data type for the user data in an error log.
  * This value is used in conjuction with the version field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the util component.
*/
enum utilUserDataType
{
    UTIL_UDT_STREAM_PERC	= 0x0001,///< Perc Data for Streams
    UTIL_UDT_MEM_ALLOC      = 0x0002,///< Memory Allocation Failure
    UTIL_UDT_REG_KEYS		= 0x0003,///< Registry key name, with data
    UTIL_UDT_FILENAME		= 0x0004,///< A null terminated filename
    UTIL_UDT_FLOCK		    = 0x0005,///< An flock struct
    UTIL_UDT_SEMAPHORE		= 0x0006,///< A semaphore object
    UTIL_UDT_LIBNAME		= 0x0007,///< Name of the library
    UTIL_UDT_REG_DATA		= 0x0008,///< Payload data for UtilReg::write
    UTIL_UDT_ERR_MSG		= 0x0009,///< An error message string
    UTIL_UDT_INOTIFY_PATH   = 0x000a,///< The path name in error
    UTIL_UDT_XML_TOKEN      = 0x000b,///< The XML token in error
    UTIL_UDT_DIRNAME        = 0x000c,///< A null terminated directory 
};



/** @enum  utilFileId
  *
  * Identifies source files in a software error section
  *
  *
*/
enum utilFileId
{
    UTIL_FID_FILE		= 0x0001,   // UtilFile
    UTIL_FID_SEM		= 0x0002,   // UtilSem
    UTIL_FID_XML        = 0x0003,   // XML
    UTIL_FID_SHMEM      = 0x0004    // Shared Memory
};


/*****************************************************************************/
// Synonyms
/*****************************************************************************/

/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Prototypes
/*****************************************************************************/

/*****************************************************************************/
// Inlines
/*****************************************************************************/


#endif //UTIL_SERVICE_CODES_H

