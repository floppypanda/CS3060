#include "point.h"

/*Default constructor*/
Point::Point()
{
  xPosition = 0;
  yPosition = 0;
}

/*Constructor which specifies point position.*/
Point::Point(int xPosition, int yPosition)
{
  this->xPosition = xPosition;
  this->yPosition = yPosition;
}

/*Sets the position of a point.*/
void Point::set(int xPosition, int yPosition)
{
  this->xPosition = xPosition;
  this->yPosition = yPosition;
}

/*Translates the point horizontally and/or vertically.*/
void Point::move(int xTranslation, int yTranslation)
{
  xPosition += xTranslation;
  yPosition += yTranslation;
}

/*Rotates the point 90 degrees.*/
void Point::rotate90Degrees()
{
  int tmp = xPosition;
  xPosition = yPosition;
  yPosition = tmp*(-1);
}

/*Gets the x-position of the point.*/
int Point::getPositionX() const
{
  return xPosition;
}

/*Gets the y-position of the point.*/
int Point::getPositionY() const
{
  return yPosition;
}
