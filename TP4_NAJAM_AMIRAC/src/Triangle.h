#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include <string>

/** @brief Classe Triangle permettant de modeliser un triangle dans le plan.
    @author NAJA Mohamed Reda, AMIRA Chafik 
    @date Janvier 2016
    */

template<typename T>
class Triangle
{
    public:
    	/** Constructeur par defaut surchargé. \n
            Initialise les trois points du triangles.
        */      
        // Exception à gerer : linearité des points  
        Triangle(Point<T> const& a, Point<T> const& b, Point<T> const& c);

    	/** Accesseur sur le premier point. \n
        */
        Point<T> p1() const;    

    	/** Accesseur sur le deuxieme point. \n
        */
        Point<T> p2() const;              
    	
    	/** Accesseur sur le troisieme point. \n
        */
        Point<T> p3() const;  

        /** Methode permettant de transformer un triangle
        */
        void transformer(double m11, double m12, double m21, double m22);

        /** Methode permettant de deplacer un triangle
        */
        void deplacer(double dx, double dy);
        
        /** Methode permettant de tourner un triangle d'un angle angle
        */
        void tourner(double angle, Point<T> const& pt);

        /** Destructeur.
        */
        virtual ~Triangle();
    protected:
        Point<T> m_p1;
        Point<T> m_p2;
        Point<T> m_p3;
    private:
};

template <typename T>
std::ostream& operator<<(std::ostream &flux, Triangle<T> const& triangle);

#include "Triangle.txx"

#endif // TRIANGLE_H