/*********************************************************************
** Program name: project3 (arena)
** Author: Charles Ledbetter
** Date: 8/3/2017
** Description: Implementation for several input validation functions.
There are two for int validation and two for double validation. In
both cases they are overloaded to either accept a min and max value
or use the min max of their data types. They return a bool for
testing purposes.
*********************************************************************/
#include "valid.hpp"

#include<string>
#include<climits>
#include<cfloat>
#include<cstdlib>

using std::string;

/*********************************************************************
** Description: Validation function for use with ints within a defined
range.
*********************************************************************/
bool intValid(string inTest, int low, int high)
{
    //for testing the inTest string
    bool validity = false;


    //if no non-digit or dash is found validity is flagged true
    //modified from code found at:
    //http://www.cplusplus.com/forum/beginner/48769/
    if(inTest.find_first_not_of( "-0123456789" ) == string::npos)
    {
      validity = true;
    }

    //if the first test was passed check for other errors
    if(validity)
    {
      //check if the number is in the correct range.
      if((atoi(inTest.c_str()) < low)
        || (atoi(inTest.c_str()) > high))
      {
        validity = false;
      }

      //if the user did not enter anything or only entered the sign.
      if((inTest == "") || (inTest == "-"))
      {
        validity = false;
      }

      //if the user entered a sign in the wrong place
      if(inTest.find_last_of( "-" ) != string::npos
        && inTest.find_last_of( "-" ) != 0)
      {
        validity = false;
      }

      //if the user entered spaces
      if(inTest.find_last_of( " " ) != string::npos)
      {
        validity = false;
      }
    }




    //make sure there are no out of place signs


    return validity;
}

/*********************************************************************
** Description: Validation function for use with ints. Sets min and
max values to MIN_INT and MAX_INT.
*********************************************************************/
bool intValid(string inTest)
{
    //for testing the inTest string
    bool validity = false;

    //if no non-digit is found validity remains true
    if(inTest.find_first_not_of( "-0123456789" ) == string::npos)
    {
      validity = true;
    }

    //if the first test was passed check if the number is in the
    //range of an int. It is converted to long long to guard
    //against int overflows.
    if(validity)
    {
      if((atoll(inTest.c_str()) <= 0)
        || (atoll(inTest.c_str()) > INT_MAX))
      {
        validity = false;
      }

      //if the user did not enter anything or only entered the sign.
      if((inTest == "") || (inTest == "-"))
      {
        validity = false;
      }

      //if the user entered a sign in the wrong place
      if(inTest.find_last_of( "-" ) != string::npos
        && inTest.find_last_of( "-" ) != 0)
      {
        validity = false;
      }

      //if the user entered spaces
      if(inTest.find_last_of( " " ) != string::npos)
      {
        validity = false;
      }
    }

    return validity;
}

/*********************************************************************
** Description: Validation function for use with doubles. For use
with min and max values.
*********************************************************************/
bool doubleValid(string inTest, double low, double high)
{
    //for testing the inTest string
    bool validity = false;


    //if no non-digit or dash is found validity is flagged true
    if(inTest.find_first_not_of( ".-0123456789" ) == string::npos)
    {
      validity = true;
    }

    //if the first test was passed check if the number is in the
    //correct range.
    /*This still needs work. If a singular dash is entered it is
    converted to a 0 and the next number is bumped over to the
    next element of the matrix.*/
    if(validity)
    {
      if((stod(inTest) < low)
        || (stod(inTest) > high))
      {
        validity = false;
      }
    }

    //if the user did not enter nums or only entered the sign or dot.
    if(validity)
    {
      if((inTest == "") || (inTest == "-") || (inTest == "."))
      {
        validity = false;
      }

      //if the user did not enter anything or only entered the sign.
      //or if they only entered a decimal point
      if((inTest == "") || (inTest == "-") || (inTest == "."))
      {
        validity = false;
      }

      //if the user entered a sign in the wrong place
      if(inTest.find_last_of( "-" ) != string::npos
        && inTest.find_last_of( "-" ) != 0)
      {
        validity = false;
      }

      //if the user entered spaces
      if(inTest.find_last_of( " " ) != string::npos)
      {
        validity = false;
      }
    }


    return validity;
}

/*********************************************************************
** Description: Validation function for use with doubles. Sets min
value to .001 and max values to DBL_MAX. Mostly for us with
monetary amounts.
*********************************************************************/
bool doubleValid(string inTest)
{
    //for testing the inTest string
    bool validity = false;

    //if no non-digit is found validity remains true
    if(inTest.find_first_not_of( ".-0123456789" ) == string::npos)
    {
      validity = true;
    }

    //if the first test was passed check if the number is in the
    //range of a double. It is converted to long double to guard
    //against double overflows.
    if(validity)
    {
      if((stold(inTest) < .001)
        || (stold(inTest) > DBL_MAX))
      {
        validity = false;
      }

      //if the user did not enter nums or only entered the sign or dot.
      if(validity)
      {
        if((inTest == "") || (inTest == "-") || (inTest == "."))
        {
          validity = false;
        }

        //if the user did not enter anything or only entered the sign.
        //or if they only entered a decimal point
        if((inTest == "") || (inTest == "-") || (inTest == "."))
        {
          validity = false;
        }

        //if the user entered a sign in the wrong place
        if(inTest.find_last_of( "-" ) != string::npos
          && inTest.find_last_of( "-" ) != 0)
        {
          validity = false;
        }

        //if the user entered spaces
        if(inTest.find_last_of( " " ) != string::npos)
        {
          validity = false;
        }
      }
    }

    return validity;
}
