#include "Shape.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(double width, double length){
  SetWidth(width);
  SetLength(length);
}

void Rectangle::SetWidth(double width){
  if(width > 0)
    m_width = width;
  else
    m_width = 1;
}

void Rectangle::SetLength(double length){
  if(length > 0)
    m_length = length;
  else
    m_length = 1;
}

double Rectangle::GetLength(){
  return m_length;
}

double Rectangle::GetWidth(){
  return m_width;
}

double Rectangle::GetArea() {
  return m_width * m_length;
}

double Rectangle::GetPerimeter() {
  return 2 * m_width + 2 * m_length;
}
