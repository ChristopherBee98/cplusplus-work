/*
File:    LinkedList.cpp
Project: CMSC 202 Project 3, Fall 2016
Author:  Austin Bailey
Date:    10/30/16
Section: 101
E-mail:  baustin1@umbc.edu

This file is used to create LinkedList objects, or nodes. It
takes in parameters/data and uses it to create nodes in a
LinkedList. It can be sorted, decrypted, and destroyed.
*/

#include "LinkedList.h"

//name: LinkedList (default constructor)
//pre: None
//post: new linked list where m_head points to NULL
LinkedList::LinkedList() {
  m_head = NULL;
}

//name: LinkedList (destructor)
//pre: There is an existing linked list
//post: A linked list is deallocated (including nodes) to have no memory leaks!
LinkedList::~LinkedList() {
  //destructor calls the clear function to clear out the list when done
  LinkedList::Clear();
}

//name: CreateNode
//pre: Takes in an int and a string
//post: Dynamically creates a new node with a pointer to the next item plus the int
// and string
Node* LinkedList::CreateNode(int newInt, string newPayload) {
  Node* newNode = new Node;
  //sets the pointer in the first node pointing to null
  newNode->m_next = NULL;
  //populates node with an int and payload
  newNode->m_int = newInt;
  newNode->m_payload = newPayload;
  //sets the node pointer as the head node pointer officially
  m_head = newNode;
  return newNode;
}

//name: InsertEnd
//pre: Takes in an int and a string. Requires a linked list
//post: Adds a new node to the end of the linked list.
void LinkedList::InsertEnd(int newInt, string newPayload){
  Node* newNode = new Node;
  //sets the placeholder pointer to the head node pointer
  Node* currentPtr = m_head;
  newNode->m_next = NULL;
  newNode->m_int = newInt;
  newNode->m_payload = newPayload;
  //traverses the linked list until it reaches the end
  while (currentPtr->m_next != NULL) {
    currentPtr = currentPtr->m_next;
  }
  //inserts the node at the end of the linked list
  currentPtr->m_next = newNode;
}

//name: Display
//pre: Outputs the linked list (raw or encrypted)
//post: None
void LinkedList::Display(){
  Node* currentPtr = m_head;
  while (currentPtr != NULL) {
    cout << currentPtr->m_payload << "->";
    currentPtr = currentPtr->m_next;
  }
  cout << "END" << endl;
}

//name: Sort
//pre: Takes in a linked list
//post: Sorts the linked list by integer (either raw or decrypted)
void LinkedList::Sort(){
  string tempDataPayload;
  //traverses the linked list
  for (Node* currentPtr = m_head; currentPtr->m_next != NULL; currentPtr = currentPtr->m_next) {
    //traverses the linked list and compares one particular nodes int to the rest of them
    for (Node* tempPtr = currentPtr->m_next; tempPtr->m_next != NULL; tempPtr = tempPtr->m_next) {
      //checks to see if there is a discrepency
      if (currentPtr->m_int > tempPtr->m_int) {
	tempDataPayload = currentPtr->m_payload;
	currentPtr->m_payload = tempPtr->m_payload;
	tempPtr->m_payload = tempDataPayload;
      }
    }
  }
  }

//name: IsEmpty
//pre: Takes in a linked list
//post: Checks to see if the linked list is empty or not
bool LinkedList::IsEmpty(){
  if (m_head == NULL) {
    return true;
  } else {
    return false;
  }
}
//name: Decrypt
//pre: Takes in a linked list
//post: Returns a linked list where any nodes where the int is NOT a perfect square
// or perfect cube is thrown out. Also, returns the square root (for perfect squares)
// or cubed root (for perfect cubes).
// For example, "121 candy" goes in - "11 candy" comes out.
LinkedList LinkedList::Decrypt(){
  LinkedList decryptedList;
  Node* currentPtr = m_head;
  int checkFirstNode = 0, tempInt;
  while (currentPtr != NULL) {
    if ((IsPerfectSquare(currentPtr->m_int) == true) || (IsPerfectCube(currentPtr->m_int) == true)) {
      if (IsPerfectSquare(currentPtr->m_int) == true) {
	tempInt = IsPerfectSquare(currentPtr->m_int);
      } else {
	tempInt = IsPerfectCube(currentPtr->m_int);
      }
      //checks to see if its the first node being created for this particular linked list
      if (checkFirstNode == 0) {
	decryptedList.CreateNode(tempInt, currentPtr->m_payload);
      } else {
	decryptedList.InsertEnd(tempInt, currentPtr->m_payload);
      }
      checkFirstNode++;
    }
    currentPtr = currentPtr->m_next;
  }
  return decryptedList;
}
//name: isPerfectSquare
//pre: Takes in an integer
//post: Returns if it is a perfect square or not
bool LinkedList::IsPerfectSquare(int n){
  int tempInt = round(sqrt(n));
  int tempInt2 = tempInt * tempInt;
  if (tempInt2 == n) {
    return true;
  } else {
    return false;
  }
}
//name: isPerfectCube
//pre: Takes in an integer
//post: Returns if it is a perfect cube or not
bool LinkedList::IsPerfectCube(int n){
  int tempInt = round(cbrt(n));
  int tempInt2 = tempInt * tempInt * tempInt;
  if (tempInt2 == n) {
    return true;
  } else {
    return false;
  }
}
//name Clear
//pre: Takes in a linked list
//post: Clears out the linked list (all nodes too)
void LinkedList::Clear(){
  Node* currentPtr = m_head;
  while (currentPtr != NULL) {
    //goes through and deletes/deallocates the data from the linked list
    m_head = m_head->m_next;
    delete currentPtr;
    currentPtr = m_head;
  }
  m_head = NULL;
}
