/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <regex.h> 
#include <errlentry.H>
#include <errlusrparser.H>
#include <errlxmlparser.H>
#include <errlcmdline.H>
#include <utilbase.H>
#include <utilfile.H>
#include <utilmem.H>
#include <errl_service_codes.H>
#include <errlusrparser.H>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#ifdef _AIX
#include <popt.h>
#endif
/*****************************************************************************/
// Synonyms
/*****************************************************************************/
typedef std::vector<errlHndl_t>		ToolElogs_t;
typedef std::vector<std::string>    TempFiles_t;

/*****************************************************************************/
// ENUM  s
/*****************************************************************************/
enum toolstatus_t
{
    ERRL_TOOL_SUCCESS		= 0x00,
    ERRL_TOOL_DISPLAY_FILEENTRY	= 0x02,
};

const uint32_t ERRL_ENTRY_MAX = 16384;

char      g_buffer[ERRL_ENTRY_MAX];
TempFiles_t     g_TempFiles;
TempFiles_t g_TempFilesHB;

/*****************************************************************************/
// F o r w a r d s
/*****************************************************************************/
toolstatus_t errlDisplayEntryFromFile( arguments & i_args);
errlstatus_t errlLoadLogs( arguments & i_args, ToolElogs_t & o_list );
void errlPrintLog( ErrlEntry & i_Log, arguments & i_args );
void errlDisplayVersion(void);
/*****************************************************************************/
// Global
/*****************************************************************************/
ErrlUsrParser	g_Parser( stdout );


using namespace std;


/*****************************************************************************/
// Executable entry point
/*****************************************************************************/
int main (int argc, char **argv)
{
    toolstatus_t l_rc = ERRL_TOOL_SUCCESS; 
    // Argument table: Set to defaults
    arguments args;
    memset(&args,0,sizeof(args));

#ifndef _AIX
    /* Parse our arguments; every option seen by parse_opt will
    be reflected in arguments. */
    argp_parse (&argp, argc, argv, 0, 0, &args);

    // Decode command line
    switch ( args.iv_operation )
    {
	case DISPLAY:
        if (args.iv_filename)
        {
            l_rc = errlDisplayEntryFromFile( args );
        }
	    break;

        case VERSION:
            errlDisplayVersion();
            break;

	default:
	    break;

    }
#else
    int l_ch = -1;
    int l_Display = 0;
    arguments l_arg;
    poptContext l_optcon;
    static struct poptOption l_options_table[] = {
       { "display", 'd', POPT_ARG_NONE, NULL, 'd', "describe the error log", 0},
       { "xml", 'X', POPT_ARG_NONE, NULL, 'X', "display error log in XML",0},
       {"file", 'f', POPT_ARG_STRING, &l_arg.iv_filename, 'f', "follow with the filename with path", 0},
       {"outdir",'o',POPT_ARG_STRING,&l_arg.iv_outdir,'o',"follow with the output directory path", 0},
       {"version",'v',POPT_ARG_NONE,NULL,'v',"display version of this tool", 0},
       POPT_AUTOHELP
       { NULL, 0, 0, NULL, 0 }
       };

    l_optcon = poptGetContext(NULL, argc, (const char **)argv,l_options_table, 0);

    while ((l_ch = poptGetNextOpt(l_optcon)) >= 0) {
        switch (l_ch) {
            case 'd': 
                  l_Display = 1;
                      break;
            case 'X':
                  l_arg.iv_xml=1;
                  break;

            case 'o':
                  break;

            case 'f':
            {
             if (l_Display)
             {
                  l_rc = errlDisplayEntryFromFile(l_arg);
             }

            }
            break;

            case 'v':
                 errlDisplayVersion();
                 break;

           default: printf("\nentered default");
                    break;
        }
    } 
#endif    
    return (int)l_rc;
}


/*****************************************************************************/
// Display version of the tool
/*****************************************************************************/
void errlDisplayVersion()
{
   #define ERRL_MAJOR_VERSION 2
   #define ERRL_MINOR_VERSION 0
   #define ERRL_RELEASE_DATE  "May 17 2018"
   #define HB_PLUGINS_VERSION "May 17 2018"
   #ifdef HB_PLUGINS_P8
   #define HB_PLUGINS_RELEASE "P8"
   #endif
   #ifdef HB_PLUGINS_P9
   #define HB_PLUGINS_RELEASE "P9"
   #endif
   printf("Version : %d.%d\n",ERRL_MAJOR_VERSION,ERRL_MINOR_VERSION);
   printf("Release Date : %s\n",ERRL_RELEASE_DATE);
   printf("Hostboot plugins based on : %s\n",HB_PLUGINS_VERSION);
}

/*****************************************************************************/
// Display Entry From File specified 
/*****************************************************************************/
toolstatus_t errlDisplayEntryFromFile( arguments & i_args)
{
    toolstatus_t   l_rc = ERRL_TOOL_SUCCESS;
    errlstatus_t   l_sts = ERRL_STATUS_SUCCESS;
    ToolElogs_t	   l_elogs;
    errlHndl_t	   l_errl;

    // Load the log from persistant store & display
    l_sts = errlLoadLogs( i_args, l_elogs );

    for (uint32_t i=0; i < l_elogs.size(); i++)
    {
	l_errl = l_elogs[i];
	
	if ( l_sts == ERRL_STATUS_SUCCESS )
	{
            if ( i_args.iv_xml )
            {
               char        l_eid[9] = {0};
               FILE *      l_fptr = NULL;
               string      l_name;

               sprintf( l_eid,"%X", l_elogs[i]->eid() );

               if (i_args.iv_outdir != NULL)
               {
                 l_name = i_args.iv_outdir;
                 l_name += "/";
               }
               l_name += "./";
               l_name += l_eid;
               l_name += ".xml";
               if((l_fptr = fopen( l_name.c_str(), "w+" )) != NULL)
               {
                  // Disable Buffering
                  setvbuf(l_fptr,NULL,_IONBF,0);

                  ErrlXmlParser l_Parser( l_fptr );

                  l_Parser.StartXMLfile();

                  l_errl->print( l_Parser );

                  l_Parser.EndXMLfile();
               }
               else
               {
                  cout << "Error in opening the file " << l_name.c_str() << endl; 
                  l_rc = ERRL_TOOL_DISPLAY_FILEENTRY;
               } 
            }
            else if ( i_args.iv_ptype == RAW )
	    {
              g_Parser.PrintHexDump(g_buffer,l_errl->flattenedSize());
	    }
	    else 
	    {
              printf("Calling Print Log\n");
              errlPrintLog( *l_errl, i_args );
	    }
	}
	else
	{
	    cout << "Bad Status returned from parsing attempt from file request.\n";
	    
	    l_rc = ERRL_TOOL_DISPLAY_FILEENTRY;	
	}
    }

    // delete the objects in the vector	
    for (uint32_t i=0; i< l_elogs.size(); i++)
    {
	delete l_elogs[i];
    }

    
    return l_rc;
}



/*****************************************************************************/
// Load a log from persistant storage
/*****************************************************************************/
errlstatus_t errlLoadLogs( arguments & i_args, ToolElogs_t & o_list )
{
    errlstatus_t    l_rc = ERRL_STATUS_SUCCESS;
    std::string	    l_filename = i_args.iv_filename;
    UtilFile 	*   l_pFile = 0;
    errlHndl_t      l_hndl = NULL;
    UtilMem	    l_LogData;
    uint32_t 	    l_bufsz = ERRL_ENTRY_MAX; 
    uint16_t	    l_tmp = 0;
    bool	    l_eof = false;
   

    if ( l_filename == "stdin" )
    {
	l_pFile = new UtilFile( stdin );
    }
    else
    {
	l_pFile = new UtilFile( l_filename.c_str() );

	l_pFile->Open( "r" );
    }
    // Transfer the data from the file stream to the 
    // memory buffer
    while ( 1 )
    {
	l_LogData.write( g_buffer, l_pFile->read( g_buffer, l_bufsz ) );

	l_eof = l_pFile->eof();

        if ( l_eof )
        {
          break;
        }
    }


    // Re-create the object
	l_LogData.seek( 0, l_LogData.START );
	
    while(!l_hndl && l_LogData.size() > l_LogData.seek(0,l_LogData.CURRENT ))
	{
	    // reset tmp
	    l_tmp = 0;
	    
	    // Find the log starting point
	    while ( l_tmp != ERRL_SID_PRIVATE_HEADER &&  l_LogData.size() > l_LogData.seek(0,l_LogData.CURRENT ))
	    {
		uint8_t	l_start = 0;
		if(l_tmp != 0)
                {
                  l_tmp = 0;
                  l_LogData.seek( -1 , l_LogData.CURRENT );
                } 
		l_LogData >> l_start;


		if ( l_start == 0x50 )
		{
		    // move one back 
		    l_LogData.seek( -(int)sizeof(l_start) , l_LogData.CURRENT );   
		    
		    // now check if it was the header
		    l_LogData >> l_tmp;
		}  
                if ( ( l_hndl = l_LogData.getLastError() ) )
                {
                    break;
                }

	    }
            if(l_LogData.size() <= l_LogData.seek(0,l_LogData.CURRENT ))
              break;

	    // move two back 
	    l_LogData.seek( -(int)sizeof(l_tmp) , l_LogData.CURRENT );   
	    
	    // add to vector
	    o_list.push_back( new ErrlEntry() );
	    
	    // unflatten	
	    l_rc = o_list[o_list.size()-1]->unflatten(l_LogData);
	    
            if ( l_rc != ERRL_STATUS_SUCCESS)
	    {
		// remove last log since it did NOT unflatten
		o_list.pop_back();
		break;
	    }
	} 


	// Update the status if there's no input data
	if ( l_LogData.size() == 0 )
	{
	    l_rc = ERRL_STATUS_SHORT_SIZE;
	}

    if ( l_rc == ERRL_STATUS_CORRUPT && o_list.size() )   //set the status somehow
    {
	l_rc = ERRL_STATUS_SUCCESS;
    }
    
    // Cleanup
    delete l_pFile;
    l_pFile = 0;

    
    return l_rc;

}

/*****************************************************************************/
// Drop log to parser
/*****************************************************************************/
void errlPrintLog( ErrlEntry & i_Log, arguments & i_args )
{
    // Locals
    bool            l_dispFull = false;
    errlslen_t          l_len;
    comp_id_t           l_cid;
    errlsubsec_t        l_sst;
    errlver_t           l_ver;
    errlidx_t           l_idx = 1;
    const void *        l_p = 0;
    struct  stat        l_stat;
    std::string         l_strfile;
    std::string     l_strfile2;
    std::string     l_strfileHB;
    std::string     l_strfile2HB;

    l_strfileHB = "hbotStringFile"; 
    l_strfile  = "trexStringFile";    
    
    // check if --long option is set. if so we need to print the hexdump of trace UD sections as well
    if(i_args.iv_ltrace) 
    {
        l_dispFull = true;
    }

    // 0. Display the log
    i_Log.print( g_Parser, l_dispFull );

    // check if we were told to skip the displaying of the trace, if so we are done.
    if ( i_args.iv_skipTrace != true )
    {
        // 1. Check to make sure
        //    a) The string file exists, otherwise exit
        if ( i_args.iv_trace )
        {
            l_strfile = i_args.iv_trace;
            l_strfileHB = i_args.iv_trace;
        }
        // check if the file passed in exists
        if (( stat( l_strfile.c_str(), &l_stat ) < 0 ) ||
            ( stat( l_strfileHB.c_str(), &l_stat ) < 0 ))
        {
             // String file not found, bail out
              printf("W> errlPrintLog: %s was not found, skipping trace\n",l_strfile.c_str());
              return;
        }
        // add a space
        l_strfile += " ";
        l_strfileHB += " ";

        // 2. Find trace sections
        while ( ( l_p = i_Log.getUsrDtls( l_len, l_cid, l_sst, l_ver, l_idx ) ) )
        {
            std::ostringstream  l_str;

            if ( l_cid == ERRL_COMP_ID && l_sst == ERRL_UDT_TRACE )
            {
                // 3. Generate file names
                l_str << "/tmp/" << std::hex << i_Log.eid() << "-";
                l_str << std::dec << getpid() << ".trace." << l_idx;

                // 4. Drop each into a temporary file ( id.trace.1, id.trace.2, ... )
                std::ofstream   out( l_str.str().c_str(), ios::binary );
                if ( !out )
                {
                    std::cerr << "Error writing " << l_str.str() << std::endl;
                }
                else
                {

                    if(l_len == 4 )
                    {
                        ++l_idx;
                        out.close();
                        continue;
                    }

                    g_TempFiles.push_back( l_str.str() );
                    out.write( (char*)l_p, l_len );
                    out.close();
                }
            }
            else
            {
                if ( (l_cid == ERRL_COMP_ID) && (l_sst == ERRL_UDT_HB_TRACE) )
                {
                    l_str << "/tmp/" << std::hex << i_Log.eid() << "-";
                    l_str << std::dec << getpid() << ".trace." << l_idx;

                    // 4a. Drop each into a temporary file ( id.trace.1, id.trace.2, ... )
                    std::ofstream   out( l_str.str().c_str(), ios::binary );
                    if ( !out )
                    {
                        std::cerr << "Error writing " << l_str.str() << std::endl;
                    }
                    else
                    {
                        if(l_len == 4 )
                        {
                            ++l_idx;
                            out.close();
                            continue;
                        }
                        g_TempFilesHB.push_back( l_str.str() );
                        out.write( (char*)l_p, l_len );
                        out.close();

                     }
                }
            }

            // Advance
            ++l_idx;
        }

        // 5. Build the trace call

        if ( g_TempFiles.size() )
        {
            std::ostringstream  l_str;
            l_str << "fsp-trace -s ";
            if ( i_args.iv_trace )
            {
                l_str << i_args.iv_trace << " ";
            }
            else
            {
                l_str << l_strfile;
            }
            for ( size_t i = 0; i < g_TempFiles.size(); i++ )
            {
                l_str << g_TempFiles[i] << " ";
            }

            // 5a. Call the trace tool to decode and print that out
            std::cout << "Calling " << l_str.str() << "..." << std::endl;
            system( l_str.str().c_str() );
        }

        // 5.1. Build the trace call for HB
        if ( g_TempFilesHB.size() )
        {
            std::ostringstream  l_str;
            l_str << "fsp-trace -s ";
            l_str << l_strfileHB;
            for ( size_t i = 0; i < g_TempFilesHB.size(); i++ )
            {
                l_str << g_TempFilesHB[i] << " ";
            }

            //5a.1 Call trace tool to decode HB trace and print that out
            std::cout << "Calling " << l_str.str() << "..." << std::endl;
            system( l_str.str().c_str() );
        }

        // 6. Cleanup the trace files - also done by percCleanup
        for ( size_t i = 0; i < g_TempFiles.size(); i++ )
        {
            remove( g_TempFiles[i].c_str() );
        }

        //6.1 Cleanup the trace files HB
        for ( size_t i = 0; i < g_TempFilesHB.size(); i++ )
        {
            remove( g_TempFilesHB[i].c_str() );
        }

        // 7. Clear out the global
        g_TempFiles.clear();
        g_TempFilesHB.clear();
    }
}

