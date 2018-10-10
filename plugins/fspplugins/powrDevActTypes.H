// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/powr/fsp/dev_actions/powrDevActTypes.H 1.7 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2015,2017 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/**
 * @file powrDevActTypes.H
 *
 * This file contains simple data types and typedefs used within the device
 * action framework.
 */

#ifndef POWR_DEV_ACT_TYPES_H
#define POWR_DEV_ACT_TYPES_H

// Standard library includes
#include <stdint.h>                 // for uint*_t and int*_t
#include <vector>

// Other component includes

// powr includes


namespace dev_actions
{
  /**
   * Mask value that determines which bits within a byte are affected by an
   * action.  The lowest order bit in the mask corresponds with the lowest
   * order bit in the byte.
   */
  typedef uint8_t bit_mask_t;


  /**
   * Bit position within a one byte value.  The bit position must be a number
   * from 0 to 7.  Bit 0 is the least significant bit, and bit 7 is the most
   * significant bit.
   */
  typedef uint8_t bit_position_t;


  /**
   * Value of a single bit.  Must be 0 or 1.
   */
  typedef uint8_t bit_value_t;


  /**
   * Value of a byte.  Must be between 0x00 and 0xFF.
   */
  typedef uint8_t byte_value_t;


  /**
   * General device address.  i2c_address_t is a logical sub-type.
   */
  typedef uint8_t device_addr_t;


  /**
   * Exponent value.  Note it must be signed to support negative exponents.
   */
  typedef int8_t exponent_t;


  /**
   * I2C address used to communicate with a device such as a VRM master or a
   * microcontroller.
   */
  typedef uint8_t i2c_address_t;


  /**
   * Byte offset.  Note that the byte at offset 0 is the first byte in a
   * sequence.  Offset 1 is the second byte.
   */
  typedef uint8_t offset_t;


  /**
   * Device register address.
   */
  typedef uint8_t register_t;


  /**
   * Telemetry data type.  This enumeration defines the types of telemetry data
   * that can be collected.
   *
   * This enumeration is used when collecting the data, storing the data in an
   * error log, and parsing the error log.  As a result, there are several
   * important rules for defining new enumerators:
   *   - Must be assigned a specific value.
   *   - Values must fit within a uint8_t, so the range is 0x00 - 0xFF.
   *   - Values cannot be changed.  The error log parser plug-in needs to handle
   *     both the current release and previous releases.
   *   - Value ranges are reserved for categories of data.  This will allow new
   *     values to be grouped with related values.
   */
  enum telemetry_data_type_t
  {
    // Range 0x00 - 0x0F reserved for current output values
    TELEMETRY_TYPE_IOUT             = 0x00u,  ///< Current output
    TELEMETRY_TYPE_IOUT_PEAK        = 0x01u,  ///< Current output peak (max)
    TELEMETRY_TYPE_IOUT_VALLEY      = 0x02u,  ///< Current output valley (min)

    // Range 0x10 - 0x1F reserved for temperature values
    TELEMETRY_TYPE_TEMPERATURE      = 0x10u,  ///< Temperature
    TELEMETRY_TYPE_TEMPERATURE_PEAK = 0x11u,  ///< Temperature peak (max)

    // Range 0x20 - 0x2F reserved for voltage output values
    TELEMETRY_TYPE_VOUT             = 0x20u,  ///< Voltage output
    TELEMETRY_TYPE_VOUT_PEAK        = 0x21u,  ///< Voltage output peak (max)
    TELEMETRY_TYPE_VOUT_VALLEY      = 0x22u   ///< Voltage output valley (min)
  };


  /**
   * Telemetry datum.  This structure contains one telemetry data value.
   *
   * The type field indicates what kind of telemetry data was read.  This field
   * contains one of the telemetry_data_type_t values.  However, it is declared
   * as a uint8_t to save space since enums are of type int.
   *
   * The value field contains the telemetry value that was read from a device.
   * The value is stored in PMBus linear data format.  This format contains a
   * 5-bit signed exponent and an 11-bit signed mantissa.  Use
   * PmBusUtils::convertLinearToDouble() to convert this value to a double.
   *
   * This structure is packed to save memory.
   */
  struct telemetry_datum_t
  {
    uint8_t  type;    ///< Telemetry data type
    uint16_t value;   ///< Telemetry data value (PMBus linear format)
  } __attribute__ ((packed));


  /**
   * Telemetry timestamp ID.  A timestamp is created whenever telemetry data is
   * collected.  Timestamps require 8 bytes on the FSP.  Since telemetry data
   * is collected from many devices at roughly the same time, a single timestamp
   * is used to save memory.  The timestamp is referenced using this ID.
   */
  typedef uint16_t telemetry_timestamp_id_t;


  /**
   * Telemetry data set.  This structure contains the set of telemetry data that
   * was collected from one device at a specific time.
   */
  struct telemetry_data_set_t
  {
    telemetry_timestamp_id_t timestamp;   ///< Time when data was collected
    std::vector<telemetry_datum_t> data;  ///< Telemetry data that was collected
  };


  /**
   * VID (Voltage ID) value used to set the output voltage of a VRM master.
   */
  typedef uint8_t vid_t;


  /**
   * Voltage value expressed in volts.
   */
  typedef double volts_t;

}  // End dev_actions namespace


#endif /* POWR_DEV_ACT_TYPES_H */
