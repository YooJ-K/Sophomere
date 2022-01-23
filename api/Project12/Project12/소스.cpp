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
	switch (iMsg)
	{
		HDC hdc;
		PAINTSTRUCT ps;
		static HPEN hPen[4][8];
		static RECT rectView;
		static int x[9], y[5];
		static int S[4][8];
		static int q, w;
		static int count, n[4][8];
	case WM_CREATE:
		count = 0;
		q = 0, w = 0;
		n[4][8] = { 0, };
		S[4][8] = { 0, };
		x[9] = { 0, };
		y[5] = { 0, };
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &rectView);
		hdc = BeginPaint(hwnd, &ps);
		x[8] = 8 * (int)(rectView.right / 8);
		y[4] = 4 * (int)(rectView.bottom / 4);
		for (int i = 0; i < 4; i++) {
			y[i] = i * (int)(rectView.bottom / 4);
			for (int j = 0; j < 8; j++) {
				x[j] = j * (int)(rectView.right / 8);
				Rectangle(hdc, j*(int)(rectView.right / 8), i*(int)(rectView.bottom / 4), (j + 1)*(int)(rectView.right / 8), (i + 1)*(int)(rectView.bottom / 4));
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				if (S[i][j] == 1) {
					if (count % 2 == 0) {//파랑
						hPen[i][j] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
					}
					else {
						hPen[i][j] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
					}
					n[i][j] = 1;
					S[i][j] = 3;
				}
				if (n[i][j] == 1) {
					(HPEN)SelectObject(hdc, hPen[i][j]);
					Ellipse(hdc, x[j], y[i], x[j + 1], y[i + 1]);
				}
			}
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		int a, b;
		a = LOWORD(lParam);
		b = HIWORD(lParam);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				if (x[j]<a&&x[j + 1]>a&&y[i]<b&&y[i + 1]>b) {
					if (S[i][j] != 3) {
						S[i][j] = 1;
						count++;
					}

					
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
