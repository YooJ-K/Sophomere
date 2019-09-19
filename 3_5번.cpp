#include <iostream>
using namespace std;

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

void main() {

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
