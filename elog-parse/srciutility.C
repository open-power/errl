/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <cstdio>
#include <srciutility.H>
#include <srcisrc.H>
#include <cstdlib>
#include <utilendian.H>

#include <errlentry.H>

#include <errno.h>

#include <errlparser.H>
#include <srci_service_codes.H>

/*****************************************************************************/
// Convert an enumerated priority to it's text counter part
/*****************************************************************************/
uint8_t srciPrioritize( srciPriority i_priority )
{
    uint8_t l_rc = 0;

    switch ( i_priority )
    {
	case SRCI_PRIORITY_HIGH:
	    l_rc = 'H';
	    break;
	case SRCI_PRIORITY_MED:
	    l_rc = 'M';
	    break;
	case SRCI_PRIORITY_MEDA:
	    l_rc = 'A';
	    break;
	case SRCI_PRIORITY_MEDB:
	    l_rc = 'B';
	    break;
	case SRCI_PRIORITY_MEDC:
	    l_rc = 'C';
	    break;
	case SRCI_PRIORITY_LOW:
	    l_rc = 'L';
	    break;
	default:
	    l_rc = 'L';
    }

    return l_rc;

}


/*****************************************************************************/
// Convert a text priority to it's enumerated counter part
/*****************************************************************************/
srciPriority srciPrioritize( uint8_t i_priority )
{
    srciPriority l_rc;

    switch ( i_priority )
    {
	case 'H':
	    l_rc = SRCI_PRIORITY_HIGH;
	    break;
	case 'M':
	    l_rc = SRCI_PRIORITY_MED;
	    break;
	case 'A':
	    l_rc = SRCI_PRIORITY_MEDA;
	    break;
	case 'B':
	    l_rc = SRCI_PRIORITY_MEDB;
	    break;
	case 'C':
	    l_rc = SRCI_PRIORITY_MEDC;
	    break;
	case 'L':
	    l_rc = SRCI_PRIORITY_LOW;
	    break;
	default:
	    l_rc = SRCI_PRIORITY_LOW;
    }

    return l_rc;

}

