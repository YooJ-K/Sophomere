#include <stdio.h>

int main() {

	for(;;){

		int x, n, sum, arr[100],j=0;

		printf("*******************************************\n\n");
		printf("\t���� ��ȯ ���α׷��Դϴ�.\n\n");
		printf("*******************************************\n");
		printf("10������ �������� ��ȯ�Ͻðڽ��ϱ�?\n(2,8,16 / 0�� ������ ���α׷��� ����˴ϴ�.) : ");
		scanf("%d", &x);

		if (x == 0) break;
		else if (x != 2 && x != 8 && x != 16) { printf("�߸��Է��ϼ̽��ϴ�.\n"); return 0; }
		else {
			printf("10������ �Է��Ͻÿ� : ");
			scanf("%d", &n);

			while (n > 1) {

				if (x == 2) {
					arr[j++] = n % 2;
					n %= 2;
				}
				else if (x == 8) {
					arr[j++] = n % 8;
					n /= 8;
				}
				else {
					arr[j] = n % 16;
					if (arr[j] == 10)
						arr[j] = A;
					n /= 16;
				}

				sum++;
			}

		}
	}
	return 0;

}