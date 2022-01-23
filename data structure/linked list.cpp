#include<stdio.h>

class Node{
public:
	Node(int d, Node*n = 0) {
		next = n;
		data = d;
	}
	Node* next;
	int data;
};

class list {
public:
	list() { lst = 0; }
	int GetSize();
	void Insert(int item);
	void Delete(int value);
	int GetAt(int position);
	int index(int value);
private:
	Node *lst; //newNode??
};

int list::GetSize() { //���� ��Ͽ� ���Ե� ������ ������ ������
	int count = 0;
	Node* ptr = lst;

	while (ptr != 0) {
		ptr = ptr->next;
		count++;
	}

	return count;
}

void list::Insert(int item) {// ������ �����Ǵ� ������ ��ġ�� ����

	if (lst == 0) {
		lst = new Node(item, 0);
		return;
	}

	if (item <= (lst->data)) {//�� �տ� ����
		lst = new Node(item, lst);
		return;
	}

	Node* ptr = lst;

	while (lst->next != 0 && ptr->next->data<item) {
		ptr = ptr->next;
	}

	ptr->next = new Node(item, ptr->next);
}

void list::Delete(int value) {
	// ��Ͽ��� key������ value�� ���� item�� ������. ������ �����ϴ� ��� ������ ������ 1 �پ��.

	Node* ptr = lst;

	if (lst == 0) return; // �󸮽�Ʈ�� ���

	if (value == lst->data) {
		lst = lst->next;
		delete ptr;
	}

	while (ptr->next !=0 && ptr->next->data != value) {
		ptr = ptr->next;
	}

	if (ptr->next == 0) return;
	Node *dptr = ptr->next;
	ptr->next = ptr->next->next;
	delete dptr;
}

int list::GetAt(int position) { // position�� GetSize()���� ���� ��� position ��ġ�� ���Ҹ� ������.

	Node*ptr = lst;

	for (int i = 0; i < position; i++) {
		if (ptr == 0) return -1;
		ptr = ptr->next;
	}

	return ptr->data;
}

int list::index(int value) {
	// ��Ͽ��� key������ value�� ���� item�� ��ġ�� ������.

	Node*ptr = lst;

	int idx = 0;
	
	while (ptr != 0) {
		if (value == ptr->data) return idx;
		ptr = ptr->next;
		idx++;
	}
	
	return -1;
}
