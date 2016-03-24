// Test de transformer(): 

#include "Maillage.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	double m11 = 7., m22 = 2., m21 = 3., m12 = 4.;
	int k = 10, n = 10;
	Maillage<double, vector> m(k,n,Point<double>(0,0));
	m.transformer(m11, m12, m21, m22);
	cout << m; 
	return 0;
}
