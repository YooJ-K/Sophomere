#include<iostream>
using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node* next;

public:
	Node(T i);
	void SetBack(Node* pnode, T d);

	Node* pN(Node* pnode) {
		return pnode->next;
	}
	T pD(Node* pnode) {
		return pnode->data;
	}
};

Node<int>;
Node<double>;

template <typename T>
ostream& operator<<(ostream& os, const Node<T> *p) {

	Node<T> *s = (Node<T>*)p;

	if (s != NULL) {
		os << s->pD(s) << " ";
		while (s->pN(s) != NULL) {
			s = s->pN(s);
			os << s->pD(s) << " ";
		}
	}	

	return os;
}

template <typename T>
Node<T>::Node(T i) {
	data = i;
	next = NULL;
}

template <typename T>
void Node<T>::SetBack(Node<T>* pnode, T d) {
	Node* newNode = new Node<T>(d);

	while (pnode->next != NULL) {
		pnode = pnode->next;
	}
	pnode->next = newNode;
}

template <typename T>
void DeleteNode(Node<T>* p) {
	delete p;
}

void Fn12_3() {

	Node<int> *node;
	node = new Node<int>(10);
	for (int i = 0; i < 5; i++) {
		node->SetBack(node, i + 1);
	}

	cout << "int Çü : ";
	cout << node << endl;
	DeleteNode(node);

	Node<double> *dnode = new Node<double>(10.5);
	for (int i = 0; i < 5; i++) {
		dnode->SetBack(dnode, (i + 1)*1.1);
	}

	cout << "double Çü : ";
	cout << dnode << endl;
	DeleteNode(dnode);
}

int main() {
	Fn12_3();

	return 0;
}