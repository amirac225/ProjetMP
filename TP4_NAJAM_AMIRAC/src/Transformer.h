#ifndef TRANSFORMER_H
#define TRANSFORMER_H
#include "Triangle.h"
#include <ostream>

class Transformer{
public:
    Transformer(double a, double b, double c, double d) : m_a(a), m_b(b), m_c(c), m_d(d)
    {

    }

    template<typename T>
    void operator()(Triangle<T>& triangle)
    {
    	triangle.transformer(m_a,m_b,m_c,m_d);
    }

private:
    double m_a, m_b, m_c, m_d;
};


#endif // TRANSFORMER_H
