#include <iostream>
using namespace std;

void main() {

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