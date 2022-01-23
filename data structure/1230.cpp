#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
} LinkedList;


typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));


void ListInit(List * plist) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	plist->head = newNode;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}
void LInsert(List * plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);

	plist->numOfData++;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;
}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	Node* c = plist->head->next;

	while (c != NULL && plist->comp(data, c->data)) {
		c = c->next;
	}

	newNode->next = c->next;
	c->next = newNode;
}

int LFirst(List * plist, LData * pdata) {
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->cur = plist->head->next;
	plist->before = plist->head;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

LData LRemove(List * plist) {
	Node* c = plist->cur;
	int s = c->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(c);
	plist->numOfData--;

	return s;
}

int LCount(List * plist) {
	return plist->numOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}

int W(LData d1, LData d2) {
	if (d1 > d2)
		return TRUE;
	else
		return FALSE;
}