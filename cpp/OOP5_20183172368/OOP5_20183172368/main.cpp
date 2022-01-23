#include <iostream>
#include "Dice.h"
#include "Complex.h"
#include "BankAccount.h"
#include <time.h>
using namespace std;

void q3() {
	Dice D1;
	srand(time(NULL));

	cout << "3번" << endl;

	for (int i = 0; i < 10; i++) {
		D1.roll();
		cout << "주사위의 숫자는 " << D1.getFace() << "입니다" << endl;
	}
}

void q6() {
	Complex c1, c2, c3;
	double r1, i1, r2, i2;

	cout << "1번째 실수부와 허수부를 입력하세요 : ";
	cin >> r1 >> i1;

	cout << "2번째 실수부와 허수부를 입력하세요 : ";
	cin >> r2 >> i2;

	cout << "==========================================" << endl;

	c1.setComplex(r1, i1);
	cout << "복소수는 : ";
	c1.Print();

	c2.setComplex(r2, i2);
	cout << "복소수는 : ";
	c2.Print();

	c3.Add(r1, r2, i1, i2);
	cout << "합은 : ";
	c3.Print();

	c3.Sub(r1, r2, i1, i2);
	cout << "차는 : ";
	c3.Print();

	cout << "==========================================" << endl;

	return;
}

void q8() {
	BankAccount a, b;

	cout << "8번" << endl;

	a.setBalance(0);
	b.setBalance(0);

	a.deposit(100000);
	b.deposit(1000);
	cout << "계좌 a의 잔액은 >> ";
	a.print();
	cout << "계좌 b의 잔액은 >> ";
	b.print();

	cout << "계좌 a의 잔액은 >> ";
	a.withdraw(8000);
	a.print();

	cout << "->a에서 2000원을 b로 이체" << endl;
	a.transfer(b, 2000);
	cout << "계좌 a 잔액은 : ";
	a.print();

	return;

}

int main() {

	//q3();
	q6();
	//q8();
	return 0;
}