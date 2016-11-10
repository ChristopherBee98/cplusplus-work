#include "Supervisor.h"
using namespace std;

Supervisor::Supervisor(string name, double payRate, string department)
  : Manager(name, payRate, true)
{
  m_department = department;
}

string Supervisor::GetDept()
{
  return m_department;
}

void Supervisor::SetDept(string department)
{
  m_department = department;
}

