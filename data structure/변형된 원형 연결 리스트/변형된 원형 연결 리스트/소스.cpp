#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct Node {
	Data data;
	struct Node* next;
}Node;

typedef struct CLL {
	Node* tail, *cur, *before;
	int numOfData;
}CLL;

typedef CLL List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);
void LInsertFront(List* plist, Data data); // 머리에 노드 추가

int LFirst(List* plist, Data* pdata);
int LNext(List*plist, Data* pdata);
Data LRemove(List* plist);
int LCount(List* plist);

void ListInit(List* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		plist->tail->next = plist->tail;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	plist->numOfData++;
	
}

void LInsertFront(List* plist, Data data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	

	if (plist->tail == NULL) {
		plist->tail = newNode;
		plist->tail->next = plist->tail;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	plist->numOfData++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->tail == NULL) return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->tail->next->data;

	return TRUE;
}

int LNext(List*plist, Data* pdata) { 
	if (plist->tail == NULL) return FALSE;

	plist->cur = plist->cur->next;
	plist->before = plist->before->next;

	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List* plist) {
	if (plist->tail == NULL) return -1;

	Node* ptr = plist->cur;

	plist->before->next = plist->cur->next;

	plist->numOfData--;

	int data = ptr->data;

	free(ptr);

	return data;
}

int LCount(List* plist) {
	return plist->numOfData;
}


int main() {
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		for (i = 0; i < LCount(&list) * 3 - 1; i++) {
			if(LNext(&list, &data)) printf("%d ", data);

		}
	}

	printf("\n");

	/*nodeNum = LCount(&list);

	if (nodeNum != 0) {
		LFirst(&list, &data);
		if (data % 2 == 0) LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++) {
			LNext(&list, &data);
			if (data % 2 == 0) LRemove(&list);
		}
	}*/

	printf("\n");

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		for (i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &data)) printf("%d ", data);

		}
	}
	printf("\n");

}
