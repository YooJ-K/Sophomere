#include <iostream>
#include <string>
using namespace std;

class STAFF {
	string name;
	bool isFull;
	int *salary;

public:
	STAFF(string n, bool i, int *s) :name(n), isFull(i) {	
		salary = new int();
		*salary 
	}
	void display() {
		cout << name << isFull << salary;
	}
};

class FullTime :STAFF {
	int bonus;
public:
	FullTime(string n, bool i, int s, int b) :STAFF(n, i, s), bonus(b) {}
	void displayF() {
		display();
		cout << bonus << endl;
	}
};

int main() {
	FullTime a("±èÃ¶¼ö", 1, 200, 120);
	//PartTime b("±èÇöºó", 0, 150);

	a.displayF();

	return 0;
}