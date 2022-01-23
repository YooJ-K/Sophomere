#include <iostream>
using namespace std;
#define MAX 10

class Queue {
public:
	Queue();
	void InsertQ(int el);
	void print();
private:
	int rear;
	int* arr = new int[MAX];
};

Queue::Queue() {
	rear = 0;
}

void Queue::InsertQ(int el) { //  큐에 새로운 데이터 항목 x를 삽입
	if (rear > MAX)
		return;

	arr[rear++] = el;
}

void Queue::print() {
	for (int i = 0; i < MAX; i++) {
		if (arr[i] < 0) {
			cout << arr[i] << " ";
		}
	}

	for (int i = 0; i < MAX; i++) {
		if (arr[i] > 0) {
			cout << arr[i] << " ";
		}
	}
}

int main() {
	int x;
	int num = MAX;
	Queue Q;

	while(num--) {
		cin >> x;
		Q.InsertQ(x);
	}
	
	Q.print();
}
