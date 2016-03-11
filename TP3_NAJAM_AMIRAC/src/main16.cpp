#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	int m = 4, n = 4;
	Dmatrix matrix(m,n,22.);
	matrix(0,0) = 18 ;
	matrix(0,2) = 54 ;
	matrix(0,3) = 42 ; 
	matrix(1,1) = 70 ;
	matrix(1,2) = 86 ;
	matrix(1,3) = 62 ; 
	matrix(2,0) = 54 ;
	matrix(2,1) =86 ;
	matrix(2,2) = 174 ;
	matrix(2,3) = 134 ;
	matrix (3,0) = 42 ;
	matrix(3,1) = 62 ;
	matrix(3,2) = 134 ;
	matrix(3,3) = 106 ;
	Dmatrix mat = matrix.cholesky() ;
	Dmatrix l = mat ;
	mat.transpose() ; 
	Dmatrix res =  l * mat  ;
	cout << "la matrice initiale est" << endl ;
	for (int i = 0 ; i < 4 ; i++){
	  for (int j = 0 ; j < 4 ; j++){
	    cout << matrix(i,j) << " " ;
	  }
	  cout << endl ; 
	}
	cout << "la matrice resultante L * transposee L est" << endl ;
	for (int i = 0 ; i < 4 ; i++){
	  for (int j = 0 ; j < 4 ; j++){
	    cout << res(i,j) << " " ;
	  }
	  cout << endl ; 
	}
	
	return 0;
}
