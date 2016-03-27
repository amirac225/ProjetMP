// Test de deplacer(): 

#include "Maillage.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	//double dx = 2, dy = 2;
	Point<double> origine(0,0);
	int k = 10, n = 10;
	Maillage<double, vector> m(k,n,Point<double>(0,0));
	m.tourner(0.0,origine);

	cout << m; 
	return 0;
}
