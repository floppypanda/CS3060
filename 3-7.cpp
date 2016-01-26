#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double calculateWindChill(double windSpeed, double temp);

/*Test program for wind chill index calculations.*/
int main()
{
  double windSpeed = 0.0, temperature = 0.0;

  /*Prompting the user for wind speed and temperature data.*/
  cout << "Please enter the wind speed: ";
  cin >> windSpeed;
  cout << "Please enter the temperature: ";
  cin >> temperature;

  /*Delivering the results of the calculation to the user.*/
  cout << "The Wind Chill Index is " 
       << calculateWindChill(windSpeed, temperature) << endl;
}

/*Calculates wind chill based on wind speed and temperature.*/
double calculateWindChill(double windSpeed, double temp)
{
  double windChill = 0.0;

  /*The temperature must be less than 10 degrees Celcius
    and the wind speed must be non-negative.*/
  if ((temp <= 10) && (windSpeed >= 0))
  {
    /*Applying the Wind Chill Index formula.*/
    windChill = 33 - (10*sqrt(windSpeed) - windSpeed + 10.5)*(33 - temp)/23.1;
  }
  else
  {
    /*Printing an error if the bounds for temperature are violated.*/
    cerr << "Error: Wind Chill Index cannot be calculated for "
         << "temperatures less than 10 degrees Celcius." << endl;
    exit(1);
  }
  return windChill;
}
