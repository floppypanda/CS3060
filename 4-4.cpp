#include <iostream>
#include <cmath>

using namespace std;

void getInput(int& feet, int& inches);
void convertBritishToMetric(int feet, int inches, double& result);
void displayOutput(double meters);

int main()
{
  char decision = '\0';
  int feet;
  int inches;
  double meters;

  /*Informs the user as to the intent of our program.*/
  cout << "This program is able to convert British"
       << " units of length into metric units of length." << endl;

  do
  {
    /*Gets input from user.*/
    getInput(feet, inches);

    /*Converts feet and inches to meters and centimeters.*/
    convertBritishToMetric(feet, inches, meters);

    /*Displays output to user.*/
    displayOutput(meters);

    /*Asks the user if they would like to make another calculation.*/
    cout << "Would you like to make another calculation? (Y/N): ";
    cin >> decision;

  }
  while (decision == 'Y' || decision == 'y');
}

/*Acquires input in feet and inches from user.*/
void getInput(int& feet, int& inches)
{
  cout << "Please enter number of feet: ";
  cin >> feet;
  cout << "Please enter number of inches: ";
  cin >> inches;
 
  /*Ensuring that high values of inches are
    added to the feet count.*/
  if (inches > 12)
  {
    feet += (inches/12);
    inches = inches % 12;
  }
}

/*Converts British units to metric units.*/
void convertBritishToMetric(int feet, int inches, double& result)
{
  /*Converting to meters using the facts that there are
    0.3048 meters in a foot and 12 inches in a foot.*/
  result = (feet * 0.3048) + (inches * (1/12) * 0.3048);
}

/*Displays output to user.*/
void displayOutput(double meters)
{
  cout << "The value of the entered length in meters is: "
       << floor(meters) << " meters " << "and "
       << (int) ((meters - floor(meters)) * 100) 
       << " centimeters." << endl;
}
