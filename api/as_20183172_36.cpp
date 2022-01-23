#include <windows.h>
#include <TCHAR.h>
#include <math.h>
#define BSIZE 40

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG       msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);     // 커서 지정

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
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

double LengthPts(int x1, int y1, int x2, int y2) {
	return(sqrt((float)(x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
}

BOOL InCircle(int x, int y, int mx, int my) {
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;
	else return FALSE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x, y, a, b;
	static BOOL Selection;
	int mx, my;
	static RECT mouse, cat;

	switch (iMsg)
	{
	case WM_CREATE:
		x = 50; y = 100;
		a = 400; b = 100;
		Selection = FALSE;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		mouse.left = x - 10;
		mouse.top = y - 10;
		mouse.right = x + 10;
		mouse.bottom = y + 10;
		DrawText(hdc, _T("쥐"), 1, &mouse, DT_CENTER);

		cat.left = a - 30;
		cat.top = b - 10;
		cat.right = a + 30;
		cat.bottom = b + 10;
		DrawText(hdc, _T("고양이"), 3, &cat, DT_CENTER);

		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		if (InCircle(x, y, mx, my)) { 
			Selection = TRUE; 
			
		}
		SetTimer(hwnd, 1, 500, NULL);
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_LBUTTONUP:
		Selection = FALSE;
		KillTimer(hwnd, 1);
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if (Selection) {
			x = mx;
			y = my;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
		break;

	case WM_TIMER:
		if (abs(a - x) <= BSIZE && abs(b - y) <= BSIZE) {
			a = x;
			b = y;
		}
		else {
			if (x < a) a = a - BSIZE;
			if (x > a) a = a + BSIZE;
			if (y > b) b = b + BSIZE;
			if (y < b) b = b - BSIZE;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
