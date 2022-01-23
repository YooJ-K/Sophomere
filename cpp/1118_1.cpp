#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Vector {
	int x, y;
public:
	Vector(int xx = 0, int yy = 0) {
		x = xx; y = yy;
	}

	Vector& operator-(Vector& i);
	Vector& operator+(Vector& i);
	Vector& operator--(int);
	Vector& operator--();
	Vector& operator+=(const Vector& v2);
	Vector& operator-=(const Vector& v2);

	friend ostream& operator<<(ostream& os, const Vector& v);
};

Vector& Vector::operator-(Vector& i) {
	
	x = x - i.x;
	y = y - i.y;

	return *this;
}

Vector& Vector::operator+(Vector& i) {
	x = x + i.x;
	y = y + i.y;

	return *this;
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

	x += v2.x;
	y += v2.y;

	return *this;
}

Vector& Vector::operator-=(const Vector& v2) {

	x -= v2.x;
	y -= v2.y;

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
	Student() {
		name = new char[1];
		job = new char[1];

		name[0] = NULL;
		job[0] = NULL;
	}

	Student(const char* n, const char* j) {

		name = new char[strlen(n) + 1];
		job = new char[strlen(j) + 1];

		strcpy(name, n);
		strcpy(job, j);
	}

	Student(Student& A) {//B=A

		name = new char[strlen(A.name) + 1];
		job = new char[strlen(A.job) + 1];

		strcpy(name, A.name);
		strcpy(job, A.job);
	}

	~Student() {
		if (name) {
			delete[] this->name;
		}

		if (job) {
			delete[] this->job;
		}
	}

	Student& operator=(const Student& A) {
		delete[] this->name;
		delete[] this->job;

		name = new char[strlen(A.name) + 1];
		job = new char[strlen(A.job) + 1];

		strcpy(name, A.name);
		strcpy(job, A.job);

		return *this;
	}

	friend ostream& operator<<(ostream& os, const Student& A);
	friend Student& operator+(Student& A, Student& B);
};



Student& operator+(Student& A, Student& B) {
	Student C;

	C.name = new char[strlen(A.name) + strlen(B.name) + 1];
	C.job = new char[strlen(A.job) + strlen(B.job) + 1];

	strcpy(C.name, A.name);
	strcpy(C.job, A.job);

	strcat(C.name, B.name);
	strcat(C.job, B.job);

	return C;
}

ostream& operator<<(ostream& os, const Student& A) {

	os << A.name << A.job << endl;

	return os;
}


void Fn10_2() {
	Student a("철수", "학생"), b("순이", "사장"), c, d = a;

	c = b; // = 연산자
	cout << c;

	c = a + b;
	cout << c;

	cout << a;

	//c = c - a; //job만 삭제
	//cout << c;

	return;
}

int main() {
	//Fn10_1();
	Fn10_2();

	return 0;
}
