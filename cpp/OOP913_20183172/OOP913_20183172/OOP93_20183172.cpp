#include "shape.h"
#include <iostream>
using namespace std;

Circle::Circle(int xl_, int xr_, int yt_, int yb_) {
	xl = xl_;
	xr = xr_;
	yt = yt_;
	yb = yb_;
}

void Circle::Draw() {
	cout << "** �� ��� ** �»�� : (" << xl << ", " << xr << ")" << " ";
	cout << "���ϴ� : (" << yt << ", " << yb << ")" << endl;
}

Line::Line(int xl_, int xr_, int yt_, int yb_) {
	xl = xl_;
	xr = xr_;
	yt = yt_;
	yb = yb_;
}

void Line::Draw() {
	cout << "** ���� ��� ** �»�� : (" << xl << ", " << xr << ")" << " ";
	cout << "���ϴ� : (" << yt << ", " << yb << ")" << endl;
}

Rectangle::Rectangle(int xl_, int xr_, int yt_, int yb_) {
	xl = xl_;
	xr = xr_;
	yt = yt_;
	yb = yb_;
}

void Rectangle::Draw() {
	cout << "** �簢�� ��� ** �»�� : (" << xl << ", " << xr << ")" << " ";
	cout << "���ϴ� : (" << yt << ", " << yb << ")" << endl;
}

Point::Point(int xl_, int xr_, int yt_, int yb_) {
	xl = xl_;
	xr = xr_;
	yt = yt_;
	yb = yb_;
}

void Point::Draw() {
	cout << "** ��ǥ ��� ** �»�� : (" << xl << ", " << xr << ")" << " ";
	cout << "���ϴ� : (" << yt << ", " << yb << ")" << endl;
}