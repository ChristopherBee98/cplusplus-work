//Comments

#include <iostream>
#include <cmath>
using namespace std;

class Polygon {
protected:
  double m_width;
  double m_height;
public:
  virtual double CalcPerimeter() = 0;
  virtual double CalcArea() = 0;
  void SetValues(double newWidth, double newHeight) {
    m_width = newWidth;
    m_height = newHeight;
  }
};


class Rectangle: public Polygon {
public:
  //Virtual isn't necessary here; only in base class
  virtual double CalcPerimeter() {
    return (2*m_width) + (2*m_height);
  }
  //Virtual isn't necessary here; only in base class
  virtual double CalcArea() {
    return (m_width*m_height);
  }
};

class Triangle: public Polygon {
public:
  //Virtual isn't necessary here; only in base class
  virtual double CalcPerimeter() {
    double per1 = 0;
    per1 = (m_height*m_height) + (m_width*m_width);
    return sqrt(per1) + m_height + m_width;
  }
  //Virtual isn't necessary here; only in base class
  virtual double CalcArea() {
    return (m_width*m_height / 2);
  }
};

int main() {
  Rectangle rect;
  Triangle tri;
  //Polygon poly;
  Polygon *ppoly1 = &rect;
  Polygon *ppoly2 = &tri;
  //Polygon *ppoly3 = &poly;
  ppoly1->SetValues(3, 5);
  ppoly2->SetValues(4, 5);
  //ppoly3->SetValues(10, 5);
  cout << "Area Calculations" << endl;
  cout << "Rectangle: " << ppoly1->CalcArea() << endl;
  cout << "Triangle: " << ppoly2->CalcArea() << endl;
  //cout << "Polygon: " << ppoly3->CalcArea() << endl;
  cout << "Perimeter Calculations" << endl;
  cout << "Rectangle: " << ppoly1->CalcPerimeter() << endl;
  cout << "Triangle: " << ppoly2->CalcPerimeter() << endl;
  //cout << "Polygon: " << ppoly3->CalcPerimeter() << endl;
  return 0;
}
