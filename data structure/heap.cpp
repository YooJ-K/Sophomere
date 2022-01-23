#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int GetIdxParent(int idx);
int GetLeftChild(int idx);
int GetRightChild(int idx);
int CompareChild(Heap* ph, int idx);

void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}


int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void HInsert(Heap* ph, HData data, Priority pr) {

	if (ph->numOfData == 100)
		return;
	
	int idx = ++ph->numOfData;

	while (idx>1) {
		int bu = GetIdxParent(idx);

		if (ph->da[bu].pr > pr) {
			//우선순위 번호가 높을 수록 낮다.
			ph->da[idx] = ph->da[bu];
			idx = bu;
		}

		else
			break;
	}

	ph->da[idx] = { data, pr };
}

HData HDelete(Heap* ph) {

	int idx = 1;
	HData rd = ph->da[idx].data;

	Harray r = { ph->da[ph->numOfData].data, ph->da[ph->numOfData].pr };

	while (idx <= ph->numOfData) {

		if (r.pr < ph->da[CompareChild(ph,idx)].pr)
			break;
		int idx2 = CompareChild(ph, idx);

		if (idx2 == -1)
			break;

		if (ph->da[idx].pr > ph->da[idx2].pr) {
			ph->da[idx] = { ph->da[idx2].data, ph->da[idx2].pr };
			idx = idx2;
		}
		else
			break;
	}

	ph->numOfData--;


	return rd;

}

int GetIdxParent(int idx) {
	return idx / 2;
}

int GetLeftChild(int idx) {
	return idx * 2;
}

int GetRightChild(int idx) {
	return idx * 2 + 1;
}

int CompareChild(Heap* ph, int idx) {

	int idx1 = GetLeftChild(idx);
	int idx2 = GetRightChild(idx);

	if (idx1 > ph->numOfData)
		return -1;

	if (idx2 > ph->numOfData) // idx1 == ph->numOfData
		return idx1;

	if (ph->da[idx1].pr < ph->da[idx2].pr)
		return idx1;
	else
		return idx2;
}

int main() {
	Heap hea;
	HeapInit(&hea);
	
	for(int i=1;i<20;i++)
		HInsert(&hea, i*100, i);
	while (!HIsEmpty(&hea))
		printf("%d \n", HDelete(&hea));
}