#include <iostream>
#include<stdlib.h>
#include<time.h>
#include"car.h"
#include"DeskLamp.h"
using namespace std;

void q1() {
	Car car1, car2;
	srand(time(NULL));

	car1.init(rand() % 200, 1, "red");
	car1.show();

	car2.init(rand() % 200, 1, "yellow");
	car2.show();

	if (car1.getSpeed() > car2.getSpeed())
		cout << "car1�� �¸��Ͽ����ϴ�." << endl;
	else
		cout << "car2�� �¸��Ͽ����ϴ�." << endl;

	return;
}

void q2() {
	DeskLamp lamp;

	lamp.turnOn();
	lamp.print();
	lamp.turnOff();
	lamp.print();
	return;

}

int main() {
	cout << "1��" << endl;
	q1();
	cout << "============================" << endl;
	cout << "2��" << endl;
	q2();

	return 0;
}