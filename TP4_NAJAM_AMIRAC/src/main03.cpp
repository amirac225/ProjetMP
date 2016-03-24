// Test de l'operateur << : 

#include "Maillage.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int k = 10, n = 10;
	Maillage<double, vector> m(k,n,Point<double>(0,0));
	cout << m; 
	return 0;
}
