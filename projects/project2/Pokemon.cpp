/*
File:    Pokemon.cpp
Project: CMSC 202 Project 2, Fall 2016
Author:  Austin Bailey
Date:    10/16/16
Section: 101
E-mail:  baustin1@umbc.edu

This file is used to create Pokemon objects. It takes in
the number of the Pokemon, the name of the Pokemon, the minimum
combat points of the Pokemon, the maximum combat points of the Pokemon, and
the rarity of the Pokemon. It then constructs the Pokemon object.
*/


#include "Pokemon.h"

Pokemon::Pokemon() {
}

// Name: Pokemon(num, name, cpMin, cpMax, rarity)
// Pre-condition: num, name, cpMin, cpMax, and rarity of the object
// Post-condition: Creates a new Pokemon object
Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity) {
  m_Num = num;
  m_Name = name;
  m_MinCP = cpMin;
  m_MaxCP = cpMax;
  m_Rarity = rarity;
}

// Name: Pokemon::GetNum()
// Pre-condition: None
// Post-condition: Returns objects num
int Pokemon::GetNum() {
  return m_Num;
}

// Name: Pokemon::GetName()
// Pre-condition: None
// Post-condition: Returns objects name
string Pokemon::GetName() {
  return m_Name;
}

// Name: Pokemon::GetCPMin()
// Pre-condition: None
// Post-condition: Returns objects minimum CP
int Pokemon::GetCPMin() {
  return m_MinCP;
}

// Name: Pokemon::GetCPMax()
// Pre-condition: None
// Post-condition: Returns objects maximum CP
int Pokemon::GetCPMax() {
  return m_MaxCP;
}

// Name: Pokemon::GetRarity()
// Pre-condition: None
// Post-condition: Returns objects rarity
int Pokemon::GetRarity() {
  return m_Rarity;
}

// Name: Pokemon::SetRarity(newRarity)
// Pre-condition: Takes in objects new rarity
// Post-condition: Sets m_Rarity to newRarity
void Pokemon::SetRarity(int newRarity) {
  m_Rarity = newRarity;
}

// Name: Pokemon::SetName(newName)
// Pre-condition: Takes in objects new name
// Post-condition: Sets m_Name to newName
void Pokemon::SetName(string newName) {
  m_Name = newName;
}

// Name: Pokemon::SetCP(newCP)
// Pre-condition: THIS FUNCTION DOES NOTHING
// Post-condition: THIS FUNCTION DOES NOTHING
void Pokemon::SetCP(int newCP) {
}
