#include <iostream>
using namespace std;

class Car {
	int speed, num;
	char* color;

public:

	Car() {
		cout << "default ������" << endl;

	}
	Car(int s, int n = 1, const char* c ="black") {
		cout << "������" << endl;
	}

	Car(const Car& p) {
		this->speed = p.speed;
		cout << "����" << endl;
	}

	int GetSpeed() {
		return speed;
	}
};

int main() {
	Car c[4];

	Car* p = c;

	p[0] = c[0];

}