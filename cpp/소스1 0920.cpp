#include <iostream>
#include <string>
using namespace std;

void q13() {
	//ã�� �ٲٱ� ���

	string a, b, c;

	cout << "���ڿ��� �Է��ϼ���(�ִ� 100��) : ";
	getline(cin, a);

	cout << a.length()<<endl;

	cout << "ã�� ���ڿ��� �Է��ϼ���(�ִ� 10��) : ";
	cin >> b;

	if (a.find(b) == -1) {
		cout << "�ش� ���ڿ��� �����ϴ�." << endl;
		return;
	}

	cout << "�ٲ� ���ڿ��� �Է��ϼ���(�ִ� 10��) : ";
	cin >> c;

	a.replace(a.find(b), b.length(), c);
	
	cout << a;

	return;
}