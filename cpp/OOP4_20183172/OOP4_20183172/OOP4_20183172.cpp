#include <iostream>
#include <string>
using namespace std;

void q8() {
	//알파벳 글자의 개수, 숫자의 개수,공백 문자의 개수
	int aNum = 0, sNum = 0, nNum = 0, l;
	string s;

	cout << "8번. 문자열을 입력하세요 (특수 문자는 입력이 불가능 합니다.) : ";
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
		cout << "특수 문자는 입력이 불가능 합니다." << endl;
	}
	else {
		cout << "alphabet : " << aNum << endl << "number : " << sNum << endl << "space : " << nNum << endl;
	}


	return;
}

void q9() {
	//단어의 개수
	int num = 0, l;
	string s;

	cout << "9번. 문자열을 입력하세요 : ";
	getline(cin, s);

	l = s.length();

	for (int i = 0; i < l; i++) {

		if (s[i] == 32) {
			num++;
		}
	}

	cout << "단어의 개수 : " << num + 1 << "개" << endl;


	return;
}

void q13() {
	//찾아 바꾸기 기능

	string a, b, c;

	cout << "13번. 문자열을 입력하세요(최대 100자) : ";
	getline(cin, a);

	if (a.length() > 100) {
		cout << "100자 초과" << endl;
		return;
	}

	cout << "찾을 문자열을 입력하세요(최대 10자) : ";
	cin >> b;

	if (b.length() > 10) {
		cout << "10자 초과" << endl;
		return;
	}

	if (a.find(b) == -1) {
		cout << "해당 문자열이 없습니다." << endl;
		return;
	}

	cout << "바꿀 문자열을 입력하세요 (최대 10자) : ";
	cin >> c;

	if (c.length() > 10) {
		cout << "10자 초과" << endl;
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