/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltoolutils.H>
#include <errlCompMap.H>
#include <errlentry.H>
#include <dlfcn.h>
#include <cstring>
#include <errlhashtables.H>
#include <errlparser.H>

/*****************************************************************************/
// Tables
/*****************************************************************************/

HASH_ITEM_TABLE( Status )
    {   ERRL_STATUS_SUCCESS,	    "Operation Successful"},
    {   ERRL_STATUS_CORRUPT,	    "Corrupt Input Data"},
    {   ERRL_STATUS_SHORT_SIZE,	    "Buffer provided by caller too small"},
    {   ERRL_STATUS_DUP_ENTRY,	    "Duplicate Entry Id or Primary SRC"},
HASH_TABLE_END( Status )


HASH_ITEM_TABLE( CreatorSubSys )
    {   ERRL_CID_HMC,		    "Hardware Mangagement Console" },
    {   ERRL_CID_SP,		    "FipS Error Logger" },
    {   ERRL_CID_HYP,		    "Hypervisor" },
    {   ERRL_CID_POWER,		    "Power Control Network" },
    {   ERRL_CID_FIRMWARE,	    "Partition Firmware" },
    {   ERRL_CID_SLIC,		    "SLIC" },
    {   ERRL_CID_HOSTBOOT,          "HostBoot" },
    {   ERRL_CID_OCC,               "OCC" },
    {   ERRL_CID_IODRAWER,          "I/O Drawer" },
    {   ERRL_CID_SAPPHIRE,          "OPAL" },
    {   ERRL_CID_POWERNV,           "POWERNV" }
HASH_TABLE_END( CreatorSubSys )


HASH_ITEM_TABLE( LogScope )
    {   ERRL_SCOPE_SINGLE_PART,	    "Single Partition" },
    {   ERRL_SCOPE_MULTIPLE_PART,   "Mutiple Partions" },
    {   ERRL_SCOPE_PLATFORM,	    "Single Platform" },
    {   ERRL_SCOPE_MULTI_PLATFORM,  "Multiple Platforms" }
HASH_TABLE_END( LogScope )


HASH_ITEM_TABLE( Sid )
    { ERRL_SID_PRIVATE_HEADER,	"Private Header" },
    { ERRL_SID_USER_HEADER,	"User Header" },
    { ERRL_SID_PRIMARY_SRC,	"Primary System Reference Code" },
    { ERRL_SID_EXTENDED_HEADER, "Extended User Header" },
    { ERRL_SID_MACHINE_TYPE,    "Machine Type/Model & Serial Number" },
    { ERRL_SID_SECONDARY_SRC,	"Secondary System Reference Code" },
    { ERRL_SID_USER_DEFINED,	"User Defined Data" },
    { ERRL_SID_EXT_USER_DEFINED,"Extended User Defined Data" }
HASH_TABLE_END( Sid )


namespace errl {


/*****************************************************************************/
// Load a Plugin and return an entry point
/*****************************************************************************/
void * LoadPluginSymbol(
    errlCreator i_ssid,
    comp_id_t	i_cid,
    const char *i_EntryPoint
)
{

    // Locals
    void *  l_rc    = 0;	    // Symbol Entry Point

    return l_rc;
}




/*****************************************************************************/
// Print the Creator SubSystem
/*****************************************************************************/
void PrintCreatorSubSystem( 
    ErrlParser &i_parser,
    uint8_t	i_val 
)
{
    i_parser.PrintTableItem( (uint32_t)i_val, "Creator Subsystem", CreatorSubSysTable, CreatorSubSysTableSz );
}


/*****************************************************************************/
// Print the log scope
/*****************************************************************************/
void PrintScope( 
    ErrlParser &i_parser,
    uint8_t	i_val 
)
{
    i_parser.PrintTableItem( (uint32_t)i_val, "Event Scope", LogScopeTable, LogScopeTableSz );
}


/*****************************************************************************/
// Component Name
/*****************************************************************************/
void PrintCompName(
    ErrlParser &i_parser,
    const char *i_label,
    comp_id_t i_cid
)
{
    //print the comp name for "Fips Error" and "power control network" subsystems
    uint32_t l_subsys = 0;
    uint16_t l_compid;
    char l_compname[3];

    l_subsys = i_parser.Parent()->creatorSubSys();
    if (((l_subsys == ERRL_CID_SP)  ||
         (l_subsys == ERRL_CID_POWER)) &&
       LookupCompName( i_cid ) )
    {
      i_parser.PrintString( i_label, LookupCompName( i_cid ) );
//      i_parser.PrintNumber( i_label, "%04X", i_cid ); 
    }

    //Print ASCII value instead of HEX value if compId for phyp logs
    else if( (l_subsys == ERRL_CID_HYP) && (i_cid != 0 ))
    {
        l_compid = i_cid;
        l_compid = ntohs(l_compid);
        sprintf(l_compname,"%c%c",((char*)&l_compid)[0],((char*)&l_compid)[1]);
        i_parser.PrintString( i_label,l_compname);
    }
    else if( (l_subsys == ERRL_CID_HOSTBOOT) )
    {
	if(( strcmp( i_label, "Log Committed by") == 0))
	{
	    i_parser.PrintString( i_label, LookupCompName( i_cid ) );
	}
	else
	{
	    i_parser.PrintString( i_label, LookupCompName( i_cid , l_subsys) );
	}
    }
    else
    {
	i_parser.PrintNumber( i_label, "%04X", i_cid );
    }
}


/*****************************************************************************/
// Lookup Component Name
/*****************************************************************************/
const char * LookupCompName( comp_id_t i_cid,uint32_t i_val )
{
    CompTableItem_t * l_p=NULL;
    static char tmp[10];
    uint16_t l_compid;
    


	if( i_val == ERRL_CID_HOSTBOOT)
	{
	    l_p = TableLookup( (uint32_t)i_cid, CompHBTable, CompHBTableSz );
	}
	else
	{
            l_p = TableLookup( (uint32_t)i_cid, CompTable, CompTableSz );
//           snprintf( tmp, 10, "0x%04X", i_cid ); 
//           return tmp; 
	}
        if ( l_p )
        {
	    return l_p->iv_Val;
        }
        else
        {
            //Print ASCII value instead of HEX value for
            //Created by fieled in errl -l
            if(i_cid != 0 )
            {
                l_compid = i_cid;
                l_compid = ntohs(l_compid);
                sprintf(tmp,"%c%c",((char*)&l_compid)[0],((char*)&l_compid)[1]);
            }
            else
            {
	        snprintf( tmp, 10, "0x%04X", i_cid );
            }
	    return tmp;
        }
}



/*****************************************************************************/
// Specialization for reverse lookup
/*****************************************************************************/
class CompNameCmp
{
public:
    inline bool operator() (const char * & i_right, const CompTableItem_t & i_left ) const
    {
	return ( strncasecmp( i_left.iv_Val, i_right, 4 ) == 0 );
    }
};

/*****************************************************************************/
// Lookup Component Id
/*****************************************************************************/
comp_id_t LookupCompId( const char * i_Name )
{
    CompTableItem_t * l_p;
    
    l_p = TableLookup( i_Name, CompTable, CompTableSz, CompNameCmp() );

    if ( l_p )
	return l_p->iv_Key;

    return 0;
}



/*****************************************************************************/
// Parse state
/*****************************************************************************/
const char *LookupState( uint8_t i_val )
{
    const char *l_p = 0;
    static char tmp[50];
    
    l_p = g_Parser.LookUpState( i_val );

    if ( ! l_p )
    {
	snprintf( tmp, 50, "Unknown - 0x%02X", i_val );
	l_p = tmp;
    }

    return l_p;
}


/*****************************************************************************/
// Parse severity
/*****************************************************************************/
const char *LookupSeverity( uint32_t i_val )
{
    const char *l_p = 0;
    static char tmp[50];
    
    l_p = g_Parser.LookUpSeverity( i_val );

    if ( ! l_p )
    {
	snprintf( tmp, 50, "Unknown - 0x%02X", i_val );
	l_p = tmp;
    }

    return l_p;
}


/*****************************************************************************/
// Parse the section header
/*****************************************************************************/
void PrintSectionHeader(
    ErrlParser &i_parser,
    uint32_t	i_val
)
{
    SidTableItem_t *l_p;
    const char *    l_msg = 0;
    static char	    tmp[50];
    
    l_p = errl::TableLookup( (uint32_t)i_val, SidTable, SidTableSz );

    if ( ! l_p )
    {
	snprintf( tmp, 50, "Unknown - 0x%04X", i_val );
	l_msg = tmp;
    }
    else
    {
	l_msg = l_p->iv_Val;
    }
    
    i_parser.PrintDivider();
    i_parser.PrintHeading( l_msg );
    i_parser.PrintDivider();
}






} // namespace
