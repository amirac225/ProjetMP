#ifndef REMPLISSAGE_H
#define REMPLISSAGE_H
#include "Triangle.h"
#include <ostream>
#include <memory>
//#include <stdbool>

template<typename T>
class Remplissage{
public:
    
    Remplissage() : m_i(0), m_j(0), m_inverse(true)
    {

    }

    Triangle<T> operator()(int n, Point<T> origine)
    {
    	Point<T> a(origine.x() + m_i, origine.y() + m_j);
		Point<T> b(origine.x() + m_i + 1, origine.y() + m_j); 
		Point<T> c(a.x() + 1,a.y() + 1);
		Point<T> d(a.x(),a.y() + 1);
//		Triangle<T> triangle = (m_inverse)?Triangle<T>(a,b,d):(c,b,d);
    	m_inverse = !m_inverse;
        if(m_j == n)
        {
        	m_i++;
        	m_j = 0; 
        }
        return (m_inverse)?Triangle<T>(a,b,d):Triangle<T>(c,b,d);
    }

private:
   	int m_i;
   	int m_j;
   	bool m_inverse;
};


#endif // REMPLISSAGE_H
