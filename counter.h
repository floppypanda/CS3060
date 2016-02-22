#ifndef COUNTER_H
#define COUNTER_H

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#define DEFAULT_LIMIT 9999

/*Simulates the behavior of a 
  grocery store counter.*/
class Counter
{
private:
  unsigned int count; //The current counter value.
  unsigned int limit; //The counter limit.
  bool overflown;     //Indicates the occurence of an overflow.
public:
  Counter();                        //Default construtor.
  Counter(unsigned int limit);      //Constructor which specifies limit.
  void reset();                     //Resets the counter.
  void incr1();                     //Increments the one's place digit.
  void incr10();                    //Increments the ten's place digit.
  void incr100();                   //Increments the hundred's place digit.
  void incr1000();                  //Increments the thousand's place digit.
  bool overflow() const;            //Returns the counter's overflow state.
  unsigned int getCounter() const;  //Prints counter value to terminal.
};

#endif
