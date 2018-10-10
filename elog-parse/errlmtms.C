/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlmtms.H>
#include <utilstream.H>
#include <cstring>
#include <errlbase.H>
#include <errlparser.H>

/*****************************************************************************/
// Import-constructor
/*****************************************************************************/
ErrlMTMS::ErrlMTMS( UtilStream & i_stream )
{
    unflatten(i_stream);
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlMTMS::~ErrlMTMS()
{
}


/*****************************************************************************/
// Export data size
/*****************************************************************************/
uint32_t ErrlMTMS::flatSize() const
{
    return ( ERRL_MTMS_MTM_LEN + ERRL_MTMS_SERIAL_LEN );
}

    
/*****************************************************************************/
// Data import
/*****************************************************************************/
void ErrlMTMS::unflatten(
    UtilStream &i_stream
)
{
    i_stream.read( iv_mtm, ERRL_MTMS_MTM_LEN );
    i_stream.read( iv_serial, ERRL_MTMS_SERIAL_LEN );
    iv_mtm[ERRL_MTMS_MTM_LEN] = 0;
    iv_serial[ERRL_MTMS_SERIAL_LEN] = 0;
}


void ErrlMTMS::print(
    ErrlParser & i_parser, bool flag
) 
{
    if(flag == false)
    {
        i_parser.PrintMachineType( iv_mtm ); 
        i_parser.PrintSerialNumber( iv_serial );
    }
    else
    {
        i_parser.PrintString( "Reporting Machine Type",iv_mtm);
        i_parser.PrintString( "Reporting Serial Number",iv_serial);
    }
}


