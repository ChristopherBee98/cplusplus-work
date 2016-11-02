#include "Shape.h"
#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle(double side1){
  m_side1 = side1;
  m_side2 = side1;
  m_side3 = side1;
}

Triangle::Triangle(double side1, double side2){
  m_side1 = side1;
  m_side2 = side2;
  m_side3 = sqrt((side1*side1)+(side2*side2));
}

Triangle::Triangle(double side1, double side2, double side3){
  m_side1 = side1;
  m_side2 = side2;
  m_side3 = side3;
}

double Triangle::GetSide3(){
  return m_side3;
}

double Triangle::GetArea(){
  return 0.5 * (m_side1 + m_side2 + m_side3);
}

double Triangle::GetPerimeter(){
  return m_side1 + m_side2 + m_side3;
}
