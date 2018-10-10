/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlentry.H>
#include <errlud.H>
#include <errlusrparser.H>
#include <errlplugincenter.H>
#include <errltoolutils.H>


/*****************************************************************************/
// User data parsing
/*****************************************************************************/
void ErrlUD::print(
    ErrlParser & i_parser,
    ErrlUD & i_obj
) 
{
    
    // Locals
    bool    l_parsed = false;   // Parse success indicator

    // Print Header
    i_obj.iv_header.print( i_obj.flatSize(), i_parser );

    // Load Plugin and parse if found
    if ( errl::PluginCenter::Instance()->LoadPlugin( i_parser.Parent()->creatorSubSys(), i_obj.compId() ) )
    {
	l_parsed = errl::PluginCenter::Instance()->CallDataPlugin(
	    i_obj.compId(),
	    dynamic_cast< ErrlUsrParser & > ( i_parser ),
	    i_obj.data(),
	    i_obj.dataSize(),
	    i_obj.version(),
	    i_obj.sst(),
            i_parser.Parent()->creatorSubSys()
	    );
    }
    
    // Default behavior
    if ( l_parsed == false )
    {
	// Hex dump
	i_parser.PrintBlank();
	i_parser.PrintHexDump( i_obj.iv_Data, i_obj.iv_Size );
	i_parser.PrintBlank();
    }
	
    i_parser.PrintSectionEnd();

}



