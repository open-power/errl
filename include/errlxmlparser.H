#ifndef ERRLXMLPARSER_H
#define ERRLXMLPARSER_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlusrparser.H>

#include <string>
#include <stack>

/*****************************************************************************/
// Forward
/*****************************************************************************/
struct BCD_time8_t;

/*****************************************************************************/
// XML Parser
/*****************************************************************************/
class ErrlXmlParser : public ErrlUsrParser
{
public:

    // stack type
    typedef std::stack< std::string > stack_t;
    
    /**
     *  @brief Build an associated parser object specific to xml
     *
     *  Builds an associated parser object which is tied to the
     *  given stream.  The net effect is the addition of some
     *  simple methods to standardize log output
     *  
     */
    ErrlXmlParser(
	FILE *		    i_output = stdout,
	const errlHndl_t    i_parent = 0
    )
    : ErrlUsrParser( i_output, i_parent ), iv_stack()
    
    {
    }
    
    /**
     *  @brief Cleanup handler
     *
     *  
     */
     ~ErrlXmlParser( )
    {
    }
    
    
    /**
     *  @brief Emit any initialization output
     *
     *  Used to output banner headings or any required
     *  parser output for the given device ( i.e. section
     *  information under xml )
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
    void Begin(
	const char * i_Fmt
	...
    );
    
    /**
     *  @brief Emit an XML init output
     *
     *  Used to start the xml file and hold varios pels if needed
     *  
     *  @return None
     *
     *  @note Should only be used by errl tool at this time
     *  
     */
    void StartXMLfile( void );
    
    
    /**
     *  @brief Emit an XML ending output
     *
     *  Used to end the xml file and hold varios pels if needed
     *  
     *  @return None
     *
     *  @note Should only be used by errl tool at this time
     *  
     */
    void EndXMLfile( void );

    
    /**
     *  @brief Finalize device output
     *
     *  Depending on the parser, the output may need to emit
     *  some sort of closure ( i.e. end a section in xml ) and
     *  this is made possible though this method.
     *  
     */
    void End( void );
    
    
    /**
     *  @brief Send a division ( section marker )
     *
     *  Do nothing in XML mode.
     *  
     */
    void PrintDivider( void )
    {
	// do nothing in XML
    }
        
    
    /**
     *  @brief Print a blank line
     *
     *  Do nothing in XML mode.
     *  
     */
    void PrintBlank()
    {
	// do nothing in XML
    }

    
    /**
     *  @brief Print a centered heading
     *
     *  The implementation depends on the type of parser
     *  ( console or other ) but the result should be the
     *  same ( i.e. a centered line of string should appear )
     *  Heading, open a new section using the given text as a tag.
     *  
     *  @param	i_centered
     *	    String to be placed in the center
     *
     */
    void PrintHeading(
	const char * i_centered
    );

    
    /**
     *  @brief Display a standard parser message
     *
     *  Displays the a message in the error log parser
     *  Add a string property sub-element to the currently active element
     *  
     *  @param	i_label
     *	    Label for the message
     *
     *  @param	i_string
     *	    Description string
     *
     */
    void PrintString(
	const char * i_label,
	const char * i_string
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
    void PrintBool(
	const char * i_label,
	bool	     i_bool
    );


    /**
     *  @brief Classical Hex dump of data
     *
     *  Add a Hex Dump sub-element to the currently active element.
     *  
     *  @param	i_data
     *	    Pointer to data buffer
     *
     *  @param	i_len
     *	    Length of data in bytes
     *
     */
    void PrintHexDump(
	const void * i_data,
	uint32_t     i_len
     );


    void PrintFailingSubSystem(uint8_t);
    
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
    void PrintNumber(
	const char * i_label,
	const char * i_fmt,
	uint32_t     i_value
    );




    //ri02a
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

    void PrintNumberUint64(
        const char * i_label,
        const char * i_fmt,
        uint64_t     i_value
    );

    //ri01a

	//fk01-add
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
     *  @brief Output a standard message for Float numeric data
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
     *      Float Numberic value
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     */

    void PrintFloatNumber(
        const char * i_label,
        const char * i_fmt,
        float        i_value
    );


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
    void PrintUnknown(
	const char * i_label,
	uint32_t     i_value,
        uint8_t	     i_width
    );

    
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
    void PrintTimeStamp( const char *i_Label, const BCD_time8_t & i_ts );

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
    void PrintSectionEnd( bool i_oneOnly = false );


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
    void PrintAsciiString( const char *  i_val );
 
    /**
     *  @brief Specialized Hex word printer
     *  
     *  The SRC hex words require some special formatting to
     *  ensure they are aligned
     *
     *  @param	i_words[]
     *	    Array of 8 hex words
     *
     */
    void PrintHexWords(
	const uint32_t i_words[SRCI_MAX_HEX_WORD_COUNT]
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
    void PrintFlag(
	const char * i_label,
	uint32_t     i_value,
	uint32_t     i_flag
    );

    /**
     *  @brief Translate & display the log actions
     *
     *  The log actions status is a set of flags and therefore this
     *  interface will forward it's request to PrintList
     *  
     *  @param	i_val
     *	    Action flags
     *
     *  @return None
     *  
     */
    void PrintActionStatus( bool i_hmcack, uint8_t i_state, bool i_ammack = false );
    
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
    void PrintActions( uint16_t i_val );

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
    void PrintList(
	K			    i_Key,
	const errl::HashFlagItem< K, V > *i_Table,
	int			    i_Sz
    );


    private:
    
    
    /**
     *  @brief Validates a label (attribute name or element name )
     *
     *  Convert a string label into a well formed XML label
     *  by removing spaces, removing illegal characters, and forcing mixed case.
     *  
     *  @param	i_label		attribute or element name
     *  @param	i_isElement	is it an attribute or element name
     *
     *  @return new validate string
     *  
     */
    std::string makeCleanXmlLabel( const char * i_label, bool i_isElement = false );
    
    /**
     *  @brief Validates String value
     *
     *  Convert a string value int a well formed XML string value
     *  by removing spaces, removing illegal characters, and forcing mixed case.
     *  
     *  @param	i_string     string value
     *
     *  @return new validated string
     *  
     */
    std::string makeValidStringValue( const char * i_string );

    /**
     *  @brief Checks if character is NOT on banned list
     *
     *  Checks if character is not on banned list and changes it
     *  accordingly if it is
     *  
     *  @param	i_char	    character being checked
     *
     *  @return bool	    true - character is valid, 
     *			    false - charater is not valid, is changed
     *  
     */
    bool isValidChar( char & i_char );

	
    
    stack_t	iv_stack;	    ///< std::string stack

};



#endif //ERRLXMLPARSER_H
