// Test de l'operateur d'accession : 

#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{
  Dvector vector(3,5.);
  vector(0) = 2.;
  assert(vector(0) == 2);
  double b = vector(1);
  assert(b == 5);
  cout << "OK\n";
  return 0;
}