/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:A derived class used to represent the create an object
that represent the engine room. It has 22 dat-members, and 10
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
EngineRoom::EngineRoom() : Space()
{}


/*********************************************************************
** Description: constructor
*********************************************************************/
EngineRoom::EngineRoom(Space* es1, Space* es2, Space* es3, Space* es4,
      vector<Item*>* eitems) :
      Space(es1, es2, es3, es4, eitems)
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
EngineRoom::~EngineRoom()
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
void EngineRoom::describe()
{
    if(condition2)
    {
      cout << descAbbr(95) << endl;
    }
    else
    {
      cout << descAbbr(94) << endl;
    }
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void EngineRoom::menu(int vogIn, bool lightsIn, bool hole,
                            bool eO, bool& deadIn)
{
    //ever present menu items
    const string m1 = "View Items";
    const string m2 = "Help / Info";

    //condition dependent actions
    const string o1 = "Enter door to airlock";
    const string o2 = "Activate manual systems override";
    const string o3 = "Activate automated engine rebuild";
    const string o4 = "Inspect the engine";


    //ship-wide condition
    isDark = lightsIn;
    selector = 0;

    describe();

    //reset 2
    if(condition2)
    {
      switch(modularMenu(4, DIGIT, o1, o4, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter airlock
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = INSPECT;     //inspect engines v2
               selector = 2;
               itemSwap = nullptr;
             break;
       case 3: action = VIEWITEMS;    //view items
             break;
       case 4: action = HELP;         //help menu
             break;
      }
    }
    //reset 1
    else if(condition1)
    {
      switch(modularMenu(5, DIGIT, o1, o3, o4, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter airlock
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = INTERACT;    //activate engine rebuild
               selector = 2;
               itemSwap = nullptr;
              break;
       case 3: action = INSPECT;     //inspect engines v1
               selector = 1;
               itemSwap = nullptr;
             break;
       case 4: action = VIEWITEMS;    //view items
             break;
       case 5: action = HELP;         //help menu
             break;
      }
    }
    else
    {
      switch(modularMenu(5, DIGIT, o1, o2, o4, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter airlock
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = INTERACT;    //activate reset computers
               selector = 1;
               itemSwap = nullptr;
              break;
       case 3: action = INSPECT;     //inspect engines v1
               selector = 1;
               itemSwap = nullptr;
             break;
       case 4: action = VIEWITEMS;    //view items
             break;
       case 5: action = HELP;         //help menu
             break;
      }
    }
}

/*********************************************************************
** Description: give a description of something in the room
*********************************************************************/
bool EngineRoom::inspectThing()
{
    //for return
    bool tempBool = false;

    switch(selector)
    {
      case 1: cout << descAbbr(96) << endl;
            break;
      case 2: cout << descAbbr(97) << endl;
            break;
    }

    return tempBool;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void EngineRoom::interact(int& userItemsHeld, int& vogIn,
                      bool& userKitFull, bool& lightsIn,
                      bool& spaceSuitIn, bool& hole, bool& eO,
                      bool& win)
{
    switch(selector)
    {
      case 1: cout << descAbbr(98) << endl;
              condition1 = true;
            break;
      case 2: cout << descAbbr(99) << endl;
              condition2 = true;
              eO = true;
            break;
    }
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* EngineRoom::itemToGet()
{
  return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void EngineRoom::removeItem()
{
  cout << "error\n" << endl;
}
