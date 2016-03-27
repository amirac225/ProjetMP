#ifndef TOURNER_H
#define TOURNER_H
#include "Triangle.h"

template<typename T>
class Tourner{
public:
    Tourner(double angle,Point<T> const& pt) : m_pt(pt), m_angle(angle)
    {

    }

    void operator()(Triangle<T>& triangle)
    {
    	triangle.tourner(m_angle,m_pt);
    }

private:
    Point<T> m_pt;
    double m_angle;
};


#endif // TOURNER_H