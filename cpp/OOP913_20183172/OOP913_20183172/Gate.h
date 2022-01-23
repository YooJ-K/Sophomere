#pragma once
class Gate {
protected:
	bool x, y, z;
public:
	virtual void inputSet() {}
	virtual void op() {}
};

class ANDGate : Gate {
public:
	ANDGate();
	void inputSet(bool xx, bool yy);
	void op();
};

class ORGate : Gate {
public:
	ORGate();
	void inputSet(bool xx, bool yy);
	void op();
};

class XORGate : Gate {
public:
	XORGate();
	void inputSet(bool xx, bool yy);
	void op();
};