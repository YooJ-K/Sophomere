#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex() {
	op1 = 0;
	op2 = 0;
	op3 = 0;
	op4 = 0;
	num = 0;
}

void Complex::setComplex(double r, double i) {
	a = r;
	b = i;
	num = 1;
}

void Complex::Add(double r1, double r2, double i1, double i2) {
	op1 = r1 + r2;
	op2 = i1 + i2;
	num = 2;
}

void Complex::Sub(double r1, double r2, double i1, double i2) {
	op3 = r1 - r2;
	op4 = i1 - i2;
	num = 3;
}

void Complex::Print() {
	if (num == 1) {
		cout << a << " + " << b << "i" << endl;
	}
	else if (num == 2) {
		cout << op1 << " + " << op2 << "i" << endl;
	}
	else if (num == 3) {
		cout << op3 << " + " << op4 << "i" << endl;
	}
}

