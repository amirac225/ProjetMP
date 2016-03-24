// Test des operateurs == et != : 

#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{
  Dvector vector(3,2.);

  vector = -vector;
  for(int i = 0; i < 3; i++)
  {
    assert(vector(i) == -2.);
  }
  cout << "OK\n";
  return 0;
}
