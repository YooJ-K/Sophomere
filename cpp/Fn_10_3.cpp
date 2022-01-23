#include <iostream>
using namespace std;

class Array {
	int size, rSize;
	int* arr, * ptr;
public:
	Array(int l) : size(l) {
		arr = new int[size];
	}

	Array(Array& a) {
		arr = new int[a.size];
		size = a.size;
		arr = a.arr;
	}

	int& operator[](int index);
	bool operator==(Array& k);
	bool operator!=(Array &k);

	friend ostream& operator<<(ostream& os, Array& k);
};

int& Array::operator[](int index) {
	int s = -1;
	if (index >= size || index < 0) return s;
	ptr = arr + index;
	return arr[index];
}

ostream& operator<<(ostream& os, Array& k) {
	for (int i = 0; i < k.size; i++) {
		cout << k.arr[i] << " ";

		if (k.ptr == (k.arr + i)) {
			k.rSize = i+1;
			break;
		}
	}

	return os;
}

bool Array:: operator==(Array& k) {
	int count = 0;
	for (int i = 0; i < rSize; i++) {
		if (k.arr[i] == arr[i]) count++;
	}

	if (count == rSize && size == k.size) return true;
	else return false;

}

bool Array::operator!=(Array &k) {
	int count = 0;
	for (int i = 0; i < rSize; i++) {
		if (k.arr[i] == arr[i]) count++;
	}

	if (count != rSize && size != k.size) return true;
	else return false;
}

void Fn10_3() {
	Array a1(10), a2(10), a3(10);

	a1[0] = 1; a1[1] = 2; a1[2] = 3;	
	a2[0] = 1; a2[1] = 2; a2[2] = 3;
	a3 = a1; a3[3] = 5;

	cout << "a1 배열은 : " << a1 << endl;
	cout << "a2 배열은 : " << a2 << endl;
	cout << "a3 배열은 : " << a3 << endl;

	cout << "a1 == a2 을 중복 정의 " << (a1 == a2) << endl;
	cout << "a1 != a3 을 중복 정의 " << (a1 != a3) << endl;
	cout << "a3 = a1 을 중복 정의 a3 : " << (a3 = a1) << endl;

}

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

	cout << "int 형 : ";
	cout << node << endl;
	DeleteNode(node);

	Node<double> *dnode = new Node<double>(10.5);
	for (int i = 0; i < 5; i++) {
		dnode->SetBack(dnode, (i + 1)*1.1);
	}

	cout << "double 형 : ";
	cout << dnode << endl;
	DeleteNode(dnode);
}

int main() {
	Fn10_3();
	cout << endl << "========================" << endl << endl;
	Fn12_3();
	return 0;
}