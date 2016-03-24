#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	int m = 3, n = 3;
	Dmatrix matrix(m,n,-1.);
	for (int i = 0 ; i < n ; i++){
	  matrix(i,i) = 2 ;
	}
	matrix (0,2) = 0 ;
	matrix (2,0) = 0 ; 
	Dmatrix mat = matrix.cholesky() ;
	Dmatrix l = mat ;
	mat.transpose() ; 
	Dmatrix res =  l * mat  ;
	cout << "la matrice initiale est" << endl ;
	for (int i = 0 ; i < 3 ; i++){
	  for (int j = 0 ; j < 3 ; j++){
	    cout << matrix(i,j) << " " ;
	  }
	  cout << endl ; 
	}
	cout << "la matrice resultante L * transposee L est" << endl ;
	for (int i = 0 ; i < 3 ; i++){
	  for (int j = 0 ; j < 3 ; j++){
	    cout << res(i,j) << " " ;
	  }
	  cout << endl ; 
	}
	return 0;
}
