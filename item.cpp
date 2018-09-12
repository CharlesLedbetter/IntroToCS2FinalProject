/*********************************************************************
** Program name: final project (textGame)
** Authors: Charles Ledbetter
** Date: 8/13/2017
** Description: Implementation of a class that has two data members and
two get methods. It also has a default constructor a constructor and
a default destructor. It also has 3 friend functions.
*********************************************************************/
#include<string>

#include "item.hpp"

////public////
/*********************************************************************
** Description: default constructor used by Game object before actual
initialization.
*********************************************************************/
Item::Item()
{
  name = "nameIn";
  desc = "descIn";
}

/*********************************************************************
** Description: constructor used to initialize Item objects in Game
*********************************************************************/
Item::Item(std::string nameIn, std::string descIn)
{
  name = nameIn;
  desc = descIn;
}

/*********************************************************************
** Description: get method for name
*********************************************************************/
std::string Item::getName()
{
  return name;
}

//get description
/*********************************************************************
** Description: get method for desc
*********************************************************************/
std::string Item::getDesc()
{
  return desc;
}
