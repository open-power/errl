/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <srcisrc.H>
#include <srcicallout.H>
#include <srcicalloutsctn.H>
#include <errlmtms.H>
#include <srcimru.H>
#include <srcipce.H>
#include <utilstream.H>
#include <utilmem.H>
#include <utilbase.H>
#include <utilfile.H>


#include <utilendian.H>

#include <cstring>
#include <cstdlib>
#include <srciutility.H>
#include <errlutility.H>
#include <errlentry.H>
#include <srci_service_codes.H>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <errlparser.H>
#include <errlusrparser.H>


/*****************************************************************************/
// L O C A L S
/*****************************************************************************/

const uint8_t  SMGR_IPLSTATE_RUNTIME	    = 3;
const uint8_t  SMGR_IPLSTATE_PRESTANDBY        = 0;

enum Local32BitConstants
{
    BIT_DECONFIGURATION		= 0x02000000, 
    BIT_GARDED			= 0x01000000,
    BIT_FSP_A			= 0x00000010,
    BIT_FSP_B			= 0x00000020,
    SRCI_IPL_STATUS_COMPLETE	= 0x40000000,
    BIT_RESETRELOAD             = 0x00800000,  //HexWord 5 bit#8
    BIT_FSPTERMINATE            = 0x00400000,  //HexWord 5 bit#9
    BIT_FSP_ACKNOWLEDGE         = 0x00200000,  //HexWord 5 bit#10 
    BIT_FSPPOSIBLERR            = 0x00100000   //HexWord 5 bit#11
};



/*****************************************************************************/
// Default constructor
/*****************************************************************************/
SrciSrc::SrciSrc()
: ErrlBase( 0 ),
  iv_version( SRCI_FIPS_VER_INVAL ), 
  iv_flags( 0 ), 
  iv_reserved0( 0 ),
  iv_wordCount( SRCI_MAX_HEX_WORD_COUNT ), 
  iv_reserved1( 0 ), 
  iv_srcLength( SRCI_BASELEN ),
  iv_callouts( 0 )
{
    memset( iv_hexWords, 0 , SRCI_MAX_HEX_WORD_COUNT * 4 );
}



/*****************************************************************************/
// Container based default constructor
/*****************************************************************************/
SrciSrc::SrciSrc(
    ErrlBase & i_parent
)
: ErrlBase( i_parent ),
  iv_version( SRCI_FIPS_VER_INVAL ), 
  iv_flags( 0 ), 
  iv_reserved0( 0 ),
  iv_wordCount( SRCI_MAX_HEX_WORD_COUNT ), 
  iv_reserved1( 0 ), 
  iv_srcLength( SRCI_BASELEN ),
  iv_callouts( 0 )
{
    memset( iv_hexWords, 0 , SRCI_MAX_HEX_WORD_COUNT * 4 );
}


/*****************************************************************************/
// Generic Constructor
/*****************************************************************************/
SrciSrc::SrciSrc(
    uint32_t		i_attr,
    const uint32_t	i_hexWords[],
    uint32_t		i_numWords
    )
: ErrlBase( 0 ),
  iv_version( SRCI_FIPS_VERSION1 ), 
  iv_flags( i_attr ), 
  iv_reserved0( 0 ),
  iv_wordCount( 0 ), 
  iv_reserved1( 0 ), 
  iv_srcLength( SRCI_BASELEN ),
  iv_callouts( 0 )
{
    // Clean Hex Data
    memset( iv_hexWords, 0 , SRCI_MAX_HEX_WORD_COUNT * 4 );

    // SRC Flags
    iv_flags &= SRCI_ATTR_MASK;

    /// Translate words
    if ( i_numWords )
    {
	// AsciiString
	iv_asciiString.setString( i_hexWords[0] );

    i_numWords = ( ( i_numWords - 1 ) < SRCI_MAX_HEX_WORD_COUNT ) ? ( i_numWords - 1 ) : SRCI_MAX_HEX_WORD_COUNT;

	memcpy( iv_hexWords, i_hexWords + 1 , i_numWords * 4 );

	// Update the word count
	iv_wordCount = i_numWords;
    }
}


/*****************************************************************************/
// Import Constructor
/*****************************************************************************/
SrciSrc::SrciSrc(
    const srciSrcData_t *i_buffer,
    srcistatus_t	&o_status
)
: ErrlBase( 0 ),
  iv_version( 0 ), 
  iv_flags( 0 ), 
  iv_reserved0( 0 ),
  iv_wordCount( 0 ), 
  iv_reserved1( 0 ), 
  iv_srcLength( 0 ),
  iv_callouts( 0 )
{
    uint16_t	l_Size = 0;

    l_Size = ntohs( i_buffer->iv_totalSize );

    
    if ( l_Size > SRCI_MAX_SIZE )
    {
	
	o_status = SRCI_STATUS_CORRUPT;

    }
    else
    {

	UtilMem l_buf( const_cast< srciSrcData_t* > ( i_buffer ), l_Size );

	o_status = unflatten( l_buf );

    }


}



/*****************************************************************************/
// Copy Constructor
/*****************************************************************************/
SrciSrc::SrciSrc(
    const SrciSrc &i_right
)
: ErrlBase( i_right ),
  iv_callouts( 0 )
{
    *this = i_right;
}


/*****************************************************************************/
// Container based copy-constructor
/*****************************************************************************/
SrciSrc::SrciSrc(
    const SrciSrc & i_right,
    ErrlBase &	    i_parent
)
: ErrlBase( i_parent ),
  iv_callouts( 0 )
{
    *this = i_right;
}



/*****************************************************************************/
// Assignment Operator
/*****************************************************************************/
SrciSrc& SrciSrc::operator=(
    const SrciSrc& i_right
)
{
    if ( &i_right != this )
    {
	// Note: I am explicitly omitting assignment to the base class
	//       because I do NOT want to change the memory container
	//       pointer. Applications such as the cecserver typically
	//       assign their error logs to the perc error log and
	//       if base assignment occurred here, the perc error would
	//       lose it's pointer to the container.

	iv_version = i_right.iv_version;
	iv_flags = i_right.iv_flags;
	iv_reserved0 = i_right.iv_reserved0;
	iv_wordCount = i_right.iv_wordCount;
	iv_reserved1 = i_right.iv_reserved1;
	iv_srcLength = i_right.iv_srcLength;
	
	// Copy Hex data
	memcpy( iv_hexWords, i_right.iv_hexWords , SRCI_MAX_HEX_WORD_COUNT * 4 );

	// Ascii String
	iv_asciiString = i_right.iv_asciiString;

	// Callout Section
	delete iv_callouts;
	iv_callouts = 0;

	if ( i_right.iv_callouts )
	{
	    iv_callouts = new(*this) SrciCalloutSctn( *i_right.iv_callouts, *this );
	}
    }

    return *this;
}



/*****************************************************************************/
// Destructor
/*****************************************************************************/
SrciSrc::~SrciSrc()
{
    delete iv_callouts;
    iv_callouts = 0;
}


/*****************************************************************************/
// Object flat size
/*****************************************************************************/
uint32_t SrciSrc::flattenedSize() const
{
    uint32_t l_rc = SRCI_HEADER_LEN;

    // Plus the hex words
    l_rc += SRCI_MAX_HEX_WORD_COUNT * 4;

    // Plus the ascii string
    l_rc += iv_asciiString.flatSize();

    // Plus the callouts
    if ( iv_callouts && iv_callouts->CalloutCount() > 0 )
    {
	l_rc += iv_callouts->flatSize();
    }
    
    return l_rc;
}


/*****************************************************************************/
// Object Private Import Function
/*****************************************************************************/
srcistatus_t SrciSrc::unflatten(
    UtilStream &i_stream
)
{
    srcistatus_t    l_rc = SRCI_STATUS_SUCCESS;
    uint32_t	    l_erc = 0;

    i_stream >> iv_version;
    i_stream >> iv_flags;
    i_stream >> iv_reserved0;
    i_stream >> iv_wordCount;
    i_stream >> iv_reserved1;
    i_stream >> iv_srcLength;

    for ( uint32_t i = 0; i < SRCI_MAX_HEX_WORD_COUNT; i++ )
    {
	i_stream >> iv_hexWords[i];
    }
    
    iv_asciiString.unflatten( i_stream );
    
    // Decrease hexWordCount by 1 ( legacy )
    iv_wordCount--;
    
    if ( iv_wordCount > SRCI_MAX_HEX_WORD_COUNT )
    {
	l_erc = SRCI_ERC_INVALID;
    }
    else if ( iv_flags & SRCI_ADDITIONAL_SECTIONS )
    {
	getCoSctn()->unflatten( i_stream );
    }
    else
    {
	// delete
	delete iv_callouts;
	iv_callouts = 0;
    }

    
    // Finger Print
    if ( l_erc )
    {
	    l_erc = SRCI_ERC_STREAM;


//	l_rc = SRCI_STATUS_CORRUPT;

    }
    
    return l_rc;
}


/*****************************************************************************/
// Src Type field
/*****************************************************************************/
uint8_t SrciSrc::type() const
{
    return iv_asciiString.Type();
}



/*****************************************************************************/
// Src Format field
/*****************************************************************************/
void SrciSrc::format( uint8_t i_val )
{
    UTIL_SET_BYTE( iv_hexWords[0], i_val, 0 );
}

/*****************************************************************************/
// Src Format field
/*****************************************************************************/
uint8_t SrciSrc::format( ) const
{
    return UTIL_GET_BYTE( iv_hexWords[0], 0 );
}



/*****************************************************************************/
// Read the Internal Module Id
/*****************************************************************************/
uint8_t SrciSrc::moduleId( ) const
{
    return UTIL_GET_BYTE( iv_hexWords[1], 1 );
}


/*****************************************************************************/
// Read Redundant FSP A indicator
/*****************************************************************************/
bool SrciSrc::FspA( void ) const
{
    return ( iv_hexWords[1] & BIT_FSP_A );
}


/*****************************************************************************/
// Read Redundant FSP B indicator
/*****************************************************************************/
bool SrciSrc::FspB( void ) const
{
    return ( iv_hexWords[1] & BIT_FSP_B );
}




/*****************************************************************************/
// Reference Code
/*****************************************************************************/
uint16_t SrciSrc::reasonCode() const
{
    return iv_asciiString.ReasonCode();
}

/*****************************************************************************/
// Ascii String
/*****************************************************************************/
const char *SrciSrc::getAsciiString() const
{
    return iv_asciiString.getString();
}



/*****************************************************************************/
// Hex Data Word access
/*****************************************************************************/
const uint32_t *SrciSrc::getHexData(uint32_t &o_count) const
{
    o_count = iv_wordCount;
    return iv_hexWords;
}


/*****************************************************************************/
// Set some termination flags
/*****************************************************************************/
uint32_t SrciSrc::readTermState() const
{
    uint32_t l_rc = iv_hexWords[3];
    
    // Mask off
    l_rc &= SRCI_TERM_STATE_ALL_FLAGS;

    return l_rc;
}


/*****************************************************************************/
// Read HyperVisor Dump Bit
/*****************************************************************************/
bool SrciSrc::HypDump() const
{
    return ( iv_flags & SRCI_HYPR_DUMP );
}




/*****************************************************************************/
// Read HyperVisor LOG SE Bit
/*****************************************************************************/
bool SrciSrc::I5SELogBit() const
{
    return ( iv_flags & SRCI_HYPR_LOG_SE );
}



/*****************************************************************************/
// Read SPCN Fault indicator
/*****************************************************************************/
bool SrciSrc::SpcnFault( void ) const
{
    return ( iv_flags & SRCI_SPCN_FAULT );
}



/*****************************************************************************/
// Read the deconfig bit
/*****************************************************************************/
bool SrciSrc::Deconfigured( void ) const
{
    return ( iv_hexWords[3] & BIT_DECONFIGURATION );
}


/*****************************************************************************/
// Read the Acknowledge bit
/*****************************************************************************/
bool SrciSrc::GetAckBit( void ) const
{
    return(iv_hexWords[3] & BIT_FSP_ACKNOWLEDGE);
}


/*****************************************************************************/
// Read the deconfig bit
/*****************************************************************************/
bool SrciSrc::Garded( void ) const
{
    return ( iv_hexWords[3] & BIT_GARDED );
}



/*****************************************************************************/
// get SRC Hex Word 5 bit# 8 (Error due to Reset Reload)
/*****************************************************************************/
bool SrciSrc::getResetReload( void ) const
{
    return ( iv_hexWords[3] & BIT_RESETRELOAD);
}


/*****************************************************************************/
// Get SRC Hex Word 5 bit# 11
/*****************************************************************************/
bool SrciSrc::getPossibleRsrlBit( void ) const
{
    return ( iv_hexWords[3] & BIT_FSPPOSIBLERR);
}




/*****************************************************************************/
// Get SRC Hex Word 5 bit# 9 (Error due to FSP Termination)
/*****************************************************************************/
bool SrciSrc::getFspTerminate( void ) const
{
    return ( iv_hexWords[3] & BIT_FSPTERMINATE);
}





/*****************************************************************************/
// Class Print
/*****************************************************************************/
void SrciSrc::print(
    ErrlParser &    i_parser
) const
{
    i_parser.PrintSrcVersion( iv_version );
    i_parser.PrintVirtualSRCbit( VirtualSrc() ); 
    i_parser.PrintI5SEbit( I5SELogBit() ); 
    i_parser.PrintHypDumpBit( HypDump() ); 
    i_parser.PrintSpcnFault( SpcnFault() );
    i_parser.PrintAddSections( iv_flags, SRCI_ADDITIONAL_SECTIONS );
    i_parser.PrintHexWordCnt( iv_wordCount+1 );
   
	
    if ( format() == SRCI_FIPS_FORMAT )
    {
	// only print this field out when it makese sense ( b1 error srcs )
	if ( ( type() == SRCI_ERR_INFO ) || ( type() == SRCI_MACH_CHECK ) )
	{
	    i_parser.PrintSysBackPlane( SystemType() );
	    
	    if ( FspA() )
	    {
		i_parser.PrintSourceFSP( "A" );
	    }
	    else if ( FspB() )
	    {
		i_parser.PrintSourceFSP( "B" );
	    }
	    else
	    {
		i_parser.PrintSourceFSP( i_parser.LoadMsg( ERRL_MSG_UNKNOWN ) );
	    }
	    
	    i_parser.PrintSrcErrorCount( ErrorCount() );

	    i_parser.PrintClockState( ClockStates() );
	}

	i_parser.PrintTermState( readTermState() );
	i_parser.PrintModId( moduleId() );
    }
    else if(format() == SRCI_HBT_FORMAT)
    {
        if ( ( type() == HBT_ERR_INFO ) || ( type() == HBT_MACH_CHECK ) )
        {
            i_parser.PrintSysBackPlane( SystemType() );

            if ( FspA() )
            {
                i_parser.PrintSourceFSP( "A" );
            }
            else if ( FspB() )
            {
                i_parser.PrintSourceFSP( "B" );
            }
            else
            {
                i_parser.PrintSourceFSP( i_parser.LoadMsg( ERRL_MSG_UNKNOWN ) );
            }

            i_parser.PrintSrcErrorCount( ErrorCount() );

            i_parser.PrintClockState( ClockStates() );
        }

        i_parser.PrintTermState( readTermState() );
        i_parser.PrintModId( moduleId() );
    }
    
    // Ascii String + Hex Words
    i_parser.PrintAsciiString( getAsciiString() );
    i_parser.PrintHexWords( iv_hexWords );
    i_parser.PrintBlank();

    // Callouts
    if ( iv_callouts )
    {
	iv_callouts->print( i_parser );
	i_parser.PrintBlank();
    }
    
}


/*****************************************************************************/
// Extract the parition dump status
/*****************************************************************************/
uint8_t SrciSrc::PartitionDumpStatus( ) const
{
    return UTIL_GET_NIBBLE( iv_hexWords[0], 7 );
}



/*****************************************************************************/
// Extract the system ipl state
/*****************************************************************************/
uint8_t SrciSrc::SysIplState( ) const
{
    return UTIL_GET_NIBBLE( iv_hexWords[0], 6 );
}


/*****************************************************************************/
// Read the parition ipl type
/*****************************************************************************/
uint8_t SrciSrc::ParitionIplType( ) const
{
    return UTIL_GET_NIBBLE( iv_hexWords[0], 5 );
}



/*****************************************************************************/
// Read the Sp Dump Status indicator
/*****************************************************************************/
uint8_t SrciSrc::SpDumpStatus( ) const
{
    return UTIL_GET_NIBBLE( iv_hexWords[0], 4 );
}



/*****************************************************************************/
// Read the Platform Ipl Mode
/*****************************************************************************/
uint8_t SrciSrc::PlatformIplMode( ) const
{
    return UTIL_GET_NIBBLE( iv_hexWords[0], 3 );
}



/*****************************************************************************/
// Read the Platform Dump Status
/*****************************************************************************/
uint8_t SrciSrc::PlatformDumpStatus( ) const
{
    return UTIL_GET_NIBBLE( iv_hexWords[0], 2 );
}




/*****************************************************************************/
// Read the system type
/*****************************************************************************/
uint16_t SrciSrc::SystemType( ) const
{
    return UTIL_GET_HWORD( iv_hexWords[1], 1 );
}



/*****************************************************************************/
// Read the value of the last progress code
/*****************************************************************************/
uint32_t SrciSrc::LastProgressCode( ) const
{
    return iv_hexWords[2];
}



/*****************************************************************************/
// Read Clock States
/*****************************************************************************/
uint32_t SrciSrc::ClockStates( void ) const
{
    return iv_hexWords[3];
}




/*****************************************************************************/
// Read the error count
/*****************************************************************************/
uint8_t SrciSrc::ErrorCount( ) const
{
    return UTIL_GET_BYTE( iv_hexWords[3], 0 );
}


/*****************************************************************************/
// Uniform access to the callout section
/*****************************************************************************/
inline SrciCalloutSctn * SrciSrc::getCoSctn()
{
    if ( ! iv_callouts )
    {
	iv_callouts = new(*this) SrciCalloutSctn( *this );
    }
    
    return iv_callouts;
}


