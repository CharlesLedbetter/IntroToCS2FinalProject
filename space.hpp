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
#ifndef SPACE_HPP
#define SPACE_HPP

#include<iostream>
#include<string>
#include<vector>

#include "item.hpp"
#include "modularMenu.hpp"
#include "valid.hpp"
#include "descAbbr.hpp"
#include "overloadComparisons.hpp"

//enum for menu selection
enum Action {CHANGEROOM, INSPECT, INTERACT, VIEWITEMS, HELP};

class Space
{
  protected:
    //data-members
    bool inShip;
    bool isDark;
    bool torchUsed;
    int selector;
    Action action;

    //room conditions
    bool condition1;
    bool condition2;
    bool condition3;
    bool condition4;
    bool condition5;
    bool condition6;

    //directions
    Space* nextRoom;
    Space* forward;
    Space* aft;
    Space* starboard;
    Space* port;

    //item slots
    std::vector<Item*>* userKit;

    //local items
    Item* itemSwap;
    Item* item1;
    Item* item2;
    Item* item3;
    Item* item4;

  public:
    //default constructor called by derived classes
    Space();

    //constructor called by derived classes
    Space(Space*, Space*, Space*, Space*, std::vector<Item*>*,
          Item* i1 = nullptr, Item* i2 = nullptr, Item* i3 = nullptr,
          Item* i4 = nullptr);

    //virtual destructor
    virtual ~Space()=0;

    //a get method for action
    Action getAction();

    //return the next room to enter
    Space* getNextRoom();

    //returns if room is in spaceship
    bool getInShip();

    //describe the room
    virtual void describe();

    //void method for running the menu
    virtual void menu(int, bool, bool, bool, bool&);

    //give a description of something in the room
    virtual bool inspectThing();

    //displays actions and reactions
    virtual void interact(int&, int&, bool&, bool&, bool&,
                          bool&, bool&, bool&);

    //method for user picking up item
    virtual Item* itemToGet();

    //remove item from room
    virtual void removeItem();

    //used for loading descriptions
    friend std::string descAbbr(int);

    friend bool operator==(Item, Item);

    friend bool operator==(std::string, Item);

    friend bool operator==(Item, std::string);
};

#endif
