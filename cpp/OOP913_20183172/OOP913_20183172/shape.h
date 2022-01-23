#pragma once

class Shape {
protected:
	int xl, xr, yt, yb;
public:
	void virtual Draw() {}
};

class Circle : public Shape {
	int xl, xr, yt, yb;
public:
	Circle(int xl_, int xr_, int yt_, int yb_);
	void Draw();
};

class Line : public Shape {
	int xl, xr, yt, yb;
public:
	Line(int xl_, int xr_, int yt_, int yb_);
	void Draw();
};

class Rectangle : public  Shape {
	int xl, xr, yt, yb;
public:
	Rectangle(int xl_, int xr_, int yt_, int yb_);
	void Draw();
};

class Point : public Shape {
	int xl, xr, yt, yb;
public:
	Point(int xl_, int xr_, int yt_, int yb_);
	void Draw();
};