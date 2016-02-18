#include <iostream>
#include "point.h"

using namespace std;

int main()
{
  unsigned int xPosition = 0, yPosition = 0;
  int xTranslation = 0, yTranslation = 0;

  /*Prompting the user for the first point's data.*/
  cout << "This serves as a test program for the Point class." << endl
       << "Please enter data for the following points." << endl
       << "Point 1 - Testing Point Position Set" << endl;
  cout << "Enter x-position: ";
  cin >> xPosition;
  cout << "Enter y-position: ";
  cin >> yPosition;

  /*Testing void set(int xPosition, int yPosition)*/
  Point pointOne;
  pointOne.set(xPosition, yPosition);
  cout << "The point position has been set to (" << pointOne.getPositionX()
       << ", " << pointOne.getPositionY() << ")." << endl;

  /*Prompting the user for the second point's data.*/
  cout << "Point 2 - Testing Point Move" << endl;
  cout << "Enter x-position: ";
  cin >> xPosition;
  cout << "Enter y-position: ";
  cin >> yPosition;
  cout << "Enter x-translation: ";
  cin >> xTranslation;
  cout << "Enter y-translation: ";
  cin >> yTranslation;

  /*Testing void move(int xTranslation, int yTranslation)*/
  Point pointTwo(xPosition, yPosition);
  pointTwo.move(xTranslation, yTranslation);
  cout << "The point position is now (" << pointTwo.getPositionX() << ", "
       << pointTwo.getPositionY() << ")." << endl;

  /*Prompting the user for the third point's data.*/
  cout << "Point 3 - Testing Point 90 degree rotation" << endl;
  cout << "Enter x-position: ";
  cin >> xPosition;
  cout << "Enter y-position: ";
  cin >> yPosition;

  /*Testing void rotate90Degrees()*/
  Point pointThree(xPosition, yPosition);
  pointThree.rotate90Degrees();
  cout << "The point position is now (" << pointThree.getPositionX() << ", "
       << pointThree.getPositionY() << ")." << endl;

  cout << "All tests have completed. Thank you for cooperating!" << endl;

  return 0;
}
