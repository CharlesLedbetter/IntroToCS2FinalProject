/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:A derived class used to represent the create an object
that represent the stateroom. It has 22 dat-members, and 10
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
StateRoom::StateRoom() : Space()
{}

/*********************************************************************
** Description: constructor
*********************************************************************/
StateRoom::StateRoom(Space* srs1, Space* srs2, Space* srs3, Space* srs4,
      vector<Item*>* sritems, Item* sri1, Item* sri2, Item* sri3) :
      Space(srs1, srs2, srs3, srs4, sritems, sri1, sri2, sri3)
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
StateRoom::~StateRoom()
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
void StateRoom::describe()
{
    if(isDark && !torchUsed)
    {
      cout << descAbbr(100) << endl;
    }
    else if(condition1)
    {
      cout << descAbbr(42) << endl;
    }
    else
    {
      cout << descAbbr(41) << endl;
    }
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void StateRoom::menu(int vogIn, bool lightsIn, bool hole,
                               bool eO, bool& deadIn)
{
    //ever present menu items
    const string m1 = "View Items";
    const string m2 = "Help / Info";

    //condition dependent actions
    const string o1 = "Use flashlight";
    const string o2 = "Enter door to bridge";
    const string o3 = "Enter door to workshop";
    const string o4 = "Inspect the kitchenette";
    const string o5 = "Inspect the lounge";
    const string o6 = "Inspect the lavatory";
    const string o7 = "Inspect the wall cabinet";
    const string o8 = "Talk to Vogler";

    //ship-wide condition
    isDark = lightsIn;
    selector = 0;

    if(vogIn == 3)
    {
      condition1 = true;
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
    //have helped Voglar to bed
    else if(condition1)
    {
      switch(modularMenu(9, DIGIT, o2, o3, o4, o5, o6, o7, o8,
                         m1, m2))
      {
       case 1: action = CHANGEROOM;     //enter bridge
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = CHANGEROOM;     //enter workshop
               nextRoom = port;
               torchUsed = false;
             break;
       case 3: action = INSPECT;        //inspect kitchenette
               selector = 4;
               itemSwap = &*item3;
             break;
       case 4: action = INSPECT;        //inspect sofa
               selector = 3;
               itemSwap = &*item2;
             break;
       case 5: action = INSPECT;        //inspect lavatory
               selector = 2;
               itemSwap = nullptr;
             break;
       case 6: action = INSPECT;        //inspect cabinet
               selector = 1;
               itemSwap = &*item1;
             break;
       case 7: action = INTERACT;       //talk to Vogler
               selector = 2;
               itemSwap = nullptr;
             break;
       case 8: action = VIEWITEMS;      //view items
             break;
       case 9: action = HELP;           //help menu
             break;
      }
    }
    //lights are on but Vogler is not here.
    else
    {
      switch(modularMenu(8, DIGIT, o2, o3, o4, o5, o6, o7, m1, m2))
      {
       case 1: action = CHANGEROOM;     //enter bridge
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = CHANGEROOM;     //enter workshop
               nextRoom = port;
               torchUsed = false;
             break;
       case 3: action = INSPECT;        //inspect kitchenette
               selector = 4;
               itemSwap = &*item3;
             break;
       case 4: action = INSPECT;        //inspect sofa
               selector = 3;
               itemSwap = &*item2;
             break;
       case 5: action = INSPECT;        //inspect lavatory
               selector = 2;
               itemSwap = nullptr;
             break;
       case 6: action = INSPECT;        //inspect cabinet
               selector = 1;
               itemSwap = &*item1;
             break;
       case 7: action = VIEWITEMS;      //view items
             break;
       case 8: action = HELP;           //help menu
             break;
      }
    }
}

/*********************************************************************
** Description: give a description of something in the room
*********************************************************************/
bool StateRoom::inspectThing()
{
    //for return
    bool tempBool = false;

    switch(selector)
    {
      case 1: if(item1 != nullptr)
              {
                cout << descAbbr(43) << endl;

                cout << "Would you like to take the first "
                     << "aid kit?\n" << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the first aid kit behind.\n"
                               << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(44) << endl;
              }
            break;
      case 2:  cout << descAbbr(45) << endl;
            break;
      case 3: if(item2 != nullptr)
              {
                cout << descAbbr(46) << endl;

                cout << "Would you like to cut a patch from the sofa"
                " using your multitool?\n" << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "It is too bad that there is no "
                               << "time to have a seat.\n It looks"
                               << " very comfy.\n" << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(47) << endl;
              }
            break;
      case 4: if(item3 != nullptr)
              {
                cout << descAbbr(48) << endl;

                cout << "Would you like to take a snack bar?\n"
                     << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the snack bar behind.\n"
                               << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(49) << endl;
              }
            break;

    }
    return tempBool;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void StateRoom::interact(int& userItemsHeld, int& vogIn,
                      bool& userKitFull, bool& lightsIn,
                      bool& spaceSuitIn, bool& hole, bool& eO,
                      bool& win)
{
    switch(selector)
    {
      case 1: torchUsed = true;
            break;
      case 2: cout << descAbbr(50) << endl;
            break;
    }
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* StateRoom::itemToGet()
{
  return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void StateRoom::removeItem()
{
  if(itemSwap->getName() == "first aid kit")
  {
    item1 = nullptr;
    itemSwap = nullptr;
  }
  else if(itemSwap->getName() == "graphene patch")
  {
    item2 = nullptr;
    itemSwap = nullptr;
  }
  else if(itemSwap->getName() == "snack bar")
  {
    item3 = nullptr;
    itemSwap = nullptr;
  }
}
