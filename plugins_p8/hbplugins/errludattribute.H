
#ifndef ERRL_UDATTRIBUTE_H
#define ERRL_UDATTRIBUTE_H

#ifndef LOGPARSER

#include <errl/errluserdetails.H>

namespace TARGETING // Forward reference
{ class Target; }

namespace ERRORLOG
{
class ErrlUserDetailsAttribute : public ErrlUserDetails {
public:

    ErrlUserDetailsAttribute(const TARGETING::Target * i_pTarget, uint32_t i_attr);
    ErrlUserDetailsAttribute(const TARGETING::Target * i_pTarget);
    void addData(uint32_t i_attr);
    virtual ~ErrlUserDetailsAttribute();

private:

    // Disabled
    ErrlUserDetailsAttribute(const ErrlUserDetailsAttribute &);
    ErrlUserDetailsAttribute & operator=(const ErrlUserDetailsAttribute &);

    // internal function
    void dumpAll();

    const TARGETING::Target * iv_pTarget;
    uint32_t iv_dataSize;
};
}
#else // if LOGPARSER defined

#include "errluserdetails.H"

namespace ERRORLOG
{
class ErrlUserDetailsParserAttribute : public ErrlUserDetailsParser {
public:

    ErrlUserDetailsParserAttribute() {}

    virtual ~ErrlUserDetailsParserAttribute() {}
  /**
   *  @brief Parses Attribute user detail data from an error log
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
    const char *pLabel = NULL;
    uint8_t *l_ptr = static_cast<uint8_t *>(i_pBuffer);
    std::vector<char> l_traceEntry(64);
    i_parser.PrintString("Target Attributes", NULL);

    for (; (l_ptr + sizeof(uint32_t)) <= ((uint8_t*)i_pBuffer + i_buflen); )
    {
        // first 4 bytes is the attr enum
        uint32_t attrEnum = ntohl(*(uint32_t *)l_ptr);
        l_ptr += sizeof(attrEnum);

        switch (attrEnum) {
          case 0xc18e8f1: {
              //not readable
              break;
          }
          case 0x9484951: {
              //not readable
              break;
          }
          case 0x7a03bac: {
              //not readable
              break;
          }
          case 0xa9d881f: {
              //not readable
              break;
          }
          case 0xc7bc372: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT8_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe93419a: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT8_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x782c053: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT32_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x002156b: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT32_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xeee9926: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT64_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x18a17a2: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT64_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xae204e8: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT8_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[32]:");
              l_traceEntry.resize(10+offset + 32 * 5);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 32 * sizeof(uint8_t);
              break;
          }
          case 0xdaba3f6: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT8_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][ 3][ 4]:");
              l_traceEntry.resize(10+offset + 24 * 5);
              for (uint32_t i = 0;i<24;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 24 * sizeof(uint8_t);
              break;
          }
          case 0xe572010: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT32_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 11);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(uint32_t);
              break;
          }
          case 0xf014872: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT32_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][3]:");
              l_traceEntry.resize(10+offset + 6 * 11);
              for (uint32_t i = 0;i<6;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 6 * sizeof(uint32_t);
              break;
          }
          case 0x4403d2c: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT64_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x24d2ff8: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT64_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x6b5b079: {
              //simpleType:uint
              pLabel = "DUMMY_RW";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[1][3][5]:");
              l_traceEntry.resize(10+offset + 15 * 5);
              for (uint32_t i = 0;i<15;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 15 * sizeof(uint8_t);
              break;
          }
          case 0x18849c5: {
              //not readable
              break;
          }
          case 0x7f95302: {
              //not readable
              break;
          }
          case 0x9184d62: {
              //not readable
              break;
          }
          case 0xf7abb7c: {
              //not readable
              break;
          }
          case 0xb5afcd7: {
              //not readable
              break;
          }
          case 0xd43ef5c: {
              //not readable
              break;
          }
          case 0xd84c572: {
              //not readable
              break;
          }
          case 0xbc8d08b: {
              //complexType - skipping
              break;
          }
          case 0x25b0084: {
              //not readable
              break;
          }
          case 0x9008e43: {
              //not readable
              break;
          }
          case 0x116670c: {
              //not readable
              break;
          }
          case 0xf4637bc: {
              //not readable
              break;
          }
          case 0x3d7757a: {
              //not readable
              break;
          }
          case 0x7cd6063: {
              //not readable
              break;
          }
          case 0x21c70fd: {
              //not readable
              break;
          }
          case 0x3b6e39f: {
              //not readable
              break;
          }
          case 0x6134e50: {
              //not readable
              break;
          }
          case 0x4367508: {
              //simpleType:uint
              pLabel = "IS_SIMULATION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x16fbd51: {
              //complexType - skipping
              break;
          }
          case 0x1c5c585: {
              //simpleType:uint
              pLabel = "HWAS_STATE_CHANGED_FLAG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x4a76d45: {
              //not readable
              break;
          }
          case 0xdbe5186: {
              //not readable
              break;
          }
          case 0x59253de: {
              //not readable
              break;
          }
          case 0x54d128f: {
              //simpleType:uint
              pLabel = "ISTEP_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcdbfb30: {
              //not readable
              break;
          }
          case 0x1fbf757: {
              //not readable
              break;
          }
          case 0x9e4aac2: {
              //not readable
              break;
          }
          case 0xcba1600: {
              //not readable
              break;
          }
          case 0xca6a09a: {
              //not readable
              break;
          }
          case 0x3fd6b69: {
              //simpleType:uint
              pLabel = "EC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6d3696b: {
              //simpleType:uint
              pLabel = "CHIP_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5ef6998: {
              //not readable
              break;
          }
          case 0x103a329: {
              //simpleType:uint
              pLabel = "L2_R_T0_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf7048b9: {
              //simpleType:uint
              pLabel = "L2_R_T1_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x620f312: {
              //simpleType:uint
              pLabel = "L2_R_T2_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1ccc263: {
              //simpleType:uint
              pLabel = "L2_FORCE_R_T2_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7bae703: {
              //simpleType:uint
              pLabel = "L2_W_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x459bd34: {
              //simpleType:uint
              pLabel = "L3_R_T0_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x3354357: {
              //simpleType:uint
              pLabel = "L3_R_T1_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6803255: {
              //simpleType:uint
              pLabel = "L3_R_T2_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0044ec7: {
              //simpleType:uint
              pLabel = "L3_FORCE_R_T2_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf8bf18e: {
              //simpleType:uint
              pLabel = "L3_W_EPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9615865: {
              //not readable
              break;
          }
          case 0x90b4ba7: {
              //not readable
              break;
          }
          case 0x5207f78: {
              //not readable
              break;
          }
          case 0x80b9cd7: {
              //not readable
              break;
          }
          case 0xcd7817c: {
              //not readable
              break;
          }
          case 0x23c87d8: {
              //not readable
              break;
          }
          case 0xc1c2678: {
              //not readable
              break;
          }
          case 0x999db6b: {
              //not readable
              break;
          }
          case 0x06e992f: {
              //simpleType:uint
              pLabel = "ALL_MCS_IN_INTERLEAVING_GROUP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4ede78d: {
              //not readable
              break;
          }
          case 0x34eeb58: {
              //not readable
              break;
          }
          case 0x5d1081e: {
              //not readable
              break;
          }
          case 0xaac24d5: {
              //not readable
              break;
          }
          case 0x1b7a6ae: {
              //not readable
              break;
          }
          case 0x29e287c: {
              //not readable
              break;
          }
          case 0x6f08f4b: {
              //simpleType:uint
              pLabel = "MIN_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb60b7d0: {
              //simpleType:uint
              pLabel = "FREQ_PB";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x4426c6b: {
              //not readable
              break;
          }
          case 0x50a3f36: {
              //simpleType:uint
              pLabel = "FREQ_X";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf9fde6a: {
              //not readable
              break;
          }
          case 0xa82e8ff: {
              //not readable
              break;
          }
          case 0x19d1b7e: {
              //complexType - skipping
              break;
          }
          case 0x1e1c64d: {
              //complexType - skipping
              break;
          }
          case 0x6fd2aa7: {
              break;
          }
          case 0xd2401e6: {
              break;
          }
          case 0x428e6a8: {
              break;
          }
          case 0xc5d939e: {
              break;
          }
          case 0x03a8b72: {
              //not readable
              break;
          }
          case 0x6f76a92: {
              //not readable
              break;
          }
          case 0x020a135: {
              //simpleType:uint
              pLabel = "PAYLOAD_BASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x64b6d86: {
              //simpleType:uint
              pLabel = "PAYLOAD_ENTRY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xa4d2083: {
              //simpleType:enum
              pLabel = "PAYLOAD_KIND";
              switch (*l_ptr) {
                  case 0x00000000: {
                      sprintf(&(l_traceEntry[0]), "PAYLOAD_KIND_UNKNOWN");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  case 0x00000001: {
                      sprintf(&(l_traceEntry[0]), "PAYLOAD_KIND_PHYP");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  case 0x00000002: {
                      sprintf(&(l_traceEntry[0]), "PAYLOAD_KIND_SAPPHIRE");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  case 0x00000003: {
                      sprintf(&(l_traceEntry[0]), "PAYLOAD_KIND_NONE");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  default: break;
              }
              break;
          }
          case 0x11a66f1: {
              //simpleType:uint
              pLabel = "HB_HRMOR_NODAL_BASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x2d207b6: {
              //simpleType:uint
              pLabel = "FABRIC_TO_PHYSICAL_NODE_MAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 5);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 8 * sizeof(uint8_t);
              break;
          }
          case 0x3849826: {
              //simpleType:uint
              pLabel = "PROC_MEM_BASES";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 19);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(uint64_t);
              break;
          }
          case 0x61d7f4f: {
              //simpleType:uint
              pLabel = "PROC_MEM_SIZES";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 19);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(uint64_t);
              break;
          }
          case 0xb9ee432: {
              //simpleType:uint
              pLabel = "PROC_MIRROR_BASES";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x18128bb: {
              //simpleType:uint
              pLabel = "PROC_MIRROR_SIZES";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x3bc248d: {
              //simpleType:uint
              pLabel = "PROC_L3_BAR1_REG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x727aab0: {
              //simpleType:uint
              pLabel = "PROC_L3_BAR2_REG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xfd9e124: {
              //simpleType:uint
              pLabel = "PROC_L3_BAR_GROUP_MASK_REG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x50c85dd: {
              //simpleType:uint
              pLabel = "FREQ_CORE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa7b5133: {
              //not readable
              break;
          }
          case 0x7adcf90: {
              //not readable
              break;
          }
          case 0x7803464: {
              //not readable
              break;
          }
          case 0x1983e2d: {
              //not readable
              break;
          }
          case 0x06d3ba7: {
              //not readable
              break;
          }
          case 0x6a258b6: {
              //not readable
              break;
          }
          case 0x8c5fb5a: {
              //simpleType:uint
              pLabel = "PAYLOAD_IN_MIRROR_MEM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcb1c3e8: {
              //not readable
              break;
          }
          case 0xff18a73: {
              //not readable
              break;
          }
          case 0x77da343: {
              //not readable
              break;
          }
          case 0xfcfe1a6: {
              //not readable
              break;
          }
          case 0xd8dde00: {
              //not readable
              break;
          }
          case 0x06d665c: {
              //not readable
              break;
          }
          case 0x6508321: {
              //not readable
              break;
          }
          case 0xac49a29: {
              //not readable
              break;
          }
          case 0xb6f0cd7: {
              //not readable
              break;
          }
          case 0x2d4e887: {
              //not readable
              break;
          }
          case 0xb3aa338: {
              //not readable
              break;
          }
          case 0x45a548d: {
              //simpleType:uint
              pLabel = "MEM_BASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x686bbbc: {
              //simpleType:uint
              pLabel = "MIRROR_BASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xafef4d7: {
              //not readable
              break;
          }
          case 0xe2bf285: {
              //not readable
              break;
          }
          case 0xd83c2a5: {
              //not readable
              break;
          }
          case 0x6c120b2: {
              //not readable
              break;
          }
          case 0x29081fa: {
              //simpleType:uint
              pLabel = "PROC_EPS_GB_PERCENTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9087eaf: {
              //simpleType:uint
              pLabel = "PROC_EPS_GB_DIRECTION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd952274: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_ASYNC_SAFE_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3c189d0: {
              //not readable
              break;
          }
          case 0x4e64981: {
              //simpleType:uint
              pLabel = "NOMINAL_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xca2de0a: {
              //simpleType:uint
              pLabel = "ULTRA_TURBO_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb7d5f9c: {
              //simpleType:uint
              pLabel = "MNFG_FLAGS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xde419d0: {
              //simpleType:uint
              pLabel = "PROC_DPLL_DIVIDER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x8f44127: {
              //simpleType:uint
              pLabel = "PM_POWER_PROXY_TRACE_TIMER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1a3cef3: {
              //simpleType:uint
              pLabel = "PM_PPT_TIMER_MATCH_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa273548: {
              //simpleType:uint
              pLabel = "PM_PPT_TIMER_TICK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x72f87ff: {
              //simpleType:uint
              pLabel = "PM_AISS_TIMEOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xed6e3be: {
              //simpleType:uint
              pLabel = "PM_PSTATE_STEPSIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x178be72: {
              //simpleType:uint
              pLabel = "PM_EXTERNAL_VRM_STEPDELAY_RANGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc7f6eb0: {
              //simpleType:uint
              pLabel = "PM_EXTERNAL_VRM_STEPDELAY_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbc9ce34: {
              //simpleType:uint
              pLabel = "PM_PMC_HANGPULSE_DIVIDER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x95f6329: {
              //simpleType:uint
              pLabel = "PM_PVSAFE_PSTATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x045cd3f: {
              //simpleType:uint
              pLabel = "PM_SPIVID_FRAME_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xca938f8: {
              //simpleType:uint
              pLabel = "PM_SPIVID_IN_DELAY_FRAME1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x811dcff: {
              //simpleType:uint
              pLabel = "PM_SPIVID_IN_DELAY_FRAME2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3ac352b: {
              //simpleType:uint
              pLabel = "PM_SPIVID_CLOCK_POLARITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x533115d: {
              //simpleType:uint
              pLabel = "PM_SPIVID_CLOCK_PHASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6ca3041: {
              //simpleType:uint
              pLabel = "PM_SPIVID_CLOCK_DIVIDER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x84bd123: {
              //simpleType:uint
              pLabel = "PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x483efc7: {
              //simpleType:uint
              pLabel = "PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x84737ed: {
              //simpleType:uint
              pLabel = "PM_SPIVID_INTER_RETRY_DELAY_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xdc81421: {
              //simpleType:uint
              pLabel = "PM_SPIVID_INTER_RETRY_DELAY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x925f149: {
              //simpleType:uint
              pLabel = "PM_SPIVID_CRC_GEN_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x30ec7ae: {
              //simpleType:uint
              pLabel = "PM_SPIVID_CRC_CHECK_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x66f37af: {
              //simpleType:uint
              pLabel = "PM_SPIVID_MAJORITY_VOTE_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe4424fb: {
              //simpleType:uint
              pLabel = "PM_SPIVID_MAX_RETRIES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6d1d3d5: {
              //simpleType:uint
              pLabel = "PM_SPIVID_CRC_POLYNOMIAL_ENABLES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb4d8e68: {
              //simpleType:uint
              pLabel = "PM_OCC_HEARTBEAT_TIME";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5c534f7: {
              //simpleType:uint
              pLabel = "PM_SLEEP_WINKLE_REQUEST_TIMEOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6dbe008: {
              //not readable
              break;
          }
          case 0x63850ad: {
              //not readable
              break;
          }
          case 0x82aa9cb: {
              //not readable
              break;
          }
          case 0xdfcccc7: {
              //not readable
              break;
          }
          case 0xb342345: {
              //not readable
              break;
          }
          case 0x0baa8a6: {
              //not readable
              break;
          }
          case 0x05b26e4: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERUP_CORE_DELAY0_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0c4456e: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERUP_CORE_DELAY1_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x95b6c49: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0f78b78: {
              //not readable
              break;
          }
          case 0xd6128fa: {
              //not readable
              break;
          }
          case 0xa546547: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERDOWN_CORE_DELAY0_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1a476f2: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERDOWN_CORE_DELAY1_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0eb02e0: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x8359ca3: {
              //not readable
              break;
          }
          case 0x1264a02: {
              //not readable
              break;
          }
          case 0x4fc4d36: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERUP_ECO_DELAY0_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x444360f: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERUP_ECO_DELAY1_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xfc0bb85: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x862db8e: {
              //not readable
              break;
          }
          case 0xaf24e2f: {
              //not readable
              break;
          }
          case 0xd4a1e98: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERDOWN_ECO_DELAY0_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x89263b9: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERDOWN_ECO_DELAY1_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc69a697: {
              //simpleType:uint
              pLabel = "PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0cfe95a: {
              //simpleType:uint
              pLabel = "PM_PSTATE0_FREQUENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x44436e4: {
              //simpleType:uint
              pLabel = "PM_IVRMS_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x96b8428: {
              //simpleType:uint
              pLabel = "PM_SAFE_PSTATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1cd58bf: {
              //simpleType:uint
              pLabel = "PM_RESONANT_CLOCK_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9e467f3: {
              //simpleType:uint
              pLabel = "PM_RESONANT_CLOCK_FULL_CSB_PSTATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf19d417: {
              //simpleType:uint
              pLabel = "PM_RESONANT_CLOCK_LFRLOW_PSTATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x922f13c: {
              //simpleType:uint
              pLabel = "PM_RESONANT_CLOCK_LFRUPPER_PSTATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdda59cd: {
              //simpleType:uint
              pLabel = "PM_RESONANT_CLOCK_HFRLOW_PSTATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5b032ee: {
              //simpleType:uint
              pLabel = "PM_RESONANT_CLOCK_HFRHIGH_PSTATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb69562d: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_FRAME_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x57a52ce: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_OUT_COUNT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xae84e31: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_IN_DELAY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3a398b7: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_IN_COUNT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0241bf2: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_CLOCK_POLARITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x82b807e: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_CLOCK_PHASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x16824ac: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_CLOCK_DIVIDER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3e336e0: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_INTER_FRAME_DELAY_SETTING";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0c042d9: {
              //simpleType:uint
              pLabel = "PM_SPIPSS_INTER_FRAME_DELAY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd0cd905: {
              //simpleType:uint
              pLabel = "PM_PBAX_RCV_RESERV_TIMEOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xce07d4c: {
              //simpleType:uint
              pLabel = "PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8ba9bf1: {
              //simpleType:uint
              pLabel = "PM_PBAX_SND_RETRY_THRESHOLD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xca3caf0: {
              //simpleType:uint
              pLabel = "PM_PBAX_SND_RESERV_TIMEOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x00cdcc8: {
              //simpleType:uint
              pLabel = "PM_SPWUP_FSP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x37373c5: {
              //simpleType:uint
              pLabel = "PM_SPWUP_OCC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x7890710: {
              //simpleType:uint
              pLabel = "PM_SPWUP_PHYP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x690c74f: {
              //simpleType:uint
              pLabel = "PM_SLW_CONTROL_VECTOR_OFFSET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6285af7: {
              //not readable
              break;
          }
          case 0x5ca8477: {
              //not readable
              break;
          }
          case 0xb2af6a0: {
              //not readable
              break;
          }
          case 0x350d093: {
              //not readable
              break;
          }
          case 0x74566a6: {
              //not readable
              break;
          }
          case 0x0fcef29: {
              //not readable
              break;
          }
          case 0xe141cc3: {
              //not readable
              break;
          }
          case 0x6636810: {
              //not readable
              break;
          }
          case 0xe7bf9a7: {
              //not readable
              break;
          }
          case 0xb3b543a: {
              //not readable
              break;
          }
          case 0x5cc04ad: {
              //not readable
              break;
          }
          case 0x191dc94: {
              //not readable
              break;
          }
          case 0x020df55: {
              //not readable
              break;
          }
          case 0x6b9bbf8: {
              //not readable
              break;
          }
          case 0xddaf529: {
              //not readable
              break;
          }
          case 0x9b7245b: {
              //simpleType:uint
              pLabel = "FREQ_CORE_MAX";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xff8bd22: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_NOM_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x812e723: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_NEST_NOM_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd03b86d: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_NEST_NOM_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1848a5c: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_CS_NOM_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa315afa: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_CS_NOM_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x233d892: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_PS_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xee24bf3: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_NEST_PS_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x7b425d9: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_NEST_PS_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x51fa163: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_CS_PS_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xccb59d6: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_CS_PS_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x79811d2: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_TURBO_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xfd264b4: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_NEST_TURBO_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5fe5632: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_NEST_TURBO_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x937d29d: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_CS_TURBO_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x8f254e2: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_CS_TURBO_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6bce019: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_FVMIN_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1b8b1bd: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_NEST_FVMIN_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1bdb6b7: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_NEST_FVMIN_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x04d25dc: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_CS_FVMIN_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9707664: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_CS_FVMIN_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0a12f85: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_LAB_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xee7cd69: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_NEST_LAB_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x475571b: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_NEST_LAB_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x97fbcc4: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_V_CS_LAB_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x879015b: {
              //simpleType:uint
              pLabel = "OVERRIDE_MVPD_I_CS_LAB_CURRENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xeb604df: {
              //simpleType:uint
              pLabel = "PROC_PCIE_IOP_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x85f1c7e: {
              //simpleType:uint
              pLabel = "PROC_PCIE_IOP_SWAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[3]:");
              l_traceEntry.resize(10+offset + 3 * 5);
              for (uint32_t i = 0;i<3;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 3 * sizeof(uint8_t);
              break;
          }
          case 0x763e8c5: {
              //simpleType:uint
              pLabel = "PROC_PCIE_PHB_ACTIVE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xfe7481f: {
              //not readable
              break;
          }
          case 0x19fa125: {
              //not readable
              break;
          }
          case 0x06e6117: {
              //not readable
              break;
          }
          case 0x01a149e: {
              //not readable
              break;
          }
          case 0x3f31bf0: {
              //not readable
              break;
          }
          case 0xfbd81e9: {
              //not readable
              break;
          }
          case 0x4c0104b: {
              //not readable
              break;
          }
          case 0xc1103ae: {
              //not readable
              break;
          }
          case 0xbcb8be1: {
              //not readable
              break;
          }
          case 0x0b97979: {
              //not readable
              break;
          }
          case 0xbfdd81f: {
              //not readable
              break;
          }
          case 0x4ab4ba8: {
              //not readable
              break;
          }
          case 0xcaeb5a9: {
              //not readable
              break;
          }
          case 0xc710685: {
              //not readable
              break;
          }
          case 0x2a9cfd3: {
              //not readable
              break;
          }
          case 0x780a573: {
              //not readable
              break;
          }
          case 0xa5ccc9a: {
              //not readable
              break;
          }
          case 0x1478506: {
              //not readable
              break;
          }
          case 0xb77318e: {
              //simpleType:uint
              pLabel = "NEST_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x208eb9c: {
              //simpleType:uint
              pLabel = "CHIP_REGIONS_TO_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[32]:");
              l_traceEntry.resize(10+offset + 32 * 19);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 32 * sizeof(uint64_t);
              break;
          }
          case 0x61f8882: {
              //simpleType:uint
              pLabel = "BOOT_FREQ_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x394b852: {
              //simpleType:uint
              pLabel = "EX_GARD_BITS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa8b10e1: {
              //simpleType:uint
              pLabel = "PIB_I2C_REFCLOCK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf3f51b8: {
              //not readable
              break;
          }
          case 0x19a4504: {
              //simpleType:uint
              pLabel = "PIB_I2C_NEST_PLL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xc6b877a: {
              //not readable
              break;
          }
          case 0x5ba77b7: {
              //simpleType:uint
              pLabel = "SBE_IMAGE_OFFSET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x2489e36: {
              //not readable
              break;
          }
          case 0x1bbcf6f: {
              //not readable
              break;
          }
          case 0x5c5498f: {
              //simpleType:uint
              pLabel = "BOOT_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xcac64a9: {
              //not readable
              break;
          }
          case 0x1b8a236: {
              //not readable
              break;
          }
          case 0x5d73c2a: {
              //not readable
              break;
          }
          case 0x2f34a29: {
              //not readable
              break;
          }
          case 0xbec0e03: {
              //simpleType:uint
              pLabel = "FAVOR_PERF_OVER_SECURITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbcad046: {
              //simpleType:uint
              pLabel = "MSS_VOLT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6894ce3: {
              //simpleType:uint
              pLabel = "VPP_BASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe88d183: {
              //simpleType:uint
              pLabel = "MSS_FREQ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xcc9fdeb: {
              //simpleType:uint
              pLabel = "MSS_DIMM_MFG_ID_CODE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x092ecab: {
              //simpleType:uint
              pLabel = "EFF_DIMM_RANKS_CONFIGED";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x88ba0c5: {
              //simpleType:uint
              pLabel = "EFF_NUM_RANKS_PER_DIMM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe35b4c7: {
              //simpleType:uint
              pLabel = "EFF_DIMM_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6743c00: {
              //simpleType:uint
              pLabel = "EFF_CUSTOM_DIMM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbcc0968: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WIDTH";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0d33633: {
              //simpleType:uint
              pLabel = "EFF_DRAM_GEN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1cace70: {
              //simpleType:uint
              pLabel = "EFF_PRIMARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7d7de33: {
              //simpleType:uint
              pLabel = "EFF_PRIMARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x170d276: {
              //simpleType:uint
              pLabel = "EFF_PRIMARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6a98e62: {
              //simpleType:uint
              pLabel = "EFF_PRIMARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xc65bac5: {
              //simpleType:uint
              pLabel = "EFF_SECONDARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf801275: {
              //simpleType:uint
              pLabel = "EFF_SECONDARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa55be17: {
              //simpleType:uint
              pLabel = "EFF_SECONDARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa65a3c4: {
              //simpleType:uint
              pLabel = "EFF_SECONDARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xbb83239: {
              //simpleType:uint
              pLabel = "EFF_TERTIARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x0236762: {
              //simpleType:uint
              pLabel = "EFF_TERTIARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf21b04e: {
              //simpleType:uint
              pLabel = "EFF_TERTIARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6dabdcc: {
              //simpleType:uint
              pLabel = "EFF_TERTIARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x50e0279: {
              //simpleType:uint
              pLabel = "EFF_QUATERNARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8418d88: {
              //simpleType:uint
              pLabel = "EFF_QUATERNARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xdaa39e7: {
              //simpleType:uint
              pLabel = "EFF_QUATERNARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xd86835e: {
              //simpleType:uint
              pLabel = "EFF_QUATERNARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf82b926: {
              //simpleType:uint
              pLabel = "EFF_ODT_RD";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x050e71b: {
              //simpleType:uint
              pLabel = "EFF_ODT_WR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x4ac394b: {
              //simpleType:uint
              pLabel = "EFF_DRAM_RON";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe2d72d1: {
              //simpleType:uint
              pLabel = "EFF_DRAM_RTT_NOM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0xdfdac0f: {
              //simpleType:uint
              pLabel = "EFF_DRAM_RTT_WR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x6945cc9: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WR_VREF";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x173aa78: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WRDDR4_VREF";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xef3a38f: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa2d0de9: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_ADDR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x3bc44b0: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_CNTL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6daa86d: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_CLK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2c59739: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_SPCKE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe9b56c2: {
              //simpleType:uint
              pLabel = "EFF_CEN_RCV_IMP_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb350f87: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb7e69dd: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_ADDR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x60806ad: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_CLK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x14b8641: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_SPCKE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe5d694b: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_CNTL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x66c0538: {
              //simpleType:uint
              pLabel = "EFF_CEN_RD_VREF";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x601a4d0: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x15e70be: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_CLK_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9f1e9d8: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_SPCKE_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb754336: {
              //simpleType:uint
              pLabel = "EFF_CEN_DRV_IMP_CNTL_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xcee20ef: {
              //simpleType:uint
              pLabel = "EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x0b98bfa: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6c13eeb: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_CLK_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x0e59f80: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_SPCKE_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x5bca776: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_ADDR_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9083929: {
              //simpleType:uint
              pLabel = "EFF_CEN_SLEW_RATE_CNTL_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xec9685a: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WR_VREF_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x467b4af: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WRDDR4_VREF_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x6b7121d: {
              //simpleType:uint
              pLabel = "EFF_CEN_RD_VREF_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xc1e40a4: {
              //simpleType:uint
              pLabel = "EFF_DIMM_SIZE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x192d6de: {
              //simpleType:uint
              pLabel = "EFF_DRAM_BANKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x39edd97: {
              //simpleType:uint
              pLabel = "EFF_DRAM_ROWS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xed0bb9d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_COLS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x07a9643: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DENSITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc9b93c9: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRCD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1f639a0: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRRD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8b78d35: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa982f98: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRAS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7461177: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8d88986: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRFI";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x878bcaf: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRFC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x398d20c: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TWTR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9791cea: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRTP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xaf91cc7: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TFAW";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x04c77a6: {
              //simpleType:uint
              pLabel = "EFF_DRAM_BL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x97a894d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_CL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x988b61c: {
              //simpleType:uint
              pLabel = "EFF_DRAM_AL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe66c2c2: {
              //simpleType:uint
              pLabel = "EFF_DRAM_CWL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2dd5bf0: {
              //simpleType:uint
              pLabel = "EFF_DRAM_RBT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1295a71: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8a96823: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DLL_RESET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x08e6e84: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe7ac6ac: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DLL_PPD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2ef3cf5: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DLL_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x92d72b7: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TDQS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4f7511d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WR_LVL_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x616737c: {
              //simpleType:uint
              pLabel = "EFF_DRAM_OUTPUT_BUFFER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7692ee2: {
              //simpleType:uint
              pLabel = "EFF_DRAM_PASR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa8ace8e: {
              //simpleType:uint
              pLabel = "EFF_DRAM_ASR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x12af03d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_SRT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9fb1838: {
              //simpleType:uint
              pLabel = "EFF_MPR_LOC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6cc620b: {
              //simpleType:uint
              pLabel = "EFF_MPR_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x41c2b82: {
              //simpleType:uint
              pLabel = "EFF_DIMM_RCD_CNTL_WORD_0_15";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x3c59155: {
              //simpleType:uint
              pLabel = "EFF_DIMM_RCD_IBT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x883151c: {
              //simpleType:uint
              pLabel = "EFF_DIMM_RCD_MIRROR_MODE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x049733a: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x48f34e1: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_ADDR_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1c93902: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_TEST_VALID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8115303: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_PARAM_VALID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xff97f93: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_WR_EYE_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1cfb0ee: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_RD_EYE_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x76ec3b2: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_DQS_CLK_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x05e2bac: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_RD_GATE_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4d7ff4b: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_ADDR_CMD_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf7a4d1e: {
              //simpleType:uint
              pLabel = "EFF_MEMCAL_INTERVAL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x629a976: {
              //simpleType:uint
              pLabel = "EFF_ZQCAL_INTERVAL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x82e6cdd: {
              //simpleType:uint
              pLabel = "EFF_IBM_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xcc56cd5: {
              //simpleType:uint
              pLabel = "EFF_NUM_DROPS_PER_PORT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0c3ce87: {
              //simpleType:uint
              pLabel = "EFF_STACK_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x0e715c8: {
              //simpleType:uint
              pLabel = "EFF_NUM_MASTER_RANKS_PER_DIMM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x42399e1: {
              //simpleType:uint
              pLabel = "EFF_NUM_PACKAGES_PER_RANK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x639e764: {
              //simpleType:uint
              pLabel = "EFF_NUM_DIES_PER_PACKAGE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xf91fb2b: {
              //simpleType:uint
              pLabel = "MSS_MEM_THROTTLE_NUMERATOR_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb131fa2: {
              //simpleType:uint
              pLabel = "MSS_MEM_THROTTLE_DENOMINATOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xca2df77: {
              //simpleType:uint
              pLabel = "MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x2e31113: {
              //simpleType:uint
              pLabel = "MSS_MEM_WATT_TARGET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xc72da79: {
              //simpleType:uint
              pLabel = "MSS_POWER_SLOPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xc627bb7: {
              //simpleType:uint
              pLabel = "MSS_POWER_SLOPE2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x5402483: {
              //simpleType:uint
              pLabel = "MSS_POWER_INT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x747aefb: {
              //simpleType:uint
              pLabel = "MSS_POWER_INT2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x2108639: {
              //simpleType:uint
              pLabel = "MSS_TOTAL_POWER_SLOPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xdea8b5d: {
              //simpleType:uint
              pLabel = "MSS_TOTAL_POWER_SLOPE2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x7bc7649: {
              //simpleType:uint
              pLabel = "MSS_TOTAL_POWER_INT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xe6b4858: {
              //simpleType:uint
              pLabel = "MSS_TOTAL_POWER_INT2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xd03076a: {
              //simpleType:uint
              pLabel = "MSS_DIMM_MAXBANDWIDTH_GBS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xf6f5210: {
              //simpleType:uint
              pLabel = "MSS_DIMM_MAXBANDWIDTH_MRS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x314033a: {
              //simpleType:uint
              pLabel = "MSS_CHANNEL_MAXBANDWIDTH_GBS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x57d7489: {
              //simpleType:uint
              pLabel = "MSS_CHANNEL_PAIR_MAXBANDWIDTH_GBS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x1dc9c80: {
              //simpleType:uint
              pLabel = "MSS_CHANNEL_MAXBANDWIDTH_MRS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xa5ac06a: {
              //simpleType:uint
              pLabel = "MSS_CHANNEL_PAIR_MAXBANDWIDTH_MRS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x9f616e0: {
              //simpleType:uint
              pLabel = "MSS_DIMM_MAXPOWER";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x6487231: {
              //simpleType:uint
              pLabel = "MSS_CHANNEL_MAXPOWER";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xc64457f: {
              //simpleType:uint
              pLabel = "MSS_CHANNEL_PAIR_MAXPOWER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xcfd373e: {
              //simpleType:uint
              pLabel = "MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x053abf8: {
              //simpleType:uint
              pLabel = "MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x95b2eb8: {
              //simpleType:uint
              pLabel = "MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xdd334a9: {
              //not readable
              break;
          }
          case 0xe8ca537: {
              //simpleType:uint
              pLabel = "MSS_NWELL_MISPLACEMENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x54fd267: {
              //simpleType:uint
              pLabel = "MSS_INTERLEAVE_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8ee2d89: {
              //not readable
              break;
          }
          case 0x771b18e: {
              //not readable
              break;
          }
          case 0xf35afa4: {
              //simpleType:uint
              pLabel = "MSS_CACHE_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x35e6114: {
              //not readable
              break;
          }
          case 0x210448b: {
              //not readable
              break;
          }
          case 0x3a46e34: {
              //simpleType:uint
              pLabel = "MSS_LAB_OVERRIDE_FOR_MEM_PLL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc666c00: {
              //simpleType:uint
              pLabel = "MSS_MEM_MC_IN_GROUP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 5);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 8 * sizeof(uint8_t);
              break;
          }
          case 0xb1f7c2d: {
              //simpleType:uint
              pLabel = "MSS_MCS_GROUP_32";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[16][16]:");
              l_traceEntry.resize(10+offset + 256 * 11);
              for (uint32_t i = 0;i<256;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 256 * sizeof(uint32_t);
              break;
          }
          case 0x578c150: {
              //simpleType:uint
              pLabel = "MSS_EFF_DIMM_FUNCTIONAL_VECTOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x832191c: {
              //simpleType:uint
              pLabel = "MSS_CAL_STEP_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x647f6d0: {
              //simpleType:uint
              pLabel = "MSS_MEM_IPL_COMPLETE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x71c3bfc: {
              //simpleType:uint
              pLabel = "MSS_SLEW_RATE_DATA";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][ 4][ 4]:");
              l_traceEntry.resize(10+offset + 32 * 5);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 32 * sizeof(uint8_t);
              break;
          }
          case 0x4ad3c3b: {
              //simpleType:uint
              pLabel = "MSS_SLEW_RATE_ADR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][ 4][ 4]:");
              l_traceEntry.resize(10+offset + 32 * 5);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 32 * sizeof(uint8_t);
              break;
          }
          case 0x522a158: {
              //simpleType:uint
              pLabel = "ECID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 19);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint64_t);
              break;
          }
          case 0xd1c0229: {
              //not readable
              break;
          }
          case 0x1d8c588: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CLK_P0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2156b07: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CLK_P1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8b8c03c: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CLK_P0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x3c718df: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CLK_P1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe8901f3: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x0c163f2: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xdf59887: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xbcafe93: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xea77d20: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A4";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x07ca5a8: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A5";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb3b297d: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A6";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xede8de8: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A7";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xd438677: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A8";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6ec818e: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A9";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x4def67f: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A10";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x5e03866: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A11";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf78d030: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A12";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x1ad95d9: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A13";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8c36c84: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A14";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6fa0e2f: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_A15";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xde0daf0: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_BA0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x501b09f: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_BA1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x01def6d: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_BA2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb070e8a: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_CASN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x746963d: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_RASN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x719b818: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_CMD_WEN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8bc743c: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_PAR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6b2b22a: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M_ACTN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xdd3e551: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CKE0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2a9ce17: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CKE1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x19f5d79: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CKE2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf4158a0: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CKE3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x64217a7: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CSN0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x00c226f: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CSN1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x972c092: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CSN2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x64c529c: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_CSN3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xc9ad00c: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_ODT0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xcf5e70b: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M0_CNTL_ODT1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xec28bef: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CKE0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe5fb201: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CKE1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2bea801: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CKE2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6d44754: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CKE3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x194205a: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CSN0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9dabdc5: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CSN1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x0c3cf4f: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CSN2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x55b6fff: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_CSN3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8dda1a9: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_ODT0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x991be14: {
              //simpleType:uint
              pLabel = "EFF_CEN_PHASE_ROT_M1_CNTL_ODT1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x805352f: {
              //not readable
              break;
          }
          case 0xb498067: {
              //simpleType:uint
              pLabel = "MSS_MCS_GROUP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[16][16]:");
              l_traceEntry.resize(10+offset + 256 * 5);
              for (uint32_t i = 0;i<256;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 256 * sizeof(uint8_t);
              break;
          }
          case 0x7fb1f18: {
              //simpleType:uint
              pLabel = "EFF_CKE_MAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x732203a: {
              //simpleType:uint
              pLabel = "EFF_SPCKE_MAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0xc624c4f: {
              //simpleType:uint
              pLabel = "EFF_DIMM_SPARE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x3f96c65: {
              //simpleType:uint
              pLabel = "MSS_PSRO";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf33bed0: {
              //not readable
              break;
          }
          case 0x517e15c: {
              //simpleType:uint
              pLabel = "PROC_PERV_BNDY_PLL_CHIPLET_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5aded9f: {
              //simpleType:uint
              pLabel = "PROC_PB_BNDY_DMIPLL_CHIPLET_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2dc0474: {
              //simpleType:uint
              pLabel = "PROC_AB_BNDY_PLL_CHIPLET_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb07614a: {
              //simpleType:uint
              pLabel = "PROC_PCI_BNDY_PLL_CHIPLET_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa69fd1e: {
              //simpleType:uint
              pLabel = "PROC_PERV_BNDY_PLL_SCAN_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6655935: {
              //simpleType:uint
              pLabel = "PROC_PB_BNDY_DMIPLL_SCAN_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x2c6431c: {
              //simpleType:uint
              pLabel = "PROC_AB_BNDY_PLL_SCAN_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9a38d08: {
              //simpleType:uint
              pLabel = "PROC_PCI_BNDY_PLL_SCAN_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x152214e: {
              //not readable
              break;
          }
          case 0x5ac150b: {
              //simpleType:uint
              pLabel = "SBE_SEEPROM_I2C_DEVICE_ADDRESS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xd1e416f: {
              //simpleType:uint
              pLabel = "SBE_SEEPROM_I2C_PORT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6044f97: {
              //not readable
              break;
          }
          case 0x3761a65: {
              //simpleType:uint
              pLabel = "SYNC_BETWEEN_STEPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x048f69f: {
              //simpleType:uint
              pLabel = "PROC_SELECT_BOOT_MASTER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x36ac7a5: {
              //simpleType:uint
              pLabel = "PROC_SELECT_SEEPROM_IMAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdba3bba: {
              //simpleType:uint
              pLabel = "PROC_SELECT_BOOT_SEEPROM_IMAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdf90286: {
              //simpleType:uint
              pLabel = "ENABLED_THREADS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x8dc78ef: {
              //not readable
              break;
          }
          case 0xa59a4fa: {
              //not readable
              break;
          }
          case 0x9130cb8: {
              //not readable
              break;
          }
          case 0xeb1d539: {
              //not readable
              break;
          }
          case 0x90ddd8e: {
              //not readable
              break;
          }
          case 0xfa1c9e6: {
              //not readable
              break;
          }
          case 0x86e21ac: {
              //not readable
              break;
          }
          case 0xbff8521: {
              //not readable
              break;
          }
          case 0xa046f56: {
              //not readable
              break;
          }
          case 0x1812aa2: {
              //simpleType:uint
              pLabel = "MSS_FREQ_OVERRIDE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9b9014c: {
              //simpleType:uint
              pLabel = "MCBIST_PATTERN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd76e7bb: {
              //simpleType:uint
              pLabel = "MCBIST_TEST_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xbc3b4dc: {
              //simpleType:uint
              pLabel = "MCBIST_PRINTING_DISABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd6f6291: {
              //simpleType:uint
              pLabel = "MCBIST_DATA_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8d4f302: {
              //simpleType:uint
              pLabel = "MCBIST_USER_RANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x48b0ac1: {
              //simpleType:uint
              pLabel = "MCBIST_USER_BANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x12f9f97: {
              //simpleType:uint
              pLabel = "SCHMOO_MULTIPLE_SETUP_CALL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd9ca00c: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_MODES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x166219d: {
              //simpleType:uint
              pLabel = "MCBIST_RANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xac57f07: {
              //simpleType:uint
              pLabel = "MCBIST_START_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x4a7b93f: {
              //simpleType:uint
              pLabel = "MCBIST_END_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xdbbc7e2: {
              //simpleType:uint
              pLabel = "MCBIST_ERROR_CAPTURE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x83f9581: {
              //simpleType:uint
              pLabel = "MCBIST_MAX_TIMEOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x1563492: {
              //simpleType:uint
              pLabel = "MCBIST_PRINT_PORT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc276d65: {
              //simpleType:uint
              pLabel = "MCBIST_STOP_ON_ERROR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3ebad85: {
              //simpleType:uint
              pLabel = "MCBIST_DATA_SEED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x4b5fd99: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_INTER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x49d0fe6: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_NUM_ROWS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd10e3c0: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_NUM_COLS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6d711e3: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_RANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x190b796: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_BANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x898ae31: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_SLAVE_RANK_ON";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1bd25b5: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_STR_MAP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x97e10af: {
              //simpleType:uint
              pLabel = "MCBIST_ADDR_RAND";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe2cfa5e: {
              //not readable
              break;
          }
          case 0xc4a5b13: {
              //simpleType:uint
              pLabel = "PROC_PBIEX_ASYNC_SEL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2b8d151: {
              //not readable
              break;
          }
          case 0xdc95f16: {
              //not readable
              break;
          }
          case 0x0ca8faf: {
              //not readable
              break;
          }
          case 0xf3365af: {
              //not readable
              break;
          }
          case 0x5035da1: {
              //not readable
              break;
          }
          case 0x7da144e: {
              //not readable
              break;
          }
          case 0xfee10ad: {
              //not readable
              break;
          }
          case 0x88124cf: {
              //not readable
              break;
          }
          case 0x304da17: {
              //not readable
              break;
          }
          case 0x5cf8e48: {
              //not readable
              break;
          }
          case 0xb6e1c9d: {
              //not readable
              break;
          }
          case 0xa6f4fe9: {
              //simpleType:uint
              pLabel = "EFF_DRAM_LPASR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4a8236c: {
              //simpleType:uint
              pLabel = "EFF_MPR_PAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdf0a068: {
              //simpleType:uint
              pLabel = "EFF_GEARDOWN_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf217fea: {
              //simpleType:uint
              pLabel = "EFF_PER_DRAM_ACCESS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x857908e: {
              //simpleType:uint
              pLabel = "EFF_TEMP_READOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x83066e3: {
              //simpleType:uint
              pLabel = "EFF_FINE_REFRESH_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x09f03dd: {
              //simpleType:uint
              pLabel = "EFF_CRC_WR_LATENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x49c4f61: {
              //simpleType:uint
              pLabel = "EFF_MPR_RD_FORMAT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7c5012d: {
              //simpleType:uint
              pLabel = "EFF_MAX_POWERDOWN_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8b38b18: {
              //simpleType:uint
              pLabel = "EFF_TEMP_REF_RANGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1e59f41: {
              //simpleType:uint
              pLabel = "EFF_TEMP_REF_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x97bdbe7: {
              //simpleType:uint
              pLabel = "EFF_INT_VREF_MON";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf41a79e: {
              //simpleType:uint
              pLabel = "EFF_CS_CMD_LATENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x33b24bf: {
              //simpleType:uint
              pLabel = "EFF_SELF_REF_ABORT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6440e8c: {
              //simpleType:uint
              pLabel = "EFF_RD_PREAMBLE_TRAIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9285080: {
              //simpleType:uint
              pLabel = "EFF_RD_PREAMBLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5402adf: {
              //simpleType:uint
              pLabel = "EFF_WR_PREAMBLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe1c6e23: {
              //simpleType:uint
              pLabel = "EFF_CA_PARITY_LATENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x88424ac: {
              //simpleType:uint
              pLabel = "EFF_CRC_ERROR_CLEAR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x39f6ac3: {
              //simpleType:uint
              pLabel = "EFF_CA_PARITY_ERROR_STATUS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x552f10f: {
              //simpleType:uint
              pLabel = "EFF_ODT_INPUT_BUFF";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x88a4b7e: {
              //simpleType:uint
              pLabel = "EFF_RTT_PARK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][ 2][ 4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0xc49c5d6: {
              //simpleType:uint
              pLabel = "EFF_CA_PARITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7881e32: {
              //simpleType:uint
              pLabel = "EFF_DATA_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8d4bb23: {
              //simpleType:uint
              pLabel = "EFF_WRITE_DBI";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0035c53: {
              //simpleType:uint
              pLabel = "EFF_READ_DBI";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x88a9505: {
              //simpleType:uint
              pLabel = "EFF_VREF_DQ_TRAIN_VALUE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x7d9ebb7: {
              //simpleType:uint
              pLabel = "EFF_VREF_DQ_TRAIN_RANGE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x9aa76c2: {
              //simpleType:uint
              pLabel = "EFF_VREF_DQ_TRAIN_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x2f3c3ee: {
              //simpleType:uint
              pLabel = "TCCD_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd9af284: {
              //simpleType:uint
              pLabel = "EFF_WRITE_CRC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb4e0269: {
              //simpleType:uint
              pLabel = "EFF_DRAM_2N_MODE_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x887b217: {
              //simpleType:uint
              pLabel = "MSS_DIMM_POWER_TEST_REV";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x278bc56: {
              //not readable
              break;
          }
          case 0xe3947ec: {
              //not readable
              break;
          }
          case 0x957176b: {
              //not readable
              break;
          }
          case 0xba4cb42: {
              //simpleType:uint
              pLabel = "PLCK_IPL_ATTR_OVERRIDES_EXIST";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9df5299: {
              //simpleType:uint
              pLabel = "DUMMY_PERSISTENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x56ef574: {
              //simpleType:uint
              pLabel = "IS_INTER_ENCLOSURE_BUS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xae3bc8f: {
              //not readable
              break;
          }
          case 0x06f2efe: {
              //not readable
              break;
          }
          case 0x9f3cbef: {
              //not readable
              break;
          }
          case 0x6847eb3: {
              //simpleType:uint
              pLabel = "PROC_HTM_BAR_BASE_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x14625e7: {
              //simpleType:uint
              pLabel = "PROC_OCC_SANDBOX_BASE_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x1c0d755: {
              //simpleType:uint
              pLabel = "MEM_MIRROR_PLACEMENT_POLICY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xff14fd2: {
              //not readable
              break;
          }
          case 0xd7adf67: {
              //not readable
              break;
          }
          case 0x6270bcb: {
              //not readable
              break;
          }
          case 0xb3adef2: {
              //simpleType:uint
              pLabel = "RISK_LEVEL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb42bb51: {
              //simpleType:uint
              pLabel = "MSS_FREQ_BIAS_PERCENTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5b64ed1: {
              //not readable
              break;
          }
          case 0x28b5520: {
              //not readable
              break;
          }
          case 0x7380824: {
              //not readable
              break;
          }
          case 0xf1bdf17: {
              //simpleType:uint
              pLabel = "EFF_DRAM_ADDRESS_MIRRORING";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x54b70ff: {
              //simpleType:uint
              pLabel = "MSS_BLUEWATERFALL_BROKEN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6f11c24: {
              //simpleType:uint
              pLabel = "CDM_POLICIES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xaff2273: {
              //simpleType:uint
              pLabel = "FIELD_CORE_OVERRIDE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0aa0ab1: {
              //simpleType:uint
              pLabel = "HOSTSVC_PLID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x778bcbb: {
              //simpleType:uint
              pLabel = "RUN_MAX_MEM_PATTERNS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8e36d0d: {
              //simpleType:uint
              pLabel = "EFF_RLO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x220f4a0: {
              //simpleType:uint
              pLabel = "EFF_WLO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x85f87ba: {
              //simpleType:uint
              pLabel = "EFF_GPO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x78f3ece: {
              //simpleType:uint
              pLabel = "EFF_CKE_PRI_MAP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xdf2f5a8: {
              //simpleType:uint
              pLabel = "EFF_CKE_PWR_MAP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x7462d7e: {
              //simpleType:uint
              pLabel = "EFF_RDTAG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x502a25d: {
              //simpleType:uint
              pLabel = "EFF_TSYS_ADR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x159e8f7: {
              //simpleType:uint
              pLabel = "EFF_TSYS_DP18";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd4d3c40: {
              //simpleType:uint
              pLabel = "EFF_DQ_WR_OFFSET";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x4d42dc7: {
              //simpleType:uint
              pLabel = "EFF_BUFFER_LATENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa9aecb6: {
              //simpleType:uint
              pLabel = "LRDIMM_MR12_REG";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x3eae089: {
              //simpleType:uint
              pLabel = "LRDIMM_ADDITIONAL_CNTL_WORDS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x5472ed9: {
              //simpleType:uint
              pLabel = "LRDIMM_RANK_MULT_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4c1219d: {
              //simpleType:uint
              pLabel = "PM_SPWUP_IGNORE_XSTOP_FLAG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x09d5ed7: {
              //simpleType:uint
              pLabel = "CPM_INFLECTION_POINTS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[16]:");
              l_traceEntry.resize(10+offset + 16 * 11);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 16 * sizeof(uint32_t);
              break;
          }
          case 0x5a21393: {
              //not readable
              break;
          }
          case 0x68c9a51: {
              //simpleType:uint
              pLabel = "MSS_CONTROL_SWITCH";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0a899a5: {
              //simpleType:uint
              pLabel = "MSS_THROTTLE_CONTROL_RAS_WEIGHT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb1fec5b: {
              //simpleType:uint
              pLabel = "MSS_THROTTLE_CONTROL_CAS_WEIGHT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb28a4f5: {
              //simpleType:uint
              pLabel = "PROC_MIRROR_BASES_ACK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x4d787f5: {
              //simpleType:uint
              pLabel = "PROC_MIRROR_SIZES_ACK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x89b8414: {
              //simpleType:uint
              pLabel = "PROC_MEM_BASES_ACK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 19);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(uint64_t);
              break;
          }
          case 0xc3e64a1: {
              //simpleType:uint
              pLabel = "PROC_MEM_SIZES_ACK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 19);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(uint64_t);
              break;
          }
          case 0x281cb6e: {
              //simpleType:uint
              pLabel = "MCBIST_RANDOM_SEED_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf9ac103: {
              //simpleType:uint
              pLabel = "MCBIST_RANDOM_SEED_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5ce94f2: {
              //simpleType:uint
              pLabel = "PROC_BOOT_VOLTAGE_VID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5af6634: {
              //not readable
              break;
          }
          case 0x5f9ce72: {
              //not readable
              break;
          }
          case 0x64e7e70: {
              //not readable
              break;
          }
          case 0x490268f: {
              //not readable
              break;
          }
          case 0x77fd8b5: {
              //not readable
              break;
          }
          case 0x5150470: {
              //not readable
              break;
          }
          case 0xdd9da11: {
              //simpleType:uint
              pLabel = "MULTI_SCOM_BUFFER_MAX_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x1fd9f3d: {
              //not readable
              break;
          }
          case 0xc1de22d: {
              //simpleType:uint
              pLabel = "PROC_VRM_VOFFSET_VDD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe24f70c: {
              //simpleType:uint
              pLabel = "PROC_VRM_VOFFSET_VCS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x611e151: {
              //not readable
              break;
          }
          case 0x2dd043f: {
              //simpleType:uint
              pLabel = "PROC_R_LOADLINE_VDD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa5423c5: {
              //simpleType:uint
              pLabel = "PROC_R_LOADLINE_VCS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa598a78: {
              //simpleType:uint
              pLabel = "PROC_R_DISTLOSS_VDD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd0c457a: {
              //simpleType:uint
              pLabel = "PROC_R_DISTLOSS_VCS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xea63a7d: {
              //not readable
              break;
          }
          case 0x869f8d9: {
              //not readable
              break;
          }
          case 0x4c67b3c: {
              //not readable
              break;
          }
          case 0x02418ea: {
              //not readable
              break;
          }
          case 0x68e1db7: {
              //simpleType:uint
              pLabel = "PROC_MASTER_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa2f9494: {
              //simpleType:uint
              pLabel = "MSS_DATABUS_UTIL_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb2ffe8c: {
              //simpleType:uint
              pLabel = "MSS_UTIL_N_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x8ff8d9c: {
              //simpleType:uint
              pLabel = "EFFECTIVE_EC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x40359a6: {
              //simpleType:uint
              pLabel = "PROC_PBA_UNTRUSTED_BAR_BASE_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x0076133: {
              //simpleType:uint
              pLabel = "PROC_PBA_UNTRUSTED_BAR_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x639dd88: {
              //not readable
              break;
          }
          case 0xba2a405: {
              //simpleType:uint
              pLabel = "MSS_INIT_STATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8eef897: {
              //not readable
              break;
          }
          case 0xe2ef85d: {
              //not readable
              break;
          }
          case 0x4345ae2: {
              //not readable
              break;
          }
          case 0x1e09d62: {
              //not readable
              break;
          }
          case 0x8218c38: {
              //not readable
              break;
          }
          case 0x5a57893: {
              //not readable
              break;
          }
          case 0x1b589a0: {
              //simpleType:uint
              pLabel = "RECONFIGURE_LOOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf543c74: {
              //not readable
              break;
          }
          case 0xc8bfded: {
              //not readable
              break;
          }
          case 0x10517be: {
              //simpleType:uint
              pLabel = "PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf4519b3: {
              //simpleType:uint
              pLabel = "PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0b098c5: {
              //simpleType:uint
              pLabel = "MSS_EFF_VPD_VERSION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf0ab8b0: {
              //simpleType:uint
              pLabel = "DISABLE_SCRUB_AFTER_PATTERN_TEST";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc08791b: {
              //simpleType:uint
              pLabel = "PM_PCBS_FSM_TRACE_EN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc315c52: {
              //simpleType:uint
              pLabel = "PM_GLOBAL_FIR_TRACE_EN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xeb1dca3: {
              //simpleType:uint
              pLabel = "MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x329e82d: {
              //not readable
              break;
          }
          case 0x83ec0da: {
              //simpleType:uint
              pLabel = "MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf597255: {
              //not readable
              break;
          }
          case 0xd08f8e3: {
              //simpleType:uint
              pLabel = "PM_HWP_ATTR_VERSION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x706e27b: {
              //not readable
              break;
          }
          case 0x76b6785: {
              //simpleType:uint
              pLabel = "MSS_NEST_CAPABLE_FREQUENCIES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbe5eeb2: {
              //not readable
              break;
          }
          case 0x057bf0f: {
              //not readable
              break;
          }
          case 0x019e5ac: {
              //simpleType:uint
              pLabel = "TOD_ROLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x72b7486: {
              //not readable
              break;
          }
          case 0xccc15e8: {
              //not readable
              break;
          }
          case 0x0f9d926: {
              //not readable
              break;
          }
          case 0xeaa3fa0: {
              //not readable
              break;
          }
          case 0xcbd7ed0: {
              //not readable
              break;
          }
          case 0xbf11ec0: {
              //not readable
              break;
          }
          case 0x3a85422: {
              //not readable
              break;
          }
          case 0x9f9143c: {
              //not readable
              break;
          }
          case 0x33b0757: {
              //not readable
              break;
          }
          case 0x80161a9: {
              //simpleType:uint
              pLabel = "MEM_AVDD_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x4fe6548: {
              //simpleType:uint
              pLabel = "RECONFIG_LOOP_TESTS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[5]:");
              l_traceEntry.resize(10+offset + 5 * 19);
              for (uint32_t i = 0;i<5;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 5 * sizeof(uint64_t);
              break;
          }
          case 0x97d43be: {
              //simpleType:uint
              pLabel = "RECONFIG_LOOP_TESTS_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcc28df8: {
              //simpleType:uint
              pLabel = "MEM_VDD_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb7b1ac5: {
              //simpleType:uint
              pLabel = "MEM_VCS_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd4a475d: {
              //simpleType:uint
              pLabel = "MEM_VPP_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe390ea6: {
              //simpleType:uint
              pLabel = "MEM_VDDR_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x59735e4: {
              //not readable
              break;
          }
          case 0xa093957: {
              //not readable
              break;
          }
          case 0xfd3432e: {
              //not readable
              break;
          }
          case 0x34604ce: {
              //not readable
              break;
          }
          case 0xeb1087c: {
              //not readable
              break;
          }
          case 0x0b207b3: {
              //not readable
              break;
          }
          case 0xbaa5d46: {
              //not readable
              break;
          }
          case 0xbb0ac42: {
              //not readable
              break;
          }
          case 0x9aef30c: {
              //simpleType:uint
              pLabel = "MSS_CENT_VDD_SLOPE_ACTIVE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x3e7ad0d: {
              //simpleType:uint
              pLabel = "MSS_CENT_VDD_SLOPE_INACTIVE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe54617c: {
              //simpleType:uint
              pLabel = "MSS_CENT_VDD_INTERCEPT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xdfbb097: {
              //simpleType:uint
              pLabel = "MSS_CENT_VCS_SLOPE_ACTIVE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0cbd3fd: {
              //simpleType:uint
              pLabel = "MSS_CENT_VCS_SLOPE_INACTIVE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x42b4fae: {
              //simpleType:uint
              pLabel = "MSS_CENT_VCS_INTERCEPT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x72f49a4: {
              //not readable
              break;
          }
          case 0x3aa234f: {
              //not readable
              break;
          }
          case 0xe2c64ec: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VPP_SLOPE_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd513657: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VPP_INTERCEPT_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x10d2a3d: {
              //not readable
              break;
          }
          case 0xbdf333e: {
              //not readable
              break;
          }
          case 0x6ac0905: {
              //not readable
              break;
          }
          case 0x420d32d: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR3_VDDR_SLOPE_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x829fde2: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR3_VDDR_INTERCEPT_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xdde9311: {
              //simpleType:uint
              pLabel = "MRW_DDR3_VDDR_MAX_LIMIT_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5d56393: {
              //not readable
              break;
          }
          case 0x56b3514: {
              //not readable
              break;
          }
          case 0x69b9e21: {
              //not readable
              break;
          }
          case 0x2b46d91: {
              //not readable
              break;
          }
          case 0xb11a217: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR4_VDDR_SLOPE_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6129fe7: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR4_VDDR_INTERCEPT_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x7b5c147: {
              //simpleType:uint
              pLabel = "MRW_DDR4_VDDR_MAX_LIMIT_POST_DRAM_INIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9b6221c: {
              //simpleType:uint
              pLabel = "MSS_VOLT_OVERRIDE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x09d8b2b: {
              //simpleType:uint
              pLabel = "MSS_VOLT_COMPLIANT_DIMMS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbb01f4d: {
              //simpleType:uint
              pLabel = "MSS_VDDR_OVERIDE_SPD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5938c0f: {
              //not readable
              break;
          }
          case 0xdb31808: {
              //simpleType:uint
              pLabel = "PM_PFET_WORKAROUND_RUN_FLAG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3e59e7e: {
              //simpleType:uint
              pLabel = "PM_OCC_LFIR_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xa48a901: {
              //simpleType:uint
              pLabel = "PM_PBA_FIR_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xb116a02: {
              //simpleType:uint
              pLabel = "PM_PMC_LFIR_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x4851132: {
              //simpleType:uint
              pLabel = "PM_FIRINIT_DONE_ONCE_FLAG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1c70941: {
              //simpleType:uint
              pLabel = "PM_SLEEP_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x442b881: {
              //complexType - skipping
              break;
          }
          case 0xe7e15a5: {
              //not readable
              break;
          }
          case 0x36acfdb: {
              //not readable
              break;
          }
          case 0xcbe6190: {
              //simpleType:uint
              pLabel = "ISDIMM_POWER_CURVE_ALGORITHM_VERSION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1439e9f: {
              //simpleType:uint
              pLabel = "PROC_PCIE_LANE_MASK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[3][2]:");
              l_traceEntry.resize(10+offset + 6 * 7);
              for (uint32_t i = 0;i<6;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 6 * sizeof(uint16_t);
              break;
          }
          case 0xea0b2bc: {
              //not readable
              break;
          }
          case 0x0d07418: {
              //simpleType:uint
              pLabel = "PROC_PCIE_IOP_REVERSAL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[3][2]:");
              l_traceEntry.resize(10+offset + 6 * 5);
              for (uint32_t i = 0;i<6;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 6 * sizeof(uint8_t);
              break;
          }
          case 0x07f9a8c: {
              //not readable
              break;
          }
          case 0xd72889f: {
              //not readable
              break;
          }
          case 0xe9b646f: {
              //not readable
              break;
          }
          case 0xecbcd69: {
              //not readable
              break;
          }
          case 0xbf7d7d7: {
              //not readable
              break;
          }
          case 0xdc4f1f5: {
              //not readable
              break;
          }
          case 0x7e09b93: {
              //not readable
              break;
          }
          case 0x69653af: {
              //not readable
              break;
          }
          case 0xb728b91: {
              //not readable
              break;
          }
          case 0x5c75b22: {
              //not readable
              break;
          }
          case 0x5171c01: {
              //simpleType:uint
              pLabel = "ISTEP_PAUSE_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x837b78a: {
              //not readable
              break;
          }
          case 0x2cf6852: {
              //simpleType:uint
              pLabel = "ISTEP_PAUSE_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xbe133c4: {
              //not readable
              break;
          }
          case 0xb257082: {
              //not readable
              break;
          }
          case 0xe79c887: {
              //not readable
              break;
          }
          case 0xe3ed39e: {
              //not readable
              break;
          }
          case 0x346f572: {
              //not readable
              break;
          }
          case 0x83c9bb5: {
              //not readable
              break;
          }
          case 0x4a0eab5: {
              //not readable
              break;
          }
          case 0xd9a1169: {
              //not readable
              break;
          }
          case 0x834d343: {
              //not readable
              break;
          }
          case 0xeca4ce3: {
              //not readable
              break;
          }
          case 0x71a9c51: {
              //not readable
              break;
          }
          case 0x81856c6: {
              //not readable
              break;
          }
          case 0xcb7fee2: {
              //not readable
              break;
          }
          case 0x9886c55: {
              //not readable
              break;
          }
          case 0x73a79a6: {
              //not readable
              break;
          }
          case 0x00f7abf: {
              //not readable
              break;
          }
          case 0x135e94d: {
              //not readable
              break;
          }
          case 0xd801bd0: {
              //not readable
              break;
          }
          case 0x31f5434: {
              //not readable
              break;
          }
          case 0x9855215: {
              //not readable
              break;
          }
          case 0x98a4f85: {
              //not readable
              break;
          }
          case 0x9b3e875: {
              //not readable
              break;
          }
          case 0xbfccf0c: {
              //not readable
              break;
          }
          case 0x13f6c19: {
              //not readable
              break;
          }
          case 0xa6ef3db: {
              //simpleType:uint
              pLabel = "MSS_VMEM_REGULATOR_MAX_DIMM_COUNT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x64c91aa: {
              //not readable
              break;
          }
          case 0x5f1c224: {
              //not readable
              break;
          }
          case 0x5c2b5f5: {
              //not readable
              break;
          }
          case 0x414abdc: {
              //not readable
              break;
          }
          case 0xc203137: {
              //not readable
              break;
          }
          case 0x60c1e14: {
              //not readable
              break;
          }
          case 0x3fc85b2: {
              //not readable
              break;
          }
          case 0xca00099: {
              //not readable
              break;
          }
          case 0xab7f2ea: {
              //simpleType:uint
              pLabel = "TRUSTED_SLAVE_SCAN_PATH_ACTIVE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4baadc1: {
              //simpleType:uint
              pLabel = "FORCE_SKIP_SBE_MASTER_INTR_SERVICE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xeb3efdd: {
              //simpleType:uint
              pLabel = "FORCE_USE_SBE_SLAVE_SCAN_SERVICE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x07de5de: {
              //simpleType:uint
              pLabel = "SBE_MASTER_INTR_SERVICE_DELAY_CYCLES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x927e9d0: {
              //simpleType:uint
              pLabel = "SBE_MASTER_INTR_SERVICE_DELAY_US";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xac7506e: {
              //not readable
              break;
          }
          case 0xbb6e062: {
              //simpleType:uint
              pLabel = "EFF_DIMM_RCD_CNTL_WORD_X";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x0dbf64a: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC00";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xbb8efa0: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC01";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xb472f05: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC02";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x3bdf1ae: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC03";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x03fc440: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC04";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x193adc4: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC05";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x7910db8: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC06_07";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x56acd0c: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC08";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xb2c0de0: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC09";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x7743239: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC10";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x55c4b62: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC11";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc013663: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC12";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xecd2c19: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC13";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6faf33c: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC14";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x8aa5843: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC15";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xba52471: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_1x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x11a491d: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_2x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x63718cd: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_3x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xb024826: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_4x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x2a65deb: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_5x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x316a223: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_6x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe15f4fa: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_7x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x7838fe1: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_8x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x5b489c1: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_9x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xadb037b: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_Ax";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x4e0fd63: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC_Bx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x732fad3: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TCCD_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd77577c: {
              //simpleType:uint
              pLabel = "EFF_LRDIMM_WORD_X";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x064d52f: {
              //simpleType:uint
              pLabel = "EFF_LRDIMM_ADDITIONAL_CNTL_WORDS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x395d734: {
              //simpleType:uint
              pLabel = "MCBIST_DDR4_PDA_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x80420b8: {
              //not readable
              break;
          }
          case 0x5f6e58a: {
              //not readable
              break;
          }
          case 0x5ab71e7: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRRD_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8cd1455: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TWTR_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3398dfb: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TCCD_S";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdf0d4d9: {
              //simpleType:uint
              pLabel = "OP_TRACE_LITE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6adbf88: {
              //not readable
              break;
          }
          case 0xdc00d2a: {
              //simpleType:uint
              pLabel = "IS_MPIPL_HB";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9b947e9: {
              //simpleType:uint
              pLabel = "XSCOM_VIRTUAL_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x24bd83c: {
              //not readable
              break;
          }
          case 0x0691853: {
              //simpleType:uint
              pLabel = "EEPROM_PAGE_ARRAY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][3]:");
              l_traceEntry.resize(10+offset + 6 * 5);
              for (uint32_t i = 0;i<6;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 6 * sizeof(uint8_t);
              break;
          }
          case 0x62c7ef8: {
              //not readable
              break;
          }
          case 0x1419735: {
              //not readable
              break;
          }
          case 0xe6e329c: {
              //not readable
              break;
          }
          case 0x0ec8887: {
              //not readable
              break;
          }
          case 0x99841b6: {
              //not readable
              break;
          }
          case 0x07646f7: {
              //not readable
              break;
          }
          case 0x29009e8: {
              //not readable
              break;
          }
          case 0x1fa93ae: {
              //not readable
              break;
          }
          case 0x474550f: {
              //not readable
              break;
          }
          case 0xde81674: {
              //not readable
              break;
          }
          case 0x63d25df: {
              //simpleType:uint
              pLabel = "SLW_IMAGE_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x559dc32: {
              //simpleType:uint
              pLabel = "SLW_IMAGE_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x8516c9c: {
              //simpleType:uint
              pLabel = "IBSCOM_VIRTUAL_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x10dd067: {
              //not readable
              break;
          }
          case 0xc88c82f: {
              //not readable
              break;
          }
          case 0xad8243a: {
              //simpleType:uint
              pLabel = "HB_EXISTING_IMAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2d130fe: {
              //simpleType:uint
              pLabel = "HB_PM_SPWUP_OHA_FLAG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1d74d8f: {
              //not readable
              break;
          }
          case 0x1a96d47: {
              //simpleType:uint
              pLabel = "HB_TARGET_SCOMABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd12d8c8: {
              //simpleType:uint
              pLabel = "OCC_COMMON_AREA_PHYS_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xcac816f: {
              //simpleType:uint
              pLabel = "HOMER_PHYS_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x1838631: {
              //simpleType:uint
              pLabel = "HOMER_VIRT_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xf807c26: {
              //not readable
              break;
          }
          case 0x0a5db3f: {
              //not readable
              break;
          }
          case 0xf6c06bc: {
              //not readable
              break;
          }
          case 0x7bfa790: {
              //not readable
              break;
          }
          case 0xf3cfe74: {
              //not readable
              break;
          }
          case 0xfc2cace: {
              //not readable
              break;
          }
          case 0x0516ed5: {
              //not readable
              break;
          }
          case 0x274740e: {
              //not readable
              break;
          }
          case 0x67b8922: {
              //not readable
              break;
          }
          case 0x2e2c7e3: {
              //not readable
              break;
          }
          case 0xdb523f2: {
              //not readable
              break;
          }
          case 0xe974923: {
              //not readable
              break;
          }
          case 0x78f38ad: {
              //not readable
              break;
          }
          case 0xaa6708b: {
              //not readable
              break;
          }
          case 0xafb435e: {
              //not readable
              break;
          }
          case 0x10e7fdc: {
              //not readable
              break;
          }
          case 0x6255aa9: {
              //not readable
              break;
          }
          case 0x54a5bff: {
              //not readable
              break;
          }
          case 0xba49a18: {
              //not readable
              break;
          }
          case 0xab26dbf: {
              //not readable
              break;
          }
          case 0x33234bf: {
              //not readable
              break;
          }
          case 0x0fc9882: {
              //not readable
              break;
          }
          case 0xc789762: {
              //not readable
              break;
          }
          case 0x227fe0f: {
              //not readable
              break;
          }
          case 0x414575c: {
              //not readable
              break;
          }
          case 0x05d02a2: {
              //simpleType:uint
              pLabel = "PSTATE_TABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[3656]:");
              l_traceEntry.resize(10+offset + 3656 * 5);
              for (uint32_t i = 0;i<3656;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 3656 * sizeof(uint8_t);
              break;
          }
          case 0xe98cfd9: {
              //simpleType:uint
              pLabel = "PSTATE_TABLE_MFG";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[3656]:");
              l_traceEntry.resize(10+offset + 3656 * 5);
              for (uint32_t i = 0;i<3656;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 3656 * sizeof(uint8_t);
              break;
          }
          case 0x509d68e: {
              //simpleType:uint
              pLabel = "OCC_CONTROL_DATA";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[256]:");
              l_traceEntry.resize(10+offset + 256 * 5);
              for (uint32_t i = 0;i<256;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 256 * sizeof(uint8_t);
              break;
          }
          case 0xf0b99dd: {
              //simpleType:uint
              pLabel = "OT_MIN_N_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0xb6f988e: {
              //simpleType:uint
              pLabel = "N_PLUS_ONE_N_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0x7608aec: {
              //simpleType:uint
              pLabel = "N_PLUS_ONE_N_PER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0x473cd82: {
              //simpleType:uint
              pLabel = "OVERSUB_N_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0x654dbfc: {
              //simpleType:uint
              pLabel = "OVERSUB_N_PER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0x21a3945: {
              //complexType - skipping
              break;
          }
          case 0x0294b5a: {
              //not readable
              break;
          }
          case 0xed25090: {
              //not readable
              break;
          }
          case 0x094cab6: {
              //simpleType:uint
              pLabel = "HTMGT_SAFEMODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x18dd55a: {
              //not readable
              break;
          }
          case 0x00bf09b: {
              //not readable
              break;
          }
          case 0x330c475: {
              //simpleType:uint
              pLabel = "IPMI_MAX_BUFFER_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xbac5402: {
              //simpleType:uint
              pLabel = "SERIAL_NUMBER";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[18]:");
              l_traceEntry.resize(10+offset + 18 * 5);
              for (uint32_t i = 0;i<18;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 18 * sizeof(uint8_t);
              break;
          }
          case 0x75f1df4: {
              //simpleType:uint
              pLabel = "PART_NUMBER";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[20]:");
              l_traceEntry.resize(10+offset + 20 * 5);
              for (uint32_t i = 0;i<20;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 20 * sizeof(uint8_t);
              break;
          }
          case 0x17cfbf7: {
              //simpleType:uint
              pLabel = "MBVPD_VERSION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9c89449: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VPP_SLOPE_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb165eec: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VPP_INTERCEPT_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x84b5044: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR3_VDDR_SLOPE_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xcc1d4bc: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR3_VDDR_INTERCEPT_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x8830142: {
              //simpleType:uint
              pLabel = "MRW_DDR3_VDDR_MAX_LIMIT_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x646bfc6: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR4_VDDR_SLOPE_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x4706e9e: {
              //simpleType:uint
              pLabel = "MSS_VOLT_DDR4_VDDR_INTERCEPT_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xcbf0ce6: {
              //simpleType:uint
              pLabel = "MRW_DDR4_VDDR_MAX_LIMIT_EFF_CONFIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xdc20544: {
              //simpleType:uint
              pLabel = "SBE_MASTER_INTR_SERVICE_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2a8e9d5: {
              //simpleType:uint
              pLabel = "CLEAR_DIMM_SPD_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x739a2c3: {
              //not readable
              break;
          }
          case 0xbd8e129: {
              //not readable
              break;
          }
          case 0xc2f06b5: {
              //simpleType:uint
              pLabel = "WOF_FREQUENCY_UPLIFT_SELECTED";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[22][13]:");
              l_traceEntry.resize(10+offset + 286 * 7);
              for (uint32_t i = 0;i<286;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 286 * sizeof(uint16_t);
              break;
          }
          case 0xeebaf3e: {
              //not readable
              break;
          }
          case 0x9a40bcc: {
              //simpleType:uint
              pLabel = "NEST_CAPABLE_FREQUENCIES_SYS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x7f57269: {
              //not readable
              break;
          }
          default: {
              pLabel = "unknown Attribute";
              break;
          }
        } // switch

        // pointing to something - print it.
        if (pLabel != NULL) {
            i_parser.PrintString(pLabel, &(l_traceEntry[0]));
        }
    } // for
  } // parse

private:

// Disabled
ErrlUserDetailsParserAttribute(const ErrlUserDetailsParserAttribute &);
ErrlUserDetailsParserAttribute & operator=(const ErrlUserDetailsParserAttribute &);
};
} // namespace
#endif
#endif
