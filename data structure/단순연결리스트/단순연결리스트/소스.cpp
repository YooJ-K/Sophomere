#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef int LData;

typedef struct linkedList {
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
}List;

void ListInit(List* plist); // �ʱ�ȭ
void FInsert(List* plist, LData data);
void LInsert(List* plist, LData data);
void SInsert(List* plist, LData data);
int comp(LData d1, LData d2);
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));
int LFirst(List* plist, LData* pdata); // head ��
int LNext(List* plist, LData* pdata); // tail ��
LData LRemove(List* plist);
int LCount(List* plist);
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->data = 0;
	plist->head->next = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
} 

void FInsert(List* plist, LData data) {
	if (plist->comp == NULL) LInsert(plist, data);
	else SInsert(plist, data);
}

void LInsert(List* plist, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

//SetSortRule �Լ��� ȣ��Ǹ鼭 ������ ������ ����Ʈ�� ��� comp�� ��ϵǸ�, SInsert �Լ� ��������
//comp�� ��ϵ� ������ ������ �ٰŷ� �����͸� �����Ͽ� �����Ѵ�.

void SInsert(List* plist, LData data) {
	Node* pred = plist->head;
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	while (plist->comp(data, pred->next->data) != 0 && (pred->next!=NULL)) {
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	plist->numOfData++;
}

int comdp(LData d1, LData d2) {
	if (d1 > d2) return 0;
	else return 1;
}

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}

int LFirst(List* plist, LData* pdata) {
	//���� ���� ����� ������ ���� pdata�� ���� ����

	plist->before = plist->head;
	plist->cur = plist->head->next;
	

	if (plist->cur == NULL) {
		return 0;
	}
	else {
		*pdata = plist->cur->data;
		
		return 1;
	}
}

int LNext(List* plist, LData* pdata) {

	if (plist->cur->next != NULL) {

		plist->before = plist->cur;
		plist->cur = plist->cur->next;

		*pdata = plist->cur->data;

		return 1;
	}
	else {
		return 0;
	}


}

LData LRemove(List* plist) {
	Node *rd = plist->cur;
	LData k = rd->data;

	plist->before->next = rd->next;
	plist->cur = plist->before;
	free(rd);

	(plist->numOfData)--;
	return k;
}

int LCount(List* plist) {
	return plist->numOfData;
}

int main() {
	
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, comdp); //�Լ��� �ּҰ��̴ϱ�! �̸���(�Ű�����X)

/*
	FInsert(&list, 11);
	FInsert(&list, 22);
	FInsert(&list, 22);
	FInsert(&list, 44);
	FInsert(&list, 55);

*/
	FInsert(&list, 5);
	FInsert(&list, 1);
	FInsert(&list, 20);

	printf("���� �������� �� : %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data)) {
		if (data == 22) LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22) {
				LRemove(&list);
			}
		}
	}

	printf("���� �������� �� : %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;

}