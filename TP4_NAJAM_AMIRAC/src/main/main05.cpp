// Test de l'operateur d'* matriciel : 

#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	/* Etape 1 */
	int m = 4, n = 2, p = 4;
	Dmatrix mat1(m,n);
	Dmatrix mat2(n,p);
	

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			mat1(i,j) = i + j + 2;
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < p; j++)
		{
			mat2(i,j) = i - j;
		}
	}

	Dmatrix mat = (mat1*mat2).transpose().transpose();

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < p; j++)
		{
			cout << mat(i,j) << " ";
		}
		cout << endl;
	}

	return 0;
}