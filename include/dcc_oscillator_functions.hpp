// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_oscillator_functions.hpp 1.11.1.4 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2008,2009 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
/*--------------------------- IBM - Confidential ----------------------------*

    (C) Copyright International Business Machines Corporation 2004
    All Rights Reserved
    Licensed Material  -  Program Property of I B M
    Refer to copyright instructions: Form G120-2083

 *---------------------------------------------------------------------------*/


#ifndef DCC_OSCILLATOR_FUNCTIONS_HPP
#define DCC_OSCILLATOR_FUNCTIONS_HPP

#include <stdint.h>

#include <dcc_oscillator_structs.hpp>
//#include <dcc_utils.hpp>


namespace dccosc
{
    typedef enum
    {
        e_rangeNominal,
        e_rangeSlow,
        e_rangeFast 
    } CycleTimeRange_t;

    /* Select oscillator modes. Selections made for one of the oscillators automatically also */
    /* selects the mode for the other oscillator card (if plugged).                           */
    int32_t oscillator_select(OscCardSet_t f_oscCard, OscSelectionMode_t f_oscSelectionMode,
            uint32_t f_drawerId = 0 );

    /* Configure switch propagation logic on the oscillator card.                             */
    /* Always the whole logic has to be configured, even for nodes not plugged.               */
    int32_t oscillator_set_propagation_mode(uint32_t f_groupId, const dccstl::vector<dccosc::SwitchoverPropagationMode_t>& f_propagationModeVec,uint32_t f_drawerId=0);

    /* Configure switch propagation logic on the oscillator card. to disable mode             */
    int32_t oscillator_disable_all_propagation(uint32_t f_drawerId=0);

    /* Read states of the oscillator cards.                                                   */
    int32_t oscillator_read_status(RedundantOscillatorStatus_t& f_redOscStatus,
            uint32_t f_drawerId=0);

    /* Get cycle time in pico seconds. */
    int32_t oscillator_get_cycle_time(uint32_t& f_cycleTime,uint32_t f_drawerId=0);

    /* Steers cycle time in smallest possible increments,                                     */
    /* until given cycletime in pico seconds is reached                                       */
    int32_t oscillator_steer_cycle_time(uint32_t f_cycleTime,uint32_t f_drawerId=0);

    /* Forces cycle time in one step to given cycle time in pico seconds                      */
    /* f_range - the range parameter is to control what pll range has to be selected          */
    /* e_rangeSlow - the slowest possible range is selected                                   */
    /* e_rangeFast - the fastest possible range is selected                                   */
    /* e_rangeNominal - the default range is selected                                         */
    /* default range is the slowest possible range,                                           */
    /* but if the cycle time is closer than 10% to the fast border                            */
    /* the next fastest range  is selected                                                    */
    int32_t oscillator_force_cycle_time(uint32_t f_cycleTime, CycleTimeRange_t f_range,
            uint32_t f_drawerId=0);

    /* Function to set up the pll spreading. */
    int32_t oscillator_read_spreading_setup(SpreadingDirection_t& f_direction, uint32_t& f_tenthPercentage,uint32_t f_drawerId=0);
    int32_t oscillator_setup_spreading(SpreadingDirection_t f_direction, uint32_t f_tenthPercentage, uint32_t f_drawerId=0);

    /* Function the measure the synchronization settings of the CP's. */
    int32_t oscillator_read_synch_lost_counts(uint32_t f_groupId, dccstl::vector<uint32_t>& f_synchLostCountVec,uint32_t f_drawerId=0);

    /* Ulli debug mode */
    int32_t oscillator_set_debug_mode(bool f_mode,uint32_t f_drawerId=0);

} // namespace dccosc

#endif // DCC_OSCILLATOR_FUNCTIONS_HPP

