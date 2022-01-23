#include <iostream>
#include "DeskLamp.h"
using namespace std;

void DeskLamp::turnOn() {
	isOn = true;
}

void DeskLamp::turnOff() {
	isOn = false;
}

void DeskLamp::print() {
	if (isOn == true) {
		cout << "·¥ÇÁ°¡ ÄÑÁü" << endl;
	}
	else {
		cout << "·¥ÇÁ°¡ ²¨Áü" << endl;
	}
}
