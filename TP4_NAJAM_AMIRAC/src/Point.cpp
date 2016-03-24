#include "Point.h"

/* Les constructeurs */
template<typename T>
Point<T>::Point() : m_x(0), m_y(0)
{

}

template<typename T>
Point<T>::Point(T x, T y) : m_x(x), m_y(y)
{

}

template<typename T>
Point<T>::Point(Point<T> const& point) : m_x(point.m_x), m_y(point.m_y)
{

}

/* Les operateurs */
template<typename T>
Point<T>& Point<T>::operator=(Point<T> const& point)
{
    if(this != &point)
    {
    	m_x = point.m_x;
    	m_y = point.m_y;
    }
    return *this;
}

/* Les methodes */
template<typename T>
T Point<T>::x() const
{
	return m_x;
}

template<typename T>
T Point<T>::y() const
{
	return m_y;
}

template <typename T>
void Point<T>::transformer(double m11, double m12, double m21, double m22)
{
	m_x = m_x*m11 + m_y*m21;
	m_y = m_x*m12 + m_y*m22;
}

/* Les operateurs */
template<typename T>
std::ostream& operator<<(std::ostream &flux, Point<T> const& point)
{
	flux << point.x() << " " << point.y() << std::endl;
	return flux;
}

template<typename T>
Point<T>::~Point()
{
	
}