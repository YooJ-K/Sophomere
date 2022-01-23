#include <windows.h>
#include <TCHAR.H>

#include "resource.h"
#include <stdlib.h>
#include <time.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hInst;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)

{

	HWND     hwnd;
	MSG   msg;
	WNDCLASS WndClass;

	hInst = hInstance;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   // 커서 지정
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); // 메뉴 이룸
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"),
		_T("Window Title Name"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{

		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return (int)msg.wParam;

}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memdc;
	PAINTSTRUCT ps;
	static HBITMAP hBitmap;
	static int num;
	static double width, height;
	const int PIC_R = 819, PIC_B = 614;
	static RECT rectView;

	typedef struct Point {
		double x, y;
	}Point;

	static Point pt[5][5], bit[5][5];

	typedef struct rr {
		int x, y;
	}RR;

	static RR r[5];

	switch (iMsg)
	{
	case WM_CREATE:
		hBitmap = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1)); // bitmap ID
		GetClientRect(hwnd, &rectView);
		width = 0;
		height = 0;
		num = 1;
		break;

	case WM_PAINT:
		
		hdc = BeginPaint(hwnd, &ps);
		memdc = CreateCompatibleDC(hdc);
		SelectObject(memdc, hBitmap);
		if (num == 1) {
			StretchBlt(hdc, 0, 0, rectView.right, rectView.bottom, //출력
				memdc, 0, 0, PIC_R, PIC_B, SRCCOPY); // 사진
		}
		else {
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num; j++) {
					StretchBlt(hdc, pt[r[i*num+j].x][r[i*num + j].y].x, pt[r[i*num + j].x][r[i*num + j].y].y, width, height, //출력
						memdc, bit[i][j].x, bit[i][j].y, PIC_R / num, PIC_B / num, SRCCOPY); // 사진
				}
			}
		}
		DeleteDC(memdc);
		EndPaint(hwnd, &ps);
		break;

	case WM_COMMAND:

		switch (LOWORD(wParam)) {
		case ID_3BY3:
			num = 3;
			break;

		case ID_4BY4:
			num = 4;
			break;

		case ID_5BY5:
			num = 5;
			break;
		}

		width = rectView.right / num;
		height = rectView.bottom / num;

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				pt[i][j].x = width * j;
				pt[i][j].y = height * i;
				bit[i][j].x = PIC_R / num * j;
				bit[i][j].y = PIC_B / num * i;
			}
		}

		srand(time(NULL));

		for (int i = 0; i < num*num; i++) { // random 을 위한 for
			r[i].x = rand() % num;
			r[i].y = rand() % num;

			for (int j = i - 1; j >= 0; j--) {
				if ((r[j].x == r[i].x) && (r[j].y == r[i].y)) {
					i--;
					break;
				}
			}
		}

		InvalidateRgn(hwnd, NULL, TRUE);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}