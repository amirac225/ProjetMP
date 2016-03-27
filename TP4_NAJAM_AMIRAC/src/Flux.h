#ifndef FLUX_H
#define FLUX_H
#include "Triangle.h"
#include <ostream>
#include <memory>

class Flux{
public:
    
    Flux(std::ostream* flux) : m_flux(flux)
    {

    }

    template<typename T>
    void operator()(Triangle<T> const& triangle)
    {
        (*m_flux) << triangle << std::endl;
    }

private:
    std::ostream* m_flux;
};


#endif // FLUX_H
