typedef char TData;
typedef struct BTreeNode {
	struct BTreeNode* left, *right;
	TData data;
}BTreeNode;

typedef int(*Visit)(BTreeNode* tree);


BTreeNode* MakeTree(void);
TData getData(BTreeNode* tree);

void setData(BTreeNode* tree, TData data);
void MakeLeftTree(BTreeNode* main, BTreeNode* left);
void MakeRightTree(BTreeNode* main, BTreeNode* right);
BTreeNode* getLeftTree(BTreeNode* tree);
BTreeNode* getRightTree(BTreeNode* tree);
void Travel(BTreeNode* tree, Visit action);