#include <iomanip>
#include "CPP_MP.h"
using namespace std;


int main() {
	//testPolynomial();
	//Function x("cos(1*x) + 2*x"),y;
	Monomial x("5*cos(2*x)");
	x.Derive();
	cout << x;

	cout << endl << endl;
	system("pause");
	return 0;
}