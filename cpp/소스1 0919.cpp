#include <iostream>
using namespace std;


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

void main() {

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
