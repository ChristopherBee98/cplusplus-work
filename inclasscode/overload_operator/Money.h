//Comments

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Money {
 public:
  Money();
  Money(int dollars, int cents);
  void Output(string name);
  Money operator- ( const Money &amount2);
 
 private:
  int m_dollars;
  int m_cents;
};
