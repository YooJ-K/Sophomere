#include <iostream>
#include <string>
using namespace std;

void add(string &s) {
	cout << s;
}

int main() {
	string s1 = "¾îÂ¼°í ";
	string s2 = "ÀúÂ¼°í";
	string s3 = s1 + s2;


	add(s3);
}