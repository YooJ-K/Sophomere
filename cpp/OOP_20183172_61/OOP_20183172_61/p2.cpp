#include "Box.h"
#include <iostream>
using namespace std;

Box::Box(int height_, int width_) {
	height = height_;
	width = width_;
	cout << "���� : " << height << " �ʺ� : " << width<<endl;
}

int Box::getVolume() {
	volume = height * width;
	return volume;
}

bool Box::empty() {
	if (volume == 0) return true;
	else return false;
}