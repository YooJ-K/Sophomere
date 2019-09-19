#include <iostream>
using namespace std;

void copy(int* A, int* B, int n) {
	for (int i = 0; i < n; i++)
		B[i] = A[i];
    
  return;
}

void main() {

	//배열 복사 프로그램 2019-09-19

	int num;

	cout << "9번. 배열의 크기를 입력하세요 : ";
	cin >> num;

	int* A = new int[num];
	int* B = new int[num];

	cout << "배열 A에 저장될 수를 차례대로 입력하시오" << endl;

	for (int i = 0; i < num; i++) {
		cin >> A[i];
	}

	copy(A, B, num);

	cout << "copy(A,B,num)의 결과는 다음과 같습니다" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << B[i] << " ";
	}

	cout << endl;

	delete[] A;
	delete[] B;

	return;
}
