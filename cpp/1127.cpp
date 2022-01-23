#include <iostream>
using namespace std;

template <typename T>
class Node {
	template<typename U>
	friend ostream& operator<<(ostream& os, const Node<U> *p);
private:
	T data;
	Node *next;
public:
	Node(T i = 0) {
		data = i;
		next = NULL;
	}

	void setBack(Node<T> *node, T a) {
		Node<T> *newnode = new Node<T>[10];
		newnode->data = a;
		newnode->next = NULL;
		while (1)
		{
			if (node->next == NULL) {
				break;
			}
			else {
				node = node->next;
			}
		}
		node->next = newnode;
	}
};

template <typename U>
ostream& operator<<(ostream& os, const Node<U> *p) {
	while (1)
	{
		os << p->data << " ";
		if (p->next == NULL) {
			break;
		}
		else {
			p = p->next;
		}

	}
	return os;
}

template <typename T>
void DeleteNode(Node<T> *p) {
	delete p;
}

void Fn12_3() {
	Node<int> *node;
	node = new Node<int>(10);
	for (int i = 0; i < 5; i++) {
		node->setBack(node, i + 1);
	}
	cout << "intÇü : ";
	cout << node << endl;
	DeleteNode(node);

	Node<double> *dnode;
	dnode = new Node<double>(10.5);
	for (int i = 0; i < 5; i++) {
		dnode->setBack(dnode, (i + 1)*1.1);
	}
	cout << "double Çü : ";
	cout << dnode << endl;
	DeleteNode(dnode);
}