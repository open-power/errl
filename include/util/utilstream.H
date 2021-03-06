#ifndef UTILSTREAM_H
#define UTILSTREAM_H

/**
 * @file utilstream.H
 *
 * @brief	Stream manipulation
 *
 * Used for creating and manipulating streams
 *
 */
/**
 * @page ChangeLogs Change Logs
 * @section UTILMEM_H utilmem.H
 * @verbatim
 *
 * Flag PTR/DCR#   Userid    Date      Description
 * ---  ---------- --------  --------  --------------------------------------
 * @endverbatim
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errltypes.H>
#include <util_service_codes.H>

#include <string>
#include <iostream>

#include <utilendian.H>


/*****************************************************************************/
// User Types
/*****************************************************************************/

//*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/

/*****************************************************************************/
// Stream class
/*****************************************************************************/
/**
 *  @brief  Stream Base class
 *
 *  Stream interface specification
 *
 */
class UtilStream
{
  public:

    enum whence
    { 
        CURRENT = 0, 
        START = 1, 
        END = 2
    };

    
    /**
     *  @brief Default constructor
     *  
     *  Initializes internals of the stream object.                     
     *  
     */
    UtilStream();

    
    
    
    
    /**
     *  @brief Destructor
     *
     */
    virtual ~UtilStream();


    
    
    /**
     *  @brief Reads data from current position of the stream
     *  
     *  Reads data from the current postion of the stream for the  
     *  specified number of bytes.
     *
     *  @return # of bytes read or zero if none.
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    virtual uint32_t read(
	void *	    o_buffer,	///< Buffer data is read into
	uint32_t    i_size	///< Size in bytes of data to be read
	) = 0;

    /**
     *  @brief Writes data to current position of the stream
     *
     *  Writes data to the current position of the stream for the
     *  specified number of bytes.
     *
     *  @return # of bytes written or zero if none.
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *
     */
    virtual uint32_t write(
        const void *i_buffer,   ///< Source buffer data is written from
        uint32_t    i_size      ///< Size in bytes of data to be written
        ) = 0;



    
    /**
     *  @brief Seek to the specified position in the stream
     *  
     *  Performs a seek based on the specified position and offset.
     *  
     *  @return Current file position after the interface completes.
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *
     *  @example
     *  // To Get the current file position
     *
     *  UtilFile    l_file;
     *  ...
     *  uint32_t l_curpos = l_file.seek( 0, l_file.CURRENT );
     *
     *	@endexample
     *  
     */
    virtual uint32_t seek(
	int32_t	    i_pos,	///< Seek offset in bytes
	whence	    i_whence	///< Position to seek from
	) = 0;

    
    
    
    /**
     *  @brief Return the current size of the stream
     *  
     *  Returns the current size of the stream.                     
     *  
     */
    virtual uint32_t size() const = 0;



    
    
    /**
     *  @brief Return EOF status
     *  
     *  Returns true if EOF has been reached, and false if it has not been reached.
     *  
     */
    bool eof();


    
    /**
     *  @brief Get the last error received.                 
     *  
     *  Returns the last error received and clears error status.
     *
     *  @note clearing the error status involves returning the last
     *        error and setting eof to false.  In other words, it wipes
     *        the slate clean.
     *  
     */
    errlHndl_t getLastError();


   
    /**
     *  @brief Set the last error received.                 
     *  
     *  Replaces the last error with the user supplied parameter.
     *
     *  @note If an error exists, it will be deleted and replaced by this
     *        call.  For this reason, the user should normally do one
     *        of the following:
     *        1. getLastError & append then setLastError, or
     *	      2. peekLastError & append, or if it's null, just setLastError
     *  
     */
    void setLastError( errlHndl_t i_error );


   
    /**
     *  @brief Peek last error
     *  
     *  Returns the last error received but does NOT clear the error status.    
     *
     *  @note
     *	    The returned handle should not be:
     *	    1. committed
     *	    2. deleted
     *
     *	    under any circumstances since it belongs to the UtilStream
     *	    object.
     *  
     */
    errlHndl_t peekLastError();

    /**
     *  @brief General Insertion to cover all outstanding cases
     *
     *  Writes the data value to the stream
     *
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *
     */
    template< class D >
    UtilStream & operator<< ( const D & i_right )
    {
        write( &i_right, sizeof(D) );
        return *this;
    }

   

    /**
     *  @brief Signed 64 bit extract
     *  
     *  Reads 8 bytes from the stream but first converts the
     *  data to host byte order.
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( int64_t & o_datum );




    /**
     *  @brief Unsigned 64 bit extract
     *  
     *  Reads 8 bytes from the stream but first converts the
     *  data to host byte order.
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( uint64_t & o_datum );




    /**
     *  @brief Signed 32 bit extract
     *  
     *  Reads 4 bytes from the stream but first converts the
     *  data to host byte order.
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( int32_t & o_datum );




    /**
     *  @brief Unsigned 32 bit extract
     *  
     *  Reads 4 bytes from the stream but first converts the
     *  data to host byte order.
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( uint32_t & o_datum );




    /**
     *  @brief Signed 16 bit extract
     *  
     *  Reads 2 bytes from the stream but first converts the
     *  data to host byte order.
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( int16_t & o_datum );




    /**
     *  @brief Unsigned 16 bit extract
     *  
     *  Reads 2 bytes from the stream but first converts the
     *  data to host byte order.
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( uint16_t & o_datum );





    /**
     *  @brief Signed 8 bit extract
     *  
     *  Reads 1 byte from the stream
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( int8_t & o_datum );




    /**
     *  @brief Unsigned 8 bit extract
     *  
     *  Reads 1 byte from the stream
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    UtilStream & operator>> ( uint8_t & o_datum );



    /**
     *  @brief bool extract 
     *
     *  Reads a boolean from the stream
     *
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *
     */
    UtilStream & operator>> ( bool & o_datum );



    /**
     *  @brief string extract (@mj00A)
     *
     *  Reads a string from the stream
     *
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *
     */
    UtilStream & operator>> ( std::string & o_string );


    
    /**
     *  @brief General Extraction to cover all outstanding cases
     *  
     *  Reads the data value from the stream
     *  
     *  @return A reference to the stream
     *
     *  @note Errors are not reported by this interface, instead
     *        the user must call getLastError.
     *  
     */
    template< class D >
    UtilStream & operator>> ( D & i_right )
    {
	read( &i_right, sizeof(D) );
	return *this;
    }



protected:
    
    /**
     * @brief	Assignment operator
     *
     * Deletes any pending errors, and copies the eof file
     * from the right hand operand.
     *
     * @return A stream reference
     *
    */
    UtilStream & operator = ( const UtilStream & i_right );


    bool		iv_eof;                 ///<Stream EOF
    mutable errlHndl_t	iv_lastError;		///<Last Error


private:

    // Disable assignment & copy-constructor until the meaning is defined
    UtilStream( const UtilStream & i_right );


};



/*****************************************************************************/
// Specialization: read int64_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( int64_t & o_datum )
{
    read(&o_datum, 8 );
    o_datum = ntohll( o_datum );
    return *this;
}

/*****************************************************************************/
// Specialization: read uint64_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( uint64_t & o_datum )
{
    read(&o_datum, 8 );
    o_datum = ntohll( o_datum );
    return *this;
}


/*****************************************************************************/
// Specialization: read int32_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( int32_t & o_datum )
{
    read(&o_datum, 4 );
    o_datum = ntohl( o_datum );
    return *this;
}

/*****************************************************************************/
// Specialization: read uint32_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( uint32_t & o_datum )
{
    read(&o_datum, 4 );
    o_datum = ntohl( o_datum );
    return *this;
}


/*****************************************************************************/
// Specialization: read int16_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( int16_t & o_datum )
{
    read(&o_datum, 2 );
    o_datum  = ntohs( o_datum );
    return *this;
}

/*****************************************************************************/
// Specialization: read uint16_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( uint16_t & o_datum )
{
    read(&o_datum, 2 );
    o_datum  = ntohs( o_datum );
    return *this;
}


/*****************************************************************************/
// Specialization: read int8_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( int8_t & o_datum )
{
    read(&o_datum, 1 );
    return *this;
}

/*****************************************************************************/
// Specialization: read uint8_t
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( uint8_t & o_datum )
{
    read(&o_datum, 1 );
    return *this;
}


/*****************************************************************************/
// Specialization: read bool 
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( bool & o_datum )
{
    read(&o_datum, sizeof(bool));
    return *this;
}


/*****************************************************************************/
// Specialization: read string 
/*****************************************************************************/
inline UtilStream & UtilStream::operator>> ( std::string & o_string )
{
    char l_char = '\0';
    o_string.clear();

    while (!iv_lastError)
    {
        read(&l_char, sizeof(char));
        if (l_char == '\0')
        {
            break;
        }
        o_string.append(&l_char, 1);
    }
    return *this;
}

/*****************************************************************************/
// Query End of File
/*****************************************************************************/
inline bool UtilStream::eof()
{
    return iv_eof;
}


/*****************************************************************************/
// Get the last Error Log
/*****************************************************************************/
inline errlHndl_t UtilStream::getLastError()
{
    errlHndl_t l_lastError;

    l_lastError = iv_lastError;

    // Clear the error condition
    iv_lastError = 0;
    iv_eof = false;

    return l_lastError;
}


/*****************************************************************************/
// Peek last Error Log
/*****************************************************************************/
inline errlHndl_t UtilStream::peekLastError()
{
    return iv_lastError;
}

#endif //UTILSTREAM_H

