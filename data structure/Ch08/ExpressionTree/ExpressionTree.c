#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		pnode = MakeBTreeNode();

		if(isdigit(exp[i]))		// 피연산자라면...
		{
			SetData(pnode, exp[i]-'0');
		}
		else					// 연산자라면...
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
	int op1, op2;

	if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch(GetData(bt))
	{
	case '+':
		return op1+op2;
	case '-':
		return op1-op2;
	case '*':
		return op1*op2;
	case '/':
		return op1/op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if(0<=data && data<=9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
	InorderTraverse(bt, ShowNodeData);
} 

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}

void ExpTo(char exp[]) {
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);
	int i, count=0;

	char* newExp = (char*)malloc(expLen+1);

	memset(newExp, 0, expLen);
	newExp[expLen] = NULL;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{

		if (isdigit(exp[i]))		// 피연산자라면...
		{
			newExp[count++] = exp[i];
		}
		else					// 연산자라면...
		{
			pnode = MakeBTreeNode();
			SetData(pnode, exp[i]);

			if (!SIsEmpty(&stack)) {
				int rank = compare(SPeek(&stack), exp[i]);
				if (rank == 1) {
					newExp[count++] = SPop(&stack);
				}
			}
			SPush(&stack, pnode);
		}

	}

	while (!SIsEmpty(&stack)) {
		newExp[count++] = SPop(&stack);
	}

	strcpy(exp, newExp);

	free(newExp);
}

int Rank(char op) {
	switch (op) {
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 3;
	}
}

int compare(char op1, char op2) {
	int r1 = Rank(op1);
	int r2 = Rank(op2);

	if (r1 >= r2) {
		return 1;
	}
	else {
		return -1;
	}
}