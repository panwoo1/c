#include <iostream>

using namespace std;

class Box {
private:
	double width, length, height;
public:
	Box() : width(4.0), length(4.0), height(3.2) {}
	Box(double w, double l, double h) : width(w), length(l), height(h) {}
	double getVolume();
	void setWidth(double w);
	void setLength(double l);
	void setHeight(double h);
};

int main()
{
	double maxVolume;
	double width, length, height;
	cin >> width >> length >> height;

	Box Box1(3.4, 5.5, 5.0);
	Box Box2;
	Box Box3;
	Box3.setWidth(width);
	Box3.setLength(length);
	Box3.setHeight(height);

	maxVolume = Box1.getVolume();

	if (Box1.getVolume() < Box2.getVolume()) {
		maxVolume = Box2.getVolume();
		if (Box2.getVolume() < Box3.getVolume()) {
			maxVolume = Box3.getVolume();
		}
	}
	else if (Box1.getVolume() < Box3.getVolume()) {
		maxVolume = Box3.getVolume();
		if (Box3.getVolume() < Box2.getVolume()) {
			maxVolume = Box2.getVolume();
		}
	}
	cout << "최대 부피 = " << maxVolume << endl;

	return 0;
}


double Box::getVolume() {
	return width * length * height;
}
void Box::setWidth(double w) {
	width = w;
}
void Box::setLength(double l) {
	length = l;
}
void Box::setHeight(double h) {
	height = h;
}