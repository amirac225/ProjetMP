// Test de maillage(p1,p2,p3,p4,m,n): 

#include "Maillage.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
//	cout << Maillage<double,vector>( Point<double>(2,3), Point<double>(7,3), Point<double>(7,6), Point<double>(2,6), 2, 3 );
	cout << Maillage<double,vector>( Point<double>(2,3), Point<double>(5,6), Point<double>(3,8), Point<double>(0,5), 2, 3 );
	return 0;
}
