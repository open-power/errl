
#ifndef ERRL_UDTARGET_H
#define ERRL_UDTARGET_H

namespace ERRORLOG
{
typedef struct TargetLabel_t
{
    static const uint32_t LABEL_TAG = 0xEEEEEEEE;
    uint32_t tag;
    char x[24]; //space to left of divider
    TargetLabel_t() : tag(0xEEEEEEEE)
    {
        memset(x,'\0',sizeof(x));
    };
} TargetLabel_t;
}
#ifndef LOGPARSER

#include <errl/errluserdetails.H>

namespace TARGETING // Forward reference
{ class Target; }

namespace ERRORLOG
{
class ErrlUserDetailsTarget : public ErrlUserDetails {
public:

    ErrlUserDetailsTarget(const TARGETING::Target * i_pTarget,
                          const char* i_label = NULL);
    virtual ~ErrlUserDetailsTarget();

private:

    // Disabled
    ErrlUserDetailsTarget(const ErrlUserDetailsTarget &);
    ErrlUserDetailsTarget & operator=(const ErrlUserDetailsTarget &);
};
}
#else // if LOGPARSER defined

#include "errluserdetails.H"
#include <string.h>

namespace ERRORLOG
{
  static uint8_t *errlud_parse_entity_path(uint8_t *i_ptr, char *o_ptr)
  {
      uint8_t *l_ptr = i_ptr;
      // from targeting/common/entitypath.[CH]
      // entityPath is PATH_TYPE:4, NumberOfElements:4, 
      //          [Element, Instance#]
      // PATH_TYPE
      const char *pathString;
      const uint8_t pathTypeLength = *l_ptr;
      l_ptr++;
      const uint8_t pathType = (pathTypeLength & 0xF0) >> 4;
      switch (pathType) {
          case 0x01: pathString = "Logical:"; break;
          case 0x02: pathString = "Physical:"; break;
          case 0x03: pathString = "Device:"; break;
          case 0x04: pathString = "Power:"; break;
          default:   pathString = "Unknown:"; break;
      }
      uint32_t dataSize = sprintf(o_ptr, "%s",pathString);
      const uint8_t pathSize = (pathTypeLength & 0x0F) * 2;
      uint8_t *lElementInstance = l_ptr;
      l_ptr += pathSize * sizeof(uint8_t);
      for (uint32_t j=0;j<pathSize;j += 2) {
          switch (lElementInstance[j]) {
              case 0x00: { pathString = "/NA"; break; }
              case 0x01: { pathString = "/Sys"; break; }
              case 0x02: { pathString = "/Node"; break; }
              case 0x03: { pathString = "/DIMM"; break; }
              case 0x04: { pathString = "/Membuf"; break; }
              case 0x05: { pathString = "/Proc"; break; }
              case 0x06: { pathString = "/EX"; break; }
              case 0x07: { pathString = "/Core"; break; }
              case 0x08: { pathString = "/L2"; break; }
              case 0x09: { pathString = "/L3"; break; }
              case 0x0A: { pathString = "/L4"; break; }
              case 0x0B: { pathString = "/MCS"; break; }
              case 0x0D: { pathString = "/MBA"; break; }
              case 0x0E: { pathString = "/XBUS"; break; }
              case 0x0F: { pathString = "/ABUS"; break; }
              case 0x10: { pathString = "/PCI"; break; }
              case 0x11: { pathString = "/DPSS"; break; }
              case 0x12: { pathString = "/APSS"; break; }
              case 0x13: { pathString = "/OCC"; break; }
              case 0x14: { pathString = "/PSI"; break; }
              case 0x15: { pathString = "/FSP"; break; }
              case 0x16: { pathString = "/PNOR"; break; }
              case 0x17: { pathString = "/OSC"; break; }
              case 0x18: { pathString = "/TODCLK"; break; }
              case 0x19: { pathString = "/CONTROL_NODE"; break; }
              case 0x1A: { pathString = "/OSCREFCLK"; break; }
              case 0x1B: { pathString = "/OSCPCICLK"; break; }
              case 0x1C: { pathString = "/REFCLKENDPT"; break; }
              case 0x1D: { pathString = "/PCICLKENDPT"; break; }
              case 0x1E: { pathString = "/NX"; break; }
              case 0x1F: { pathString = "/PORE"; break; }
              case 0x20: { pathString = "/PCIESWITCH"; break; }
              case 0x21: { pathString = "/CAPP"; break; }
              case 0x22: { pathString = "/FSI"; break; }
              case 0x23: { pathString = "/TPM"; break; }
              case 0x24: { pathString = "/TEST_FAIL"; break; }
              case 0x25: { pathString = "/LAST_IN_RANGE"; break; }
              default:   { pathString = "/UKNOWN"; break; }
          } // switch
          // copy next part in, overwritting previous terminator
          dataSize += sprintf(o_ptr + dataSize,
                              "%s%d", pathString,
                              lElementInstance[j+1]);
      } // for
      return l_ptr;
} // errlud_parse_entity_path 
class ErrlUserDetailsParserTarget : public ErrlUserDetailsParser {
public:

    ErrlUserDetailsParserTarget() {}

    virtual ~ErrlUserDetailsParserTarget() {}
/**
 *  @brief Parses Target user detail data from an error log
 *  @param  i_version Version of the data
 *  @param  i_parse   ErrlUsrParser object for outputting information
 *  @param  i_pBuffer Pointer to buffer containing detail data
 *  @param  i_buflen  Length of the buffer
 */
  virtual void parse(errlver_t i_version,
                        ErrlUsrParser & i_parser,
                        void * i_pBuffer,
                        const uint32_t i_buflen) const
  {
    const char *attrData;
    char l_label[24];
    sprintf(l_label,"Target");
    uint32_t *l_ptr32 = reinterpret_cast<uint32_t *>(i_pBuffer);
    // while there is still at least 1 word of data left
    for (; (l_ptr32 + 1) <= (uint32_t *)((uint8_t*)i_pBuffer + i_buflen); )
    {
      if (*l_ptr32 == 0xFFFFFFFF) { // special - master
        i_parser.PrintString("Target", "MASTER_PROCESSOR_CHIP_TARGET_SENTINEL");
        l_ptr32++; // past the marker
      } else if (*l_ptr32 == TargetLabel_t::LABEL_TAG) {
        TargetLabel_t* tmp_label = reinterpret_cast<TargetLabel_t*>(l_ptr32);
        memcpy( l_label, tmp_label->x, sizeof(l_label)-1 );
        l_ptr32 += (sizeof(TargetLabel_t)/sizeof(uint32_t));
      } else { 
        // first 4 are always the same
        if ((l_ptr32 + 4) <= (uint32_t *)((uint8_t*)i_pBuffer + i_buflen)) {
            i_parser.PrintNumber( l_label, "HUID = 0x%08X", ntohl(*l_ptr32) );
            l_ptr32++;
            switch (ntohl(*l_ptr32)) { // CLASS
                case 0x00: { attrData = "CLASS_NA"; break; }
                case 0x01: { attrData = "CLASS_CARD"; break; }
                case 0x02: { attrData = "CLASS_ENC"; break; }
                case 0x03: { attrData = "CLASS_CHIP"; break; }
                case 0x04: { attrData = "CLASS_UNIT"; break; }
                case 0x05: { attrData = "CLASS_DEV"; break; }
                case 0x06: { attrData = "CLASS_SYS"; break; }
                case 0x07: { attrData = "CLASS_LOGICAL_CARD"; break; }
                case 0x08: { attrData = "CLASS_MAX"; break; }
                default:   { attrData = "UNKNOWN_CLASS"; break; }
            } // switch
            i_parser.PrintString("  ATTR_CLASS", attrData);
            l_ptr32++;
            switch (ntohl(*l_ptr32)) { // TYPE
                case 0x00: { attrData = "TYPE_NA"; break; }
                case 0x01: { attrData = "TYPE_SYS"; break; }
                case 0x02: { attrData = "TYPE_NODE"; break; }
                case 0x03: { attrData = "TYPE_DIMM"; break; }
                case 0x04: { attrData = "TYPE_MEMBUF"; break; }
                case 0x05: { attrData = "TYPE_PROC"; break; }
                case 0x06: { attrData = "TYPE_EX"; break; }
                case 0x07: { attrData = "TYPE_CORE"; break; }
                case 0x08: { attrData = "TYPE_L2"; break; }
                case 0x09: { attrData = "TYPE_L3"; break; }
                case 0x0A: { attrData = "TYPE_L4"; break; }
                case 0x0B: { attrData = "TYPE_MCS"; break; }
                case 0x0D: { attrData = "TYPE_MBA"; break; }
                case 0x0E: { attrData = "TYPE_XBUS"; break; }
                case 0x0F: { attrData = "TYPE_ABUS"; break; }
                case 0x10: { attrData = "TYPE_PCI"; break; }
                case 0x11: { attrData = "TYPE_DPSS"; break; }
                case 0x12: { attrData = "TYPE_APSS"; break; }
                case 0x13: { attrData = "TYPE_OCC"; break; }
                case 0x14: { attrData = "TYPE_PSI"; break; }
                case 0x15: { attrData = "TYPE_FSP"; break; }
                case 0x16: { attrData = "TYPE_PNOR"; break; }
                case 0x17: { attrData = "TYPE_OSC"; break; }
                case 0x18: { attrData = "TYPE_TODCLK"; break; }
                case 0x19: { attrData = "TYPE_CONTROL_NODE"; break; }
                case 0x1A: { attrData = "TYPE_OSCREFCLK"; break; }
                case 0x1B: { attrData = "TYPE_OSCPCICLK"; break; }
                case 0x1C: { attrData = "TYPE_REFCLKENDPT"; break; }
                case 0x1D: { attrData = "TYPE_PCICLKENDPT"; break; }
                case 0x1E: { attrData = "TYPE_NX"; break; }
                case 0x1F: { attrData = "TYPE_PORE"; break; }
                case 0x20: { attrData = "TYPE_PCIESWITCH"; break; }
                case 0x21: { attrData = "TYPE_CAPP"; break; }
                case 0x22: { attrData = "TYPE_FSI"; break; }
                case 0x23: { attrData = "TYPE_TPM"; break; }
                case 0x24: { attrData = "TYPE_TEST_FAIL"; break; }
                case 0x25: { attrData = "TYPE_LAST_IN_RANGE"; break; }
                default:   { attrData = "UNKNOWN_TYPE"; break; }
            } // switch
            i_parser.PrintString("  ATTR_TYPE", attrData);
            l_ptr32++;
            switch (ntohl(*l_ptr32)) { // MODEL
                case 0x00: { attrData = "MODEL_NA"; break; }
                case 0x10: { attrData = "MODEL_RESERVED"; break; }
                case 0x11: { attrData = "MODEL_VENICE"; break; }
                case 0x12: { attrData = "MODEL_MURANO"; break; }
                case 0x13: { attrData = "MODEL_NAPLES"; break; }
                case 0x30: { attrData = "MODEL_CENTAUR"; break; }
                case 0x50: { attrData = "MODEL_JEDEC"; break; }
                case 0x51: { attrData = "MODEL_CDIMM"; break; }
                case 0x70: { attrData = "MODEL_POWER8"; break; }
                case 0x71: { attrData = "MODEL_CECTPM"; break; }
                default:   { attrData = "UNKNOWN_MODEL"; break; }
            } // switch
            i_parser.PrintString("  ATTR_MODEL", attrData);
            l_ptr32++;
            // 2 Entity Paths next
            for (uint32_t k = 0;k < 2; k++)
            {
                uint32_t l_pathType = ntohl(*l_ptr32);
                if ((l_pathType == 0xf7abb7c) || // ATTR_PHYS_PATH
                    (l_pathType == 0xb5afcd7))   // ATTR_AFFINITY_PATH
                {
                    l_ptr32++;
                    uint8_t *l_ptr = reinterpret_cast<uint8_t *>(l_ptr32);
                    char outString[128];
                    l_ptr = errlud_parse_entity_path(l_ptr,outString);
                    if (l_pathType == 0xf7abb7c)
                    {
                      i_parser.PrintString("  ATTR_PHYS_PATH", outString);
                    }
                    if (l_pathType == 0xb5afcd7)
                    {
                      i_parser.PrintString("  ATTR_AFFINITY_PATH", outString);
                    } // else don't print anything
                    l_ptr32 = reinterpret_cast<uint32_t *>(l_ptr);
                } else {
                    l_ptr32++;
                }
            } // for
        } // if
      }
    } // for
  } // parse()

private:

// Disabled
ErrlUserDetailsParserTarget(const ErrlUserDetailsParserTarget &);
ErrlUserDetailsParserTarget & operator=(const ErrlUserDetailsParserTarget &);
};
} // namespace
#endif
#endif
