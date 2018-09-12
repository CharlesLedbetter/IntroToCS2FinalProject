/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:
*********************************************************************/
#ifndef STATEROOM_HPP
#define STATEROOM_HPP

#include<iostream>
#include<string>
#include<vector>

#include "item.hpp"
#include "modularMenu.hpp"
#include "valid.hpp"
#include "descAbbr.hpp"
#include "overloadComparisons.hpp"

class StateRoom : public Space
{
  public:
    StateRoom();

    //constructor called by derived classes
    StateRoom(Space*, Space*, Space*, Space*, std::vector<Item*>*,
          Item*, Item*, Item*);

    //virtual destructor
    virtual ~StateRoom();

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

};

#endif
