#ifndef __HBFW_TERM_RC_H
#define __HBFW_TERM_RC_H

namespace HBFW
{

namespace SBE
{
    enum sbeReasonCode
    {
        SBE_UPDATE_REQUEST_REIPL = 0x220C,
    };
};

namespace HWAS
{
    enum HwasReasonCode
    {
        RC_SYSAVAIL_INSUFFICIENT_HW = 0xC04,
    };
};

namespace INTR
{
    enum IntrReasonCode
    {
        RC_PERSISTENT_INTERRUPTS = 0xF06,
    };
};

namespace INITSERVICE
{
    enum    InitServiceReasonCode
    {
        ISTEP_FAILED_DUE_TO_DECONFIG = 0x50a,
        SHUTDOWN_REQUESTED_BY_FSP = 0x50b,
        SBE_EXTRACT_RC_REQUEST_REIPL = 0x50e,
        SHUTDOWN_NOT_RECONFIG_LOOP = 0x510,
    };
};

namespace PNOR
{
    enum PNORReasonCode
    {
        RC_UNSUPPORTED_HARDWARE = 0x60A,
        RC_PARTITION_TABLE_INVALID = 0x60C,
        RC_UNSUPPORTED_MODE = 0x60D,
        RC_UNSUPPORTED_SFCRANGE = 0x60E,
        RC_ECC_UE = 0x60F,
        RC_REINITIALIZE_SFC = 0x611,
        RC_PNOR_INIT_FAILURE = 0x613,
        RC_PARTITION_TABLE_NOT_FOUND = 0x624,
        RC_PARTITION_TABLE_CORRUPTED = 0x625,
        RC_FINDTOC_FAILED = 0x626,
        RC_INVALID_WORKING_TOC = 0x628,
        RC_PNOR_CORRUPTION = 0x699,
    };
};

};
#endif
