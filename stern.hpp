/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description:
*********************************************************************/
#ifndef STERN_HPP
#define STERN_HPP

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

class Stern : public Space
{
  public:
    Stern();

    //constructor called by derived classes
    Stern(Space*, Space*, Space*, Space*, std::vector<Item*>*);

    //virtual destructor
    virtual ~Stern();

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
