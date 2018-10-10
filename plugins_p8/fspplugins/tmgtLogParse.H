// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/plugins/tmgtLogParse.H 1.5 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2012,2016 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/**********************************************************************************************************************************/
/*  CHANGE ACTIVITY:                                                                                                              */
/*                                                                                                                                */
/*  Flag  Track   Release   Date     Userid    Comments                                                                           */
/*  ----- ------  --------- -------- --------- --------------------------------------------------------------------------------   */
/*  END CHANGE ACTIVITY                                                                                                           */
/**********************************************************************************************************************************/
#include <utilerrlusrdata.H>
#include <utilfactory.H>

/**
 * @brief Class to handle TMGT_ENERGYSCALE_DATA_TYPE parsing
 */
class tmgtENERGYSCALE_DATA_TYPE : public util::ErrlUsrDataParser
{
public:

    /**
     *  @brief Constructor
     *
     */
    tmgtENERGYSCALE_DATA_TYPE() {}

    /**
     *  @brief Destructor
     *
     */
    virtual ~tmgtENERGYSCALE_DATA_TYPE() {}

    /**
     *  @brief Parses user detail data from an error log
     *
     *  Parses the supplied user detail data and outputs info to i_parser. This
     *  overrides the pure virtual function in the base class
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
    virtual void parse(errlver_t i_ver,
                       ErrlUsrParser &i_parser,
                       const void *i_buffer,
                       const uint32_t i_buflen) const;

private:
    // Disabled
    tmgtENERGYSCALE_DATA_TYPE(const tmgtENERGYSCALE_DATA_TYPE &);
    tmgtENERGYSCALE_DATA_TYPE & operator=(const tmgtENERGYSCALE_DATA_TYPE &);
};
/**
 * @brief Class to handle TMGT_OCC_ELOG_DATA_TYPE parsing
 */
class tmgtOCC_ELOG_DATA_TYPE : public util::ErrlUsrDataParser
{
public:

    /**
     *  @brief Constructor
     *
     */
    tmgtOCC_ELOG_DATA_TYPE() {}

    /**
     *  @brief Destructor
     *
     */
    virtual ~tmgtOCC_ELOG_DATA_TYPE() {}

    /**
     *  @brief Parses user detail data from an error log
     *
     *  Parses the supplied user detail data and outputs info to i_parser. This
     *  overrides the pure virtual function in the base class
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
    virtual void parse(errlver_t i_ver,
                       ErrlUsrParser &i_parser,
                       const void *i_buffer,
                       const uint32_t i_buflen) const;

private:
    // Disabled
    tmgtOCC_ELOG_DATA_TYPE(const tmgtOCC_ELOG_DATA_TYPE &);
    tmgtOCC_ELOG_DATA_TYPE & operator=(const tmgtOCC_ELOG_DATA_TYPE &);
};
/**
 * @brief Class to handle TMGT_MSG_DATA_TRUNCATED parsing
 */
class tmgtMSG_DATA_TRUNCATED : public util::ErrlUsrDataParser
{
public:

    /**
     *  @brief Constructor
     *
     */
    tmgtMSG_DATA_TRUNCATED() {}

    /**
     *  @brief Destructor
     *
     */
    virtual ~tmgtMSG_DATA_TRUNCATED() {}

    /**
     *  @brief Parses user detail data from an error log
     *
     *  Parses the supplied user detail data and outputs info to i_parser. This
     *  overrides the pure virtual function in the base class
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
    virtual void parse(errlver_t i_ver,
                       ErrlUsrParser &i_parser,
                       const void *i_buffer,
                       const uint32_t i_buflen) const;

private:
    // Disabled
    tmgtMSG_DATA_TRUNCATED(const tmgtMSG_DATA_TRUNCATED &);
    tmgtMSG_DATA_TRUNCATED & operator=(const tmgtMSG_DATA_TRUNCATED &);
};


class tmgtTMGT_ELOG_TYPE_TOIF_RESET : public util::ErrlUsrDataParser
{
public:

    tmgtTMGT_ELOG_TYPE_TOIF_RESET() {}
    virtual ~tmgtTMGT_ELOG_TYPE_TOIF_RESET() {}
    virtual void parse(errlver_t i_ver,
                       ErrlUsrParser &i_parser,
                       const void *i_buffer,
                       const uint32_t i_buflen) const;

private:
    // Disabled
    tmgtTMGT_ELOG_TYPE_TOIF_RESET(const tmgtTMGT_ELOG_TYPE_TOIF_RESET &);
    tmgtTMGT_ELOG_TYPE_TOIF_RESET & operator=(const tmgtTMGT_ELOG_TYPE_TOIF_RESET &);
};


class tmgtTMGT_ELOG_TYPE_OCC_RESET : public util::ErrlUsrDataParser
{
public:

    tmgtTMGT_ELOG_TYPE_OCC_RESET() {}
    virtual ~tmgtTMGT_ELOG_TYPE_OCC_RESET() {}
    virtual void parse(errlver_t i_ver,
                       ErrlUsrParser &i_parser,
                       const void *i_buffer,
                       const uint32_t i_buflen) const;

private:
    // Disabled
    tmgtTMGT_ELOG_TYPE_OCC_RESET(const tmgtTMGT_ELOG_TYPE_OCC_RESET &);
    tmgtTMGT_ELOG_TYPE_OCC_RESET & operator=(const tmgtTMGT_ELOG_TYPE_OCC_RESET &);
};



class tmgtTMGT_ELOG_TYPE_PCAP_DATA : public util::ErrlUsrDataParser
{
public:

    tmgtTMGT_ELOG_TYPE_PCAP_DATA() {}
    virtual ~tmgtTMGT_ELOG_TYPE_PCAP_DATA() {}
    virtual void parse(errlver_t i_ver,
                       ErrlUsrParser &i_parser,
                       const void *i_buffer,
                       const uint32_t i_buflen) const;

private:
    // Disabled
    tmgtTMGT_ELOG_TYPE_PCAP_DATA(const tmgtTMGT_ELOG_TYPE_PCAP_DATA &);
    tmgtTMGT_ELOG_TYPE_PCAP_DATA & operator=(const tmgtTMGT_ELOG_TYPE_PCAP_DATA &);
};



class tmgtTMGT_ELOG_TYPE_THERMAL_DATA : public util::ErrlUsrDataParser
{
public:

    tmgtTMGT_ELOG_TYPE_THERMAL_DATA() {}
    virtual ~tmgtTMGT_ELOG_TYPE_THERMAL_DATA() {}
    virtual void parse(errlver_t i_ver,
                       ErrlUsrParser &i_parser,
                       const void *i_buffer,
                       const uint32_t i_buflen) const;

private:
    // Disabled
    tmgtTMGT_ELOG_TYPE_THERMAL_DATA(const tmgtTMGT_ELOG_TYPE_THERMAL_DATA &);
    tmgtTMGT_ELOG_TYPE_THERMAL_DATA & operator=(const tmgtTMGT_ELOG_TYPE_THERMAL_DATA &);
};



/**
 * @brief Parser Factory Class for the TMGT component
 *
 * This derives from Factory<ErrlUsrDataParser, int>, therefore it is a factory
 * that produces ErrlUsrDataParser objects and references each type of object
 * with an int.
 */
class tmgtErrlUsrDataParserFactory : public util::Factory<util::ErrlUsrDataParser, int>
{
public:

    /**
     *  @brief Constructor
     *
     *  Registers all possible types of parser object with the factory
     *
     */
    tmgtErrlUsrDataParserFactory();

    /**
     *  @brief Destructor
     *
     */
    virtual ~tmgtErrlUsrDataParserFactory();
};

