// Test de l'operateur d'* matriciel : 

#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	/* Etape 1 */
	int m = 4, n = 4, p = 4;
	Dmatrix matrix1(m,n,8.);
	Dmatrix matrix2(n,p,0.0);

	for(int i = 0; i < m; i++)
	{
		matrix2(i,i) = 1.;
	}
	
	Dmatrix matrix3	= matrix1*matrix2;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			assert(matrix3(i,j) == matrix1(i,j));
		}
	}

	/* Etape 2 */
	m = 7;
	n = 4;
	p = 2;
	Dmatrix matrix4(m,n,1.);
	Dmatrix matrix5(n,p,2.);
	Dmatrix matrix6 = matrix4*matrix5;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < p; j++)
		{
			assert(matrix6(i,j) == 4*2.); 
		}
	}
	/* Etape 3 */
	m = 8;
	n = 0;
	p = 4;
	Dmatrix matrix7(m,n,1.);
	Dmatrix matrix8(n,p,2.);
	Dmatrix matrix9 = matrix7*matrix8;

	for(int i = 0; i < matrix7.lines(); i++)
	{
		for(int j = 0; j < matrix7.columns(); j++)
		{
			cout << matrix7(i,j) << " ";
		}
		cout << endl;
	}
	
	/* Etape 4 */
	m = 7;
	n = 4;
	p = 4;
	Dmatrix mat(m,n,5.);
	Dvector vect(p,2.);
	Dvector v = mat*vect;
	for(int i = 0; i < v.size(); i++)
	{
		assert(v(i) == 5*2*4);
	}
	
	/* Etape 5 */
	
	m = 7;
	n = 0;
	p = 0;
	Dmatrix mat1(m,n,5.);
	Dvector vect1(p,2.);
	Dvector v1 = mat1*vect1;
	for(int i = 0; i < v1.size(); i++)
	{
		cout << v1(i) << endl;
	}
	return 0;
}