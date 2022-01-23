#include <windows.h>
#include <TCHAR.h>
#include <math.h>
#define BSIZE 10
#define MOVE 20

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
	int mx, my, result;
	RECT mouse, cat;

	switch (iMsg)
	{
	case WM_CREATE:
		x = 50; y = 50;
		a = 400; b = 50;
		Selection = FALSE;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		mouse.left = x - BSIZE;
		mouse.right = x + BSIZE;
		mouse.top = y - BSIZE;
		mouse.bottom = y + BSIZE;
		DrawText(hdc, _T("쥐"), 1, &mouse, DT_CENTER || DT_VCENTER);

		cat.left = a - 3*BSIZE;
		cat.right = a + 3*BSIZE;
		cat.top = b- BSIZE;
		cat.bottom = b + BSIZE;
		DrawText(hdc, _T("고양이"), 3, &cat, DT_CENTER || DT_VCENTER);
		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		if (InCircle(x, y, mx, my)) Selection = TRUE;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_LBUTTONUP:
		Selection = FALSE;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if (Selection) {
			x = mx;
			y = my;
			SetTimer(hwnd, 1, 1, NULL);
			InvalidateRgn(hwnd, NULL, TRUE);
		}
		else {
			KillTimer(hwnd, 1);
		}
		break;

	case WM_TIMER:
		result = sqrt((x - a)*(x - a) + (y - b)*(y - b));
		if (x > a && x - a >= MOVE) a - MOVE;
		InvalidateRgn(hwnd, NULL, TRUE);

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}