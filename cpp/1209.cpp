#include<set>
#include<iostream>
using namespace std;

int main() {
	set<int> my_set;
	multiset<int> my_multi;

	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(3);

	my_multi.insert(my_set.begin(), my_set.end());

	my_multi.insert(3);

	multiset<int> ::iterator pos;
	multiset<int> ::iterator it;

	pos = my_multi.find(2);

	cout << *pos << endl;

	for (it = my_multi.begin(); it != my_multi.end(); it++) {
		cout << *it << endl;
	}

	my_multi.erase(3);
	my_multi.erase(pos);

	for (it = my_multi.begin(); it != my_multi.end(); it++) {
		cout << *it << endl;
	}
}

