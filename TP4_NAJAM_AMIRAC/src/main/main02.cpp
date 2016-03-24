// Test de l'operateur d'affectation matriciel : 

#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	int m = 4, n = 4;
	Dmatrix matrix(m,n,7.);
	Dmatrix matrice;

	matrice = matrix;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			assert(matrice(i,j) == 7.);
			matrice(i,j) = i+j;
		}
	}
	
	matrix = matrice;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			assert(matrix(i,j) == i+j);
			assert(matrice(i,j) == i+j);
		}
	}
	return 0;
}