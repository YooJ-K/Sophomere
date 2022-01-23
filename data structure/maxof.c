#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(int* jin,int n) {

	int max = *jin;

	for (int i = 0; i < n; i++) {
		if (jin[i] > max)
			max = jin[i];
		printf("%2d ", max);
	}
	printf("\n");

	return max;
}

int main() {

	int number, *bae, result;

	srand(time(NULL));

	scanf("%d", &number);

	bae = calloc(number, sizeof(int));

	for (int i = 0; i < number; i++) {
		bae[i] = rand() % 100 + 1;
		printf("%2d ", bae[i]);
	}
	printf("\n");

	result = maxof(bae, number);

	printf("%d\n", result);

	free(bae);

	return 0;
}