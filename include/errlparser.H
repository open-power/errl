#ifndef ERRLPARSER_H
#define ERRLPARSER_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errllang.H>
#include <srci.H>

#ifdef __AIX
#include <cstdarg>
#endif

/*****************************************************************************/
// Forward
/*****************************************************************************/
struct BCD_time8_t;

namespace errl {

template< class K, class V > struct HashItem;
template< class K, class V > struct HashFlagItem;

}

#define INVALID_CATALOG	((nl_catd)-1)

/*****************************************************************************/
// Constants
/*****************************************************************************/
enum mnfgMRUType_t {
    MNFG_NULL_MRU    = 0xFFFF,
    MNFG_PROC_CHIP_MRU   = 0x0001,
    MNFG_MEMBUF_CHIP_MRU     = 0x0006,
    MNFG_SP_CHIP_MRU     = 0x0009,
    MNFG_SP_IOU_CHIP_MRU     = 0x000A,
    MNFG_BUILTIN_IO_MRU  = 0x000B,
    MNFG_FLASH_CHIP_MRU  = 0x000D,
    MNFG_APSS_MRU    = 0x000E,
    MNFG_DPSS_MRU    = 0x000F,
    MNFG_PROC_MODULE_MRU     = 0x0100,
    MNFG_RISER_CARD_MRU  = 0x0101,
    MNFG_DIMM_MRU    = 0x0102,
    MNFG_VRM_CARD_MRU    = 0x0104,
    MNFG_CARD_ASM_MRU    = 0x0103,
};


/*****************************************************************************/
// User Types
/*****************************************************************************/
class ErrlParser
{
public:

    
    /**
     *  @brief Build an associated parser object
     *
     *  Builds an associated parser object which is tied to the
     *  given stream.  The net effect is the addition of some
     *  simple methods to standardize log output
     *  
     *  @param	i_output
     *	    Stream to be used for output
     *
     *  @param	i_parent
     *	    A pointer to the parent object
     *
     *  @note The parent could be null
     *  
     */
    ErrlParser(
	FILE *		    i_output = stdout,
	const errlHndl_t    i_parent = 0
    );
    
    
    
    /**
     *  @brief Cleanup handler
     *
     *  Currently no-op
     *  
     */
    virtual ~ErrlParser();
    
    
    
    /**
     *  @brief Set Parent pointer
     *
     *  Let the object carry with it a pointer to the parent
     *  
     *  @param	i_val
     *	    Parent handle
     *
     *	@note	The parent handle is not owned by this object
     *	        will therefore not be released automatically.
     *
     */
    void setParent( errlHndl_t i_val )
    {
	iv_Parent = i_val;
    }

  
    
    
    /**
     *  @brief Access Parent ( if any )
     *
     *  The parent pointer is so that users of the interface
     *  can have full access to the log which is being parsed
     *  
     *  @return Parent handle
     *
     *  @note The parent handle can be null
     *  
     */
    const errlHndl_t Parent( void ) const
    {
	return iv_Parent;
    }

    
    
    /**
     *  @brief Set Stream pointer
     *
     *  Changes the output stream pointer which ultimately
     *  determines what OS device receives the data
     *  
     *  @param	i_val
     *	    Output stream
     *
     *	@note	The stream handle is not owned by this object
     *	        and will therefore not be released automatically
     *
     */
    void setStream( FILE * i_val )
    {
	iv_Stream = i_val;
    }


    
    void setCatalog( nl_catd i_val )
    {
    }

  
    
    /**
     *  @brief Emit any initialization output
     *
     *  Used to output banner headings or any required
     *  parser output for the given device ( i.e. table
     *  information under html )
     *  
     *  @param	i_Fmt
     *	    Format string.  The method is a direct call into
     *	    one of the string variadic functions and thus will
     *	    take a format string and a set of optional variable
     *	    length arguments
     *
     *  @param	Variable
     *	    List of variable arguments
     *
     *  @return None
     *
     *  @note The input format is typically used to output
     *        a header
     *  
     */
    virtual void Begin(
	const char * i_Fmt
	...
    ) = 0;
    
    
    
    
    /**
     *  @brief Finalize device output
     *
     *  Depending on the parser, the output may need to emit
     *  some sort of closure ( i.e. end a table in html ) and
     *  this is made possible though this method.
     *  
     */
    virtual void End( void ) = 0;
    
    
    
    
    /**
     *  @brief Send a division ( section marker )
     *
     *  In console mode, a line is displayed and a table row
     *  is sent to the output in html mode
     *  
     */
    virtual void PrintDivider( void ) = 0;
    

    
    
    /**
     *  @brief Output a blank line
     *
     *  In error log parser format, a blank line includes
     *  the leader and trailer lines and thus requires an
     *  interface.
     *  
     */
    virtual void PrintBlank() = 0;


    
    
    /**
     *  @brief Print a centered heading
     *
     *  The implementation depends on the type of parser
     *  ( console or other ) but the result should be the
     *  same ( i.e. a centered line of string should appear )
     *  
     *  @param	i_centered
     *	    String to be placed in the center
     *
     */
    virtual void PrintHeading(
	const char * i_centered
    ) = 0;

    
    
    /**
     *  @brief Format & Print centered
     *
     *  Calls the above template method but first
     *  formats a temporary string according to the
     *  specified format specifier and argument list
     *  
     *  @param	i_Fmt
     *	    Format specifier ( same as printf )
     *
     *  @param	i_ap
     *	    Initialized va_list
     *
     */
    void PrintHeading(
	const char *i_Fmt,
	va_list	    i_ap
    );




    /**
     *  @brief Display a standard parser message
     *
     *  Displays the a message in the error log parser
     *  format of "Label: Desc"
     *  
     *  @param	i_label
     *	    Label for the message
     *
     *  @param	i_string
     *	    Description string
     *
     */
    virtual void PrintString(
	const char * i_label,
	const char * i_string
    ) = 0;


    
    
    /**
     *  @brief Output a standard message for numeric data
     *
     *  A message consisting of the label and a hex formatted
     *  number is forwarded to the PrintString interface
     *  
     *  @param	i_label
     *	    Left-hand label for the data
     *
     *  @param	i_fmt
     *	    Numeric format used to parse the data value
     *
     *  @param	i_value
     *	    Numberic value
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     */
    virtual void PrintNumber(
	const char * i_label,
	const char * i_fmt,
	uint32_t     i_value
    );

	/**
     *  @brief Print the float based on host's byte order
     *
     *  Takes a float number and converts it to the host's byte order 
     *  and then returns the new value. 
     *  Float require special handling on X86 systems.  The errlog buffer is generated
     *  on a ppc system (Big Endian), therefore when we attempt to parse the buffer 
     *  into a structure on an X86 system, the bytes in the parameters of the 
     *  structure are assumed to be in little endian order.  Therefore the function
     *  ntohs/ntohl need to be used to convert the Big endian data into the correct
     *  format based on host byte order.  Nevertheless, a float requires a little 
     *  extra handling, thus this function.
     *
     *  @param	i_val: 
     *
     *  @return float with bytes in proper order.
     */
     float HandleFloatNumber(const float i_val);


    /**
     *  @brief Output a standard message for numeric data
     *
     *  A message consisting of the label and a hex formatted
     *  number is forwarded to the PrintString interface
     *
     *  @param  i_label
     *      Left-hand label for the data
     *
     *  @param  i_fmt
     *      Numeric format used to parse the data value
     *
     *  @param  i_value
     *      Numberic value of uint64_t
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     */
    virtual void PrintNumberUint64(
        const char * i_label,
        const char * i_fmt,
        uint64_t     i_value
    );
 
    
    
    /**
     *  @brief Output a standard message for booleans
     *
     *  A message consisting of the label and a "True/False" value
     *  is forwarded to the PrintString interface
     *  
     *  @param	i_label
     *	    Left-hand label for the data
     *
     *  @param	i_bool
     *	    The boolean variable to be parsed
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     */
    virtual void PrintBool(
	const char * i_label,
	bool	     i_bool
    );

    
    
    /**
     *  @brief Output a standard message for flags
     *
     *  A message consisting of the label and a "Enabled/Disabled" value
     *  is forwarded to the PrintString interface
     *  
     *  @param	i_label
     *	    Left-hand label for the data
     *
     *  @param	i_value
     *	    Value to be displayed
     *
     *  @param	i_flag
     *	    Flag value
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     */
    virtual void PrintFlag(
	const char * i_label,
	uint32_t     i_value,
	uint32_t     i_flag
    );

    /**
     *  @brief Tell Parser object that Section has ended
     *
     *  This is mainly used for subclasses of ErrlParser
     *  to ensure we correctly stamp xml tags
     *  
     *  @param	i_oneOnly
     *	    defaulted to false, means only stamp one label 
     *	    off the stack
     *
     *  @note This is a noop on all classes except XmlParser
     */
    virtual void PrintSectionEnd( bool i_oneOnly = false );
    
    /**
     *  @brief Output an unknown data value
     *
     *  Outputs a standard message for unknown data
     *  
     *  @param	i_label
     *	    Left-hand label for the data
     *
     *  @param	i_value
     *	    Value to be displayed
     *
     *  @param	i_width
     *	    Preferred width of the data value
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     *  
     *  
     */
    virtual void PrintUnknown(
	const char * i_label,
	uint32_t     i_value,
        uint8_t	     i_width
    );


    
    /**
     *  @brief Classical Hex dump of data
     *
     *  A 5 column output consisting of an offset, 4 hex words,
     *  and an ascii equivalent will be dumped in big endian
     *  mode
     *  
     *  @param	i_data
     *	    Pointer to data buffer
     *
     *  @param	i_len
     *	    Length of data in bytes
     *
     */
    virtual void PrintHexDump(
	const void * i_data,
	uint32_t     i_len
     ) = 0;


    
    /**
     *  @brief Mru parsing interface for plugins
     *
     *  In order to provide plugins with a consistent look and feel
     *  when printing Mrus, this interface was added.  It is a small
     *  inline wrapper to the PrintString interface which uses a
     *  standard label.
     *  
     *  @param	i_msg
     *	    Mru string message
     *
     *  @return None
     *
     */
    void PrintMru(
	const char * i_msg
    )
    {
	PrintString( LoadMsg( ERRL_MSG_MRU_ID ), i_msg );
    }


    
    
    /**
     *  @brief Mru parsing interface for error logger
     *
     *  The error logger uses this interface when displaying
     *  a mru id
     *  
     *  @param	i_val
     *	    Value of the MRU
     *
     *  @note The interface is undefined in the ERRL_TOOL context
     *        as far as this header file is concerned.  However,
     *        the implementation is supplied by tools/errltoolmru.C
     *  
     */
    void PrintMruId( uint32_t i_val );
    


    
	
    /**
     *  @brief Parse Timestamp
     *  
     *  The BCD timestamp is converted to a human readable version
     *
     *  @param	i_Label
     *	    Message Label
     *
     *  @param	i_val
     *	    Reference to timestamp
     *
     */
    virtual void PrintTimeStamp( const char *i_Label, const BCD_time8_t & i_ts );


    /**
     *  @brief Output a standard message for float numeric data
     *
     *  A message consisting of the label and a float formatted
     *  number is forwarded to the PrintString interface
     *
     *  @param  i_label
     *      Left-hand label for the data
     *
     *  @param  i_fmt
     *      Numeric format used to parse the data value
     *
     *  @param  i_value
     *      Float Numberic value
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     */
   
    virtual void PrintFloatNumber(
        const char * i_label,
        const char * i_fmt,
        float       i_value
    );                          
 
       /**
     *  @brief Generic list priting
     *
     *  Takes advantage of a generic HashItem or HashFlagItem to lookup
     *  values or flags and display them in the parser format of a list.
     *
     *  IMPORTANT:
     *  The first row of the table must contain the message identifier
     *  for the label
     *
     *  @param  i_Key
     *      Matching Key.  Used in comparing to lookup table
     *
     *  @param  i_Table
     *      Pointer to table
     *
     *  @param  i_Sz
     *      Table Size
     *
     */
    template< class K, class V >
    void PrintList(
        K                           i_Key,
        const errl::HashFlagItem< K, V > *i_Table,
        int                         i_Sz
    )
    {
        const char * l_Label = LoadMsg( i_Table[0].iv_Val );

        for ( int i = 1; i < i_Sz; i++ )
        {
            if ( i_Table[i] == i_Key )
            {
                PrintString( l_Label, LoadMsg( i_Table[i].iv_Val ) );

                // Symbolizes that at least one item was printed and
                // also enables us to skip the label on subsequent lines
                l_Label = 0;
            }
        }

        if ( l_Label )
        {
            PrintString( l_Label, LoadMsg( ERRL_MSG_NONE_DECLARED ) );
        }
    }

    /**
     *  @brief Generic table item priting
     *
     *  Takes advantage of a generic HashItem or HashFlagItem to lookup
     *  values or flags in a table and display if found.  Otherwise,
     *  display that the value is unknown.
     *
     *  @param  i_Key
     *      Matching Key.  Used in comparing to lookup table
     *
     *  @param  i_Label
     *      Label for the row
     *
     *  @param  i_Table
     *      Pointer to table
     *
     *  @param  i_Sz
     *      Table Size
     *
     */
    template< class K, class V >
    void PrintTableItem(
        K                       i_Key,
        const char *            i_Label,
        const errl::HashItem< K, V > *i_Table,
        int                     i_Sz
    )
    {
        for ( int i = 0; i < i_Sz; i++ )
        {
            if ( i_Table[i] == i_Key )
            {
                PrintString( i_Label, LoadMsg( i_Table[i].iv_Val ) );

                // Symbolizes that we found the item
                i_Label = 0;

                break;
            }
        }

        if ( i_Label )
        {
            PrintUnknown( i_Label, i_Key, 8 );
        }
    }



    /**
     *  @brief Generic table item priting
     *
     *  Takes advantage of a generic HashItem or HashFlagItem to lookup
     *  values or flags in a table and display if found.  Otherwise,
     *  display that the value is unknown.
     *
     *  IMPORTANT:
     *  The first row of the table must contain the message identifier
     *  for the label
     *  
     *  @param	i_Key
     *	    Matching Key.  Used in comparing to lookup table
     *
     *  @param	i_Table
     *	    Pointer to table
     *
     *  @param	i_Sz
     *	    Table Size
     *
     */

    template< class K, class V >
    inline void PrintTableItem(
	K			i_Key,
	const errl::HashItem< K, V > *i_Table,
	int			i_Sz
    )
    {
	const char * l_Label = LoadMsg( i_Table[0].iv_Val );

	PrintTableItem( i_Key, l_Label, &i_Table[1], i_Sz - 1 );
    }

    

    const char * LoadMsg( const char * i_MsgId )
    {
	return i_MsgId;
    }
    


    
    /**
     *  @brief Translate severity to text
     *
     *  Routine used by both Error logger and ASM to convert severity to text
     *  
     *  @param  i_sev
     *	    Severity
     *
     *  @return Pointer to the string
     *
     */
    const char * LookUpSeverity( 
	uint8_t   i_sev
    );

    /**
     *  @brief Translate severity to text
     *
     *  Routine used by both Error logger and ASM to convert severity to text
     *  
     *  @param  i_sev
     *	    Severity
     *
     *  @return Pointer to the string
     *
     */
    const char * LookUpState( 
	uint8_t   i_val
    );


    /**
     *  @brief Translate Subsystem to text
     *
     *  Routine used by both Error logger and ASM to convert subsystem to text
     *  
     *  @param  i_subsys
     *	    Subsystem value
     *
     *  @return Pointer to the string
     *
     */
    const char * LookUpSubSys( 
	uint8_t	i_subsys
    );


    
    /**
     *  @brief Display Driver Name
     *
     *  The driver information is formatted and sent to
     *  the output device
     *  
     *  @param	i_str
     *	    Formatted driver name
     *
     */
    void PrintDriverName( const char * i_str )
    {
	PrintString( LoadMsg( ERRL_MSG_DRIVER_NAME ), i_str );
    }

    
    
    /**
     *  @brief Short-hand to Print Create timestamp
     *  
     *  Forward message to the generic PrintTimeStamp but
     *  load in the proper message first.
     *
     *  @param	i_ts
     *	    rtim BCD timestamp
     *
     *  @return None
     *
     */
    void PrintCreateTimeStamp( const BCD_time8_t & i_ts )
    {
	PrintTimeStamp( LoadMsg( ERRL_MSG_CREATED_AT ), i_ts );
    }
    
    
    
    /**
     *  @brief Display primary src heading
     */
    void PrintPriSRCHeading( void )
    {
	PrintHeading( LoadMsg( ERRL_MSG_PRI_SRC ) );
    }
   
    
    /**
     *  @brief Display header for a log hex dump
     */
    void PrintLogHexDumpHeader( void )
    {
	PrintHeading( LoadMsg( ERRL_MSG_LOGHEX_DUMP_HDR ) );
    }
    

    /**
     *  @brief Translate & display failing subsystem
     *
     *  The failing subsystem is translated from a table and
     *  then output using a standard message string.
     *
     *  @param  i_val
     *      Subsystem identifier
     *
     *  @return None
     *
     */
    void PrintFailingSubSystem( uint8_t i_val );

    /**
     *  @brief Translate & display the log severity
     *
     *  The severity is translated from a table and
     *  then output using a standard message string.
     *  
     *  @param	i_val
     *	    Severity
     *
     *  @return None
     *  
     */
    void PrintSeverity( uint8_t i_val );


    /**
     *  @brief Translate & display the event type
     *
     *  The event type is translated from a table and
     *  then output using a standard message string.
     *  
     *  @param	i_val
     *	    Event type
     *
     *  @return None
     *  
     */
    void PrintEventType( uint8_t i_val );
   
    
    
    /**
     *  @brief Translate & display the log actions
     *
     *  The log actions is a set of flags and therefore this
     *  interface will forward it's request to PrintList
     *  
     *  @param	i_val
     *	    Action flags
     *
     *  @return None
     *  
     */
    virtual void PrintActions( uint16_t i_val );

    
    
    /**
     *  @brief Overrideable Procedure Number print
     *  
     *  On flash, displays the procedure number only.  However,
     *  this operation is overloaded in the tool to display the
     *  description of the procedure if available
     *
     *  @param	i_val
     *	    Procedure Number in text ( FSPXXXX )
     *
     *  @return None
     *
     */
    void PrintProcNumber( const char * i_val );
    
    
	
    /**
     *  @brief SRC Hex Word display
     *
     *  The SRC hex words are displayed using two rows with
     *  the proper labels.  The implementation is dependent
     *  on the output device and thus is only declared
     *  abstractly here
     *  
     *  @param	i_words
     *	    An array of SRCI_MAX_HEX_WORD_COUNT
     *
     *  @return None
     *
     */
    virtual void PrintHexWords(
	const uint32_t i_words[SRCI_MAX_HEX_WORD_COUNT]
    ) = 0;



    
    /**
     *  @brief Display SRC Word 11 - ascii string
     *
     *  Only the first 8 digits of the ascii string are displayed
     *  
     *  @param	i_val
     *	    Ascii string coming from src object
     *
     *  @return None
     *
     */
    virtual void PrintAsciiString( const char *  i_val );


    void PrintLocCode( const char *  i_val )
    {
	PrintString( LoadMsg( ERRL_MSG_LOC_CODE ), i_val );
    }

    void PrintPartNumber( const char * i_val )
    {
	PrintString( LoadMsg( ERRL_MSG_PART_NUMBER ), i_val );
    }

    void PrintSerialNumber( const char * i_val )
    {
	PrintString( LoadMsg( ERRL_MSG_MACHINE_SERIAL ), i_val );
    }

    void PrintCCIN( const char * i_val )
    {
	PrintString( LoadMsg( ERRL_MSG_CCIN ), i_val );
    }
    
    void PrintCalloutPriority( uint32_t i_priority );

    
    void PrintAddSections( uint32_t i_val, uint32_t i_flags )
    {
	PrintFlag( LoadMsg( ERRL_MSG_ADD_SEC ), i_val, i_flags );
    }
    
    
    void PrintCalloutCnt( uint16_t i_val )
    {
	PrintNumber( LoadMsg( ERRL_MSG_CALLOUT_CNT ), "%i", i_val );
    }

    void PrintHypDumpBit( bool i_val )
    {
	PrintBool( LoadMsg( ERRL_MSG_HYP_DUMP_BIT ), i_val );
    }
    
    void PrintI5SEbit( bool i_val )
    {
	PrintBool( LoadMsg( ERRL_MSG_I5OS_SERVICE_EVENT_BIT ), i_val );
    }
    
    void PrintVirtualSRCbit( bool i_val )
    {
	PrintBool( LoadMsg( ERRL_MSG_VIRTUALSRC_BIT ), i_val );
    }

    void PrintPCEname( const char * i_val )
    {
	PrintString( LoadMsg( ERRL_MSG_PCE_NAME ), i_val );
    }

    void PrintModId( uint8_t i_val )
    {
	PrintNumber( LoadMsg( ERRL_MSG_MOD_ID ), "0x%02X", i_val );
    }

    void PrintSourceFSP( const char * i_val )
    {
	PrintString( LoadMsg( ERRL_MSG_SOURCE_FSP ), i_val );
    }

    void PrintSysBackPlane( uint16_t i_val )
    {
	PrintNumber( LoadMsg( ERRL_MSG_SYS_BACKPLANE  ),"0x%04X", i_val );
    }

    void PrintSrcVersion( uint8_t i_val )
    {
	PrintNumber( LoadMsg( ERRL_MSG_SRC_VER ), "0x%02X", i_val );
    }

    void PrintSpcnFault( bool i_val )
    {
	PrintBool( LoadMsg( ERRL_MSG_SPCN_FAULT ), i_val );
    }

    void PrintHexWordCnt( uint32_t i_val )
    {
	PrintNumber( LoadMsg( ERRL_MSG_HEX_WORD_CNT ), "%i", i_val );
    }

    void PrintMachineType( const char * i_val )
    {
	PrintString( LoadMsg( ERRL_MSG_MACHINE_TYPE ), i_val );
    }

    void PrintSrcErrorCount( uint8_t i_val )
    {
	PrintNumber( LoadMsg( ERRL_MSG_SRC_ERR_CNT ), "0x%02X", i_val );
    }

    void PrintRealBlank()
    {
	fprintf( iv_Stream, "\n" );
    }

    
    void PrintTermState( uint32_t i_val );
    
    void PrintClockState( uint32_t i_val );

    void PrintHmcAckFlag( bool i_val );

    void PrintAmmAckFlag( bool i_val );

    void PrintPELState( uint8_t i_val );

    virtual void PrintActionStatus( bool i_hmcack, uint8_t i_state, bool i_ammack = false);

    void PrintFSstatusHeader( void )
    {
	Begin( LoadMsg( ERRL_MSG_FS_HEADER ) );
    }
    
    void PrintHistoryLogSize( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_HIST_SZ ), "%d", i_size );
    }

    void PrintBlockSize( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_BLK_SZ ), "%d", i_size );
    }
   
    void PrintFATSize( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_FAT_SZ ), "%d", i_size );
    }

    void PrintFATBlockSize( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_FATBLK_SZ ), "%d", i_size );
    }

    void PrintReportLogQueue( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_REPLOG_SZ ), "%d", i_size );
    }

    void PrintTotalFiles( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_TOTAL_LOGS ),"%d", i_size );
    }

    void PrintFileSystemSPHeader( void )
    {
	PrintHeading( LoadMsg( ERRL_MSG_FS_SP_HDR ) );
    } 
 
    void PrintQuotaMax( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_MEM_TITLE ), "%d", i_size );
    } 
 
    void PrintQuotaFileNumber( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_NUMLOG_TITLE ), "%d", i_size );
    }

    void PrintQuotaUse( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_MEMUSED_TITLE ), "%d", i_size );
    }

    void PrintQuotaUnused( uint32_t i_size )
    {
	PrintNumber( LoadMsg( ERRL_MSG_FS_MEMUNUSED_TITLE ), "%d", i_size );
    }

    void PrintLogPresent( uint32_t i_bool )
    {
	PrintBool( LoadMsg( ERRL_MSG_FS_LOG_PRESENT ), i_bool );
    }


    void PrintQuotaErrorHeader( void )
    {
	PrintString( LoadMsg( ERRL_MSG_FS_ERR_QUOTA_HDR ), "" );
    }

    void PrintQuotaInfoHeader( void )
    {
	PrintString( LoadMsg( ERRL_MSG_FS_INFO_QUOTA_HDR ), "" );
    }

    void PrintQuotaOtherHeader( void )
    {
	PrintString( LoadMsg( ERRL_MSG_FS_OTHER_QUOTA_HDR ), "" );
    }

    void PrintQuotaHypervisorHeader( void )
    {
	PrintHeading( LoadMsg( ERRL_MSG_FS_HYPR_HDR ) );
    }

    void PrintQuotaLastHeader( void )
    {
	PrintHeading( LoadMsg( ERRL_MSG_FS_LAST_QUOTA_HDR ) );
    }
   
    void PrintPurgingAlgoLabel( bool i_val )
    {
	PrintBool( LoadMsg( ERRL_MSG_FS_PURGED_HDR ), i_val ); 
    }
    
 

 
protected:
    
    // Data
    errlHndl_t	iv_Parent;	    ///< Parent pointer ( if any )
    FILE *	iv_Stream;	    ///< Associated stream
};




#endif //ERRLPARSER_H
