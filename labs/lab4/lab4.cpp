#include "Student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void fillVector(vector<Student>&);
// fill vector - fills student info
// @param vector<Student>& - students in class
// Passed by reference
void printVector(vector<Student>&);
// printVector - prints the information of all students
// @param const vector<Student>& students in class
// Passed by reference

int main () {
  //Creates a new vector of Students
  vector<Student> myClass;
  //Populates the vector
  fillVector(myClass);
  //Prints the contents of the vector
  printVector(myClass);

  return 0;
}

void fillVector(vector<Student>& newMyClass) {
  //Write this function
  //Needs to ask how many students
  //Gets first name, last name, and ID of a student
  //Uses the overloaded constructor for the Student
  //Needs to add student to the vector
  int amountOfStudents, id;
  string firstName, lastName;
  cout << "How many students are in your class?" << endl;
  cin >> amountOfStudents;
  for (int j = 1; j < amountOfStudents+1; j++) {
    cout << "Student " << j << endl;
    cout << "Student First Name: " << endl;
    cin >> firstName;
    cout << "Student Last Name: " << endl;
    cin >> lastName;
    cout << "Student ID: " << endl;
    cin >> id;
    newMyClass.push_back(Student(firstName, lastName, id));
}
}
void printVector(vector<Student>& newMyClass){
  //Needs to loop through the vector of Students and outputs the information
  for(unsigned int i = 0; i < newMyClass.size(); i++) {
    cout << "Student First Name: " << newMyClass[i].GetFirstName() << endl;
    cout << "Student Last Name: " << newMyClass[i].GetLastName() << endl;
    cout << "Student ID: " << newMyClass[i].GetID() << endl;
  }
}
