#include <iostream>
#include <cmath>

using namespace std;

void getBritishLengthInput(int& feet, int& inches);
void getMetricLengthInput(double& meters);
void convertBritishToMetric(int feet, int inches, double& result);
void convertMetricToBritish(double meters, int& feet, int& inches);
void displayBritishLengthOutput(int feet, int inches);
void displayMetricLengthOutput(double metersResult);
void britishToMetric();
void metricToBritish();

int main()
{
  char continuationDecision = '\0';
  char conversionDecision = '\0';

  /*Informs the user as to the intent of our program.*/
  cout << "This program is able to convert British units of length"
       << "into Metric units of length and vice versa." << endl;

  do
  {
    cout << "Would you like to convert from British to Metric"
         << " or from Metric to British?" << endl
         << "(1: British to Metric) | (2: Metric to British) -> ";
    cin >> conversionDecision;

    if (conversionDecision == '1')
    {
      britishToMetric();
    }
    else if (conversionDecision == '2')
    {
      metricToBritish();
    }
    else
    {
      continue;
    }

    cout << "Would you like to make another calculation? (Y/N): ";
    cin >> continuationDecision;
  }
  while (continuationDecision == 'Y' || continuationDecision == 'y');
}

/*Conducts the Britsh to Metric conversion sequence.*/
void britishToMetric()
{
  int feet, inches;
  double meters;

  /*Gets input from user.*/
  getBritishLengthInput(feet, inches);

  /*Converts feet and inches to meters and centimeters.*/
  convertBritishToMetric(feet, inches, meters);

  /**Displays output to user.*/
  displayMetricLengthOutput(meters);
}

/*Conducts the Metric to British conversion sequence.*/
void metricToBritish()
{
  int feet, inches;
  double meters;

  /*Gets input from user.*/
  getMetricLengthInput(meters);

  /*Converts meters to feet and inches.*/
  convertMetricToBritish(meters, feet, inches);

  /*Displays output to user.*/
  displayBritishLengthOutput(feet, inches);
}

/*Acquires input in feet and inches from user.*/
void getBritishLengthInput(int& feet, int& inches)
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

/*Acquires input in meters and centimeters from user.*/
void getMetricLengthInput(double& metersResult)
{
  int meters, centimeters;
  cout << "Please enter number of meters: ";
  cin >> meters;
  cout << "Please enter number of centimeters: ";
  cin >> centimeters;
  metersResult = (meters + (centimeters/100));
}

/*Converts British units to metric units.*/
void convertBritishToMetric(int feet, int inches, double& result)
{
  /*Converting to meters using the facts that there are
    0.3048 meters in a foot and 12 inches in a foot.*/
    result = (feet * 0.3048) + (inches * (1/12) * 0.3048);
}

/*Converts metric units to British units.*/
void convertMetricToBritish(double meters, int& feet, int& inches)
{
  /*Converting to British units using the facts that there
    are 3.281 feet in a meter and 3.372 inches in 0.281 feet.*/
    double decimalFeet = (meters * 3.281);
    feet = floor(decimalFeet);
    inches = ceil((decimalFeet - floor(decimalFeet)) * 3.372);
}

/*Displays British length output to user.*/
void displayBritishLengthOutput(int feet, int inches)
{
  cout << "The value of the entered length in British units is: "
       << feet << " feet and " << inches << " inches." << endl;
}

/*Displays metric length output to user.*/
void displayMetricLengthOutput(double metersResult)
{
  cout << "The value of the entered length in meters is: "
       << floor(metersResult) << " meters " << "and "
       << (int) ((metersResult - floor(metersResult)) * 100)
       << " centimeters." << endl;
}
