/*
File:    MyPokemon.cpp
Project: CMSC 202 Project 2, Fall 2016
Author:  Austin Bailey
Date:    10/16/16
Section: 101
E-mail:  baustin1@umbc.edu

This file takes in paramaters and creates a MyPokemon object.
It takes in the number of the Pokemon, the name of the Pokemon, the
combat points of the Pokemon, the hit points of the Pokemon, and the rarity
of the Pokemon. It then constructs the Pokemon object.
*/


#include "MyPokemon.h"

MyPokemon::MyPokemon() {
}

// Name: MyPokemon(num, name, cp, hp, rarity)
// Pre-condition: Takes in num, name, cp, hp and rarity from call
// Post-condition: Creates a MyPokemon object
MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity) {
  m_Num = num;
  m_Name = name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;
}

// Name: MyPokemon::GetCP()
// Pre-condition: None
// Post-condition: Returns the CP of an object
int MyPokemon::GetCP() {
  return m_CP;
}

// Name: MyPokemon::GetHP()
// Pre-condition: None
// Post-condition: Returns the HP of an object
int MyPokemon::GetHP() {
  return m_HP;
}

// Name: MyPokemon::GetRarity()
// Pre-condition: None
// Post-condition: Returns the rarity of an object
int MyPokemon::GetRarity() {
  return m_Rarity;
}

// Name: MyPokemon::GetName()
// Pre-condition: None
// Post-condition: Returns the name of an object
string MyPokemon::GetName() {
  return m_Name;
}

// Name: MyPokemon::GetNum()
// Pre-condition: None
// Post-condition: Returns the number of an object
int MyPokemon::GetNum() {
  return m_Num;
}

// Name: MyPokemon::SetRarity(newRarity)
// Pre-condition: Takes in objects new rarity
// Post-condition: Sets m_Rarity as newRarity
void MyPokemon::SetRarity(int newRarity) {
  m_Rarity = newRarity;
}

// Name: MyPokemon::SetName(newName)
// Pre-condition: Takes in objects new name
// Post-condition: Sets m_Name as newName
void MyPokemon::SetName(string newName) {
  m_Name = newName;
}

// Name: MyPokemon::SetHP(newHP)
// Pre-condition: Takes in objects new HP
// Post-condition: Sets m_HP to newHP
void MyPokemon::SetHP(int newHP) {
  m_HP = newHP;
}

// Name: MyPokemon::SetCP(newCP)
// Pre-condition: Takes in objects new CP
// Post-condition: Sets m_CP to newCP
void MyPokemon::SetCP(int newCP) {
  m_CP = newCP;
}

// Name: MyPokemon::Train()
// Pre-condition: None
// Post-condition: Adds 10 to the CP of the object
void MyPokemon::Train() {
  m_CP += 10;
}
