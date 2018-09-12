/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:A derived class used to represent the create an object
that represent the outside the ship. It has 22 dat-members, and 10
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
OutsideAirlock::OutsideAirlock() : Space()
{}

/*********************************************************************
** Description: constructor
*********************************************************************/
OutsideAirlock::OutsideAirlock(Space* oas1, Space* oas2,
        Space* oas3, Space* oas4, vector<Item*>* oaitems) :
        Space(oas1, oas2, oas3, oas4, oaitems)
{
    inShip = false;
    isDark = false;
    torchUsed = true;
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
OutsideAirlock::~OutsideAirlock()
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
}

/*********************************************************************
** Description: describe the room
*********************************************************************/
void OutsideAirlock::describe()
{
    cout << descAbbr(85) << endl;
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void OutsideAirlock::menu(int vogIn, bool lightsIn, bool hole,
                            bool eO, bool& deadIn)
{
    //ever present menu items
    const string m1 = "View Items";
    const string m2 = "Help / Info";

    //condition dependent actions
    const string o1 = "Reenter ship";
    const string o2 = "Move to the stern";

    //ship-wide condition
    isDark = lightsIn;
    selector = 0;

    describe();

    switch(modularMenu(4, DIGIT, o1, o2, m1, m2))
    {
      case 1: action = CHANGEROOM;   //enter airlock
              nextRoom = starboard;
            break;
      case 2: action = CHANGEROOM;   //move to aft
              nextRoom = aft;
            break;
      case 3: action = VIEWITEMS;   //view items
            break;
      case 4: action = HELP;        //help menu
            break;
    }
}

/*********************************************************************
** Description: give a description of something in the room
*********************************************************************/
bool OutsideAirlock::inspectThing()
{
    return false;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void OutsideAirlock::interact(int& userItemsHeld, int& vogIn,
                      bool& userKitFull, bool& lightsIn,
                      bool& spaceSuitIn, bool& hole, bool& eO,
                      bool& win)
{
   cout << "error\n" << endl;
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* OutsideAirlock::itemToGet()
{
  return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void OutsideAirlock::removeItem()
{
  cout << "error\n" << endl;
}
