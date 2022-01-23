#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* next;
};

typedef struct List {
	Node* head;
	Node* cur;

	int numOfData;
}List;

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(int));
	plist->head->next = NULL;

	plist->numOfData = 0;
}

void LInsert(List* plist, int d) {
	plist->cur = plist->head;

	while (plist->cur->next != NULL) {
		plist->cur = plist->cur->next;
	}

	plist->cur->next = (Node*)malloc(sizeof(int));
}

int main() {

}