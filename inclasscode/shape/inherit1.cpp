#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

#include <iostream>
using namespace std;

int main () {
  Rectangle rect1(10, 5);
  Triangle tri1(5);
  Triangle tri2(3, 4);
  Triangle tri3(3, 4, 5);

  cout << "Rectangle 1's area: " << rect1.GetArea() << endl;
  cout << "Rectangle 1's perimeter: " << rect1.GetPerimeter() << endl;
  cout << "Triangle 1's area: " << tri1.GetArea() << endl;
  cout << "Triangle 1's perimeter: " << tri1.GetPerimeter() << endl;
  cout << "Triangle 2's area: " << tri2.GetArea() << endl;
  cout << "Triangle 2's perimeter: " << tri2.GetPerimeter() << endl;
  cout << "Triangle 3's area: " << tri3.GetArea() << endl;
  cout << "Triangle 3's perimeter: " << tri3.GetPerimeter() << endl;
  return 0;
}
