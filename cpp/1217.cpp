#include <iostream>
using namespace std;

class Vector {
	int x, y;
public:
	Vector(int xx, int yy);
	Vector& operator*(int a);
	friend Vector operator*(int a, Vector& s);
	friend ostream& operator<<(ostream& os, Vector& k);
};

Vector::Vector(int xx, int yy) {
	x = xx;
	y = yy;
}


Vector Vector::operator*(int a) {
	x *= a;
	y *= a;

	return Vector(s.x, s.y);

}

Vector operator*(int a, Vector& s) {
	s.x *= a;
	s.y *= a;

	return Vector(s.x, s.y);
}

ostream& operator<<(ostream& os, Vector& k) {
	os << k.x << " " << k.y << endl;

	return os;
}


int main() {
	Vector x(1, 1);
	Vector y = x * 2;
	Vector z = 2 * x;

	cout << x<<y << z;
}