#include <iostream>
#define PI 3.141592

using namespace std;

class Circle {
private:
	double radius;
public:
	void setRadius(double r);
	double getArea();
};

int main()
{
	int n = 0, count = 0;
	cin >> n;

	Circle* C = new Circle[n];

	for (int i = 0; i < n; i++) {
		double radius;
		cin >> radius;
		C[i].setRadius(radius);
	}
	for (int i = 0; i < n; i++) {
		if (C[i].getArea() > 100)
			count++;
	}
	cout << "넓이가 100이 넘는 원의 개수 = " << count << endl;

	delete[]C;

	return 0;
}

void Circle::setRadius(double r) {
	radius = r;
}
	
double Circle::getArea() {
	return radius * radius * PI;
}
