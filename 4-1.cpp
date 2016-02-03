#include <iostream>

using namespace std;


/*Defining a structure in which
  time data is stored.*/
typedef struct
{
  int hours;
  int minutes;
  char timeOfDay;
} Time;

Time * getInput();
bool validHours(int hours);
bool validMinutes(int minutes);
void convertTime(Time& time);
void displayOutput(Time& time);

int main()
{
  char decision = '\0';
  Time * militaryTime = NULL;

  /*Introducing the program to the user.*/
  cout << "This program is capable of converting 24-hour"
          "time to 12-hour time." << endl;

  do 
  {
  
  /*Acquiring 24-hour time from the user.*/
  militaryTime = getInput();

  /*Converting military time to 12-hour time.*/
  convertTime(*militaryTime);

  /*Displaying output to user.*/
  displayOutput(*militaryTime);
 
  cout << "Would you like to convert another time value? (Y/N): ";
  cin >> decision;
  
  }
  while (decision == 'Y' || decision == 'y');

  /*Cleaning up allocated memory.*/
  delete militaryTime;
}

/*Retrieves military time data from user.*/
Time * getInput()
{
  Time * inputTime = new Time;
 
 /*Gathering hours from user.*/
  do
  {
    cout << "Please enter hours: ";
    cin >> inputTime->hours;

    /*Checking validity of hours.*/
    if (!validHours(inputTime->hours))
    {
      cout << "Invalid hours. Please try again." << endl;
      continue;
    }
    else
    {
      break;
    }
  }
  while (true);

  /*Gathering minutes from user.*/
  do
  {
    cout << "Please enter minutes: ";
    cin >> inputTime->minutes;

    /*Checking validity of minutes.*/
    if (!validMinutes(inputTime->minutes))
    {
      cout << "Invalid minutes. Please try again." << endl;
      continue;
    }
    else
    {
      break;
    }
  }
  while (true);

  return inputTime;
}

/*Ensures that the given hours value is valid.*/
bool validHours(int hours)
{
  return ((hours >= 0) && (hours <= 23)) ? true : false;
}

/*Ensures that the given minutes value is valid.*/
bool validMinutes(int minutes)
{
  return ((minutes >= 0) && (minutes <= 59)) ? true : false;
}

/*Converts 24-hour time to 12-hour time.*/
void convertTime(Time& time)
{
  /*We simply need to subtract 12 hours from
    hour values between 13 and 23.*/
  if (time.hours > 12)
  {
    time.timeOfDay = 'P'; //Setting time of day to PM.
    time.hours -= 12;
  }
  else
  {
    time.timeOfDay = 'A'; //Setting time of day to AM.
  }
}

/*Displays time value to user.*/
void displayOutput(Time& time)
{
  cout << "The converted time is "
       << time.hours << ":" << time.minutes << " ";
  cout << ((time.timeOfDay == 'A') ? "A.M." : "P.M.") << endl;
}
