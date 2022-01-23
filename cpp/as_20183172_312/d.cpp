#include <iostream>
#include <string.h>
using namespace std;

class Student {
	char* name;
	char* job;
public:
	Student() {}

	Student(const char *n, const char* j){
		name = new char[strlen(n) + 1];
		strcpy(name, n);

		job = new char[strlen(j) + 1];
		strcpy(job, j);
	}

	Student(const Student& obj) {
		name = obj.name;
		job = obj.job;
	}

	~Student(){
		delete name;
		delete job;
	}

	Student operator+(const Student& obj1, const Student& obj2) {
		
		
		
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Student& obj);
};

ostream& operator<<(ostream& os, const Student& obj) {

	cout << "이름 : " << obj.name << " 직업 : " << obj.job << endl;
	return os;
}

void Fn10_2() {
	Student a("철수", "학생"), b("순이", "사장"), c, d=a;

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
