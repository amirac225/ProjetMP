// Test des operateurs +-*/ avec un double : 

#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{
  Dvector vector1(3,2.);
  Dvector vector2(vector1);
  assert(vector1 == vector2);
  
  cout << "OK\n";
  return 0;
}