#include <windows.h>
#include <TCHAR.H>
#include "resource.h"


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
	WndClass.lpszMenuName = NULL; // 메뉴 이름
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

void Animation(int xPos, int yPos, HDC hdc) {
	HDC memdc;
	HBITMAP RunBit[10], hBit, oldBit;
	static int count;
	int i;
	count++;
	count %= 10;
	RunBit[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	RunBit[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP3));
	RunBit[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP4));
	RunBit[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5));
	RunBit[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP6));
	RunBit[5] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP7));
	RunBit[6] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8));
	RunBit[7] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP9));
	RunBit[8] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP10));
	RunBit[9] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP11));

	memdc = CreateCompatibleDC(hdc);
	hBit= LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	oldBit = (HBITMAP)SelectObject(memdc, hBit);
	StretchBlt(hdc, 0, 0, rt.right, rt.bottom, memdc, 0, 0, 819, 614, SRCCOPY);
	BitBlt(hdc, 0, 0, 819, 614, memdc, 0, 0, SRCCOPY);
	SelectObject(memdc, RunBit[count]);
	BitBlt(hdc, xPos, yPos, 180, 240, memdc, 0, 0, SRCCOPY);
	SelectObject(memdc, oldBit);
	for (i = 0; i < 10; i++) DeleteObject(RunBit[i]);
	DeleteDC(memdc);
	DeleteObject(hBit);


}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rt;
	static int xPos;

	switch (iMsg)
	{
	case WM_CREATE:
		xPos = -100;
		SetTimer(hwnd, 1, 100, NULL);
		break;

	case WM_TIMER:
		xPos += 10;
		if (xPos > 819-240) xPos = -100;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rt);
		hdc = BeginPaint(hwnd, &ps);
		Animation(xPos, 300, hdc);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		break;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}