#include <iostream>
#include "Dice.h"
#include "Complex.h"
#include "BankAccount.h"
#include <time.h>
using namespace std;

void q3() {
	Dice D1;
	srand(time(NULL));

	cout << "3��" << endl;

	for (int i = 0; i < 10; i++) {
		D1.roll();
		cout << "�ֻ����� ���ڴ� " << D1.getFace() << "�Դϴ�" << endl;
	}
}

void q6() {
	Complex c1, c2, c3;
	double r1, i1, r2, i2;

	cout << "1��° �Ǽ��ο� ����θ� �Է��ϼ��� : ";
	cin >> r1 >> i1;

	cout << "2��° �Ǽ��ο� ����θ� �Է��ϼ��� : ";
	cin >> r2 >> i2;

	cout << "==========================================" << endl;

	c1.setComplex(r1, i1);
	cout << "���Ҽ��� : ";
	c1.Print();

	c2.setComplex(r2, i2);
	cout << "���Ҽ��� : ";
	c2.Print();

	c3.Add(r1, r2, i1, i2);
	cout << "���� : ";
	c3.Print();

	c3.Sub(r1, r2, i1, i2);
	cout << "���� : ";
	c3.Print();

	cout << "==========================================" << endl;

	return;
}

void q8() {
	BankAccount a, b;

	cout << "8��" << endl;

	a.setBalance(0);
	b.setBalance(0);

	a.deposit(100000);
	b.deposit(1000);
	cout << "���� a�� �ܾ��� >> ";
	a.print();
	cout << "���� b�� �ܾ��� >> ";
	b.print();

	cout << "���� a�� �ܾ��� >> ";
	a.withdraw(8000);
	a.print();

	cout << "->a���� 2000���� b�� ��ü" << endl;
	a.transfer(b, 2000);
	cout << "���� a �ܾ��� : ";
	a.print();

	return;

}

int main() {

	//q3();
	q6();
	//q8();
	return 0;
}