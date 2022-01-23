#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
}Node;

typedef struct CList {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}List;

void ListInit(List*plist);
void LInsert(List* plist, Data data);
void LInsertFront(List *plist, Data data);

int LFirst(List* plist, Data *pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LCount(List* plist);

void ListInit(List*plist) {
	plist->tail = plist->before = plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	plist->before = plist->tail;
	plist->tail->next = newNode;
	newNode = plist->tail;

}

void LInsertFront(List *plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;


}