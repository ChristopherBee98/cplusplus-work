#include <iostream>
using namespace std;

void extraCredit(int &score1, int &score2);

int main() {
  int scoreOne, scoreTwo;
  cout << "Enter score 1: " << endl;
  cin >> scoreOne;
  cout << "Enter score 2: " << endl;
  cin >> scoreTwo;
  cout << "Score 1 before extra credit: " << scoreOne << endl;
  cout << "Score 2 before extra credit: " << scoreTwo << endl;
  extraCredit(scoreOne, scoreTwo);
  cout << "Score 1 after extra credit: " << scoreOne << endl;
  cout << "Score 2 after extra credit: " << scoreTwo << endl;
  return 0;
}

void extraCredit(int &score1, int &score2) {
  score1 += 2;
  score2 += 2;
}
