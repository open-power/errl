// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/occc/fsp/plugins/occcDataParse.H 1.4 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2013,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/**
 *  @page ChangeLogs Change Logs
 *  @section OCCCDATAPARSE_H occcDataParse.H
 *  @verbatim
 *
 *  Flag    PTR/DCR#   Userid    Date        Description
 *  ------- ---------- --------  --------    --------------------------------------
 *  @jh00c  915009     joshych   02/07/2014  Update parser for OCC call-home data
 *
 *  @endverbatim
*/

//************************************************************************* 
// Includes 
//************************************************************************* 
 
//************************************************************************* 
// Externs 
//************************************************************************* 
 
//************************************************************************* 
// Macros 
//************************************************************************* 
 
//************************************************************************* 
// Defines/Enums 
//************************************************************************* 
#define MAX_APSS_ADC_CHANNELS       16
#define CHOM_MAX_OCCS               4
#define MAX_NUM_ERRH_ENTRIES        4

// Call home log data versions
enum
{
    CHOMLOGDATA_VER_0,
    CHOMLOGDATA_VER_1,
    CHOMLOGDATA_VER_2
};
// List of call home sensors from chom.h,occ810 @jh00ca

namespace VER_0
{
enum
{
    /* Node total power (DC) */
    CHOMPWR                = 0,
    /* Socket power */ // @jh007c
    CHOMPWRS0,
    CHOMPWRS1,
    CHOMPWRS2,
    CHOMPWRS3,
    CHOMPWRS4,
    CHOMPWRS5,
    CHOMPWRS6,
    CHOMPWRS7,
    /* Memory power */
    CHOMPWRM0,
    CHOMPWRM1,
    CHOMPWRM2,
    CHOMPWRM3,
    CHOMPWRM4,
    CHOMPWRM5,
    CHOMPWRM6,
    CHOMPWRM7,
    /* Fan power */
    CHOMPWRFAN, // @jh007a
    /* Processor frequency */
    CHOMFREQP0,
    CHOMFREQP1,
    CHOMFREQP2,
    CHOMFREQP3,
    CHOMFREQP4,
    CHOMFREQP5,
    CHOMFREQP6,
    CHOMFREQP7,
    /* Processor utilization sensor */
    CHOMUTILP0,
    CHOMUTILP1,
    CHOMUTILP2,
    CHOMUTILP3,
    CHOMUTILP4,
    CHOMUTILP5,
    CHOMUTILP6,
    CHOMUTILP7,
    /* Max core temperature for all processors in the node */
    CHOMTEMPPROC,
    /* Max Centaur temperature for all Centaurs in the node */
    CHOMTEMPCENT,
    /* Max Dimm temperature for all Dimms in the node */
    CHOMTEMPDIMM,
    /* Instructions per second sensor */
    CHOMIPS,
    /* Memory bandwidth for process memory controller */
    CHOMBWP0M0,
    CHOMBWP0M1,
    CHOMBWP0M2,
    CHOMBWP0M3,
    CHOMBWP0M4,
    CHOMBWP0M5,
    CHOMBWP0M6,
    CHOMBWP0M7,
    CHOMBWP1M0,
    CHOMBWP1M1,
    CHOMBWP1M2,
    CHOMBWP1M3,
    CHOMBWP1M4,
    CHOMBWP1M5,
    CHOMBWP1M6,
    CHOMBWP1M7,
    CHOMBWP2M0,
    CHOMBWP2M1,
    CHOMBWP2M2,
    CHOMBWP2M3,
    CHOMBWP2M4,
    CHOMBWP2M5,
    CHOMBWP2M6,
    CHOMBWP2M7,
    CHOMBWP3M0,
    CHOMBWP3M1,
    CHOMBWP3M2,
    CHOMBWP3M3,
    CHOMBWP3M4,
    CHOMBWP3M5,
    CHOMBWP3M6,
    CHOMBWP3M7,
    CHOMBWP4M0,
    CHOMBWP4M1,
    CHOMBWP4M2,
    CHOMBWP4M3,
    CHOMBWP4M4,
    CHOMBWP4M5,
    CHOMBWP4M6,
    CHOMBWP4M7,
    CHOMBWP5M0,
    CHOMBWP5M1,
    CHOMBWP5M2,
    CHOMBWP5M3,
    CHOMBWP5M4,
    CHOMBWP5M5,
    CHOMBWP5M6,
    CHOMBWP5M7,
    CHOMBWP6M0,
    CHOMBWP6M1,
    CHOMBWP6M2,
    CHOMBWP6M3,
    CHOMBWP6M4,
    CHOMBWP6M5,
    CHOMBWP6M6,
    CHOMBWP6M7,
    CHOMBWP7M0,
    CHOMBWP7M1,
    CHOMBWP7M2,
    CHOMBWP7M3,
    CHOMBWP7M4,
    CHOMBWP7M5,
    CHOMBWP7M6,
    CHOMBWP7M7,

    /* The number of chom sensors reported*/
    CHOM_NUM_OF_SENSORS
};
};

namespace VER_1
{
enum
{
    /* Node total power (DC) */
    CHOMPWR                = 0,
    CHOMPWRAPSSCH0,
    CHOMPWRAPSSCH1,
    CHOMPWRAPSSCH2,
    CHOMPWRAPSSCH3,
    CHOMPWRAPSSCH4,
    CHOMPWRAPSSCH5,
    CHOMPWRAPSSCH6,
    CHOMPWRAPSSCH7,
    CHOMPWRAPSSCH8,
    CHOMPWRAPSSCH9,
    CHOMPWRAPSSCH10,
    CHOMPWRAPSSCH11,
    CHOMPWRAPSSCH12,
    CHOMPWRAPSSCH13,
    CHOMPWRAPSSCH14,
    CHOMPWRAPSSCH15,
    /* Processor frequency */
    CHOMFREQP0,
    CHOMFREQP1,
    CHOMFREQP2,
    CHOMFREQP3,
    /* Processor utilization sensor */
    CHOMUTILP0,
    CHOMUTILP1,
    CHOMUTILP2,
    CHOMUTILP3,
    /* Proc temperatures across all nodes */
    CHOMTEMPPROC0,
    CHOMTEMPPROC1,
    CHOMTEMPPROC2,
    CHOMTEMPPROC3,
    /* Centaur temperatures for all nodes */
    CHOMTEMPCENTP0,
    CHOMTEMPCENTP1,
    CHOMTEMPCENTP2,
    CHOMTEMPCENTP3,
    /* Max Dimm temperature for all Dimms in node */
    CHOMTEMPDIMMP0,
    CHOMTEMPDIMMP1,
    CHOMTEMPDIMMP2,
    CHOMTEMPDIMMP3,
    /* VRM VDD temperature per proc */
    CHOMTEMPVDDP0,
    CHOMTEMPVDDP1,
    CHOMTEMPVDDP2,
    CHOMTEMPVDDP3,
    /* Instructions per second sensor */
    CHOMIPS,
    /* Memory bandwidth for process memory controller */
    CHOMBWP0M0,
    CHOMBWP0M1,
    CHOMBWP0M2,
    CHOMBWP0M3,
    CHOMBWP0M4,
    CHOMBWP0M5,
    CHOMBWP0M6,
    CHOMBWP0M7,
    CHOMBWP1M0,
    CHOMBWP1M1,
    CHOMBWP1M2,
    CHOMBWP1M3,
    CHOMBWP1M4,
    CHOMBWP1M5,
    CHOMBWP1M6,
    CHOMBWP1M7,
    CHOMBWP2M0,
    CHOMBWP2M1,
    CHOMBWP2M2,
    CHOMBWP2M3,
    CHOMBWP2M4,
    CHOMBWP2M5,
    CHOMBWP2M6,
    CHOMBWP2M7,
    CHOMBWP3M0,
    CHOMBWP3M1,
    CHOMBWP3M2,
    CHOMBWP3M3,
    CHOMBWP3M4,
    CHOMBWP3M5,
    CHOMBWP3M6,
    CHOMBWP3M7,
    /* The number of chom sensors reported*/
    CHOM_NUM_OF_SENSORS
};
};

#define MAX_OCCS 8 // @jh00ca

// @jh00ca
/* Call home sensor Structure */
struct ChomSensor
{
    uint16_t    sample;           // last sample value during the polling period
    uint16_t    sampleMin;        // min sample value recorded during polling period
    uint16_t    sampleMax;        // max sample value recorded during polling period
    uint16_t    average;          // average sample value during polling period
    uint32_t    accumulator;      // accumulator register to computer the average
} __attribute__ ((__packed__));

typedef struct ChomSensor ChomSensor_t;

// Error history data structure
typedef struct __attribute__ ((packed))
{
    uint8_t error_id;
    uint8_t error_count;
} error_history_count_t;
// CPI data structure
struct ChomCpiData
{
    uint8_t     proc;
    uint32_t    cpi;
}__attribute__ ((__packed__));

typedef struct ChomCpiData ChomCpiData_t;

/* Power mode structure */
struct ChomPwrMode
{
    uint8_t     mode;            // OCC power mode
    uint32_t    numOfSamples;    // Number of times samples were polled while in this mode
}__attribute__ ((__packed__));

typedef struct ChomPwrMode ChomPwrMode_t;


/* Call home data Structure version 1 */
struct ChomNodeData_v0
{
    uint32_t       eyecatcher;                               // "CHOM" will mark the beginning of the data
    uint8_t        version;                                  // version of call home data being reported
    uint8_t        curPwrMode;                               // the current power mode at the time of the polling event
    uint32_t       totalTime;                                // duration of the polling period
    uint8_t        modeInLog;                                // the number of different power mode in the polling period
    ChomCpiData_t  cpiData[MAX_OCCS];                        // Chip Packing Interface data, 5 bytes per processor
    uint16_t       numSensors;                               // the number of sensors for which call home data was collected
} __attribute__ ((__packed__));

typedef struct ChomNodeData_v0 ChomNodeData_v0_t;

/* Call home data Structure version 1 */
struct ChomNodeData_v1
{
    uint32_t       eyecatcher;                               // "CHOM" will mark the beginning of the data
    uint8_t        version;                                  // version of call home data being reported
    uint8_t        curPwrMode;                               // the current power mode at the time of the polling event
    uint32_t       totalTime;                                // duration of the polling period
    uint8_t        modeInLog;                                // the number of different power mode in the polling period
    uint8_t        channelFuncIds[MAX_APSS_ADC_CHANNELS];    // the function IDs corresponding to the APSS channels
    uint16_t       numSensors;                               // the number of sensors for which call home data was collected
    error_history_count_t errhCounts[CHOM_MAX_OCCS-1][MAX_NUM_ERRH_ENTRIES];
} __attribute__ ((__packed__));
typedef struct ChomNodeData_v1 ChomNodeData_v1_t;

/* Call home data Structure version 2 */
struct ChomNodeData_v2
{
    uint32_t       eyecatcher;                               // "CHOM" will mark the beginning of the data
    uint8_t        version;                                  // version of call home data being reported
    uint8_t        curPwrMode;                               // the current power mode at the time of the polling event
    uint32_t       totalTime;                                // duration of the polling period
    uint8_t        modeInLog;                                // the number of different power mode in the polling period
    uint8_t        channelFuncIds[MAX_APSS_ADC_CHANNELS];    // the function IDs corresponding to the APSS channels
    uint16_t       numSensors;                               // the number of sensors for which call home data was collected
    error_history_count_t errhCounts[CHOM_MAX_OCCS-1][MAX_NUM_ERRH_ENTRIES];
    uint32_t       fClipHist[CHOM_MAX_OCCS-1];
} __attribute__ ((__packed__));
typedef struct ChomNodeData_v2 ChomNodeData_v2_t;

/* Call home sensor data */
struct ChomSensorData_v0
{
    ChomPwrMode_t   pwrMode;
    ChomSensor_t    sensor[VER_0::CHOM_NUM_OF_SENSORS];
}__attribute__ ((__packed__));

typedef struct ChomSensorData_v0 ChomSensorData_v0_t;

struct ChomSensorData_v1
{
    ChomPwrMode_t   pwrMode;
    ChomSensor_t    sensor[VER_1::CHOM_NUM_OF_SENSORS];
}__attribute__ ((__packed__));

typedef struct ChomSensorData_v1 ChomSensorData_v1_t;

// No new Sensors were added in v2, so re-use v1 struct
typedef struct ChomSensorData_v1 ChomSensorData_v2_t;

/* Call home log data version 0*/
struct ChomLogData_v0
{
    ChomNodeData_v0_t    nodeData;      // general node data
    ChomSensorData_v0_t  sensorData[2]; // sensors data (current and previous power mode)
}__attribute__ ((__packed__));

typedef struct ChomLogData_v0 ChomLogData_v0_t;

/* Call home log data version 1*/
struct ChomLogData_v1
{
    ChomNodeData_v1_t    nodeData;      // general node data
    ChomSensorData_v1_t  sensorData[2]; // sensors data (current and previous power mode)
}__attribute__ ((__packed__));

typedef struct ChomLogData_v1 ChomLogData_v1_t;

/* Call home log data version 2*/
struct ChomLogData_v2
{
    ChomNodeData_v2_t    nodeData;      // general node data
    ChomSensorData_v2_t  sensorData[2]; // sensors data (current and previous power mode)
}__attribute__ ((__packed__));

typedef struct ChomLogData_v2 ChomLogData_v2_t;

//************************************************************************* 
// Globals 
//************************************************************************* 
 
//************************************************************************* 
// Function Prototypes 
//************************************************************************* 
 
//************************************************************************* 
// Functions 
//************************************************************************* 
