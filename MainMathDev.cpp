#include "CPP_MP.h"
using namespace std;
using namespace Math;


int main() {
	Complex test(2,3),B(4,-5),C(0,1);
	test / B;
	
	Math::Cycle<double> cyc(vector<double>({ 1.2, 2.5, 3.7 }));
	double x;
	for (int i = 0; i < 10; i++) {
		cyc(x);
		cout << x << endl;
	}
	
	//cout << Factorial(5);
	cout << endl << endl;
	system("pause");
	return 0;
}