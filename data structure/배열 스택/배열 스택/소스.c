//stack

#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct stack {
	int arr[10];
	int top;
}stack;
typedef int Data;

void StackInit(stack *pstack);
int SIsEmpty(stack* pstack);
void Push(stack* pstack, Data data);
Data Pop(stack* pstack);
Data Speek(stack* pstack);

void StackInit(stack *pstack) {
	pstack->top = -1; // -1���� �� ���¸� �ǹ��ؾ��� not 1
}

int SIsEmpty(stack* pstack) {
	if (pstack->top > 0) return TRUE; // pstack->top == -1�� ��찡 �� ������
	else return FALSE;
}

void Push(stack* pstack, Data data) {
	if (pstack->top >= 10) return;

	pstack->arr[++pstack->top] = data;
}

Data Pop(stack* pstack) {
	if (pstack->top == 0) return FALSE; //-1�� ��찡 ���� �̰� Ʋ��

	pstack->top--;
	return TRUE; // ���� �Ǵ� ������ �� ��ȯ�ؾ� �Ѵ�
	//==>
	//Data lastTop=pstack->arr[pstack->top--];
	//return lastTop;
}

Data Speek(stack* pstack) {
	//top�� -1�� ��� FALSE ����
	return pstack->arr[pstack->top];
}

int main() {
	stack h;

	StackInit(&h);
	
	Push(&h, 1);
	Push(&h, 2);
	Push(&h, 3);
	Push(&h, 4);
	Push(&h, 5);

	for (int i = 0; i <= h.top; i++)
		printf("%d ", h.arr[i]);

	printf("\n");

	printf("%d ", Speek(&h));

	Pop(&h);
	Pop(&h);

	printf("%d ", Speek(&h));
	
	for (int i = 0; i <= h.top; i++)
		printf("%d ", h.arr[i]);
}