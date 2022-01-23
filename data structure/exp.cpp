#include <stdio.h>
#include "stack.h"
#include <ctype.h>
#include <string.h>

void expToTree(char exp[]) {
	Stack stack;

	StackInit(&stack);

	int len = strlen(exp);

	for (int i = 0; i < len; i++) {
		if (isdigit(exp[i])) {
			BTreeNode* newB = MakeTree();
			setData(newB, exp[i]);
			SPush(&stack, newB);
		}
		else {
			BTreeNode* op = MakeTree();
			setData(op, exp[i]);
			op->right = SPop(&stack);
			op->left = SPop(&stack);
			SPush(&stack, op);
		}
	}
}

int expression(BTreeNode* tree) {
	char op = tree->data;


}