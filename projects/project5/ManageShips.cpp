/*
File:    ManageShips.cpp
Project: CMSC 202 Project 5, Fall 2016
Author:  Austin Bailey
Date:    12/11/16
Section: 101
E-mail:  baustin1@umbc.edu

This file is used for managing the entire operation. It gets
heaviest ships, lightest ships, heaviest items, etc. It also
has a function for outputting the information in the ships
to a .txt file. (Called proj5_output.txt)
*/

#include "ManageShips.h"

// Constructor for Managing the ships.
// Once the data has been imported and split used to manage all additonal functions
// Two ships (one for item and one for people)
// Two cargo lists (one for items and one for people)
ManageShips::ManageShips(vector< Spaceship <Item> > itemShip,
	    vector< Spaceship <Person> > personShip,
	    vector< Item > itemCargo,
	    vector< Person > personCargo){
  m_itemShips = itemShip;
  m_personShips = personShip;
  m_items = itemCargo;
  m_person = personCargo;
  //loads all the items and people into their respective ships
  LoadItemShip();
  LoadPersonShip();
}

//Name: LoadItemShip
//Precondition: Requires itemShips and itemCargo
//Postcondition: Loads items into each ship
//Additional information: Cannot load more than capacity of each ship.
//It is possible that not all items will be loaded
void ManageShips::LoadItemShip() {
  double totalCapacity;
  int checkCapacity, checkShips = 0, checkItems = 0;
  int countOfItems = 0, countOfShips = 0;
  //checks for either no ships left or no items left
  while (checkShips == 0 && checkItems == 0) {
    totalCapacity = 0;
    checkCapacity = 0;
    //fixed! but need to look at logic a little more
    while (checkCapacity == 0) {
      if (countOfItems == (int)m_items.size()) {
	checkItems = 1;
	checkCapacity = 1;
      }
      else {
	totalCapacity += m_items.at(countOfItems).GetWeight();
	if (totalCapacity >= m_itemShips.at(countOfShips).GetCapacity()) {
	  totalCapacity -= m_items.at(countOfItems).GetWeight();
	  checkCapacity = 1;
	  countOfShips++;
	} else if (totalCapacity == m_itemShips.at(countOfShips).GetCapacity()){
	  checkCapacity = 1;
	  countOfShips++;
	} else {
	  m_itemShips.at(countOfShips).AddCargo(m_items.at(countOfItems));
	  countOfItems++;
	}
      }
      }
    if (countOfShips == (int)m_itemShips.size())
      checkShips = 1;
    }
  cout << "Item Ships Loaded: " << countOfShips << endl;
  cout << "Items Loaded: " << countOfItems << endl;
  //deletes certain objects depending on how many have been loaded
  m_items.erase(m_items.begin(), m_items.begin()+countOfItems);
}
//Name: LoadPersonShip
//Precondition: Requires personShips and personCargo
//Postcondition: Loads people into each ship
//Additional information: Cannot load more than capacity of each ship.
//It is possible that not all items will be loaded
void ManageShips::LoadPersonShip() {
  double totalCapacity;
  int checkCapacity, checkPeople = 0, checkShips = 0;
  int countOfPeople = 0, countOfShips = 0;
  while (checkPeople == 0 && checkShips == 0) {
    //fixed! but need to look at logic a little more
    totalCapacity = 0;
    checkCapacity = 0;
    while (checkCapacity == 0) {
      if (countOfPeople == (int)m_person.size()) {
        checkPeople = 1;
        checkCapacity = 1;
      } else {
	totalCapacity += 1;
	if (totalCapacity == m_personShips.at(countOfShips).GetCapacity()) {
	  checkCapacity = 1;
	  countOfShips++;
	} else {
	  m_personShips.at(countOfShips).AddCargo(m_person.at(countOfPeople));
	  countOfPeople++;
      }
      }
    }
    if (countOfShips == (int)m_personShips.size())
      checkShips = 1;
  }
  cout << "Person Ships Loaded: " << countOfShips << endl;
  cout << "Persons Loaded: " << countOfPeople << endl;
  m_person.erase(m_person.begin(), m_person.begin()+countOfPeople);
}

//Name: DisplayItemLeft
//Precondition: Requires that all item ships have been loaded
//Postcondition: Outputs (cout) each item not loaded into a ship
void ManageShips::DisplayItemLeft() {
  if ((int)m_items.size() == 0)
    cout << "None" << endl;
  else {
    for (int i = 0; i < (int)m_items.size(); i++)
      cout << "Item " << i+1 << " - Name: " << m_items.at(i).GetName() << endl;
  }
}
//Name: DisplayPersonLeft
//Precondition: Requires that all people ships have been loaded
//Postcondition: Outputs (cout) each person not loaded into a ship
void ManageShips::DisplayPersonLeft() {
  if ((int)m_person.size() == 0)
    cout << "None" << endl;
  else {
    for (int i = 0; i < (int)m_person.size(); i++)
      cout << "Person " << i+1 << " - Name: " << m_person.at(i).GetFName() << endl;
  }
}

//Name: OutputShips
//Precondition: Requires that all ships have been loaded
//Postcondition: Writes out all ships and their cargo to a specific output file
//Output file will always be proj5_output.txt
void ManageShips::OutputShips() {
  fstream outputStream;
  string personShips, itemShips;
  outputStream.open("proj5_output.txt");
  //gets one giant string for item ships and people ships to output
  for (int i = 0; i < (int)m_personShips.size(); i++)
    personShips += m_personShips.at(i).ToString();
  for (int j = 0; j < (int)m_itemShips.size(); j++)
    itemShips += m_itemShips.at(j).ToString();
  outputStream << "**Personnel Ships**" << "\n" << personShips << "**Item Ships**" << "\n" << itemShips;
  outputStream.close();
}
//Name: GetHeaviestShip()
//Precondition: Requires that all ships have been loaded
//Postcondition: Outputs (cout) the heaviest ship based on total weight
//**Important: Checks both cargo (item) ships and personnel (person) ships
string ManageShips::GetHeaviestShip() {
  //creates 2 different types of ships for comparison
  Spaceship<Item> heaviestItemShip = m_itemShips.at(0);
  Spaceship<Person> heaviestPersonShip = m_personShips.at(0);
  double weightOfItemShip, weightOfPersonShip;
  for (int i = 0; i < (int)m_itemShips.size(); i++) {
    if (heaviestItemShip.operator>(m_itemShips.at(i)) == true)
      heaviestItemShip = m_itemShips.at(i);
  }
  for (int j = 0; j < (int)m_personShips.size(); j++) {
    if (heaviestPersonShip.operator>(m_personShips.at(j)) == true)
      heaviestPersonShip = m_personShips.at(j);
  }
  //gets both types of ships weights, then compares them
  for (int k = 0; k < (int)heaviestItemShip.GetCargo().size(); k++)
    weightOfItemShip += heaviestItemShip.GetCargoAt(k).GetWeight();
  for (int k = 0; k < (int)heaviestPersonShip.GetCargo().size(); k++)
    weightOfPersonShip += heaviestPersonShip.GetCargoAt(k).GetWeight();
  if (weightOfItemShip > weightOfPersonShip) {
    cout << "Ship Type: " << "Item" << endl;
    cout << "Ship Name: " << heaviestItemShip.GetName() << endl;
    cout << "Total Weight: " << weightOfItemShip << endl;
    cout << "Total Capacity: " << heaviestItemShip.GetCapacity() << endl;
    return "*****************";
  } else {
    cout << "Ship Type: " << "Person" << endl;
    cout << "Ship Name: " << heaviestPersonShip.GetName() << endl;
    cout << "Total Weight: " << weightOfPersonShip << endl;
    cout << "Total Capacity: " << heaviestPersonShip.GetCapacity() << endl;
    return "*****************";
  }
}

//Name: GetLightestShip()
//Precondition: Requires that all ships have been loaded
//Postcondition: Outputs (cout) the lightest ship based on total weight
//**Important: Checks both cargo (item) ships and personnel (person) ships
string ManageShips::GetLightestShip() {
  Spaceship<Item> lightestItemShip = m_itemShips.at(0);
  Spaceship<Person> lightestPersonShip = m_personShips.at(0);
  double weightOfItemShip, weightOfPersonShip;
  for (int i = 0; i < (int)m_itemShips.size(); i++) {
    if (lightestItemShip.operator<(m_itemShips.at(i)) == true)
      lightestItemShip = m_itemShips.at(i);
  }
  for (int j = 0; j < (int)m_personShips.size(); j++) {
    if (lightestPersonShip.operator<(m_personShips.at(j)) == true)
      lightestPersonShip = m_personShips.at(j);
  }
  for (int k = 0; k < (int)lightestItemShip.GetCargo().size(); k++)
    weightOfItemShip += lightestItemShip.GetCargoAt(k).GetWeight();
  for (int k = 0; k < (int)lightestPersonShip.GetCargo().size(); k++)
    weightOfPersonShip += lightestPersonShip.GetCargoAt(k).GetWeight();
  if (weightOfItemShip > weightOfPersonShip) {
    cout << "Ship Type: " << "Person" << endl;
    cout << "Ship Name: " << lightestPersonShip.GetName() << endl;
    cout << "Total Weight: " << weightOfPersonShip << endl;
    cout << "Total Capacity: " << lightestPersonShip.GetCapacity() << endl;
    return "*****************";
  } else {
    cout << "Ship Type: " << "Item" << endl;
    cout << "Ship Name: " << lightestItemShip.GetName() << endl;
    cout << "Total Weight: " << weightOfItemShip << endl;
    cout << "Total Capacity: " << lightestItemShip.GetCapacity() << endl;
    return "*****************";
  }
}

//Name: GetLightestItem
//Precondition: Requires that all ships have been loaded
//Postcondition: Outputs (cout) the lightest item on a ship
string ManageShips::GetLightestItem() {
  //creates cargo to copy the cargo of multiple ships
  vector<Item> tempCargo;
  Item lightestCargo = m_itemShips.at(0).GetCargoAt(0);
  for (int i = 0; i < (int)m_itemShips.size(); i++) {
    tempCargo = m_itemShips.at(i).GetCargo();
    for (int j = 0; j < (int)tempCargo.size(); j++) {
      //if its smaller than the other cargo, lightestCargo is now that particular cargo
      if (tempCargo.at(j).GetWeight() < lightestCargo.GetWeight())
	lightestCargo = tempCargo.at(j);
    }
  }
  cout << "Item Name: " << lightestCargo.GetName() << endl;
  cout << "ID: " << lightestCargo.GetId() << endl;
  cout << "Weight: " << lightestCargo.GetWeight() << endl;
  return "*****************";
}
//Name: GetHeaviestItem
//Precondition: Requires that all ships have been loaded
//Postcondition: Outputs (cout) the heaviest item on a ship
string ManageShips::GetHeaviestItem() {
  vector<Item> tempCargo;
  Item heaviestCargo = m_itemShips.at(0).GetCargoAt(0);
  for (int i = 0; i < (int)m_itemShips.size(); i++) {
    tempCargo = m_itemShips.at(i).GetCargo();
    for (int j = 0; j < (int)tempCargo.size(); j++) {
      if (tempCargo.at(j).GetWeight() > heaviestCargo.GetWeight())
        heaviestCargo = tempCargo.at(j);
    }
  }
  cout << "Item Name: " << heaviestCargo.GetName() << endl;
  cout << "ID: " << heaviestCargo.GetId() << endl;
  cout << "Weight: " << heaviestCargo.GetWeight() << endl;
  return "*****************";
}

//Name: GetOldestPerson
//Precondition: Requires that all ships have been loaded
//Postcondition: Outputs (cout)  the oldest person on a ship
string ManageShips::GetOldestPerson() {
  vector<Person> tempCargo;
  Person oldestCargo = m_personShips.at(0).GetCargoAt(0);
  for (int i = 0; i < (int)m_personShips.size(); i++) {
    tempCargo = m_personShips.at(i).GetCargo();
    for (int j = 0; j < (int)tempCargo.size(); j++) {
      if (tempCargo.at(j).GetAge() > oldestCargo.GetAge())
        oldestCargo = tempCargo.at(j);
    }
  }
  cout << "First Name: " << oldestCargo.GetFName() << endl;
  cout << "Last Name: " << oldestCargo.GetLName() << endl;
  cout << "Age: " << oldestCargo.GetAge() << endl;
  cout << "Weight: " << oldestCargo.GetWeight() << endl;
  return "*****************";
}
//Name: GetYoungestPerson
//Precondition: Requires that all ships have been loaded
//Postcondition: Outputs (cout)  the youngest person on a ship
string ManageShips::GetYoungestPerson() {
  vector<Person> tempCargo;
  Person youngestCargo = m_personShips.at(0).GetCargoAt(0);
  for (int i = 0; i < (int)m_personShips.size(); i++) {
    tempCargo = m_personShips.at(i).GetCargo();
    for (int j = 0; j < (int)tempCargo.size(); j++) {
      if (tempCargo.at(j).GetAge() < youngestCargo.GetAge())
        youngestCargo = tempCargo.at(j);
    }
  }
  cout << "First Name: " << youngestCargo.GetFName() << endl;
  cout << "Last Name: " << youngestCargo.GetLName() << endl;
  cout << "Age: " << youngestCargo.GetAge() << endl;
  cout << "Weight: " << youngestCargo.GetWeight() << endl;
  return "*****************";
}

/*
vector< Spaceship<Item> > m_itemShips;
vector< Spaceship<Person> > m_personShips;
vector< Item > m_items;
vector< Person > m_person;
*/
