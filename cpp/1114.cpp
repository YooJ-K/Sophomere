#include <iostream>
#include <string>
using namespace std;

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


		return *this;
	}

	friend ostream& operator<<(ostream& os, const Student& obj);
};
