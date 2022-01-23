#include <windows.h>
#include <TCHAR.H>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG   msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   // 커서 지정

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
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x1, x2, y1, y2, oldX, oldY,sumX, sumY;
	static bool num;

	switch (iMsg) {

	case WM_CREATE:
		x1 = x2 = 20; 
		y1 = y2 = 20;
		oldX = x1; 
		oldY = y1;
		num = FALSE;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, x1 - 20, y1 - 20, x1 + 20, y1 + 20);
		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		num = TRUE; 
		hdc = GetDC(hwnd);
		SetROP2(hdc, R2_XORPEN);
		SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y2);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONUP:
		num = FALSE; 
		hdc = GetDC(hwnd);
		SetROP2(hdc, R2_XORPEN);
		SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y2);
		ReleaseDC(hwnd, hdc);
		x2 = LOWORD(lParam);
		y2 = HIWORD(lParam);
		sumX = abs(x1 - x2);
		sumY = abs(y1 - y2);
		sumX /= 10;
		sumY /= 10;
		SetTimer(hwnd, 1, 100, NULL);		
		break;

	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		if (num) {
			SetROP2(hdc, R2_XORPEN);
			SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, oldX, oldY);
			x2 = LOWORD(lParam);
			y2 = HIWORD(lParam);
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, x2, y2);
			oldX = x2; oldY = y2;
		}
		ReleaseDC(hwnd, hdc);
		break;

	case WM_TIMER:
		/*if (x1 == x2 && y1 == y2) {
			KillTimer(hwnd, 1);
		}
		if (abs(x1 - x2) < 40) x1 = x2;
		if (abs(y1 - y2) < 40) y1 = y2;*/
		if (abs(x1 - x2) < sumX && abs(y1 - y2) < sumY) {
			x1 = x2;
			y1 = y2;
			KillTimer(hwnd, 1);
		}
		if (x1 < x2) x1 += sumX;
		if (x1 > x2) x1 -= sumX;
		if (y1 < y2) y1 += sumY;
		if (y1 > y2) y1 -= sumY;

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}