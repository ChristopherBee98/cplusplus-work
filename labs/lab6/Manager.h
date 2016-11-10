#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <string>

class Manager : public Employee {
 public:
  Manager(string name,
          double payRate,
          bool isSalaried);

  bool GetSalaried();
  void SetSalaried(bool isSalaried);
  double Pay(double hoursWorked);

 protected:
  bool m_salaried;
};

#endif
