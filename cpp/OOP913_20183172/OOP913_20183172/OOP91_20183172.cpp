#include "Gate.h"
#include <iostream>
using namespace std;

ANDGate::ANDGate() {
	x = y = z = false;
}

void ANDGate::inputSet(bool xx, bool yy) {
	x = xx;
	y = yy;
	cout << "AND input : " << (int)x << " " << (int)y << " -> ";
}

void ANDGate::op() {
	if (x && y) z = true;
	else z = false;
	cout << (int)z << endl;
}

ORGate::ORGate() {
	x = y = z = false;
}

void ORGate::inputSet(bool xx, bool yy) {
	x = xx;
	y = yy;

	cout << "OR input : " << (int)x << " " << (int)y << " -> ";
}

void ORGate::op() {
	if (x || y) z = true;
	else z = false;
	cout << (int)z << endl;
}

XORGate::XORGate() {
	x = y = z = false;
}

void XORGate::inputSet(bool xx, bool yy) {
	x = xx;
	y = yy;
	cout << "XOR input : " << (int)x << " " << (int)y << " -> ";
}

void XORGate::op() {
	if (x != y) z = true;
	else z = false;
	cout << (int)z << endl;
}