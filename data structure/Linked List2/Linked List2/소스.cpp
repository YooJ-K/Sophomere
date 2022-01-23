#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _node {
	int data;
	struct _node* next;
}Node;

typedef struct Linked {
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
}List;

typedef int LData;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData *data);
int LNext(List* plist, LData *data);
int LRemove(List* plist);
int LCount(List* plist);


void ListInit(List* plist) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	plist->head = newNode;
	plist->cur = NULL;
	plist->before = NULL;

	plist->numOfData = 0;
}

void LInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	plist->numOfData++;
}

int LFirst(List* plist, LData *data) {
	if (plist->head->next == NULL) return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	*data = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData *data) {
	if (plist->cur->next == NULL) return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*data = plist->cur->data;

	return TRUE;
}

int LRemove(List* plist) {
	
}

int LCount(List* plist) {
	return plist->numOfData;
}

int main() {

	List list;

	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 55);

	 

}