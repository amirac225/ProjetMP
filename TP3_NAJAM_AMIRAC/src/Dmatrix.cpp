#include "Darray.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Dmatrix.h"
#include "Dvector.h"
#include <cassert>

/* Les Constructeurs : */

/* Initialisation d'un vecteur à partir d'une taille et d'un argument facultatif */
/* Necessite que taille >= 0 */
Dmatrix::Dmatrix(int nb_lines, int nb_col , double arg) : Darray(nb_lines*nb_col, arg)
{
  m = nb_lines ;
  n = nb_col ; 
}

/* Surcharge du constructeur de recopie */
Dmatrix::Dmatrix(Dmatrix const& dmatrix) : Darray(dmatrix)
{
  m = dmatrix.m ;
  n = dmatrix.n ; 
}


/* Destructeur */
Dmatrix::~Dmatrix()
{
    std::cout << "Destruction de la matrice" << std::endl;
    delete [] m_double;
}

Dvector operator * (Dmatrix const &matrix, Dvector const& vector){
  assert(matrix.lines() == vector.size()) ; 

  // Dvector vect = Dvector(m,0) ;
  // for (int i = 0; i < n ; i++){
  //   for (int j = 0 ; j < m; j++){
  //     vect(i) += (*this)(i,j) * vector(j) ;
  //   }
  // }
  Dvector vect = Dvector(matrix.lines(),0) ; 
  for (int i = 0; i < matrix.lines(); i++){
    vect(i) += matrix.line(i) * vector ;
  }
  return vect ; 
}


double & Dmatrix::operator() (int i , int j){
  return (*(Darray *)this)(j + i*n) ;
}

const double & Dmatrix::operator() (int i , int j) const{
  return (*(Darray *)this)(j + i*n) ;
}

Dvector Dmatrix::line (int pos) const{
  assert (pos >= 0 && pos < m) ;
  Dvector line (n, 0) ;
  for (int j = 0 ; j < m ; j++){
    line(j) = (*this)(pos, j) ;
  }
  return line ;
}

Dvector Dmatrix::column (int pos) const {
  assert(pos >= 0 && pos < m);
  Dvector column (n, 0) ;
  for (int i = 0; i < n; i++){
    column(i) = (*this)(i,pos) ;
  }
  return column ;
}

Dmatrix operator * (Dmatrix const &matrix1, Dmatrix const & matrix2) {
  assert(matrix1.columns() == matrix2.lines()) ; 
  Dmatrix mat = Dmatrix(matrix1.lines(), matrix2.columns(), 0) ; 
  for (int i = 0 ; i < matrix1.lines() ; i++){
    for (int j =0 ; j < matrix2.lines() ; j++){
      mat(i,j) = matrix1.line(i) * matrix2.column(j) ;
    }
  }
  return mat ; 
}


Dmatrix& Dmatrix::operator = (Dmatrix const & matrix){
 if (this != &matrix){
   m = matrix.m ;
   n = matrix.n ;
   m_taille = n * m ;
   delete[] m_double ;
   m_double = new double[n*m] ; 
   memcpy(m_double, matrix.m_double, m_taille*sizeof(double)) ;
    
 }
 return *this ; 
} 


int Dmatrix::lines() const {
  return this->m ; 
}
 
int Dmatrix::columns() const {
  return this->n ;
}



Dmatrix& Dmatrix::transpose() {
  double a ;
  assert (n == m) ; 
  for  (int i =1 ; i < n ; i++){
    for (int j = 0 ; j < i ; j++){
      a = (*this)(i,j) ;
      (*this)(i,j) = (*this)(j,i)  ;
      (*this)(j,i) = a ;
    }
  }
 
  return *this ;
}
