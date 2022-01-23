#include <string>

class Car {
private:
	int speed;
	int gear;
	std::string color;
public:
	void init(int s, int g, std::string c);
	void show();
	int getSpeed();
};