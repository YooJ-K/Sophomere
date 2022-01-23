#include <iostream>
using namespace std;

class Node {
	int data;
	Node* next;

	Node* cur;
	Node* head;
public:
	Node() {
		head = new Node();
		head->next = NULL;
		data = 0;
	}

	Node(int d) {
		head = new Node();
		head->next = NULL;
		data = d;
	}

	void SetBack(Node* p, int d);

	friend ostream& operator<<(ostream& os, const Node* p);
};

ostream& operator<<(ostream& os, const Node* p) {
	Node* s = p->head;
	while (s->next != NULL) {
		s = s->next;

		os << s->data << endl;
	}

	return os;
}

void Node::SetBack(Node* plist, int d) {
	cur = plist->head;

	while (plist->cur->next != NULL) {
		plist->cur = plist->cur->next;
	}

	Node* newNode = new Node(d);

	plist->cur->next = newNode;
}

void DeleteNode(Node* p) {
	delete p;
}


void Fn12_3() {
	
	Node *node;
	node = new Node(10);
	for (int i = 0; i < 5; i++) {
		node->SetBack(node, i + 1);
	}

	cout << "int Çü : ";
	cout << node << endl;
	DeleteNode(node);

	Node *dnode;
	dnode = new Node(10);
	for (int i = 0; i < 5; i++) {
		dnode->SetBack(dnode, i + 1);
	}

	cout << "double Çü : ";
	cout << dnode << endl;
	DeleteNode(dnode); 
}

int main() {
	Fn12_3();

	return 0;
}