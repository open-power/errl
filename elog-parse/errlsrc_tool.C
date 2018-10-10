/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlentry.H>
#include <errlsrc.H>
#include <srcisrc.H>
#include <srciutility.H>
#include <srcicalloutsctn.H>
#include <errlusrparser.H>
#include <errlplugincenter.H>
#include <errltoolutils.H>


/*****************************************************************************/
// Object parse
/*****************************************************************************/
void ErrlSrc::print(
    ErrlParser & i_parser,
    ErrlSrc    & i_obj
)
{
    // Locals
    uint32_t	l_wc = 0;	// Valid Word Count
    
    // Print the header
    i_obj.iv_header.print( i_obj.flatSize(),  i_parser );

    // PRINT SRC
    i_parser.PrintNumber( "SRC Format", "0x%02X", i_obj.iv_src->format() );
    i_parser.PrintSrcVersion( i_obj.iv_src->iv_version );
    i_parser.PrintVirtualSRCbit( i_obj.iv_src->VirtualSrc() );
    i_parser.PrintI5SEbit( i_obj.iv_src->I5SELogBit() ); 
    i_parser.PrintHypDumpBit( i_obj.iv_src->HypDump() ); 
    i_parser.PrintSpcnFault( i_obj.iv_src->SpcnFault() );
	
    if ( i_obj.iv_src->format() == SRCI_FIPS_FORMAT )
    {
	i_parser.PrintSourceFSP( i_obj.iv_src->FspA() ? "A" : ( i_obj.iv_src->FspB() ? "B" : "Unknown" ) );
	i_parser.PrintSysBackPlane( i_obj.iv_src->SystemType() );
	
	if ( i_obj.iv_src->LastProgressCode() )
	{
	    i_parser.PrintNumber( "Last Progress Code","0x%08X", i_obj.iv_src->LastProgressCode() ); 
	}

	i_parser.PrintNumber( "System IPL State", "0x%02X", i_obj.iv_src->SysIplState() );
	i_parser.PrintNumber( "SP Dump Status", "0x%02X", i_obj.iv_src->SpDumpStatus() );
	i_parser.PrintNumber( "Platform IPL Mode", "0x%02X", i_obj.iv_src->PlatformIplMode() );
	i_parser.PrintNumber( "Platform Dump Status", "0x%02X", i_obj.iv_src->PlatformDumpStatus() );
	i_parser.PrintNumber( "Partition IPL Type", "0x%02X", i_obj.iv_src->ParitionIplType() );
	i_parser.PrintNumber( "Partition Dump Status", "0x%02X", i_obj.iv_src->PartitionDumpStatus() );
    }

    if( (i_obj.iv_src->format() == SRCI_FIPS_FORMAT) || (i_obj.iv_src->format() == SRCI_HBT_FORMAT))   
    {
	i_parser.PrintBool( "Deconfigured", i_obj.iv_src->Deconfigured() );
	i_parser.PrintBool( "Garded", i_obj.iv_src->Garded() );
    }
												
    if( i_obj.iv_src->format() == SRCI_HBT_FORMAT )
    {
	i_parser.PrintBool( "Acknowledged", (!i_obj.iv_src->GetAckBit()) );
    }
											
    if ( i_obj.iv_src->format() == SRCI_FIPS_FORMAT )
    {
	i_parser.PrintTermState( i_obj.iv_src->readTermState() );
	i_parser.PrintClockState( i_obj.iv_src->ClockStates() );
	i_parser.PrintSrcErrorCount( i_obj.iv_src->ErrorCount() );
        i_parser.PrintBool( "ResetReload", i_obj.iv_src->getResetReload() );                           
        i_parser.PrintBool( "Termination", i_obj.iv_src->getFspTerminate() );                          
        i_parser.PrintBool( "Possible RR", i_obj.iv_src->getPossibleRsrlBit() );                      
    }
    
    i_parser.PrintBlank();
    i_parser.PrintNumber( "Valid Word Count", "0x%02X", i_obj.iv_src->iv_wordCount+1 );
    
    if ( i_obj.iv_src->format() == SRCI_FIPS_FORMAT )
    {
	i_parser.PrintModId( i_obj.iv_src->moduleId() );
    }
    
    // Ascii String + Hex Words
    i_parser.PrintAsciiString( i_obj.iv_src->getAsciiString() );
    i_parser.PrintHexWords( i_obj.iv_src->getHexData( l_wc ) );
    i_parser.PrintBlank();
    
    // Callouts
    if ( i_obj.iv_src->iv_callouts )
    {
	i_obj.iv_src->iv_callouts->print( i_parser );
	i_parser.PrintBlank();
    }

    // Load Plugin and parse if found
    if ( errl::PluginCenter::Instance()->LoadPlugin( i_parser.Parent()->creatorSubSys(), i_obj.compId() ) )
    {
	errl::PluginCenter::Instance()->CallSrcPlugin(
	    i_obj.compId(),
	    dynamic_cast< ErrlUsrParser & > ( i_parser ),
	    *i_obj.SRC(),
            i_parser.Parent()->creatorSubSys()
	    );
    }
    
    i_parser.PrintSectionEnd();
}

