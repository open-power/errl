/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlparser.H>
#include <errlhashtables.H> 
#include <errlusrparser.H>
#include <rtim.H>

#include <errlbase.H>
#include <errlutility.H>

#include <cstdarg>

#include <cstring>
#include <ctype.h>
#include <cstdlib>


///< Maximum displayable characters
static const int    LINE_WIDTH = 78;


struct ProcedureMap{
char ProcName[10];
char Description[500];
};

ProcedureMap errlProcMap[100]=
{
{   "FSPSP01",
        "A part vital to the system has been deconfigured." },
{   "FSPSP02",
        "This procedure is for boot failures that terminate very early "
        "in the boot process.  This error path is indicated when the SRC "
        "data words are scrolling automatically through operator panel "
        "functions 11, 12, and 13, and the operator panel interface "
        "buttons are not responsive." },
{   "FSPSP03",
        "System operator error or user error. Refer to the documentation "
        "of the function you were attempting to perform. " },
{   "FSPSP04",
        "A problem has been detected in the Service Processor firmware "
        "by the Service Processor." },
{   "FSPSP05",
        "A problem has been detected in Platform firmware by the Service "
        "Processor." },
{   "FSPSP06",
        "The Service Processor reported a suspected intermittent problem.  "
        "Contact the next level of support." },
{   "FSPSP07",
        "Lost the Time of Day(TOD).  The Time of Day has been reset to the "
        "default value.  To set the Time of Day -refer to ASM or HMC." },
{   "FSPSP08",
        "A problem has been detected with a System Processor.  However, the "
        "Service Processor is unable to isolate it to a specific System "
        "Processor." },
{   "FSPSP09",
        "A problem has been detected with a Memory DIMM.  However, the "
        "Service Processor is unable to isolate it to a specific Memory "
        "DIMM." },
{   "FSPSP10",
        "The part indicated in the FRU callout that follows this procedure "
        "is invalid or missing for this system's configuration." },
{   "FSPSP14",
        "Communication has been lost between the Service Processor and PHYP."
        "Please wait 40 minutes to allow the system to resolve the problem."
        "PHYP should time out and the FSP will just let the system run." },
{   "FSPSP16",
        "Contact your next level of support for assistance.  If possible, "
        "save all error log and dump data." },
{   "FSPSP17",
        "A System Uncorrectable Error(SUE) has been detected by the system."},
{   "FSPSP18",
        "A Problem has been detected in the Service Processor firmware "
        "by the Service Processor." },
{   "FSPSP23",
        "The system needs to perform a Service Processor dump." }, 
{   "FSPSP27",
        "An Attention Line has been detected as having a problem." },
{   "FSPSP28",
        "The Resource Id (RID) of the FRU could not be found in the Vital Product "
        "Data (VPD) table." },
{   "FSPSP30",
        "A problem hsa been encountered accessing the VPD card or the data found "
        "on the VPD card has been corrupted.  This error occurred before VPD "
        "collection was completed, so no location codes have been created." },
{   "FSPSP31",
        "The Service Processor has detected that one or more of the required "
        "fields in the System VPD have not been initialized." },
{   "FSPSP32",
        "The Service Processor has detected that an Enclosure Serial Number has "
        "not been initialized." },
{   "FSPSP33",
        "A problem has been detected in the connection with the Hardware "
        "Management Console (HMC) for eServer." },
{   "FSPSP34",
        "The memory cards are plugged in an invalid configuration and cannot be "
        "used by the system." },
{   "FSPSP36",
        "One or both of the SMP Cables connecting the System Processors on this "
        "system are incorrectly plugged, are broken, or are not the correct type "
        "of cable for this system configuration." },
{   "FSPSP38",
        "The system has detected an error within the JTAG path." },
{   "FSPSP40",
        "This procedure is a warning due to an invalid login attempt to the FSP." },
{    "FSPSP45",
        "The system has detected an error within the FSI path." },
{   "FSPSP46",
        "Some corrupt areas of flash or NVRAM have been detected on the Service Processor" },
{   "FSPSP47",
        "The system has detected an error within the PSI link." },
{   "FSPSP48",
        "Diagnostics has detected an external processor    "
        "interface problem. Perform this procedure. If that"
        "does not fix the problem,replace the FRUs that are "
        "called out."},
{   "FSPSP49",
        "Diagnostics has detected an internal processor    "
        "interface problem.First replace the FRUs that are "
        "called out.If that does not fix the problem,      "
        "perform this procedure."},
{   "FSPSP52",
        "Runtime diagnostics has detected a problem on a memory bus." },
{   "FSPSP55",
        "An error has been detected on a bus between two FRUs.  The end-point "
        "FRUs have been called out, but the source of the error could be the bus "
        "path between the FRUs." },
{   "FSPSP64",
        "All the PSI links of the system are either nonfunctional or deconfigured, "
        "so the system cannot IPL appropriately.  Please look for previous "
        "error logs that deconfigure hardware." },
{   "FSPSP65",
        "An incorrectly wired or setup network has both Service Processor "
        "ethernet interfaces on the same IP subnet.  Please refer to the HMC "
        "installation and Configuration guide to correct this problem." },
{   "FSPSP66",
        "B1xxE6ED indicates that a system with redundant service processors"
        " was booted with service processor redundancy disabled."
        " Do the following to correct this: 1.  Shut down the system."
        " 2.  Use the hardware management console (HMC) to enable redundancy."
        " 3.  Reboot the system.  Verify that SRC B1xxE6ED was not logged during this boot."},
{   "FSPSP68",
        "Save any service processor error logs and service processor dump data and contact your next"
        " level of support for assistance."},
{   "FSPSP70",
        ""},
{   "FSPSP76",
        "A unique CCIN associated with the FRU being called"
        "out could not be found in the system model.       "
        "Please walk through this procedure to identify the"
        "CCIN associated with the FRU." },
{   "FSPSP78",
        "There was a problem in waking up a core that had  "
        "earlier been in idle state. Look for previous logs"
        "with the same PLID as this log and logs with a    "
        "SRC of the format B1xxB8A7 for the root cause of  "
        "the failure." },
{   "FSPSP79",
        "Look for errors indicating uncorrectable memory   "
        "failures in the serviceable event view that were  "
        "logged at about the same time as this error and   "
        "resolve them. If there are no such errors logged, "
        "replace the processor module." },
{   "FSPSP80",
        "A problem has been detected in Platform firmware  "
        "by the Service Processor. Contact the next level  "
        "of support. If possible, save all error log and   "
        "dump data." },
{   "FSPSP83",
        "Reminder that defective hardware pending repair is "
        "present in the system. Schedule repair with next   "
        "level of support at your convenience."},
{   "FSPSP84",
        "A problem has been detected in the connection with"
        " the Chassis Management Module(CMM) for eServer.  " },
{   "FSPSP85",
        "A problem has been detected in the Hostboot firmware." },
{   "FSPSP86",
        "A diagnostic function detected a problem with TOD or PCIe clock function." },
{   "FSPSP87",
        "A diagnostic function detected a problem with the reference clock function." },
{   "FSPSP88",
        "A diagnostic function detected a problem with the UPIC Cables." },
{   "FSPSP89",
        "A diagnostic function detected a problem with the Clock Flex cables." },
{   "FSPSP90",
        "A diagnostic function detected a problem with the GFSP cables between the "
        "system control unit and the system nodes." },
{   "PWR1900",
        "Contains a procedural index based on model." },
{   "PWR1902",
        "A system unit power supply load fault is "
        "occurring." },
{   "PWR1903",
        "A system unit power supply load fault is "
        "occurring." },
{   "PWR1904",
        "A power supply or regulator overcurrent fault is "
        "occurring in the server." },
{   "PWR1906",
        "The server detected an error in the power system." },
{   "PWR1907",
        "A unit was dropped from the SPCN configuration." },
{   "PWR1908",
        "A power supply fault or load fault has occurred "
        "in a 5088 or 0588 expansion unit." },
{   "PWR1909",
        "A power supply load fault is occurring in a "
        "system expansion unit or I/O tower." },
{   "PWR1911",
        "You are here because of a power problem on a dual "
        "line cord system. If the failing  unit does not "
        "have a dual line cord, return to the procedure "
        "that sent you here or go to the next item in the "
        "FRU list." },
{   "PWR1912",
        "The server detected an error in the power system." },
{   "PWR1915",
        "Use this procedure after observing a system "
        "reference code (SRC) of 1XXX 8440 on a 520 with "
        "Quiet Office Accoustic conversion or a 285." },
{   "PWR1916",
        "The server detected an error in the power system." },
{   "PWR1917",
        "Displaying or changing the Configuration ID." },
{   "PWR1918",
        "The server detected an error in the power system." },
{   "PWR1920",
        "Use this procedure to verify that the lights on "
        "the server control panel and the display panel on "
        "all attached I/O expansion units are operation "
        "correctly." },
{   "PWR2402",
        "The server detected an error in the power system." },                 

};

/*****************************************************************************/
// Constructor
/*****************************************************************************/
ErrlParser::ErrlParser(
    FILE *		i_output,
    const errlHndl_t    i_parent
)
: iv_Parent( i_parent ), iv_Stream( i_output )
{
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlParser::~ErrlParser()
{
}



/*****************************************************************************/
// Format & Print a heading
/*****************************************************************************/
void ErrlParser::PrintHeading( const char * i_Fmt, va_list i_ap )
{
    // Locals
    int	    l_written = 0;
    char *  l_pStr  = 0;
    va_list ap;

    // Determine size
    va_copy( ap, i_ap );
    
    l_written = vsnprintf( l_pStr, l_written, i_Fmt, ap );
    
    va_end( ap );

    // Alloc
    l_pStr = new char[ ++l_written ];

    // Generate string
    vsnprintf( l_pStr, l_written, i_Fmt, i_ap );

    // Just to make sure
    l_pStr[ l_written - 1 ] = 0;

 
    // Output string
    PrintHeading( l_pStr );
    
    // Cleanup
    delete[] l_pStr;
}



/*****************************************************************************/
// Numeric Print
/*****************************************************************************/
void ErrlParser::PrintNumber(
    const char * i_label,
    const char * i_fmt,
    uint32_t	 i_value
)
{
    char l_tmp[LINE_WIDTH];

    snprintf(l_tmp,LINE_WIDTH,i_fmt,i_value);
    l_tmp[LINE_WIDTH-1] = 0;

    PrintString( i_label, l_tmp );
}

//@fk01-add
/*****************************************************************************/
// Print given float value in host's byte order.
/*****************************************************************************/
float ErrlParser::HandleFloatNumber(const float i_val)
{
    //For x86, the float value needs to be copied out to a uint32_t, flipped (due to endianness, and 
    //copied back into a float.
    uint32_t l_tempPtr[1] = {0};
    memcpy((void *)l_tempPtr, (void *)&(i_val), 4);
    l_tempPtr[0] = ntohl(l_tempPtr[0]);
    float l_flt = 0;
    memcpy((void *)&l_flt, l_tempPtr, 4);
    return l_flt;
}

//ri01a
/*****************************************************************************/
// Numeric Print for uint64_t
/*****************************************************************************/
void ErrlParser::PrintNumberUint64(
    const char * i_label,
    const char * i_fmt,
    uint64_t     i_value
)
{
    char l_tmp[LINE_WIDTH];

    snprintf(l_tmp,LINE_WIDTH,i_fmt,i_value);
    l_tmp[LINE_WIDTH-1] = 0;

    PrintString( i_label, l_tmp );
}




/*****************************************************************************/
// Display an unknown value
/*****************************************************************************/
void ErrlParser::PrintUnknown(
    const char * i_label,
    uint32_t     i_value,
    uint8_t	 i_width
)
{
    char l_tmp[LINE_WIDTH];

    snprintf(l_tmp,LINE_WIDTH,"%s - 0x%0*X",LoadMsg(ERRL_MSG_UNKNOWN),i_width,i_value);
    l_tmp[LINE_WIDTH-1] = 0;

    PrintString( i_label, l_tmp );
}



/*****************************************************************************/
// Print Boolean - true/false 
/*****************************************************************************/
void ErrlParser::PrintBool(
    const char * i_label,
    bool	     i_bool
)
{
    PrintString( i_label, i_bool ?
	LoadMsg( ERRL_MSG_BOOL_TRUE ) : LoadMsg( ERRL_MSG_BOOL_FALSE ) );
}




/*****************************************************************************/
// Print a Flag -  
/*****************************************************************************/
void ErrlParser::PrintFlag(
	const char * i_label,
	uint32_t     i_value,
	uint32_t     i_flag
)
{
    PrintString( i_label, i_value & i_flag ?
	LoadMsg( ERRL_MSG_STR_ENABLED ) : LoadMsg( ERRL_MSG_STR_DISABLED ) );
}




/*****************************************************************************/
// Print Seciton end 
/*****************************************************************************/
void ErrlParser::PrintSectionEnd( bool i_oneOnly )
{
    // Do nothing unless its sub classed
}




/*****************************************************************************/
// Print Mru Id
/*****************************************************************************/
void ErrlParser::PrintMruId( uint32_t i_val )
{
    static char l_DefMru[50];

    // Locals
    bool    l_parsed = false;   // Parse success indicator
    uint16_t    l_MruId =0;
    uint16_t    l_instance = 0;


    // Determine which component will parse this mru
    // MRU ID: Support NEW MRU ID parser
    // MRID is a 2-part structure
    // [MRU Type][Instance Number]

    l_MruId = i_val >> 16;
    l_instance = i_val ;

    // MRU ID: Support NEW MRU ID parser
    switch(l_MruId)
    {
        case(MNFG_PROC_CHIP_MRU): // Processor Chip
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x", "PROC_CHIP",l_instance);
            PrintMru( l_DefMru );
            break;
        case(MNFG_MEMBUF_CHIP_MRU): // Memory Buffer Chip
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","MEMBUF_CHIP",l_instance);
            PrintMru( l_DefMru );
            break;
        case(MNFG_SP_CHIP_MRU): // Service Processor
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","SP_CHIP",l_instance);
            PrintMru( l_DefMru );
            break;
        case(MNFG_SP_IOU_CHIP_MRU): // Service Processor I/O Extender
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","SP_IOU_CHIP",l_instance);
            PrintMru( l_DefMru );
            break;
        case(MNFG_BUILTIN_IO_MRU): // IOA component chips visible to PHYP or OS
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","BUILTIN_IO",l_instance);
            PrintMru( l_DefMru );
            break;
            //*****  Cards, Modules and Assemblies  *****
        case(MNFG_PROC_MODULE_MRU): // Processor Module
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","PROC_MODULE",l_instance);
            PrintMru( l_DefMru );
            break;
        case(MNFG_RISER_CARD_MRU): // Intermediate non-FRU riser car
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","RISER_CARD",l_instance);
            PrintMru( l_DefMru );
            break;
        case(MNFG_DIMM_MRU): // Non-FRU DIMMs
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","DIMM",l_instance);
            PrintMru( l_DefMru );
            break;
        case(MNFG_CARD_ASM_MRU): // Card Assembly (catch-all for other cards
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","CARD_ASM",l_instance);
            PrintMru( l_DefMru );
            break;
	case(MNFG_VRM_CARD_MRU): // Card Assembly (catch-all for other cards
            l_parsed = true;
            sprintf( l_DefMru, "%s-%04x","CARD_VRM",l_instance);
            PrintMru( l_DefMru );
            break;
        default: //     Placeholder for empty or unknown fields
            l_parsed = false;
            break;
    }

    // Default behavior
    if(l_parsed == false)
    {

        sprintf( l_DefMru, "0x%08X", i_val );
        PrintMru( l_DefMru );
    }
}


/*****************************************************************************/
// Print the time stamp
/*****************************************************************************/
void ErrlParser::PrintTimeStamp( const char *i_Label, const BCD_time8_t & i_ts )
{
    const   uint32_t MAX_TMP = 20;
    char  * l_tmp = new char[ MAX_TMP ];
    
    snprintf(l_tmp, MAX_TMP, "%02X/%02X/%04X %02X:%02X:%02X", 
	    i_ts.month, i_ts.day, ntohs(i_ts.year),
	    i_ts.hours, i_ts.minutes, i_ts.seconds
	    );
    
    PrintString( i_Label, l_tmp );

    delete [] l_tmp;
}



/*****************************************************************************/
// Float Numeric Print
/*****************************************************************************/
void ErrlParser::PrintFloatNumber(
    const char * i_label,
    const char * i_fmt,
    float       i_value
)
{
    char l_tmp[LINE_WIDTH];
    snprintf(l_tmp,LINE_WIDTH,i_fmt,i_value);
    l_tmp[LINE_WIDTH-1] = 0;
    PrintString( i_label, l_tmp );
}







/*****************************************************************************/
// Lookup the state
/*****************************************************************************/
const char * ErrlParser::LookUpState( uint8_t i_val )
{
    LogStateTableItem_t	*l_p;

    l_p = errl::TableLookup( (uint32_t)i_val, &LogStateTable[1], LogStateTableSz - 1 );

    if ( l_p )
	return LoadMsg( l_p->iv_Val );

    return 0;
}

/*****************************************************************************/
// Lookup severity on table
/*****************************************************************************/
const char * ErrlParser::LookUpSeverity( 
    uint8_t   i_sev
)
{
    ErrlSevTableItem_t	*l_p;

    l_p = errl::TableLookup( (uint32_t)i_sev, &ErrlSevTable[1], ErrlSevTableSz - 1 );

    if ( l_p )
	return LoadMsg( l_p->iv_Val );

    return 0;
}


/*****************************************************************************/
// Failing SubSystem
/*****************************************************************************/
void ErrlParser::PrintFailingSubSystem( uint8_t i_val )
{
    PrintTableItem( (uint32_t)i_val, ErrlSubSysTable, ErrlSubSysTableSz );
}


/*****************************************************************************/
// Severity
/*****************************************************************************/
void ErrlParser::PrintSeverity( uint8_t i_val )
{
    PrintTableItem( (uint32_t)i_val, ErrlSevTable, ErrlSevTableSz );
}



/*****************************************************************************/
// Print the event type
/*****************************************************************************/
void ErrlParser::PrintEventType( uint8_t i_val )
{
    PrintTableItem( (uint32_t)i_val, EventTypeTable, EventTypeTableSz );
}


/*****************************************************************************/
// Print the actions
/*****************************************************************************/
void ErrlParser::PrintActions( 
    uint16_t i_actions
    )
{
    PrintList( (uint32_t)i_actions, ErrlActionTable, ErrlActionTableSz );
}


/*****************************************************************************/
// Print Procedure Number and Description  
/*****************************************************************************/
void ErrlParser::PrintProcNumber( const char * i_val )
{

    // Output Procedure Number
    PrintString( "Procedure Number", i_val );

        for(uint32_t i=0;i<sizeof(errlProcMap)/sizeof(ProcedureMap);i++)
        {
           if(!strcmp(errlProcMap[i].ProcName,i_val))
           {
             PrintString( "Description", errlProcMap[i].Description );
           }
        }
}  


/*****************************************************************************/
// Print Src ascii string
/*****************************************************************************/
void ErrlParser::PrintAsciiString( const char *  i_val )
{
    char tmp[SRCI_MAX_ASCII_BYTES + 1];
    snprintf( tmp, SRCI_MAX_ASCII_BYTES, "%8.32s", i_val );
    PrintString( LoadMsg( ERRL_MSG_ASCII_STR_LABEL ), tmp );
}

/*****************************************************************************/
// Prints the replacement priority or an unknown message if not found
/*****************************************************************************/
void ErrlParser::PrintCalloutPriority( uint32_t i_priority )
{
    PrintTableItem( i_priority, SrciPriorityTable, SrciPriorityTableSz );
}


/*****************************************************************************/
// Print termination states
/*****************************************************************************/
void ErrlParser::PrintTermState( uint32_t i_val )
{
    PrintList( i_val, TermStateTable, TermStateTableSz );
}


/*****************************************************************************/
// Print clock states
/*****************************************************************************/
void ErrlParser::PrintClockState( uint32_t i_val )
{
    PrintList( i_val, ClockStateTable, ClockStateTableSz );
}

/*****************************************************************************/
// Print HMC Acknowledged Flag 
/*****************************************************************************/
void ErrlParser::PrintHmcAckFlag( bool i_val )
{
    PrintBool( LoadMsg( ERRL_MSG_HMC_ACKNOWLEDGED ), i_val ); 	   
}

/*****************************************************************************/
// Print AMM Acknowledged Flag
/*****************************************************************************/
void ErrlParser::PrintAmmAckFlag( bool i_val )
{
    PrintBool( LoadMsg( ERRL_MSG_AMM_ACKNOWLEDGED ), i_val );
}

/*****************************************************************************/
// Print PEL State 
/*****************************************************************************/
void ErrlParser::PrintPELState( uint8_t i_val )
{
    PrintString( LoadMsg( ERRL_MSG_STATE ), LookUpState( i_val ) ); 	    
}


/*****************************************************************************/
// Print PEL Status 
/*****************************************************************************/
void ErrlParser::PrintActionStatus( bool i_hmcack, uint8_t i_state, bool i_ammack )
{
    const char * l_Label = LoadMsg( ERRL_MSG_STATE ); 	    
	
    PrintString( l_Label, LookUpState( i_state ) ); 	    

    if ( i_hmcack )
    {
	// only print this if hmc ack is true and ignore a label
	l_Label = 0;
	PrintString( l_Label, LoadMsg( ERRL_MSG_HMC_ACKNOWLEDGED ) ); 	   
    }

    if ( i_ammack)
    {
        // only print this if hmc ack is true and ignore a label
        l_Label = 0;
        PrintString( l_Label, LoadMsg( ERRL_MSG_AMM_ACKNOWLEDGED ) );
    }


}

