#include "CPP_MP.h"
using namespace std;


int main() {
	Function x("cos(1*x) + 2*x"),y;
	x.Derive();
	cout << x;

	cout << endl << endl;
	system("pause");
	return 0;
}