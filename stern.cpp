/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:** Description:A derived class used to represent the create an object
that represent the stern. It has 22 dat-members, and 10
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
Stern::Stern() : Space()
{}

/*********************************************************************
** Description: constructor
*********************************************************************/
Stern::Stern(Space* sts1, Space* sts2, Space* sts3, Space* sts4,
      vector<Item*>* stitems) :
      Space(sts1, sts2, sts3, sts4, stitems)
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
Stern::~Stern()
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
void Stern::describe()
{
    if(condition2)
    {
      cout << descAbbr(88) << endl;
    }
    else if(condition1)
    {
      cout << descAbbr(87) << endl;
    }
    else
    {
      cout << descAbbr(86) << endl;
    }
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void Stern::menu(int vogIn, bool lightsIn, bool hole,
                            bool eO, bool& deadIn)
{
    //ever present menu items
    const string m1 = "View Items";
    const string m2 = "Help / Info";

    //condition dependent actions
    const string o1 = "Move back to airlock";
    const string o2 = "Patch hull";
    const string o3 = "Secure patch";
    const string o4 = "Inspect the cosmos";


    //ship-wide condition
    isDark = lightsIn;
    selector = 0;

    if(hole)
    {
      condition2 = true;
    }

    describe();

    //hull sealed
    if(condition2)
    {
      switch(modularMenu(4, DIGIT, o1, o4, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = INSPECT;     //inspect the cosmos
               selector = 1;
               itemSwap = nullptr;
             break;
       case 3: action = VIEWITEMS;    //view items
             break;
       case 4: action = HELP;         //help menu
             break;
      }
    }
    //have patch on
    else if(condition1)
    {

      switch(modularMenu(5, DIGIT, o1, o3, o4, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = INTERACT;    //weld patch
               selector = 2;
               itemSwap = nullptr;
              break;
       case 3: action = INSPECT;     //inspect the cosmos
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
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = forward;
               torchUsed = false;
             break;
       case 2: action = INTERACT;    //place patch
               selector = 1;
               itemSwap = nullptr;
              break;
       case 3: action = INSPECT;     //inspect the cosmos
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
bool Stern::inspectThing()
{
    //for return
    bool tempBool = false;

    switch(selector)
    {
      case 1: cout << descAbbr(89) << endl;
    }

    return tempBool;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void Stern::interact(int& userItemsHeld, int& vogIn,
                      bool& userKitFull, bool& lightsIn,
                      bool& spaceSuitIn, bool& hole, bool& eO,
                      bool& win)
{
    bool tempTest = false;

    switch(selector)
    {
      case 1: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "standard hull patch")
                {
                  tempTest = true;
                  cout << descAbbr(90) << endl;
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
                cout << descAbbr(91) << endl;
              }
            break;
      case 2: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "plasma welder")
                {
                  tempTest = true;
                  cout << descAbbr(92) << endl;
                  condition2 = true;
                  hole = true;
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
                cout << descAbbr(93) << endl;
              }
            break;
    }
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* Stern::itemToGet()
{
  return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void Stern::removeItem()
{
  cout << "error\n" << endl;
}
