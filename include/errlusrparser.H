#ifndef ERRLUSRPARSER_H
#define ERRLUSRPARSER_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlparser.H>

/*****************************************************************************/
// User Types
/*****************************************************************************/
class ErrlUsrParser : public ErrlParser
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
    ErrlUsrParser(
	FILE *		    i_output = stdout,
	const errlHndl_t    i_parent = 0
    )
    : ErrlParser( i_output, i_parent )
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
    void Begin(
	const char * i_Fmt
	...
    );
    
    
    
    
    /**
     *  @brief Finalize device output
     *
     *  Depending on the parser, the output may need to emit
     *  some sort of closure ( i.e. end a table in html ) and
     *  this is made possible though this method.
     *  
     */
    void End( void );
    
    
    /**
     *  @brief Send a division ( section marker )
     *
     *  In console mode, a line is displayed and a table row
     *  is sent to the output in html mode
     *  
     */
    void PrintDivider( void );
    

    
    // Print Blank line
    void PrintBlank();

    
    
    // Heading, centered string
    void PrintHeading(
	const char * i_centered
    );

    
    // String
    void PrintString(
	const char * i_label,
	const char * i_string
    );


    // Hex Dump
    void PrintHexDump(
	const void * i_data,
	uint32_t     i_len
     );


    // Print a Number
    void PrintNumber(
	const char * i_label,
	const char * i_fmt,
	uint32_t     i_value
    );

   

    // Print a uint64_t Number
    void PrintNumberUint64(
        const char * i_label,
        const char * i_fmt,
        uint64_t     i_value
    ); 
    
    
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
     *  @brief DEPRECATED - Do not use
     *
     *  Old interface to printing a heading
     *  
     *  @param	i_centered
     *	    Centered string
     *
     *  @return None
     *
     *  @note DO NOT REMOVE AS IT IS CURRENTLY BEING USED
     *        BY AT LEAST: DMAE, NETS AND SURV
     *  
     */
    void heading(
	const char * i_centered
    )
    {
	PrintHeading( i_centered );
    }

    
};



#endif //ERRLUSRPARSER_H
