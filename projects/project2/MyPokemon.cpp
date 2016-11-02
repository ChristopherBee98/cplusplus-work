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

MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity) {
  m_Num = num;
  m_Name = name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;
}

int MyPokemon::GetCP() {
  return m_CP;
}

int MyPokemon::GetHP() {
  return m_HP;
}

int MyPokemon::GetRarity() {
  return m_Rarity;
}

string MyPokemon::GetName() {
  return m_Name;
}

int MyPokemon::GetNum() {
  return m_Num;
}

void MyPokemon::SetRarity(int newRarity) {
  m_Rarity = newRarity;
}

void MyPokemon::SetName(string newName) {
  m_Name = newName;
}

void MyPokemon::SetHP(int newHP) {
  m_HP = newHP;
}

void MyPokemon::SetCP(int newCP) {
  m_CP = newCP;
}

void MyPokemon::Train() {
  m_CP += 10;
}
