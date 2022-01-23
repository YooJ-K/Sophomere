#include <iostream>
#include "FruitSeller.h"
#include "FruitBuyer.h"
using namespace std;

FruitSeller::FruitSeller(int price_, int number_, int money_) {
	price = price_;
	number = number_;
	money = money_;
}

void FruitSeller::ShowSalesResult() {
	cout << "���� ��� : " << number << endl;
	cout << "�Ǹ� ���� : " << price << endl;
}

FruitBuyer::FruitBuyer(int myM_) {
	myM = myM_;
}

void FruitBuyer::BuyApples(FruitSeller &s, int a) {

	many = a / s.price;
	s.price += a;
	s.number -= many;
	myM -= a;

}

void FruitBuyer::ShowBuyResult() {
	cout << "���� �ܾ� : " << myM << endl;
	cout << "��� ���� : " << many << endl;
}