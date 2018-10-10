#ifndef ERRL_SERVICE_CODES_H
#define ERRL_SERVICE_CODES_H

#ifdef __HOSTBOOT_MODULE
#include <hbotcompid.H>
#else
#include <fips_comp_id.H>
#endif
/*****************************************************************************/
// User Types
/*****************************************************************************/
typedef unsigned short  comp_id_t;


/*****************************************************************************/
// Constants
/*****************************************************************************/


/** @enum  errlUserDataVersion
  *
  * Identifier for the version of user data in an error log.
  * This value is used in conjuction with the type field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the errl component.
*/
enum errlUserDataVersion
{
    ERRL_UDV_DEFAULT_VER_1	= 0x0001,   // Version 1, default info
    ERRL_UDV_DEFAULT_UD		= 0x0002,   // Default Errl User Data
    ERRL_UDV_DEFAULT_UD3	= 0x0003,   // Default Errl User Data section type 3
    ERRL_UDV_FILENAME_1		= 0x0001,   // Version 1 of filename
    ERRL_UDV_P3STATS_1		= 0x0001,   // Version 1 of P3 Stats UDs
    ERRL_UDV_SMGR_STATES_1	= 0x0001,   // Version 1 of FSP Smgr States UDs
    ERRL_UDV_JEDEC		= 0x0001,   // VPD Raw JEDEC UDs
    ERRL_UDV_CORR               = 0x0001,   // Corrosion History                  
    ERRL_UDV_SETINFOEVENT       = 0x0004    // Set informational event          
};



/** @enum  errlUserDataType
  *
  * Identifier for the user data type for the user data in an error log.
  * This value is used in conjuction with the version field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the errl component.
*/
enum errlUserDataType
{
    ERRL_UDT_MACH_SEC	    = 0x0000,   // Used by Machine section
    ERRL_UDT_FIRM_SEC	    = 0x0001,   // Used by Firmware setion
    ERRL_UDT_ERROR_LOG	    = 0x0002,   // Flat error log data
    ERRL_UDT_BOOT_CAPTURE   = 0x0003,	// Boot Capture file
    ERRL_UDT_UD_SEC	    = 0x0004,   // Used by default UD section
    ERRL_UDT_FILENAME	    = 0x0005,	// A filename
    ERRL_UDT_HEAP_OBJ	    = 0x0006,	// A memory copy of a UtilHeap
    ERRL_UDT_SYSLOG_MSG	    = 0x0007,	// A memory image of a syslog msg
    ERRL_UDT_FILE_HEADER    = 0x0008,	// Set of file Headers
    ERRL_UDT_DATA_BLOCK     = 0x0009,	// A filesystem data block
    ERRL_UDT_BLOCK_LIST     = 0x000A,	// Filesystem block list
    ERRL_UDT_FAT_LIST       = 0x000B,	// FAT block list
    ERRL_UDT_TRACE          = 0x000C,	// A trace buffer
    ERRL_UDT_P3STAT_MSG	    = 0x000D,	// A memory image of a p3Stat msg
    ERRL_UDT_P3STATS	    = 0x000E,	// P3 stats from p3 file 
    ERRL_UDT_MBOX_P3STATS   = 0x000F,	// P3 stats from phyp vi MBOX
    ERRL_UDT_SMGR_STATES    = 0x0010,	// Fsp Smgr State Entries
    ERRL_UDT_JEDEC          = 0x0011,	// SVPD JEDEC Data
    ERRL_UDT_CORR           = 0x0012,   // Corrosion History Data               
    ERRL_UDT_TABLE_HANDLER  = 0x0013,   // Errltablehandler                   
    ERRL_UDT_DEBUG_TRACING  = 0x0014,   // Enable debug tracing              
    ERRL_UDT_HB_TRACE       = 0x0015,   // Hostboot tracing               

    ERRL_UDT_LAST
};

#define         ERRL_ENTRYID_HUNDRED_COUNTER    100



#endif //ERRL_SERVICE_CODES_H
