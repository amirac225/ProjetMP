#include "Darray.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

/* Les Constructeurs : */

/* Constructeur par défaut surchargé */
Darray::Darray() : m_double(0), m_taille(0)
{
    std::cout << "Appel du constructeur par defaut" << std::endl;
    m_double = new double[m_taille];
}

/* Initialisation d'un vecteur à partir d'un fichier se trouvant à str */
Darray::Darray(std::string const& str) : m_double(0), m_taille(0)
{
    std::cout << "Appel du constructeur faisant appel au fichier " << str << std::endl;
    /* Ouverture du fichier */
    std::ifstream file(str.c_str());
    if(file)
    {
        double tmp;
        /* Calcul de la taille du vecteur */
        while(!file.eof())
        {
            m_taille++;
            file >> tmp;
        }
        m_taille--;
        /* Fermeture puis reouverture du fichier et construction du vecteur */
        file.clear();
        file.seekg(0,std::ios::beg);
        m_double = new double[m_taille];
        for(int i = 0; i < m_taille; i++)

        {
            file >> m_double[i];
        }
        file.close();
    }
    else
    {
        m_double = new double[m_taille]; 
    }
}
/* Initialisation d'un vecteur à partir d'une taille et d'un argument facultatif */
/* Necessite que taille >= 0 */
Darray::Darray(int taille, double arg) : m_double(0), m_taille(taille)
{
    std::cout << "Appel du constructeur initialisant à partir d'une taille et d'un argument " << std::endl;
    m_double = new double[m_taille];
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = arg;
    }
}

/* Surcharge du constructeur de recopie */
Darray::Darray(Darray const& dvector) : m_double(0), m_taille(dvector.m_taille)
{
    std::cout << "Appel du constructeur de recopie " << std::endl;
    m_double = new double[m_taille];
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = dvector.m_double[i];
    }
}

/* La surcharges d'opérateurs : */

/* Surcharge de l'operateur d'affectation puisqu'on a surchargé un constructeur de recopie */
// Darray& Darray::operator=(Darray const& dvector)
// {
//     if(this != &dvector)
//     {
//         m_taille = dvector.m_taille;
//         delete [] m_double;
//         m_double = new double[m_taille];
//         for(int i = 0; i < m_taille; i++)
//         {
//             m_double[i] = dvector.m_double[i];
//         }
//     }
//     return *this;
// }
//Deuxième implémentation de l'operateur
//d'affectation
Darray& Darray::operator=(Darray const& dvector)
{
    if(this != &dvector)
    {
        m_taille = dvector.m_taille;
        delete [] m_double;
        m_double = new double[m_taille] ;
	    memcpy(m_double, dvector.m_double, m_taille*sizeof(double)) ;
    }
    return *this;
}
/* Operateur d'accession : */
double& Darray::operator()(int i)
{
    return m_double[i];
}

double const& Darray::operator()(int i) const
{
    return m_double[i];
}


/* Operateur de comparaison : */
bool operator==(Darray const& dvector1, Darray const& dvector2)
{
    if(dvector1.size() != dvector2.size())
    {
        return false;
    }
    for(int i = 0; i < dvector1.size(); i++)
    {
        if(dvector1.m_double[i] != dvector2.m_double[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(Darray const& dvector1, Darray const& dvector2)
{
    return !(dvector1 == dvector2);
}

// Doivent avoir la meme taille :
Darray& Darray::operator+=(Darray const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] += dvector.m_double[i];
    }
    return *this;
}


/* Operateur d'ajout : */
Darray operator+(Darray const& dvector1, Darray const& dvector2)
{
    Darray tmpvector(dvector1);
    tmpvector += dvector2;
    return tmpvector;
}

Darray operator-(Darray const& dvector)
{
    return Darray(dvector.size(),0.)-dvector;
}

// doivent avoir la meme taille :
Darray& Darray::operator-=(Darray const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] -= dvector.m_double[i];
    }
    return *this;
}

/* Operateur d'ajout : */
Darray operator-(Darray const& dvector1, Darray const& dvector2)
{
    Darray tmpvector(dvector1);
    tmpvector -= dvector2;
    return tmpvector;
}

Darray& Darray::operator+=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] += dvector;
    }
    return *this;
}

Darray operator+(double const& dvector1, Darray const& dvector2)
{
    Darray dvector(dvector2);
    dvector += dvector1;
    return dvector;
}

Darray operator+(Darray const& dvector2, double const& dvector1)
{
    return dvector1 + dvector2;
}

Darray& Darray::operator-=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] -= dvector;
    }
    return *this;
}

Darray operator-(double const& dvector1, Darray const& dvector2)
{
    Darray dvector(dvector2.size(),dvector1);
    dvector -= dvector2;
    return dvector;
}

Darray operator-(Darray const& dvector2, double const& dvector1)
{
    return -(dvector1 - dvector2);
}

Darray& Darray::operator*=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] *= dvector;
    }
    return *this;
}

Darray operator*(double const& dvector1, Darray const& dvector2)
{
    Darray dvector(dvector2);
    dvector *= dvector1;
    return dvector;
}

Darray operator*(Darray const& dvector2, double const& dvector1)
{
    return dvector1 * dvector2;
}

Darray& Darray::operator/=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] /= dvector;
    }
    return *this;
}

Darray operator/(Darray const& dvector2, double const& dvector1)
{ 
    Darray dvector(dvector2);
    dvector /= dvector1;
    return dvector;
}

std::ostream& operator<<(std::ostream &flux, Darray const& dvector)
{
    int size = dvector.m_taille ;
    flux << "Vecteur de coodonnees : " ; 
    for (int i = 0 ; i < size ; i++){
	flux << dvector.m_double[i]<<std::endl ; 
    }
    return flux;
}

std::istream& operator>>(std::istream &flux, Darray & dvector){
    for (int i = 0 ; i < dvector.size() ; i++){
	flux >> dvector.m_double[i];
    }	
    return flux ;
}
/* Les methodes : */

/* Affichage du vecteur */
void Darray::display(std::ostream& str) const
{
    for(int i = 0; i < m_taille; i++)
    {
        str << m_double[i] << std::endl;
    }
}

/* Renvoi la taille du vecteur */
int Darray::size() const
{
    return m_taille;
}

/* Rempli le vecteur selon la loi uniforme sur [0,1] */
void Darray::fillRandomly()
{
    static bool init = false ;
    if (!init){
        init = true ; 
        srand(time(0)) ; 
    }
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = rand()/(double)RAND_MAX;
    }
}

void Darray::resize(int const& taille, double const& init)
{
    double *z_double(0);
    z_double = new double[taille];

    if(taille > m_taille)
    {
        memcpy(z_double,m_double,m_taille*sizeof(double));
        for(int i = m_taille; i < taille; i++)
        {
            z_double[i] = init;
        }
    }
    else
    {
        memcpy(z_double,m_double,taille*sizeof(double));
    }
    
    delete [] m_double;
    m_double = z_double;
    m_taille = taille;
}

/* Destructeur */
Darray::~Darray()
{
    std::cout << "Destruction du vecteur" << std::endl;
    delete [] m_double;
}
