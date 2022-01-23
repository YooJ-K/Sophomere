#include "BankAccount.h"
#include <iostream>

void BankAccount::setBalance(int amount) {
	balance = amount;
}

void BankAccount::deposit(int amount) {
	balance += amount;
}

void BankAccount::withdraw(int amount) {
	balance -= amount;
}

void BankAccount::print() {
	std::cout << balance << std::endl;
}

void BankAccount::transfer(BankAccount &a, int amount) {
	a.balance -= amount;
}
