#include "Point.h"
#include <cmath>

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
	T tmp = m_x;
	m_x = m_x*m11 + m_y*m21;
	m_y = tmp*m12 + m_y*m22;
}

template <typename T>
void Point<T>::deplacer(double dx, double dy)
{
	m_x += dx;
	m_y += dy;
}

template <typename T>
void Point<T>::tourner(double angle, Point<T> const& pt)
{
	if(m_x == pt.x() && m_y == pt.y())
	{
		return;
	}
	m_x -= pt.x();
	m_y -= pt.y();

	T r = distance(Point<T>(0,0));
	double theta = atan2(m_y,m_x);
	m_x = r*cos(theta + angle) + pt.x();
	m_y = r*sin(theta + angle) + pt.y();
}

template <typename T>
T Point<T>::distance(Point<T> const& pt) const
{
	return sqrt(pow(pt.y() - m_y,2) + pow(pt.x() - m_x,2));
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