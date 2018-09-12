/*********************************************************************
** Program name: project3 (arena)
** Author: Charles Ledbetter
** Date: 8/3/2017
** Description: The overload comparisons for the Item class.
*********************************************************************/
#ifndef OVERLOADCOMPARISONS_HPP
#define OVERLOADCOMPARISONS_HPP

#include "item.hpp"

//
bool operator==(Item, Item);

//
bool operator==(std::string, Item);

//
bool operator==(Item, std::string);

#endif
