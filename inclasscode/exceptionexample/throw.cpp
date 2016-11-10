#include <iostream>
using namespace std;

void function1();
void function2();

int main() {
  try {
    function1();
  }
  catch (int) {
    cout << "Exception occurred" << endl;
  }
  return 0;
}

void function1() {
  function2();
  cout << "function1" << endl;
}

void function2() {
  cout << "function2" << endl;
  throw int(42);
}
