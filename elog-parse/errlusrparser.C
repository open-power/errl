/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlusrparser.H>
#include <cstring>
#include <ctype.h>
#include <cstdarg>


/*****************************************************************************/
// Send the label & return # of chars printed
/*****************************************************************************/
static int PrintLabel(
                     FILE *   i_stream,
                     const char * i_label
                     )
{
    if ( ! i_label )
    {
        i_label = "";
    }

    return fprintf(i_stream,"| %-25.25s: ",i_label);
}


/*****************************************************************************/
// Output Init
/*****************************************************************************/
void ErrlUsrParser::Begin( const char * i_Fmt, ... )
{
    // Locals
    va_list ap;

    va_start( ap, i_Fmt );
    ErrlParser::PrintHeading( i_Fmt, ap );
    va_end( ap );
}


/*****************************************************************************/
// Output End
/*****************************************************************************/
void ErrlUsrParser::End( void )
{
    PrintDivider();
}


/*****************************************************************************/
// Divider
/*****************************************************************************/
void ErrlUsrParser::PrintDivider( void )
{
    fprintf( iv_Stream, "|------------------------------------------------------------------------------|\n");
}


/*****************************************************************************/
// Send a blank line
/*****************************************************************************/
void ErrlUsrParser::PrintBlank()
{
    fprintf( iv_Stream, "|%78c|\n",' ' );
}


/*****************************************************************************/
// Centered Heading
/*****************************************************************************/
void ErrlUsrParser::PrintHeading( const char * i_centered )
{
    uint32_t l_strlen;

    // Cover nulls
    if ( ! i_centered )
    {
        i_centered = "";
    }

    // Calc length
    l_strlen = strlen( i_centered );

    // Output
    if ( l_strlen > 78 )
    {
        fprintf(iv_Stream,"|%78.78s|\n",i_centered);
    }
    else
    {
        uint32_t l_leading = ( 78 - l_strlen ) / 2;

        fprintf(iv_Stream, "|%-*c%-*s|\n",l_leading,' ',78-l_leading,i_centered);
    }
}

/*****************************************************************************/
// Regular string ( may be multiline )
/*****************************************************************************/
void ErrlUsrParser::PrintString(
                               const char * i_label,
                               const char * i_string
                               )
{
    // Must make sure the string fits on the available width
    int l_strlen = 0; 
    int l_printed = 0;


    // Ensure String is valid
    if ( i_string )
    {
        l_strlen = strlen( i_string );
    }

    // Fake a blank string
    if ( ! l_strlen )
    {
        l_strlen = 1;
        i_string = " ";
    }

    // Print it out
    while ( l_strlen > l_printed )
    {
        // Leader ( label or blanks )
        PrintLabel( iv_Stream, i_label );

        // label is only printed once
        i_label = "";

        l_printed += fprintf(
                            iv_Stream,
                            "%-50.50s",
                            i_string+l_printed
                            );

        fprintf(iv_Stream,"|\n");
    }
}


/*****************************************************************************/
// Hex Dump
/*****************************************************************************/
void ErrlUsrParser::PrintHexDump(
                                const void * i_data,
                                uint32_t     i_len
                                )
{
    uint32_t i = 0 ;
    uint32_t l_counter = 0;
    uint32_t l_written;
    uint8_t *l_data = (uint8_t*)i_data;

    while ( l_counter < i_len)
    {
        fprintf(iv_Stream,"|   %08X     ",l_counter);

        // Display 16 bytes in Hex with 2 spaces in between
        l_written = 0;
        for ( i = 0; i < 16 && l_counter < i_len; i++ )
        {
            l_written += fprintf(iv_Stream,"%02X",l_data[l_counter++]);

            if ( ! ( l_counter % 4 ) )
            {
                l_written += fprintf(iv_Stream,"  ");
            }
        }

        // Pad with spaces
        fprintf(iv_Stream,"%-*c",43-l_written,' ');

        // Display ASCII -- fk1
        l_written = 0;
        uint8_t l_char;
        for ( ; i > 0 ; i-- )
        {
            l_char = l_data[ l_counter-i ];

            if ( isprint( l_char ) &&
                 ( l_char != '&' ) &&
                 ( l_char != '<' ) &&
                 ( l_char != '>' )
               )
            {
                l_written += fprintf( iv_Stream,"%c",l_char );
            }
            else
            {
                l_written += fprintf( iv_Stream,"." );
            }
        }

        // Pad with spaces -- fk1
        fprintf( iv_Stream,"%-*c|\n",19-l_written,' ' );



    }
}

/*****************************************************************************/
// Numeric Print
/*****************************************************************************/
void ErrlUsrParser::PrintNumber(
                               const char * i_label,
                               const char * i_fmt,
                               uint32_t     i_value
                               ){
    ErrlParser::PrintNumber( i_label, i_fmt, i_value );
}





//ri01a
/*****************************************************************************/
// Numeric Print for uint64_t
/*****************************************************************************/
void ErrlUsrParser::PrintNumberUint64(
                               const char * i_label,
                               const char * i_fmt,
                               uint64_t     i_value
                               ){
    ErrlParser::PrintNumberUint64( i_label, i_fmt, i_value );
}






/*****************************************************************************/
// Hex word formatter
/*****************************************************************************/
void ErrlUsrParser::PrintHexWords(
                                 const uint32_t i_words[SRCI_MAX_HEX_WORD_COUNT]
                                 ){
    char l_tmp[30];
    int  l_printed;

    // Row 1: Label, data, padd
    snprintf( l_tmp, 30, "%s 2 - 5", LoadMsg( ERRL_MSG_USR_DATA ) );
    PrintLabel( iv_Stream, l_tmp );
    l_printed = fprintf( iv_Stream, "%08X %08X %08X %08X", i_words[0],
                         i_words[1], i_words[2], i_words[3] );
    fprintf(iv_Stream,"%-*c|\n",50-l_printed,' ');

    // Row 2: Label, data, padd
    snprintf( l_tmp, 30, "%s 6 - 9", LoadMsg( ERRL_MSG_USR_DATA ) );
    PrintLabel( iv_Stream, l_tmp );
    l_printed = fprintf( iv_Stream, "%08X %08X %08X %08X", i_words[4],
                         i_words[5], i_words[6], i_words[7] );
    fprintf(iv_Stream,"%-*c|\n",50-l_printed,' ');
}



