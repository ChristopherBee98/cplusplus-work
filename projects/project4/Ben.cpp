
#include "Ben.h"
#include "Monster.h"

//Name: Ben (Constructor)
//Precondition: Need to have the name and the life (from table in project doc)
//Postcondition: Creates a default version of Ben (not transformed)
Ben::Ben(string name, int life) {
  m_name = name;
  m_life = life;
}
//Name: Ben (Overloaded constructor)
//Precondition: Need to have all of the stats for an advanced form
//Data from table in project document
//Postcondition: Creates a specific version of Ben for use in transformed versions
Ben::Ben(string name, int life, string nameNorm, string nameSpecial,
    double defenseBonus, double missPercent, int usedSpecial,
	 int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec) {
  m_name = name;
  m_life = life;
  m_nameNormal = nameNorm;
  m_nameSpecial = nameSpecial;
  m_defenseBonus = defenseBonus;
  m_missPercent = missPercent;
  m_usedSpecial = usedSpecial;
  m_maxSpecial = maxSpecial;
  m_minDamageNormal = minDamNorm;
  m_maxDamageNormal = maxDamNorm;
  m_damageSpecial = damSpec;
}
//Name: ~Ben
//Precondition: Dynamically allocated Ben (using new)
//Postcondition: Removes allocated Ben from memory
Ben::~Ben() {
}
//Name: Attack
//Precondition: Need a target (May miss!)
//Postcondition: Reduces life of target with output
void Ben::Attack(Monster *&target) {
  int attackPower;
  double chanceOfMiss = rand() % 1001 + 1;
  chanceOfMiss *= m_missPercent;
  cout << m_name << " attacks using his " << m_nameNormal << " attack." << endl;
  if (chanceOfMiss >= 10.0) {
    attackPower = rand() % (m_maxDamageNormal + 1) + m_minDamageNormal;
    int monsterLife = target->GetLife() - attackPower;
    target->SetLife(monsterLife);
    cout << m_name << " did " << attackPower << " damage to " << target->GetName() << "." << endl;
    if (target->GetLife() < 0)
      target->SetLife(0);
  } else {
    cout << m_name << " misses! " << target->GetName() << " retaliates!" << endl;
  }
}
//Name: Special Attack
//Precondition: Needs a target (Finite number of special attacks by form)
//Postcondition: Reduces life of target with output
void Ben::SpecialAttack(Monster *&target) {
  double chanceOfMiss;
  if (m_usedSpecial != m_maxSpecial) {
    chanceOfMiss = rand() % 1001 + 1;
    chanceOfMiss *= m_missPercent;
    if (chanceOfMiss >= 10.0) {
      cout << m_name << " attacks using his " << m_nameSpecial << " attack." << endl;
      int monsterLife = target->GetLife() - m_damageSpecial;
      target->SetLife(monsterLife);
      cout << m_name << " did " << m_damageSpecial << " damage to " << target->GetName() << "." << endl;
      if (target->GetLife() < 0)
	target->SetLife(0);
      m_usedSpecial += 1;
    } else {
      cout << m_name << " misses! " << target->GetName() << " retaliates!" << endl;
      m_usedSpecial += 1;
    }
  } else {
    cout << m_name << " is out of special attacks! " << target->GetName() << " retaliates!" << endl;
  }
}
//Name: Ultimate Attack
//Precondition: Needs a target (only available with Crystalsapien)
//Postcondition: Reduces life of target with output
void Ben::UltimateAttack(Monster *&target) {
  cout << m_name << " has no ultimate attack! " << target->GetName() << "retaliates!" << endl;
}
//Name: Mutators and Acccessors
void Ben::SetLife(int life) {
  m_life = life;
}
string Ben::GetName() {
  return m_name;
}
int Ben::GetLife() {
  return m_life;
}
