#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0

typedef BTreeNode* Data;

typedef struct Node {
	Data data;
	struct Node* next;
}Node;

typedef struct Stack {
	struct Node* head;
	int numOfData;
}Stack;

void StackInit(Stack* pstack);
int SisEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);

