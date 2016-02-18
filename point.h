#ifndef POINT_H
#define POINT_H

class Point
{
  private:
    int xPosition;
    int yPosition;
  public:
    Point();
    Point(int xPosition, int yPosition);
    void set(int xPosition, int yPosition);
    void move(int xTranslation, int yTranslation);
    void rotate90Degrees();
    int getPositionX() const;
    int getPositionY() const;
};

#endif
