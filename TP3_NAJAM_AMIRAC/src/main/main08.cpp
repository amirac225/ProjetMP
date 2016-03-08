// Test des operateurs +-*/ avec un double : 

#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{
  Dvector vector01(3,5.);
  Dvector vector(3,2);

  vector01 = vector + 6;
  for(int i = 0; i < 3; i++)
  {
  	assert(vector01(i) == 8.);
  }

  vector01 = vector * 6;
  for(int i = 0; i < 3; i++)
  {
    assert(vector01(i) == 12.);
  }

  vector01 = vector - 6.;
  for(int i = 0; i < 3; i++)
  {
    assert(vector01(i) == -4.);
  }

  vector01 = vector / 6.0;
  for(int i = 0; i < 3; i++)
  {
    assert(vector01(i) == 1.0/3);
  }
  cout << "OK\n";
  return 0;
}
