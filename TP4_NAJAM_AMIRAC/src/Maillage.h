#ifndef MAILLAGE_H
#define MAILLAGE_H

#include "Triangle.h"
#include <memory>

/** @brief Classe Maillage permettant de modeliser un maillage de triangle.
    @author NAJA Mohamed Reda, AMIRA Chafik 
    @date Janvier 2016
    */

template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
class Maillage
{
    public:
    	/** Constructeur . \n
            Initialise le maillage en triangle.
        */        
        Maillage(int m, int n, const Point<T>& origine);

        /** Constructeur . \n
            Initialise le maillage en triangle.
        */ 
        Maillage(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, int m, int n);

        /** Iterateur sur le début du conteneur
        */
        typename C<Triangle<T> >::const_iterator beginiter() const;

        /** Iterateur sur la fin du conteneur
        */
        typename C<Triangle<T> >::const_iterator enditer() const;

        /** Methode permettant de transformer un maillage 
        */
        void transformer(double m11, double m12, double m21, double m22);

        /** Methode permettant de deplacer un maillage 
        */
        void deplacer(double dx, double dy);

        /** Methode permettant de tourner un maillage d'un angle angle
        */
        void tourner(double angle, Point<T> const& pt);        

        /** Destructeur.
        */
        virtual ~Maillage();
    protected:
    	C<Triangle<T> > m_maillage;
    private:
};

/** Operateur de flux . \n
*/ 
template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
std::ostream& operator<<(std::ostream &flux, Maillage<T,C> const& maillage);

#include "Maillage.txx"

#endif // MAILLAGE_H