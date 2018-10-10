#ifndef ERRLTOOLUTILS_H
#define ERRLTOOLUTILS_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <errlusrparser.H>
#include<errlutility.H>

/*****************************************************************************/
// Globals
/*****************************************************************************/
extern ErrlUsrParser	g_Parser;


namespace errl {

/*****************************************************************************/
// Constants
/*****************************************************************************/
const uint32_t ERRL_MAX_LIB_NAME    = 20;


/*****************************************************************************/
// Prototypes
/*****************************************************************************/

/**
 *  @brief Load a plugin symbol
 *
 *  A plugin library with the name lib'SubSystem'-XXXX.so ( where 'SubSystem'
 *  is the subsystem id in ascii and XXXX is the 4 digit hex code for the
 *  component ) is loaded and the requested symbol entry point is obtained
 *  
 *  @param  i_ssid
 *	Creator Subsystem value
 *
 *  @param  i_cid
 *	Component Id
 *
 *  @param  i_EntryPoint
 *	Desired entry point name
 *
 *  @return Symbol Pointer if found, 0 otherwise
 *
 *  @note A plugin library with the name lib'SubSystem'-XXXX.so is looked for
 *        and loaded if possible.
 *  
 */
void * LoadPluginSymbol(
    errlCreator i_ssid,
    comp_id_t	i_cid,
    const char *i_EntryPoint
);



/**
 *  @brief Lookup a state value in a table
 *
 *  Returns the text string associated with the given log state
 *  
 *  @param  i_val
 *	Binary value
 *
 *  @return Text string
 *
 *  @note If not found, the string "Unknown" is returned
 *  
 */
const char * LookupState( uint8_t i_val );



/**
 *  @brief Short-hand log scope printing
 *  
 *  Maps the log scope to the string representation and outputs
 *  it to the given parser object
 *
 *  @param  i_parser
 *	Output device
 *
 *  @param  i_val
 *	Binary scope
 *
 */
void PrintScope( 
    ErrlParser &i_parser,
    uint8_t	i_val 
);



/**
 *  @brief Short-hand log status printing
 *  
 *  Maps the log status to the string representation and outputs
 *  it to the given parser object
 *
 *  @param  i_parser
 *	Output device
 *
 *  @param  i_val
 *	Binary status
 *
 */
void PrintStatus(
    ErrlParser &i_parser,
    uint16_t	i_val 
);



/**
 *  @brief Short-hand subsystem printing
 *  
 *  Maps the subsystem to the string representation and outputs
 *  it to the given parser object
 *
 *  @param  i_parser
 *	Output device
 *
 *  @param  i_val
 *	Binary subsystem
 *
 */
void PrintCreatorSubSystem( 
    ErrlParser &i_parser,
    uint8_t	i_val 
);




/**
 *  @brief Short-hand log scope printing
 *  
 *  Maps the log scope to the string representation and outputs
 *  it to the given parser object
 *
 *  @param  i_parser
 *	Output device
 *
 *  @param  i_val
 *	Binary scope
 *
 */
void PrintScope( 
    ErrlParser &i_parser,
    uint8_t	i_val 
);




/**
 *  @brief Display the component name
 *
 *  Maps the component id to the string representation and outputs
 *  it to the given parser object
 *  
 *  @param  i_parser
 *	Output device
 *
 *  @param  i_label
 *	Format label
 *
 *  @param  i_cid
 *	Component Id
 *
 */
void PrintCompName(
    ErrlParser &i_parser,
    const char *i_label,
    comp_id_t	i_cid
);



/**
 *  @brief Load and lookup the component name
 *
 *  Lookup the component name given it's Id
 *  
 *  @param  i_cid
 *	Component Id
 *
 *  @return Pointer to string regardless of lookup
 *
 */
const char * LookupCompName( comp_id_t i_cid,uint32_t i_val = 0);



/**
 *  @brief Reverse of the above - Map name to id
 *  
 *  Lookup the component Id given it's name
 *
 *  @param  i_Name
 *	Component Name: const char *
 *
 *  @return Component Id if found, 0 otherwise
 *
 */
comp_id_t LookupCompId( const char * i_Name );




/**
 *  @brief Return string representation of subsystem
 *  
 *  @param  i_val
 *	Binary value
 *
 *  @return Pointer to string ( may be a static string with
 *          the "unknown - value" format
 *
 */
const char *LookupSeverity( uint32_t i_val );



/**
 *  @brief Display the section header
 *
 *  The Section header involves a couple of dividers plus
 *  a centered message
 *  
 *  @param  i_parser
 *	Output device
 *
 *  @param  i_val
 *	Header value to be translated
 *
 */
void PrintSectionHeader(
    ErrlParser &i_parser,
    uint32_t	i_val
);




} // namespace
#endif //ERRLTOOLUTILS_H
