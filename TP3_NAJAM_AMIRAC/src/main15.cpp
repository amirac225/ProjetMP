#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	int m = 3, n = 3;
	Dmatrix matrix(m,n,12.);
	matrix(0,0) = 4 ;
	matrix(0,2) = -16 ;
	matrix(1,1) = 37 ;
	matrix(2,2) = 98 ;
	matrix(1,2) = -43 ;
	matrix(2,0) = -16 ;
	matrix(2,1) = -43 ;
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
