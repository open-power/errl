// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/powr/fsp/plugins/powrVrmTelemetryParser.C 1.3 
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

// Standard library includes
#include <stdio.h>                    // for snprintf()
#include <ctype.h>                    // for isprint()
#include <math.h>                     // for pow()
#include <arpa/inet.h>                // for htons()

// Other component includes
#include <errlxmlparser.H>            // for ErrlXmlParser

// powr includes
#include <powrVrmTelemetryParser.H>
#include <powrDevActTypes.H>          // for telemetry data types
#include <powr_service_codes.H>       // for sub-section versions

/*
 * IMPORTANT NOTE!  The XML output of this class is parsed by tools that store
 * the telemetry data in databases.  Tool owners need to be notified if the XML
 * output format changes.  See powrVrmTelemetryParser.H for more information.
 */

using namespace dev_actions;


/* ************************************************************************** */
/*                               Public methods                               */
/* ************************************************************************** */

VrmTelemetryParser::VrmTelemetryParser(ErrlUsrParser & errlParser, void * buffer,
                                       uint32_t bufferLength, errlver_t version) :
  iv_errlParser(&errlParser),
  iv_buffer((uint8_t*) buffer),
  iv_bufferLength(bufferLength),
  iv_version(version),
  iv_outputIsXml(false),
  iv_offset(0),
  iv_timestampList()
{
  // Determine whether the ERRL parser is producing XML or console (plain text)
  // output.  Unfortunately there is no method we can call to determine this, so
  // we have to rely on the run-time type information of the ERRL parser object.
  // The ErrlUsrParser class produces console mode output.  The ErrlXmlParser
  // class, which inherits from ErrlUsrParser, produces XML output.
  iv_outputIsXml = (dynamic_cast<ErrlXmlParser*>(iv_errlParser));
}


VrmTelemetryParser::~VrmTelemetryParser()
{
  // Currently nothing to do.  The pointer data members refer to objects/memory
  // that we did not allocate and do not own.
}


bool VrmTelemetryParser::parse(void)
{
  // Verify user data section version has expected value
  if (iv_version != POWR_DEFAULT_VER)
  {
    return false;
  }

  // Print start of VRM telemetry data
  printVrmTelemetryStart();

  // Parse drawer and its telemetry data
  if (!parseDrawer())
  {
    return false;
  }

  // Print end of VRM telemetry data
  printVrmTelemetryEnd();

  // Parsing succeeded; return true
  return true;
}


/* ************************************************************************** */
/*                              Private methods                               */
/* ************************************************************************** */

void VrmTelemetryParser::printDatum(const BCD_time8_t& timestamp,
                                    const std::string& type, double value,
                                    const std::string& unit)
{
  // If we are in XML output mode
  if (iv_outputIsXml)
  {
    // Print a <Datum> parent element
    iv_errlParser->PrintHeading("Datum");

    // Print timestamp.  PrintTimeStamp() prints a child <Property> element.
    // The PrintTimeStamp() method assumes the year is in big-endian (network)
    // order and calls ntohs() on the value.  When we parsed the BCD_time8_t
    // fields we converted the year to host endian, so we have to convert it
    // back to big-endian.
    BCD_time8_t bigEndianTimeStamp = timestamp;
    bigEndianTimeStamp.year = htons(bigEndianTimeStamp.year);
    iv_errlParser->PrintTimeStamp("time", bigEndianTimeStamp);

    // Print type, value, and unit.  Prints child <Property> elements.
    iv_errlParser->PrintString("type", type.c_str());
    iv_errlParser->PrintFloatNumber("value", "%f", value);
    iv_errlParser->PrintString("unit", unit.c_str());

    // Print </Datum> end tag
    iv_errlParser->PrintSectionEnd(true);
  }
  else
  {
    // In console output mode.  Print one table row.

    // Format timestamp.  Timestamp fields are BCD, so we print them as hex which
    // effectively 'converts' them to decimal digits.
    char formattedTimestamp[20];
    snprintf(formattedTimestamp, sizeof(formattedTimestamp),
             "%02X/%02X/%04X %02X:%02X:%02X",
             timestamp.month, timestamp.day,     timestamp.year,
             timestamp.hours, timestamp.minutes, timestamp.seconds);

    // Format data type and value
    char formattedTypeValue[80];
    snprintf(formattedTypeValue, sizeof(formattedTypeValue),
             "%-25s : %f %s", type.c_str(), value, unit.c_str());

    // Print one row with formatted timestamp, data type, and data value
    iv_errlParser->PrintString(formattedTimestamp, formattedTypeValue);
  }
}


void VrmTelemetryParser::printDataSetListStart(void)
{
  // If we are printing console mode output (not XML)
  if (!iv_outputIsXml)
  {
    // Print heading for table of telemetry data
    iv_errlParser->PrintString("Time"               , "Type                      : Value"        );
    iv_errlParser->PrintString("-------------------", "--------------------      : -------------");
  }
}


void VrmTelemetryParser::printDataSetListEnd(void)
{
  // Currently don't need to print anything at the end of a data set list
}


void VrmTelemetryParser::printRailStart(const std::string& rail)
{
  // Print visual divider.  Does nothing in XML mode.
  iv_errlParser->PrintDivider();

  // Print heading.  In XML mode prints a <Rail> parent element.
  iv_errlParser->PrintHeading("Rail");

  // Print rail name.  In XML mode prints a <Property> child element.
  iv_errlParser->PrintString("Name", rail.c_str());

  // Print blank line before telemetry data.  Does nothing in XML mode.
  iv_errlParser->PrintBlank();
}


void VrmTelemetryParser::printRailEnd(void)
{
  // In XML mode prints </Rail> end tag.  Does nothing in console mode.
  iv_errlParser->PrintSectionEnd(true);
}


void VrmTelemetryParser::printDrawerStart(uint8_t drawerNumber)
{
  // Print visual divider.  Does nothing in XML mode.
  iv_errlParser->PrintDivider();

  // Print heading.  In XML mode prints a <Drawer> parent element.
  iv_errlParser->PrintHeading("Drawer");

  // Print drawer number.  In XML mode prints a <Property> child element.
  iv_errlParser->PrintNumber("Number", "%u", drawerNumber);
}


void VrmTelemetryParser::printDrawerEnd(void)
{
  // In XML mode prints </Drawer> end tag.  Does nothing in console mode.
  iv_errlParser->PrintSectionEnd(true);
}


void VrmTelemetryParser::printVrmTelemetryStart(void)
{
  if (iv_outputIsXml)
  {
    // Print parent <VrmTelemetry> element
    iv_errlParser->PrintHeading("VrmTelemetry");
  }
  else
  {
    // Print heading
    iv_errlParser->PrintBlank();
    iv_errlParser->PrintHeading("VRM Telemetry");
  }
}


void VrmTelemetryParser::printVrmTelemetryEnd(void)
{
  // In XML mode prints </VrmTelemetry> end tag.  Does nothing in console mode.
  iv_errlParser->PrintSectionEnd(true);
}


bool VrmTelemetryParser::getDataTypeProperties(uint8_t type, std::string& name,
                                               std::string& unit) const
{
  bool rc = true;

  // Find the name and unit of the specified telemetry data type.  The telemetry
  // data types are defined in the enumeration telemetry_data_type_t.  The data
  // type names must be identical to the values of the <telemetry-data-type>
  // element in the VRM XML file schema.
  switch (type)
  {
    case TELEMETRY_TYPE_IOUT:
      name = "iout";
      unit = "A";                 // Amperes
      break;
    case TELEMETRY_TYPE_IOUT_PEAK:
      name = "iout-peak";
      unit = "A";                 // Amperes
      break;
    case TELEMETRY_TYPE_IOUT_VALLEY:
      name = "iout-valley";
      unit = "A";                 // Amperes
      break;
    case TELEMETRY_TYPE_TEMPERATURE:
      name = "temperature";
      unit = "C";                 // Celsius
      break;
    case TELEMETRY_TYPE_TEMPERATURE_PEAK:
      name = "temperature-peak";
      unit = "C";                 // Celsius
      break;
    case TELEMETRY_TYPE_VOUT:
      name = "vout";
      unit = "V";                 // Volts
      break;
    case TELEMETRY_TYPE_VOUT_PEAK:
      name = "vout-peak";
      unit = "V";                 // Volts
      break;
    case TELEMETRY_TYPE_VOUT_VALLEY:
      name = "vout-valley";
      unit = "V";                 // Volts
      break;
    default:
      // Unexpected data type
      rc = false;
      break;
  }

  return rc;
}


double VrmTelemetryParser::convertLinearToDouble(uint16_t value) const
{
  // Obtain 5-bit, two's complement exponent from most significant 5 bits
  uint8_t exponent = (uint8_t) (value >> 11); 

  // If 5-bit exponent value is negative, extend the sign bit to 8 bits
  if (exponent & 0x10u)                 // 0001 0000 = 0x10
  {
    exponent |= 0xE0u;                  // 1110 0000 = 0xE0
  }

  // Cast to a signed double exponent value
  double signedExponent = (double) ((int8_t) exponent);

  // Obtain 11-bit, two's complement mantissa from least significant 11 bits
  uint16_t mantissa = value & 0x07FFu;  // 0000 0111 1111 1111 = 0x07FF

  // If 11-bit mantissa value is negative, extend sign bit to 16 bits
  if (mantissa & 0x0400u)               // 0000 0100 0000 0000 = 0x0400
  {
    mantissa |= 0xF800u;                // 1111 1000 0000 0000 = 0xF800
  }

  // Cast to a signed double mantissa value
  double signedMantissa = (double) ((int16_t) mantissa);

  // Get double value using equation 'value = mantissa * 2^exponent'
  double doubleValue = signedMantissa * pow(2.0, signedExponent);

  return doubleValue;
}


bool VrmTelemetryParser::parseString(std::string& str)
{
  // Clear output string parameter
  str.clear();

  // Loop until we find a null terminator or hit end of buffer.  We might not
  // find a null terminator if the user data section was corrupted or truncated.
  bool foundTerminator = false;
  while (!foundTerminator && (bytesLeft() > 0))
  {
    // Read next character and advance buffer offset
    char nextChar = (char) iv_buffer[iv_offset++];

    if (nextChar == '\0')
    {
      // Found null terminator at end of string
      foundTerminator=true;
    }
    else if (!isprint(nextChar))
    {
      // Unprintable character; something is wrong.  Break out of loop.
      break;
    }
    else
    {
      // Valid character; append to string
      str += nextChar;
    }
  }

  // Parsing succeeded if we found null terminator at end of string
  return foundTerminator;
}


bool VrmTelemetryParser::parseTimestampList(void)
{
  // Parse timestamp count
  uint16_t count;
  if (!parseUint16(count))
  {
    return false;
  }

  // Parse list of timestamps
  for (int i = 0; i < count; ++i)
  {
    // Parse fields in one timestamp
    uint16_t year;
    uint8_t month, day, hours, minutes, seconds, hundredths;
    if (!parseUint16(year)   ||
        !parseUint8(month)   ||
        !parseUint8(day)     ||
        !parseUint8(hours)   ||
        !parseUint8(minutes) ||
        !parseUint8(seconds) ||
        !parseUint8(hundredths))
    {
      return false;
    }

    // Add timestamp to list
    BCD_time8_t timestamp = { year, month, day, hours, minutes, seconds, hundredths };
    iv_timestampList.push_back(timestamp);
  }

  // Parsing succeeded; return true
  return true;
}


bool VrmTelemetryParser::parseDatum(const BCD_time8_t& timestamp)
{
  // Parse telemetry data type
  uint8_t type;
  if (!parseUint8(type))
  {
    return false;
  }

  // Parse telemetry data value
  uint16_t value;
  if (!parseUint16(value))
  {
    return false;
  }

  // Get data type name and unit
  std::string typeName, unit;
  if (!getDataTypeProperties(type, typeName, unit))
  {
    return false;
  }

  // Convert data value from PMBus linear data format to a double
  double doubleValue = convertLinearToDouble(value);

  // Print formatted timestamp, data type, data value, and unit
  printDatum(timestamp, typeName, doubleValue, unit);

  // Parsing succeeded; return true
  return true;
}


bool VrmTelemetryParser::parseDataSet(void)
{
  // Parse timestamp ID
  uint16_t timestampId;
  if (!parseUint16(timestampId))
  {
    return false;
  }

  // Find timestamp associated with ID.  ID is just an index into the timestamp list.
  if (timestampId >= iv_timestampList.size())
  {
    return false;
  }
  BCD_time8_t timestamp = iv_timestampList[timestampId];

  // Parse telemetry datum count
  uint8_t count;
  if (!parseUint8(count))
  {
    return false;
  }

  // Parse all telemetry datums
  for (int i = 0; i < count; ++i)
  {
    if (!parseDatum(timestamp))
    {
      return false;
    }
  }

  // Parsing succeeded; return true
  return true;
}


bool VrmTelemetryParser::parseDataSetList(void)
{
  // Parse telemetry data set count
  uint16_t count;
  if (!parseUint16(count))
  {
    return false;
  }

  // Print start of telemetry data set list
  printDataSetListStart();

  // Parse all telemetry data sets
  for (int i = 0; i < count; ++i)
  {
    if (!parseDataSet())
    {
      return false;
    }
  }

  // Print end of telemetry data set list
  printDataSetListEnd();

  // Parsing succeeded; return true
  return true;
}


bool VrmTelemetryParser::parseVrmMasterList(void)
{
  // Parse VRM master count
  uint8_t count;
  if (!parseUint8(count))
  {
    return false;
  }

  // Parse all VRM masters
  std::string vrmMasterId;
  for (int i = 0; i < count; ++i)
  {
    // Parse the VRM master ID
    if (!parseString(vrmMasterId))
    {
      return false;
    }

    // Print start of VRM master data.  We use term 'rail' in output.
    printRailStart(vrmMasterId);

    // Parse list of telemetry data sets for this VRM master
    if (!parseDataSetList())
    {
      return false;
    }

    // Print end of VRM master data.  We use term 'rail' in output.
    printRailEnd();
  }

  // All parsing succeeded; return true
  return true;
}


bool VrmTelemetryParser::parseDrawer(void)
{
  // Parse drawer number
  uint8_t drawerNumber;
  if (!parseUint8(drawerNumber))
  {
    return false;
  }

  // Print start of drawer data
  printDrawerStart(drawerNumber);

  // Parse list of timestamps
  if (!parseTimestampList())
  {
    return false;
  }

  // Parse list of VRM masters and their telemetry data
  if (!parseVrmMasterList())
  {
    return false;
  }

  // Print end of drawer data
  printDrawerEnd();

  // All parsing succeeded; return true
  return true;
}
