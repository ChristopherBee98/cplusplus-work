#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape{
 public:
  Triangle(double side1);
  Triangle(double side1, double side2);
  Triangle(double side1, double side2, double side3);
  double GetSide3();
 private:
  double m_side1;
  double m_side2;
  double m_side3;
};

#endif
