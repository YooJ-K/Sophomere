#include <iostream>
#include <string.h>
using namespace std;

class Vector {
	int x, y;
public:
	Vector(int xx = 0, int yy = 0) {
		x = xx; y = yy;
	}

	Vector operator-(Vector& i);
	Vector& operator+(Vector& i);
	Vector& operator--(int);
	Vector& operator--();
	Vector& operator+=(const Vector& v2);
	Vector& operator-=(const Vector& v2);

	friend ostream& operator<<(ostream& os, const Vector& v);
};

Vector Vector::operator-(Vector& i) {
	Vector v;
	v.x = this->x - i.x;
	v.y = this->y - i.y;

	return v;
}

Vector& Vector::operator+(Vector& i) {
	Vector v;
	v.x = this->x + i.x;
	v.y = this->y + i.y;

	return v;
}

Vector& Vector::operator--(int) {//후위연산자
	x -= 1;
	y -= 1;
	return *this;
}

Vector& Vector::operator--() {//전위연산자
	x -= 1;
	y -= 1;
	return*this;
}

Vector& Vector::operator+=(const Vector& v2) {

	this->x += v2.x;
	this->y += v2.y;

	return *this;
}

Vector& Vector::operator-=(const Vector& v2) {

	this->x -= v2.x;
	this->y -= v2.y;

	return *this;
}

ostream& operator<<(ostream& os, const Vector& v) {

	cout << "(" << v.x << ", " << v.y << ")";
	return os;
}

void Fn10_1() {
	Vector a(1, 2), b(2, 3), c;

	c = a - b;
	cout << "c = a - b : " << a << " , " << b << " , " << c << endl;
	a += b;
	cout << "a += b : " << a << " , " << b << " , " << c << endl;
	a -= c;
	cout << "a -= c : " << a << " , " << b << " , " << c << endl;
	cout << "--a : " << --a << endl;
	cout << "a-- : " << a-- << endl;
}

class Student {
	char* name;
	char* job;
public:
	Student() {}

	Student(const char *n, const char* j) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);

		job = new char[strlen(j) + 1];
		strcpy(job, j);
	}

	Student(const Student& obj) {
		name = obj.name;
		job = obj.job;
	}

	~Student() {
		delete name;
		delete job;
	}

	Student operator+(const Student& obj) {
		int s1 = strlen(name), s2 = strlen(obj.name);
		char* s = new char[s1 + s2 + 1];

		for (int i = 0; i < s1; i++)
			s[i] = name[i];

		for (int i = s1; i < (s1 + s2); i++)
			s[i] = obj.name[i];

		delete s;

		s1 = strlen(job);
		s2 = strlen(obj.job);

		s = new char[s1 + s2 + 1];

		for (int i = 0; i < s1; i++)
			s[i] = job[i];

		for (int i = s1; i < (s1 + s2); i++)
			s[i] = obj.job[i];

		delete s;

		return *this;
	}

	friend ostream& operator<<(ostream& os, const Student& obj);
};

ostream& operator<<(ostream& os, const Student& obj) {

	cout << "이름 : " << obj.name << " 직업 : " << obj.job << endl;
	return os;
}



void Fn10_2() {
	Student a("철수", "학생"), b("순이", "사장"), c, d = a;

	c = b;
	cout << c;

	c = a + b;
	cout << c;

	//c = c - a; //job만 삭제
	cout << c;
}

int main() {
	//Fn10_1();
	Fn10_2();
}