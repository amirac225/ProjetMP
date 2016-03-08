#ifndef DMATRIX_H
#define DMATRIX_H
#include "Darray.h"
#include "Dvector.h"
/** @brief Classe Dmatrix modelisant une matrice réelle de taille n * m
    @author NAJA Mohamed Reda, AMIRA Chafik 
    @date Janvier 2016
    */

class Dmatrix : public Darray{
 private :
  int m ;
  int n ;
 public :
  /** Constructeur qui permet d'initialiser une matric de taille nb_lines * nb_col dont les coordonnées sont toutes égales à arg.  
        */
  Dmatrix(int nb_lines, int nb_col, double arg = 0.0);
        /** Constructeur de recopie. */
  Dmatrix(Dmatrix const& matrix);



        /** Destructeur.
        */
        virtual ~Dmatrix();

	/* Surcharges des opérateurs */


	/**
	   @brief Acceder au nombre de lignes de la matrice 
	   @return un entier égal au nombre de lignes de la matrice
	**/
	int lines() const;

	/**
	   @brief Acceder au nombre de colonnes de la matrice 
	   @return un entier égal au nombre de colonnes de la matrice
	**/
	int columns() const;


	/**
	   @brief redéfinition de l'operateur = pour l'affectation d'une matrice 
	   @param Matrix la matrice dans le membre à droite 
	   @return 
	**/
	Dmatrix& operator = (Dmatrix const & matrix) ; 
	


	/** 
	    @brief Extraction d'une ligne de la matrice 
	    @param pos numero de la colonne
	    @return un Dvector correspondant à la ligne d'indice pos 
	**/
	Dvector line (int pos) const;
	
	/** 
	    @brief Extraction d'une colonne de la matrice 
	    @param pos numero de la colonne
	    @return un Dvector correspondant à la colonne d'indice pos 
	**/
	Dvector column (int pos) const;

	
	/**
	   @brief Accession à un coefficient de la matrice 
	   @param i indice de la ligne (entre 0 et n-1)
	   @param j indice de la ligne (entre 0 et m-1)
	   @return le coefficient (i,j) de la matrice. 
	**/
	double& operator() (int i , int j) ;

	/**
	   @brief Accession à un coefficient de la matrice avec const 
	   @param i indice de la ligne (entre 0 et n-1)
	   @param j indice de la ligne (entre 0 et m-1)
	   @return le coefficient (i,j) de la matrice. 
	**/
	const double& operator() (int i, int j) const ;
	/** 
	    @brief Transposition d'une matrice carrée
	    @return Matrice transposée
	**/
	Dmatrix & transpose() ; 

};

	Dmatrix operator * (Dmatrix const &matrix1 ,Dmatrix const & matrix2) ;
	Dvector operator * (Dmatrix const& matrix, Dvector const& vector) ;
#endif // DMATRIX_H
