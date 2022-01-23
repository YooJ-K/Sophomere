#include "resource.h"
#include <windows.h>
#include <TCHAR.H>

BOOL CALLBACK IDC_DIALOG1(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
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


BOOL CALLBACK Dlg6(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) 
{

	static float result;
	static int num = 0;

	int e1, e2;

	char* c;

	switch (iMsg) {

	case WM_INITDIALOG:
		return 1;

	case WM_COMMAND:
		e1 = (int)GetDlgItem(hDlg, IDC_E1);
		e2 = (int)GetDlgItem(hDlg, IDC_E2);

		switch (LOWORD(wParam)) {
		case IDC_PLUS:
			result = e1 + e2;
			num = 1;
			break;

		case IDC_MINUS:
			result = e1 - e2;
			num = 1;
			break;

		case IDC_MULTI:
			result = e1 * e2;
			num = 1;
			break;

		case IDC_DIV:
			result = e1 / e2;
			num = 1;
			break;

		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}

		break;

	}


	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;


	switch (iMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_1), hwnd, Dlg6);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

