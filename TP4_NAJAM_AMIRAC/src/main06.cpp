// Test de deplacer(): 

#include "Maillage.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//double dx = 2, dy = 2;
	vector<double> origine(7);
	int n = 10;
	fill_n(origine.begin(),n,5);
	cout << origine[2] << endl;
	return 0;
}