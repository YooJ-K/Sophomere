#pragma once
class BankAccount {
private:
	int balance;//잔고
public:
	void deposit(int amount); // 입금 함수
	void withdraw(int amount); //출금 함수
	void print(); //현재 상태(잔고) 출력
	void setBalance(int amount); // balance에 대한 설정자
	void transfer(BankAccount &a, int amount);
	//이체 -> a의 멤버 변수값 변화, 함수가 인자로 객체를 받을 때는 참조자로 받는 것이 좋다
	// 특히, 객체를 받아 함수에서 멤버값을 변화시키는 경우 참조자 사용
	//void transfer(BankAccount a, int amount); 이 경우 a값 변화 없음!
};