#include <iostream>
#include <vector>

using namespace std;

class  Point {
private:
	int x, y;
public:
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};

class Polygon {
private:
	vector <Point> points;
public:
	int countConcave(int n);
	float perimeter(int n);
	float area(int n);
	void getpoints(int n);
	void set_vector_size(int n);
};
int ccw(Point P1, Point P2, Point P3);
float dist(Point p, Point q);

int main()
{
	int n, concave;
	float perimeter, area;
	cin >> n;
	Polygon p;
	p.set_vector_size(n);
	p.getpoints(n);
	concave = p.countConcave(n);
	perimeter = p.perimeter(n);
	area = p.area(n);

	cout << concave << endl;
	cout << fixed;
	cout.precision(1);
	cout << perimeter << endl;
	cout << area << endl;
}
void Point::setX(int num) 
{
	x = num;
}
void Point::setY(int num)
{
	y = num;
}
int Point::getX() 
{
	return x;
}
int Point::getY() 
{
	return y;
}
int Polygon::countConcave(int n)
{
	int* result = new int [n];
	int  count = 0, count_1 = 0, count_2 = 0;
	for (int i = 0; i < n; i++) {
		if (i + 2 == n) {
			points[i + 2].setX(points[i + 2 - n].getX());
			points[i + 2].setY(points[i + 2 - n].getY());
		}
		if (i + 1 == n) {
			points[i + 1].setX(points[i + 1 - n].getX());
			points[i + 1].setY(points[i + 1 - n].getY());
		
			if (i + 2 == n + 1) {
				points[i + 2].setX(points[i + 2 - n].getX());
				points[i + 2].setY(points[i + 2 - n].getY());
			}
		}
		result[i] = ccw(points[i], points[i + 1], points[i + 2]);
	}
	for (int i = 0; i < n - 1; i++) {
		if (result[i] == 1) {
			count_1++;
		}
		else if (result[i] == -1) {
			count_2++;
		}
	}
	if (count_1 < count_2) {
		count = count_1;
	}
	else if (count_1 > count_2) {
		count = count_2;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			if (result[i] == 1 && result[i + 1] == -1) {
				count++;
			}
			if (i == n - 2 && result[i] == -1 && result[i + 1] == 1) {
				count++;
			}
		}
	}
	return count;
}
float Polygon::perimeter(int n)
{
	float length = 0;
	for (int i = 1; i < n; i++) {
		length += dist(points[i-1], points[i]);
	}
	length += dist(points[0], points[n - 1]);
	return length;
}
float Polygon::area(int n)
{
	float area;
	float result_sum=0, result_distance=0, result=0;
	for (int i = 1; i < n; i++) {
		result_sum += points[i-1].getX()* points[i].getY();
	}
	result_sum += points[n - 1].getX() * points[0].getY();
	for (int i = 1; i < n; i++) {
		result_distance += points[i].getX()* points[i - 1].getY();
	}
	result_distance += points[0].getX() * points[n - 1].getY();
	result = result_sum - result_distance;
	
	area = result/2;
	if (area < 0) {
		area = -area;
	}

	return area;
}
void Polygon :: getpoints(int n)
{
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points[i].setX(x);
		points[i].setY(y);
	}
}
int ccw(Point P1, Point P2, Point P3)
{
	int S;

	S = (P2.getX() - P1.getX()) * (P3.getY() - P1.getY()) - (P2.getY() - P1.getY()) * (P3.getX() - P1.getX());

	if (S > 0)
		return 1;
	else if (S < 0)
		return -1;
	else
		return 0;
}
float dist(Point p, Point q)
{
	return sqrt((p.getX() - q.getX()) * (p.getX() - q.getX()) + (p.getY() - q.getY()) * (p.getY() - q.getY()));
}
void Polygon ::set_vector_size(int n)
{
	points.resize(n+2);
}