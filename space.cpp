/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description: An abstract class used to create derived objects that
represent spaces in the game world. It has 22 dat-members, and 10
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
** Description: default constructor called by derived classes
*********************************************************************/
Space::Space()
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
    forward = nullptr;;
    aft = nullptr;;
    starboard = nullptr;;
    port = nullptr;;

    itemSwap = nullptr;
    item1 = nullptr;;
    item2 = nullptr;;
    item3 = nullptr;;
    item4 = nullptr;;
    userKit = nullptr;;
}

/*********************************************************************
** Description: constructor called by derived classes
*********************************************************************/
Space::Space(Space* s1, Space* s2, Space* s3, Space* s4,
      std::vector<Item*>* userKitIn, Item* i1, Item* i2,
      Item* i3, Item* i4)
{
    action = HELP;

    nextRoom = nullptr;
    forward = s1;
    aft = s2;
    starboard = s3;
    port = s4;

    itemSwap = nullptr;
    item1 = i1;
    item2 = i2;
    item3 = i3;
    item4 = i4;
    userKit = userKitIn;
}

/*********************************************************************
** Description: virtual destructor
*********************************************************************/
Space::~Space()
{}

/*********************************************************************
** Description: a get method for action
*********************************************************************/
Action Space::getAction()
{
    return action;
}

/*********************************************************************
** Description: return the next room to enter
*********************************************************************/
Space* Space::getNextRoom()
{
    return nextRoom;
}

/*********************************************************************
** Description: returns if room is in spaceship
*********************************************************************/
bool Space::getInShip()
{
    return inShip;
}

/*********************************************************************
** Description: describe the room
*********************************************************************/
void Space::describe()
{
    cout << "inheritance error\n" << endl;
}

/*********************************************************************
** Description: void method for running the menu
*********************************************************************/
void Space::menu(int i, bool b1, bool b2, bool b3, bool& b4)
{
    cout << "inheritance error\n" << endl;
}

/*********************************************************************
** Description: give a description of something in the room
*********************************************************************/
bool Space::inspectThing()
{
    cout << "inheritance error\n" << endl;
    return false;
}

/*********************************************************************
** Description: displays actions and reactions
*********************************************************************/
void Space::interact(int& i1, int& i2, bool& b1, bool& b2, bool& b3,
                             bool& b4, bool& b5, bool& b6)
{
    cout << "inheritance error\n" << endl;
}

/*********************************************************************
** Description: method for user picking up item
*********************************************************************/
Item* Space::itemToGet()
{
    cout << "inheritance error\n" << endl;
    return itemSwap;
}

/*********************************************************************
** Description: remove item from room
*********************************************************************/
void Space::removeItem()
{
    cout << "inheritance error\n" << endl;
}
