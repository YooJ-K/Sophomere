#include <iostream>
#include <string>
using namespace std;

void q8() {
	//���ĺ� ������ ����, ������ ����,���� ������ ����
	int aNum = 0, sNum = 0, nNum = 0, l;
	string s;

	cout << "8��. ���ڿ��� �Է��ϼ��� (Ư�� ���ڴ� �Է��� �Ұ��� �մϴ�.) : ";
	getline(cin, s);

	l = s.length();

	for (int i = 0; i < l; i++) {

		if (s[i] >= 65 && s[i] <= 122)
		{
			aNum++;
		}

		if (s[i] == 32) {
			nNum++;
		}

		if (s[i] >= 48 && s[i] <= 57) {
			sNum++;
		}
	}

	if (l != sNum + aNum + nNum) {
		cout << "Ư�� ���ڴ� �Է��� �Ұ��� �մϴ�." << endl;
	}
	else {
		cout << "alphabet : " << aNum << endl << "number : " << sNum << endl << "space : " << nNum << endl;
	}


	return;
}

void q9() {
	//�ܾ��� ����
	int num = 0, l;
	string s;

	cout << "9��. ���ڿ��� �Է��ϼ��� : ";
	getline(cin, s);

	l = s.length();

	for (int i = 0; i < l; i++) {

		if (s[i] == 32) {
			num++;
		}
	}

	cout << "�ܾ��� ���� : " << num + 1 << "��" << endl;


	return;
}

void q13() {
	//ã�� �ٲٱ� ���

	string a, b, c;

	cout << "13��. ���ڿ��� �Է��ϼ���(�ִ� 100��) : ";
	getline(cin, a);

	if (a.length() > 100) {
		cout << "100�� �ʰ�" << endl;
		return;
	}

	cout << "ã�� ���ڿ��� �Է��ϼ���(�ִ� 10��) : ";
	cin >> b;

	if (b.length() > 10) {
		cout << "10�� �ʰ�" << endl;
		return;
	}

	if (a.find(b) == -1) {
		cout << "�ش� ���ڿ��� �����ϴ�." << endl;
		return;
	}

	cout << "�ٲ� ���ڿ��� �Է��ϼ��� (�ִ� 10��) : ";
	cin >> c;

	if (c.length() > 10) {
		cout << "10�� �ʰ�" << endl;
		return;
	}

	a.replace(a.find(b), b.length(), c);

	cout << a;

	return;
}

int main() {
	q8();
	q9();
	q13();

	return 0;
}