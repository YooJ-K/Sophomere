#include <iostream>
#include"car.h"
using namespace std;

void Car::init(int s, int g, string c) {
	speed = s;
	gear = g;
	color = c;
}

void Car::show() {
	cout << "속도 : " << speed << endl;
	cout << "기어 : " << gear << endl;
	cout << "색상 : " << color << endl;
	cout << "============================" << endl;
}

int Car::getSpeed() {
	return speed;

}

