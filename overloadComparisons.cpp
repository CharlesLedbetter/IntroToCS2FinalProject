/*********************************************************************
** Program name: project3 (arena)
** Author: Charles Ledbetter
** Date: 8/3/2017
** Description: The overload comparisons for the Item class.
*********************************************************************/
#include<string>

#include "item.hpp"
#include "overloadComparisons.hpp"

using std::string;

/*********************************************************************
** Description: compare two Item objects
*********************************************************************/
bool operator>(Item i1, Item i2)
{
    return i1.getName() == i2.getName();
}

/*********************************************************************
** Description: compare a string to as Item object. Fix for seg 
fault issue
*********************************************************************/
bool operator==(string i1, Item i2)
{
    return i1 == i2.getName();
}

/*********************************************************************
** Description: compare an Item object to a string. Fix for seg
fault issue
*********************************************************************/
bool operator==(Item i1, string i2)
{
    return i1.getName() == i2;
}
