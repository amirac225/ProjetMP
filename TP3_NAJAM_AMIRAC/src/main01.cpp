// Test de l'operateur d'accession matriciel : 

#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	int m = 4, n = 4;
	Dmatrix matrix(m,n,7.);
	Dmatrix matrice(matrix);
	const Dmatrix matrac(m,n,8.);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			assert(matrix(i,j) == 7.);
			assert(matrice(i,j) == 7.);
			assert(matrac(i,j) == 8.);
			matrix(i,j) = i+j;
			matrice(i,j) = matrix(i,j);
		}
	}
	
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