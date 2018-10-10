/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errluh.H>
#include <utilstream.H>
#include <memory>
#include <errl_service_codes.H>
#include <errlparser.H>
#include <errlxmlparser.H>
#include <utilbase.H>
#include <errltoolutils.H>


/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/


/*****************************************************************************/
// Determines if the severity is of "symptom" type
/*****************************************************************************/
bool ErrlUH::isSymptomSev(
    errlSeverity i_sev
) 
{
    bool l_rc = false;

    if( (i_sev == ERRL_SEV_SYMPTOM_RECOVERED) ||
        (i_sev == ERRL_SEV_SYMPTOM_PREDICTIVE) ||
        (i_sev == ERRL_SEV_SYMPTOM_UNRECOV) ||
        (i_sev == ERRL_SEV_SYMPTOM_DIAGERR) )
    {
        l_rc = true;
    }
    return l_rc;
}



/*****************************************************************************/
// Data Import
/*****************************************************************************/
void ErrlUH::unflatten(
    UtilStream &i_stream
)
{
    iv_header.unflatten( i_stream );

    i_stream >> iv_ssid >> iv_scope >> iv_severity >> iv_etype >> iv_rc;
    i_stream >> iv_domain >> iv_vector >> iv_actions;
    i_stream >> iv_reserved1;

    Validate( i_stream );
}


/*****************************************************************************/
// Check if reserved1 Field is being temporarily used by asm or errl tool 
/*****************************************************************************/
bool ErrlUH::reserved1Valid( void )
{
   return ( bool ( UTIL_GET_BYTE( iv_reserved1, 3 ) ) );
}



/*****************************************************************************/
// Object parse
/*****************************************************************************/
void ErrlUH::print(
    ErrlParser & i_parser
) 
{
    // Print the header
    iv_header.print( flatSize(), i_parser );

    i_parser.PrintFailingSubSystem( iv_ssid );

    i_parser.PrintSeverity( iv_severity );

    i_parser.PrintEventType( iv_etype );

    i_parser.PrintNumber("Return Code", "0x%08X", iv_rc );	
    
    i_parser.PrintActions( iv_actions );

    // Print State and HMC ack flag if log has that information
    if ( reserved1Valid() )
    {
	bool	    l_hmcack = UTIL_GET_BYTE( iv_reserved1, 2 );
        bool        l_ammack = UTIL_GET_BYTE( iv_reserved1, 0 );
	errlState   l_state = errlState ( UTIL_GET_BYTE ( iv_reserved1, 1 ) );

        i_parser.PrintActionStatus( l_hmcack, l_state, l_ammack );
    }
}



/*****************************************************************************/
// Validate section
/*****************************************************************************/
void ErrlUH::Validate(
        UtilStream &i_stream
    )
{
    errlHndl_t	l_hndl = 0;
    
    if ( iv_header.iv_sid != ERRL_SID_USER_HEADER ||
         iv_header.iv_ver !=  VER)
    {
      l_hndl = i_stream.getLastError();
    }
}


