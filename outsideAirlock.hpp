/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:
*********************************************************************/
#ifndef OUTSIDEAIRLOCK_HPP
#define OUTSIDEAIRLOCK_HPP

#include<iostream>
#include<string>
#include<vector>

#include "item.hpp"
#include "modularMenu.hpp"
#include "valid.hpp"
#include "descAbbr.hpp"
#include "overloadComparisons.hpp"

class OutsideAirlock : public Space
{
  public:
    OutsideAirlock();

    //constructor called by derived classes
    OutsideAirlock(Space*, Space*, Space*, Space*, std::vector<Item*>*);

    //virtual destructor
    virtual ~OutsideAirlock();

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
