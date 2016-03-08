#include <iostream>
#include "Dvector.h"
#include <assert.h>

using namespace std;

int main()
{
  Dvector vector2(4);
  Dvector vector1(2,5.);
  Dvector vector3(7,1.);
  Dvector tmp;
  tmp = vector1;
  cout << "tmp \n";
  tmp.display(cout);
  cout << "end tmp" << endl;
  vector1 = vector2;
  vector1.display(cout);
  cout << endl;
  vector2 = vector3;
  vector2.display(cout);
  cout << endl;
  vector3= tmp;
  vector3.display(cout);
  cout << endl;
}