#include<stdio.h>
#include <stdlib.h>
#include "stack.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL;
	pstack->numOfData = 0;
}

int SisEmpty(Stack* pstack) {
	if (pstack->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack* pstack) {
	Node* save = pstack->head;
	Data saveData = save->data;

	pstack->head = pstack->head->next;

	free(save);

	return saveData;
}
