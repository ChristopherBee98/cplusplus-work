
#include "Monster.h"

//Name: Monster (Constructor)
//Precondition: Must have the level of the game.
//Sets the name of the monster randomly from the monster.txt file.
//Sets the life and attack based on calculated values
//Postcondition: Loads a new monster with stats based on the level.
Monster::Monster(int level) {
  if (level == 0)
    LoadMonster();
  m_name = SummonMonster();
  switch(level) {
  case 0:
    m_life = rand() % 50 + 20;
    m_attack = rand() % 5 + 1;
    break;
  case 1:
    m_life = rand() % 60 + 30;
    m_attack = rand() % 10 + 3;
    break;
  default:
    m_life = rand() % 70 + 40;
    m_attack = rand() % 15 + 5;
    break;
  }
}
//Name: ~Monster
//Precondition: Something must be dynamically allocated
//Postcondition: None
Monster::~Monster() {
}
//Name: SummonMonster
//Precondition: Need to have the m_monster vector populated by LoadMonster
//Postcondition: Returns the string value of a random monster from the vector
string Monster::SummonMonster() {
  string monsterName;
  int randomMonster;
  randomMonster = rand() % (int)m_monster.size() + 1;
  monsterName = m_monster.at(randomMonster);
  return monsterName;
}
//Name: LoadMonster
//Precondition: Must have the m_monster vector available and the monster.txt
//Postcondition: Populates the m_monster vector with the monster names in the file
void Monster::LoadMonster() {
  fstream inputStream, checkStream;
  string tempName;
  inputStream.open("monster.txt");
  checkStream.open("monster.txt");
  while (checkStream >> tempName) {
    m_monster.push_back(tempName);
  }
  inputStream.close();
  checkStream.close();
}
//Name: Attack
//Precondition: Must have a form of Ben to attack
//Postcondition: Reduces current version of Ben by calculated damage
void Monster::Attack(Ben *&target) {
  int heroLife;
  cout << m_name << " attacks " << target->GetName() << " using a normal attack." << endl;
  heroLife = target->GetLife() - m_attack;
  target->SetLife(heroLife);
  cout << m_name << " does " << m_attack << " to " << target->GetName() << "." << endl;
  if (target->GetLife() < 0)
    target->SetLife(0);
}
//Name: Mutators and Accessors
//Normal getters and setters
void Monster::SetLife(int life) {
  m_life = life;
}
int Monster::GetLife() {
  return m_life;
}
string Monster::GetName() {
  return m_name;
}

//Name - Name of the monster
//string m_name;
//Life - Calculated number of life points for the monster
//int m_life;
//Attack - Calculated number of attack for the monster
//int m_attack;
//Vector to hold the entire list of monster names
//vector <string> m_monster;
