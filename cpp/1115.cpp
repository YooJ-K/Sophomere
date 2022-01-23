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

Vector& Vector::operator--(int) {//����������
   x -= 1;
   y -= 1;
   return *this;
}

Vector& Vector::operator--() {//����������
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
	Student(char* _name="����", char* _job = "����"){
	name =  _name;
	job = _job;
	}
	
	Student(Student& A){
		A.name = this->name;
		A.job = this->job;
	}	
		
	friend Student& operator+(Student& a, Student& b);
	friend ostream& operator<<(ostream& os, const Student& A);
};

ostream& operator<<(ostream& os, const Student& A) {

   cout << A.name << A.job << endl;
   return os;
}

Student& operator+(Student& a, Student& b){
	strcat(a.name, b.name);
	strcat(a.job, b.job);
	
	return a;
}


void Fn10_2() {
   Student a("ö��", "�л�"), b("����", "����"), c, d = a;
	
   c = b;
   cout << c;

   //c = a + b;
   cout << c;

   //c = c - a; //job�� ����
   cout << c;
}

int main(){
	Fn10_2();
	
	return 0;
}
