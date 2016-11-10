#include "Employee.h"

Employee::Employee(string name, double payRate)
{
  m_name = name;
  m_payRate = payRate;
}

string Employee::GetName()
{
  return m_name;
}

double Employee::GetPayRate()
{
  return m_payRate;
}

void Employee::SetName(string name)
{
  m_name = name;
}

void Employee::SetPayRate(double payRate)
{
  m_payRate = payRate;
}

double Employee::Pay(double hoursWorked)
{
  return hoursWorked * m_payRate;
}
