#include "FruitSeller.h"
#include "FruitBuyer.h"
#include "Box.h"
#include <iostream>
using namespace std;

void P2() {
	Box a(5, 7), b(7,10), c(3, 8);

	int x = a.getVolume();
	int y = b.getVolume();
	int z = c.getVolume();
	
	int max = 0;

	if (x > max) max = x;
	if (y > max) max = y;
	if (z > max) max = z;

	cout << "���� ���ǰ� ū �ڽ��� ���Ǵ� " << max << "�Դϴ�." << endl;
}

void P3() {
	FruitSeller seller(1000, 20, 0);

	FruitBuyer buyer(5000);

	buyer.BuyApples(seller, 2000);

	cout << "===========================" << endl;

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();

	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return;
}

int main() {
	P2();
	P3();
}