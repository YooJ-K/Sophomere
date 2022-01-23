#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct area {
	int width[10];
	int length[10];
}area;

int multi(int*a, int*b) {

	if (*a < 0) {
		*a = -(*a);
	}
	if (*b < 0) {
		*b = -(*b);
	}

	int result = (*a) * (*b);

	return result;
}

int main() {
	area x;
	int re[10];

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		x.width[i] = rand() % 201- 100;
		x.length[i]=rand()%201-100;

		if (x.width[i] == 0 || x.length[i] == 0) {
			printf("잘못된 값입니다.\n");
		}
		else {
			printf("%3d %3d ", x.width[i], x.length[i]);

			re[i] = multi(&x.width[i], &x.length[i]);

			printf("%3d %3d", x.width[i], x.length[i]);

			printf(" %d\n", re[i]);
		}
	}

	int max = re[0];
	int su=0;

	for (int i = 1; i < 10; i++) {
		if (re[i] > max) {
			max = re[i];
			su = i;
		}
	}

	printf("%d번째 좌표가 %d의 넓이로 가장 크다.\n", su+1, max);
}