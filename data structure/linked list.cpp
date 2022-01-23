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

int list::GetSize() { //현재 목록에 포함된 원소의 개수를 돌려줌
	int count = 0;
	Node* ptr = lst;

	while (ptr != 0) {
		ptr = ptr->next;
		count++;
	}

	return count;
}

void list::Insert(int item) {// 정렬이 유지되는 유일한 위치에 삽입

	if (lst == 0) {
		lst = new Node(item, 0);
		return;
	}

	if (item <= (lst->data)) {//맨 앞에 삽입
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
	// 목록에서 key값으로 value를 갖는 item을 삭제함. 삭제에 성공하는 경우 원소의 개수가 1 줄어듬.

	Node* ptr = lst;

	if (lst == 0) return; // 빈리스트인 경우

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

int list::GetAt(int position) { // position이 GetSize()보다 작은 경우 position 위치의 원소를 돌려줌.

	Node*ptr = lst;

	for (int i = 0; i < position; i++) {
		if (ptr == 0) return -1;
		ptr = ptr->next;
	}

	return ptr->data;
}

int list::index(int value) {
	// 목록에서 key값으로 value를 갖는 item의 위치를 돌려줌.

	Node*ptr = lst;

	int idx = 0;
	
	while (ptr != 0) {
		if (value == ptr->data) return idx;
		ptr = ptr->next;
		idx++;
	}
	
	return -1;
}
