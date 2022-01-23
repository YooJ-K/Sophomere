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
	static POINT R[4][8];
	static int width, height, count[4][8];
	static bool selection[4][8];
	static RECT rt;
	HPEN rPen, bPen;


	switch (iMsg)
	{

	case WM_CREATE:
		GetClientRect(hwnd, &rt);
		width = rt.right / 8;
		height = rt.bottom / 4;
		if (width > height) width = height;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				R[i][j] = { j * width,i * width };
			}
		}
		selection[4][8] = { false, };
		count[4][8] = { 0, };
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				Rectangle(hdc, R[i][j].x, R[i][j].y, R[i][j].x+ width, R[i][j].y+ width);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				if (selection[i][j]) {
					if (count[i][j] % 2 == 1) {
						rPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
						(HBRUSH)SelectObject(hdc, rPen);
					}
					else {
						bPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
						(HBRUSH)SelectObject(hdc, bPen);
					}
					Ellipse(hdc, R[i][j].x, R[i][j].y, R[i][j].x + width, R[i][j].y + width);
				}
			}
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		int x, y;
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		
		if (!(width * 8 < x || width * 4 < y)) {
			x /= width;
			y /= width;
			selection[y][x] = true;
			count[y][x]++;
		}
		
		InvalidateRgn(hwnd, NULL, FALSE);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
