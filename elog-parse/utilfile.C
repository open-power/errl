/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Linux includes
#include <utilfile.H>
#include <utilbase.H>
#include <utilmem.H>
#include <stdarg.h>
#include <srcisrc.H>
#include <errlentry.H>


#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>	    // fopen, fileno
#include <sys/file.h>	    // lockf
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>


static const char UTIL_FILE_INVALID_NM[] = "";

/*****************************************************************************/
// Default Constructor
/*****************************************************************************/
UtilFile::UtilFile()
: iv_filePathName( 0 ), iv_fp( 0 )
{
    FileName(UTIL_FILE_INVALID_NM);
}


/*****************************************************************************/
// Stream Pointer Constructor
/*****************************************************************************/
UtilFile::UtilFile( FILE * i_stream )
: iv_filePathName( 0 ), iv_fp( i_stream )
{
    FileName( UTIL_FILE_INVALID_NM );
}


/*****************************************************************************/
// Constructor
/*****************************************************************************/
UtilFile::UtilFile(const char * i_filePathName)
: iv_filePathName( 0 ), iv_fp( 0 )
{
    FileName( i_filePathName );
}



/*****************************************************************************/
// Destructor
/*****************************************************************************/
UtilFile::~UtilFile()
{

    // Eliminate prior errors
    // - this is done bcs close will abort if there are prior errors
    delete getLastError();

    // Close it up: only if it was created by us
    if ( strcmp( iv_filePathName, UTIL_FILE_INVALID_NM ) != 0 )
    {
	Close();
    }

    
    delete[] iv_filePathName;

    // Note: a lingering iv_lastError will be trashed
    //       by the base destructor

}


/*****************************************************************************/
// Does the file exist?
/*****************************************************************************/
bool UtilFile::exists( void ) const
{
    bool    l_rc = false;
    struct  stat    l_stat;
    int	    l_urc;

    l_urc = stat( iv_filePathName, &l_stat );
    if ( ! l_urc )
    {
      
	l_rc = true;
    }
  
    errno = 0;

    return l_rc;
}

/*****************************************************************************/
// Does the file exist?
/*****************************************************************************/
bool UtilFile::exists( const char *i_fileName )
{
    bool    l_rc = false;
    struct  stat    l_stat;
    int	    l_urc;

    l_urc = stat( i_fileName, &l_stat );
    if ( ! l_urc )
    {
	    l_rc = true;
    }
  
    //Reset Errno
    errno = 0;

    return l_rc;
}

/*****************************************************************************/
// Open the file opening the file in flash by default.
/*****************************************************************************/
void UtilFile::Open( 
    const char * i_mode
    )
{
  Open(i_mode,false);

}


/*****************************************************************************/
// Open the file opening the file in /nfs if the bool flag is set.
/*****************************************************************************/
void UtilFile::Open( 
    const char * i_mode,
    bool i_nfsFlag
    )
{

    //reset errno
    errno = 0;
    
    do
    {
    
	//Locals
	const uint32_t MAX_MODE_STR_LEN = 9;///< max mode string size, should really never be this big!
	char l_mode [ MAX_MODE_STR_LEN ];   ///< temp for mode string

	// lets copy callers mode to temp mode var     
	strncpy( l_mode, i_mode, MAX_MODE_STR_LEN );

	    if ( ( strstr( i_mode, "+") == NULL) && 
		 ( strstr( i_mode, "r") == NULL) )
	    {
		strncat( l_mode, "+", MAX_MODE_STR_LEN ); 	
	    }

    
	if ( ( iv_fp = fopen(iv_filePathName, l_mode) ) != 0 )
	{
	    // Disable Buffering
	    setvbuf(iv_fp,NULL,_IONBF,0);

	}

    } //do while end
    while ( 0 );


    // Return
}

/*
 * The function obtains the current value of the file position indicator
 * for the stream. 
 */

uint32_t UtilFile::fpos()
{
	uint32_t l_pos = 0;

	if ( isOpen() )
	{
		l_pos=(uint32_t)ftell(iv_fp);
	}

	return l_pos;
}



// The function to check end of file.

bool UtilFile::eof()
{
	bool file_eof = false;

	if ( isOpen() )
    {
		iv_eof = feof( iv_fp );

		if (iv_eof) 
		{
			file_eof = true;
		}

	}
    return file_eof;
}

/*****************************************************************************/
// Close the file
/*****************************************************************************/
void UtilFile::Close()
{
    int		l_rc;

     if ( isOpen() != false )
    {
	// Reset errno
	errno = 0;

	l_rc = fclose(iv_fp);

	if ( l_rc != EOF )
	{
	    // Clear all of the internal flags
	    iv_fp = 0;
	    iv_eof = false;
	}
    
    }

    // Return

}

/*****************************************************************************/
// Write the file with automatic sync calling the write method
/*****************************************************************************/


uint32_t UtilFile::write(
    const void *i_buffer,
    uint32_t    i_size
    )
{
   size_t          l_rc = 0;
   l_rc = fwrite( i_buffer, 1, i_size, iv_fp );
   return l_rc;
}

/*****************************************************************************/
// Read the file (no locking used!)
/*****************************************************************************/
uint32_t UtilFile::_read(
    void *	    o_buffer,
    uint32_t	    i_size,
    bool	    i_restartStream
    )
{
    //Locals
    uint32_t	    l_rc = 0;
    uint32_t	    l_curPos = 0;
    int		    l_ferr = 0;
    utilExtRefCode  l_erc = UTIL_ERC_NONE;

    // place at start of file
    if ( i_restartStream )
    { 
	l_curPos = seek( 0, CURRENT );
	seek( 0, START );
    }

localread:
    l_rc = fread( o_buffer, 1, i_size, iv_fp );

   if ( ( iv_eof = feof( iv_fp ) ) )
   {
       l_erc = UTIL_ERC_FILE_EOF;
   }

    else if ( l_rc != i_size )
    {
	if ( ( iv_eof = feof( iv_fp ) ) )
	{
	    l_erc = UTIL_ERC_FILE_EOF;
	}
	else if ( ( l_ferr = ferror( iv_fp ) ) )
	{
	    if ( EINTR == errno )
	    {
		goto localread;
	    }
	    l_erc = UTIL_ERC_OP_FAILED;
	}
    }

    // return to original position if no errors 
    if ( (l_erc == UTIL_ERC_NONE) && i_restartStream ) 
	seek( l_curPos, START );

    
    return l_rc;
}


/*****************************************************************************/
// Read the file
/*****************************************************************************/
uint32_t UtilFile::read(
    void *   o_buffer,
    uint32_t i_size
    )
{
    // Locals
    size_t	    l_rc = 0;
    utilExtRefCode  l_erc = UTIL_ERC_NONE;
    

    if (!iv_eof )
    {
        if ( isOpen() )
	{
	    //reset errno	
	    errno = 0;
	
	    l_rc = _read( o_buffer, i_size, false );

        if ( l_rc == 0)
	    {	    
		l_erc = UTIL_ERC_OP_FAILED_READ; 
	    }

	}
        else
	{
            l_erc = UTIL_ERC_FILE_NOT_OPEN;
	}
    }
    
    if ( l_erc != UTIL_ERC_NONE )
    {


    }

    return l_rc;
}

/*****************************************************************************/
// Seek the file
/*****************************************************************************/
uint32_t UtilFile::seek(
    int	    i_pos,
    whence  i_whence
    )
{
    uint32_t l_rc = 0;
    int	     l_whence = 0;
    int	     l_ferr = 0;

        if ( isOpen() )
	{
            switch ( i_whence )
	    {
		case CURRENT:
		    l_whence = SEEK_CUR;
		    break;
		case START:
		    l_whence = SEEK_SET;
		    break;
		case END:
		    l_whence = SEEK_END;
		    break;
	    }

	    //reset errno
	    errno = 0;

            if ( fseek( iv_fp, i_pos, l_whence ) == 0 )
	    {
                l_rc = (uint32_t)ftell( iv_fp );

                // Reset the indicators
                iv_eof = 0;
                clearerr(iv_fp);
	    }
            else
	    {
                if ( ( iv_eof = feof( iv_fp ) ) )
		{
		}
                else if ((l_ferr = ferror( iv_fp )))
		{
                    // Set Error Code
		}
	    }

	}

    return l_rc;
}

/*****************************************************************************/
// Query the file size
/*****************************************************************************/
uint32_t UtilFile::size() const 
{
    uint32_t	l_rc = 0;
    uint32_t	l_curPos = 0;
    UtilFile *	l_this = const_cast< UtilFile * > ( this );

    // reset errno
    errno = 0;

	l_curPos = l_this->seek( 0, CURRENT );

	l_rc = l_this->seek( 0, END );

	l_this->seek( l_curPos, START );

    return l_rc;
}


/*****************************************************************************/
// Set/Get the object's filename
/*****************************************************************************/
void UtilFile::FileName( const char * i_name )
{
    
    // Cleanup
    delete[] iv_filePathName;

    iv_filePathName = new char[strlen(i_name) + 1];

    strcpy(iv_filePathName, i_name);

}


