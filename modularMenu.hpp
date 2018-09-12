/*********************************************************************
** Program name: project3 (arena)
** Author: Charles Ledbetter
** Date: 8/3/2017
** Description: The definition for a function that calls a modular
menu that displays commonly used text and returns the answer picked as
an integer. It has the option to choose which type of enumerators to
display and how many (up to 15).
*********************************************************************/
#ifndef MODULARMENU_HPP
#define MODULARMENU_HPP

#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cctype>

//enum for choosing enumerator type
enum Menu {DIGIT, ALPHACAP, ALPHALOW, ROMAN};

//enum for Roman numerals
enum Roman {I, II, III, IV, V, VI, VII, VIII, IX, X, XI, XII, XIII,
            XIV, XV};

//defaults for optional params given here
int modularMenu(int, Menu, std::string m1 = "", std::string m2 = "",
               std::string m3 = "", std::string m4 = "",
               std::string m5 = "", std::string m6 = "",
               std::string m7 = "", std::string m8 = "",
               std::string m9 = "", std::string m10 = "",
               std::string m11 = "", std::string m12 = "",
               std::string m13 = "", std::string m14 = "",
               std::string m15 = "");

#endif
