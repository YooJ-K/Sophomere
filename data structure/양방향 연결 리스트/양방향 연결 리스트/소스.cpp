#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct Node {
	Data data;
	struct Node * next;
	struct Node* prev;
}Node;

typedef struct DLinked {
	Node* head;
	Node* cur;
	int numOfData;
}List;

void ListInit(List* plist);
void LInsert(List*plist, Data data);

int LFirst(List *plist, Data* pdata);
int LNext(List *plist, Data* pdata);
int LPrevious(List *plist, Data* pdata);

int LCount(List* plist);

void ListInit(List* plist) {
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List*plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL; v 

	if (plist->head == NULL) plist->head = newNode;
	else {
		plist->cur = plist->head;

		while (plist->cur->next != NULL) {
			plist->cur = plist->cur->next;
		}

		plist->cur->next = newNode;
		newNode->prev = plist->cur;
	}

	plist->numOfData++;
}

int LFirst(List *plist, Data* pdata) {
	if (plist->head == NULL) return FALSE;
	plist->cur = plist->head;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List *plist, Data* pdata) {
	if (plist->cur->next == NULL) return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;

}

int LPrevious(List *plist, Data* pdata) {
	if (plist->cur->prev == NULL) return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List* plist) {
	return plist->numOfData;
}

int main() {
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 1);	
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) printf("%d ", data);

		while (LPrevious(&list, &data)) printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}