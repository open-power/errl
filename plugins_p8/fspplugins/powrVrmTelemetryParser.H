// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/powr/fsp/plugins/powrVrmTelemetryParser.H 1.2 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2017 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 

#ifndef POWR_VRM_TELEMETRY_PARSER_H
#define POWR_VRM_TELEMETRY_PARSER_H

// Standard library includes
#include <stdint.h>                   // for uint*_t
#include <string>
#include <vector>

// Other component includes
#include <errlusrparser.H>            // for ErrlUsrParser
#include <errltypes.H>                // for errlver_t
#include <rtim.H>                     // for BCD_time8_t

// powr includes


/**
 * @class VrmTelemetryParser
 *
 * This class parses VRM telemetry data stored in a user data section of an
 * error log.
 *
 * The user data section contains binary data.  All multi-byte integers in the
 * section are stored in big endian format.  This class parses the binary data
 * and produces formatted output.
 *
 * The errl tool normally produces console (plain text) output.  If the --xml
 * parameter is specified, errl produces XML output instead.  When in console
 * output mode, VrmTelemetryParser prints telemetry data in a table format for
 * brevity and readability.  When in XML output mode, VrmTelemetryParser prints
 * telemetry data in a hierarchical format.
 *
 * IMPORTANT NOTE!  The XML output of this class is parsed by tools that store
 * the telemetry data in databases.  The XML output format is defined/documented
 * in the XML schema vrm_telemetry.xsd.  If you must change the XML output
 * format, you must also do the following:
 *   - Update vrm_telemetry.xsd
 *   - Notify the owners of tools that parse the XML output.  Provide them with
 *     the updated schema.
 * The console mode output is not parsed by tools and can be changed as needed.
 */
class VrmTelemetryParser
{
  public:

    /**
     * Constructor.
     *
     * @param errlParser   ERRL user data section parser.  Used for formatted
     *                     output.
     * @param buffer       Buffer containing VRM telemetry data from user data
     *                     section.
     * @param bufferLength Buffer length.
     * @param version      Section version.  Used for backward compatibility
     *                     in case the format of the user data section changes
     *                     over time.
     */
    VrmTelemetryParser(ErrlUsrParser & errlParser, void * buffer,
                       uint32_t bufferLength, errlver_t version);

    /**
     * Destructor.
     */
    ~VrmTelemetryParser();
    
    /**
     * Parses the VRM telemetry data specified in the constructor.  Prints
     * formatted output using the ERRL user data section parser.
     *
     * @return true if user data section was successfully parsed, false otherwise
     */
    bool parse(void);

  private:

    /**
     * Prints one telemetry datum.
     *
     * @param timestamp time when datum was collected
     * @param type telemetry data type
     * @param value telemetry data value
     * @param unit data type unit, such as "V" for volts
     */
    void printDatum(const BCD_time8_t& timestamp,
                    const std::string& type, double value,
                    const std::string& unit);

    /**
     * Prints output related to the start of a telemetry data set list.
     */
    void printDataSetListStart(void);

    /**
     * Prints output related to the end of a telemetry data set list.
     */
    void printDataSetListEnd(void);

    /**
     * Prints output related to the start of telemetry data for the specified
     * rail (VRM master).
     *
     * @param rail rail name (VRM master ID)
     */
    void printRailStart(const std::string& rail);

    /**
     * Prints output related to the end of telemetry data for a rail (VRM
     * master).
     */
    void printRailEnd(void);

    /**
     * Prints output related to the start of telemetry data for the specified
     * drawer.
     *
     * @param drawerNumber drawer number
     */
    void printDrawerStart(uint8_t drawerNumber);

    /**
     * Prints output related to the end of telemetry data for a drawer.
     */
    void printDrawerEnd(void);

    /**
     * Prints output related to the start of telemetry data for this user data
     * section.
     */
    void printVrmTelemetryStart(void);

    /**
     * Prints output related to the end of telemetry data for this user data
     * section.
     */
    void printVrmTelemetryEnd(void);

    /**
     * Gets the name and unit of the specified telemetry data type.  The unit is
     * the suffix appearing after the value, such as "V" for volts or "C" for
     * degrees Celsius.
     *
     * @param type telemetry data type
     * @param name data type name is stored in this parameter
     * @param unit data type unit is stored in this parameter
     * @return true if name and unit were found, false otherwise
     */
    bool getDataTypeProperties(uint8_t type, std::string& name,
                               std::string& unit) const;

    /**
     * Converts a PMBus linear data format value to a double.  The linear data
     * format contains an 11 bit mantissa and 5 bit exponent.
     *
     * @param value linear data format value to convert
     * @return double value
     */
    double convertLinearToDouble(uint16_t value) const;

    /**
     * Returns the number of bytes left to parse in the buffer.
     *
     * @return number of bytes left to parse
     */
    inline uint32_t bytesLeft(void) const;

    /**
     * Reads a uint8_t value from the current offset in the buffer and then
     * advances the buffer offset.
     *
     * @param value value read from buffer is stored in this parameter
     * @return true if value was successfully read from buffer, false otherwise
     */
    inline bool parseUint8(uint8_t& value);

    /**
     * Reads a uint16_t value from the current offset in the buffer and then
     * advances the buffer offset.  Assumes the value is stored in big-endian
     * format in the buffer.
     *
     * @param value value read from buffer is stored in this parameter
     * @return true if value was successfully read from buffer, false otherwise
     */
    inline bool parseUint16(uint16_t& value);

    /**
     * Reads a null-terminated string value from the current offset in the
     * buffer.  Advances the buffer offset to the position after the string that
     * was read.
     *
     * @param str string read from buffer is stored in this parameter
     * @return true if string was successfully read from buffer, false otherwise
     */
    bool parseString(std::string& str);

    /**
     * Parses the timestamp list located at the current offset in the buffer.
     *
     * @return true if timestamp list was successfully parsed, false otherwise
     */
    bool parseTimestampList(void);

    /**
     * Parses the telemetry datum located at the current offset in the buffer.
     *
     * @param timestamp timestamp associated with datum
     * @return true if datum was successfully parsed, false otherwise
     */
    bool parseDatum(const BCD_time8_t& timestamp);

    /**
     * Parses the telemetry data set located at the current offset in the
     * buffer.
     *
     * @return true if data set was successfully parsed, false otherwise
     */
    bool parseDataSet(void);

    /**
     * Parses the list of telemetry data sets located at the current offset in
     * the buffer.
     *
     * @return true if data set list was successfully parsed, false otherwise
     */
    bool parseDataSetList(void);

    /**
     * Parses the list of VRM masters and their telemetry data located at the
     * current offset in the buffer.
     *
     * @return true if VRM master list was successfully parsed, false otherwise
     */
    bool parseVrmMasterList(void);

    /**
     * Parses the drawer and its telemetry data located at the current offset in
     * the buffer.
     *
     * @return true if drawer was successfully parsed, false otherwise
     */
    bool parseDrawer(void);

    // Unsupported methods
    VrmTelemetryParser(const VrmTelemetryParser& other);
    VrmTelemetryParser& operator=(const VrmTelemetryParser& other);

    // Make CxxTest class a friend so it can test private methods
    friend class VrmTelemetryParserTest;

    // Data members
    ErrlUsrParser * iv_errlParser;              // ERRL user data section parser
    uint8_t * iv_buffer;                        // Data from user data section
    uint32_t iv_bufferLength;                   // Length of iv_buffer
    errlver_t iv_version;                       // User data section version
    bool iv_outputIsXml;                        // Is parser output XML?
    uint32_t iv_offset;                         // Current offset in iv_buffer
    std::vector<BCD_time8_t> iv_timestampList;  // List of timestamps found in section
};


inline uint32_t VrmTelemetryParser::bytesLeft(void) const
{
  return (iv_bufferLength > iv_offset) ? (iv_bufferLength - iv_offset) : 0;
}


inline bool VrmTelemetryParser::parseUint8(uint8_t& value)
{
  bool rc = false;
  if (bytesLeft() >= 1)
  {
    value = iv_buffer[iv_offset++];
    rc = true;
  }
  return rc;
}


inline bool VrmTelemetryParser::parseUint16(uint16_t& value)
{
  bool rc = false;
  if (bytesLeft() >= 2)
  {
    // Note: multi-byte values are big-endian
    value = ((uint16_t) iv_buffer[iv_offset++]) << 8;
    value |= (uint16_t) iv_buffer[iv_offset++];
    rc = true;
  }
  return rc;
}


#endif /* POWR_VRM_TELEMETRY_PARSER_H */
