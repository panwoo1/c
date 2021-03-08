#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	bool flag = true;
	cout << flag << endl;

	cout.setf(ios_base::boolalpha);
	cout << flag << endl;

	int c = 100;
	cout.width(10);
	cout << c << endl;

	float f1 = 12.3456;
	cout.precision(4);
	cout << f1;

	return 0;
}