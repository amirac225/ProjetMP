#ifndef DEPLACER_H
#define DEPLACER_H
#include "Triangle.h"

class Deplacer{
public:
    Deplacer(double x, double y) : m_dx(x), m_dy(y)
    {

    }

    template<typename T>
    void operator()(Triangle<T>& triangle)
    {
    	triangle.deplacer(m_dx,m_dy);
    }

private:
    double m_dx, m_dy;
};


#endif // DEPLACER_H