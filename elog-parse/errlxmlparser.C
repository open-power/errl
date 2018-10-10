/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlxmlparser.H>
#include <rtim.H>

#ifndef _AIX 
#include <ctype.h>
#include <cstdarg>
#endif

#include <cstring>
#include <cstdlib>
#include <netinet/in.h>
#include <errlhashtables.H>
#include <map>

/*****************************************************************************/
// Constants ( no spaces or XML-invalid chars allowed!)
/*****************************************************************************/
const char * PEL_HDR = "PlatformEvent";
const char * PEL_HISTORY = "PEL";
const char * DEF_STR_UNDEFINED = "UNDEFINED";
const char * DEF_STR_ERROR = "ERROR";
const char * HEXDUMP = "HexDump";


/*****************************************************************************/
// xml Start File
/*****************************************************************************/
void ErrlXmlParser::StartXMLfile( void )
{
    fprintf( iv_Stream, "<%s>\n", PEL_HISTORY );
}

/*****************************************************************************/
// xml End File
/*****************************************************************************/
void ErrlXmlParser::EndXMLfile( void )
{
    fprintf( iv_Stream, "</%s>\n", PEL_HISTORY );
}

/*****************************************************************************/
// xml Init
/*****************************************************************************/
void ErrlXmlParser::Begin( const char * i_Fmt, ... )
{
    fprintf( iv_Stream, "<%s>\n", PEL_HDR );
}


/*****************************************************************************/
// Xml end of PEL
/*****************************************************************************/
void ErrlXmlParser::End( void )
{
    while ( ! iv_stack.empty() )
    {
        fprintf( iv_Stream, "</%s>\n", (iv_stack.top()).c_str() );
	iv_stack.pop();
    }
    
    fprintf( iv_Stream, "</%s>\n", PEL_HDR );
}


/*****************************************************************************/
// Print Section End 
/*****************************************************************************/
void ErrlXmlParser::PrintSectionEnd( bool i_oneOnly )
{
    while ( !iv_stack.empty() )
    {
        fprintf( iv_Stream, "</%s>\n", (iv_stack.top()).c_str() );
	iv_stack.pop();

	if ( i_oneOnly )
	    break;
    }
}


/*****************************************************************************/
// Centered Heading
/*****************************************************************************/
void ErrlXmlParser::PrintHeading( const char * i_centered )
{
    // Cover nulls
    if ( ! i_centered )
    {
        i_centered = "Unknown";
    }
    
    iv_stack.push( makeCleanXmlLabel ( i_centered, true ) );
    fprintf( iv_Stream, "<%s>\n", (iv_stack.top()).c_str() );
}

/*****************************************************************************/
// Regular string ( may be multiline )
/*****************************************************************************/
void ErrlXmlParser::PrintString(const char * i_label, const char * i_string) 
{
    if ( i_label && i_string ) 
    {
        fprintf( iv_Stream, "<Property name=\"%s\" stringValue=\"%s\"/>\n", (makeCleanXmlLabel( i_label )).c_str(), (makeValidStringValue( i_string )).c_str() );
    }
}


/*****************************************************************************/
// Numeric Print
/*****************************************************************************/
void ErrlXmlParser::PrintNumber(const char * i_label, const char * i_fmt, uint32_t i_value) 
{
    fprintf( iv_Stream, "<Property name=\"%s\" numericValue=\"", (makeCleanXmlLabel(i_label)).c_str() );
    fprintf( iv_Stream, i_fmt, i_value );
    fprintf( iv_Stream, "\"/>\n" );
}


//ri03a
/*****************************************************************************/
// Numeric Print
/*****************************************************************************/
void ErrlXmlParser::PrintNumberUint64(const char * i_label, const char * i_fmt, uint64_t i_value)
{
    fprintf( iv_Stream, "<Property name=\"%s\" numericValue=\"", (makeCleanXmlLabel(i_label)).c_str() );
    fprintf( iv_Stream, i_fmt, i_value );
    fprintf( iv_Stream, "\"/>\n" );
}



//ri02a

//@fk01-add
/*****************************************************************************/
// Print given float value in host's byte order.
/*****************************************************************************/
float ErrlXmlParser::HandleFloatNumber(const float i_val)
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

/*****************************************************************************/
// Float Numeric Print
/*****************************************************************************/
void ErrlXmlParser::PrintFloatNumber(const char * i_label, const char * i_fmt, float  i_value)
{
    fprintf( iv_Stream, "<Property name=\"%s\" numericValue=\"", (makeCleanXmlLabel(i_label)).c_str() );
    fprintf( iv_Stream, i_fmt, i_value );
    fprintf( iv_Stream, "\"/>\n" );
}



/*****************************************************************************/
// Unknown Print (print numerical value as a single hex string)
/*****************************************************************************/
void ErrlXmlParser::PrintUnknown(const char * i_label, uint32_t i_value, uint8_t i_width) 
{
    fprintf( iv_Stream, "<Property name=\"%s\" hexValue=\"0x%08X\"/>\n", (makeCleanXmlLabel(i_label).c_str()), i_value );
}


/*****************************************************************************/
// Boolean Print
/*****************************************************************************/
void ErrlXmlParser::PrintBool( const char * i_label, bool i_bool ) 
{
    fprintf( iv_Stream, "<Property name=\"%s\" booleanValue=\"%s\"/>\n", (makeCleanXmlLabel(i_label)).c_str(), i_bool ?
	    LoadMsg( ERRL_MSG_BOOL_TRUE ) : LoadMsg( ERRL_MSG_BOOL_FALSE ) );
}

/*****************************************************************************/
// Print the time stamp
/*****************************************************************************/
void ErrlXmlParser::PrintTimeStamp(const char *i_Label, const BCD_time8_t & i_ts) 
{
    const   uint32_t MAX_TMP = 32;
    char  * l_tmp = new char[ MAX_TMP ];
    
    snprintf(l_tmp, MAX_TMP, "%04X-%02X-%02XT%02X:%02X:%02X.000-00:00", 
	    ntohs(i_ts.year), i_ts.month, i_ts.day, 
	    i_ts.hours, i_ts.minutes, i_ts.seconds);
    
    fprintf( iv_Stream, "<Property name=\"%s\" timeValue=\"%s\"/>\n", (makeCleanXmlLabel(i_Label).c_str()), l_tmp );
    delete [] l_tmp;
}


/*****************************************************************************/
// Flag Print
/*****************************************************************************/
void ErrlXmlParser::PrintFlag(const char * i_label, uint32_t i_value, uint32_t i_flag) 
{
    fprintf( iv_Stream, "<Flag name=\"%s\" value=\"%s\"/>\n", (makeCleanXmlLabel(i_label).c_str()), i_value & i_flag ?
	    LoadMsg( ERRL_MSG_STR_ENABLED ) : LoadMsg( ERRL_MSG_STR_DISABLED ) );
}

/*****************************************************************************/
// Print the actions
/*****************************************************************************/
void ErrlXmlParser::PrintActions(uint16_t i_actions) 
{
    PrintList( (uint32_t)i_actions, ErrlActionTable, ErrlActionTableSz );
}

/*****************************************************************************/
// Print the actions status flags
/*****************************************************************************/
void ErrlXmlParser::PrintActionStatus( bool i_hmcack, uint8_t i_state, bool i_ammack )
{
    const char * l_Label = LoadMsg( ERRL_MSG_STATE ); 	    
	
    PrintString( l_Label, LookUpState( i_state ) ); 	  
    
    if ( i_hmcack )
    {
	// only print this if hmc ack is true 
	PrintString( l_Label, LoadMsg( ERRL_MSG_HMC_ACKNOWLEDGED ) ); 	   
    }
    if ( i_ammack )
    {
        // only print this if hmc ack is true
        PrintString( l_Label, LoadMsg( ERRL_MSG_AMM_ACKNOWLEDGED ) );
    }
}
   
/*****************************************************************************/
// Print a generic list
/*****************************************************************************/
template< class K, class V >
void ErrlXmlParser::PrintList(
	K			    i_Key,
	const errl::HashFlagItem< K, V > *i_Table,
	int			    i_Sz
    )
{
    const char *    l_Label = LoadMsg( i_Table[0].iv_Val );

    for ( int i = 1; i < i_Sz; i++ ) 
    {
	if ( i_Table[i] == i_Key ) 
	{
	    fprintf( iv_Stream, "<Property name=\"%s\" value=\"%s\"/>\n", (makeCleanXmlLabel( l_Label ).c_str()), LoadMsg( i_Table[i].iv_Val ) );
	}
    }

    if ( !l_Label )
    {
	fprintf( iv_Stream, "<Property name=\"%s\" value=\"%s\"/>\n", (makeCleanXmlLabel( l_Label ).c_str()), LoadMsg( ERRL_MSG_NONE_DECLARED ) );
    }
}


/*****************************************************************************/
// Hex Dump
/*****************************************************************************/
void ErrlXmlParser::PrintHexDump( const void * i_data, uint32_t i_len) 
{
}


/*****************************************************************************/
// SRC Hex word printer
/*****************************************************************************/
void ErrlXmlParser::PrintHexWords(const uint32_t i_words[SRCI_MAX_HEX_WORD_COUNT]) 
{
    int hex_cnt = 0;    // Hex word count used while printing
    for ( uint32_t i=0; i < SRCI_MAX_HEX_WORD_COUNT; i++ ) 
    {
        // In PEL specs, these hex words are defined as words 2 to 9
        hex_cnt = i + 2;
        fprintf( iv_Stream, "<HexWord word=\"%d\" value=\"%08X\"/> \n", hex_cnt, i_words[i] );
    }
}

/*****************************************************************************/
// SRC Ascii String
/*****************************************************************************/
void ErrlXmlParser::PrintAsciiString(const char * i_val ) 
{
    // Locals
    uint32_t	l_size = strlen( i_val );
    char	l_tmp[ l_size + 1 ];
    memset( l_tmp, 0x00, sizeof( l_tmp ) );
    
    if ( i_val )
    {
	uint32_t l_cnt = 0;
	for ( uint32_t x = 0; x < strlen( i_val ); x++ )
	{   
	    char l_char = i_val[x];
	    
	    if ( !isblank( l_char ) )
	    {
		l_tmp[ l_cnt ] = l_char;
		l_cnt++;
	    }
	}
    }

    PrintString( LoadMsg( ERRL_MSG_ASCII_STR_LABEL ), l_tmp );
}

/*****************************************************************************/
// Clean the given string so it is ready for XML consumption ( for strings ) 
/*****************************************************************************/
std::string ErrlXmlParser::makeValidStringValue( const char * i_string ) 
{
                                                                                         //ri01 below
    std::string l_rc(i_string);

    if ( i_string )
    {
        // Locals
        uint32_t    l_cnt = 0;

											//ri04 below
        std::map<char,std::string> l_xmlescape; 
        l_xmlescape['"'] = "&quot;";
        l_xmlescape['\''] = "&apos;";
        l_xmlescape['>'] = "&gt;";
        l_xmlescape['<'] = "&lt;";
        l_xmlescape['&'] = "&amp;"; 

        for ( uint32_t x = 0; x < strlen( i_string ); x++ )
        {
            char l_char = i_string[x];


            std::map<char,std::string>::iterator l_itr = l_xmlescape.find(l_char);

            if(l_itr != l_xmlescape.end())
	    {

		l_rc.replace(x,1,l_itr->second.c_str());
		l_cnt = l_cnt+l_itr->second.size();
                continue;

	    }
        										//ri04 above
            if ( isValidChar( l_char ) )
            {
                l_rc[l_cnt] = l_char;
                l_cnt++;
            }
        }

        if ( l_cnt == 0 )
        {
            l_rc = DEF_STR_UNDEFINED;
        }

    }
    else
    {
        l_rc = DEF_STR_UNDEFINED;
    }
                                                                                         //ri01 above

    return l_rc;
}



/*****************************************************************************/
// Clean the given string so it is ready for XML consumption ( for Labels )
/*****************************************************************************/
std::string ErrlXmlParser::makeCleanXmlLabel( const char * i_label, bool i_isElement ) 
{
    std::string l_rc;

    if ( i_label )
    {
	// Locals
	char	    l_newstring[ strlen ( i_label ) +1 ]; 
	uint32_t    l_cnt = 0;

	for ( uint32_t x = 0; x < strlen( i_label ); x++ )
	{   
	    char l_char = i_label[x];
	    
	    if ( isalnum( l_char ) )
	    {
		// Only convert attributes starting character
		if ( !i_isElement && ( x == 0 ) )
		{
		    l_char = tolower( l_char );
		}
		
		if ( isValidChar( l_char ) )
		{	
		    l_newstring[ l_cnt ] = l_char;
		    l_cnt++;
		}
	    }
	}

	if ( l_cnt != 0 )
	{
	    l_newstring[l_cnt] = 0x00;
	    l_rc = l_newstring;
	}
	else
	{   
	    l_rc = DEF_STR_ERROR;
	}

    }

    return l_rc;
}



/*****************************************************************************/
// compares current character against banned list
/*****************************************************************************/
bool ErrlXmlParser::isValidChar( char & i_char )
{
    bool l_rc = true;
    char l_banned[] = { '<', '>' };

    for ( uint32_t y = 0; y < sizeof( l_banned ); y++ )
    {
	if ( l_banned[y] == i_char )
	{
	    if ( y == 0 )
	    { 
		i_char = '[';
	    }
	    else
	    {
		i_char = ']';
	    }
	
	    l_rc = false;
	}

    }
    
    return l_rc;
}

/*****************************************************************************/
// Failing SubSystem
/*****************************************************************************/
void ErrlXmlParser::PrintFailingSubSystem( uint8_t i_val )
{
    PrintTableItem( (uint32_t)i_val, ErrlSubSysTable, ErrlSubSysTableSz );
}

