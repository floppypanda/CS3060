#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#include "counter.h"

using namespace std;

void checkOverflow(Counter counter);

/*Application entry point.*/
int main()
{
  unsigned int counterLimit = 0;
  char decision = '\0';
  int  digit = 1;

  /*Describing program usage to user.*/
  cout << "Counter Simulation" << endl 
       << "This program serves as a simulation of a grocery "
       << "store counter. The number of cents, dimes, dollars "
       << "and tens of dollars may be incremented by entering "
       << "a for cents, followed by a digit 1 to 9; s for dimes, "
       << "followed by a digit 1 to 9; d for dollars, followed by "
       << "a digit 1 to 9; and f for tens of dollars, again followed "
       << "by a digit 1 to 9. The overflow status may be requested " 
       << "by entering o. Enter r to reset counter and q to quit the "
       << "simulation." <<endl;

  /*Querying for counter limit.*/
  cout << "Please enter the counter limit: ";
  cin >> counterLimit;

  /*Creating a counter object with the appropriate limit.*/
  Counter counter(counterLimit);

  /*Loop in which the user may increment the counter to their hearts
    content.*/
  do
  {
    cout << "Counter Value: " << counter.getCounter() << endl;
    cout << "Enter simulation command: ";
    cin >> decision;
    
    if ((decision != 'q') && (decision != 'o') && (decision != 'r'))
    {
      cin >> digit;
    }

    if ((digit > 0) && (digit < 10))
    {
      switch (decision)
      {
        case 'a':
          for (int i = 0; i < digit; ++i)
          {
            counter.incr1();
          }
          checkOverflow(counter);
          break;
        case 's':
          for (int j = 0; j < digit; ++j)
          {
            counter.incr10();
          }
          checkOverflow(counter);
          break;
        case 'd':
          for (int k = 0; k < digit; ++k)
          {
            counter.incr100();
          }
          checkOverflow(counter);
          break;
        case 'f':
          for (int l = 0; l < digit; ++l)
          {
            counter.incr1000();
          }
          checkOverflow(counter);
          break;
        case 'o':
          cout << "The current overflow status is: ";
          if (counter.overflow())
          {
            cout << "True";
          }
          else
          {
            cout << "False";
          }
          cout << endl;
          break;
        case 'r':
          counter.reset();
          break;
        case 'q':
          cout << "Simulation terminated." << endl;
          return 0;
        default:
          cout << "Invalid simulation command. Please try again." << endl;       
      }
    }
    else
    {
      cout << "Error: The entered digit must be between 1 and 9." << endl;
      continue;
    }
  }
  while (true);
}

/*Prints overflow message if necessary.*/
void checkOverflow(Counter counter)
{
 if (counter.overflow())
 {
  cout << "Counter overflow occured." << endl;
 }
}
