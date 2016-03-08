#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

/* Les Constructeurs : */

/* Initialisation d'un vecteur à partir d'un fichier se trouvant à str */
Dvector::Dvector(std::string const& str) : Darray(str)
{

}
/* Initialisation d'un vecteur à partir d'une taille et d'un argument facultatif */
/* Necessite que taille >= 0 */
Dvector::Dvector(int taille, double arg) : 	Darray(taille,arg)
{

}

/* Surcharge du constructeur de recopie */
Dvector::Dvector(Dvector const& dvector) : Darray(dvector)
{

}

/* [/!\] Doivent avoir la meme taille */
double operator*(Dvector const& dvector1, Dvector const& dvector2)
{
	double sum = 0.;
	for(int i = 0; i < dvector1.size(); i++)
	{
		sum += dvector1(i)*dvector2(i);
	}
	return sum;
}

/* Destructeur */
Dvector::~Dvector()
{
    std::cout << "Destruction du vecteur" << std::endl;
    delete [] m_double;
}
