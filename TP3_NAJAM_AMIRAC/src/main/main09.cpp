// Test des operateurs +- avec un dvector : 

#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{
  Dvector vector01(3,5.);
  Dvector vector(3,2);

  vector01 = vector + vector;
  for(int i = 0; i < 3; i++)
  {
  	assert(vector01(i) == 4.);
  }

  vector01 = vector - vector;
  for(int i = 0; i < 3; i++)
  {
    assert(vector01(i) == -0.);
  }

  vector01 = vector01 + vector + vector01 - vector;
  for(int i = 0; i < 3; i++)
  {
    assert(vector01(i) == -0.);
  }

  cout << "OK\n";
  return 0;
}
