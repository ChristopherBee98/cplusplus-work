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

Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity) {
  m_Num = num;
  m_Name = name;
  m_MinCP = cpMin;
  m_MaxCP = cpMax;
  m_Rarity = rarity;
}

int Pokemon::GetNum() {
  return m_Num;
}

string Pokemon::GetName() {
  return m_Name;
}

int Pokemon::GetCPMin() {
  return m_MinCP;
}

int Pokemon::GetCPMax() {
  return m_MaxCP;
}

int Pokemon::GetRarity() {
  return m_Rarity;
}

void Pokemon::SetRarity(int newRarity) {
  m_Rarity = newRarity;
}

void Pokemon::SetName(string newName) {
  m_Name = newName;
}

void Pokemon::SetCP(int newCP) {
}
