#ifndef UTILENDIAN_H
#define UTILENDIAN_H

/**
 *  @file utilendian.H
 *
 *  @brief Central Include for all FipS Endian Conversions
 *
 *  This file contains the headers required for endian conversions and also
 *  two additional macros to support 64 bit endian conversion
*/
/**
 *  @page ChangeLogs Change Logs
 *  @section UTILENDIAN_H utilendian.H
 *  @verbatim
 *
 *  Flag PTR/DCR#   Userid    Date      Description
 *  ---  ---------- --------  --------  --------------------------------------
 *@endverbatim
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <netinet/in.h>

#ifndef _AIX
#include <byteswap.h>

# define ntohll(x)	bswap_64(x)
# define htonll(x)	bswap_64(x)

#else
#define __BYTE_ORDER __BIG_ENDIAN
#ifndef ntohll
# define ntohll(x)      (x) 
#endif
#ifndef htonll                                                   
# define htonll(x)      (x)      
#endif
#endif
/*****************************************************************************/
// Prototypes
/*****************************************************************************/

/*****************************************************************************/
// Inlines
/*****************************************************************************/


#endif //UTILENDIAN_H
