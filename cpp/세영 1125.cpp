#include<iostream>

using namespace std;

template <typename T>
class Node {
	friend ostream& operator<<(ostream& os, const Node<T>*p);
private:
	T data;
	Node * next;

public:
	Node(T i);
	void SetBack(Node<T>* p, T num = 0);
	void DeleteNode(Node<T>* p);
};

template <typename T>
Node<T> ::Node(T i) : data(i), next(NULL)
{
}

template <typename T>
void Node<T> ::SetBack(Node<T>*p, T num)
{
	Node<T> *nnode;
	nnode = new Node<T>(num);

	while (1)
	{
		if (p->next == NULL)
		{
			p->next = nnode;
			break;
		}

		p = p->next;
	}

}

template <typename T>
ostream& operator<<(ostream& os, const Node<T> *p)
{

	while (1)
	{
		os << p->data << " ";

		if (p->next == NULL)
			break;

		else
			p = p->next;
	}

	return os;
}

template <typename T>
void Node<T> ::DeleteNode(Node<T> *node)
{
	node->next = NULL;
}

void main()
{
	Node<int> *node;
	node = new Node<int>(10);
	for (int i = 0; i < 5; i++)
		node->SetBack(node, i + 1);

	cout << "intÇü : ";
	cout << node << endl;
	node->DeleteNode(node);

	Node<double> *dnode;
	dnode = new Node<double>(10.5);
	for (int i = 0; i < 5; i++)
		dnode->SetBack(dnode, (i + 1)*1.1);

	cout << "doubleÇü : ";
	cout << dnode << endl;
	dnode->DeleteNode(dnode);
}