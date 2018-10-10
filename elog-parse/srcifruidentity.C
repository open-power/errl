/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcifruidentity.H>
#include <cstring>
#include <utilstream.H>
#include <errlutility.H>
#include <srciutility.H>
#include <srcisrc.H>

#include <errlparser.H>

#include <string>
#include <ctype.h>


/*****************************************************************************/
// Fru Callout
/*****************************************************************************/
SrciFruIdentity::SrciFruIdentity(
    const char * i_pn,
    const char * i_ccin,
    const char * i_sn,
    ErrlBase &	 i_parent
)
: SrciSubSt( SrciSubSt::SST_FRU_IDENTITY, i_parent )
{
    // Flags
    FailingCompType( SRCI_FCT_NORMAL_HW_FRU );

    // Invariants
    PartNumber( i_pn );
    ccin( i_ccin );
    SerialNumber( i_sn );
}



/*****************************************************************************/
// Copy-constructor
/*****************************************************************************/
SrciFruIdentity::SrciFruIdentity(
    const SrciFruIdentity & i_right,
    ErrlBase &		    i_parent
)
: SrciSubSt( i_right, i_parent )
{
    memcpy( iv_number, i_right.iv_number, SRCI_FRU_PART_NUMBER_LEN );
    memcpy( iv_ccin, i_right.iv_ccin, SRCI_FRU_CCIN_LEN + 1);
    memcpy( iv_serial, i_right.iv_serial, SRCI_FRU_SERIAL_LEN + 1);
}


/*****************************************************************************/
// Import Constructor
/*****************************************************************************/
SrciFruIdentity::SrciFruIdentity(
    UtilStream &    i_input,
    const Header &  i_hdr,
    ErrlBase &	    i_parent
)
: SrciSubSt( i_input, i_hdr, i_parent )
{
    // Invalidate all fields
    strcpy( iv_number, "INVALID");
    strcpy( iv_ccin, "XXXX" );
    strcpy( iv_serial,"INVALID" );

    if ( iv_header.iv_flags & FRU_PART_NUMBER_SUPPLIED ||
	 iv_header.iv_flags & MAINTENANCE_PROC_SUPPLIED )
    {
	i_input.read( iv_number, SRCI_FRU_PART_NUMBER_LEN );
	iv_number[SRCI_FRU_PART_NUMBER_LEN - 1] = 0;
    }
    if ( iv_header.iv_flags & CCIN_SUPPLIED )
    {
	i_input.read( iv_ccin, SRCI_FRU_CCIN_LEN );
	iv_ccin[SRCI_FRU_CCIN_LEN] = 0;
    }
    if ( iv_header.iv_flags & SERIAL_NUMBER_SUPPLIED )
    {
	i_input.read( iv_serial, SRCI_FRU_SERIAL_LEN );
	iv_serial[SRCI_FRU_SERIAL_LEN] = 0;
    }
}



/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciFruIdentity::~SrciFruIdentity()
{
}


/*****************************************************************************/
// Set the part number
/*****************************************************************************/
void SrciFruIdentity::PartNumber(
    const char *i_part
)
{
    if ( i_part )
    {
	// Skip Leading Whitespace
	while ( isspace( i_part[0] ) )  ++i_part;

	strncpy( iv_number, i_part, SRCI_FRU_PART_NUMBER_LEN );
    }
    else
    {
	strncpy( iv_number, "INVALID", SRCI_FRU_PART_NUMBER_LEN );
    }
    
    iv_number[SRCI_FRU_PART_NUMBER_LEN - 1] = 0;

    iv_header.iv_flags |= FRU_PART_NUMBER_SUPPLIED;
    iv_header.iv_flags &= ( ~MAINTENANCE_PROC_SUPPLIED );
}


/*****************************************************************************/
// Read the part number
/*****************************************************************************/
const char *SrciFruIdentity::PartNumber() const
{
    const char * l_rc = 0;

    if ( iv_header.iv_flags & FRU_PART_NUMBER_SUPPLIED )
    {
	l_rc = iv_number;
    }

    return l_rc;
}



/*****************************************************************************/
// Read the procedure number
/*****************************************************************************/
const char *SrciFruIdentity::ProcedureNumber() const
{
    const char * l_rc = 0;

    if ( iv_header.iv_flags & MAINTENANCE_PROC_SUPPLIED )
    {
	l_rc = iv_number;
    }

    return l_rc;
}





/*****************************************************************************/
// Set the ccin
/*****************************************************************************/
void SrciFruIdentity::ccin(
    const char *i_ccin
)
{
    if ( i_ccin )
    {
	strncpy( iv_ccin, i_ccin, SRCI_FRU_CCIN_LEN );
    }
    else
    {
	strncpy( iv_ccin, "XXXX", SRCI_FRU_CCIN_LEN );
    }
    
    iv_ccin[SRCI_FRU_CCIN_LEN] = 0;

    iv_header.iv_flags |= CCIN_SUPPLIED;
}


/*****************************************************************************/
// Read the ccin
/*****************************************************************************/
const char *SrciFruIdentity::ccin() const
{
    const char * l_rc = 0;
    
    if ( iv_header.iv_flags & CCIN_SUPPLIED )
    {
	l_rc = iv_ccin;
    }

    return l_rc;
}


/*****************************************************************************/
// Set the serial number
/*****************************************************************************/
void SrciFruIdentity::SerialNumber(
    const char *i_fsn
)
{
    if ( i_fsn )
    {
	strncpy( iv_serial, i_fsn, SRCI_FRU_SERIAL_LEN );
    }
    else
    {
	strncpy( iv_serial, "INVALID", SRCI_FRU_SERIAL_LEN );
    }
    
    iv_serial[SRCI_FRU_SERIAL_LEN] = 0;

    iv_header.iv_flags |= SERIAL_NUMBER_SUPPLIED ;
}


/*****************************************************************************/
// Read the serial number
/*****************************************************************************/
const char *SrciFruIdentity::SerialNumber() const
{
    const char * l_rc = 0;
    
    if ( iv_header.iv_flags & SERIAL_NUMBER_SUPPLIED )
    {
	l_rc = iv_serial;
    }

    return l_rc;
}




/*****************************************************************************/
// Export size
/*****************************************************************************/
uint32_t SrciFruIdentity::flatSize() const
{
    uint32_t l_rc;

    l_rc = iv_header.flatSize();
    
    if ( PartNumber() || ProcedureNumber() )
    {
	l_rc += SRCI_FRU_PART_NUMBER_LEN;
    }
    if ( ccin() )
    {
	l_rc += SRCI_FRU_CCIN_LEN;
    }
    if ( SerialNumber() )
    {
	l_rc += SRCI_FRU_SERIAL_LEN;
    }

    return l_rc;
}


/*****************************************************************************/
// Object print
/*****************************************************************************/
void SrciFruIdentity::print(
    ErrlParser	& i_parser
) const
{

    if ( PartNumber() )
    {
	i_parser.PrintPartNumber( PartNumber() );
    }
    if ( ProcedureNumber() )
    {
	i_parser.PrintProcNumber( ProcedureNumber() );
    }
    if ( ccin() )
    {
	i_parser.PrintCCIN( ccin() );
    }
    if ( SerialNumber() )
    {
	i_parser.PrintSerialNumber( SerialNumber() );
    }
    
}


/*****************************************************************************/
// Set the failing component type
/*****************************************************************************/
void SrciFruIdentity::FailingCompType( srcifct i_type )
{
    srcifct l_type = (srcifct)( iv_header.iv_flags & 0xF0 );  // Current flag type

    // ignore user request if current type is same type requested by user 
    if ( l_type != i_type )
    {
	// Procedure Type
	if ( ( i_type == SRCI_FCT_MAINTENANCE_PROC_REQ ) ||
	     ( i_type == SRCI_FCT_CONFIG_ERR_PROC_REQ ) )
	{
		//clear flag type & bits
		iv_header.iv_flags &= 0x00;

		//add procedure callout bit
		iv_header.iv_flags |= MAINTENANCE_PROC_SUPPLIED; // 0x02

		//clean up unnecessary fields
		// Note: iv_number is not cleared since it may contain
		// a procedure id since field is "shared"
		memset( iv_ccin, 0x00, sizeof( iv_ccin ) );  	
		memset( iv_serial, 0x00, sizeof( iv_serial ) );  
		
		//set caller's failing component type
	    	iv_header.iv_flags |= (uint8_t)i_type;

	} // FRU Type
	else if (   ( i_type == SRCI_FCT_NORMAL_HW_FRU ) ||
		    ( i_type == SRCI_FCT_CODE_FRU ) ||
		    ( i_type == SRCI_FCT_EXTERNAL_FRU ) ||
		    ( i_type == SRCI_FCT_EXTERNAL_CODE_FRU ) ||
		    ( i_type == SRCI_FCT_TOOL_FRU ) ||
                    ( i_type == SRCI_FCT_SYMBOLIC_FRU ) ||
		    ( i_type == SRCI_FCT_SYMBOLIC_FRU_WITH_LOC )    ) 
	{
		//clear flag type 
		iv_header.iv_flags &= 0x0F;
		
		//clear procedure bit
		iv_header.iv_flags &= ( ~( MAINTENANCE_PROC_SUPPLIED ) );

		//add fru bit
		iv_header.iv_flags |= FRU_PART_NUMBER_SUPPLIED; // 0x08 

		//set caller's failing component type
	    	iv_header.iv_flags |= (uint8_t)i_type;
	}
 
    }

}
