#include "point.h"

Point::Point()
{
  xPosition = 0;
  yPosition = 0;
}

Point::Point(int xPosition, int yPosition)
{
  this->xPosition = xPosition;
  this->yPosition = yPosition;
}

void Point::set(int xPosition, int yPosition)
{
  this->xPosition = xPosition;
  this->yPosition = yPosition;
}

void Point::move(int xTranslation, int yTranslation)
{
  xPosition += xTranslation;
  yPosition += yTranslation;
}

void Point::rotate90Degrees()
{
  int tmp = xPosition;
  xPosition = yPosition;
  yPosition = tmp*(-1);
}

int Point::getPositionX() const
{
  return xPosition;
}

int Point::getPositionY() const
{
  return yPosition;
}
