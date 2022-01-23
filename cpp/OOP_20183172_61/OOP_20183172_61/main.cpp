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

	cout << "가장 부피가 큰 박스의 부피는 " << max << "입니다." << endl;
}

void P3() {
	FruitSeller seller(1000, 20, 0);

	FruitBuyer buyer(5000);

	buyer.BuyApples(seller, 2000);

	cout << "===========================" << endl;

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();

	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return;
}

int main() {
	P2();
	P3();
}