#include "Shape.h"

#include <iostream>
using namespace std;

Shape::Shape()
{
  m_area = 0;
  m_perimeter = 0;
}

double Shape::GetArea()
{
  return m_area;
}

double Shape::GetPerimeter()
{
  return m_perimeter;
}
