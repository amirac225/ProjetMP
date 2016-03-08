#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
#include <string>

/** @brief Classe Dvector modelisant un vecteur réel de taille m_taille.
<<<<<<< HEAD
    @author NAJA Mohamed Reda
=======
    @author NAJA Mohamed Reda 
    @date Janvier 2016
    */

class Dvector
{
    public:
        /** Constructeur par defaut surchargé. \n
            Initialise la taille et le pointeur à 0.
        */
        Dvector();
        /** Constructeur qui permet d'initialiser un vecteur de taille 'taille' dont les coordonnées sont toutes égales à arg.  
        */
        Dvector(int taille, double arg = 0.0);
        /** Constructeur de recopie. */
        Dvector(Dvector const& dvector);
        /** Constructeur qui construit un vecteur à partir du fichier str.
        */
        Dvector(std::string str);
        /** @return La taille du vecteur.
        */
        int size() const;
        /** Methode qui construit le vecteur à partir de la loi normal sur [0,1]
        */
        void fillRandomly();
        /** Affiche le vecteur.
            @param str : un flux.
        */
#include <iostream>
#include <string>

/** @brief Classe Dvector modelisant un vecteur réel de taille m_taille.
    @author NAJA Mohamed Reda 
    @date Janvier 2016
>>>>>>> 42c43a30952d81c5e0a13daa61bc8496a490d97c
    */

class Dvector
{
    public:
        /** Constructeur par defaut surchargé. \n
            Initialise la taille et le pointeur à 0.
        */
        Dvector();
        /** Constructeur qui permet d'initialiser un vecteur de taille 'taille' dont les coordonnées sont toutes égales à arg.  
        */
        Dvector(int taille, double arg = 0.0);
        /** Constructeur de recopie. */
        Dvector(Dvector const& dvector);
        /** Constructeur qui construit un vecteur à partir du fichier str.
        */
        Dvector(std::string const& str);
        /** @return La taille du vecteur.
        */
        int size() const;
        /** Methode qui construit le vecteur à partir de la loi normal sur [0,1]
        */
        void fillRandomly();
        /** Affiche le vecteur.
            @param str : un flux.
        */
        void display(std::ostream& str) const;
	
        /** Destructeur.
        */
        virtual ~Dvector();
    protected:
        /**
            Tableau vecteur alloué dynamiquement lors de la construction de l'objet.
        */
        double* m_double;

        void display(std::ostream& str) const;
	
        /** Destructeur.
        */
        virtual ~Dvector();
    protected:
        /**
            Tableau vecteur alloué dynamiquement lors de la construction de l'objet.
        */
        double* m_double;
        /**
            Taille du vecteur.
        */
        int m_taille;
};

Dvector operator + (const Dvector &v , const double &a) ;
Dvector operator - (const Dvector &v , const double &a) ;
Dvector operator * (const Dvector &v , const double &a) ; 
Dvector operator / (const Dvector &v , const double &a) ;
Dvector operator + (const Dvector &v1 , const Dvector &v2) ;
Dvector operator - (const Dvector &v1 , const Dvector &a2) ;


#endif // DVECTOR_H
