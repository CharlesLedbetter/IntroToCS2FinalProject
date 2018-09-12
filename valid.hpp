/*********************************************************************
** Program name: project3 (arena)
** Author: Charles Ledbetter
** Date: 8/3/2017
** Description: Definition for several input validation functions.
There are two for int validation and two for double validation. In
both cases they are overloaded to either accept a min and max value
or use the min max of their data types. They return a bool for
testing purposes.
*********************************************************************/
#ifndef VALID_HPP
#define VALID_HPP

#include<string>

//for use with min and max values
bool intValid(std::string, int, int);

//sets min and max values to MIN_INT and MAX_INT
bool intValid(std::string);

//for use with min and max values
bool doubleValid(std::string, double, double);

//sets min and max values to MIN_INT and MAX_INT
bool doubleValid(std::string);

#endif
