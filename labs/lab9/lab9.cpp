#include <iostream>
#include "IntArray.h"

using namespace std;

int main(int argc, char *argv[])
{
  // Create IntArray objects and call methods here...
  IntArray ia(10);
  //error 1
  IntArray ia1(-1);
  //edge case 1
  IntArray ia2(0, -1);
  //error 2
  IntArray ia3(100000000000000000);
  //error 3
  ia.operator==(ia3);
  //error 4
  ia.operator!=(ia3);
  //error 5
  ia.operator[](100);
  //error 6
  ia.Get(-1);
  //error 7
  ia.Get(1000000);
  //error 8, 9
  IntArray ia4;
  ia4.SetItem(-1, 1);
  ia.SetItem(100, 1);
  //error 10, 11
  ia4.Insert(-1, 1);
  ia.Insert(100000000000, 1);
  //error 12
  ia4.Del(-1);
  
  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
    
  return 0;
}
