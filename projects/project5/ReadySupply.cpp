/*
File:    ReadySupply.cpp
Project: CMSC 202 Project 5, Fall 2016
Author:  Austin Bailey
Date:    12/11/16
Section: 101
E-mail:  baustin1@umbc.edu

This file is used as a file for populating the vectors of
ships and cargo. It then returns it to ManageShips.cpp for
use in that class definition file.
*/

#include "ReadySupply.h"

//Name: ReadySupply() and ReadySupply(string, string)
//Precondition: Requires two files a ship file and a cargo file
//Postcondition: Populates two vectors
ReadySupply::ReadySupply() {
}
ReadySupply::ReadySupply(string shipFile, string cargoFile) {
  m_shipFile = shipFile;
  m_cargoFile = cargoFile;
  //populates all the vectors
  LoadShips();
  LoadCargo();
}

//Name: LoadShips
//Precondition: Requires a ships file
//Postcondition: Builds TWO vectors
//Ship 1: Holds people (person)
//Ship 2: Holds cargo (items)
void ReadySupply::LoadShips() {
  ifstream inputStream, outputStream;
  string tempLine, shipName, shipType;
  double shipCapacity;
  //converts it to a cstring
  inputStream.open(m_shipFile.c_str());
  outputStream.open(m_shipFile.c_str());
  while (getline(outputStream, tempLine)) {
    inputStream >> shipType >> shipName >> shipCapacity;
    if (shipType == "Item") {
      Spaceship< Item > newItemShip(shipName, shipType, shipCapacity);
      m_itemShips.push_back(newItemShip);
    } else {
      Spaceship< Person > newPersonShip(shipName, shipType, shipCapacity);
      m_personShips.push_back(newPersonShip);
    }
  }
  inputStream.close();
  outputStream.close();
}
//Name: LoadCargo
//Precondition: Requires a cargo file
//Postcondition: Builds TWO vectors
//Cargo 1: Holds people (person)
//Cargo 2: Holds cargo (item)
void ReadySupply::LoadCargo() {
  ifstream inputStream, outputStream;
  int cargoId, cargoAge;
  string tempLine, cargoName, cargoFName, cargoLName, cargoType;
  double cargoWeight;
  inputStream.open(m_cargoFile.c_str());
  outputStream.open(m_cargoFile.c_str());
  while (getline(outputStream, tempLine)) {
    inputStream >> cargoType;
    //checks which cargo type it is, then takes in a certain amount of value after
    if (cargoType == "i") {
      inputStream >> cargoId >> cargoName >> cargoWeight;
      Item newItemCargo(cargoId, cargoName, cargoWeight);
      m_itemCargo.push_back(newItemCargo);
    } else {
      inputStream >> cargoFName >> cargoLName >> cargoWeight >> cargoAge >> cargoId;
      Person newPersonCargo(cargoFName, cargoLName, cargoWeight, cargoAge, cargoId);
      m_personCargo.push_back(newPersonCargo);
    }
  }
  inputStream.close();
  outputStream.close();
}

//Name: GetItemShips
//Precondition: Requires that item ships have been built
//Postcondition: Returns a vector of all item ships
vector< Spaceship<Item> > ReadySupply::GetItemShips() {
  return m_itemShips;
}
//Name: GetPersonShips
//Precondition: Requires that person ships have been built
//Postcondition: Returns a vector of all person ships
vector< Spaceship<Person> > ReadySupply::GetPersonShips() {
  return m_personShips;
}
//Name: GetItemCargo
//Precondition: Requires that all item vectors have been built
//Postcondition: Returns a vector of all items
vector< Item > ReadySupply::GetItemCargo() {
  return m_itemCargo;
}
//Name: GetPersonCargo
//Precondition: Requires that all person vectors have been built
//Postcondition: Returns a vector of all people (person)
vector< Person > ReadySupply::GetPersonCargo() {
  return m_personCargo;
}

/*
string m_shipFile;
string m_cargoFile;
vector< Spaceship<Item> > m_itemShips;
vector< Spaceship<Person> > m_personShips;
vector< Person> m_personCargo;
vector< Item> m_itemCargo;
*/
