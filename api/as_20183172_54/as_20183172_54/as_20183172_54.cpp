#include "resource.h"
#include <windows.h>
#include <TCHAR.H>

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

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memdc;
	PAINTSTRUCT ps;
	static HBITMAP hBitmap;
	BITMAP bit;
	static int x, y, bx, by, a, b, sx, sy;
	static RECT rectView;

	switch (iMsg)
	{
	case WM_CREATE:
		hBitmap = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1)); // bitmap ID
		GetObject(hBitmap, sizeof(BITMAP), &bit);
		sx = bit.bmWidth;
		sy = bit.bmHeight;
		bx = by = 20;
		x = y = 0;
		a = b = 1;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rectView);
		memdc = CreateCompatibleDC(hdc);
		SelectObject(memdc, hBitmap);
		BitBlt(hdc, x, y, sx, sy, memdc, 0, 0, SRCCOPY);
		DeleteDC(memdc);
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_RETURN) {
			SetTimer(hwnd, 1, 100, NULL);
		}
		break;

	case WM_TIMER:
		x += a * bx;
		y += b * by;

		int oldX, oldY;

		if (x + bx + sx >= rectView.right) {
			if (a == 1) {
				oldX = x;
				x = rectView.right - sx;
				y = y + b * (x - oldX);
			}
			a = -1;
		}
		else if (x - bx <= rectView.left) {
			if (a == -1) {
				oldX = x;
				x = rectView.left + sx;
				y = y + b * (oldX - x);
			}
			a = 1;
		}

		if (y + by + sy >= rectView.bottom) {
			if (b == 1) {
				oldY = y;
				y = rectView.bottom - sy;
				x = x + a * (y - oldY);
			}
			b = -1;
		}
		else if (y - by <= rectView.top) {
			if (b == -1) {
				oldY = y;
				y = rectView.top + sy;
				x = x + a * (oldY-y);
			}

			b = 1;
		}

		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
