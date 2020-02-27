#include <iomanip>
#include "CPP_MP.h"
using namespace std;

//void testPolynomial() {
//	Polynomial p;
//	p.print(); cout << endl;
//	p.add(one);
//	p.print(); cout << endl;
//	cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 5
//	p.add(Monomial(1, 2));
//	p.print(); cout << endl;
//	cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 6
//	p.add(Monomial(-1, 2));
//	p.print(); cout << endl;
//	cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 5
//}


int main() {
	//testPolynomial();
	Monomial x(2, 1), xsquare(3, 2), m23(2, 3);
	x ^ 5;
	cout << x;
	
	cout << endl << endl;
	system("pause");
	return 0;
}