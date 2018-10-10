
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
          case 0x1b7a6ae: {
              //not readable
              break;
          }
          case 0x29e287c: {
              //not readable
              break;
          }
          case 0x01e31e8: {
              //not readable
              break;
          }
          case 0x88381f0: {
              //not readable
              break;
          }
          case 0x83fe364: {
              //not readable
              break;
          }
          case 0x893594e: {
              //simpleType:uint
              pLabel = "MSS_VPD_CKE_MAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0xe85ca14: {
              //simpleType:uint
              pLabel = "MSS_VPD_DQ_MAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][72]:");
              l_traceEntry.resize(10+offset + 144 * 5);
              for (uint32_t i = 0;i<144;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 144 * sizeof(uint8_t);
              break;
          }
          case 0x1812aa2: {
              //simpleType:uint
              pLabel = "MSS_FREQ_OVERRIDE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xe88d183: {
              //simpleType:uint
              pLabel = "MSS_FREQ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
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
          case 0xc1e40a4: {
              //simpleType:uint
              pLabel = "EFF_DIMM_SIZE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x97a894d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_CL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x988b61c: {
              //simpleType:uint
              pLabel = "EFF_DRAM_AL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe66c2c2: {
              //simpleType:uint
              pLabel = "EFF_DRAM_CWL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2dd5bf0: {
              //simpleType:uint
              pLabel = "EFF_DRAM_RBT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x1295a71: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x8a96823: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DLL_RESET";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe7ac6ac: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DLL_PPD";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2ef3cf5: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DLL_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x4f7511d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WR_LVL_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x616737c: {
              //simpleType:uint
              pLabel = "EFF_DRAM_OUTPUT_BUFFER";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7692ee2: {
              //simpleType:uint
              pLabel = "EFF_DRAM_PASR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa8ace8e: {
              //simpleType:uint
              pLabel = "EFF_DRAM_ASR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x12af03d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_SRT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9fb1838: {
              //simpleType:uint
              pLabel = "EFF_MPR_LOC";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6cc620b: {
              //simpleType:uint
              pLabel = "EFF_MPR_MODE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
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
          case 0x464ca55: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC0A";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x7b5be1e: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC0B";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xb57d29f: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC0C";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa07ef50: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC0D";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x39d1412: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC0E";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xd15b7ce: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_RC0F";
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x48f34e1: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_ADDR_MODE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x1c93902: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_TEST_VALID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8115303: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_PARAM_VALID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xff97f93: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_WR_EYE_MIN_MARGIN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x1cfb0ee: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_RD_EYE_MIN_MARGIN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x76ec3b2: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_DQS_CLK_MIN_MARGIN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x05e2bac: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_RD_GATE_MIN_MARGIN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x4d7ff4b: {
              //simpleType:uint
              pLabel = "EFF_SCHMOO_ADDR_CMD_MIN_MARGIN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf7a4d1e: {
              //simpleType:uint
              pLabel = "EFF_MEMCAL_INTERVAL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x629a976: {
              //simpleType:uint
              pLabel = "EFF_ZQCAL_INTERVAL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
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
          case 0xe44453d: {
              //simpleType:uint
              pLabel = "EFF_PRIM_DIE_COUNT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x8469517: {
              //simpleType:uint
              pLabel = "MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0x079546e: {
              //simpleType:uint
              pLabel = "MSS_MEM_PORT_POS_OF_FAIL_THROTTLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xde9b2c0: {
              //simpleType:uint
              pLabel = "MSS_MEM_M_DRAM_CLOCKS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x0a9317e: {
              //simpleType:uint
              pLabel = "MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0x2e31113: {
              //simpleType:uint
              pLabel = "MSS_MEM_WATT_TARGET";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xa389d3d: {
              //simpleType:uint
              pLabel = "MSS_TOTAL_PWR_SLOPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 7);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint16_t);
              break;
          }
          case 0x03b0320: {
              //simpleType:uint
              pLabel = "MSS_TOTAL_PWR_INTERCEPT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 7);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint16_t);
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
          case 0xa334b21: {
              //simpleType:uint
              pLabel = "MSS_DATABUS_UTIL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xbddd69f: {
              //simpleType:uint
              pLabel = "MSS_PORT_MAXPOWER";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x5afde5c: {
              //simpleType:uint
              pLabel = "MSS_DIMM_THERMAL_LIMIT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xf34c5f2: {
              //simpleType:uint
              pLabel = "MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0xe428629: {
              //simpleType:uint
              pLabel = "MSS_RUNTIME_MEM_M_DRAM_CLOCKS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x30c5225: {
              //simpleType:uint
              pLabel = "MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0x578c150: {
              //simpleType:uint
              pLabel = "MSS_EFF_DIMM_FUNCTIONAL_VECTOR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa6f4fe9: {
              //simpleType:uint
              pLabel = "EFF_DRAM_LPASR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x4a8236c: {
              //simpleType:uint
              pLabel = "EFF_MPR_PAGE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xdf0a068: {
              //simpleType:uint
              pLabel = "EFF_GEARDOWN_MODE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf217fea: {
              //simpleType:uint
              pLabel = "EFF_PER_DRAM_ACCESS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x857908e: {
              //simpleType:uint
              pLabel = "EFF_TEMP_READOUT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x09f03dd: {
              //simpleType:uint
              pLabel = "EFF_CRC_WR_LATENCY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x49c4f61: {
              //simpleType:uint
              pLabel = "EFF_MPR_RD_FORMAT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7c5012d: {
              //simpleType:uint
              pLabel = "EFF_MAX_POWERDOWN_MODE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xeee1ede: {
              //simpleType:uint
              pLabel = "EFF_INTERNAL_VREF_MONITOR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf41a79e: {
              //simpleType:uint
              pLabel = "EFF_CS_CMD_LATENCY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x33b24bf: {
              //simpleType:uint
              pLabel = "EFF_SELF_REF_ABORT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6440e8c: {
              //simpleType:uint
              pLabel = "EFF_RD_PREAMBLE_TRAIN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9285080: {
              //simpleType:uint
              pLabel = "EFF_RD_PREAMBLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x5402adf: {
              //simpleType:uint
              pLabel = "EFF_WR_PREAMBLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe1c6e23: {
              //simpleType:uint
              pLabel = "EFF_CA_PARITY_LATENCY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x88424ac: {
              //simpleType:uint
              pLabel = "EFF_CRC_ERROR_CLEAR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x39f6ac3: {
              //simpleType:uint
              pLabel = "EFF_CA_PARITY_ERROR_STATUS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x552f10f: {
              //simpleType:uint
              pLabel = "EFF_ODT_INPUT_BUFF";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xc49c5d6: {
              //simpleType:uint
              pLabel = "EFF_CA_PARITY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7881e32: {
              //simpleType:uint
              pLabel = "EFF_DATA_MASK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8d4bb23: {
              //simpleType:uint
              pLabel = "EFF_WRITE_DBI";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x0035c53: {
              //simpleType:uint
              pLabel = "EFF_READ_DBI";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
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
          case 0xd9af284: {
              //simpleType:uint
              pLabel = "EFF_WRITE_CRC";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x832191c: {
              //simpleType:uint
              pLabel = "MSS_CAL_STEP_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x72e879b: {
              //simpleType:uint
              pLabel = "MSS_CUSTOM_TRAINING_ADV_PATTERNS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x91172b5: {
              //simpleType:uint
              pLabel = "MSS_CUSTOM_TRAINING_ADV_BACKUP_PATTERNS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xbf1609e: {
              //simpleType:uint
              pLabel = "MSS_CUSTOM_TRAINING_ADV_WR_PATTERN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6ed96de: {
              //simpleType:uint
              pLabel = "MSS_VREF_CAL_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0x7ce66ef: {
              //simpleType:uint
              pLabel = "MSS_RDVREF_CAL_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0xff291f4: {
              //simpleType:uint
              pLabel = "MSS_CAL_ABORT_ON_ERROR";
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][4][4]:");
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][4][4]:");
              l_traceEntry.resize(10+offset + 32 * 5);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 32 * sizeof(uint8_t);
              break;
          }
          case 0x12f9f97: {
              //simpleType:uint
              pLabel = "SCHMOO_MULTIPLE_SETUP_CALL";
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x0b098c5: {
              //simpleType:uint
              pLabel = "MSS_EFF_VPD_VERSION";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
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
          case 0xdbfbe2d: {
              //simpleType:uint
              pLabel = "MSS_VREF_DAC_NIBBLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x11d5578: {
              //simpleType:uint
              pLabel = "MSS_VCCD_OVERRIDE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcc1d237: {
              //simpleType:uint
              pLabel = "EFF_DRAM_MAC";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 7);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint16_t);
              break;
          }
          case 0x3d7baaf: {
              //simpleType:uint
              pLabel = "EFF_DRAM_MODULE_BUS_WIDTH";
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
          case 0x10d0cba: {
              //simpleType:uint
              pLabel = "EFF_DRAM_RTT_PARK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x9f09ef3: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC00";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x025d61b: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC01";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc9e6a86: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC02";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xec45ccd: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC03";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x16647d1: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC04";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xab55622: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC05";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x367b0cf: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC06";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe4b2093: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC07";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc932360: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC08";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x965f70d: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC09";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa8aa61f: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC0A";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x9baa851: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC0B";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x9bca452: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC0C";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x39f9d81: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC0D";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x30657d3: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC0E";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xce75758: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_BC0F";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xf716883: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F0BC1x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa8a5557: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BC2x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x898d1da: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BC3x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xdc9830a: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BC4x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa6c1e85: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BC5x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x44ac68a: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F0BC6x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xd21a679: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F70BC7x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x632b0fc: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BC8x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x2bed23e: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BC9x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x1c8e5ad: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BCAx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6eb57f8: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F30BCBx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x1c74b50: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F0BCCx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x50d9c31: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F0BCDx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x7451b69: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F0BCEx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xf51eeab: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F0BCFx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x348d207: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F1BCCx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa4b2ccd: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F1BCDx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe80ba73: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F1BCEx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x106a5a8: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F1BCFx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x97ef6f1: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F4BC0x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xae05d47: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F4BC1x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xeb183bf: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F4BC2x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x17024a5: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F4BC3x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xcb0149a: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F4BC4x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x3ebe386: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F4BC5x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x093748e: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F4BC6x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6dd9b32: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F5BC0x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x970c888: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F5BC1x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x518af90: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F5BC2x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x86de6f2: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F5BC3x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc4c6956: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F5BC5x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xce86ef2: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F5BC6x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x59e99e9: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F6BC0x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xf2c440f: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F6BC1x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x565b92c: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F6BC2x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x56096a3: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F6BC3x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xb9ed8a3: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F6BC4x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xd675fd7: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F6BC5x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa69c5b6: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BC8x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc5e8a7d: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BC9x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc60f5d1: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BCAx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6658888: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BCBx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x391d99a: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BCCx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x7fa2b10: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BCDx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xada1877: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BCEx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xd09004f: {
              //simpleType:uint
              pLabel = "EFF_DIMM_DDR4_F74BCFx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
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
          case 0x92d72b7: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TDQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x20fbdcf: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TREFI";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0x9791cea: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRTP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xdb87b55: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRFC_DLR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x94577f3: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TFAW_DLR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x4081691: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRRD_DLR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf26c1ee: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TXS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x469b49b: {
              //simpleType:uint
              pLabel = "MSS_IGNORE_PLUG_RULES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3167876: {
              //simpleType:uint
              pLabel = "MSS_MVPD_FWMS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][8]:");
              l_traceEntry.resize(10+offset + 16 * 11);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 16 * sizeof(uint32_t);
              break;
          }
          case 0x8da66d4: {
              //simpleType:uint
              pLabel = "MSS_REORDER_QUEUE_SETTING";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x18d405f: {
              //simpleType:uint
              pLabel = "EFF_RANK_GROUP_OVERRIDE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 7);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint16_t);
              break;
          }
          case 0xd34bb04: {
              //simpleType:uint
              pLabel = "MSS_RTT_NOM_OVERRIDE_DISABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x53b8bd1: {
              //simpleType:uint
              pLabel = "MSS_EFF_WR_CRC";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x59c221f: {
              //simpleType:uint
              pLabel = "MSS_WR_VREF_OFFSET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((int8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2eb771c: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_0_VERSION_LAYOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0a3c06d: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_1_VERSION_DATA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x63a654c: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_2_SIGNATURE_HASH";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xaf8883d: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_DPHY_GPO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe421f44: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_DPHY_RLO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x3388aef: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_DPHY_WLO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xfa51a3e: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_2N_MODE_AUTOSET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa8235cc: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa1b24d4: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xfd009d5: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xbb69a29: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9f54ba4: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x3a84164: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x462ffde: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xcfde8a8: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x5725019: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x4f951bc: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xbdb5559: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2d88c22: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2520084: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa58bbd8: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x4770499: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xc0fc67a: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x3ab26b4: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x43438a4: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x5804b81: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xaffb9fe: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x3c77248: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa1cea11: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xfe7bdde: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x975821d: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x70b6294: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7a97b24: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xbc28284: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb6aa7a5: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xab62254: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb52a50d: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf7b498d: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9134bd8: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xec381e5: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf3b0140: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x0642dce: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2fde2e8: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xc7021c1: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x1762315: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8225533: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8b740a2: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_D0_CLKN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x1020074: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_D0_CLKP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa2af804: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_D1_CLKN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xc369bc5: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_MC_PHASE_ROT_D1_CLKP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8b952fa: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_TSYS_ADR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xba5c0ae: {
              //simpleType:uint
              pLabel = "MSS_VPD_MR_TSYS_DATA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5fd9713: {
              //not readable
              break;
          }
          case 0xbe06c50: {
              //not readable
              break;
          }
          case 0xc0f9335: {
              //not readable
              break;
          }
          case 0xb3e8ad9: {
              //not readable
              break;
          }
          case 0xbd13798: {
              //not readable
              break;
          }
          case 0xd4bbddc: {
              //not readable
              break;
          }
          case 0x07bf802: {
              //not readable
              break;
          }
          case 0x0fb9e1f: {
              //not readable
              break;
          }
          case 0x61d3421: {
              //not readable
              break;
          }
          case 0xeab9168: {
              //not readable
              break;
          }
          case 0x6d05234: {
              //not readable
              break;
          }
          case 0x7f51090: {
              //not readable
              break;
          }
          case 0xe5e91b7: {
              //not readable
              break;
          }
          case 0x1949903: {
              //not readable
              break;
          }
          case 0x414abdc: {
              //not readable
              break;
          }
          case 0x3e06dcd: {
              //not readable
              break;
          }
          case 0xfc9bdd9: {
              //not readable
              break;
          }
          case 0xc62f1ae: {
              //not readable
              break;
          }
          case 0xa15fc01: {
              //not readable
              break;
          }
          case 0xf844545: {
              //not readable
              break;
          }
          case 0xd7f8bcd: {
              //not readable
              break;
          }
          case 0x87bdfb9: {
              //not readable
              break;
          }
          case 0x99f7795: {
              //not readable
              break;
          }
          case 0x4f60a5e: {
              //not readable
              break;
          }
          case 0x70c6446: {
              //not readable
              break;
          }
          case 0xfa55dea: {
              //not readable
              break;
          }
          case 0x9c3a3d6: {
              //not readable
              break;
          }
          case 0x1fddb6b: {
              //not readable
              break;
          }
          case 0x2997eae: {
              //not readable
              break;
          }
          case 0x23d66fa: {
              //not readable
              break;
          }
          case 0xc1c206e: {
              //not readable
              break;
          }
          case 0x7b7fc78: {
              //not readable
              break;
          }
          case 0x4c3dbf1: {
              //not readable
              break;
          }
          case 0x86bad95: {
              //not readable
              break;
          }
          case 0x424be69: {
              //not readable
              break;
          }
          case 0x40bfda4: {
              //not readable
              break;
          }
          case 0x047ef58: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_0_VERSION_LAYOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x65e73dc: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_1_VERSION_DATA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x783ce08: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_2_SIGNATURE_HASH";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x3b9d83b: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DIMM_RCD_IBT_CA";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x5e2695c: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DIMM_RCD_IBT_CKE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x4d481e1: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DIMM_RCD_IBT_CS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe2df6e2: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DIMM_RCD_IBT_ODT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x7c84715: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x0f8b173: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DRAM_RTT_NOM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x19ad3b5: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DRAM_RTT_PARK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0xc8013d9: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_DRAM_RTT_WR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x18dd068: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_BIAS_TRIM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x83aea0f: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xfb7a7e9: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x0dbcd50: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xfaa8c76: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DQ_CTLE_CAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 19);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint64_t);
              break;
          }
          case 0x3b94bc2: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DQ_CTLE_RES";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 19);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint64_t);
              break;
          }
          case 0x3ed588d: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DRV_IMP_CLK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x263bb20: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x40553a7: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DRV_IMP_CNTL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9147263: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DRV_IMP_CSCID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9e57914: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_DRV_IMP_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][5]:");
              l_traceEntry.resize(10+offset + 10 * 5);
              for (uint32_t i = 0;i<10;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 10 * sizeof(uint8_t);
              break;
          }
          case 0xa3884a4: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_MC_RCV_IMP_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][5]:");
              l_traceEntry.resize(10+offset + 10 * 5);
              for (uint32_t i = 0;i<10;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 10 * sizeof(uint8_t);
              break;
          }
          case 0x22ad0be: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_ODT_RD";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0xabb67d1: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_ODT_WR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x5c3e6d5: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_PREAMBLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2de5814: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_VREF_DRAM_WR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xb3185b9: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_VREF_MC_RD";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0xec9b003: {
              //simpleType:uint
              pLabel = "MSS_VPD_MT_WINDAGE_RD_CTR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((int16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(int16_t);
              break;
          }
          case 0xf0c49e4: {
              //not readable
              break;
          }
          case 0xa344932: {
              //not readable
              break;
          }
          case 0xf58569d: {
              //not readable
              break;
          }
          case 0x6a276dd: {
              //not readable
              break;
          }
          case 0x7a98e7d: {
              //not readable
              break;
          }
          case 0xf9808c0: {
              //not readable
              break;
          }
          case 0x332e75d: {
              //not readable
              break;
          }
          case 0xfaad3a9: {
              //not readable
              break;
          }
          case 0xe54fb9c: {
              //not readable
              break;
          }
          case 0x0a779ef: {
              //not readable
              break;
          }
          case 0x23b609f: {
              //not readable
              break;
          }
          case 0x8a00d0f: {
              //not readable
              break;
          }
          case 0xeda4c90: {
              //not readable
              break;
          }
          case 0x0d33633: {
              //simpleType:uint
              pLabel = "EFF_DRAM_GEN";
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa71dd22: {
              //simpleType:uint
              pLabel = "EFF_HYBRID_MEMORY_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x43cb904: {
              //simpleType:uint
              pLabel = "EFF_HYBRID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x07a9643: {
              //simpleType:uint
              pLabel = "EFF_DRAM_DENSITY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x06d133f: {
              //simpleType:uint
              pLabel = "EFF_DRAM_BANK_BITS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x667433c: {
              //simpleType:uint
              pLabel = "EFF_DRAM_BANK_GROUP_BITS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x2f2f11c: {
              //simpleType:uint
              pLabel = "EFF_DRAM_COLUMN_BITS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x1c28c5e: {
              //simpleType:uint
              pLabel = "EFF_DRAM_ROW_BITS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x4934fda: {
              //simpleType:uint
              pLabel = "EFF_PRIM_STACK_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x96494e2: {
              //simpleType:uint
              pLabel = "EFF_DRAM_PPR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x5534fbf: {
              //simpleType:uint
              pLabel = "EFF_DRAM_SOFT_PPR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc9b93c9: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRCD";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8b78d35: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa982f98: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRAS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7461177: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRC";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x878bcaf: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRFC";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0xaf91cc7: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TFAW";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xd6045da: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRRD_S";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x5ab71e7: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TRRD_L";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x732fad3: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TCCD_L";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x05193dd: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TWR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x440bec8: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TWTR_S";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8cd1455: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TWTR_L";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8196e7d: {
              //simpleType:uint
              pLabel = "EFF_DRAM_TMAW";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 7);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint16_t);
              break;
          }
          case 0xbcc0968: {
              //simpleType:uint
              pLabel = "EFF_DRAM_WIDTH";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x55fe8eb: {
              //simpleType:uint
              pLabel = "EFF_DRAM_RANK_MIX";
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
          case 0x38313b7: {
              //simpleType:uint
              pLabel = "EFF_REGISTER_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x4bbfd53: {
              //simpleType:uint
              pLabel = "EFF_DRAM_MFG_ID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 7);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint16_t);
              break;
          }
          case 0x43a0d7e: {
              //simpleType:uint
              pLabel = "EFF_RCD_MFG_ID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 7);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint16_t);
              break;
          }
          case 0x6cb15ee: {
              //simpleType:uint
              pLabel = "EFF_REGISTER_REV";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x208baa7: {
              //simpleType:uint
              pLabel = "EFF_PACKAGE_RANK_MAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][18]:");
              l_traceEntry.resize(10+offset + 72 * 5);
              for (uint32_t i = 0;i<72;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 72 * sizeof(uint8_t);
              break;
          }
          case 0x86feede: {
              //simpleType:uint
              pLabel = "EFF_NIBBLE_MAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][18]:");
              l_traceEntry.resize(10+offset + 72 * 5);
              for (uint32_t i = 0;i<72;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 72 * sizeof(uint8_t);
              break;
          }
          case 0x9bb2997: {
              //simpleType:uint
              pLabel = "DO_MSS_WR_VREF";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd8add56: {
              //simpleType:uint
              pLabel = "SKIP_HW_VREF_CAL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4068890: {
              //simpleType:uint
              pLabel = "SKIP_RD_VREF_VREFSENSE_OVERRIDE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x052d264: {
              //simpleType:uint
              pLabel = "DO_MSS_VREF_DAC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc45c859: {
              //simpleType:uint
              pLabel = "DO_MSS_TRAINING_BAD_BITS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x775e116: {
              //simpleType:uint
              pLabel = "MSS_RUN_DCD_CALIBRATION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x69e5db1: {
              //simpleType:uint
              pLabel = "FREQ_PB_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x59a4fc1: {
              //simpleType:uint
              pLabel = "FREQ_O_MHZ";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x01204e8: {
              //simpleType:uint
              pLabel = "FREQ_A_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x38a35a1: {
              //simpleType:uint
              pLabel = "FREQ_X_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd804c85: {
              //not readable
              break;
          }
          case 0xeb57649: {
              //not readable
              break;
          }
          case 0x82f58e6: {
              //not readable
              break;
          }
          case 0xf4ac0bc: {
              //not readable
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
          case 0x64056db: {
              //not readable
              break;
          }
          case 0x23eb4b4: {
              //not readable
              break;
          }
          case 0x7f5639e: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_CORE_FLOOR_RATIO";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xca11470: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_CORE_CEILING_RATIO";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc1c2678: {
              //not readable
              break;
          }
          case 0xcd4c887: {
              //not readable
              break;
          }
          case 0xc0f898a: {
              //not readable
              break;
          }
          case 0x367b1e8: {
              //not readable
              break;
          }
          case 0x7d5f905: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_OPTICS_CONFIG_MODE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x13fc0a6: {
              //not readable
              break;
          }
          case 0x1871395: {
              //simpleType:uint
              pLabel = "FABRIC_PRESENT_GROUPS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf7c35e8: {
              //not readable
              break;
          }
          case 0xc22c68a: {
              //simpleType:uint
              pLabel = "FABRIC_ADDR_EXTENSION_GROUP_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x418fbe1: {
              //simpleType:uint
              pLabel = "FABRIC_ADDR_EXTENSION_CHIP_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbb5d3e9: {
              //simpleType:uint
              pLabel = "PROC_EFF_FABRIC_GROUP_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb91f5de: {
              //simpleType:uint
              pLabel = "PROC_EFF_FABRIC_CHIP_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe831572: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_SYSTEM_MASTER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa2c9bd2: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_GROUP_MASTER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x00116c3: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_LINK_ACTIVE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa7ea6d2: {
              //simpleType:uint
              pLabel = "LINK_TRAIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0d40743: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_X_ATTACHED_CHIP_CNFG";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[7]:");
              l_traceEntry.resize(10+offset + 7 * 5);
              for (uint32_t i = 0;i<7;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 7 * sizeof(uint8_t);
              break;
          }
          case 0x6704d48: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_X_LINKS_CNFG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9db3e24: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_A_ATTACHED_CHIP_CNFG";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x87ff43a: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_A_LINKS_CNFG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa96afb3: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_X_ATTACHED_CHIP_ID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[7]:");
              l_traceEntry.resize(10+offset + 7 * 5);
              for (uint32_t i = 0;i<7;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 7 * sizeof(uint8_t);
              break;
          }
          case 0x56be955: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_X_ATTACHED_LINK_ID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[7]:");
              l_traceEntry.resize(10+offset + 7 * 5);
              for (uint32_t i = 0;i<7;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 7 * sizeof(uint8_t);
              break;
          }
          case 0x5f943d0: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_A_ATTACHED_CHIP_ID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x36e454b: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_A_ATTACHED_LINK_ID";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xeada36c: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_X_AGGREGATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1f2c617: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_X_ADDR_DIS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[7]:");
              l_traceEntry.resize(10+offset + 7 * 5);
              for (uint32_t i = 0;i<7;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 7 * sizeof(uint8_t);
              break;
          }
          case 0xd60cf0a: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_X_LINK_DELAY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[7]:");
              l_traceEntry.resize(10+offset + 7 * 11);
              for (uint32_t i = 0;i<7;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 7 * sizeof(uint32_t);
              break;
          }
          case 0x23ad20f: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_A_AGGREGATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa9a7c39: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_A_ADDR_DIS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc0bb633: {
              //simpleType:uint
              pLabel = "PROC_FABRIC_A_LINK_DELAY";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x29081fa: {
              //simpleType:uint
              pLabel = "PROC_EPS_GB_PERCENTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((int8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x23c87d8: {
              //not readable
              break;
          }
          case 0x21049e0: {
              //simpleType:uint
              pLabel = "PROC_EPS_READ_CYCLES_T0";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x4bf64b9: {
              //simpleType:uint
              pLabel = "PROC_EPS_READ_CYCLES_T1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa78e807: {
              //simpleType:uint
              pLabel = "PROC_EPS_READ_CYCLES_T2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x948370e: {
              //simpleType:uint
              pLabel = "PROC_EPS_WRITE_CYCLES_T1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf104f67: {
              //simpleType:uint
              pLabel = "PROC_EPS_WRITE_CYCLES_T2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xbff8521: {
              //not readable
              break;
          }
          case 0x6a47337: {
              //simpleType:uint
              pLabel = "SYSTEM_IPL_PHASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3fe9f90: {
              //not readable
              break;
          }
          case 0x57ab3c7: {
              //not readable
              break;
          }
          case 0xe595eec: {
              //simpleType:uint
              pLabel = "MAX_INTERLEAVE_GROUP_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x1c0d755: {
              //not readable
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
          case 0x41ed7c4: {
              //not readable
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[16][18]:");
              l_traceEntry.resize(10+offset + 288 * 11);
              for (uint32_t i = 0;i<288;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 288 * sizeof(uint32_t);
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
          case 0xb7dddfb: {
              //not readable
              break;
          }
          case 0xb65b981: {
              //simpleType:uint
              pLabel = "PROC_NHTM_BAR_BASE_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xc4941e4: {
              //simpleType:uint
              pLabel = "PROC_NHTM_BAR_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xf42d558: {
              //simpleType:uint
              pLabel = "PROC_CHTM_BAR_BASE_ADDR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[24]:");
              l_traceEntry.resize(10+offset + 24 * 19);
              for (uint32_t i = 0;i<24;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 24 * sizeof(uint64_t);
              break;
          }
          case 0x4479a4c: {
              //simpleType:uint
              pLabel = "PROC_CHTM_BAR_SIZES";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[24]:");
              l_traceEntry.resize(10+offset + 24 * 19);
              for (uint32_t i = 0;i<24;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 24 * sizeof(uint64_t);
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
          case 0x9f3cbef: {
              //simpleType:uint
              pLabel = "PROC_OCC_SANDBOX_SIZE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
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
          case 0x0ea4707: {
              //simpleType:uint
              pLabel = "HTM_QUEUES";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 5);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 8 * sizeof(uint8_t);
              break;
          }
          case 0xc81c42d: {
              //not readable
              break;
          }
          case 0xc856eaf: {
              //not readable
              break;
          }
          case 0x8921b4b: {
              //not readable
              break;
          }
          case 0xa046f56: {
              //not readable
              break;
          }
          case 0xdc95f16: {
              //not readable
              break;
          }
          case 0x5035da1: {
              //not readable
              break;
          }
          case 0x03614dc: {
              //not readable
              break;
          }
          case 0x962cc31: {
              //not readable
              break;
          }
          case 0xf3365af: {
              //not readable
              break;
          }
          case 0xfee10ad: {
              //not readable
              break;
          }
          case 0x85fcda1: {
              //simpleType:uint
              pLabel = "NHTM_TRACE_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa1e433c: {
              //simpleType:uint
              pLabel = "CHTM_TRACE_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[24]:");
              l_traceEntry.resize(10+offset + 24 * 5);
              for (uint32_t i = 0;i<24;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 24 * sizeof(uint8_t);
              break;
          }
          case 0xcde0848: {
              //simpleType:uint
              pLabel = "HTMSC_TTYPEFILT_PAT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xefc5783: {
              //simpleType:uint
              pLabel = "HTMSC_TSIZEFILT_PAT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf91795a: {
              //simpleType:uint
              pLabel = "HTMSC_TTYPEFILT_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x172d7c5: {
              //simpleType:uint
              pLabel = "HTMSC_TSIZEFILT_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8b5ae6e: {
              //simpleType:uint
              pLabel = "HTMSC_TTYPEFILT_INVERT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xce3e5e5: {
              //simpleType:uint
              pLabel = "HTMSC_CRESPFILT_INVERT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xed6586e: {
              //simpleType:uint
              pLabel = "HTMSC_FILT_PAT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xea5d545: {
              //simpleType:uint
              pLabel = "HTMSC_FILT_CRESP_PAT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x19b3931: {
              //simpleType:uint
              pLabel = "HTMSC_FILT_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe356be6: {
              //simpleType:uint
              pLabel = "HTMSC_FILT_CRESP_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x117c575: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_CONTENT_SEL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd9db997: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_CAPTURE_GENERATED_WRITES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3e20511: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa844a05: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_CAPTURE_PRECISE_CRESP_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xfb2fe64: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x653f119: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_CAPTURE_PMISC_ONLY_CMD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3ad5ca0: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_SYNC_STAMP_FORCE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdb283e0: {
              //simpleType:uint
              pLabel = "NHTM_HTMSC_MODE_WRITETOIO";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x092d705: {
              //simpleType:uint
              pLabel = "CHTM_HTMSC_MODE_CONTENT_SEL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0e2fb21: {
              //simpleType:uint
              pLabel = "CHTM_HTMSC_MODE_CAPTURE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6e2352a: {
              //simpleType:uint
              pLabel = "CHTM_HTMSC_MODE_CORE_INSTR_STALL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5390d2b: {
              //simpleType:uint
              pLabel = "HTMSC_MODE_WRAP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x90059b3: {
              //simpleType:uint
              pLabel = "HTMSC_MODE_DIS_TSTAMP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3d84c2e: {
              //simpleType:uint
              pLabel = "HTMSC_MODE_SINGLE_TSTAMP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5fa7892: {
              //simpleType:uint
              pLabel = "HTMSC_MODE_MARKERS_ONLY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe3950d2: {
              //simpleType:uint
              pLabel = "HTMSC_MODE_DIS_FORCE_GROUP_SCOPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x46a1caf: {
              //simpleType:uint
              pLabel = "HTMSC_MODE_VGTARGET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xfdbc8b2: {
              //simpleType:uint
              pLabel = "HTMSC_MEM_SCOPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x51dd309: {
              //simpleType:uint
              pLabel = "HTMSC_MEM_PRIORITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x65c995d: {
              //simpleType:uint
              pLabel = "NHTM_CTRL_TRIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb9cc761: {
              //simpleType:uint
              pLabel = "NHTM_CTRL_MARK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x16a3e9f: {
              //simpleType:uint
              pLabel = "CHTM_CTRL_TRIG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x970ff46: {
              //simpleType:uint
              pLabel = "CHTM_CTRL_MARK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5464e01: {
              //simpleType:uint
              pLabel = "HTMSC_CTRL_DBG0_STOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5add085: {
              //simpleType:uint
              pLabel = "HTMSC_CTRL_DBG1_STOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc352d05: {
              //simpleType:uint
              pLabel = "HTMSC_CTRL_RUN_STOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xecc42ef: {
              //simpleType:uint
              pLabel = "HTMSC_CTRL_OTHER_DBG0_STOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x472b4fc: {
              //simpleType:uint
              pLabel = "HTMSC_CTRL_XSTOP_STOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdf6bde0: {
              //simpleType:uint
              pLabel = "HTMSC_CTRL_CHIP0_STOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4a70af5: {
              //simpleType:uint
              pLabel = "HTMSC_CTRL_CHIP1_STOP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x65e924e: {
              //simpleType:uint
              pLabel = "HTMSC_IMA_PDBAR_SPLIT_CORE_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe2556ce: {
              //simpleType:uint
              pLabel = "HTMSC_IMA_PDBAR_SCOPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x833d2c7: {
              //simpleType:uint
              pLabel = "HTMSC_IMA_PDBAR_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xfa58f19: {
              //simpleType:uint
              pLabel = "IO_DMI_PROC_DCCAL_FLAGS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa0a75df: {
              //not readable
              break;
          }
          case 0x3df4226: {
              //not readable
              break;
          }
          case 0x78fc2b8: {
              //not readable
              break;
          }
          case 0xaa3902b: {
              //simpleType:uint
              pLabel = "IO_OBUS_DCCAL_FLAGS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9ef1783: {
              //not readable
              break;
          }
          case 0x5c4a180: {
              //not readable
              break;
          }
          case 0xd9db2d5: {
              //not readable
              break;
          }
          case 0xd54b4ac: {
              //not readable
              break;
          }
          case 0xd0b5036: {
              //not readable
              break;
          }
          case 0x1952ef4: {
              //not readable
              break;
          }
          case 0xd8a32e8: {
              //simpleType:uint
              pLabel = "IO_OLLFIR_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x1202cd6: {
              //simpleType:uint
              pLabel = "IO_PB_IOOFIR_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x0d1a22c: {
              //not readable
              break;
          }
          case 0x4505c05: {
              //simpleType:uint
              pLabel = "IO_XBUS_DCCAL_FLAGS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4eddd74: {
              //not readable
              break;
          }
          case 0x213ac30: {
              //not readable
              break;
          }
          case 0xbbf242e: {
              //not readable
              break;
          }
          case 0xc22cf13: {
              //simpleType:uint
              pLabel = "IO_XBUS_MASTER_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9ef94c7: {
              //not readable
              break;
          }
          case 0x5c4b5de: {
              //not readable
              break;
          }
          case 0xa607f58: {
              //not readable
              break;
          }
          case 0x85f1c7e: {
              //not readable
              break;
          }
          case 0xc03d18e: {
              //not readable
              break;
          }
          case 0x998757c: {
              //not readable
              break;
          }
          case 0x637e6da: {
              //not readable
              break;
          }
          case 0xb6b4231: {
              //not readable
              break;
          }
          case 0x6a37320: {
              //not readable
              break;
          }
          case 0xce4b99b: {
              //not readable
              break;
          }
          case 0x0110aab: {
              //not readable
              break;
          }
          case 0xaf99076: {
              //not readable
              break;
          }
          case 0xa3814e1: {
              //not readable
              break;
          }
          case 0x575b03e: {
              //not readable
              break;
          }
          case 0x407787b: {
              //not readable
              break;
          }
          case 0x1766b6d: {
              //simpleType:uint
              pLabel = "PROC_PCIE_PCS_RX_ROT_EXTEL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x21687c0: {
              //not readable
              break;
          }
          case 0x3003319: {
              //not readable
              break;
          }
          case 0x7072e41: {
              //not readable
              break;
          }
          case 0xc55cf38: {
              //not readable
              break;
          }
          case 0x16a9135: {
              //not readable
              break;
          }
          case 0x55f6f2d: {
              //not readable
              break;
          }
          case 0xdd9ccb4: {
              //not readable
              break;
          }
          case 0xe6d858e: {
              //not readable
              break;
          }
          case 0x28f1c68: {
              //not readable
              break;
          }
          case 0xb88574f: {
              //simpleType:uint
              pLabel = "PROC_PCIE_PCS_RX_DFE_FDDC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8f0d7db: {
              //not readable
              break;
          }
          case 0x8f1af9c: {
              //not readable
              break;
          }
          case 0xe3352f1: {
              //not readable
              break;
          }
          case 0xf8dd85b: {
              //not readable
              break;
          }
          case 0xbcf856d: {
              //not readable
              break;
          }
          case 0x4f90d56: {
              //not readable
              break;
          }
          case 0xb5b073a: {
              //not readable
              break;
          }
          case 0x7d06d25: {
              //not readable
              break;
          }
          case 0x6c1b996: {
              //not readable
              break;
          }
          case 0xc008a8d: {
              //not readable
              break;
          }
          case 0x35c6687: {
              //not readable
              break;
          }
          case 0x8883a11: {
              //not readable
              break;
          }
          case 0x206be4b: {
              //not readable
              break;
          }
          case 0x928d6c3: {
              //not readable
              break;
          }
          case 0x037feec: {
              //not readable
              break;
          }
          case 0x6234fc5: {
              //not readable
              break;
          }
          case 0xeb5a690: {
              //not readable
              break;
          }
          case 0x80d024f: {
              //not readable
              break;
          }
          case 0xa625af4: {
              //not readable
              break;
          }
          case 0x28090cf: {
              //not readable
              break;
          }
          case 0x859416a: {
              //not readable
              break;
          }
          case 0xc821788: {
              //not readable
              break;
          }
          case 0x7f84e84: {
              //not readable
              break;
          }
          case 0x51cd229: {
              //not readable
              break;
          }
          case 0x6560cc9: {
              //not readable
              break;
          }
          case 0xa5f7c09: {
              //not readable
              break;
          }
          case 0xf4a1165: {
              //not readable
              break;
          }
          case 0x32fb31e: {
              //not readable
              break;
          }
          case 0x903c07c: {
              //not readable
              break;
          }
          case 0xba8abbe: {
              //not readable
              break;
          }
          case 0x819b97a: {
              //simpleType:uint
              pLabel = "PROC_NPU_REGION_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb441dca: {
              //not readable
              break;
          }
          case 0x8faffe3: {
              //not readable
              break;
          }
          case 0x2a89ed8: {
              //not readable
              break;
          }
          case 0xb6c105c: {
              //simpleType:uint
              pLabel = "EQ_GARD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x837f7ab: {
              //simpleType:uint
              pLabel = "EC_GARD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xbeb4dd6: {
              //not readable
              break;
          }
          case 0x738ed86: {
              //not readable
              break;
          }
          case 0x1cae277: {
              //not readable
              break;
          }
          case 0x575a0f0: {
              //not readable
              break;
          }
          case 0x02190b7: {
              //simpleType:uint
              pLabel = "NEST_PLL_BUCKET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0a745be: {
              //simpleType:uint
              pLabel = "FILTER_PLL_BUCKET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xeedb5b0: {
              //not readable
              break;
          }
          case 0xb3adef2: {
              //simpleType:uint
              pLabel = "RISK_LEVEL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb1c3653: {
              //not readable
              break;
          }
          case 0xb812834: {
              //simpleType:uint
              pLabel = "BACKUP_SEEPROM_SELECT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc774921: {
              //simpleType:uint
              pLabel = "BOOT_FLAGS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
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
          case 0x9ebe9f0: {
              //not readable
              break;
          }
          case 0x208eb9c: {
              //not readable
              break;
          }
          case 0x42549c8: {
              //not readable
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
          case 0xe0c4403: {
              //not readable
              break;
          }
          case 0x229196b: {
              //not readable
              break;
          }
          case 0xafa97ce: {
              //not readable
              break;
          }
          case 0x3d44494: {
              //not readable
              break;
          }
          case 0x241918a: {
              //simpleType:uint
              pLabel = "MC_SYNC_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5d60af0: {
              //not readable
              break;
          }
          case 0x9f08be2: {
              //not readable
              break;
          }
          case 0x22aa222: {
              //not readable
              break;
          }
          case 0x4c42b9b: {
              //simpleType:uint
              pLabel = "PROC_SBE_MASTER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5ac150b: {
              //not readable
              break;
          }
          case 0xd1e416f: {
              //not readable
              break;
          }
          case 0x1592396: {
              //not readable
              break;
          }
          case 0x72ee257: {
              //not readable
              break;
          }
          case 0x0f17b39: {
              //not readable
              break;
          }
          case 0x2d07ffa: {
              //not readable
              break;
          }
          case 0x8d46776: {
              //not readable
              break;
          }
          case 0x3fab398: {
              //not readable
              break;
          }
          case 0x05a0ca5: {
              //not readable
              break;
          }
          case 0xcd97b51: {
              //simpleType:uint
              pLabel = "MASTER_CORE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xfe2e509: {
              //simpleType:uint
              pLabel = "MASTER_EX";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x92913ca: {
              //not readable
              break;
          }
          case 0x29d4df6: {
              //not readable
              break;
          }
          case 0x242427b: {
              //not readable
              break;
          }
          case 0x4bb165d: {
              //simpleType:uint
              pLabel = "PIBMEM_REPAIR0";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xa7ff329: {
              //simpleType:uint
              pLabel = "PIBMEM_REPAIR1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x7090c2b: {
              //simpleType:uint
              pLabel = "PIBMEM_REPAIR2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x8b4b0fb: {
              //simpleType:uint
              pLabel = "SENSEADJ_STEP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1ac5893: {
              //not readable
              break;
          }
          case 0x32c3c25: {
              //not readable
              break;
          }
          case 0x273690d: {
              //not readable
              break;
          }
          case 0x54157b3: {
              //not readable
              break;
          }
          case 0x1204a39: {
              //not readable
              break;
          }
          case 0x2e506e2: {
              //simpleType:uint
              pLabel = "TARGET_HAS_POWER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf83aee8: {
              //simpleType:uint
              pLabel = "TARGET_HAS_CLOCK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7014d18: {
              //simpleType:uint
              pLabel = "TARGET_IS_SCOMMABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf64aeb7: {
              //not readable
              break;
          }
          case 0x5cd9484: {
              //not readable
              break;
          }
          case 0x1c900fa: {
              //not readable
              break;
          }
          case 0x9761e43: {
              //not readable
              break;
          }
          case 0xfe66f82: {
              //not readable
              break;
          }
          case 0x55b725e: {
              //not readable
              break;
          }
          case 0x8ad2e2a: {
              //simpleType:uint
              pLabel = "NDL_MESHCTRL_SETUP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9aa43bc: {
              //not readable
              break;
          }
          case 0x655aa2b: {
              //simpleType:uint
              pLabel = "SYSTEM_CORECACHE_SKEWADJ_DISABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe8e795c: {
              //simpleType:uint
              pLabel = "SYSTEM_CORECACHE_DCADJ_DISABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf0d8721: {
              //not readable
              break;
          }
          case 0x4a9bc8e: {
              //simpleType:uint
              pLabel = "PROC_MEM_TO_USE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x836d048: {
              //simpleType:uint
              pLabel = "ORIG_FIR_SETTINGS_ACTION0";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x9653ac9: {
              //simpleType:uint
              pLabel = "ORIG_FIR_SETTINGS_ACTION1";
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
          case 0xb8bcc7a: {
              //simpleType:uint
              pLabel = "STOPGPE_BOOT_COPIER_IVPR_OFFSET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x303045d: {
              //simpleType:uint
              pLabel = "PSTATEGPE_BOOT_COPIER_IVPR_OFFSET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
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
          case 0x1cae7cd: {
              //simpleType:uint
              pLabel = "OCC_LFIR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x28f2315: {
              //simpleType:uint
              pLabel = "PBA_LFIR";
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
          case 0x639b7ee: {
              //simpleType:uint
              pLabel = "QUAD_PPM_ERRMASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x478edab: {
              //simpleType:uint
              pLabel = "CORE_PPM_ERRMASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb877675: {
              //simpleType:uint
              pLabel = "CME_LOCAL_FIRMASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xea7105b: {
              //simpleType:uint
              pLabel = "L2_HASCLOCKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe977d9f: {
              //simpleType:uint
              pLabel = "L3_HASCLOCKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x46cca69: {
              //simpleType:uint
              pLabel = "C0_EXEC_HASCLOCKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcadc29f: {
              //simpleType:uint
              pLabel = "C1_EXEC_HASCLOCKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb639c30: {
              //simpleType:uint
              pLabel = "C0_PC_HASCLOCKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xae1e6c4: {
              //simpleType:uint
              pLabel = "C1_PC_HASCLOCKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdece9f6: {
              //simpleType:uint
              pLabel = "L2_HASPOWER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5437d12: {
              //simpleType:uint
              pLabel = "L3_HASPOWER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2010712: {
              //simpleType:uint
              pLabel = "C0_HASPOWER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5a8ea4b: {
              //simpleType:uint
              pLabel = "C1_HASPOWER";
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
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
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
          case 0xa3a4736: {
              //simpleType:uint
              pLabel = "PSTATES_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xaa9080d: {
              //simpleType:uint
              pLabel = "RESCLK_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd2ee0c7: {
              //simpleType:uint
              pLabel = "VDM_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x49b21cc: {
              //simpleType:uint
              pLabel = "IVRM_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xca00099: {
              //simpleType:uint
              pLabel = "WOF_ENABLED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4dcb32b: {
              //simpleType:uint
              pLabel = "SGPE_PHANTOM_HALT_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x08f223c: {
              //simpleType:uint
              pLabel = "PGPE_PHANTOM_HALT_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9057ba2: {
              //simpleType:uint
              pLabel = "CME_STOP_PHANTOM_HALT_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x61e642a: {
              //simpleType:uint
              pLabel = "CME_PSTATE_PHANTOM_HALT_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xae5b915: {
              //simpleType:uint
              pLabel = "CORE_INSIDE_SPECIAL_WAKEUP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2bf8757: {
              //simpleType:uint
              pLabel = "EX_INSIDE_SPECIAL_WAKEUP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcb7b544: {
              //simpleType:uint
              pLabel = "EQ_INSIDE_SPECIAL_WAKEUP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xacb5e44: {
              //simpleType:uint
              pLabel = "INITIATED_PM_RESET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1c0ff39: {
              //simpleType:uint
              pLabel = "PM_RESET_PHASE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1a091ba: {
              //not readable
              break;
          }
          case 0x19ff8c3: {
              //not readable
              break;
          }
          case 0xc8ab5a1: {
              //not readable
              break;
          }
          case 0x9dfa8e3: {
              //not readable
              break;
          }
          case 0x055981e: {
              //not readable
              break;
          }
          case 0x920e9b8: {
              //not readable
              break;
          }
          case 0xd604eb6: {
              //simpleType:uint
              pLabel = "SAFE_MODE_NOVDM_UPLIFT_MV";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xad63b90: {
              //simpleType:uint
              pLabel = "SAFE_MODE_VOLTAGE_MV";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x39691ca: {
              //simpleType:uint
              pLabel = "SAFE_MODE_FREQUENCY_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xcc07b62: {
              //not readable
              break;
          }
          case 0x520c023: {
              //not readable
              break;
          }
          case 0xa6d99fc: {
              //not readable
              break;
          }
          case 0xef21476: {
              //not readable
              break;
          }
          case 0xc86629f: {
              //not readable
              break;
          }
          case 0x3f58687: {
              //not readable
              break;
          }
          case 0xceb4953: {
              //not readable
              break;
          }
          case 0xa813c97: {
              //not readable
              break;
          }
          case 0xe20b119: {
              //not readable
              break;
          }
          case 0xbecf4b6: {
              //simpleType:uint
              pLabel = "VDD_BOOT_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa2fea8f: {
              //simpleType:uint
              pLabel = "VDN_BOOT_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa68e8ba: {
              //simpleType:uint
              pLabel = "VCS_BOOT_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9493ec3: {
              //not readable
              break;
          }
          case 0x191dc94: {
              //not readable
              break;
          }
          case 0x14713d4: {
              //not readable
              break;
          }
          case 0x656ab25: {
              //not readable
              break;
          }
          case 0x603a62c: {
              //not readable
              break;
          }
          case 0x4958571: {
              //not readable
              break;
          }
          case 0x4698c59: {
              //not readable
              break;
          }
          case 0x664e3f1: {
              //not readable
              break;
          }
          case 0x99e5b32: {
              //not readable
              break;
          }
          case 0x30ca0ae: {
              //not readable
              break;
          }
          case 0x75abdf6: {
              //not readable
              break;
          }
          case 0x0271124: {
              //not readable
              break;
          }
          case 0xd6ece64: {
              //not readable
              break;
          }
          case 0x1013c3d: {
              //not readable
              break;
          }
          case 0xf99ae48: {
              //not readable
              break;
          }
          case 0x70b05ab: {
              //not readable
              break;
          }
          case 0xd378c29: {
              //not readable
              break;
          }
          case 0x5cae63f: {
              //not readable
              break;
          }
          case 0x5fd22bd: {
              //not readable
              break;
          }
          case 0x0242ba7: {
              //not readable
              break;
          }
          case 0x9fc8b45: {
              //not readable
              break;
          }
          case 0x256bf9a: {
              //not readable
              break;
          }
          case 0x5126c79: {
              //not readable
              break;
          }
          case 0x63f5997: {
              //not readable
              break;
          }
          case 0x8ae9503: {
              //not readable
              break;
          }
          case 0xfc7ecc4: {
              //not readable
              break;
          }
          case 0x431a931: {
              //not readable
              break;
          }
          case 0xa9d1ad8: {
              //not readable
              break;
          }
          case 0xcbb524c: {
              //not readable
              break;
          }
          case 0x5dd7e45: {
              //not readable
              break;
          }
          case 0xd7e2c04: {
              //not readable
              break;
          }
          case 0x2996256: {
              //not readable
              break;
          }
          case 0xa7a6601: {
              //not readable
              break;
          }
          case 0x58a7917: {
              //not readable
              break;
          }
          case 0x93b8597: {
              //not readable
              break;
          }
          case 0x955e6b7: {
              //not readable
              break;
          }
          case 0x7f199a1: {
              //not readable
              break;
          }
          case 0x15c7694: {
              //not readable
              break;
          }
          case 0x59b35d5: {
              //not readable
              break;
          }
          case 0x8d7f254: {
              //not readable
              break;
          }
          case 0xc96a9e2: {
              //not readable
              break;
          }
          case 0x4221eb9: {
              //not readable
              break;
          }
          case 0x36ea053: {
              //not readable
              break;
          }
          case 0xabe3829: {
              //not readable
              break;
          }
          case 0xde3c776: {
              //not readable
              break;
          }
          case 0xf8d7cd7: {
              //not readable
              break;
          }
          case 0x71de8bc: {
              //not readable
              break;
          }
          case 0x2cc9be4: {
              //not readable
              break;
          }
          case 0x73feb55: {
              //not readable
              break;
          }
          case 0x69c7dbd: {
              //not readable
              break;
          }
          case 0x37aeba2: {
              //not readable
              break;
          }
          case 0x10b1123: {
              //not readable
              break;
          }
          case 0x43d0fa1: {
              //not readable
              break;
          }
          case 0x648c404: {
              //not readable
              break;
          }
          case 0x5ce2ab7: {
              //not readable
              break;
          }
          case 0xf4be9f1: {
              //not readable
              break;
          }
          case 0x5ac3ecd: {
              //not readable
              break;
          }
          case 0x4053318: {
              //not readable
              break;
          }
          case 0x55cd48a: {
              //not readable
              break;
          }
          case 0x6aba034: {
              //not readable
              break;
          }
          case 0x05d0481: {
              //not readable
              break;
          }
          case 0x1fe5640: {
              //not readable
              break;
          }
          case 0x38c4618: {
              //not readable
              break;
          }
          case 0xfb6b288: {
              //not readable
              break;
          }
          case 0x1bc94b8: {
              //simpleType:uint
              pLabel = "SYSTEM_RESCLK_DISABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8bdeb02: {
              //not readable
              break;
          }
          case 0x452a420: {
              //simpleType:uint
              pLabel = "SYSTEM_RESCLK_FREQ_REGIONS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 7);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(uint16_t);
              break;
          }
          case 0xcdf52b9: {
              //simpleType:uint
              pLabel = "SYSTEM_RESCLK_FREQ_REGION_INDEX";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 5);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 8 * sizeof(uint8_t);
              break;
          }
          case 0x168939c: {
              //simpleType:uint
              pLabel = "SYSTEM_RESCLK_VALUE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[64]:");
              l_traceEntry.resize(10+offset + 64 * 7);
              for (uint32_t i = 0;i<64;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 64 * sizeof(uint16_t);
              break;
          }
          case 0x41ffdbd: {
              //simpleType:uint
              pLabel = "SYSTEM_RESCLK_L3_VALUE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xff4e39a: {
              //simpleType:uint
              pLabel = "SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0x4028d5e: {
              //not readable
              break;
          }
          case 0xe226c94: {
              //not readable
              break;
          }
          case 0xbe90420: {
              //not readable
              break;
          }
          case 0x2bfa1f9: {
              //not readable
              break;
          }
          case 0xa030cff: {
              //not readable
              break;
          }
          case 0xbb90f0a: {
              //not readable
              break;
          }
          case 0xa24c56a: {
              //not readable
              break;
          }
          case 0x467a7c6: {
              //not readable
              break;
          }
          case 0xa41ce38: {
              //not readable
              break;
          }
          case 0x787d424: {
              //not readable
              break;
          }
          case 0x8a7db83: {
              //not readable
              break;
          }
          case 0x211648c: {
              //not readable
              break;
          }
          case 0x6167a77: {
              //not readable
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
          case 0xaa1d410: {
              //simpleType:uint
              pLabel = "FREQ_PB_MHZ_POUNDV_FALLBACK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6381afd: {
              //simpleType:uint
              pLabel = "SKIP_WAKEUP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa3a830c: {
              //simpleType:uint
              pLabel = "PM_MALF_ALERT_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9bb1f90: {
              //simpleType:uint
              pLabel = "PM_RESET_FFDC_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb630402: {
              //simpleType:uint
              pLabel = "MINI_EC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x80817dc: {
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
          case 0x656ee0f: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT16_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0xcb3bded: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT16_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][3][4]:");
              l_traceEntry.resize(10+offset + 24 * 5);
              for (uint32_t i = 0;i<24;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 24 * sizeof(uint8_t);
              break;
          }
          case 0xe9713da: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT16_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[16]:");
              l_traceEntry.resize(10+offset + 16 * 7);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 16 * sizeof(uint16_t);
              break;
          }
          case 0xc0571d2: {
              //simpleType:uint
              pLabel = "SCRATCH_UINT16_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][3][2]:");
              l_traceEntry.resize(10+offset + 12 * 7);
              for (uint32_t i = 0;i<12;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 12 * sizeof(uint16_t);
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
          case 0xdf566d7: {
              //simpleType:uint
              pLabel = "SCRATCH_INT8_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((int8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5d3127f: {
              //simpleType:uint
              pLabel = "SCRATCH_INT8_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((int8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe9d2ef4: {
              //simpleType:uint
              pLabel = "SCRATCH_INT16_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((int16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(int16_t);
              break;
          }
          case 0xd1894f0: {
              //simpleType:uint
              pLabel = "SCRATCH_INT16_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((int16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(int16_t);
              break;
          }
          case 0x738e066: {
              //simpleType:uint
              pLabel = "SCRATCH_INT32_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((int32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(int32_t);
              break;
          }
          case 0x14868e6: {
              //simpleType:uint
              pLabel = "SCRATCH_INT32_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((int32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(int32_t);
              break;
          }
          case 0xad61d85: {
              //simpleType:uint
              pLabel = "SCRATCH_INT64_1";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((int64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(int64_t);
              break;
          }
          case 0x10e4b80: {
              //simpleType:uint
              pLabel = "SCRATCH_INT64_2";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((int64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(int64_t);
              break;
          }
          case 0x03f242e: {
              //simpleType:uint
              pLabel = "SCRATCH_INT8_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[32]:");
              l_traceEntry.resize(10+offset + 32 * 5);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((int8_t *)l_ptr)+i));
              }
              l_ptr += 32 * sizeof(uint8_t);
              break;
          }
          case 0x4082afe: {
              //simpleType:uint
              pLabel = "SCRATCH_INT8_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][3][4]:");
              l_traceEntry.resize(10+offset + 24 * 5);
              for (uint32_t i = 0;i<24;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((int8_t *)l_ptr)+i));
              }
              l_ptr += 24 * sizeof(uint8_t);
              break;
          }
          case 0x04c90e8: {
              //simpleType:uint
              pLabel = "SCRATCH_INT16_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[16]:");
              l_traceEntry.resize(10+offset + 16 * 7);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((int16_t *)l_ptr)+i)));
              }
              l_ptr += 16 * sizeof(int16_t);
              break;
          }
          case 0x04dc667: {
              //simpleType:uint
              pLabel = "SCRATCH_INT16_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][3][2]:");
              l_traceEntry.resize(10+offset + 12 * 7);
              for (uint32_t i = 0;i<12;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((int16_t *)l_ptr)+i)));
              }
              l_ptr += 12 * sizeof(int16_t);
              break;
          }
          case 0xf5c9611: {
              //simpleType:uint
              pLabel = "SCRATCH_INT32_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 11);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((int32_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(int32_t);
              break;
          }
          case 0x408451a: {
              //simpleType:uint
              pLabel = "SCRATCH_INT32_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][3]:");
              l_traceEntry.resize(10+offset + 6 * 11);
              for (uint32_t i = 0;i<6;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((int32_t *)l_ptr)+i)));
              }
              l_ptr += 6 * sizeof(int32_t);
              break;
          }
          case 0x66c62f7: {
              //simpleType:uint
              pLabel = "SCRATCH_INT64_ARRAY_1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((int64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(int64_t);
              break;
          }
          case 0x0e62699: {
              //simpleType:uint
              pLabel = "SCRATCH_INT64_ARRAY_2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((int64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(int64_t);
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
          case 0x6134e50: {
              //not readable
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
          case 0xfe9c5fd: {
              //not readable
              break;
          }
          case 0xf55ca02: {
              //not readable
              break;
          }
          case 0xcd7817c: {
              //not readable
              break;
          }
          case 0xacbf06c: {
              //not readable
              break;
          }
          case 0x9553606: {
              //not readable
              break;
          }
          case 0x216289b: {
              //simpleType:uint
              pLabel = "CEN_BAD_DQ_BITMAP";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4][10]:");
              l_traceEntry.resize(10+offset + 40 * 5);
              for (uint32_t i = 0;i<40;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 40 * sizeof(uint8_t);
              break;
          }
          case 0x26d1fab: {
              //simpleType:uint
              pLabel = "CEN_MBVPD_VERSION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa8fffa4: {
              //simpleType:uint
              pLabel = "CEN_SPD_DRAM_DEVICE_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe591acd: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7acc3c5: {
              //simpleType:uint
              pLabel = "CEN_SPD_CUSTOM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe5b71e7: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_DENSITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc85ecac: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_BANKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8d19976: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_ROWS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xaac68e8: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_COLUMNS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf88a542: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_NOMINAL_VOLTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x345a5a9: {
              //simpleType:uint
              pLabel = "CEN_SPD_NUM_RANKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9e0e3fb: {
              //simpleType:uint
              pLabel = "CEN_SPD_DRAM_WIDTH";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6b8f21b: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_MEMORY_BUS_WIDTH";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x40b4fb8: {
              //simpleType:uint
              pLabel = "CEN_SPD_TCKMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x545bab9: {
              //simpleType:uint
              pLabel = "CEN_SPD_CAS_LATENCIES_SUPPORTED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6154008: {
              //simpleType:uint
              pLabel = "CEN_SPD_TAAMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8918edd: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRCDMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xde661b3: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRPMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf80eeef: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRASMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe36cd64: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRCMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0f2eeae: {
              //simpleType:uint
              pLabel = "CEN_SPD_TFAWMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x7f09287: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_OPTIONAL_FEATURES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x397bf41: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x38a46eb: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_THERMAL_SENSOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc135f64: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_DEVICE_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x134cb00: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x71d9ecd: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_DIE_COUNT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdfdcdb8: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TCKMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xde4db5d: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TAAMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa9786b6: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TRCDMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5df69d0: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TRPMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x710fe72: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TRCMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x33ca1e0: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x44dc96e: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0bcf48e: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5ee0a6c: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa76f037: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_PART_NUMBER";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[20]:");
              l_traceEntry.resize(10+offset + 20 * 5);
              for (uint32_t i = 0;i<20;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 20 * sizeof(uint8_t);
              break;
          }
          case 0x8077369: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_REVISION_CODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x81ef32f: {
              //simpleType:uint
              pLabel = "CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe05b53a: {
              //simpleType:uint
              pLabel = "CEN_SPD_BAD_DQ_DATA";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[80]:");
              l_traceEntry.resize(10+offset + 80 * 5);
              for (uint32_t i = 0;i<80;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 80 * sizeof(uint8_t);
              break;
          }
          case 0x0e06d84: {
              //simpleType:uint
              pLabel = "CEN_SPD_FTB_DIVIDEND";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x67a0fa7: {
              //simpleType:uint
              pLabel = "CEN_SPD_FTB_DIVISOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2f0ef6b: {
              //simpleType:uint
              pLabel = "CEN_SPD_MTB_DIVIDEND";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xfb11c56: {
              //simpleType:uint
              pLabel = "CEN_SPD_MTB_DIVISOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4de5e69: {
              //simpleType:uint
              pLabel = "CEN_SPD_TWRMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x89947bc: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRRDMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3933ade: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRFCMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd55dd72: {
              //simpleType:uint
              pLabel = "CEN_SPD_TWTRMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd931ae0: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRTPMIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7b54005: {
              //simpleType:uint
              pLabel = "CEN_SPD_SDRAM_BANKGROUPS_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcecb997: {
              //simpleType:uint
              pLabel = "CEN_SPD_TIMEBASE_MTB_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1c61d7c: {
              //simpleType:uint
              pLabel = "CEN_SPD_TIMEBASE_FTB_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8143520: {
              //simpleType:uint
              pLabel = "CEN_SPD_TCKMAX_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd407fc6: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRFC1MIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x42e428e: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRFC2MIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd5d66e1: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRFC4MIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd61ff24: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRRDSMIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xafbcc5a: {
              //simpleType:uint
              pLabel = "CEN_SPD_TRRDLMIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x67c6c0e: {
              //simpleType:uint
              pLabel = "CEN_SPD_TCCDLMIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1609614: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TCCDLMIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x95ab899: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TRRDLMIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcd21212: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TRRDSMIN_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xfac2a44: {
              //simpleType:uint
              pLabel = "CEN_SPD_FINE_OFFSET_TCKMAX_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x29928b0: {
              //simpleType:uint
              pLabel = "CEN_SPD_CRC_BASE_CONFIG_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5f26798: {
              //simpleType:uint
              pLabel = "CEN_SPD_DRAM_STEPPING_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8fe3aec: {
              //simpleType:uint
              pLabel = "CEN_SPD_CRC_MNFG_SEC_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xfa89609: {
              //simpleType:uint
              pLabel = "CEN_SPD_ADDR_MAP_REG_TO_DRAM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2e4ff5f: {
              //simpleType:uint
              pLabel = "CEN_SPD_MODULE_REVISION_CODE_DDR4";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9377123: {
              //not readable
              break;
          }
          case 0xe2373c9: {
              //not readable
              break;
          }
          case 0x9299ae3: {
              //simpleType:uint
              pLabel = "CEN_ISDIMM_MBVPD_INDEX";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x327f621: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_ADDRESS_MIRRORING";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x744b48b: {
              //simpleType:uint
              pLabel = "CEN_MSS_FREQ_OVERRIDE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe0cee5c: {
              //simpleType:uint
              pLabel = "CEN_MSS_FREQ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x598ed16: {
              //simpleType:uint
              pLabel = "CEN_MSS_FREQ_BIAS_PERCENTAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5002ebb: {
              //not readable
              break;
          }
          case 0x19c1aa8: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_RANKS_CONFIGED";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x981e348: {
              //simpleType:uint
              pLabel = "CEN_EFF_NUM_RANKS_PER_DIMM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x8b0548d: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x06af8a9: {
              //simpleType:uint
              pLabel = "CEN_EFF_CUSTOM_DIMM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe43e89a: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_WIDTH";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd95adc1: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_GEN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3a71a35: {
              //simpleType:uint
              pLabel = "CEN_EFF_PRIMARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xd4c69ad: {
              //simpleType:uint
              pLabel = "CEN_EFF_PRIMARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xe342420: {
              //simpleType:uint
              pLabel = "CEN_EFF_PRIMARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x3439ff1: {
              //simpleType:uint
              pLabel = "CEN_EFF_PRIMARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xef6070d: {
              //simpleType:uint
              pLabel = "CEN_EFF_SECONDARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7f09352: {
              //simpleType:uint
              pLabel = "CEN_EFF_SECONDARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2bd2766: {
              //simpleType:uint
              pLabel = "CEN_EFF_SECONDARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x1d3b834: {
              //simpleType:uint
              pLabel = "CEN_EFF_SECONDARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x30d084e: {
              //simpleType:uint
              pLabel = "CEN_EFF_TERTIARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xba1f2ab: {
              //simpleType:uint
              pLabel = "CEN_EFF_TERTIARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xf36c168: {
              //simpleType:uint
              pLabel = "CEN_EFF_TERTIARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xc16e92e: {
              //simpleType:uint
              pLabel = "CEN_EFF_TERTIARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xd710fa6: {
              //simpleType:uint
              pLabel = "CEN_EFF_QUATERNARY_RANK_GROUP0";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x8deea09: {
              //simpleType:uint
              pLabel = "CEN_EFF_QUATERNARY_RANK_GROUP1";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x90db64a: {
              //simpleType:uint
              pLabel = "CEN_EFF_QUATERNARY_RANK_GROUP2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xd003a67: {
              //simpleType:uint
              pLabel = "CEN_EFF_QUATERNARY_RANK_GROUP3";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xafa101d: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_WR_VREF";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x7d23783: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_WR_VREF_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x2f4087f: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_DRV_IMP_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x9b039b6: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x89f62ee: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_DRV_IMP_CLK_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x11e4545: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_DRV_IMP_SPCKE_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x48658bb: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_DRV_IMP_CNTL_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x53b2992: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_RCV_IMP_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x15b523f: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x5548a63: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_SLEW_RATE_DQ_DQS";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x6b79b1a: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x73de7a1: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_SLEW_RATE_CLK_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x2f8f25e: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_SLEW_RATE_SPCKE_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xa0e66d7: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_SLEW_RATE_ADDR_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0xba38f89: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_SLEW_RATE_CNTL_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x7db9326: {
              //simpleType:uint
              pLabel = "CEN_EFF_RD_VREF";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x7085a02: {
              //simpleType:uint
              pLabel = "CEN_EFF_CEN_RD_VREF_SCHMOO";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 11);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 2 * sizeof(uint32_t);
              break;
          }
          case 0x0e8df6e: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_SIZE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x02908ea: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_BANKS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6a90ade: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_ROWS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8b20d41: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_COLS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9bdcdaa: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_DENSITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1836a37: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRCD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9543112: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRRD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xecc5414: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRRD_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6d5a997: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb1db98e: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRAS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4d6323a: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x43ba536: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRFI";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xddf91cd: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRFC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1933ca2: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TWTR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x095db90: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TWTR_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x307f42c: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TRTP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1d20bdd: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TFAW";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xfbaf45b: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_BL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x55adebc: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_CL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4043cb7: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_AL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xa172bee: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_CWL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0addad1: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_RBT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf4da2e3: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xecd6fdb: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_DLL_RESET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0dc73e8: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_WR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb42f8f9: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_DLL_PPD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xda13177: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_DLL_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x623d3cd: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TDQS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe8dda1d: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_WR_LVL_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xea7a80c: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_OUTPUT_BUFFER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x84447d8: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_PASR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x67b1316: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_ASR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbfc2d98: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_SRT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd6495b1: {
              //simpleType:uint
              pLabel = "CEN_EFF_MPR_LOC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf4eb56b: {
              //simpleType:uint
              pLabel = "CEN_EFF_MPR_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd887095: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_RCD_CNTL_WORD_0_15";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 19);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint64_t);
              break;
          }
          case 0x93e06ad: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC00";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6fa41e1: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC01";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xa59e9bf: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC02";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xee6811c: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC03";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xad67ccf: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC04";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6fc5121: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC05";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x4aacd37: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC06_07";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xdfc70b4: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC08";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xf9972b2: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC09";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x1ef4374: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC10";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x0a4b71b: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC11";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xb105f49: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC12";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xec72c7d: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC13";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x17d3083: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC14";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x191d103: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC15";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x16b7380: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_1x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x87bd1cc: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_2x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x43ebe7d: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_3x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x54f20c2: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_4x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x254d9fb: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_5x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xd82d9b6: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_6x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x08f7b4d: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_7x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x82c649b: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_8x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x3cce036: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_9x";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xde47cfc: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_Ax";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x22a780c: {
              //simpleType:uint
              pLabel = "CEN_EFF_DIMM_DDR4_RC_Bx";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6b50c45: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x869f899: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_ADDR_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xedff315: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_TEST_VALID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1120167: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_PARAM_VALID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xff192b3: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_WR_EYE_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3142251: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_RD_EYE_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1f2bcd4: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_DQS_CLK_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x52f31f0: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_RD_GATE_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc98a82d: {
              //simpleType:uint
              pLabel = "CEN_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x50a84d7: {
              //simpleType:uint
              pLabel = "CEN_EFF_MEMCAL_INTERVAL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x7686210: {
              //simpleType:uint
              pLabel = "CEN_EFF_ZQCAL_INTERVAL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x795a863: {
              //simpleType:uint
              pLabel = "CEN_EFF_IBM_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x54d689f: {
              //simpleType:uint
              pLabel = "CEN_EFF_NUM_DROPS_PER_PORT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xec3e951: {
              //simpleType:uint
              pLabel = "CEN_EFF_STACK_TYPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x6b62dba: {
              //simpleType:uint
              pLabel = "CEN_EFF_NUM_MASTER_RANKS_PER_DIMM";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xc65a405: {
              //simpleType:uint
              pLabel = "CEN_EFF_NUM_PACKAGES_PER_RANK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0x1674bb9: {
              //simpleType:uint
              pLabel = "CEN_EFF_NUM_DIES_PER_PACKAGE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xe8d6009: {
              //simpleType:uint
              pLabel = "CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x28b0dbe: {
              //simpleType:uint
              pLabel = "CEN_MSS_MEM_THROTTLE_DENOMINATOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x0e92733: {
              //simpleType:uint
              pLabel = "CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x82bc6a4: {
              //simpleType:uint
              pLabel = "CEN_MSS_MEM_WATT_TARGET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x3fa1340: {
              //simpleType:uint
              pLabel = "CEN_MSS_POWER_SLOPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x9c9f3a2: {
              //simpleType:uint
              pLabel = "CEN_MSS_POWER_SLOPE2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xdd513bc: {
              //simpleType:uint
              pLabel = "CEN_MSS_POWER_INT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xdd6a5e0: {
              //simpleType:uint
              pLabel = "CEN_MSS_POWER_INT2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xcfc2a9a: {
              //simpleType:uint
              pLabel = "CEN_MSS_TOTAL_POWER_SLOPE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x6db2eb2: {
              //simpleType:uint
              pLabel = "CEN_MSS_TOTAL_POWER_SLOPE2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xc7e086f: {
              //simpleType:uint
              pLabel = "CEN_MSS_TOTAL_POWER_INT";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0x47675e0: {
              //simpleType:uint
              pLabel = "CEN_MSS_TOTAL_POWER_INT2";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2]:");
              l_traceEntry.resize(10+offset + 4 * 11);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint32_t);
              break;
          }
          case 0xaae5043: {
              //simpleType:uint
              pLabel = "CEN_MSS_CHANNEL_PAIR_MAXPOWER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1c958c3: {
              //simpleType:uint
              pLabel = "CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x2cb84a2: {
              //simpleType:uint
              pLabel = "CEN_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb926025: {
              //simpleType:uint
              pLabel = "CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x370b061: {
              //not readable
              break;
          }
          case 0x1967c1a: {
              //not readable
              break;
          }
          case 0x958e78e: {
              //simpleType:uint
              pLabel = "CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xaafd4f0: {
              //simpleType:uint
              pLabel = "CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x878d10f: {
              //not readable
              break;
          }
          case 0xb4d4cf8: {
              //not readable
              break;
          }
          case 0x2c636b8: {
              //not readable
              break;
          }
          case 0xfd1b83b: {
              //not readable
              break;
          }
          case 0x6d48287: {
              //simpleType:uint
              pLabel = "CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x37d1388: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_LPASR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x41c9ac8: {
              //simpleType:uint
              pLabel = "CEN_EFF_MPR_PAGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xce4e093: {
              //simpleType:uint
              pLabel = "CEN_EFF_GEARDOWN_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xff781f8: {
              //simpleType:uint
              pLabel = "CEN_EFF_PER_DRAM_ACCESS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x310c52f: {
              //simpleType:uint
              pLabel = "CEN_EFF_TEMP_READOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3ade6e3: {
              //simpleType:uint
              pLabel = "CEN_EFF_FINE_REFRESH_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x51c8ac1: {
              //simpleType:uint
              pLabel = "CEN_EFF_CRC_WR_LATENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0483f1f: {
              //simpleType:uint
              pLabel = "CEN_EFF_MPR_RD_FORMAT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x09f4548: {
              //simpleType:uint
              pLabel = "CEN_EFF_MAX_POWERDOWN_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xed1f8e8: {
              //simpleType:uint
              pLabel = "CEN_EFF_TEMP_REF_RANGE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xaf1df7d: {
              //simpleType:uint
              pLabel = "CEN_EFF_TEMP_REF_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x225ce7a: {
              //simpleType:uint
              pLabel = "CEN_EFF_INT_VREF_MON";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc468688: {
              //simpleType:uint
              pLabel = "CEN_EFF_CS_CMD_LATENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x748adc1: {
              //simpleType:uint
              pLabel = "CEN_EFF_SELF_REF_ABORT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcab8eb5: {
              //simpleType:uint
              pLabel = "CEN_EFF_RD_PREAMBLE_TRAIN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7f96acf: {
              //simpleType:uint
              pLabel = "CEN_EFF_RD_PREAMBLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc4fc72c: {
              //simpleType:uint
              pLabel = "CEN_EFF_WR_PREAMBLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x59149c4: {
              //simpleType:uint
              pLabel = "CEN_EFF_CA_PARITY_LATENCY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcaed664: {
              //simpleType:uint
              pLabel = "CEN_EFF_CRC_ERROR_CLEAR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd9e41c8: {
              //simpleType:uint
              pLabel = "CEN_EFF_CA_PARITY_ERROR_STATUS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd7d60d6: {
              //simpleType:uint
              pLabel = "CEN_EFF_ODT_INPUT_BUFF";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xd31a650: {
              //simpleType:uint
              pLabel = "CEN_EFF_CA_PARITY";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb3ecdd6: {
              //simpleType:uint
              pLabel = "CEN_EFF_DATA_MASK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xc1806ea: {
              //simpleType:uint
              pLabel = "CEN_EFF_WRITE_DBI";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcefaef7: {
              //simpleType:uint
              pLabel = "CEN_EFF_READ_DBI";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xaa26704: {
              //simpleType:uint
              pLabel = "CEN_EFF_VREF_DQ_TRAIN_VALUE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x5d87502: {
              //simpleType:uint
              pLabel = "CEN_EFF_VREF_DQ_TRAIN_RANGE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0xccaca56: {
              //simpleType:uint
              pLabel = "CEN_EFF_VREF_DQ_TRAIN_ENABLE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][2][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
              break;
          }
          case 0x20a086a: {
              //simpleType:uint
              pLabel = "CEN_EFF_DRAM_TCCD_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x93979a5: {
              //simpleType:uint
              pLabel = "CEN_TCCD_L";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0589671: {
              //simpleType:uint
              pLabel = "CEN_EFF_WRITE_CRC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x604bcac: {
              //simpleType:uint
              pLabel = "CEN_MSS_CAL_STEP_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xf7d3f14: {
              //not readable
              break;
          }
          case 0xfe92797: {
              //simpleType:uint
              pLabel = "CEN_MSS_SLEW_RATE_DATA";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][4][4]:");
              l_traceEntry.resize(10+offset + 32 * 5);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 32 * sizeof(uint8_t);
              break;
          }
          case 0xe8e23fa: {
              //simpleType:uint
              pLabel = "CEN_MSS_SLEW_RATE_ADR";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2][4][4]:");
              l_traceEntry.resize(10+offset + 32 * 5);
              for (uint32_t i = 0;i<32;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 32 * sizeof(uint8_t);
              break;
          }
          case 0x354ab09: {
              //not readable
              break;
          }
          case 0x4b3f705: {
              //not readable
              break;
          }
          case 0xfe414f7: {
              //simpleType:uint
              pLabel = "CEN_MSS_PSRO";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9cc0816: {
              //simpleType:uint
              pLabel = "CEN_MSS_NWELL_MISPLACEMENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2d82797: {
              //simpleType:uint
              pLabel = "CEN_MSS_BLUEWATERFALL_BROKEN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x0b6c5db: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_PATTERN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf26628b: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_TEST_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa4e60c2: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_PRINTING_DISABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x997f7c4: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_DATA_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x21603c1: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_USER_RANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xdd686eb: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_USER_BANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3dd7117: {
              //simpleType:uint
              pLabel = "CEN_SCHMOO_MULTIPLE_SETUP_CALL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xca9f7c7: {
              //simpleType:uint
              pLabel = "CEN_LRDIMM_RANK_MULT_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x53f11f8: {
              //simpleType:uint
              pLabel = "CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x515dae1: {
              //simpleType:uint
              pLabel = "CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7b2175f: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_RANDOM_SEED_VALUE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xc75eb41: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_RANDOM_SEED_TYPE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xff27847: {
              //simpleType:uint
              pLabel = "CEN_MSS_INIT_STATE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x87fe8e8: {
              //simpleType:uint
              pLabel = "CEN_MSS_EFF_VPD_VERSION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x87001ce: {
              //simpleType:uint
              pLabel = "CEN_MSS_NEST_CAPABLE_FREQUENCIES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6a19cdb: {
              //not readable
              break;
          }
          case 0x5ac4af5: {
              //not readable
              break;
          }
          case 0x42088ff: {
              //not readable
              break;
          }
          case 0xaa72074: {
              //not readable
              break;
          }
          case 0x8f739e7: {
              //not readable
              break;
          }
          case 0x4f733bb: {
              //not readable
              break;
          }
          case 0x236906f: {
              //not readable
              break;
          }
          case 0xc80af45: {
              //not readable
              break;
          }
          case 0x55b3d54: {
              //not readable
              break;
          }
          case 0x686471f: {
              //not readable
              break;
          }
          case 0x7af7c72: {
              //not readable
              break;
          }
          case 0x9daba11: {
              //not readable
              break;
          }
          case 0xc9baf6f: {
              //not readable
              break;
          }
          case 0x63b9799: {
              //not readable
              break;
          }
          case 0x5b64ed1: {
              //not readable
              break;
          }
          case 0x6ab4033: {
              //simpleType:uint
              pLabel = "CEN_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x65f1d3f: {
              //not readable
              break;
          }
          case 0xd50eebc: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_MODES";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x8ad71d2: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_RANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5bc2120: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_START_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xe532e44: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_END_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x260db1a: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ERROR_CAPTURE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4993ed6: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_MAX_TIMEOUT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x54b87d2: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_PRINT_PORT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7aaa7ea: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_STOP_ON_ERROR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x239639b: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_DATA_SEED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xf8f5783: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_INTER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9f281eb: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_NUM_ROWS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcfd32f3: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_NUM_COLS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x1e81411: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_RANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x3de3e81: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_BANK";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x7be028c: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_SLAVE_RANK_ON";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x292cb92: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_STR_MAP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xc32d9ea: {
              //simpleType:uint
              pLabel = "CEN_MCBIST_ADDR_RAND";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x5f1edc8: {
              //not readable
              break;
          }
          case 0x8fbd559: {
              //not readable
              break;
          }
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
          case 0xdeda910: {
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
          case 0xd301294: {
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
          case 0x21c70fd: {
              //not readable
              break;
          }
          case 0x3b6e39f: {
              //not readable
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
          case 0xb1fab71: {
              //not readable
              break;
          }
          case 0xca6a09a: {
              //not readable
              break;
          }
          case 0x3e2ad88: {
              //simpleType:uint
              pLabel = "TPM_UNUSABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x9f10191: {
              //simpleType:uint
              pLabel = "HDAT_EC";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
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
          case 0xdb4e40c: {
              //not readable
              break;
          }
          case 0x34eeb58: {
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
          case 0x6d7bbc9: {
              //simpleType:uint
              pLabel = "DPO_MIN_FREQ_PERCENT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((int32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(int32_t);
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
          case 0x9dc28f2: {
              //not readable
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
          case 0x7803464: {
              //simpleType:uint
              pLabel = "XSCOM_BASE_ADDRESS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
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
          case 0x6508321: {
              //simpleType:uint
              pLabel = "PSI_BRIDGE_BASE_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xac49a29: {
              //simpleType:uint
              pLabel = "INTP_BASE_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
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
          case 0xe8b8c0b: {
              //not readable
              break;
          }
          case 0xa2bac3b: {
              //not readable
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
          case 0x3dbc21a: {
              //not readable
              break;
          }
          case 0x6a22222: {
              //not readable
              break;
          }
          case 0xec8827a: {
              //not readable
              break;
          }
          case 0x89224bc: {
              //not readable
              break;
          }
          case 0x61356e1: {
              //not readable
              break;
          }
          case 0xc498800: {
              //not readable
              break;
          }
          case 0x51289c7: {
              //not readable
              break;
          }
          case 0x2280840: {
              //not readable
              break;
          }
          case 0xb4f1718: {
              //not readable
              break;
          }
          case 0xefb544c: {
              //not readable
              break;
          }
          case 0x17228f8: {
              //not readable
              break;
          }
          case 0x3317838: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VDDR_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x18a11eb: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VPP_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xc76fe71: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VCS_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xdcbd688: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VDD_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6f09c49: {
              //simpleType:uint
              pLabel = "MSS_VOLT_AVDD_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x666457d: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VDDR_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x1166570: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VPP_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x32d623a: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VCS_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x9a3b18e: {
              //simpleType:uint
              pLabel = "MSS_VOLT_VDD_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x4f0f469: {
              //simpleType:uint
              pLabel = "MSS_VOLT_AVDD_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
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
          case 0x30cbc29: {
              //simpleType:uint
              pLabel = "TEST_NEGATIVE_FCN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((int8_t *)l_ptr)+i));
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
          case 0x639dd88: {
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
          case 0xbf11ec0: {
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
          case 0xc73cd4e: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VDDR_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x2b00bff: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VPP_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x32d84bd: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VCS_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x19c712c: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VDD_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xad171df: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_AVDD_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x317b69f: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VDDR_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xa6645a7: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VPP_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xb5913fd: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VCS_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd55bf40: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_VDD_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xc976513: {
              //simpleType:uint
              pLabel = "CEN_MSS_VOLT_AVDD_OFFSET_MILLIVOLTS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
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
          case 0x442b881: {
              //complexType - skipping
              break;
          }
          case 0xe7e15a5: {
              //not readable
              break;
          }
          case 0x1439e9f: {
              //simpleType:uint
              pLabel = "PROC_PCIE_LANE_MASK";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 7);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 4 * sizeof(uint16_t);
              break;
          }
          case 0x97e0876: {
              //simpleType:uint
              pLabel = "PEC_PCIE_IOP_REVERSAL";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4]:");
              l_traceEntry.resize(10+offset + 4 * 5);
              for (uint32_t i = 0;i<4;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 4 * sizeof(uint8_t);
              break;
          }
          case 0xebbaf50: {
              //not readable
              break;
          }
          case 0x70406e6: {
              //not readable
              break;
          }
          case 0x65a6fb3: {
              //not readable
              break;
          }
          case 0x3322938: {
              //not readable
              break;
          }
          case 0x1d55f3f: {
              //not readable
              break;
          }
          case 0xa258a52: {
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
          case 0xe79c887: {
              //simpleType:uint
              pLabel = "TPM_REQUIRED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
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
          case 0xe6e8743: {
              //not readable
              break;
          }
          case 0x723f825: {
              //not readable
              break;
          }
          case 0x1049d17: {
              //not readable
              break;
          }
          case 0x3d1a60f: {
              //not readable
              break;
          }
          case 0x5b0d3bc: {
              //simpleType:uint
              pLabel = "RCD_PARITY_RECONFIG_LOOP_COUNT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xbfccf0c: {
              //not readable
              break;
          }
          case 0x1ffe3ce: {
              //simpleType:uint
              pLabel = "LPC_BUS_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x859437f: {
              //simpleType:uint
              pLabel = "XIVE_CONTROLLER_BAR_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x5cba1d1: {
              //simpleType:uint
              pLabel = "XIVE_THREAD_MGMT1_BAR_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x4e64812: {
              //simpleType:uint
              pLabel = "PSI_HB_ESB_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x9f670db: {
              //simpleType:uint
              pLabel = "FUSED_CORE_OPTION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x934de01: {
              //not readable
              break;
          }
          case 0x2c13580: {
              //not readable
              break;
          }
          case 0x7d275f0: {
              //not readable
              break;
          }
          case 0xacc8025: {
              //not readable
              break;
          }
          case 0x9cb467b: {
              //not readable
              break;
          }
          case 0x0bce06b: {
              //not readable
              break;
          }
          case 0xfc7c1e8: {
              //not readable
              break;
          }
          case 0x07a2758: {
              //not readable
              break;
          }
          case 0x8845c5b: {
              //not readable
              break;
          }
          case 0xfc574bf: {
              //not readable
              break;
          }
          case 0xdbffc50: {
              //not readable
              break;
          }
          case 0x1192453: {
              //not readable
              break;
          }
          case 0xfb5ce79: {
              //not readable
              break;
          }
          case 0xfca622c: {
              //not readable
              break;
          }
          case 0x436dd94: {
              //not readable
              break;
          }
          case 0x134fdb0: {
              //not readable
              break;
          }
          case 0xeb0420c: {
              //not readable
              break;
          }
          case 0xd75007e: {
              //not readable
              break;
          }
          case 0xf4e0097: {
              //not readable
              break;
          }
          case 0x8ce790d: {
              //not readable
              break;
          }
          case 0x997e20e: {
              //simpleType:uint
              pLabel = "HDAT_RSV_MEM_NUM_SECTIONS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xc6dfefe: {
              //simpleType:uint
              pLabel = "HDAT_HBRT_NUM_SECTIONS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd0167e2: {
              //simpleType:uint
              pLabel = "HDAT_HBRT_SECTION_SIZE";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[9]:");
              l_traceEntry.resize(10+offset + 9 * 19);
              for (uint32_t i = 0;i<9;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 9 * sizeof(uint64_t);
              break;
          }
          case 0x4baf80d: {
              //simpleType:uint
              pLabel = "WOF_POWER_LIMIT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2e5f49c: {
              //not readable
              break;
          }
          case 0xf70279f: {
              //not readable
              break;
          }
          case 0xc8c49e7: {
              //not readable
              break;
          }
          case 0xa40efa1: {
              //not readable
              break;
          }
          case 0xfaa68ab: {
              //simpleType:uint
              pLabel = "TOD_CPU_DATA";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[44]:");
              l_traceEntry.resize(10+offset + 44 * 5);
              for (uint32_t i = 0;i<44;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 44 * sizeof(uint8_t);
              break;
          }
          case 0xbc55176: {
              //not readable
              break;
          }
          case 0x4b839c0: {
              //not readable
              break;
          }
          case 0xdab5f58: {
              //not readable
              break;
          }
          case 0xe2df671: {
              //simpleType:uint
              pLabel = "ORDINAL_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x84a4edb: {
              break;
          }
          case 0x9fb4db6: {
              //not readable
              break;
          }
          case 0xf9e2621: {
              //not readable
              break;
          }
          case 0x30c07c8: {
              //simpleType:uint
              pLabel = "PNOR_FLASH_WORKAROUNDS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
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
          case 0xad3e4fe: {
              //not readable
              break;
          }
          case 0x9b7099c: {
              //not readable
              break;
          }
          case 0x78c64c6: {
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
          case 0xc794239: {
              //not readable
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
          case 0xe926ea8: {
              //simpleType:uint
              pLabel = "SBE_IS_STARTED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x6a258b6: {
              //not readable
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
          case 0xd837641: {
              //not readable
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
          case 0xa3dc291: {
              //simpleType:uint
              pLabel = "FREQ_CORE_CEILING_MHZ";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x49f38fe: {
              //simpleType:uint
              pLabel = "PG";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0x96f8bd3: {
              //simpleType:uint
              pLabel = "SECUREBOOT_PROTECT_DECONFIGURED_TPM";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x4d8df8d: {
              //simpleType:uint
              pLabel = "PROC_PCIE_PCS_SYSTEM_CNTL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 7);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*7]), "0x%.4X ", ntohs(*(((uint16_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint16_t);
              break;
          }
          case 0x2b23c7c: {
              //not readable
              break;
          }
          case 0xe2cfa5e: {
              //simpleType:uint
              pLabel = "PROC_PCIE_REFCLOCK_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
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
          case 0x48a8902: {
              //simpleType:uint
              pLabel = "PROC_PCIE_IOVALID_ENABLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
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
          case 0x706e27b: {
              //not readable
              break;
          }
          case 0x30c46b3: {
              //not readable
              break;
          }
          case 0x8135b05: {
              //simpleType:enum
              pLabel = "KEY_TRANSITION_STATE";
              switch (*l_ptr) {
                  case 0x00000000: {
                      sprintf(&(l_traceEntry[0]), "KEY_TRANSITION_STATE_KEY_TRANSITION_NOT_REQUESTED");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  case 0x00000001: {
                      sprintf(&(l_traceEntry[0]), "KEY_TRANSITION_STATE_KEY_TRANSITION_STARTED");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  case 0x00000002: {
                      sprintf(&(l_traceEntry[0]), "KEY_TRANSITION_STATE_KEY_TRANSITION_FAILED");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  case 0x00000003: {
                      sprintf(&(l_traceEntry[0]), "KEY_TRANSITION_STATE_KEY_TRANSITION_SUCCEEDED");
                      l_ptr += sizeof(uint32_t);
                      break;
                  }
                  default: break;
              }
              break;
          }
          case 0xc7d9261: {
              //simpleType:uint
              pLabel = "FUSED_CORE_MODE_HB";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe2ab0d2: {
              //simpleType:uint
              pLabel = "SOCKET_POWER_NOMINAL";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x8949e92: {
              //simpleType:uint
              pLabel = "SOCKET_POWER_TURBO";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xe1b47d7: {
              //simpleType:uint
              pLabel = "WOF_TABLE_LID_NUMBER";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x2b8d151: {
              //not readable
              break;
          }
          case 0xa10bfc8: {
              //not readable
              break;
          }
          case 0xc4fcb9a: {
              //not readable
              break;
          }
          case 0xf2039e4: {
              //not readable
              break;
          }
          case 0xb67f259: {
              //not readable
              break;
          }
          case 0x837b78a: {
              //not readable
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
          case 0x350d093: {
              //not readable
              break;
          }
          case 0x020df55: {
              //not readable
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
          case 0x13326ac: {
              //simpleType:uint
              pLabel = "MSS_PHY_SEQ_REFRESH";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[2]:");
              l_traceEntry.resize(10+offset + 2 * 5);
              for (uint32_t i = 0;i<2;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 2 * sizeof(uint8_t);
              break;
          }
          case 0x38a7b13: {
              //simpleType:uint
              pLabel = "PRD_HWP_PLID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x5ef37d7: {
              //not readable
              break;
          }
          case 0x51cc341: {
              //not readable
              break;
          }
          case 0xb312257: {
              //not readable
              break;
          }
          case 0x9487ddb: {
              //not readable
              break;
          }
          case 0xe242d68: {
              //not readable
              break;
          }
          case 0x7e1fa3b: {
              //not readable
              break;
          }
          case 0x6a00c9c: {
              //not readable
              break;
          }
          case 0xce01813: {
              //not readable
              break;
          }
          case 0x7f829da: {
              //not readable
              break;
          }
          case 0x22d9035: {
              //not readable
              break;
          }
          case 0x935d008: {
              //not readable
              break;
          }
          case 0x2d9433b: {
              //not readable
              break;
          }
          case 0xc610fe3: {
              //not readable
              break;
          }
          case 0xb257082: {
              //not readable
              break;
          }
          case 0x97c0210: {
              //not readable
              break;
          }
          case 0x0ddfd25: {
              //not readable
              break;
          }
          case 0xaac24d5: {
              //not readable
              break;
          }
          case 0x0ca8faf: {
              //not readable
              break;
          }
          case 0x7da144e: {
              //not readable
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
          case 0xb2af6a0: {
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
          case 0x8218c38: {
              //not readable
              break;
          }
          case 0xc8bfded: {
              //not readable
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
          case 0x7b7504f: {
              //not readable
              break;
          }
          case 0x6a49991: {
              //not readable
              break;
          }
          case 0x13f6c19: {
              //not readable
              break;
          }
          case 0xae3040d: {
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
          case 0xa71e033: {
              //not readable
              break;
          }
          case 0xb43f2fe: {
              //simpleType:uint
              pLabel = "MC_PLL_BUCKET";
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
          case 0xbde3ab9: {
              //not readable
              break;
          }
          case 0x8944726: {
              //simpleType:uint
              pLabel = "TCE_START_TOKEN_FOR_PAYLOAD";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x8dfa6d6: {
              //simpleType:uint
              pLabel = "START_MEM_ADDRESS_FOR_PAYLOAD_TCE_TOKEN";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x4194918: {
              //simpleType:uint
              pLabel = "TCE_START_TOKEN_FOR_HDAT";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0x6adbf88: {
              //not readable
              break;
          }
          case 0x27e9c32: {
              //simpleType:uint
              pLabel = "CHKSTOP_ANALYSIS_ON_STARTUP";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
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
          case 0x4f42b20: {
              //simpleType:uint
              pLabel = "IS_SLAVE_DRAWER";
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
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[4][4]:");
              l_traceEntry.resize(10+offset + 16 * 5);
              for (uint32_t i = 0;i<16;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 16 * sizeof(uint8_t);
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
          case 0x7329dbe: {
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
          case 0x3aecc94: {
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
          case 0xf888d7a: {
              //simpleType:uint
              pLabel = "HOMER_HCODE_LOADED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe5c8589: {
              //simpleType:uint
              pLabel = "SBE_FFDC_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x1232b64: {
              //simpleType:uint
              pLabel = "SBE_COMM_ADDR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
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
          case 0x21a3945: {
              //complexType - skipping
              break;
          }
          case 0x09d23f6: {
              //simpleType:uint
              pLabel = "SPCWKUP_COUNT";
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
          case 0x891d6d1: {
              //simpleType:uint
              pLabel = "HBRT_HYP_ID";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xf0904ee: {
              //simpleType:uint
              pLabel = "IS_DRTM_MPIPL_HB";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xe67411b: {
              //simpleType:uint
              pLabel = "DRTM_PAYLOAD_ADDR_MB_HB";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 11);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint32_t);
              break;
          }
          case 0xd794c33: {
              //not readable
              break;
          }
          case 0x02fea82: {
              //simpleType:uint
              pLabel = "ATTN_CHK_ALL_PROCS";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x73b59bc: {
              //simpleType:uint
              pLabel = "MASTER_MBOX_SCRATCH";
              uint32_t offset = sprintf(&(l_traceEntry[0]), "[8]:");
              l_traceEntry.resize(10+offset + 8 * 11);
              for (uint32_t i = 0;i<8;i++) {
                  sprintf(&(l_traceEntry[offset+i*11]), "0x%.8X ", ntohl(*(((uint32_t *)l_ptr)+i)));
              }
              l_ptr += 8 * sizeof(uint32_t);
              break;
          }
          case 0x5a32695: {
              //simpleType:uint
              pLabel = "HB_RSV_MEM_NEXT_SECTION";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xcacfa03: {
              //simpleType:uint
              pLabel = "HB_TPM_INIT_ATTEMPTED";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xb8fa011: {
              //simpleType:uint
              pLabel = "TPM_ROLE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0xeaece7d: {
              //not readable
              break;
          }
          case 0x4af8455: {
              //simpleType:uint
              pLabel = "HB_TPM_LOG_MGR_PTR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0xf322cf5: {
              //simpleType:uint
              pLabel = "ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 5);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*5]), "0x%.2X ", *(((uint8_t *)l_ptr)+i));
              }
              l_ptr += 1 * sizeof(uint8_t);
              break;
          }
          case 0x2c95fa5: {
              //simpleType:uint
              pLabel = "MEMD_OFFSET";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
              break;
          }
          case 0x71bd6c8: {
              //simpleType:uint
              pLabel = "CENTAUR_REGISTER_CACHE_PTR";
              uint32_t offset = 0;
              l_traceEntry.resize(10+offset + 1 * 19);
              for (uint32_t i = 0;i<1;i++) {
                  sprintf(&(l_traceEntry[offset+i*19]), "0x%.16llX ", ntohll(*(((uint64_t *)l_ptr)+i)));
              }
              l_ptr += 1 * sizeof(uint64_t);
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
