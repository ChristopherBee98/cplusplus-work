//Comments
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileIOError{};

int getHighScore() throw (FileIOError) {
  ifstream f;
  int high = -1;

  f.open("scores.txt");
  if(f.fail())
    throw FileIOError();
  
  int num;
  f >> high;
  while (f >> num) {
    if (num > high)
      high = num;
  }
  f.close();
  return high;
}

int main() {
  try {
    int highscore = getHighScore();
    cout << "The high score is " << highscore << endl;
  } catch (FileIOError)
    {
      cout << "Could not open the scores file." << endl;
    }
  return 0;
}
