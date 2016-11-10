#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
 public:
  Shape();
  double GetArea();
  double GetPerimeter();
 private:
  double m_area;
  double m_perimeter;
};

#endif
