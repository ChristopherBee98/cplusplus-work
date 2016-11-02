/*
File:    proj3.cpp
Project: CMSC 202 Project 3, Fall 2016
Author:  Austin Bailey
Date:    10/30/16
Section: 101
E-mail:  baustin1@umbc.edu

This file is used to run the "system". It asks what
the user wants to do with any particular file. It then
can display encrypted or decrypted messages from text files.
*/

#include "LinkedList.h"
#include "proj3.h"

int main () {
  LinkedList list;
  mainMenu(list);
  return 0;
}

/*name: readFile
  Pre: Takes in a linked list by reference may or may not be empty
  Post: Asks the user for file name. Tries to open the file and read the file
  into a linked list. File may be any size. File contains int and string on each line
*/
void readFile(LinkedList &list){
  //lists out items and streams needed to open up the file
  int listInt, countOfItems = 0;
  fstream inputStream, anotherStream;
  string fileName, filePayload, tempWord;
  cout << "What is the file name?" << endl;
  cin >> fileName;
  inputStream.open(fileName.c_str());
  anotherStream.open(fileName.c_str());
  while (anotherStream >> tempWord) {
    countOfItems++;
  }
  //making sure list isn't populated already
  if (list.IsEmpty() == false) {
    int option = 0;
    bool isExit = 0;
    do {
      do {
	cout << "Do you want to:" << endl;
	cout << "1. Overwrite the message" << endl;
	cout << "2. Append the message" << endl;
	cout << "3. Cancel" << endl;
	cin >> option;
      }while (option < 1 || option > 3);
      switch(option){
      case 1:
	list.Clear();
	countOfItems = countOfItems / 2;
	for (int i = 0; i < countOfItems; i++) {
	  inputStream >> listInt >> filePayload;
	  //does the first node, and lets the InsertEnd do the rest
	  if (i == 0) {
	    list.CreateNode(listInt, filePayload);
	  } else {
	    list.InsertEnd(listInt, filePayload);
	  }
	}
	cout << "List has been overwritten." << endl;
	isExit = 1;
	break;
      case 2:
	countOfItems = countOfItems / 2;
	for (int i = 0; i < countOfItems; i++) {
	  inputStream >> listInt >> filePayload;
	  list.InsertEnd(listInt, filePayload);
	}
	cout << "List has been appended." << endl;
	isExit = 1;
	break;
      case 3:
	cout << "Action cancelled." << endl;
	isExit = 1;
      }
    }while(isExit == 0);

  } else {
    countOfItems = countOfItems / 2;
    for (int i = 0; i < countOfItems; i++) {
      inputStream >> listInt >> filePayload;
      if (i == 0) {
	list.CreateNode(listInt, filePayload);
      } else {
	list.InsertEnd(listInt, filePayload);
      }
  }
    //checks for a valid file name
    if (list.IsEmpty() == false) {
      cout << "New message loaded." << endl;
    } else {
      cout << "Message load failed." << endl;
    }
  }
  inputStream.close();
  anotherStream.close();
}

/*
  name: mainMenu
  Pre: Requires a linked list (passed by reference)
  Post: None
*/
void mainMenu(LinkedList &list){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. Load a new encrypted message" << endl;
      cout << "2. Display a raw message" << endl;
      cout << "3. Display an encrypted message" << endl;
      cout << "4. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 4);

    switch(option){
    case 1:
      readFile(list);
      break;
    case 2:
      //checks to make sure list has message
      if (list.IsEmpty() == true) {
	cout << "Load a message first." << endl;
      } else {
      displayMessage(list);
      }
      break;
    case 3:
      //checks to make sure list has message
      if (list.IsEmpty() == true) {
	cout << "Load a message first." << endl;
      } else {
      displayEncrypt(list);
      }
      break;
    case 4:
      exitLinked(list);
      isExit = 1;
    }
  }while(isExit == 0);
}

/*
  name: displayMessage
  Pre: Requires a linked list (encrypted message)
  Post: Displays the "raw" message - which has all the nodes still it in.
*/
void displayMessage(LinkedList &list){
  cout << "Payload of list are: " << endl;
  list.Display();
  cout << "Payload of list are: " << endl;
  //sorts the list before the payload displays
  list.Sort();
  list.Display();
}

/*
  name: exitLinked
  Pre: Requires a linked list (passed by reference) (to deallocate)
  Post: list is deallocated and the application is exited.
*/
void exitLinked(LinkedList &list){
  cout << "Have a nice day!" << endl;
}

/*
  name: displayEncrypt
  Pre: Requires a linked list (an encrypted message)
  Post: Displays only the decrypted message by creating a new linked list
        and copying only the perfect squares and perfect cubes to it.
        The new linked list with "real" clues is then sorted to display the message.
        When this is done running the original message is still available in list.
        The new linked list is deallocated.
*/
void displayEncrypt(LinkedList &list){
  LinkedList list2;
  //decrypts and then sorts the list
  list2 = list.Decrypt();
  list2.Sort();
  cout << "Payload of list are:" << endl;
  list2.Display();
  //clears the list so it ceases to exist
  list2.Clear();
}
