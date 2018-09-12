/*********************************************************************
** Program name: project3 (arena)
** Author: Charles Ledbetter
** Date: 8/3/2017
** Description: A function that calls a modular menu that displays
commonly used text and returns the answer chosen as an integer. It has
the option to choose which type of enumerators to display and how many
(up to 15).
*********************************************************************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cctype>

#include "modularMenu.hpp"
#include "valid.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::string;

//enums Menu and Roman defined in modularMenu.hpp

//all string params default to "". This is defined in modularMenu.hpp
int modularMenu(int size, Menu enumType, string m1, string m2,
                string m3, string m4, string m5, string m6, string m7,
                string m8, string m9, string m10, string m11,
                string m12, string m13, string m14, string m15)
  {
    //what is returned. the users valid choice
    int choice = 0;

    //the sting version of choice used for validation
    string strChoice = "";

    //for testing valid input and looping until it is entered
    bool validChoice = false;

    //array to hold choices for for loops
    string options[15] = {m1, m2, m3, m4, m5, m6, m7, m8 ,m9 ,m10,
                         m11, m12, m13, m14, m15};

    do {
      //display the first menu
      cout << "Please select one of the options below.\n";

      if(enumType == DIGIT)
      {
        //explain how to choose
        cout << "(Enter the number only.)\n";

        //display choices laid out by program in digits
        for(int i = 0; i < size; ++i)
        {
          cout << (i + 1) << ") " << options[i] << "\n";
        }
      }
      else if(enumType == ALPHACAP)
      {
        //explain how to choose
        cout << "(Enter the letter only.)\n";

        //display choices laid out by program in upper case letters
        for(int i = 0; i < size; ++i)
        {
          cout << static_cast<char>(65 + i) << ") " << options[i] << "\n";
        }
      }
      else if(enumType == ALPHALOW)
      {
        //explain how to choose
        cout << "(Enter the letter only.)\n";

        //display choices laid out by program in lower case letters
        for(int i = 0; i < size; ++i)
        {
          cout << static_cast<char>(97 + i) << ") " << options[i]
               << "\n";
        }
      }
      else if(enumType == ROMAN)
      {
        //explain how to choose
        cout << "(Enter the numeral only.)\n";

        //display choices laid out by program in roman numerals
        for(int i = 0; i < size; ++i)
        {
          cout << static_cast<Roman>(i) << ") " << options[i] << "\n";
        }
      }

      //get user data sandwiched in blank lines
      cout << "\n";
      getline(cin, strChoice);
      cout << endl;

      //convert choice for return statement
      if((enumType == DIGIT || enumType == ROMAN)
        && intValid(strChoice, 1, size))
      {
        choice = atoi(strChoice.c_str());
        validChoice = true;
      }
      // not working yet / not needed for this program
      // else if((enumType == ALPHACAP || enumType == ALPHALOW)
      //        && charValid(strChoice, false, 'a',
      //                     static_cast<char>(96 + size)))
      // {
      //   //this converts upper to lower by taking first cahr of string
      //   /- needs work if first char of string is space then wrong
      //   value is returned -/
      //   choice = std::tolower(strChoice.c_str()[0]) - 96;
      // }
      else
      {
        cout << "That is not an option. Please try again.\n" << endl;
      }
    } while(!validChoice);

    return choice;
  }
