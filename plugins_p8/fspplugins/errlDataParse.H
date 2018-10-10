// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/errl/fsp/plugins/errlDataParse.H 1.1 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2003,2014 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
#ifndef _ERRL_DATAPARSE_H
#define _ERRL_DATAPARSE_H

// Change Log **********************************************************
//
//  Flag  Track     Userid    Date      Description
//  ----  --------  --------  --------  -----------
//  fk01  D923085   fmkassem  04/23/14  Created.
//
// End Change Log ******************************************************


// History file constants
#define CORR_TWO_HOUR_READING_TBL_SIZE	18	// 1.5 days worth
#define CORR_DAILY_READING_TBL_SIZE	28	// 4 weeks worth
#define CORR_WEEKLY_READING_TBL_SIZE	260	// 5 years worth
#define CORR_MAX_FILENAME_SIZE		128

// Calculation constants
#define CORR_TEMP_MULTIPLER		.0625   // Sensitivity of TMP275 temp sensor 

//
// Since customer is unaware of the corrosion sensor card, device errors on the card are stored as special values
// in the corrosion log data (temperature field).
//
// Error values - when adding new errors update CORR_DEVICE_ERROR
#define CORR_TEMPERATURE_DEVICE_ERROR	0xFFFC	// Device error reading temperature
#define CORR_SEEPROM_DEVICE_ERROR	0xFFFD	// Device error reading/writing seeprom
#define CORR_CORROSION_DEVICE_ERROR	0xFFFE	// Device error reading corrosion sensor
#define CORR_SENSOR_END_OF_LIFE		0xFFFF	// Corrosion sensor has reached end of life resistance
#define CORR_DEVICE_ERROR		CORR_TEMPERATURE_DEVICE_ERROR	// Lowest device error value

// Corrosion reading data

struct corrosionData_t
{
    uint32_t timestamp;			// offset 0x0000 -- UTC data/time
    float    resistance;			// offset 0x0004 -- Normalized resistance reading
    uint16_t temperature;		// offset 0x0008 -- Ambient temperature
    union {
    	uint16_t thicknessConsumed;	// offset 0x000A -- Thickness consumed -- 2 hr readings
    	uint16_t corrosionRate;		// offset 0x000A -- Corrosion rate -- daily & weekly averages
    };
};

struct corrosionDataHeader_t
{
    uint16_t dataLayoutVersion;			// Version number of data layout
    uint16_t unused1;				// Not used
    uint16_t unused2;				// Not used
    BCD_time8_t initialTimestamp;		// Genesis timestamp from original card 
    uint16_t thicknessConsumedPrevCards;	// Thickness consumed on previous cards (0 if original card)
    corrosionData_t	initialReading;		// Initial reading from current card
};

struct corrosionHistoryFile_t
{
    corrosionDataHeader_t	header;					// Header
    corrosionData_t	twoHourReadings[CORR_TWO_HOUR_READING_TBL_SIZE]; // 2 hour reading section 
    corrosionData_t	dailyAverages[CORR_DAILY_READING_TBL_SIZE];	// Daily reading section
    corrosionData_t	weeklyAverages[CORR_WEEKLY_READING_TBL_SIZE];	// Weekly reading section
};

struct corrosionReadings_t
{
    uint32_t	timestamp;			// date/time of reading
    uint16_t	tempRawReading;			// Raw reading from temp sensor
    uint16_t	corrReadAttempts;		// Number of read attempts to get 20 valid
    uint32_t    corrRawReadings[20];		// Raw readings from corr sensor
};


#endif // _ERRL_DATAPARSE_H
