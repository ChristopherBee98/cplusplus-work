//Comments
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main() {
  map<string, int> mapOfWords;
  //first is the key, second is the value
  //keys aren't replicated but values can be
  mapOfWords.insert(make_pair("earth", 1));
  mapOfWords.insert(make_pair("mars", 2));
  //different syntax for inserting the key and value
  mapOfWords["neptune"] = 3;
  mapOfWords["sun"] = 4;
  for(map<string, int>::iterator it = mapOfWords.begin(); it != mapOfWords.end(); it++) {
    cout << it->first << ": " << it->second << endl;
    //changes the value of a specific key
    if(it->first == "sun")
      it->second = 15;
}
  //searches for a specific key
  if(mapOfWords.find("sun") != mapOfWords.end())
    cout << "Word 'sun' found" << endl;
  return 0;
}
