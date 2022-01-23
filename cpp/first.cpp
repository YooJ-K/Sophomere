#include <iostream>
#include <cmath>
using namespace std;

double dist_2d(int x1, int y1, int x2, int y2) {
	double dist;

	dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);

	dist = sqrt(dist);

	return dist;
}

void quad_eqn(double a, double b, double c, double d) {
	double sum1, sum2;

	sum1 = ((-b) + sqrt(d)) / 2;
	sum2 = ((-b) - sqrt(d)) / 2;

	if (sum1 > sum2) {
		cout << "���� " << sum2 << "�� " << sum1 << "�Դϴ�.";
	}
	else {
		cout << "���� " << sum1 << "�� " << sum2 << "�Դϴ�.";
	}

	return;
}

void quad_equal(double a, double b, double c, double d) {
	double sum;

	sum = ((-b) + sqrt(d)) / 2;

	cout << "���� " << sum << "�Դϴ�.";

	return;
}

void p9() {
	int x1, x2, y1, y2;
	double dist;

	cin >> x1 >> y1 >> x2 >> y2;

	dist = dist_2d(x1, y1, x2, y2);

	cout << dist << endl;

	cout << "=============================================" << endl;

	return;
}

void p10() {
	double a, b, c, d;

	cout << "2�� �������� ����� �Է��Ͻÿ�." << endl << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	d = pow(b, 2) - 4 * a * c;

	if (d > 0) {
		quad_eqn(a, b, c, d);
	}
	else if (d == 0) {
		quad_equal(a, b, c, d);
	}
	else if (d < 0) {
		cout << "���� �����ϴ�." << endl;
	}

	return;
}

int main() {
	
	p9();
	p10();

	return 0;
}