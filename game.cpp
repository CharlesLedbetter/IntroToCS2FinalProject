/*********************************************************************
** Program name: final project (textGame)
** Author: Charles Ledbetter
** Date: 8/13/2017
** Description: Implementation for a class that has 31 data-members,
and 4 methods. There are also 2 private methods used for initializing
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
#include<string>
#include<vector>

#include "game.hpp"
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

using std::cout;
using std::endl;
using std::string;
using std::vector;


////private////
/*********************************************************************
** Description: Used for loading Item objects with names and
descriptions
*********************************************************************/
void Game::loadItems()
{
  flashlight = Item("flashlight", descAbbr(6));
  multitool = Item("multitool", descAbbr(7));
  foodBar = Item("snack bar", descAbbr(8));
  firstAid = Item("first aid kit", descAbbr(9));
  patchCable = Item("patch cable", descAbbr(10));
  dSuit = Item("damaged spacesuit", descAbbr(11));
  nanoThreader = Item("nano-threader", descAbbr(12));
  graphenePatch = Item("graphene patch", descAbbr(13));
  repairedSpaceSuit = Item("patched spacesuit", descAbbr(14));
  pneumaticWrench = Item("pneumatic wrench", descAbbr(15));
  plasmaWelder = Item("plasma welder", descAbbr(16));
  hullPatch = Item("standard hull patch", descAbbr(17));
}



/*********************************************************************
** Description: used for loading derived Space objects with Space
pointers, Item pointers and a pointer to the user inventory vector
*********************************************************************/
void Game::loadRooms()
{
    bridge = Bridge(nullptr, &stateRoom, nullptr, &workShop, &kit,
                    &patchCable);
    airlock = Airlock(&workShop, &engineRoom, nullptr, &outsideAirlock,
                      &kit, &dSuit, &hullPatch);
    workShop = WorkShop(&bridge, &airlock, &stateRoom, nullptr,
                        &kit,  &nanoThreader, &plasmaWelder,
                        &pneumaticWrench, &repairedSpaceSuit);
    stateRoom = StateRoom(&bridge, nullptr, nullptr, &workShop,
                          &kit, &firstAid, &graphenePatch, &foodBar);
    engineRoom = EngineRoom(&airlock, nullptr, nullptr, nullptr,
                            &kit);
    outsideAirlock = OutsideAirlock(nullptr, &stern, &airlock, nullptr,
                                    &kit);
    stern = Stern(&outsideAirlock, nullptr, nullptr, nullptr, &kit);
}


////public////
/*********************************************************************
** Description: calls all other methods (some indirectly) and sets
initial game conditions
*********************************************************************/
Game::Game()
{
    loadItems();
    loadRooms();

    currentRoom = &stateRoom;

    kit.push_back(&flashlight);
    kit.push_back(&multitool);
    itemsHeld = 2;
    kitFull = false;
    steps = 0;
    vogler = 1;
    lights = true;
    spaceSuit = false;
    holePatched = false;
    enginesOnline = false;
    winning = false;
    dead = false;

    playGame();
}

/*********************************************************************
** Description: insures pointers are set to null and deleted
*********************************************************************/
Game::~Game()
{
    currentRoom = nullptr;

    for (int i = 0; i < kit.size(); ++i)
    {
    kit.at(i) = nullptr;
    }
    kit.clear();
}

/*********************************************************************
** Description: loops through game until gameover or win. Give welcome
message than calls room menu, parsing input until winning condition is
met or losing condition met, player quits.
*********************************************************************/
void Game::playGame()
{
    //used for time running out message
    int tempRand = 0;

    //used to check if player has quit
    bool quit = false;

    //welcome messages
    cout << descAbbr(1) << endl;
    cout << descAbbr(2) << endl;
    cout << descAbbr(3) << endl;

    //loop until the game ends
    do {
      //step counter
      steps++;

      //more that 55 steps give dire warning
      if(steps > 55 && currentRoom->getInShip())
      {
      cout << descAbbr(4) << endl;
      }
      //if more that 30 steps give warning
      else if(steps > 30)
      {
        tempRand = (rand() % 3);
        if(tempRand == 0)
        {
          cout << descAbbr(5) << endl;
        }
      }

      //call the menu of the room
      currentRoom->menu(vogler, lights, holePatched,
                        enginesOnline, dead);

      //parse inspect object
      if(currentRoom->getAction() == INSPECT)
      {
        bool itemTest = false;
        itemTest = currentRoom->inspectThing();
        if(itemTest)
        {
          pickUpItem(currentRoom->itemToGet());
        }
      }

      //parse interact with object or person
      else if(currentRoom->getAction() == INTERACT)
      {
        currentRoom->interact(itemsHeld, vogler,
                              kitFull, lights, spaceSuit,
                              holePatched, enginesOnline,
                              winning);
      }

      //show user a list of their items
      else if(currentRoom->getAction() == VIEWITEMS)
      {
        viewItems();
      }

      //show user help / quit message and menu
      else if(currentRoom->getAction() == HELP)
      {
        quit = help();
      }

      //if the user chose to change rooms
      if(currentRoom->getAction() == CHANGEROOM)
      {
        currentRoom = currentRoom->getNextRoom();
      }


    } while(!winning && (steps < 75) && !dead && !quit);

    //display win message
    if(winning)
    {
      cout << descAbbr(105) << endl;
    }
    // in ship without spacesuit and lose
    else if(steps >= 75 && currentRoom->getInShip() && !spaceSuit)
    {
      cout << descAbbr(101)<< endl;
    }
    //in ship with space suit and lose
    else if(steps >= 75 && currentRoom->getInShip() && spaceSuit)
    {
      cout << descAbbr(102)<< endl;
    }
    //outside ship when it explodes and lose
    else if(steps >= 75 && !currentRoom->getInShip())
    {
      cout << descAbbr(103)<< endl;
    }
    //cycle the airlock without a suit on and lose
    else if(dead)
    {
      cout << descAbbr(104) << endl;
    }

      //show how many rounds they lasted.
      cout << "\nYou played for " << steps << " turns.\n" << endl;
}


/*********************************************************************
** Description: adds the item passed to it by a Space object
*********************************************************************/
void Game::pickUpItem(Item* toInv)
{
    //when inventory full reject item
    if(kitFull)
    {
      cout << "Sorry but you do not have room for that item. Use up "
           << "some items and try again.\n" << endl;
    }
    //when inventory not full take item
    else
    {
      kit.push_back(&*toInv);
      if(*toInv == "patched spacesuit")
      {
        spaceSuit = true;
      }

      currentRoom->removeItem();
      itemsHeld++;
      if(itemsHeld > 7)
      {
        kitFull = true;
      }
    }
}

/*********************************************************************
** Description: shows a list of items with descriptions
*********************************************************************/
void Game::viewItems()
{
    //show a list of the players items
    cout << "Your items:\n\n";
    for(int i = 0; i < kit.size(); ++i)
    {
      cout << (i + 1) << " " << kit.at(i)->getName() << "\n";
      cout << "   " << kit.at(i)->getDesc() << "\n";
    }
    cout << endl;

    //correct steps
    steps--;
}

/*********************************************************************
** Description: shows a help message and a quit menu
*********************************************************************/
bool Game::help()
{
    //for return
    bool tempBool = false;

    //help message
    cout << descAbbr(106) << endl;

    cout << "Would you like to continue playing?\n" << endl;

    switch(modularMenu(2, DIGIT, "continue playing", "quit game"))
    {
      case 1:
            break;
      case 2: tempBool = true;
            break;
    }

    //correct steps
    steps--;

    //
    return tempBool;
}
