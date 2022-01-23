#include <iostream>
using namespace std;

template <typename T>
class Node {
	T data;
	Node* next;
	Node* head;
	Node* cur;
public:
	Node();
	Node(T data_);
	bool setBack(Node* node, T data);
	bool DeleteNode(Node* node);
};

template <typename T>
Node<T>::Node() {
	head = new Node<T>;
	head->data = 0;
	head->next = NULL;
}

template <typename T>
Node<T>::Node(T data_) {
	head = new Node<T>;
	head->data = data_;
	head->next = NULL;
}

template <typename T>
bool Node<T>::setBack(Node* node, T data) {

	Node* newNode = new Node<T>(data);
	newNode->data = data;
	newNode->next = NULL;

	if (head = NULL) cur = head = newNode;
	else {
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
	}
	
	return true;
}

template <typename T>
bool Node<T>::DeleteNode(Node* node) {
	cur = node->head;

	while (cur->next != NULL) {
		Node * del;
		del = cur;
		cur = cur->next;
		delete del;
	}

	return true;
}

void Fn12_3() {

	Node<int> *node;
	node = new Node<int>(10);
	for (int i = 0; i < 5; i++) {
		node->setBack(node, i + 1);
	}

	cout << "int Çü : ";
	cout << node << endl;
	node->DeleteNode(node);

	Node<double> *dnode;
	dnode = new Node<double>(10);
	for (int i = 0; i < 5; i++) {
		dnode->setBack(dnode, i + 1);
	}

	cout << "double Çü : ";
	cout << dnode << endl;
	dnode->DeleteNode(dnode);
}

int main() {
	Fn12_3();

	return 0;
}