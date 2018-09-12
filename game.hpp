/*********************************************************************
** Program name: project3 (arena)
** Author: Charles Ledbetter
** Date: 8/3/2017
** Description: Declaration for a class that has 31 data-members, and
4 methods. There are also 2 private methods used for initializing
data-members. There are also 4 friend functions a constructor and a
destructor. 3 of the data members are for holding and tracking
pointers to Item objects in a vector. 8 of the data members are for
tracking global game events. 1 of the data members if a pointer to a
Space that represents the current room. There are 7 derived Space
objects that represent each 'room' of the game. There are 12 Item
objects that represent items in the game. The constructor calls all
other methods. The playGame method loops through the game. All other
public methods are helper methods to playGame.
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

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

class Game
{
  private:
    //data-members
    std::vector<Item*> kit;
    int itemsHeld;
    bool kitFull;

    //global events
    int steps;
    int vogler;
    bool lights;
    bool spaceSuit;
    bool holePatched;
    bool enginesOnline;
    bool winning;
    bool dead;

    //points to current room
    Space* currentRoom;

    //rooms
    Bridge bridge;
    Airlock airlock;
    WorkShop workShop;
    StateRoom stateRoom;
    EngineRoom engineRoom;
    OutsideAirlock outsideAirlock;
    Stern stern;

    //items
    Item flashlight;
    Item multitool;
    Item foodBar;
    Item firstAid;
    Item patchCable;
    Item dSuit;
    Item nanoThreader;
    Item graphenePatch;
    Item repairedSpaceSuit;
    Item pneumaticWrench;
    Item plasmaWelder;
    Item hullPatch;

    //for initializing Items
    void loadItems();

    //for initializing spaces
    void loadRooms();

  public:
    //constructor that calls all other methods (some indirectly)
    Game();

    //destructor avoids dangling pointers
    ~Game();

    //loops through game until gameover or win
    void playGame();

    //updates user held items
    void pickUpItem(Item*);

    //print list of items with descriptions
    void viewItems();

    //help menu
    bool help();

    //helper functions
    //overload == for Item objects
    friend bool operator==(Item, Item);

    friend bool operator==(std::string, Item);

    friend bool operator==(Item, std::string);

    //used for loading descriptions
    friend std::string descAbbr(int);
};

#endif
