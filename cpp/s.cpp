#include <stdio.h>
#include <stdlib.h>
#define LIST_LEN 100
#define TRUE 1
#define FALSE 0

typedef struct Point {
	int xpos, ypos;
}Point;

typedef Point LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} List;


void ListInit(List * plist) {
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List * plist, LData* data) {
	plist->arr[plist->numOfData].xpos = data->xpos;
	plist->arr[plist->numOfData].ypos = data->ypos;

	plist->numOfData++;
}

int LFirst(List * plist, LData * pdata) {

	if (plist->numOfData == 0) return FALSE;

	plist->curPosition = 0;

	pdata->xpos = plist->arr[plist->curPosition].xpos;
	pdata->ypos = plist->arr[plist->curPosition].ypos;

	return TRUE;
}

int LNext(List * plist, LData * pdata) {

	if (plist->numOfData == 0) return FALSE;
	if(plist->curPosition == plist->numOfData-1) return FALSE;

	plist->curPosition++;

	pdata->xpos = plist->arr[plist->curPosition].xpos;
	pdata->ypos = plist->arr[plist->curPosition].ypos;

	return TRUE;
}

LData* LRemove(List * plist) {
	int i;
	LData* ppos;

	ppos->xpos = plist->arr[plist->curPosition].xpos;
	ppos->ypos = plist->arr[plist->curPosition].ypos;

	for (i = plist->curPosition; i < plist->numOfData-1; i++) {
		plist->arr[i].xpos = plist->arr[i + 1].xpos;
		plist->arr[i].ypos = plist->arr[i + 1].ypos;
	}

	return ppos;
}

int LCount(List * plist) {
	return plist->numOfData;
}

void SetPointPos(LData* ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

int PointComp(LData *ppos, LData *compPos) {
	if(ppos->xpos == compPos->xpos && ppos->ypos == compPos->ypos) return TRUE;
	return FALSE;
}

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	/*** 4개의 데이터 저장 ***/
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, ppos))
	{
		printf("(%d, %d)\n", ppos->xpos, ppos->ypos);

		while (LNext(&list, ppos))
			printf("(%d, %d)\n", ppos->xpos, ppos->ypos);
	}
	printf("\n");

	/*** xpos가 2인 모든 데이터 삭제 ***/
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, ppos))
	{
		printf("(%d, %d)\n", ppos->xpos, ppos->ypos);

		while (LNext(&list, ppos))
			printf("(%d, %d)\n", ppos->xpos, ppos->ypos);
	}
	printf("\n");

	return 0;
}
