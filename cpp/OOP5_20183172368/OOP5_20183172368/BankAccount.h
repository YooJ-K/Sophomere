#pragma once
class BankAccount {
private:
	int balance;//�ܰ�
public:
	void deposit(int amount); // �Ա� �Լ�
	void withdraw(int amount); //��� �Լ�
	void print(); //���� ����(�ܰ�) ���
	void setBalance(int amount); // balance�� ���� ������
	void transfer(BankAccount &a, int amount);
	//��ü -> a�� ��� ������ ��ȭ, �Լ��� ���ڷ� ��ü�� ���� ���� �����ڷ� �޴� ���� ����
	// Ư��, ��ü�� �޾� �Լ����� ������� ��ȭ��Ű�� ��� ������ ���
	//void transfer(BankAccount a, int amount); �� ��� a�� ��ȭ ����!
};