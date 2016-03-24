#include "Triangle.h"

/* Les constructeurs */
/* Leve une exception si les points sont colineaire */
template<typename T>
Triangle<T>::Triangle(Point<T> const& a, Point<T> const& b, Point<T> const& c) : m_p1(a), m_p2(b), m_p3(c)
{
	if( (a.x() == b.x() && a.y() == b.y()) || ( a.x() == c.x() && a.y() == c.y() ) || ( b.x() == c.x() && b.y() == c.y() ) )
		throw std::string("Triangle incorrecte, les points doivent êtres differents");
}

/* Les methodes */
template<typename T>
Point<T> Triangle<T>::p1() const
{
	return m_p1;
}

template<typename T>
Point<T> Triangle<T>::p2() const
{
	return m_p2;
}

template<typename T>
Point<T> Triangle<T>::p3() const
{
	return m_p3;
}

template<typename T>
void Triangle<T>::transformer(double m11, double m12, double m21, double m22)
{
	m_p1.transformer(m11,m12,m21,m22);
	m_p2.transformer(m11,m12,m21,m22);
	m_p3.transformer(m11,m12,m21,m11);
}

/* Les operateurs */
template <typename T>
std::ostream& operator<<(std::ostream &flux, Triangle<T> const& triangle)
{
	flux << triangle.p1();
	flux << triangle.p3();
	flux << triangle.p2();
	flux << triangle.p1();
	return flux;
}

template<typename T>
Triangle<T>::~Triangle()
{
	
}