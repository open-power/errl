/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlsctn.H>
#include <errlprvt.H>
#include <errluh.H>
#include <errlsrc.H>
#include <errlud.H>
#include <errlextduh.H>
#include <srcisrc.H>
#include <memory>
#include <utilstream.H>
#include <errlsysmtms.H>

#include <errlED.H>

/*****************************************************************************/
// Section Builder
/*****************************************************************************/
ErrlSctn * ErrlSctn::Create(
    ErrlBase &   i_src,
    UtilStream & i_stream
)
{

    // Locals
    ErrlSctn *	l_rc = 0;	    // Return code
    ErrlSctnHdr	l_hdr;		    // Section Header

    // Read the section header
    l_hdr.unflatten( i_stream );

    // Process the section
    if ( ! i_stream.peekLastError() )
    {
    
	switch ( l_hdr.iv_sid )
	{
	    case ERRL_SID_PRIMARY_SRC:
	    case ERRL_SID_SECONDARY_SRC:
		l_rc = new(i_src) ErrlSrc( i_stream, l_hdr, i_src );
		break;

        case ERRL_SID_EXTENDED_HEADER:
             l_rc = new(i_src) ErrlExtdUH( i_stream, l_hdr, i_src );
              break;

        case ERRL_SID_SOFTWARE_ERROR:
             break;

        case ERRL_SID_MFG_INFORMATION:
             break;

        case ERRL_SID_MACHINE_TYPE:
             l_rc = new(i_src) ErrlSysMtms( i_stream, l_hdr, i_src );
             break;


        case ERRL_SID_CALL_HOME:
             break;

	    case ERRL_SID_USER_DEFINED:
		l_rc = new(i_src) ErrlUD( i_stream, l_hdr, i_src );
		break;
         
        case ERRL_SID_EXT_USER_DEFINED:
             break; 

	    default:
                l_rc = new(i_src) ErrlUD( i_stream, l_hdr, i_src );
//		l_rc = CreateUnknown( i_src, i_stream, l_hdr );
		break;
	    
	}

    }

    return l_rc;

}



/*****************************************************************************/
// Build unknown sections
/*****************************************************************************/
ErrlSctn * ErrlSctn::CreateUnknown(
    ErrlBase &   i_src,
    UtilStream & i_stream,
    ErrlSctnHdr &i_hdr
)
{
    // Locals
    ErrlSctn *	l_rc = 0;	    // Return code
    
    switch ( i_hdr.iv_sid )
    {
	case ERRL_SID_DUMP_LOCATOR:
	    break;

	case ERRL_SID_PARTITION:
	    break;
    
	case ERRL_SID_LOGICAL_RESOURCE:
	    break;
	
	case ERRL_SID_HMC_ID:
	    break;

	case ERRL_SID_EPOW:
	    break;

	case ERRL_SID_IO_EVENT:
	    break;

    case ERRL_SID_EXT_USER_DEFINED:
        l_rc = new(i_src) ErrlED( i_stream, i_hdr, i_src );
        break;
    
    case ERRL_SID_ENV_INFO:
         break; 

	default:
	    l_rc = new(i_src) ErrlUD( i_stream, i_hdr, i_src );
	    break;
	
    }
	
    return l_rc; 

}
