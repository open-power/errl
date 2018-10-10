/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: errltool/include/utilfile.H $                                 */
/*                                                                        */
/* OpenPOWER errltool Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef UTILFILE_H
#define UTILFILE_H

/**
 * @file utilfile.H
 *
 * @brief File Stream manipulation
 *
 * Used for creating and manipulating file streams
 *
 */
/**
 * @page ChangeLogs Change Logs
 * @section UTILFILE_H utilfile.H
 * @verbatim
 *
 * Flag PTR/DCR#   Userid    Date      Description
 * ---  ---------- --------  --------  --------------------------------------
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Utility Includes
#include <utilstream.H>

/*****************************************************************************/
// Forwards
/*****************************************************************************/
class UtilMem;
struct stat;

//*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/

/*****************************************************************************/
// File Stream class
/*****************************************************************************/
/**
 *  @brief     Utility file stream class
 *
 *  Used for file streams 
 *
 */
class UtilFile : public UtilStream
{
  public:

    enum LockType
    {
	EXCL = 0,
	SHRD = 1
    };


    /**
     *  @brief Default Constructor
     *  
     *  Initializes internals to null and will thus cause a SIGSEV if an invalid
     *  operation is performed ( such as writing to the file without opening it )
     *  
     */
    UtilFile();



    /**
     *  @brief Stream Pointer based constructor
     *  
     *  Can be used to read/write to a stream which was not created by
     *  this object and which is not necessarily a file ( i.e. stdout, stdin )
     *
     *  Care must be exercised when using this approach as it can lead to
     *  potentially undesireable effects.
     *  1. Calling open will attempt to close the stream first and will be
     *     unable to re-open it as expected.
     *  2. Calling close will properly close the stream but this may not
     *     be what the user intended.
     *	
     *	The recommended list of methods which the user should stick to
     *	when using this constructor is as follows:
     *	1. Read
     *	2. Write
     *	3. Perhaps Seek
     *
     *	The rest of the methods should be scrutinized on a case by case
     *	basis.
     *  
     *  @note The object's destructor normally closes the stream at the end
     *        but a stream which was not created by this class will not be
     *        closed automatically.  However, the user can call any of the
     *        close methods if he wishes to close that stream.
     *  
     */
       UtilFile( FILE * i_stream );   


    /**
     *  @brief Constructor
     *  
     *  Initializes internals of the file stream object with the file path name.             
     *  
     */
    UtilFile(const char * i_filePathName);


    /**
     *  @brief Assign a UtilMem object to the file
     *
     *	Copies all of the data from the UtilMem object ( up to it's size )
     *	into the current file position.
     *
     *	@return A reference to the UtilFile object
     *
     *	@note Errors are reported through getLastError
     *
     */
    UtilFile & operator=( const UtilMem & i_right );

 

    /**
     *  @brief Destructor
     *
     *	1. Closes the file ( if it's open )
     *	2. Deletes allocated resources
     *	3. Deletes any pending error logs ( effectively aborting )
     *
     */
    virtual ~UtilFile();





    /**
     *  @brief Determines if the file is available in the filesystem
     *  
     *  Attempts to open the file for readonly to determine if it exists
     *  in the file system.  Secondary failures are not reported by
     *  this interface.
     *
     *  @return
     *	    Bool: true, the file exists.  false, it doesn't exist or a
     *	    secondary failure occurred while making the determination.
     *  
     */
    bool exists( void ) const;

    /**
     *  @brief Determines if the file is available in the filesystem
     *  
     *  This is a static function that to determine if it exists
     *  in the file system and is a REGULAR file. 
     *  Secondary failures are not reported by
     *  this interface.
     *
     *  @return
     *	    Bool: true, the file exists.  false, it doesn't exist or a
     *	    secondary failure occurred while making the determination.
     *  
     */
    static bool exists(const char * );



    /**
     *  @brief Open the file associated with the object
     *  
     *  Opens the file based off of the file name associated with the object
     *  with the specified file mode by calling Open with the flag set to false
     *  to always open the flash file by default.
     *
     *  @return
     *	    Nothing. Errors are deferred until the user calls getLastError
     *  
     */
    void Open(
	const char * i_mode ///<Mode file is to be opened in
    );




    /**
     *  @brief Open the file associated with the object
     *
     *  Opens the file based off of the file name associated with the object
     *  with the specified file mode and flag which if set will override the flash 
     *  file and opens the file in /nfs.
     *
     *  @return
     *      Nothing. Errors are deferred until the user calls getLastError
     *
     */
    void Open(
        const char * i_mode, ///<Mode file is to be opened in
        bool i_nfsFlag       ///<Flag to decide file to open - @meg1
    );



    /**
     *  @brief Close the file associated with the object
     *  
     *  Closes the file based off file pointer associated with the file.
     *  
     *  @return
     *	    Nothing. Errors are deferred until the user calls getLastError
     *
     */
    void Close();




    /**
     *  @brief Close the file associated with the object
     *  
     *  Closes the file based off file pointer associated with the file.
     *  
     *  @return
     *	    A error handle specifying the failure ( if any ).
     *
     */
    errlHndl_t close()
    {
	Close();
	return getLastError();
    }




    /**
     *  @brief Reads data from current position of the stream
     *  
     *  Reads data from the current postion of the stream for the  
     *  specified number of bytes.                               
     *  
     */
    uint32_t read(
	void * o_buffer,    ///< Buffer data is read into
	uint32_t i_size	    ///< Size in bytes of data to be read
    );


    /**
     *  @brief Seek to the specified position in the stream
     *  
     *  Performs a seek based on the specified position and offset.
     *  
     */
    uint32_t seek(
	int i_pos,	    ///< Seek offset in bytes
	whence i_whence	    ///< Position to seek from
    );


    /**
     *  @brief Return the current size of the stream
     *  
     *  Returns the current size of the stream.                     
     *  
     */
    uint32_t size() const;
    
    
    
    /**
     * @brief Query the file's open/closed state
     *
     * Determines if the file is currently open
     *
     * @return bool value indicating the open status of the file
     *
    */
    bool isOpen( void ) const
    {
	return ( iv_fp != 0 );
    }

    
    

    
    
    /**
     *  @brief Expose the filename
     *
     *  Return a const char * to the filename
     *  
     *  @return Filename pointer
     *
     */
    const char * Name() const;
  



    /**
     *  @brief Access the stat function call for the current file
     *
     *  Forwards the command the os and generates an error log on failures
     *  
     *  @param	i_name
     *	    A character array for the path filename.
     *
     *  @param	o_stat
     *	    A reference to a struct stat which receives the data
     *
     *  @return An error handle upon failure, null otherwise.
     *
     *  @note This is a static method, which does not require an
     *        object instance.
     *  
     */
    static errlHndl_t getAttributes(
	const char	i_name[],
	struct	stat &	o_stat
    );



    /**
     * The fpos() function obtains the current value of the file position
     * indicator for the file.
     */
    uint32_t fpos();


    /*
     * checking the end of file is reached .Return true for eof is reached and 
     * else false.
     */

    bool eof(); 

private:
    
    /**
     *  @brief Reads data from current position of the stream (internal)
     *  
     *  Reads data from the current postion of the stream for the  
     *  specified number of bytes.                               
     *  
     */
    uint32_t _read(
	void *		o_buffer,	///< Buffer data is read into
	uint32_t	i_size,		///< Size in bytes of data to be read
	bool		i_start = true	///< read from begining of file
    );

    /**
     *  @brief Writes data to current position of the stream
     *
     *  Writes data to the current postion of the stream for the
     *  specified number of bytes.
     *
     */
    uint32_t write(
        const void *i_buffer,     ///< Source buffer data is written from
        uint32_t    i_size        ///< Size in bytes of data to be written
    );


    enum LockCmd
    {
	LOCK		= 0,
	UNLOCK		= 1,
	TEST		= 2
    };



    /**
     * @brief Change the object's filename
     *
     * Set the object's filename
     *
     * @param i_name
     *	    New name, or null to simply get
     *
     * @return void
     *
    */
    void FileName( const char * i_name );


    // Instance variables
    char *	iv_filePathName;    ///< Name of file being operated on 
    FILE *	iv_fp;		    ///< Posix File Stream pointer
};


/*****************************************************************************/
// Get Filename
/*****************************************************************************/
inline const char * UtilFile::Name() const
{
    return iv_filePathName;
}



#endif //UTILFILE_H
