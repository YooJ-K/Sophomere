#include<iostream>
using namespace std;

class node {
public:
	node() {
		data_ = 0; lc_ = 0; rc_ = 0;
	}
	node(int data, node* lc = 0, node * rc = 0) {
		data_ = data;
		lc_ = lc;
		rc_ = rc;
	}
public:
	int data_;
	node * lc_;
	node * rc_;
};

class binaryTree {
public:
	binaryTree(int root);
	~binaryTree();
	bool Search(int el);
	bool AddLeftChild(int parent, int child);
	bool AddRightChild(int parent, int child);
	int NumberOfOddNumbers() { return Noon(root_); };
	int MaxNumber() { return Maxn(root_); };
	int MinNumber() { return Minn(root_); };
protected:
	void DeleteTree(node * ptr);
	node * Search(node * ptr, int el);
	int  Maxn(node * ptr);
	int  Minn(node * ptr);
	int  Noon(node * ptr);
private:
	node * root_;
};

binaryTree::binaryTree(int root) {
	root_ = new node(root);
}

binaryTree::~binaryTree() {
	root_ = 0;
	DeleteTree(root_);
}

bool binaryTree::AddLeftChild(int parent, int child) {
	node * ptr = Search(root_, parent);
	if (ptr == 0) return false;
	if (ptr->lc_ != 0) return false;
	ptr->lc_ = new node(child);
	ptr->lc_->data_ = child;
	return true;
}

bool binaryTree::AddRightChild(int parent, int child) {
	node * ptr = Search(root_, parent);
	if (ptr == 0) return false;
	if (ptr->rc_ != 0) return false;
	ptr->rc_ = new node(child);
	ptr->rc_->data_ = child;
	return true;
}

void binaryTree::DeleteTree(node * ptr) {
	if (ptr == 0) return;
	DeleteTree(ptr->lc_);
	DeleteTree(ptr->rc_);
	delete ptr;
}

bool binaryTree::Search(int el) {
	if (Search(root_, el) == 0) return false;
	return true;
}

node * binaryTree::Search(node * ptr, int el) {
	if (ptr == 0) return 0;
	if (ptr->data_ == el) return ptr;
	node * tptr = Search(ptr->lc_, el);
	if (tptr) return tptr;
	tptr = Search(ptr->rc_, el);
	return tptr;
}


int binaryTree::Maxn(node * ptr) { // 최댓값을 구하는 함수
	int max = 0, nl, nr, root;

	if (ptr != 0) {
		root = ptr->data_;
		int nl = Maxn(ptr->lc_);
		int nr = Maxn(ptr->rc_);

		if (nr > max) {
			max = nr;
		}
		else {
			max = nl;
		}

		if (root > max)
			max = root;
	}

	return max;
}


int binaryTree::Minn(node * ptr) {//최소값을 구하는 함수

	int min=100000, nl, nr, root;

	if (ptr != 0) {
		root = ptr->data_;
		nl = Minn(ptr->lc_);
		nr = Minn(ptr->rc_);

		if (nl > nr)
			min = nr;
		else
			min = nl;

		if (root < min)
			min = root;

	}

	return min;
}

int binaryTree::Noon(node * ptr) {
	int sum = 0, root,nl,nr;

	if (ptr != 0) {
		root = ptr->data_;

		nl = Noon(ptr->lc_);
		nr = Noon(ptr->rc_);

		if (root % 2 == 1) {
			sum += 1 + nl + nr;
		}
	}

	return sum;
}

int main() {
	int n, p, f, c;

	cin >> n;
	cin >> p;
	binaryTree * bt = new binaryTree(p);
	for (int i = 1; i < n; i++) {
		cin >> p >> f >> c;
		if (f == 0) bt->AddLeftChild(p, c);
		else bt->AddRightChild(p, c);
	}

	cout << bt->MaxNumber() << " ";
	cout << bt->MinNumber() << " ";
	cout << bt->NumberOfOddNumbers() << " ";
	return 0;
}