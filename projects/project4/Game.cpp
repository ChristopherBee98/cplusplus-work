
#include "Game.h"

//Name: Game (Constructor)
//Precondition: None
//Postcondition: Game is started with monsters initialized, ben initialized,
//decides number of levels
Game::Game() {
  m_levels = NumLevels();
  m_level = 0;
  InitMonsters();
  InitBen();
  Start(100);
}
//Name: ~Game (Destructor)
//Precondition: Destructor for the game
//Postcondition: Deletes all dynamically allocated data
Game::~Game() {
}
//Name: InitMonsters
//Precondition: Requires m_mons
//Postcondition: Dynamically populates m_mons with one monster per level
void Game::InitMonsters() {
  m_mons = new Monster*[m_levels];
  for(int i = 0; i < m_levels; i++) {
    Monster *newMonster = new Monster(m_level);
    m_mons[i] = newMonster;
  }
  m_currMons = m_mons[0];
}
//Name: InitBen
//Precondition: Requires m_ben
//Postcondition: Dynamically populates m_ben with all possible forms
// Level 1 = Ben, Level 2 = Pyronite, Level 3 = Crystalsapien
void Game::InitBen() {
  m_ben = new Ben*[3];
  Ben *ben = new Ben("Ben", 100, "hand-to-hand", "kick", 0, 0.10, 0, 2, 10, 20, 25);
  Pyronite *pyronite = new Pyronite("Pyronite", 100, "fire", "flamer", 0, 0.15, 0, 1, 15, 20, 30);
  Crystalsapien *crystalsapien = new Crystalsapien("Crystalsapien", 100, "energy", "laser", 0.25, 0.25, 0, 1, 25, 30, 10);
  m_ben[0] = ben;
  m_ben[1] = pyronite;
  m_ben[2] = crystalsapien;
}
//Name: SetBen
//Precondition: Requires populated m_ben (Lists all possible Bens for that level)
//Postcondition: Sets m_currBen based on the user choice
void Game::SetBen(int startLife) {
  int choiceOfBen;
  cout << "Select one from the available forms of Ben at level 1 are: " << endl;
  switch(m_level) {
  case 0:
    cout << "1. Ben" << endl;
    cin >> choiceOfBen;
    break;
  case 1:
    cout << "1. Ben" << endl;
    cout << "2. Pyronite" << endl;
    cin >> choiceOfBen;
    break;
  default:
    cout << "1. Ben" << endl;
    cout << "2. Pyronite" << endl;
    cout << "3. Crystalsapien" << endl;
    cin >> choiceOfBen;
  }
  switch(choiceOfBen) {
  case 1:
    m_currBen = m_ben[0];
    break;
  case 2:
    m_currBen = m_ben[1];
    break;
  default:
    m_currBen = m_ben[2];
  }
}
//Name: Start
//Precondition: Starts the game (Primary driver of game)
//Postcondition: May exit if Ben dies (exits game) or Monster dies (goes to
//next level or wins game!
void Game::Start(int startLife) {
  bool isOver = false;
  while (isOver == false) {
    if (m_level == 0)
      SetBen(startLife);
    else
      SetBen(m_currBen->GetLife());
    cout << "BEN: " << m_currBen->GetName() << endl;
    cout << "MONSTER: " << m_currMons->GetName() << endl;
    cout << "The start life of Ben is: " << m_currBen->GetLife() << endl;
    cout << "The start life of " << m_currMons->GetName() << " is: " << m_currMons->GetLife() << endl;
    while (m_currMons->GetLife() != 0) {
      cout << m_currBen->GetName() << ": " << m_currBen->GetLife() << "        " << m_currMons->GetName() << ": " << m_currMons->GetLife() << endl;
      isOver = Input();
  }
    if (m_currMons->GetLife() == 0) {
      cout << "Congrats! " << m_currBen->GetName() << " won that level." << endl;
      m_level += 1;
      m_currMons = m_mons[m_level];
  }
  }
  if (m_currBen->GetLife() == 0)
    cout << "Game over! Ben has DIED." << endl;
  else
    cout << "Congratulations! You WIN." << endl;
}
//Name: NumLevels
//Precondition: Prompts user for number of levels between 1 and 20
//Postcondition: Returns user response
int Game::NumLevels() {
  bool isValid = 0;
  int levels;
  while (isValid == 0) {
    cout << "How many levels would you like to try?" << endl;
    cin >> levels;
    if (levels <= 20 && levels >= 1)
      isValid = 1;
    if (levels > 20 || levels < 1)
      cout << "You need to do 1 between 20 levels." << endl;
  }
  return levels;
}
//Name: Input (basically the battle function)
//Precondition: Checks to see if Ben and monster are alive
//During: Prompts user with menu
//Postcondition: Manages types of attacks (normal, special, or ultimate)
bool Game::Input() {
  int choiceOfAttack, check = 0;
  cout << "What would you like to do?" << endl;
  cout << "1. Normal Attack" << endl;
  cout << "2. Special Attack" << endl;
  cout << "3. Ultimate Attack" << endl;
  cin >> choiceOfAttack;
  while (check == 0) {
    switch(choiceOfAttack) {
    case 1:
      m_currBen->Attack(m_currMons);
      m_currMons->Attack(m_currBen);
      check = 1;
      break;
    case 2:
      m_currBen->SpecialAttack(m_currMons);
      m_currMons->Attack(m_currBen);
      check = 1;
      break;
    case 3:
      m_currBen->UltimateAttack(m_currMons);
      m_currMons->Attack(m_currBen);
      check = 1;
      break;
    default:
      cout << "Invalid; please enter a valid number" << endl;
      cin >> choiceOfAttack;
  }
  }
  if ((m_level == (m_levels - 1)) && (m_currMons->GetLife() == 0))
    return true;
  else if (m_currBen->GetLife() == 0)
    return true;
  else
    return false;
}
