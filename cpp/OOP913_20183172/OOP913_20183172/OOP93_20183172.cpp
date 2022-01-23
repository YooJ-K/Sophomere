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
	cout << "** 원 출력 ** 좌상단 : (" << xl << ", " << xr << ")" << " ";
	cout << "우하단 : (" << yt << ", " << yb << ")" << endl;
}

Line::Line(int xl_, int xr_, int yt_, int yb_) {
	xl = xl_;
	xr = xr_;
	yt = yt_;
	yb = yb_;
}

void Line::Draw() {
	cout << "** 직선 출력 ** 좌상단 : (" << xl << ", " << xr << ")" << " ";
	cout << "우하단 : (" << yt << ", " << yb << ")" << endl;
}

Rectangle::Rectangle(int xl_, int xr_, int yt_, int yb_) {
	xl = xl_;
	xr = xr_;
	yt = yt_;
	yb = yb_;
}

void Rectangle::Draw() {
	cout << "** 사각형 출력 ** 좌상단 : (" << xl << ", " << xr << ")" << " ";
	cout << "우하단 : (" << yt << ", " << yb << ")" << endl;
}

Point::Point(int xl_, int xr_, int yt_, int yb_) {
	xl = xl_;
	xr = xr_;
	yt = yt_;
	yb = yb_;
}

void Point::Draw() {
	cout << "** 좌표 출력 ** 좌상단 : (" << xl << ", " << xr << ")" << " ";
	cout << "우하단 : (" << yt << ", " << yb << ")" << endl;
}