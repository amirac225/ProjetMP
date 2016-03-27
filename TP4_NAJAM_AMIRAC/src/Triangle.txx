#include "Triangle.h"

/* Les constructeurs */
/* Leve une exception si les points sont colineaire */
template<typename T>
Triangle<T>::Triangle(Point<T> const& a, Point<T> const& b, Point<T> const& c) : m_p1(a), m_p2(b), m_p3(c)
{
	/* les points a, b et c doivent être non alignées :*/
	if((a.x()-c.x())*(b.y() - c.y()) != (a.y() - c.y())*(b.x() - c.x()))
		throw std::string("Triangle incorrecte, les points doivent êtres non alignées");
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
	m_p3.transformer(m11,m12,m21,m22);
}

template <typename T>
void Triangle<T>::deplacer(double dx, double dy)
{
	m_p1.deplacer(dx,dy);
	m_p2.deplacer(dx,dy);
	m_p3.deplacer(dx,dy);
}

template <typename T>
void Triangle<T>::tourner(double angle, Point<T> const& pt)
{
	m_p1.tourner(angle,pt);
	m_p2.tourner(angle,pt);
	m_p3.tourner(angle,pt);
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