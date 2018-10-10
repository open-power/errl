/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Linux includes
#include <utilstream.H>
#include <errlentry.H>
#include <utilbase.H>


/*****************************************************************************/
// Default Constructor
/*****************************************************************************/
UtilStream::UtilStream()
: iv_eof( false ), iv_lastError( 0 )
{
}


/*****************************************************************************/
// Assignment operator
/*****************************************************************************/
UtilStream & UtilStream::operator= ( const UtilStream & i_right )
{
    if ( &i_right != this )
    {
	delete iv_lastError;
	
	iv_eof = false;
	iv_lastError = 0;

    }

    return *this;
}


/*****************************************************************************/
// Default destructor
/*****************************************************************************/
UtilStream::~UtilStream()
{
    delete iv_lastError;
}


/*****************************************************************************/
// Set the last Error Log
/*****************************************************************************/
void UtilStream::setLastError( errlHndl_t i_error )
{
    delete iv_lastError;
    iv_lastError = i_error;
}


