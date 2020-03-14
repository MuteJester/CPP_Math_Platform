#include "CPP_MP.h"
using namespace std;
using namespace Math;


int main() {
	vector < vector<int> > result;
	Point<double> PA(3, 4), PB(-2, 3);
	Function g("1*x^0 + 45*x^1 + 504*x^2 + 2489*x^3 + 6468*x^4 + 9860*x^5 + 9608*x^6 + 6027*x^7 + 2331*x^8 + 506*x^9 + 48*x^10");
	Function q("1*x^0 + 10*x^1 + 36*x^2 + 84*x^3 + 126*x^4 + 126*x^5 + 84*x^6 + 36*x^7 + 9*x^8 + 1*x^9");
	Function z("1*x^3 - 9*x^2 + 1*x^0");
	//cout << z;
	Point<double> p(1, 1, 1);
	cout << 
	//cout << "Result: ";

	//cout << Factorial(5);
	cout << endl << endl;
	system("pause");
	return 0;
}