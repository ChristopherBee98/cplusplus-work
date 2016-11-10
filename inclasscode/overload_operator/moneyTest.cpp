//Comments
#include "Money.h"
#include <iostream>
#include <string>
using namespace std;

int main () {

  Money cash(700, 65);
  Money bills(99, 85);
  cout << "Before paying our bills: " << endl;
  cash.Output("Cash");
  bills.Output("Bills");
  
  cash = cash - bills;
  cout << "After paying the bills from cash: " << endl;
  cash.Output("Cash");
  
  return 0;
}
