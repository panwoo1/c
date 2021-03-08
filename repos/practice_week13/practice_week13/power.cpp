#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
//	Power operator+(Power& p);
	friend  Power operator+=(Power& p1, Power& p2);
	friend Power operator +(Power& p1, Power& p2);
};

void Power::show() {
	cout << "kick= " << kick << ',' << "punch= " << punch << endl;
}

/*Power Power::operator+(Power& p){
	this->kick += p.kick;
	this->punch += p.punch;

	return *this;
}*/
Power  operator+=(Power& p1, Power& p2) {
	p1.kick += p2.kick;
	p1.punch += p2.punch;

	return p1;
}
Power operator +(Power& p1, Power& p2) {
	Power p;
	p.kick = p1.kick + p2.kick;
	p.punch = p1.punch + p2.punch;

	return p;
}
int main() {
	Power A(3, 5);
	Power B(4, 6);

	A.show();
	B.show();
	(A + B).show();
	//(A += B).show();
	//(A+B).show();
}