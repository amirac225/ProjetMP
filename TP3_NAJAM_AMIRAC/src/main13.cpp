#include <iostream>
#include "Dmatrix.h"
#include <assert.h>

using namespace std;

int main()
{
	int m = 4, n = 4;
	Dmatrix matrix(m,n,1.);
	for (int i = 0 ; i < n ; i++){
	  matrix(0,i) = 1 ;
	}
	for (int i = 0 ; i < n ; i++){
	  matrix(i,0) = 1 ;
	}

	for (int i = 1 ; i < n ; i++){
	  matrix(1,i) = 5 ;
	}
	for (int i = 1 ; i < n ; i++){
	  matrix(i,1) = 5 ;
	}
	for (int i = 2 ; i < n ; i++){
	  matrix(2,i) = 14 ;
	}
	for (int i = 2 ; i < n ; i++){
	  matrix(i,2) = 14 ;
	}
	matrix(3,3) = 15 ;

	Dmatrix mat = matrix.cholesky() ; 
	for (int i = 0 ; i < 4 ; i++){
	  for (int j = 0 ; j < 4 ; j++){
	    cout << mat(i,j) << " " ;
	  }
	  cout << endl ; 
	}
	return 0;
}
