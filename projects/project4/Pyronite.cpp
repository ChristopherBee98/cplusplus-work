
#include "Pyronite.h"
#include "Monster.h"

//Name: Attack
//Precondition: Requires target
//Postcondition: Does calculated damage to the target based on table in project doc
void Pyronite::Attack(Monster *&target) {
  int attackPower;
  double chanceOfMiss = rand() % 1001 + 1;
  chanceOfMiss *= m_missPercent;
  cout << m_name << " attacks using his " << m_nameNormal << " attack." << endl;
  if (chanceOfMiss >= 15.0) {
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
//Precondition: Requires target (finite uses)
//Postcondition: Does calculated damage to the target based on table in project doc
void Pyronite::SpecialAttack(Monster *&target) {
  double chanceOfMiss;
  if (m_usedSpecial != m_maxSpecial) {
    chanceOfMiss = rand() % 1001 + 1;
    chanceOfMiss *= m_missPercent;
    if (chanceOfMiss >= 15.0) {
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
//Note: No ultimate attack
