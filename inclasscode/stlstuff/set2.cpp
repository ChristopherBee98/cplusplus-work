//Comments
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  set<string> setOfNumbers;
  setOfNumbers.insert("first");
  setOfNumbers.insert("second");
  setOfNumbers.insert("third");
  setOfNumbers.insert("fourth");
  setOfNumbers.insert("fifth");
  setOfNumbers.insert("first"); //Doesn't add it to the set; it's already in it
  cout << "Set size = " << setOfNumbers.size() << endl;
  cout << "Set size = " << setOfNumbers.count("fifth") << endl;
  //Iterates through the set
  for(set<string>::iterator it = setOfNumbers.begin(); it != setOfNumbers.end(); it++)
    cout << ' ' << *it;
  cout << endl;
  return 0;
}
