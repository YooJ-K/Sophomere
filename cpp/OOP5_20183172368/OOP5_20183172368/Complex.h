#pragma once

class Complex {
private:
	double op1, op2, op3, op4, num;
	double a,b;
	static int count;
public:
	Complex();
	void setComplex(double r, double i);
	void Add(double r1, double r2, double i1, double i2);
	void Sub(double r1, double r2, double i1, double i2);
	void Print();
};