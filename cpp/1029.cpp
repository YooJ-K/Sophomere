#include <iostream>
#include <string>
using namespace std;

void add(string &s) {
	cout << s;
}

int main() {
	string s1 = "��¼�� ";
	string s2 = "��¼��";
	string s3 = s1 + s2;


	add(s3);
}