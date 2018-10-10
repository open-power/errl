#ifndef _EPUB_SERVICE_CODES_H
#define _EPUB_SERVICE_CODES_H

//-----------------------------------------------------------------------
// SUBSYSTEM ------------------------------------------------------------
//-----------------------------------------------------------------------

    /** @enum epubSubSystem
     *  This enumeration contains all the Sub-System codes used in the SRCs to
     *  indicate what subsystem was in error or is associated with the event.
     *
     *  INSTRUCTIONS FOR ADDING SUBSYSTEM IDs
     *
     *  1.  This is the value in the second byte of the hex string in the
     *      ASCII field. For instance, B1XXYYYY, XX is the Subsystem value.
     *      Additions to this field must be approved by architecture.
     */
enum epubSubSystem
{
    EPUB_RESERVED_0 = 0x00,

    // Processor subsystem
    EPUB_PROCESSOR_SUBSYS     = 0x10,
    EPUB_PROCESSOR_FRU        = 0x11,
    EPUB_PROCESSOR_CHIP_CACHE = 0x12,
    EPUB_PROCESSOR_UNIT       = 0x13,
    EPUB_PROCESSOR_BUS_CTL    = 0x14,

    // Memory subsystem
    EPUB_MEMORY_SUBSYS     = 0x20,
    EPUB_MEMORY_CONTROLLER = 0x21,
    EPUB_MEMORY_BUS        = 0x22,
    EPUB_MEMORY_DIMM       = 0x23,
    EPUB_MEMORY_FRU        = 0x24,
    EPUB_EXTERNAL_CACHE    = 0x25,

    // I/O subsystem: hub and bridge
    EPUB_IO_SUBSYS               = 0x30,
    EPUB_IO_HUB                  = 0x31,
    EPUB_IO_BRIDGE               = 0x32,
    EPUB_IO_BUS_INTF             = 0x33,
    EPUB_IO_PROCESSOR            = 0x34,
    EPUB_IO_SMA_HUB              = 0x35,
    EPUB_IO_RIO_LOOP_WITH_HUB    = 0x36,
    EPUB_IO_RIO_LOOP_WITH_BRIDGE = 0x37,
    EPUB_IO_PHB                  = 0x38,
    EPUB_IO_EADS_SUBSYS          = 0x39,
    EPUB_IO_EADS_SLOT            = 0x3A,
    EPUB_IO_INFINIBAND_HUB       = 0x3B,
    EPUB_IO_INFINIBAND_BRIDGE    = 0x3C,

    // I/O Adapter, Device, and Peripheral
    EPUB_IO_ADAPTER_SUBSYS     = 0x40,
    EPUB_IO_ADAPTER_COMM       = 0x41,
    EPUB_IO_DEVICE_SUBSYS      = 0x46,
    EPUB_IO_DEVICE_DASD        = 0x47,
    EPUB_IO_EXT_PERIPH_SUBSYS  = 0x4C,
    EPUB_IO_EXT_PERIPH_LCLWKST = 0x4D,
    EPUB_IO_MEZZA_EXP_SUBSYS   = 0x4E,                                          //gb13

    // CEC Hardware
    EPUB_CEC_HDW_SUBSYS       = 0x50,
    EPUB_CEC_HDW_SRV_PROC_A   = 0x51,
    EPUB_CEC_HDW_SRV_PROC_B   = 0x52,
    EPUB_CEC_HDW_NODE_CTLR    = 0x53,
    EPUB_CEC_HDW_VPD_INTF     = 0x55,
    EPUB_CEC_HDW_I2C_DEVS     = 0x56,
    EPUB_CEC_HDW_JTAG         = 0x57,
    EPUB_CEC_HDW_CHIP_INTF    = 0x57,  // includes JTAG, FSI, etc.
    EPUB_CEC_HDW_CLK_CTL      = 0x58,
    EPUB_CEC_HDW_OP_PANEL     = 0x59,
    EPUB_CEC_HDW_TOD_HDW      = 0x5A,
    EPUB_CEC_HDW_SRV_PROC_MEM = 0x5B,
    EPUB_CEC_HDW_SP_PHYP_INTF = 0x5C,
    EPUB_CEC_HDW_SERV_NETWORK = 0x5D,
    EPUB_CEC_HDW_RFSP         = 0x5E,

    // Power/Cooling subsystem and control
    EPUB_POWER_SUBSYS  = 0x60,
    EPUB_POWER_SUPPLY  = 0x61,
    EPUB_POWER_CTL_HDW = 0x62,
    EPUB_POWER_FAN     = 0x63,

    // Others
    EPUB_MISC_SUBSYS                           = 0x70,
    EPUB_MISC_HMC_HDW                          = 0x71,
    EPUB_MISC_TEST_TOOL                        = 0x72,
    EPUB_MISC_REM_MEDIA                        = 0x73,
    EPUB_MISC_MULTIPLE_SUBSYS                  = 0x74,
    EPUB_MISC_UNKNOWN                          = 0x75,
    EPUB_MISC_INFORMATIONAL                    = 0x76,
    EPUB_MISC_SURV_ERR_PHYP_LOST_COMM_SP       = 0x7A,
    EPUB_MISC_SURV_ERR_SP_LOST_COMM_PHYP       = 0x7B,
    EPUB_MISC_SURV_ERR_SP_LOST_COMM_HMC        = 0x7C,
    EPUB_MISC_SURV_ERR_HMC_LOST_COMM_PARTITION = 0x7D,
    EPUB_MISC_SURV_ERR_HMC_LOST_COMM_BPA       = 0x7E,
    EPUB_MISC_SURV_ERR_HMC_LOST_COMM_OTHER_HMC = 0x7F,

    // Platform Firmware
    EPUB_FIRMWARE_SUBSYS     = 0x80,
    EPUB_FIRMWARE_SP         = 0x81,
    EPUB_FIRMWARE_PHYP       = 0x82,
    EPUB_FIRMWARE_PARTITION  = 0x83,
    EPUB_FIRMWARE_SLIC       = 0x84,
    EPUB_FIRMWARE_SPCN       = 0x85,
    EPUB_FIRMWARE_BULK_PWR   = 0x86,
    EPUB_FIRMWARE_HMC        = 0x87,
    EPUB_FIRMWARE_BULK_PWR_B = 0x88,
    EPUB_FIRMWARE_VIRTUAL_SP = 0x89,

    // Software
    EPUB_SOFTWARE_SUBSYS = 0x90,
    EPUB_SOFTWARE_OS     = 0x91,
    EPUB_SOFTWARE_XPF    = 0x92,
    EPUB_SOFTWARE_APPS   = 0x93,

    // External Environment
    EPUB_EXT_ENVIRO_SUBSYS = 0xA0,
    EPUB_EXT_ENVIRO_AC_PWR = 0xA1,
    EPUB_EXT_ENVIRO_TEMP   = 0xA2,
    EPUB_EXT_ENVIRO_USER   = 0xA3,

    EPUB_FIRMWARE_HOSTBOOT = 0x8A,                      //mi12
    EPUB_FIRMWARE_OCC      = 0x8B,                      //mi12
    EPUB_FIRMWARE_DPSS     = 0x8C,                      //ri02

};
#endif
