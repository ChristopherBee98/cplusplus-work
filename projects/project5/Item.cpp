/*
File:    Item.cpp
Project: CMSC 202 Project 5, Fall 2016
Author:  Austin Bailey
Date:    12/11/16
Section: 101
E-mail:  baustin1@umbc.edu

This file is used as a file to create all item objects. It contains the usual
accessors and mutators but also has a ToString function for outputting to a file.
*/

#include "Item.h"

// Constructors for Item
Item::Item() {
}

Item::Item(int inId, string inName, float inWeight){
  m_id = inId;
  m_name = inName;
  m_weight = inWeight;
}

// Accessors for Item
int Item::GetId() const {
  return m_id;
}

string Item::GetName() const {
  return m_name;
}

float Item::GetWeight() const {
  return m_weight;
}

//Name: ToString
//Precondition: Requires item to be formatted for output
//Postcondition: Creates single string for output
//Allowed to use <sstream> for this (not necessarily)
string Item::ToString() const {
  ostringstream stringStream;
  //for printing out to the file
  stringStream << m_name << "\n";
  string concString = stringStream.str();
  return concString;
}

