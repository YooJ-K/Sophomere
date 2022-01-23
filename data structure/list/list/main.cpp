#include <stdio.h>
#include "array.h"

int main() {
	List list;
	int data, sum = 0;
	ListInit(&list);

	for (int i = 0; i < 10; i++) {
		LInsert(&list, i);
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));


	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}

	printf("\n");

	if (LFirst(&list, &data)) {
		sum += data;

		while (LNext(&list, &data)) {
			sum += data;
		}
	}

	if (LFirst(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0) LRemove(&list);

		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0 ) LRemove(&list);
		}
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));


	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
}