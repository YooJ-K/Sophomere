#pragma once
#include "FruitSeller.h"
class FruitBuyer {
	int much; // 얼마
	int myM; // 내 돈
	int many; // 몇개
public:
	FruitBuyer(int myM_);
	void BuyApples(FruitSeller &s, int much_);
	void ShowBuyResult();
};