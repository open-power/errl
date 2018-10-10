// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_utils.hpp 1.1 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
#ifndef DCC_UTILS_HPP
#define DCC_UTILS_HPP

/*
 * This file contains method that needs to be generically available 
 * to multiple classes in the infrastructure code.
 */

//******************************************************************************
// includes
//******************************************************************************
#include <DynamicOscillatorHandler.hpp>
#include <dcc_oscillator_types.hpp>
#include <dcc_utils.hpp>
#include <ExecList.hpp>
#include <query_service.hpp>

//******************************************************************************
// Constants
//******************************************************************************
namespace dcc
{
   
    /* Return DccPtr object wrapping ContentClass for the input drawerId.
     * In case ContentClass could not be found for the input drawer
     * then NULL pointer will be returned back to the caller.
     *
     * The ContentClass must implement getDrawer() method.
     */
    template <class ContentClass> DccPtr<ContentClass> getDrawerObject(
            const uint32_t f_drawerId,
            QueryBaseCP f_pCollectRoot)

    {
        ExecList<ContentClass> potentialList;
        if ( f_pCollectRoot == NULL )
        {
            potentialList =  collectClasstypeInTree<ContentClass>();
        }
        else
        {
            potentialList = collectClasstypeInSubTree<ContentClass>(f_pCollectRoot);
        }
        DccPtr<ContentClass> contenClassPointer;

        typename  ExecList<ContentClass>::const_iterator iterCurrent = potentialList.begin();

        while (iterCurrent != potentialList.end())
        {
            ITRACE2(DCOM_FUNC_OSC,"Input drawerId = %d ,Current DrawerId = %d",f_drawerId,(iterCurrent)->getDrawerId());
            if ( iterCurrent->getDrawerId() == f_drawerId )
            {
                contenClassPointer = (*iterCurrent);
                break;
            }
            else
            {
                iterCurrent++;
            }
        }
        return contenClassPointer; 
    }

    /*
     * This method return the Id of drawer where the slot passed as input lies.
     */
    dccosc::OscDrawerId_t getDrawerIdForThisSlot( SlotId_t f_slotId );
    
    /*
     * This method return the Id of slot0 and slot1 for the drawer passed
     * as input. 
     */
    void getSlotsOnThisDrawer( dccosc::OscDrawerId_t f_drawerId, uint32_t& o_slot0,
            uint32_t& o_slot1);
}
#endif //DCC_UTILS_HPP
