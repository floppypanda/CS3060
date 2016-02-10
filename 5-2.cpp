#include <iostream>
#include <cstdint>
#include <string.h>

using namespace std;

/*Creating a structure to keep track of 
  which characters have been found in a 
  character array.*/
typedef struct AlphabetBitField
{
  /*One bit for each lowercase character
    and 6 bits as throwaway or extra flag storage.*/
  uint32_t bitfield;

} AlphabetBitField;

void deleteRepeats(char array[], int& size);
void printArray(char array[], int size);

int main()
{
  /*Testing deleteRepeats on a sample array.*/
  char testArray[256];
  int testArraySize = 0;

  cout << "Please enter a character array for deduplication: ";
  cin >> testArray;

  testArraySize = strlen(testArray);

  /*Deduplicating array.*/
  deleteRepeats(testArray, testArraySize);

  /*Printing array after deduplication.*/
  cout << "Array after deduplication: ";
  printArray(testArray, testArraySize);
}

/*Prints a character array.*/
void printArray(char array[], int size)
{
  for (int index = 0; index < size; ++index)
  {
    cout << array[index];
  }
  cout << endl;
}

/*Deletes repeated characters from a character array.*/
void deleteRepeats(char array[], int& size)
{
  /*Keeps track of which characters exist in the string.*/
  AlphabetBitField tracker;
  memset(&tracker, 0, sizeof(tracker));

  /*Loops through characters and removes repeats.*/
  for (int index = 0; index < size; ++index)
  {
    /*This assumes all characters are alphabetic lowercase.*/
    uint32_t bitPosition = (uint32_t) (array[index] - 'a');

    if ((tracker.bitfield & (1 << bitPosition)) == 0)
    {
      /*Shifting the 1 to the appropriate bit position
       and then using a logical or to flip the tracker bit.*/
      tracker.bitfield |= (1 << bitPosition);
    }
    else
    {
      /*If the tracker bit is set, we must remove the character
        and shift any characters following it towards the front.*/
      
      array[index] = '\0';

      for (int swapPosition = index; swapPosition + 1 < size; ++swapPosition)
      {
	int tmp = array[swapPosition];
        array[swapPosition] = array[swapPosition + 1];
	array[swapPosition + 1] = tmp;
      }

      /*Once the element has been removed we decrease the array
        size by one.*/
        --size;

      /*We then need to return the index location of the
        element which has been shifted..*/
      --index;
    }
  }
}
