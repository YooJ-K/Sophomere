#include <windows.h>
#include <TCHAR.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG		 msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);  	// Ŀ�� ����

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
	static int x, y;
	static RECT rt;

	switch (iMsg) {
	case WM_CREATE:
		x = 20; y = 20;
		
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rt);
		rt.right = (rt.right / 40) * 40;
		rt.bottom = rt.bottom / 40 * 40;
		Rectangle(hdc, 0, 0, rt.right, rt.bottom);
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN:

		

		if (wParam == VK_RIGHT && x < rt.right-20) x += 40;
		else if (wParam == VK_LEFT && x > 40)x -= 40;
		else if (wParam == VK_UP && y > 40) y -= 40;
		else if (wParam == VK_DOWN && y< rt.bottom - 20)y += 40;
		else if (wParam == VK_HOME) {
			x = 20;
			y = 20;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}