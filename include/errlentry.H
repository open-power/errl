#ifndef ERRLENTRY_H
#define ERRLENTRY_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlbase.H>
#include <srci.H>
#include <errluh.H>   

/*****************************************************************************/
// F O R W A R D S
/*****************************************************************************/
class ErrlSctn;
class ErrlPrvt;
class ErrlUH;
class ErrlSrc;
class ErrlExtdUH;
class UtilStream;
class UtilHeap;
class ErrlSwV2;
class SrciSrc;
struct BCD_time8_t;
class ErrlParser;

/*****************************************************************************/
// Macros
/*****************************************************************************/

/*****************************************************************************/
// Error Log Entry  C l a s s
/*****************************************************************************/
/**
 *  @brief	Error log entry class.
 *  
 *  This class contains all of the entry management logic and server
 *  communication logic to process an error entry.  A pointer to this class
 *  is known as an errlHndl_t (the error log handle) and it is the data
 *  type passed by applications on the stack to convey a failure.  Some of
 *  the things this class is able to accomplish are: storing a uint32_t
 *  value, adding an SRC, adding a chunk of data in the form of a user
 *  details section, setting the dumpId and flags, adding a software
 *  error section, etc.
 *  
*/
class ErrlEntry : public ErrlBase
{
public:

    
    /**
     * @brief	Destructor
     *
     * Releases all resources owned by the handle.  If the log has not
     * been committed, it effectively aborts the log.  Moreover, all logs
     * ( committed or not ) must be deleted to avoid a resource leak.
     *
     * @return	None
     *
    */
    virtual ~ErrlEntry();

    
    
    /**
     * @brief	Returns the flat size of the object
     *
     * The object flat size represents the amount of storage (in bytes )required
     * to hold the object.
     *
     * @return	32 bit quantity
     *
    */
    uint32_t flattenedSize() const;

    
    
    
    /**
     * @brief	Get the platform Log Id
     *
     * The Platform Log Id ( plid ) is a quantity used to link several logs
     * together. This identifier does not uniquely identify each log ( that's
     * the Entry id ( eid ).
     *
     * @return	32 bit unsigned identifier
     *
    */
    uint32_t plid();

    
    
    
    
    
    /**
     * @brief	Get the Entry Id
     *
     * The Entry Id ( eid ) is a unique identifier assigned to each log at
     * the time of creation.
     *
     * @return	32 bit unsigned identifier
     *
    */
    uint32_t eid() const;
    
    


    
    /**
     *  @brief Operator driven assignment of the return code
     *
     *  Calls the above setRC method
     *  
     *  @param	i_right
     *	    New value for the return code
     *
     *  @return A copy of the input value
     *
     *  @note The overloaded operator functions well but is
     *        dependent upon uint32_t compiler context during
     *        assignment.  Given the fact that most users of
     *        error logger are using handles ( pointers ) then
     *        I would adivse against using this method and
     *        instead use the setRC method
     *  
     */
    uint32_t operator=(
        const uint32_t i_right
    );



    

    /**
     *  @brief Log print
     *  
     *  Print method used by ASM when displaying
     *  the contents of a log to a customer
     *
     *  @param	i_parser
     *	    Interface to a parser object
     *
     *  @param  i_dispFull
     *      Option to display full elog or skip trace UD hexdump sections
     *
     *  @return None
     *
     */
    void print( ErrlParser & i_parser, bool i_dispFull = false );       

    

    
    /**
     *	@brief	Default Constructor
     *
     *	Used in Creating an invalid object for the purposes of unflatten
     *	or assignment.
     *
     *	@note	Using such an object for something other than assignment
     *	        or unflatten is undefined.
    */
    ErrlEntry();
    
    
    
    /**
     *  @brief Import a log
     *
     *  Discards the current log contents and reads and rebuilds
     *  a log from stream data.  The data must have been previously
     *  exported with the flatten interface.
     *
     *  In the event the import operation fails, the current log
     *  contents have been discarded and the state of the log
     *  is now invalid.
     *
     *  In addition, the optional second parameter allows the
     *  caller to determine if a log import failure should be
     *  logged locally or left in the stream for further processing
     *  by the caller
     *  
     *  @param	i_stream
     *	    Data Source
     *
     *  @param	i_commit
     *	    True/False to control the commit of import failures
     *	    locally or allow them to flow back to the caller
     *	    in the stream object
     *
     *  @return Status of the operation
     *
     */
    errlstatus_t unflatten(
        UtilStream &i_stream,
	bool	    i_commit = true
    );

    

    
    /**
     *  @brief Read the log's creator Id value
     *
     *  The log has a component Id associated with it to denote
     *  the detecting component.
     *  
     *  @return Current Log creator Id
     *
     */
    comp_id_t creator() const;


    
    

    /**
     *  @brief Obtain the Log's Subsystem creator
     *  
     *  Each log has an associated value to determine which
     *  subsystem created it.  This method allows the query
     *  of such data.
     *
     *  @return Error Log Creator Subsystem
     *
     */
    errlCreator creatorSubSys() const;

  
    /**
     *  @brief Data block access
     *
     *  Access a given data block given an index
     *  token.  The tokens are returned from the
     *  respective add operations
     *  
     *  @param	o_len
     *	    Output paramter to pass back the length
     *	    of the block
     *
     *  @param	o_cid
     *	    Output parameter for the section component
     *
     *  @param	o_sst
     *	    Output parameter for the section type
     *
     *  @param	o_ver
     *	    Output parameter for the section version
     *
     *  @param	i_idx
     *	    Index to data block.
     *
     *  @return A constant pointer to the data
     *
     *  @note Index tokens are numbered with 1 to usrDtlCount
     *        with a value of 0 acting as a special token to
     *        the last data block
     *  
     */
    const void * getUsrDtls(
	errlslen_t &	o_len,
        comp_id_t   &	o_cid,
        errlsubsec_t &	o_sst,
        errlver_t    &	o_ver,
	errlidx_t	i_idx = 0
    );

private:


    /**
     *  @brief Read the number of sections in the log
     *
     *  Denotes the total number of sections ( required + optional )
     *  which are currently present in the log
     *  
     *  @return # of sections
     *
     */
    uint8_t sections() const;



    /**
     *  @brief Read the log's creation timestamp
     *  
     *  The creation timestamp is stored as an 8 byte bcd
     *  in one of the required sections.
     *
     *  @return Constant Reference to the timestamp
     *
     *  @note The definition of the bcd structure is a part
     *        of the rtim component
     *  
     */
    const BCD_time8_t &created() const;

  


    /**
     *  @brief Number of User data sections in the log
     *
     *  Provides the total number of user data sections
     *  in the log.  The number can be used to iterate
     *  through the sections using the getUsrDtls method
     *  
     *  @return Count of user data sections
     *
     */
    errlidx_t usrDtlCount() const;

    /**
     *  @brief Read the log's commit component Id
     *  
     *  The log's committer is stored in the required
     *  sections and can be read through this interface
     *
     *  @return Component Id of log's committer or 0 if not
     *          yet committed
     *
     */
    comp_id_t committer() const;

    
    // Data Members
    ErrlSctn **	iv_optionals;
    uint32_t	iv_optCount;
    ErrlSrc *	iv_prisrc;
    ErrlPrvt *	iv_prvt;
    ErrlUH   *	iv_usrhdr;
    bool        iv_logDeleted;
    bool        iv_jedec;
    bool        iv_hwCallout;       // Set to one if atleast one hardware Callout
    bool        iv_fwProcCallout;   // Set to one if _only_ FSPSP04 and/or FSPSP06 Proc Callout
    ErrlExtdUH * iv_extduh;          // Extended User Header Section

    // Friends 4 ever
    friend class ErrlELR;

};





#endif //ERRLENTRY_H
