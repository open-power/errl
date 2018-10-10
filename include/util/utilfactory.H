/* @(#)88       1.1  src/util/fsp/utilfactory.H, esw_util, fips860 3/6/09 15:17:15  */
// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips860 src/util/fsp/utilfactory.H 1.1 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2009 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
#ifndef UTILFACTORY_H
#define UTILFACTORY_H

/**
 * @file utilfactory.H
 *
 * @brief Provides a generic object factory
 *
 * This should be used by a client wishing to create objects of a particular
 * base class type.
 * 
 *  A Factory object is not thread-safe, it should only be used by one thread
 *  in a process.
 *
 * Usage example.
 *
 *   class FactoryTestBaseClass {...};
 *   class FactoryTestSubClass1 : public FactoryTestBaseClass {...};
 *   class FactoryTestSubClass2 : public FactoryTestSubClass1 {...};
 *
 *   enum FactoryTestClasses {TestBaseClass = 1,
 *                            TestSubClass1 = 2,
 *                            TestSubClass2 = 3};
 *
 *   // Create object factory and register all 3 types of object (with base
 *   // class FactoryTestBaseClass) that it can create
 *   util::Factory<FactoryTestBaseClass, int> l_factory;
 *   Assert (l_factory.Register<FactoryTestBaseClass>(TestBaseClass) == true);
 *   Assert (l_factory.Register<FactoryTestSubClass1>(TestSubClass1) == true);
 *   Assert (l_factory.Register<FactoryTestSubClass2>(TestSubClass2) == true);
 *
 *   // Use the factory to create all 3 objects
 *   FactoryTestBaseClass * l_pObj1 = l_factory.Create(TestBaseClass);
 *   FactoryTestSubClass1 * l_pObj2 = static_cast<FactoryTestSubClass1*>
 *                                    (l_factory.Create(TestSubClass1));
 *   FactoryTestSubClass2 * l_pObj3 = static_cast<FactoryTestSubClass2*>
 *                                    (l_factory.Create(TestSubClass2));
 *
 *   // Unregister TestSubClass2
 *   Aassert (l_factory.Unregister(TestSubClass2) == true);
 *
 *   // Delete the 3 objects
 *   delete l_pObj1;
 *   delete l_pObj2;
 *   delete l_pObj3;
 *
*/

/**
 * @page ChangeLogs Change Logs
 * @section UTILSINGLETON_H utilsngleton.H
 * @verbatim
 *
 * Flag PTR/DCR#   Userid    Date      Description
 * ---  ---------- --------  --------  --------------------------------------
 *      F698612    mjjones   01/19/08  Created - based off Ajay's code.
 *
 * @endverbatim
*/

#include <map>

namespace util
{

/**
 * @brief Generic Object Factory
 *
 * T_BaseClassType - The base class type of all the objects that this factory
 *                   can create
 *
 * T_UniqueIdType  - The type of unique id used to indicate which type of
 *                   object to create (This is usually an int (enum))
 */
template<typename T_BaseClassType, typename T_UniqueIdType>
class Factory
{
public:

    /**
     *  @brief Constructor
     *
     */
    Factory()
    {
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~Factory()
    {
    }

    /**
     *  @brief Register an object type with the factory.
     *
     *  Register an object type that this factory can create and associate it
     *  with the supplied unique id.
     *
     *  T_ClassType - The type of object being registered
     *
     *  @param i_UID
     *      The unique-id representing the type of object being registered
     *
     *  @return bool
     *      true  - the object was registered successfully
     *      false - the object was not registered successfully because of an
     *              existing registration with the same unique-id
     *
     */
    template<typename T_ClassType>
    bool Register(T_UniqueIdType i_UID)
    {
        if (iv_objectCreator.find(i_UID) != iv_objectCreator.end())
        {
            // There is an existing registration using this unique-id
            return false;
        }

        // Add the object-creator function to the map
        iv_objectCreator[i_UID] = &CreateObject<T_ClassType>;
        return true;
    }

    /**
     *  @brief Unregister an object type.
     *
     *  Unregister an object type that this factory can create
     *
     *  @param i_UID
     *      The unique-id representing the type of object being unregistered
     *
     *  @return bool
     *      true - the object was successfully unregistered
     *      false - the object was not previously registered
     *
     */
    bool Unregister(T_UniqueIdType i_UID)
    {
        return (iv_objectCreator.erase(i_UID) == 1);
    }

    /**
     *  @brief Create an object of the specified type
     *
     *  @param i_UID
     *      The unique-id representing the type of object being unregistered
     *
     *  @return T_BaseClassType *
     *      Pointer to the object created. If the UID was not registered then a
     *      NULL pointer is returned
     *
     */
    T_BaseClassType *Create(T_UniqueIdType i_UID)
    {
        typename IdToProductMap_t::const_iterator itr_t =
            iv_objectCreator.find(i_UID);
        if (itr_t != iv_objectCreator.end())
        {
            // Call the object creator function (CreateObject)
            return ((itr_t->second)());
        }
        return NULL;
    }

protected:

    /**
     *  @brief Object Creator function
     *
     *  T_ClassType - The type of object to create
     *
     *  @return T_BaseClassType *
     *      A pointer to the created object of type T_BaseClassType (this can be
     *      a sub-class of course)
     *
     */
    template<typename T_ClassType>
    static T_BaseClassType *CreateObject()
    {
        return new T_ClassType();
    }
    
    /**
     * @brief Typedef for the Create Object Function
     */
    typedef T_BaseClassType *(*CreateObjectFunc_t)();
    
    /**
     * @brief Typedef for the Map of UIDs and Create Object Functions
     */
    typedef std::map<T_UniqueIdType, CreateObjectFunc_t> IdToProductMap_t;
    
    /**
     * @brief Map of UIDs and Create Object Functions
     */
    IdToProductMap_t iv_objectCreator;

private:

    // Disabled
    Factory(const Factory & i_Right);
    Factory & operator=(const Factory & i_Right);
};

}
#endif
