#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

static int NUM_DIGITS = 20;

void convertNumberString(char charArray[], int * intArray);
void addArrayIntegers(int addendOne[], int addendTwo[], int * sum);

int main()
{
  char firstNumber[NUM_DIGITS], secondNumber[NUM_DIGITS];
  char characterSum[NUM_DIGITS];

  int convertedFirstNumber[NUM_DIGITS], convertedSecondNumber[NUM_DIGITS];
  int integerSum[NUM_DIGITS];

  char continuationDecision = '\0';

  cout << "This program adds digits of length twenty or less." << endl;

  do
  {
    /*We must clear out this memory so as not to affect further calculations.*/
    memset(firstNumber, 0, sizeof(char) * NUM_DIGITS);
    memset(secondNumber, 0, sizeof(char) * NUM_DIGITS);
    memset(characterSum, 0, sizeof(char) * NUM_DIGITS);
    memset(convertedFirstNumber, 0, sizeof(int) * NUM_DIGITS);
    memset(convertedSecondNumber, 0, sizeof(int) * NUM_DIGITS);
    memset(integerSum, 0, sizeof(int) * NUM_DIGITS);

    /*Prompting user to enter addends.*/
    cout << "Please enter the first number: ";
    cin >> firstNumber;
    cout << "Please enter the second number: ";
    cin >> secondNumber;

    /*Converting number strings to integer arrays.*/
    convertNumberString(firstNumber, convertedFirstNumber);
    convertNumberString(secondNumber, convertedSecondNumber);

    /*Carrying out the addition.*/
    addArrayIntegers(convertedFirstNumber, convertedSecondNumber, integerSum);

    /*Displaying the result.*/
    bool leadingZero = true;
    cout << "The result is: ";
    for (int index = NUM_DIGITS - 1; index >= 0; --index)
    {
      if (leadingZero && (integerSum[index] != 0))
      {
        leadingZero = false;
      }

      if (!leadingZero)
      {
        cout << integerSum[index];
      }
    }
    cout << endl;

    cout << "Would you like to make another calculation (Y/N)?: ";
    cin >> continuationDecision;
  }
  while (continuationDecision == 'Y' || continuationDecision == 'y');
}

/*Converts a digit represented as a string to an integer array.*/
void convertNumberString(char charArray[], int * intArray)
{
  bool leadingZero = true;
  int intArrayIndex = 0;

  /*Looping through characters and converting them to integers.*/
  for (int index = NUM_DIGITS - 1; index >= 0; --index)
  {
    switch (charArray[index])
    {
      case '0':
        /*We must ignore leading zeros.*/
        if (!leadingZero)
        {
          intArray[intArrayIndex] = 0;
        }
        break;
      case '1':
        intArray[intArrayIndex] = 1;
        leadingZero = false;
        break;
      case '2':
        intArray[intArrayIndex] = 2;
        leadingZero = false;
        break;
      case '3':
        intArray[intArrayIndex] = 3;
        leadingZero = false;
        break;
      case '4':
        intArray[intArrayIndex] = 4;
        leadingZero = false;
        break;
      case '5':
        intArray[intArrayIndex] = 5;
        leadingZero = false;
        break;
      case '6':
        intArray[intArrayIndex] = 6;
        leadingZero = false;
        break;
      case '7':
        intArray[intArrayIndex] = 7;
        leadingZero = false;
        break;
      case '8':
        intArray[intArrayIndex] = 8;
        leadingZero = false;
        break;
      case '9':
        intArray[intArrayIndex] = 9;
        leadingZero = false;
        break;
    }

    if (!leadingZero)
    {
      ++intArrayIndex;
    }

  }
}

/*Adds two very large numbers represented as an integer array.*/
void addArrayIntegers(int addendOne[], int addendTwo[], int * sum)
{
  int carry = 0;
  int microSum = 0;

  /*Paper and Pencil Algorithm*/
  for (int index = 0; index < NUM_DIGITS; ++index)
  {
    /*Adding numbers in one column.*/
    microSum = addendOne[index] + addendTwo[index];

    /*Adding the carry from a previous step.*/
    microSum += carry;
    
    /*Setting the used carry to zero.*/
    carry = 0;

    /*Setting the appropriate digit of the sum.*/
    sum[index] = (microSum % 10); 

    /*Setting the carry value if needed.*/
    if (microSum >= 10)
      carry = 1;
    
    /*Determining if an overflow has occured using
      the carry value.*/
    if ((index == NUM_DIGITS - 1) && carry == 1)
      cerr << "An integer overflow has occured." << endl;
  }
}
