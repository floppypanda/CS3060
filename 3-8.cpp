#include <iostream>
#include <string> 
using namespace std;

/*Tables used to convert numbers to their English names.*/
const char * ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six",
                     "Seven", "Eight", "Nine"};
const char * tens[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                     "Seventy", "Eighty", "Ninety"};
const char * teens[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
                      "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

/*Repeated sentence fragments from song lyrics.*/
const char bottlesOnTheWall[] = " bottles of beer on the wall";
const char bottleOnTheWall[] = " bottle of beer on the wall,";
const char bottlesOfBeer[] = " bottles of beer";
const char bottleOfBeer[] = " bottle of beer,";
const char takeOneDown[] = "Take one down, pass it around";

string convertNumToName(unsigned int num);

/*Prints out the 99 bottles of beer on the wall song lyrics.*/
int main()
{
  unsigned int numBottles = 99;
  for (; numBottles > 1; --numBottles)
  {
    string numberName = convertNumToName(numBottles);
    cout << numberName << bottlesOnTheWall << ",\n" << numberName 
         << bottlesOfBeer << ",\n" << takeOneDown << ",\n";
  }

  /*Printing the "One" and "Zero" cases separately as the "One" case differs.*/
  cout << ones[numBottles] << bottleOnTheWall << endl;
  cout << ones[numBottles--] << bottleOfBeer << endl;
  cout << ones[numBottles] << bottlesOnTheWall << "." << endl;
}

/*Converts a number to its English name.*/
string convertNumToName(unsigned int num)
{
  string numberName;
  
  int onesPlaceDigit = num % 10;  
  int tensPlaceDigit = (num - onesPlaceDigit)/10;
 
  /*Handling numbers in the teens.*/
  if ((tensPlaceDigit == 1) && (onesPlaceDigit != 0))
  {
    numberName.append(teens[onesPlaceDigit - 1]);
  }
  /*Handling single digit numbers.*/
  else if (tensPlaceDigit == 0)
  {
    numberName.append(ones[onesPlaceDigit]);
  }
  /*All other numbers have two digits and/or are multiples of ten.*/
  else
  {
    /*Multiples of ten are identified by the ones place digit.*/
    if (onesPlaceDigit == 0)
    {
      numberName.append(tens[tensPlaceDigit - 1]);
    }
    /*All other numbers are a combination of the tens and ones place.*/
    else
    {
      numberName.append(tens[tensPlaceDigit - 1]);
      numberName.append("-");
      numberName.append(ones[onesPlaceDigit]);
    }
  }

  return numberName;
}
