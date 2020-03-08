#include "CPP_MP.h"
using namespace std;
using namespace Math;


int main() {
	vector < vector<int> > result;
	Point<double> PA(3, 4), PB(-2, 3);
	double a, b;
	cout << Angle_Between_Points(PA, PB) << endl;
	
	//cout << Factorial(5);
	cout << endl << endl;
	system("pause");
	return 0;
}