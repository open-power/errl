/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcioptsctn.H>
#include <errlutility.H>
#include <srciutility.H>
#include <cstring>

#include <errlparser.H>
#include <string>


/*****************************************************************************/
// F O R W A R D S
/*****************************************************************************/
void srciPrintSectionType( ErrlParser & i_parser, uint8_t i_type );


/*****************************************************************************/
// Object print
/*****************************************************************************/
void SrciOptSctn::print(
    ErrlParser & i_parser
) const
{
    
    srciPrintSectionType( i_parser, SectionType() ) ;
    i_parser.PrintBlank();


    i_parser.PrintAddSections( iv_flags, SRCI_ADDITIONAL_SECTIONS );

}


/*****************************************************************************/
// Print the section type
/*****************************************************************************/
void srciPrintSectionType( ErrlParser & i_parser, uint8_t i_type )
{
    const char *l_msg = 0;
    
    if ( i_type == SrciOptSctn::CALLOUT_SCTN )
    {
	l_msg = i_parser.LoadMsg( ERRL_MSG_FRU_CALL_SEC );
    }
    else
    {
	l_msg = i_parser.LoadMsg( ERRL_MSG_UNKNOWN_TYPE );
    }

    i_parser.PrintHeading( l_msg );
}


