/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description: Declaration of a class that has two data members and
two get methods. It also has a default constructor a constructor and
a default destructor. It also has 3 friend functions.
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include<string>

class Item
{
  protected:
    //data-members
    std::string name;
    std::string desc;

  public:
    //default constructor
    Item();

    //constructor
    Item(std::string, std::string);

    //get name
    std::string getName();

    //get description
    std::string getDesc();

    //helper functions
    //overload == for Item objects
    friend bool operator==(Item, Item);

    friend bool operator==(std::string, Item);

    friend bool operator==(Item, std::string);
};

#endif
