#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Manager.h"
#include <string>

class Supervisor : public Manager {
 public:
  //Constructors
  Supervisor(string name, double payRate, string department);
  //Accessors
  string GetDept();
  //Mutators
  void SetDept(string department);
 private:
  string m_department;
};


#endif
