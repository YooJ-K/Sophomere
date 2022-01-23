#include <stdio.h>

int main() {

	for(;;){

		int x, n, sum, arr[100],j=0;

		printf("*******************************************\n\n");
		printf("\t진수 변환 프로그램입니다.\n\n");
		printf("*******************************************\n");
		printf("10진수를 몇진수로 변환하시겠습니까?\n(2,8,16 / 0을 누르면 프로그램이 종료됩니다.) : ");
		scanf("%d", &x);

		if (x == 0) break;
		else if (x != 2 && x != 8 && x != 16) { printf("잘못입력하셨습니다.\n"); return 0; }
		else {
			printf("10진수를 입력하시오 : ");
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