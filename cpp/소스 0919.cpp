#include <iostream>
using namespace std;

void q3() {

	// 사용자로부터 10개 이하의 실수 자료를 읽어 평균과 표준편차를 계산하라
	// C++ 평균, 표준편차 계산 프로그램 2019-09-18

	int num;
	float *arr, average = 0, sum = 0;

	cout << "3번. 몇 개의 수를 입력하겠습니까? ";
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

void sum(int(*arr)[5], int* sumH, int* sumY) {

	for (int i = 0; i < 3; i++) {

		sumH[i] = 0;

		for (int j = 0; j < 5; j++) {
			sumH[i] += arr[i][j];
		}
	}

	for (int j = 0; j < 5; j++) {

		sumY[j] = 0;

		for (int i = 0; i < 3; i++) {
			sumY[j] += arr[i][j];
		}
	}
}

void q5() {
	cout << "5번" << endl;

	int arr[3][5] = {
	 { 12,56,32,16,98 },
	 { 99,56,34,41,3 },
	 { 65,3,87,78,21 }
	};

	int(*arrP)[5] = arr;

	int* sumH = new int[3];
	int* sumY = new int[5];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << "각 행의 합 : ";

	sum(arrP, sumH, sumY);

	for (int i = 0; i < 3; i++) {
		cout << sumH[i] << " ";
	}


	cout << endl << "각 열의 합 : ";

	for (int i = 0; i < 5; i++) {
		cout << sumY[i] << " ";
	}

	cout << endl;


	delete[] sumH;
	delete[] sumY;

	return;
}

void copy(int* A, int* B, int n) {
	for (int i = 0; i < n; i++)
		B[i] = A[i];
}

void q9() {

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

void get_start(double A[], double *p_avg, double *p_max, double *p_sum) {
	int num = *p_avg;

	*p_avg = 0;
	*p_max = 0;
	*p_sum = 0;

	for (int i = 0; i < num; i++) {
		*p_sum += A[i];

		if (*p_max < A[i])
			*p_max = A[i];
	}

	*p_avg = *p_sum / num;
}

void q11() {

	int num;

	cout << "11번. 배열의 크기를 입력하세요 : ";
	cin >> num;

	double *a = new double[num];

	double avg, max, sum;

	avg = num;//배열의 크기를 전달해주기 위함

	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}

	get_start(a, &avg, &max, &sum);

	cout << "평균 : " << avg << endl << "최댓값 : " << max << endl << "합 : " << sum << endl;

	return;
}

int main() {
	q5();

	return 0;
}

