#pragma once
#include "FruitSeller.h"
class FruitBuyer {
	int much; // ��
	int myM; // �� ��
	int many; // �
public:
	FruitBuyer(int myM_);
	void BuyApples(FruitSeller &s, int much_);
	void ShowBuyResult();
};