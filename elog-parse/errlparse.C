
#ifndef _AIX
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlcmdline.H>
#include <errltoolutils.H>
#include <cstring>
#include <cstdlib>
#include <errno.h>


#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

// Globals
int g_ErrlDebugLevel = 0;


// General Flags
enum GeneralFlags
{
        
    DALL	    = 0x0000F001,
    DUMP,
    SINGLE_FILE,
    LTRACE 
	
}; 


const char *argp_program_version =
  "FipS Error Logger 1.99";

const char *argp_program_bug_address =
  "FSP Error Logging Team";

// Program documentation. 
static char doc[] =
    "FipS Error Logger - command line access and control\n";


static char examples[] =
    "Notes:\n"
    "  - Text inputs are not case sensitive\n"
    "  - Identifiers may be entered in decimal or hex ( hex requires 0x prefix )\n"
    "Examples:\n"
    "  errl -d < some_binary_error_log.file     Display an error from a file.\n"
    "  cat errl.bin | errl -d --                Display an error from stdin\n"
    "  errl -d --file=some_binary_error_log     Display an error from a file.\n\n"
    "  NOTE: User must specify a --repository directory option when attempting \n"
    "  a different operation other than the examples listed above.\n" 
    ;

// The options we understand. 
static struct argp_option options[] = 
{
/******************************************************************************/
//name		key	    arg		flags	    doc
{0,		0,	    0,		0,	"Operations"},
{"display",	'd',	    "EntryId",	OPTION_ARG_OPTIONAL,"Display the entry"},
{"long",        LTRACE,     0,          0,      "Option to display the Error log along with hexdump of tracebuffer"},
{0,		0,	    0,		0,	"General options"},
{"repository",  'R',	    "directory", 0,	"Alternate location of the repository. The result must "
						"be a path filename. NOTE: When including this option, "
						"all commands are performed on the repository files "
						"found in the path specified.  Files found in path WILL "
						"NOT be modified, thus options that normally make changes "
						"to ERRL file system files are NOT supported." },
{0,		0,	    0,		0,	"Repository List options"}, 
{0,		0,	    0,		0,	"Error Log Parse/Display options"},
{"file",	SINGLE_FILE,"filename",	0,	"Ignores the repository and attempts to build a log "
						"based on the data read from this file. It then     "
						"proceeds to display it.                            "
						},
{"full",	0,	    0,		0,	"Full parse of the entry (default)"},
{"raw",		'x',	    0,		0,	"Hex dump of the entry"},
{"xml",		'X',	    0,		0,	"XML output of the entry"},
{"outdir",	'o',	    "directory",	0,	"output directory of the entry"},
{"version",	'v',        0,          0,      "Display detailed version of the tool"},
{"hbtrace",     't',        "hbotStringFile",  0,      "Hostboot trexStringFile"},   
{"fsptrace",    's',        "trexStringFile",  0,      "FSP trexStringFile"},   
{"skipTrace",   'S',        0,         0,     "Skip decoding traces"},
{0,		0,	    0,		OPTION_DOC,examples},
{0}
};

// Arguments structure
struct argp argp = { options, parse_opt, 0, doc };


// Parse a single option. 
error_t parse_opt(int key, char *arg, struct argp_state *state)
{
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *args = (struct arguments*)state->input;
  error_t   l_rc = 0;

    switch (key)
    {
	case ARGP_KEY_INIT:
	    // Default the filename to stdin
	    args->iv_filename = "stdin";
            args->iv_outdir = ".";
	    break;

	case ARGP_KEY_END:
	    break;

	case ARGP_KEY_SUCCESS:
	    if ( args->iv_operation == NONE )
	    {
		argp_error( state, "Missing operation" );
	    }
	    else if ( args->iv_operation == DISPLAY )
	    {
		if ( (args->iv_dump == false) && (args->iv_dall == false) && (!args->iv_filename) )
		{
		    if ( args->iv_eid == 0 )
		    {
			argp_error( state, "Unknown Identifier: %s\n", arg );
		    }
		}
	    }
	    break;

	case 'R':
	    args->iv_repository = arg;
	    break;

	case DUMP:
	    args->iv_dump = true;
	    break;
	    
	case 'd':
	    args->iv_operation = DISPLAY;
	    
	    if ( !args->iv_eid && arg)
	    {
		args->iv_eid = strtoul(arg,0,0);
	    }
	    
	    break;
	
         case 'v':
            args->iv_operation = VERSION;
            break;

	case SINGLE_FILE:
	    args->iv_filename = arg;
	    break;

        case 'o':
            args->iv_outdir = arg;
            break;
        
        case 'S':
            args->iv_skipTrace = true;
            break;
        
        case 't':
            args->iv_trace = arg;
            break;

	case 'x':
	    args->iv_ptype = RAW;
	    break;
	
	case 'X':
	    args->iv_xml = true;
	    break;

	case ARGP_KEY_ARG:
	    if (state->arg_num > 1)
	    {
		argp_error ( state, "Invalid arguments" );
	    }

	    if ( arg && ( (args->iv_operation == DISPLAY)) 
		     && (!args->iv_eid))
	    {
		args->iv_eid = strtoul(arg,0,0);
	    }
	    
	    break;


    case LTRACE:
         args->iv_ltrace = true;
         break;

	default:
	    l_rc = ARGP_ERR_UNKNOWN;

    }

  return l_rc;

}
#endif



