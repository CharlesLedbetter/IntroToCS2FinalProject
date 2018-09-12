/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:A derived class used to represent the create an object
that represent the bridge. It has 22 dat-members, and 10
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
Bridge::Bridge() : Space()
{}

/*********************************************************************
** Description: constructor
*********************************************************************/
Bridge::Bridge(Space* bs1, Space* bs2, Space* bs3, Space* bs4,
      vector<Item*>* bitems, Item* bi1) :
      Space(bs1, bs2, bs3, bs4, bitems, bi1)
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
Bridge::~Bridge()
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
void Bridge::describe()
{
    if(isDark && !torchUsed)
    {
      cout << descAbbr(100) << endl;
    }
    else if(condition6)
    {
      cout << descAbbr(24) << endl;
    }
    else if(condition5)
    {
      cout << descAbbr(23) << endl;
    }
    else if(condition4)
    {
      cout << descAbbr(22) << endl;
    }
    else if(condition3)
    {
      cout << descAbbr(21) << endl;
    }
    else if(condition2)
    {
      cout << descAbbr(20) << endl;
    }
    else if(condition1)
    {
      cout << descAbbr(19) << endl;
    }
    else
    {
      cout << descAbbr(18) << endl;
    }
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void Bridge::menu(int vogIn, bool lightsIn, bool hole,
                            bool eO, bool& deadIn)
{
    //ever present menu items
    const string m1 = "View Items";
    const string m2 = "Help / Info";

    //condition dependent actions
    const string o1 = "Use flashlight";
    const string o2 = "Enter door to workshop";
    const string o3 = "Enter door to stateroom";
    const string o4 = "Help Vogler";
    const string o5 = "Inspect main console";
    const string o6 = "Inspect bin";
    const string o7 = "Revive Vogler";
    const string o8 = "Talk to Vogler";
    const string o9 = "Remove console's access panel";
    const string o10 = "Repair main console";
    const string o11 = "Give snack bar to Vogler";
    const string o12 = "Reboot main console";

    //ship-wide condition
    isDark = lightsIn;
    selector = 0;

    describe();

    if(eO)
    {
      switch(modularMenu(6, DIGIT, o2, o3, o12, o6, m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter workShop
                nextRoom = port;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 3: action = INTERACT;    //reboot main console
                selector = 10;
                itemSwap = nullptr;
              break;
        case 4: action = INSPECT;     //inspect bin
                selector = 1;
                itemSwap = &*item1;
              break;
        case 5: action = VIEWITEMS;   //view items
              break;
        case 6: action = HELP;        //help menu
              break;
        }
    }
    else if(isDark && !torchUsed)
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
    //have feed Vogler and moved him to
    else if(condition6)
    {
      switch(modularMenu(6, DIGIT, o2, o3, o5, o6, m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter workShop
                nextRoom = port;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 3: action = INSPECT;     //inspect console v2
                selector = 3;
                itemSwap = nullptr;
              break;
        case 4: action = INSPECT;     //inspect bin
                selector = 1;
                itemSwap = &*item1;
              break;
        case 5: action = VIEWITEMS;   //view items
              break;
        case 6: action = HELP;        //help menu
              break;
      }
    }
    //have removed panel and fixed lights
    else if(condition5)
    {
      switch(modularMenu(8, DIGIT, o2, o3, o5, o6, o8, o11,
                             m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter workShop
                nextRoom = port;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 3: action = INSPECT;     //inspect console v2
                selector = 3;
                itemSwap = nullptr;
              break;
        case 4: action = INSPECT;     //inspect bin
                selector = 1;
                itemSwap = &*item1;
              break;
        case 5: action = INTERACT;    ///talk to Vogler v3
                selector = 8;
                itemSwap = nullptr;
              break;
        case 6: action = INTERACT;    //give food bar to Vogler
                selector = 9;
                itemSwap = nullptr;
              break;
        case 7: action = VIEWITEMS;   //view items
              break;
        case 8: action = HELP;        //help menu
              break;
      }
    }
    //have removed panel
    else if(condition4)
    {
      switch(modularMenu(8, DIGIT, o2, o3, o5, o6, o8, o10,
                             m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter workShop
                nextRoom = port;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 3: action = INSPECT;     //inspect console v1
                selector = 2;
                itemSwap = nullptr;
              break;
        case 4: action = INSPECT;     //inspect bin
                selector = 1;
                itemSwap = &*item1;
              break;
        case 5: action = INTERACT;    //talk to Vogler v2
                selector = 5;
                itemSwap = nullptr;
              break;
        case 6: action = INTERACT;    //repair main console
                selector = 7;
                itemSwap = nullptr;
              break;
        case 7: action = VIEWITEMS;   //view items
              break;
        case 8: action = HELP;        //help menu
              break;
      }
    }
    //have spoken with Voglar about problem
    else if(condition3)
    {
      switch(modularMenu(8, DIGIT, o2, o3, o5, o6, o8, o9,
                             m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = port;
               torchUsed = false;
             break;
       case 2: action = CHANGEROOM;   //enter stateRoom
               nextRoom = aft;
               torchUsed = false;
             break;
       case 3: action = INSPECT;      //inspect console v1
               selector = 2;
               itemSwap = nullptr;
             break;
       case 4: action = INSPECT;      //inspect bin
               selector = 1;
               itemSwap = &*item1;
             break;
       case 5: action = INTERACT;     //talk to Vogler v2
               selector = 5;
               itemSwap = nullptr;
             break;
       case 6: action = INTERACT;     //remove access panel
               selector = 6;
               itemSwap = nullptr;
             break;
       case 7: action = VIEWITEMS;    //view items
             break;
       case 8: action = HELP;         //help menu
             break;
      }
    }
    //have revived Voglar
    else if(condition2)
    {
      switch(modularMenu(7, DIGIT, o2, o3, o5, o6, o8, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = port;
               torchUsed = false;
             break;
       case 2: action = CHANGEROOM;   //enter stateRoom
               nextRoom = aft;
               torchUsed = false;
             break;
       case 3: action = INSPECT;      //inspect console v1
               selector = 2;
               itemSwap = nullptr;
             break;
       case 4: action = INSPECT;      //inspect bin
               selector = 1;
               itemSwap = &*item1;
             break;
       case 5: action = INTERACT;     //talk to Vogler v1
               selector = 4;
               itemSwap = nullptr;
             break;
       case 6: action = VIEWITEMS;    //view items
             break;
       case 7: action = HELP;         //help menu
             break;
      }
    }
    //have helped Voglar
    else if(condition1)
    {
      switch(modularMenu(7, DIGIT, o2, o3, o5, o6, o7, m1, m2))
      {
       case 1: action = CHANGEROOM;     //enter workShop
               nextRoom = port;
               torchUsed = false;
             break;
       case 2: action = CHANGEROOM;     //enter stateRoom
               nextRoom = aft;
               torchUsed = false;
             break;
       case 3: action = INSPECT;        //inspect console v1
               selector = 2;
               itemSwap = nullptr;
             break;
       case 4: action = INSPECT;        //inspect bin
               selector = 1;
               itemSwap = &*item1;
             break;
       case 5: action = INTERACT;       //revive Vogler
               selector = 3;
               itemSwap = nullptr;
             break;
       case 6: action = VIEWITEMS;      //view items
             break;
       case 7: action = HELP;           //help menu
             break;
      }
    }
    //no actions taken yet
    else
    {
      switch(modularMenu(5, DIGIT, o2, o3, o4, m1, m2))
      {
       case 1: action = CHANGEROOM;   //enter workShop
               nextRoom = port;
               torchUsed = false;
             break;
       case 2: action = CHANGEROOM;   //enter stateRoom
               nextRoom = aft;
               torchUsed = false;
             break;
       case 3: action = INTERACT;     //help Vogler
               selector = 2;
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
bool Bridge::inspectThing()
{
    //for return
    bool tempBool = false;

    switch(selector)
    {
      case 1: if(item1 != nullptr)
              {
                cout << descAbbr(25) << endl;

                cout << "Would you like to take the patch "
                     << "cable?\n" << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the patch cable behind.\n"
                               << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(26) << endl;
              }
            break;
      case 2: cout << descAbbr(27) << endl;
            break;
      case 3: cout << descAbbr(28) << endl;
            break;
    }
    return tempBool;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void Bridge::interact(int& userItemsHeld, int& vogIn,
                      bool& userKitFull, bool& lightsIn,
                      bool& spaceSuitIn, bool& hole, bool& eO,
                      bool& win)
{
    bool tempTest = false;

    switch(selector)
    {
      case 1: torchUsed = true;
            break;
      case 2: cout << descAbbr(29) << endl;
              condition1 = true;
            break;
      case 3: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName()
                   == "first aid kit")
                {
                  tempTest = true;
                  cout << descAbbr(30) << endl;
                  condition2 = true;
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
                cout << descAbbr(31) << endl;
              }
            break;
      case 4: cout << descAbbr(32) << endl;
              condition3 = true;
            break;
      case 5: cout << descAbbr(33) << endl;
            break;
      case 6: cout << descAbbr(34) << endl;
              condition4 = true;
            break;
      case 7: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "patch cable")
                {
                  tempTest = true;
                  cout << descAbbr(35) << endl;
                  condition5 = true;
                  lightsIn = false;
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
                cout << descAbbr(36) << endl;
              }
            break;
      case 8: cout << descAbbr(37) << endl;
            break;
      case 9: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "snack bar")
                {
                  tempTest = true;
                  cout << descAbbr(38) << endl;
                  condition6 = true;
                  vogIn = 2;
                  nextRoom = port;
                  action = CHANGEROOM;
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
                cout << descAbbr(39) << endl;
              }
            break;
      case 10: cout << descAbbr(40) << endl;
               win = true;
            break;
    }
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* Bridge::itemToGet()
{
  return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void Bridge::removeItem()
{
  if(itemSwap->getName() == "patch cable")
  {
    item1 = nullptr;
    itemSwap = nullptr;
  }
}
