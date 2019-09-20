#include <iostream>
#include <string>
using namespace std;

int main() {
	//찾아 바꾸기 기능

	string a, b, c;
	int index, range;

	cout << "문자열을 입력하세요(최대 100자) : ";
	getline(cin, a);

	cout << a.length()<<endl;

	cout << "찾을 문자열을 입력하세요(최대 10자) : ";
	cin >> b;

	index = a.find(b);

	if (index == -1) {
		cout << "해당 문자열이 없습니다." << endl;
		return -1;
	}

	cout << "바꿀 문자열을 입력하세요(최대 10자) : ";
	cin >> c;

	a.replace(a.find(b), b.length(), c);
	
	cout << a;

	return 0;
}
