// Construction du maillage : 

#include "Maillage.h"
#include "Triangle.h"
#include <vector>

using namespace std;

int main()
{
	Point<double> a(5.,6.);
	Point<double> b(7.,6.);
	Point<double> c(8.,4.);
	Triangle<double> tri(a,b,c);
	Maillage<double,vector> maille(5,5,a);
	return 0;
}