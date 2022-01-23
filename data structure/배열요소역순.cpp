#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type,x,y) do{type tmp=x;x=y;y=tmp;}while(0)

int main() {

	int n, j;

	scanf("%d", &n);

	int *bae =(int*) malloc(sizeof(int)*n);

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		bae[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", bae[i]);
	}

	printf("\n");

	/*if (n % 2 == 0)
		j = n / 2;
	else
		j = n / 2;

	printf("%d\n", j);

	for (int i=0; i < j; i++) {
		int tmp = bae[i];
		bae[i] = bae[n - i-1];
		bae[n - i-1] = tmp;
		printf("%d %d\n", bae[i], bae[n - i-1]);
	}*/

	for (int i = 0; i < n / 2; i++) do { swap(int,bae[i], bae[n - i - 1]); } while (0);

	for (int i = 0; i < n; i++) {
		printf("%d ",bae[i]);
	}

	printf("\n");

	free(bae);

	return 0;
}