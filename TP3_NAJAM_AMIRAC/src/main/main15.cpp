#include <iostream>
#include "Dvector.h"
#include <assert.h>


int main()
{
  Dvector vector2(4);
  std::cout<< "entrez les 4 coordonnees du vecteur";
  std::cin>>vector2;	
  std::cout<<vector2;
}
