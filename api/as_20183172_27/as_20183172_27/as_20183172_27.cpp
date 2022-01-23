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


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect[4] = {
		{ 10,60,60,110 },
		{ 60,10,110,60 },
		{ 60,110,110,160 },
		{ 110,60,160,110 }
	};

	static int sum;

	TCHAR direct[4][10] = { _T("왼쪽"),_T("위"),_T("아래"),_T("오른쪽") };

	HBRUSH brush1, brush2, b3;

	switch (iMsg) {

	case WM_CREATE:
		sum = 5;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		brush1 = CreateSolidBrush(RGB(255, 0, 0));
		brush2 = CreateSolidBrush(RGB(255, 255, 255));
		


		for (int i = 0; i<4; i++) {

			if (sum == i) {
				SelectObject(hdc, brush1);
			}
			else {
				SelectObject(hdc, brush2);
			}

			Rectangle(hdc, rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);

			if (sum != i) {
				DrawText(hdc, direct[i], _tcslen(direct[i]), &rect[i], DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			}

		}

		EndPaint(hwnd, &ps);

		break;

	case WM_KEYDOWN:
		if (VK_LEFT == wParam) {
			sum = 0;
		}

		else if (VK_UP == wParam) {
			sum = 1;
		}

		else if (VK_RIGHT == wParam) {
			sum = 3;
		}

		else if (VK_DOWN == wParam) {
			sum = 2;
		}

		else {
			sum = 4;
		}

		InvalidateRgn(hwnd, NULL, TRUE);

		break;

	case WM_KEYUP:

		if (VK_LEFT == wParam || VK_UP == wParam || VK_RIGHT == wParam || VK_DOWN == wParam) {
			sum = 4;
		}
		InvalidateRgn(hwnd, NULL, TRUE);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
