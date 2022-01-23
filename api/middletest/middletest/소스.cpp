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

#include <math.h>
#include <time.h>

bool InCircle(int x, int y, int diameterA, int mx, int my, int diameterB) {
	if (sqrt((x - mx)*(x - mx) + (y - my)*(y - my)) < diameterA + diameterB) return true;
	else return false;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x,y, cc[10][3];
	static bool selection;
	static RECT rt;
	
	switch (iMsg)
	{
	case WM_CREATE:
		GetClientRect(hwnd, &rt);
		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
			//10~100 까지 10단위의 반지름 부여
			//1~GetClientRect()값의 right값, bottom값 부여
			
			cc[i][0] = rand() % rt.right; // x좌표
			cc[i][1] = rand() % rt.bottom; // y좌표
			cc[i][2] = (rand() % 10 + 1) * 10; // 반지름

			for (int j = i; j >=0; j--) {
				if (InCircle(cc[i][0], cc[i][1], cc[i][2], cc[j][0], cc[j][1], cc[j][2])) {
					i--;
					break;
				}
			}
			
			
		}
		x = y = 0;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i < 10; i++) {
			Ellipse(hdc, cc[i][0] - cc[i][2], cc[i][1] - cc[i][2], cc[i][0] + cc[i][2], cc[i][1] + cc[i][2]);
		}
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		selection = true;
		break;

	case WM_MOUSEMOVE:
		if (selection) {
			x = LOWORD(lParam);
			y = HIWORD(lParam);
		}
		InvalidateRgn(hwnd, NULL, TRUE);

		break;

	case WM_LBUTTONUP:
		selection = false;
		break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}