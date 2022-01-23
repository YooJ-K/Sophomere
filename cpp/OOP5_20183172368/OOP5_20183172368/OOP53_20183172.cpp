#include <iostream>
#include "Dice.h"

void Dice::roll() {

	face = (int)(rand() % 6 + 1);
	return;
}

int Dice::getFace() {
	return face;
}