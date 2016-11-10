#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape{
 public:
  Rectangle(double width, double length);
  void SetWidth(double width);
  void SetLength(double length);
  double GetLength();
  double GetWidth();
  double GetArea();
  double GetPerimeter();
 private:
  double m_length;
  double m_width;
};

#endif
