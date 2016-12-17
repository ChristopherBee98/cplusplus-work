//Comments

#include <iostream>
using namespace std;

int fibonacci(int number);

int main() {
  //13 is just some random number for testing
  for (int count = 0; count < 13; count++)
    cout << fibonacci(count) << endl;
  return 0;
}

int fibonacci(int number) {
  //base case
  if (number == 0)
    return 0;
  if (number == 1)
    return 1;
  
  //recursive case
  
  return fibonacci(number - 1) + fibonacci(number - 2);
}
