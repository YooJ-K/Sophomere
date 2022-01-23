#include "BinaryTree.h"
#include<stdio.h>
#include <stdlib.h>

BTreeNode* MakeTree(void) {
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	return newNode;
}

TData getData(BTreeNode* tree) {
	return tree->data;
}

void setData(BTreeNode* tree, TData data) {
	tree->data = data;
}

void MakeLeftTree(BTreeNode* main, BTreeNode* left) {
	if (main->left != NULL)
		free(main->left);
	
	main->left = left;
}

void MakeRightTree(BTreeNode* main, BTreeNode* right) {
	if (main->right != NULL)
		free(main->right);
	
	main->right = right;
}

BTreeNode* getLeftTree(BTreeNode* tree) {
	return tree->left;
}

BTreeNode* getRightTree(BTreeNode* tree) {
	return tree->right;
}

void Travel(BTreeNode* tree, Visit action) {
	if (tree == NULL)return;
	Travel(tree->left, action);
	action(tree);
	Travel(tree->right, action);
}