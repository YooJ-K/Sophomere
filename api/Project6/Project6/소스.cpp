#include <windows.h>
#include <TCHAR.h>

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

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x, y, count, a, b;
	static RECT rt;
	HPEN hPen;

	switch (iMsg) {
	case WM_CREATE:
		x = 60; y = 20; a = 20; b = 20;
		count = 0;
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rt);
		hdc = BeginPaint(hwnd, &ps);
		rt.right = (rt.right / 40) * 40;
		rt.bottom = rt.bottom / 40 * 40;
		Rectangle(hdc, 0, 0, rt.right, rt.bottom);
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		(HPEN)SelectObject(hdc, hPen);
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
		SelectObject(hdc, hPen);
		DeleteObject(hPen);
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		(HPEN)SelectObject(hdc, hPen);
		Ellipse(hdc, a - 20, b - 20, a + 20, b + 20);
		SelectObject(hdc, hPen);
		DeleteObject(hPen);
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN:

		if (wParam == VK_RIGHT && x < rt.right - 20) {
			b = y;
			a = x;
			x += 40; 
		}
		else if (wParam == VK_LEFT && x > 40) {
			b = y;
			a = x;
			x -= 40;
		}
		else if (wParam == VK_UP && y > 40) {
			a = x;
			b = y;
			y -= 40;
		}
		else if (wParam == VK_DOWN && y < rt.bottom - 20) {
			a = x;
			b = y;
			y += 40;
		}
		else if (wParam == VK_HOME) {
			x = 20;
			y = 20;
			a = 60;
			b = 20;
		}
		else if (wParam == VK_RETURN) {
			count++;
			if (count % 2 != 0) {
				SetTimer(hwnd, 1, 70, NULL);
			}
			else {
				KillTimer(hwnd, 1);
			}
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_TIMER:
		x += 40;
		a += 40;
		if (x + 20 > rt.right) {
			a -= 40;
			x -= 40;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}