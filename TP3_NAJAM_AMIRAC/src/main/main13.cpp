// Test de resize() : 

#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{
  Dvector vector(3,2.);
  vector.resize(5,7.0);
  assert(vector.size() == 5);
  for(int i = 0; i < 3; i++)
  {
  	assert(vector(i) == 2.);
  }
  assert(vector(3) == 7.);
  assert(vector(4) == 8.);

  vector.resize(2);
  assert(vector.size() == 2);
  assert(vector(0) == 2.);
  assert(vector(1) == 2.);

  vector.resize(2);
  assert(vector.size() == 2);
  assert(vector(0) == 2.);
  assert(vector(1) == 2.);

  vector.resize(6,1.);
  assert(vector.size() == 6);
  for(int i = 2; i < 6; i++)
  {
  	assert(vector(i) == i-1);
  }

  cout << "OK\n";
  return 0;
}
