/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:A derived class used to represent the create an object
that represent the workshop. It has 22 dat-members, and 10
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
WorkShop::WorkShop() : Space()
{}

/*********************************************************************
** Description: constructor
*********************************************************************/
WorkShop::WorkShop(Space* ws1, Space* ws2, Space* ws3, Space* ws4,
      vector<Item*>* witems, Item* wi1, Item* wi2, Item* wi3,
      Item* wi4) :
      Space(ws1, ws2, ws3, ws4, witems, wi1, wi2, wi3, wi4)
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
WorkShop::~WorkShop()
{
    item1 = nullptr;
    item2 = nullptr;
    item3 = nullptr;
    item4 = nullptr;
    itemSwap = nullptr;

    forward = nullptr;
    starboard = nullptr;
    aft = nullptr;
    port = nullptr;
    nextRoom = nullptr;

    userKit = nullptr;
}

/*********************************************************************
** Description: describe the room
*********************************************************************/
void WorkShop::describe()
{
    if(isDark && !torchUsed)
    {
      cout << descAbbr(100) << endl;
    }
    else if(condition6)
    {
      cout << descAbbr(56) << endl;
    }
    else if(condition5)
    {
      cout << descAbbr(55) << endl;
    }
    else if(condition4)
    {
      cout << descAbbr(55) << endl;
    }
    else if(condition2)
    {
      cout << descAbbr(53) << endl;
    }
    else if(condition1)
    {
      cout << descAbbr(52) << endl;
    }
    else
    {
      cout << descAbbr(51) << endl;
    }
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void WorkShop::menu(int vogIn, bool lightsIn, bool hole,
                              bool eO, bool& deadIn)
{
    //ever present menu items
    const string m1 = "View Items";
    const string m2 = "Help / Info";

    //condition dependent actions
    const string o1 = "Use flashlight";
    const string o2 = "Enter door to bridge";
    const string o3 = "Enter door to stateroom";
    const string o4 = "Enter door to airlock";
    const string o5 = "Inspect the toolbox";
    const string o6 = "Inspect the heavy equipment lockup";
    const string o7 = "Inspect the workbench";
    const string o8 = "Talk to Vogler";
    const string o9 = "Give Vogler the nano-threader";
    const string o10 = "Give Vogler the graphene patch";
    const string o11 = "Give Vogler the spacesuit";
    const string o12 = "Inspect spacesuit";
    const string o13 = "Take Vogler to his bed";

    //ship-wide condition
    isDark = lightsIn;
    selector = 0;

    if(vogIn == 2)
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
    //vogler has been moved to his bed
    else if(condition6)
    {
      switch(modularMenu(8, DIGIT, o2, o3, o4, o5, o6, o7, m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter bridge
                nextRoom = forward;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter airlock
                nextRoom = starboard;
                torchUsed = false;
              break;
        case 3: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 4: action = INSPECT;     //inspect tool chest
                selector = 3;
                itemSwap = &*item3;
              break;
        case 5: action = INSPECT;     //inspect heavy equipment
                selector = 2;
                itemSwap = &*item2;
              break;
        case 6: action = INSPECT;     //inspect workbench
                selector = 1;
                itemSwap = &*item1;
              break;
        case 7: action = VIEWITEMS;   //view items
              break;
        case 8: action = HELP;        //help menu
              break;
      }
    }
    //user has fixed spacesuit
    else if(condition5)
    {
      switch(modularMenu(9, DIGIT, o2, o3, o4, o5, o6, o7, o8,
                         m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter bridge
                nextRoom = forward;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter airlock
                nextRoom = starboard;
                torchUsed = false;
              break;
        case 3: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 4: action = INSPECT;     //inspect tool chest
                selector = 3;
                itemSwap = &*item3;
              break;
        case 5: action = INSPECT;     //inspect heavy equipment
                selector = 2;
                itemSwap = &*item2;
              break;
        case 6: action = INSPECT;     //inspect workbench
                selector = 1;
                itemSwap = &*item1;
              break;
        case 7: action = INTERACT;     //talk to Vogler v5
                selector = 6;
                itemSwap = nullptr;
              break;
        case 8: action = VIEWITEMS;   //view items
              break;
        case 9: action = HELP;        //help menu
              break;
      }
    }
    //vogler has spacesuit
    else if(condition4)
    {
      switch(modularMenu(10, DIGIT, o2, o3, o4, o12, o5, o6, o7, o8,
                         m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter bridge
                nextRoom = forward;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter airlock
                nextRoom = starboard;
                torchUsed = false;
              break;
        case 3: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 4: action = INSPECT;     //inspect spacesuit
                selector = 4;
                itemSwap = &*item4;
              break;
        case 5: action = INSPECT;     //inspect tool chest
                selector = 3;
                itemSwap = &*item3;
              break;
        case 6: action = INSPECT;     //inspect heavy equipment
                selector = 2;
                itemSwap = &*item2;
              break;
        case 7: action = INSPECT;     //inspect workbench
                selector = 1;
                itemSwap = &*item1;
              break;
        case 8: action = INTERACT;     //talk to Vogler v4
                selector = 5;
                itemSwap = nullptr;
              break;
        case 9: action = VIEWITEMS;   //view items
              break;
        case 10: action = HELP;        //help menu
              break;
      }
    }
    //vogler has patch
    else if(condition3)
    {
      switch(modularMenu(10, DIGIT, o2, o3, o4, o5, o6, o7, o11, o8,
                         m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter bridge
                nextRoom = forward;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter airlock
                nextRoom = starboard;
                torchUsed = false;
              break;
        case 3: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 4: action = INSPECT;     //inspect tool chest
                selector = 3;
                itemSwap = &*item3;
              break;
        case 5: action = INSPECT;     //inspect heavy equipment
                selector = 2;
                itemSwap = &*item2;
              break;
        case 6: action = INSPECT;     //inspect workbench
                selector = 1;
                itemSwap = &*item1;
              break;
        case 7: action = INTERACT;     //give spacesuit
                selector = 9;
                itemSwap = nullptr;
              break;
        case 8: action = INTERACT;     //talk to Vogler v3
                selector = 4;
                itemSwap = nullptr;
              break;
        case 9: action = VIEWITEMS;   //view items
              break;
        case 10: action = HELP;        //help menu
              break;
      }
    }
    //vogler has nano-threader
    else if(condition2)
    {
      switch(modularMenu(10, DIGIT, o2, o3, o4, o5, o6, o7, o10, o8,
                         m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter bridge
                nextRoom = forward;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter airlock
                nextRoom = starboard;
                torchUsed = false;
              break;
        case 3: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 4: action = INSPECT;     //inspect tool chest
                selector = 3;
                itemSwap = &*item3;
              break;
        case 5: action = INSPECT;     //inspect heavy equipment
                selector = 2;
                itemSwap = &*item2;
              break;
        case 6: action = INSPECT;     //inspect workbench
                selector = 1;
                itemSwap = &*item1;
              break;
        case 7: action = INTERACT;     //give patch
                selector = 8;
                itemSwap = nullptr;
              break;
        case 8: action = INTERACT;     //talk to Vogler v2
                selector = 3;
                itemSwap = nullptr;
              break;
        case 9: action = VIEWITEMS;   //view items
              break;
        case 10: action = HELP;        //help menu
              break;
      }
    }
    //Vogler is present
    else if(condition1)
    {
      switch(modularMenu(10, DIGIT, o2, o3, o4, o5, o6, o7, o9, o8,
                         m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter bridge
                nextRoom = forward;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter airlock
                nextRoom = starboard;
                torchUsed = false;
              break;
        case 3: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 4: action = INSPECT;     //inspect tool chest
                selector = 3;
                itemSwap = &*item3;
              break;
        case 5: action = INSPECT;     //inspect heavy equipment
                selector = 2;
                itemSwap = &*item2;
              break;
        case 6: action = INSPECT;     //inspect workbench
                selector = 1;
                itemSwap = &*item1;
              break;
        case 7: action = INTERACT;     //give nanoThreader
                selector = 7;
                itemSwap = nullptr;
              break;
        case 8: action = INTERACT;     //talk to Vogler v1
                selector = 2;
                itemSwap = nullptr;
              break;
        case 9: action = VIEWITEMS;   //view items
              break;
        case 10: action = HELP;        //help menu
              break;
      }
    }
    //no actions taken yet
    else
    {
      switch(modularMenu(8, DIGIT, o2, o3, o4, o5, o6, o7, m1, m2))
      {
        case 1: action = CHANGEROOM;  //enter bridge
                nextRoom = forward;
                torchUsed = false;
              break;
        case 2: action = CHANGEROOM;  //enter airlock
                nextRoom = starboard;
                torchUsed = false;
              break;
        case 3: action = CHANGEROOM;  //enter stateRoom
                nextRoom = aft;
                torchUsed = false;
              break;
        case 4: action = INSPECT;     //inspect tool chest
                selector = 3;
                itemSwap = &*item3;
              break;
        case 5: action = INSPECT;     //inspect heavy equipment
                selector = 2;
                itemSwap = &*item2;
              break;
        case 6: action = INSPECT;     //inspect workbench
                selector = 1;
                itemSwap = &*item1;
              break;
        case 7: action = VIEWITEMS;   //view items
              break;
        case 8: action = HELP;        //help menu
              break;
      }
  }
}

/*********************************************************************
** Description: give a description of something in the room
*********************************************************************/
bool WorkShop::inspectThing()
{
    //for return
    bool tempBool = false;

    switch(selector)
    {
      case 1: if(item1 != nullptr)
              {
                cout << descAbbr(57) << endl;

                cout << "Would you like to take the nano-threader?\n"
                     << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the nano-threader behind.\n"
                               << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(58) << endl;
              }
            break;
      case 2: if(item2 != nullptr)
              {
                cout << descAbbr(59) << endl;

                cout << "Would you like to take the plasma welder?"
                     << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the plasma welder "
                               << "behind.\n" << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(60) << endl;
              }
            break;
      case 3: if(item3 != nullptr)
              {
                cout << descAbbr(61) << endl;

                cout << "Would you like to take the pneumatic"
                     << " wrench?\n" << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                        break;
                  case 2: cout << "You left the pneumatic wrench "
                               << "behind.\n" << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(62) << endl;
              }
            break;
      case 4:  if(item4 != nullptr)
              {
                cout << descAbbr(63) << endl;

                cout << "Would you like to take the patched "
                     << "spacesuit?\n" << endl;

                switch(modularMenu(2, DIGIT, "yes", "no"))
                {
                  case 1: tempBool = true;
                          condition5 = true;
                        break;
                  case 2: cout << "You left the patched spacesuit "
                               << "behind.\n" << endl;
                        break;
                }
              }
              else
              {
                cout << descAbbr(64) << endl;
              }
            break;
    }
    return tempBool;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void WorkShop::interact(int& userItemsHeld, int& vogIn,
                      bool& userKitFull, bool& lightsIn,
                      bool& spaceSuitIn, bool& hole, bool& eO,
                      bool& win)
{
    bool tempTest = false;

    switch(selector)
    {
      case 1: torchUsed = true;
            break;
      case 2: cout << descAbbr(65) << endl;
            break;
      case 3: cout << descAbbr(66) << endl;
            break;
      case 4: cout << descAbbr(67) << endl;
            break;
      case 5: cout << descAbbr(68) << endl;
            break;
      case 6: cout << descAbbr(69) << endl;
              condition6 = true;
              vogIn = 3;
              nextRoom = starboard;
              action = CHANGEROOM;
            break;
      case 7: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "nano-threader")
                {
                  tempTest = true;
                  cout << descAbbr(70) << endl;
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
                cout << descAbbr(71) << endl;
              }
            break;
      case 8: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "graphene patch")
                {
                  tempTest = true;
                  cout << descAbbr(72) << endl;
                  condition3 = true;
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
                cout << descAbbr(73) << endl;
              }
            break;
      case 9: for(int i = 0; i < userKit->size(); ++i)
              {
                if(userKit->at(i)->getName() == "damaged spacesuit")
                {
                  tempTest = true;
                  cout << descAbbr(74) << endl;
                  condition4 = true;
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
                cout << descAbbr(75) << endl;
              }
            break;
    }
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* WorkShop::itemToGet()
{
  return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void WorkShop::removeItem()
{
  if(itemSwap->getName() == "nano-threader")
  {
    item1 = nullptr;
    itemSwap = nullptr;
  }
  else if(itemSwap->getName() == "plasma welder")
  {
    item2 = nullptr;
    itemSwap = nullptr;
  }
  else if(itemSwap->getName() == "pneumatic wrench")
  {
    item3 = nullptr;
    itemSwap = nullptr;
  }
  else if(itemSwap->getName() == "patched spacesuit")
  {
    item4 = nullptr;
    itemSwap = nullptr;
  }
}
