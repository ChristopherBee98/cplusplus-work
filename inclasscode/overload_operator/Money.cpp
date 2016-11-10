//Comments
#include "Money.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Money::Money() {
}

Money::Money(int dollars, int cents) {
  m_dollars = dollars;
  m_cents = cents;
}

void Money::Output(string name){
  cout << name << " is $" << m_dollars << "." << m_cents << endl;
}

Money Money::operator- ( const Money &amount2) {
  int dollarsRet;
  int centsRet;
  //Money1 - Money2
  if (m_cents <= amount2.m_cents) {
    dollarsRet = m_dollars - amount2.m_dollars - 1;
    centsRet = 100 + (m_cents - amount2.m_cents);
  }
  else {
    centsRet = m_cents - amount2.m_cents;
    dollarsRet = m_dollars - amount2.m_dollars;
  }
  return Money(dollarsRet, centsRet);
}
