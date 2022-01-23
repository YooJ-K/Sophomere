#include <stdio.h>
#define LIST_LEN 100
#define TRUE 1
#define FALSE 0

typedef struct Point {
	int xpos, ypos;
}Point;

typedef struct ArrayList {
	Point arr[LIST_LEN];
	int numOfCount, cur;
}List;

void SetPointPos(Point* ppos, int xpos, int ypos); // 값을 저장
void ShowPointPos(Point* ppos); // 정보 출력
int PointComp(Point* pos1, Point* pos2); // 비교

void SetPointPos(Point* ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point* ppos) {
	printf("%d %d\n", ppos->xpos, ppos->ypos); 
}

int PointComp(Point* pos1, Point* pos2) {
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos) return TRUE;
	else return FALSE;
}

int main() {

}