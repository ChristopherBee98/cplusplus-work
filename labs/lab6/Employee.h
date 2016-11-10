#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
 public:
  Employee(string name, double payRate);

  string GetName();
  double GetPayRate();
  void SetName(string name);
  void SetPayRate(double payRate);
  double Pay(double hoursWorked);

 protected:
  string m_name;
  double m_payRate;
};

#endif
