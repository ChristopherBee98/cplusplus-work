//Comments

#include <iostream>
#include <string>
using namespace std;

template <class T>
T maxx(const T& a, const T& b) {
  return (a > b) ? a : b;
}

//new template declaration for each function
//each declaration name (i.e. T) is seperate
template <class T>
T minn(const T& a, const T& b) {
  return (a > b) ? b : a;
}

int main() {
  int a1 = 10;
  int b1 = 20;
  char a2 = 'a';
  char b2 = 'b';
  float a3 = 3.3;
  float b3 = 4.4;
  string a4 = "barney";
  string b4 = "bar";
  double a5 = 3.3;
  float b5 = 4.4;
  cout << a1 << " " << b1 << ": " << maxx(a1, b1) << " " << minn(a1, b1) << endl;
  cout << a2 << " " << b2 << ": " << maxx(a2, b2) << " " << minn(a2, b2) << endl;
  cout << a3 << " " << b3 << ": " << maxx(a3, b3) << " " << minn(a3, b3) << endl;
  cout << a4 << " " << b4 << ": " << maxx(a4, b4) << " " << minn(a4, b4) << endl;
  cout << a5 << static_cast<double>(b5) << ": " << maxx(a5, static_cast<double>(b5)) << " " << minn(a5, static_cast<double>(b5)) << endl;
  return 0;
}
