#include <iostream>
#include"car.h"
using namespace std;

void Car::init(int s, int g, string c) {
	speed = s;
	gear = g;
	color = c;
}

void Car::show() {
	cout << "�ӵ� : " << speed << endl;
	cout << "��� : " << gear << endl;
	cout << "���� : " << color << endl;
	cout << "============================" << endl;
}

int Car::getSpeed() {
	return speed;

}

