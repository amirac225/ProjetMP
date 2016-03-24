#include "Maillage.h"

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
{/*
    for(typename C<Triangle<T> >::iterator it = m_maillage.begin(); it != m_maillage.end(); ++it)
    {
    	it->transformer(m11,m12,m21,m22);
    }*/
    generate(m_maillage.begin(),m_maillage.end(),);
}

/* Les operateurs */
template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
std::ostream& operator<<(std::ostream &flux, Maillage<T,C> const& maillage)
{
    for(typename C<Triangle<T> >::const_iterator it = maillage.beginiter(); it != maillage.enditer(); ++it)
    {
    	flux << *it << std::endl;
    }
    return flux;
}



/* Le destructeur */
template<typename T, 
    template <typename, typename = std::allocator<Triangle<T> > > class C >
Maillage<T,C>::~Maillage()
{
	
}