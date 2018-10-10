
#ifndef RTIM_H
#define RTIM_H



/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <stdint.h>          // standard types


/*-----------------------------------------------------------------------------*/
/* Macros                                                                      */
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/* Type definitions                                                            */
/*-----------------------------------------------------------------------------*/

/** @brief Type definition for an 8 byte BCD time structure.
 */
struct BCD_time8_t
{
  uint16_t year;
  uint8_t  month;
  uint8_t  day;
  uint8_t  hours;
  uint8_t  minutes;
  uint8_t  seconds;
  uint8_t  hundredths;
}  __attribute__ ((packed));

/** @brief Type definition for a 12 byte BCD time structure.
 */
struct BCD_time12_t
{
  uint16_t year;
  uint8_t  month;
  uint8_t  day;
  uint8_t  hours;
  uint8_t  minutes;
  uint8_t  seconds;
  uint8_t  reserved;
  uint32_t microseconds;
}  __attribute__ ((packed));

/** @brief Type definition for a 12 byte Binary time structure.
 */
struct BIN_time12_t
{
  uint16_t year;
  uint8_t  month;
  uint8_t  day;
  uint8_t  hours;
  uint8_t  minutes;
  uint8_t  seconds;
  uint8_t  hundredths;
  uint32_t microseconds;
}  __attribute__ ((packed));

#endif // RTIM_H
