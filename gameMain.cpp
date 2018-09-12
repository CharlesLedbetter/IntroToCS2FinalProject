/*********************************************************************
** Program name: final project (textGame)
** Author: Charles Ledbetter
** Date: 8/13/2017
** Description: This program is an interactive text game. It gives
the player choices in a menu and allows them to choose the order in
which they do things, yet the story is linear overall. The game is
made up of 7 spaces that have items to collect and use. The player
has 75 turns to complete the game before the ship explodes.
*********************************************************************/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

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

int main()
{
    //constants for modularMenu
    //number of menu items
    const int menu1Count = 2;

    //menu type in modularMenu's Menu enum
    const Menu menuEnum = DIGIT;

    //menu option strings
    const string menu1Op1 = "Yes";
    const string menu1Op2 = "No";

    //variable for test if user has quit
    bool gameOn = true;

    //initialize random numbers
    srand(time(0));

    //continue to loop main menu until user quits
    do {
      //variable for menu testing
      int menuTest = 0;

      //call the game object
      Game game;

      //ask to play again
      cout << "Would you like to play again?\n" << endl;

      //display menu and get a validated user choice
      menuTest = modularMenu(menu1Count, menuEnum, menu1Op1, menu1Op2);

      switch(menuTest)
      {
        case 1: cout << "\n\n" << endl;
              break;
        case 2: cout << "Thank you for playing.\n" << endl;
                gameOn = false;
                break;
        default: cout << "An error has occurred.\n" << endl;
      }

    } while(gameOn);

    return 0;
}
