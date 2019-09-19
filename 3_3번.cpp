#include <iostream>
using namespace std;

void main() {

	// 사용자로부터 10개 이하의 실수 자료를 읽어 평균과 표준편차를 계산하라
	// C++ 평균, 표준편차 계산 프로그램 2019-09-18

	int num;
	float *arr, average = 0, sum = 0;

	cout << "몇 개의 수를 입력하겠습니까? ";
	cin >> num;

	arr = new float[num];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		average += arr[i];
	}

	average /= (float)num;

	for (int i = 0; i < num; i++) {
		sum += (arr[i] - average)*(arr[i] - average);
	}

	sum /= (float)num;

	cout << "평균은 " << average << " 표준편차는 " << sum << endl;

	delete[] arr;

	return;
}
