// Test de la question 2 : 

#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{

  Dvector vector(3,-6.);
  vector = vector + vector;
  return 0;
}