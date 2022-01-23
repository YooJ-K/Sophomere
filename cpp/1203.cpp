#include <iostream>
using namespace std;

class Point {
public:
	int x, y;

	void input() {
		cin >> x >> y;
	}

	double rr(Point& obj) {//����
		return (y - obj.y) / (x - obj.x);
	}

};

int main() {
	Point A1, A2, B1, B2;
	double m1, m2, distance[8];

	cout << "A ������ �� ���� ��ǥ�� �Է��ϼ��� : ";
	A1.input();
	A2.input();

	cout << "B ������ �� ���� ��ǥ�� �Է��ϼ��� : ";
	B1.input();
	B2.input();

	int count = 0;
	static int l;

	if (A1.x == B1.x && A1.y == B1.y) {
		count++;
		l = 1;
	}
	if (A1.x == B2.x && A1.y == B2.y) {
		count++;
		l = 2;
	}
	if (A2.x == B1.x && A2.y == B1.y) {
		count++;
		l = 3;
	}
	if (A2.x == B2.x &&A2.y == B2.y) {
		count++;
		l = 4;
	}

	if (count == 2) {
		cout << "������ ��ġ�մϴ�." << endl;
		return 0;
	}

	else if (count == 1) {
		cout << "������ ��ǥ : ";
		if (l == 1) cout << A1.x << ", " << A1.y << " " << B1.x << ", " << B1.y;
		else if(l==2) cout << A1.x << ", " << A1.y << " " << B2.x << ", " << B2.y;
		else if(l==3) cout << A2.x << ", " << A2.y << " " << B1.x << ", " << B1.y;
		else cout << A2.x << ", " << A2.y << " " << B2.x << ", " << B2.y;
		cout << endl;
		return 0;
	}

	else if (count > 2) {
		cout << "��ǥ�� ���Է��ϼ���." << endl;
		return 0;
	}

	m1 = A1.rr(A2);
	m2 = B1.rr(B2);

	distance[0] = (A1.x - B1.x)*(A1.x - B1.x) + (A1.y - B1.y)*(A1.y - B1.y); // A1�� B1������ �Ÿ�
	distance[1] = (A1.x - B2.x)*(A1.x - B2.x) + (A1.y - B2.y)*(A1.y - B2.y); // A1�� B2������ �Ÿ�
	distance[2] = (A2.x - B1.x)*(A2.x - B1.x) + (A2.y - B1.y)*(A2.y - B1.y); // A2�� B1������ �Ÿ�
	distance[3] = (A2.x - B2.x)*(A2.x - B2.x) + (A2.y - B2.y)*(A2.y - B2.y); // A2�� B2������ �Ÿ�

	//A1�� L2������ �Ÿ�
	distance[4] = (m2*(A1.x - B2.x) + B2.y - A1.y)/sqrt(m2*m2+1);
	//A2�� L2 ������ �Ÿ�
	distance[5] = (m2*(A2.x - B2.x) + B2.y - A2.y) / sqrt(m2*m2 + 1);
	//B1�� L1 ������ �Ÿ�
	distance[6] = (m1*(B1.x - A2.x) + A2.y - B1.y)/sqrt(m1*m1 + 1);
	//B2�� L1 ������ �Ÿ�
	distance[7] = (m1*(B2.x - A2.x) + A2.y - B2.y)/sqrt(m1*m1 + 1);

	double min = distance[0];

	for (int i = 1; i < 8; i++) {
		if (distance[i] < min) min = distance[i];
	}

	cout << "�Ÿ� : " << min << endl;

	return 0;
}