#define TRUE 1
#define FALSE 0

typedef int Priority;
typedef int HData;

typedef struct Harray {
	HData data;
	Priority pr;
}Harray;

typedef struct Heap {
	Harray da[101];
	int numOfData;
}Heap;

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);