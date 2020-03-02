#include "CPP_MP.h"
using namespace std;


int main() {
	vector<int> test{ 26, 33, 65, 28, 34, 55, 25, 44, 50, 36, 26, 37, 43, 62, 35, 38, 45, 32, 28, 34 };
	vector<double> rnd = Random_DOUBLE_Vector(10,-1.0,1.0); 

	//cout << rnd << endl;
	//cout << Random_DOUBLE(4);

	cout << endl << endl;
	system("pause");
	return 0;
}