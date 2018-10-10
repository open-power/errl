// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgtinternals.H 1.2.5.21 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2005,2016 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC:
// $Source: fips740 fsp/src/tmgt/fsp/tmgtinternals.H 1$


#ifndef TMGTINT_H
#define TMGTINT_H

/**
 *  @file tmgtinternals.H
 *
 *  @brief This file contains the definition of constants, macros, etc. that
 *         are internal to the thermal management component and are needed by
 *         more than one .H or .C file.
 *
 */


/**********************************************************************************************************************************/
/*                                                                                                                                */
/*  CHANGE ACTIVITY:                                                                                                              */
/*                                                                                                                                */
/*  Flag  Track   Release     Date     Userid    Comments                                                                         */
/*  ----- ------  ----------- -------- --------- -------------------------------------------------------------------------------- */
/*                                                                                                                                */
/*  END CHANGE ACTIVITY                                                                                                           */
/**********************************************************************************************************************************/


#include <errltypes.H>



/**
  Regular Flag
  A Flag can only have states defined by FLAG_VALUE.
  There could be a class defined for a negative active flag,
  but no reason to create one at this time
  There are more flag types defined in powr_fsp_persistant.h
  @see FLAG_VALUE
  @par Example
  @code
  Flag f;  // create flag and set to OFF
  if(OFF(f))
  {
// this leg will be executed
}
else
{
// this leg won't be executed
}
SET(f); // turn flag ON
if(ON(f))
{
// this leg will be executed
} else
{
// this leg won't be execute
}
CLEAR(f);  // turn flag off again
@endcode
 */
class Flag
{
    private:
        uint8_t xVal;

    public:
        /**
          Constructor
          @post Flag created and Cleared
         */
        Flag() : xVal(0) {}
        Flag(const uint8_t val) : xVal(val) {}

        /**
          Assign the state of the flag
          The Flag can only be assigned a state specified by enum FLAG_VALUE
          @note Overloading the operator= prevents assignment by any other type
         */
        const Flag & operator=(const uint8_t lval) { xVal = lval; return *this;}

        /**
          Assign this flag from another flag
         */
        const Flag & operator=(const Flag & f) { xVal = f.xVal; return *this;}

        /**
          Compare state of flag with value from enum FLAG_VALUE
         */
        bool operator==(const uint8_t lval) const { return xVal == lval; }

        /**
          Compare Flag with another Flag
         */
        bool operator==(const Flag &f) const { return xVal == f.xVal; }
};

/**
  Flag operator SET - turn flag "on"
  @post ON(flag) == true
 */
inline void SET(Flag & t) { t=1; }

/**
  Flag operator CLEAR - turn flag "off"
  @post OFF(flag) == true
 */
inline void CLEAR(Flag & t) { t=0; }

/**
  Query if flag is ON
  @return true | false
 */
inline bool ON(const Flag & t) { return t==1; }

/**
  Query if flag is OFF
  @return true | false
 */
inline bool OFF(const Flag & t) { return t==0; }



#endif // TMGTINT_H
