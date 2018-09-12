/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:A derived class used to represent the create an object
that represent the airlock. It has 22 dat-members, and 10
methods. It also has two constructors (1 default) a destructor and 4
friend functions. 5 of the data members are for tracing global events.
6 are for tracking local events. 5 are for pointing to other rooms. 2
are for tracking user owned items. 4 are for tracking local items.
There are get methods for three data-members that effect global
events. there is a print method for the room description.There is a
method for controlling which menu is displayed. and there are 2
methods for parsing user menu choices. There is a get method for the
item the user is picking up, and a method for removing that item from
the space.
*********************************************************************/
#include<iostream>
#include<string>
#include<vector>

#include "space.hpp"
#include "airlock.hpp"
#include "workShop.hpp"
#include "engineRoom.hpp"
#include "stateRoom.hpp"
#include "bridge.hpp"
#include "outsideAirlock.hpp"
#include "stern.hpp"
#include "item.hpp"
#include "modularMenu.hpp"
#include "valid.hpp"
#include "descAbbr.hpp"
#include "overloadComparisons.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

////public////
/*********************************************************************
** Description: default constructor
*********************************************************************/
Airlock::Airlock() : Space()
{}



/*********************************************************************
** Description: constructor
*********************************************************************/
Airlock::Airlock(Space* as1, Space* as2, Space* as3, Space* as4,
      vector<Item*>* aitems, Item* ai1, Item* ai2) :
      Space(as1, as2, as3, as4, aitems, ai1, ai2)
{
    inShip = true;
    isDark = true;
    torchUsed = false;
    selector = 0;
    action = HELP;
    condition1 = false;
    condition2 = false;
    condition3 = false;
    condition4 = false;
    condition5 = false;
    condition6 = false;

    nextRoom = nullptr;

    itemSwap = nullptr;
}

/*********************************************************************
** Description: destructor overwrites ~Space
*********************************************************************/
Airlock::~Airlock()
{
    item1 = nullptr;
    item2 = nullptr;
    item3 = nullptr;
    item4 = nullptr;
    itemSwap = nullptr;

    forward = nullptr;
    aft = nullptr;
    starboard = nullptr;
    port = nullptr;
    nextRoom = nullptr;

    userKit = nullptr;
}

/*********************************************************************
** Description: describe the room
*********************************************************************/
void Airlock::describe()
{
    if(isDark && !torchUsed)
    {
      cout << descAbbr(100) << endl;
    }
    else if(condition1)
    {
      cout << descAbbr(77) << endl;
    }
    else
    {
      cout << descAbbr(76) << endl;
    }
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void Airlock::menu(int vogIn, bool lightsIn, bool hole,
                            bool eO, bool& deadIn)
{
    //ever present menu items
    const string m1 = "View Items";
    const string m2 = "Help / Info";

    //condition dependent actions
    const string o1 = "Use flashlight";
    const string o2 = "Enter door to workshop";
    const string o3 = "Enter door to engine room";
    const string o4 = "Cycle airlock";
    const string o5 = "Inspect the door to the engine room";
    const string o6 = "Inspect equipment locker";
    const string o7 = "Inspect spacesuit rack";
    const string o8 = "Repair airlock door";


    //ship-wide condition
    isDark = lightsIn;
    selector = 0;

    if(hole)
    {
      condition2 = true;
    }

    describe();

    if(isDark && !torchUsed)
    {
      switch(modularMenu(3, DIGIT, o1, m1, m2))
      {
        case 1: action = INTERACT;    //use flashlight
                selector = 1;
                itemSwap = nullptr;
              break;
        case 2: action = VIEWITEMS;   //view items
              break;
        case 3: action = HELP;        //help menu
              break;
      }
    }
    //have patched hull
    else if(condition2)
    {
      switch(modularMenu(7, DIGIT, o2, o4, o3, o6, o7, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = CHANGEROOM;   //exit ship / cycle airlock
               nextRoom = port;
               torchUsed = false;
             break;
       case 3: action = CHANGEROOM;   //enter engine room
               nextRoom = aft;
               torchUsed = false;
             break;
       case 4: action = INSPECT;     //inspect equipment locker
               selector = 2;
               itemSwap = &*item2;
             break;
       case 5: action = INSPECT;     //inspect spacesuit rack
               selector = 1;
               itemSwap = &*item1;
             break;
       case 6: action = VIEWITEMS;    //view items
             break;
       case 7: action = HELP;         //help menu
             break;
      }
    }
    //have fixed airlock
    else if(condition1)
    {
      bool tempBool = false;

      switch(modularMenu(7, DIGIT, o2, o4, o5, o6, o7, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: for(int i = 0; i < userKit->size(); ++i)
               {
                 if(userKit->at(i)->getName() == "patched spacesuit")
                 {
                   tempBool = true;
                   action = CHANGEROOM;   //exit ship / cycle airlock
                   nextRoom = port;
                   torchUsed = false;
                 }
               }

               if(!tempBool)
               {
                 deadIn = true;
               }
             break;
       case 3: action = INSPECT;     //inspect engine room door
               selector = 3;
               itemSwap = nullptr;
             break;
       case 4: action = INSPECT;     //inspect equipment locker
               selector = 2;
               itemSwap = &*item2;
             break;
       case 5: action = INSPECT;     //inspect spacesuit rack
               selector = 1;
               itemSwap = &*item1;
             break;
       case 6: action = VIEWITEMS;    //view items
             break;
       case 7: action = HELP;         //help menu
             break;
      }
    }
    //no actions taken yet
    else
    {
      switch(modularMenu(7, DIGIT, o2, o5, o6, o7, o8, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = INSPECT;     //inspect engine room door
               selector = 3;
               itemSwap = nullptr;
             break;
       case 3: action = INSPECT;     //inspect equipment locker
               selector = 2;
               itemSwap = &*item2;
             break;
       case 4: action = INSPECT;     //inspect spacesuit rack
               selector = 1;
               itemSwap = &*item1;
             break;
       case 5: action = INTERACT;     //repair airlock
               selector = 2;
               itemSwap = nullptr;
             break;
       case 6: action = VIEWITEMS;    //view items
             break;
       case 7: action = HELP;         //help menu
             break;
      }
    }
}

/*********************************************************************
** Description: give a description of something in the room
*********************************************************************/
bool Airlock::inspectThing()
{
    //for return
    bool tempBool = false;

    switch(selector)
    {
      case 1: if(item1 != nullptr)
              {
                cout << descAbbr(78) << endl;

                cout << "Would you like to take the damaged "
                     << "spacesuit?\n" << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the damaged spacesuit"
                               << "behind.\n" << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(79) << endl;
              }
            break;
      case 2: if(item2 != nullptr)
              {
                cout << descAbbr(80) << endl;

                cout << "Would you like to take the standard"
                     << " hull patch?\n" << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the hull patch behind.\n"
                               << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(81) << endl;
              }
            break;
      case 3: cout << descAbbr(82) << endl;
            break;
    }
    return tempBool;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void Airlock::interact(int& userItemsHeld, int& vogIn,
                      bool& userKitFull, bool& lightsIn,
                      bool& spaceSuitIn, bool& hole, bool& eO,
                      bool& win)
{
    bool tempTest = false;

    switch(selector)
    {
      case 1: torchUsed = true;
            break;
      case 2: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "pneumatic wrench")
                {
                  tempTest = true;
                  cout << descAbbr(83) << endl;
                  condition1 = true;
                  userKit->at(i) = nullptr;
                  userKit->erase(userKit->begin() + i);
                  userItemsHeld--;
                  if(userItemsHeld < 8)
                  {
                    userKitFull = false;
                  }
                }
              }

              if(!tempTest)
              {
                cout << descAbbr(84) << endl;
              }

            break;
    }
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* Airlock::itemToGet()
{
  return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void Airlock::removeItem()
{
  if(itemSwap->getName() == "damaged spacesuit")
  {
     item1 = nullptr;
     itemSwap = nullptr;
  }
  else if(itemSwap->getName() == "standard hull patch")
  {
   item2 = nullptr;
   itemSwap = nullptr;
  }
}
