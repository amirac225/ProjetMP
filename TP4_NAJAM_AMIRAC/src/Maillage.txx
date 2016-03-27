#include "Maillage.h"
#include "Flux.h"
#include "Transformer.h"
#include "Deplacer.h"
#include "Tourner.h"
//#include "Remplissage.h"
#include <algorithm>

/* Les constructeurs */
template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
Maillage<T,C>::Maillage(int m, int n, const Point<T>& origine)
{
	if(m < 1 || n < 1)
		throw std::string("Dimension du maillage incorrect !");
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			Point<T> a(origine.x() + i, origine.y() + j);
			Point<T> b(origine.x() + i + 1, origine.y() + j); 
			Point<T> c(a.x() + 1,a.y() + 1);
			Point<T> d(a.x(),a.y() + 1);
			Triangle<T> triangle1(a,b,d);
			Triangle<T> triangle2(c,b,d);
			m_maillage.push_back(triangle1);
			m_maillage.push_back(triangle2);
		}
	}  
	/*Remplissage<T> R();
	fill(m_maillage.begin(),m*n,R(n,origine));*/
}

template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
Maillage<T,C>::Maillage(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, int m, int n)
{
	if(m < 1 || n < 1)
		throw std::string("Dimension du maillage incorrect !");
	T d1 = p2.distance(p1);
	T d2 = p4.distance(p1);
	T d3 = p3.distance(p2);
	T d4 = p3.distance(p4);
	/* Un rectangle est un quadrilatère : */
	if(d3 != d2 || d1 != d4 || d1 == 0 || d2 == 0)
		throw std::string("Dimension du rectangle incorrect !");
	/* Possedant 4 angles droits : */
	T a = (p2.x() - p1.x())*(p3.x() - p1.x());
	T b = (p2.y() - p1.y())*(p3.y() - p1.y());
	if(a + b != 0)
		throw std::string("Ceci n'est pas un rectangle !");
	T cos1 = (p2.x() - p1.x())/d1;
	T cos2 = (p4.x() - p1.x())/d2;
	T sin1 = (p2.y() - p1.y())/d1;
	T sin2 = (p4.y() - p1.y())/d2;
	d1 /= m;
	d2 /= n;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			Point<T> a(p1.x() + i*d1*cos1 + j*d2*cos2, p1.y() + i*d1*sin1 + j*d2*sin2);
			Point<T> b(p1.x() + (i + 1)*d1*cos1 + j*d2*cos2, p1.y() + (i+1)*d1*sin1 + j*d2*sin2); 
			Point<T> c(a.x() + 1*d1*cos1 + d2*cos2,a.y() + d1*sin1 + 1*d2*sin2);
			Point<T> d(a.x() + d2*cos2,a.y() + 1*d2*sin2);
			Triangle<T> triangle1(a,b,d);
			Triangle<T> triangle2(c,b,d);
			m_maillage.push_back(triangle1);
			m_maillage.push_back(triangle2);
		}
	}  
}

/* Les methodes */
template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
typename C<Triangle<T> >::const_iterator Maillage<T,C>::beginiter() const
{
	return m_maillage.begin();
}

template<typename T,
    template <typename, typename = std::allocator<Triangle<T> > > class C >
typename C<Triangle<T> >::const_iterator Maillage<T,C>::enditer() const
{
	return m_maillage.end();
}

template<typename T,
    template <typename, typename = std::allocator<Triangle<T> > > class C >
void Maillage<T,C>::transformer(double m11, double m12, double m21, double m22)
{
    for_each(m_maillage.begin(),m_maillage.end(),Transformer(m11,m12,m21,m22));
}

template<typename T,
    template <typename, typename = std::allocator<Triangle<T> > > class C >
void Maillage<T,C>::deplacer(double dx, double dy)
{
    for_each(m_maillage.begin(),m_maillage.end(),Deplacer(dx,dy));
}

template<typename T,
    template <typename, typename = std::allocator<Triangle<T> > > class C >
void Maillage<T,C>::tourner(double angle, Point<T> const& pt)
{
    for_each(m_maillage.begin(),m_maillage.end(),Tourner<T>(angle,pt));
}

/* Les operateurs */
template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
std::ostream& operator<<(std::ostream &flux, Maillage<T,C> const& maillage)
{
	for_each(maillage.beginiter(), maillage.enditer(), Flux(&flux));
    return flux;
}

/* Le destructeur */
template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
Maillage<T,C>::~Maillage()
{
	
}