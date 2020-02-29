#include <iomanip>
#include "CPP_MP.h"
using namespace std;


int main() {
	//testPolynomial();
	Function x("2*x^2 + 5*x");
	x.Derive();

	cout << x[5];
	cout << endl << endl;
	system("pause");
	return 0;
}