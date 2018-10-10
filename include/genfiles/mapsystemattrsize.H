
#ifndef MAPSYSTEMATTRSIZE_H
#define MAPSYSTEMATTRSIZE_H

/**
 *  @file mapsystemattrsize.H
 *
 *  @brief Interface to get the map of system target attributes with respective
 *  attribute size
 */

// STD
#include <map>

// TARG
#include <targeting/common/trace.H>
#include <targeting/common/target.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FUNC

//******************************************************************************
// Interface
//******************************************************************************

namespace TARGETING
{

class MapSystemAttrSize;

/**
 *  @brief Return the MapSystemAttrSize singleton instance
 *
 *  @return Reference to the MapSystemAttrSize singleton
 */
TARGETING::MapSystemAttrSize& mapSystemAttrSize();


#define TARG_NAMESPACE "MAPSYSTEMATTRSIZE::"

#define TARG_CLASS "MapSystemAttrSize::"

/*
 * @brief Typedef map <attr, attSize>
 */
typedef std::map<ATTRIBUTE_ID, uint32_t> AttrSizeMapper;

class MapSystemAttrSize
{

    public:
        /**
         *  @brief Destroy the MapSystemAttrSize class
         */
        ~MapSystemAttrSize();

        /**
         *  @brief Create the MapSystemAttrSize class
         */
        MapSystemAttrSize();

        /*
         *  @brief returns the map of Writeable System attributes as Key and
         *  size of the attributes as value.
         *
         *  @return, returns the map which has the Writeable Sytem attributes
         *  as key and size as value pair, variable <SYSTEM_ATTRIBUTE_ID::Size>
         */
         const AttrSizeMapper& getMapForWriteableSystemAttributes() const;

     private:

        /* Map variable for System Attribute Ids Vs the Size */
        AttrSizeMapper iv_mapSysAttrSize;

        /* Disable Copy constructor and assignment operator */
        MapSystemAttrSize(
            const MapSystemAttrSize& i_right);

        MapSystemAttrSize& operator = (
            const MapSystemAttrSize& i_right);
};

/**
 *  @brief Provide singleton access to the MapSystemAttrSize
 */
TARG_DECLARE_SINGLETON(TARGETING::MapSystemAttrSize, theMapSystemAttrSize);

#undef TARG_CLASS
#undef TARG_NAMESPACE


}// namespace TARGETING

#endif // MAPSYSTEMATTRSIZE_H

