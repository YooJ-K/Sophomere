#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}List;

typedef int LData;

#define TRUE 1
#define FALSE 0

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void ListInit(List * plist) {
	plist = NULL;
}

void LInsert(List * plist, LData data) {

	plist =

	plist->data = data;
	plist->next = NULL;
}