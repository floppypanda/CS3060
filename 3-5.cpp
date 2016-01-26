#include <iostream>
#include <cmath>

using namespace std;

double calculateHatSize(double height, double weight);
double calculateJacketSize(double height, double weight, int age);
double calculateWaistSize(double weight, int age);

int main()
{
  char decision = 'Y';

  /*Configuring output stream for later display of decimal values.*/
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  /*Loop for processing user input multiple times in a single session.*/
  while (decision == 'Y' || decision == 'y')
  {
    double height = 0, weight = 0;
    double hatSize = 0, jacketSize = 0, waistSize = 0;
    int age = 0;

    /*Prompting the user for their height, weight, and age.*/
    cout << "How tall are you in inches?: ";
    cin >> height;
    cout << "How much do you weigh in pounds?: ";
    cin >> weight;
    cout <<"How old are you?: ";
    cin >> age;

    /*Calculating hat size, jacket size, and waist in inches.*/
    hatSize = calculateHatSize(weight, height);
    jacketSize = calculateJacketSize(height, weight, age);
    waistSize = calculateWaistSize(weight, age);

    /*Outputing user hat size, jacket size, and weight in inches.*/
    cout << "Your hat size is: " << hatSize << endl;
    cout << "Your jacket size is: " << jacketSize << endl;
    cout << "Your waist size is: " << waistSize << endl;

    /*Asking the user if they would like to make another calculation.*/
    cout << "Would you like to make another calculation? (Y/N): ";
    cin >> decision;
  }
}

/*Calculates hat size based on weight and height.*/
double calculateHatSize(double weight, double height)
{
  return (weight / height) * 2.9;
}

/*Calculates jacket size based on height, weight, and age.*/
double calculateJacketSize(double height, double weight, int age)
{
  double jacketSize = (height * weight / 288);

  /*A one-eigth inch correction is applied for every ten years
    over 30.*/
  if (age > 30)
    jacketSize += (0.125 * floor((age - 30)/10));
  return jacketSize;
}

/*Calculates waist size based on weight and age.*/
double calculateWaistSize(double weight, int age)
{
  /*A one-tenth inch correction is applied for every 2 years
    over 28.*/
  double  waistSize = (weight/5.7);
  if (age > 28) 
    waistSize += (0.1 * floor((age - 28)/2));
  return waistSize;
}
