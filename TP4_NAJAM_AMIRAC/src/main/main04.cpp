// Polymorphisme
#include <iostream>
#include "Dmatrix.h"
#include <assert.h>
#include <vector>

using namespace std;

int main()
{
	vector<Darray*> tableau;
	tableau.push_back(new Dmatrix(10,5,1.));
	tableau.push_back(new Dvector(5,4.));
	tableau.push_back(new Dvector(5,-2.));
	tableau.push_back(new Dmatrix(5,10,-1.));
	for(int i = 0; i < 4; i++)
	{
		delete tableau[i];		
	}
	return 0;
}