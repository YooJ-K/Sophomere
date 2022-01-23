#include "Gate.h"
#include "shape.h"

void m91() {
	ANDGate and_gate;
	ORGate or_gate;
	XORGate xor_gate;

	and_gate.inputSet(true, false);
	and_gate.op();
	and_gate.inputSet(true, true);
	and_gate.op();

	or_gate.inputSet(true, false);
	or_gate.op();
	or_gate.inputSet(true, true);
	or_gate.op();

	xor_gate.inputSet(true, false);
	xor_gate.op();
	xor_gate.inputSet(true, true);
	xor_gate.op();
}

void m93() {
	Circle a(1, 1, 5, 5); // �»����, ���ϴ��� ��ǥ
	Line b(5, 5, 9, 9); // �»����, ���ϴ��� ��ǥ
	Shape *p;
	a.Draw(); // ���� ��¡� �»��/���ϴ��� ��ǥ ���
	b.Draw(); // ������ ��¡� �»��/���ϴ��� ��ǥ ���
	p = new Line(10, 10, 100, 100);
	p->Draw();
	p = new Circle(100, 100, 200, 200);
	p->Draw();
	delete p;
}

int main() {
	m91();
	m93();
}