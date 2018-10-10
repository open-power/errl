#ifndef UTILERRLUSRDATA_H
#define UTILERRLUSRDATA_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

namespace util
{

#ifndef PARSER

/**
 * @brief ERRL User Data Creator
 *
 * This is an abstract base class that defines how user detail error log data
 * should be created. For every different format of user detail data, a
 * component should create a class that derives from this class.
 *
 * An ErrlUsrDataCreator object is not thread-safe, it should only be used by
 * one thread in a process.
*/
class ErrlUsrDataCreator
{
public:

    /**
     *  @brief Constructor
     *
     *  Sets up instance variables. A derived class should set up the instance
     *  variables to reflect a specific format of user detail data
     *
     */
    ErrlUsrDataCreator();

    /**
     *  @brief Destructor
     *
     *  Performs any necesary cleanup
     *
     */
    virtual ~ErrlUsrDataCreator();

    /**
     *  @brief Adds user detail data to error log
     *
     *  Adds the user detail data stored in the internal buffer to the error log
     *  Subclasses should override if the detail data is not stored in the
     *  internal buffer.
     *
     *  @param  i_log
     *      Error log handle to add detail data to
     *
     *  @return None
     *
     */
    virtual void addToLog(errlHndl_t i_log) const;

    /**
     *  @brief Calll percAbend Method
     *
     *  @return None
     *
     */
     void callPercAbend() const;


protected:

    /**
     *  @brief Allocates the internal data buffer for storing detail data
     *
     *  If the internal buffer is already allocated then it is freed. The
     *  data buffer is allocated with the specified size.
     *
     *  @param  i_size
     *      Size of buffer
     *
     *  @return uint8_t*
     *      Pointer to the data buffer
     *
     */
    uint8_t * allocUsrBuf(const uint32_t i_size);

    /**
     *  @brief Reallocates the internal data buffer for storing detail data
     *
     *  The internal data buffer is resized to the specified size, the contents
     *  of the old buffer are preserved in the new buffer.
     *
     *  @param  i_size
     *      Size of buffer
     *
     *  @return uint8_t*
     *      Pointer to the data buffer
     *
     */
    uint8_t * reallocUsrBuf(const uint32_t i_size);

    /**
     *  @brief Returns the size of the internal data buffer
     *
     *  @return uint32_t
     *      Size of the internal data buffer
     *
     */
    uint32_t getUsrBufSize() const;

    /**
     *  Protected Data: ID of component adding user details
     */
    comp_id_t    iv_CompId;
    
    /**
     *  Protected Data: Version number of the user details
     */
    errlver_t    iv_Version;
    
    /**
     *  Protected Data: Subsection number of the user details
     */
    errlsubsec_t iv_SubSection;

private:

    // Disabled
    ErrlUsrDataCreator(const ErrlUsrDataCreator &);
    ErrlUsrDataCreator & operator=(const ErrlUsrDataCreator &);

    /**
     *  Private Data members (the internal buffer should be accessed through
     *  public member functions)
     */
    uint8_t * iv_pBuffer;       // Pointer to internal buffer
    uint32_t  iv_BufLen;        // Length of internal buffer

};

#else // (if PARSER defined)

/**
 * @brief ERRL User Data Parser
 * 
 * This is an abstract base class that defines how user detail error log data
 * should be parsed. For every different format of user detail data, a
 * component should create a class that derives from this class.
 *
 * Note that each component should also create a single factory class (derived
 * from util::Factory) that will create an ErrlUsrDataParser object for any
 * format of user detail data. A factory object should be created by the
 * LogDataParse() function (in the plugins directory) and used to create an
 * ErrlUsrDataParser object to parse the data . See the util component for an
 * example.
*/
class ErrlUsrDataParser
{
public:

    /**
     *  @brief Constructor
     *
     */
    ErrlUsrDataParser()
    {
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~ErrlUsrDataParser()
    {
    }

    /**
     *  @brief Parses user detail data from an error log
     *
     *  Parses the supplied user detail data and outputs info to i_parser. This
     *  is a pure virtual function that must be overridden by a concrete derived
     *  class that is specific to a particular component, version and subsection
     *
     *  @param  i_version
     *      Version of the data
     *
     *  @param  i_parse
     *      ErrlUsrParser object for outputting information
     *
     *  @param  i_pBuffer
     *      Pointer to buffer containing detail data
     *
     *  @param  i_buflen
     *      Length of the buffer
     *
     *  @return None
     *
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       const void * i_pBuffer,
                       const uint32_t i_buflen) const = 0;

private:

    // Disabled
    ErrlUsrDataParser(const ErrlUsrDataParser &);
    ErrlUsrDataParser & operator=(const ErrlUsrDataParser &);
};

#endif //PARSER

} // namespace util
#endif //UTILERRLUSRDATA_H
