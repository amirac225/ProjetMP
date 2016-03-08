#ifndef DVECTOR_H
#define DVECTOR_H

#include "Darray.h"

/** @brief Classe Darray modelisant un vecteur réel de taille m_taille.
    @author NAJA Mohamed Reda, AMIRA Chafik 
    @date Janvier 2016
    */
class Dvector : public Darray 
{
	public : 
/** Constructeur qui permet d'initialiser un vecteur de taille 'taille' dont les coordonnées sont toutes égales à arg.  
    */
    Dvector(int taille, double arg = 0.0);
    /** Constructeur de recopie. */
    Dvector(Dvector const& dvector);
    /** Constructeur qui construit un vecteur à partir du fichier str.
    */
    Dvector(std::string const& str);
    virtual ~Dvector();
};

/**
Definition l'operateur * produit scalaire
@brief On effectue le produit scalaire des deux vecteurs
@param vecteur numéro 1 
@param vecteur numéro 2
@return un scalaire.
 */
double operator*(Dvector const& dvector1, Dvector const& dvector2);

#endif // DVECTOR_H
