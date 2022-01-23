#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int number; // �й�

public:
	Student(string n, int nb) : name(n), number(nb){}
	string getName() {
		return name;
	}
	int getNumber() {
		return number;
	}
};

void Add(list<Student> &s) {
	string name;
	int number;

	cout << "�̸� : ";
	cin >> name;
	
	cout << "�й� : ";
	cin >> number;

	Student newStu(name, number);

	s.push_back(newStu);

	cout << endl;

}

void Search(list<Student> &s) {

	string searchName;
	bool search_ = false;

	cout << "ã�� �̸� : ";
	cin >> searchName;

	cout << endl;

	list<Student>::iterator it;
	for (it = s.begin(); it != s.end(); ++it) {

		if (it->getName() == searchName) {
			search_ = true;
			cout << "�̸� : " << it->getName() << endl;
			cout << "�й� : " << it->getNumber() << endl << endl;
			break;
		}
	}

	if (search_ == false) {
		cout << "ã�� �л��� �����ϴ�." << endl << endl;
	}
}

void Delete(list<Student> &s) {
	string delName;
	bool del_ = false;

	cout << "���� �� �̸� : ";
	cin >> delName;

	cout << endl;

	list<Student>::iterator it;
	for (it = s.begin(); it != s.end(); ++it) {

		if (it->getName() == delName) {
			del_ = true;

			s.erase(it);
			
			cout << "���� �Ϸ�!" << endl << endl;
			break;
		}
	}

	if (del_ == false) {
		cout << "�ش� �л��� �����ϴ�." << endl << endl;
	}
}

void PrintAll(list<Student> &s) {

	list<Student>::iterator it;

	cout << endl;

	for (it = s.begin(); it != s.end(); ++it) {
		cout << "�̸� : " << it->getName() << endl;
		cout << "�й� : " << it->getNumber() << endl << endl;

	}

}

int main(void) {
	list<Student> s;
	int sel;
	s.push_back(Student("a", 1));
	s.push_back(Student("b", 2));
	s.push_back(Student("c", 3));

	while (1) {
		cout << "1, �л����� �߰� 2, �л����� �˻� 3, �л����� ���� 4, �л����� ��� 5,EXIT" << endl;
		cout << ">>";

		cin >> sel;

		if (sel == 1) Add(s);
		else if (sel == 2) Search(s);
		else if (sel == 3) Delete(s);
		else if (sel == 4) PrintAll(s);
		else if (sel == 5) return 0;
	}
	return 0;
}