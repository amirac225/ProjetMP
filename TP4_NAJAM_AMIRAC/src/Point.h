#ifndef POINT_H
#define POINT_H

#include <ostream>

/** @brief Classe Point permettant de modeliser un point dans le plan.
    @author NAJA Mohamed Reda, AMIRA Chafik 
    @date Janvier 2016
    */

template<typename T>
class Point
{
    public:
    	/** Constructeur par defaut surchargé. \n
            Initialise les coordonnées du point à (0,0).
        */
        Point();

    	/** Constructeur. \n
            Initialise les coordonnées du point à (x,y).
        */        
        Point(T x, T y);

    	/** Constructeur de recopie \n
            Initialise les coordonnées du point à (x,y).
        */        
        Point(Point<T> const& point);

        /** Operateur d'affectation
        */
        Point<T>& operator=(Point<T> const& point);

    	/** Accesseur. \n
            Renvoi l'abscisse du point.
        */                
        T x() const;

    	/** Accesseur. \n
            Renvoi l'ordonné du point.
        */                
        T y() const;

        /** Methode permettant de transformer un point. 
        */
        void transformer(double m11, double m12, double m21, double m22);

        /** Methode permettant de deplacer un point. 
        */
        void deplacer(double dx, double dy);

        /** Methode permettant de tourner un point d'un angle angle
        */
        void tourner(double angle, Point<T> const& pt);
        
        /** Methode permettant de calculer la distance entre le point courant et pt
        */
        T distance(Point<T> const& pt) const;

        /** Destructeur.
        */
        virtual ~Point();
    protected:
        T m_x;
        T m_y;
    private:
};

template<typename T>
std::ostream& operator<<(std::ostream &flux, Point<T> const& point);

#include "Point.txx"

#endif // POINT_H