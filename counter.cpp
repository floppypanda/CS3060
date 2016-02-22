#include "counter.h"

Counter::Counter()
{
  count = 0;
  limit = DEFAULT_LIMIT;
  overflown = false;
}

Counter::Counter(unsigned int limit)
{
  count = 0;
  this->limit = limit;
  overflown = false;
}

/*Resets the counter to zero.*/
void Counter::reset()
{
  count = 0;  
  overflown = false;
}

/*Increments the one's place digit.*/
void Counter::incr1()
{
  if ((count + 1) < limit + 1)
  {
    ++count;
  }
  else
  {
    overflown = true;
  }
}

/*Increments the ten's place digit.*/
void Counter::incr10()
{
  if ((count + 10) < limit + 1)
  {
    count += 10;
  }
  else
  {
    count = limit;
    overflown = true;
  }
}

/*Increments the one-hundred's place digit.*/
void Counter::incr100()
{
  if ((count + 100) < limit + 1)
  {
    count += 100;
  }
  else
  {
    count = limit;
    overflown = true;
  }
}

/*Increments the thousand's place digit.*/
void Counter::incr1000()
{
  if ((count + 1000) < limit + 1)
  {
    count += 1000;
  }
  else
  {
    count = limit;
    overflown = true;
  }
}

/*Returns a value indicating counter overflow.*/
bool Counter::overflow() const
{
  return overflown;
}

unsigned int Counter::getCounter() const
{
  return count; 
}

