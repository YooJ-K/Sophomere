#pragma once
class Box {
private:
	int height, width, volume;
public:
	Box() {
		height = 0;
		width = 0;
		volume = 0;
	}
	Box(int height_, int width_);
	int getVolume();
	bool empty();
};