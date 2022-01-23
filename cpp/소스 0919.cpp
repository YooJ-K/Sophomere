#include <iostream>
using namespace std;

void q3() {

	// ����ڷκ��� 10�� ������ �Ǽ� �ڷḦ �о� ��հ� ǥ�������� ����϶�
	// C++ ���, ǥ������ ��� ���α׷� 2019-09-18

	int num;
	float *arr, average = 0, sum = 0;

	cout << "3��. �� ���� ���� �Է��ϰڽ��ϱ�? ";
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

	cout << "����� " << average << " ǥ�������� " << sum << endl;

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
	cout << "5��" << endl;

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

	cout << "�� ���� �� : ";

	sum(arrP, sumH, sumY);

	for (int i = 0; i < 3; i++) {
		cout << sumH[i] << " ";
	}


	cout << endl << "�� ���� �� : ";

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

	//�迭 ���� ���α׷� 2019-09-19

	int num;

	cout << "9��. �迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> num;

	int* A = new int[num];
	int* B = new int[num];

	cout << "�迭 A�� ����� ���� ���ʴ�� �Է��Ͻÿ�" << endl;

	for (int i = 0; i < num; i++) {
		cin >> A[i];
	}

	copy(A, B, num);

	cout << "copy(A,B,num)�� ����� ������ �����ϴ�" << endl;

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

	cout << "11��. �迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> num;

	double *a = new double[num];

	double avg, max, sum;

	avg = num;//�迭�� ũ�⸦ �������ֱ� ����

	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}

	get_start(a, &avg, &max, &sum);

	cout << "��� : " << avg << endl << "�ִ� : " << max << endl << "�� : " << sum << endl;

	return;
}

int main() {
	q5();

	return 0;
}

