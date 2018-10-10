/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdlib.h>		// for strtoul
#include <srciascstr.H>
#include <memory>
#include <cstring>
#include <utilstream.H>
#include <cctype>
#include <srciutility.H>
#include <srcisrc.H>

#include <utilendian.H>

const uint32_t SRCI_ASCSTR_UNUSED_LEN = 24;



uint16_t SrciAsciiString::ReasonCode() const
{
    uint16_t l_rc = 0;

    if ( Type() == SRCI_INTERVENTION_REQ || Type() == SRCI_ERR_INFO || Type() == HBT_INTERVENTION_REQ || Type() == HBT_ERR_INFO )
    {
	l_rc = getLast();
    }

    return l_rc;
}


uint16_t SrciAsciiString::ProgressCode() const
{
    uint16_t l_rc = 0;

    if ( Type() == SRCI_IPL_STATUS || Type() == SRCI_DUMP_STATUS || Type() == HBT_IPL_STATUS || Type() == HBT_DUMP_STATUS )
    {
	l_rc = getLast();
    }

    return l_rc;
}



uint8_t SrciAsciiString::Type() const
{
    uint8_t	l_rc;

    l_rc = ( strtoul(iv_string,0,16) & 0xFF000000 ) >> 24;

    return l_rc;
}


uint8_t SrciAsciiString::getMiddle() const
{
    uint8_t	l_rc;

    l_rc = ( strtoul(iv_string,0,16) & 0x00FF0000 ) >> 16;

    return l_rc;
}


uint16_t SrciAsciiString::getLast() const
{
    uint16_t	l_rc;

    l_rc = ( strtoul(iv_string,0,16) & 0x0000FFFF);

    return l_rc;
}


void SrciAsciiString::setString( uint32_t i_word )
{
    sprintf(iv_string,"%08X",i_word);
}


const char * SrciAsciiString::getString( void ) const
{
    return iv_string;
}

    
void SrciAsciiString::unflatten(
    UtilStream &i_stream
)
{

    //Locals - space for unused 24 bytes
    const char  l_space = ' ';

    // write the ascii 
    i_stream.read( iv_string, SRCI_MAX_ASCII_BYTES );

    // Write the padd
    for ( uint32_t i = (SRCI_MAX_ASCII_BYTES - SRCI_ASCSTR_UNUSED_LEN) ; i < SRCI_MAX_ASCII_BYTES ; i++ )
    {
        iv_string[i] = l_space;
    }

}

