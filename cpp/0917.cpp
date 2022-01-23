#include <iostream>
using namespace std;

void Q5() {
	int arr[3][5] = {
		{12,56,32,16,98}, {99,56,34,41,3}, {65,3,87,78,21}
	};

	int sum[5] = { 0, };

	cout << "각 행의 값은 ";

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			sum[i] += arr[j][i];
		}

		cout << sum[i] << " ";
	}

	cout << endl;

	sum[5] = { 0, };

	cout << "각 열의 값은 ";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			sum[i] += arr[i][j];
		}

		cout << sum[i] << " ";
	}

	cout << endl;

}

int main() {

	Q5();
	
	return 0;
}