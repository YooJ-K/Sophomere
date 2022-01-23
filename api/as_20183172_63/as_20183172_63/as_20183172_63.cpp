#include <windows.h>
#include <TCHAR.H>
#include <stdio.h>
#include"resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_3(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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

BOOL CALLBACK Dlg6_3(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	static TCHAR word1[20], word2[20], re[20];
	double num1, num2;


	switch (iMsg) {
	case WM_INITDIALOG:

		return 1;

	case WM_COMMAND:
		GetDlgItemText(hDlg, ID_NUM1, word1, 20);
		GetDlgItemText(hDlg, ID_NUM2, word2, 20);

		num1 = _ttof(word1);
		num2 = _ttof(word2);

		switch (LOWORD(wParam)) {
		case ID_END:
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;

		case ID_PLUS:
			if (num1 == 0 && num2 == 0) {
				SetDlgItemText(hDlg, ID_RESULT, _T("입력을 해주세요."));
				break;
			}
			_stprintf_s(re, _T("%lf"), num1 + num2);
			SetDlgItemText(hDlg, ID_RESULT, re);
			break;
		case ID_MIN:
			if (num1 == 0 && num2 == 0) {
				SetDlgItemText(hDlg, ID_RESULT, _T("입력을 해주세요."));
				break;
			}
			_stprintf_s(re, _T("%lf"), num1 - num2);
			SetDlgItemText(hDlg, ID_RESULT, re);
			break;
		case ID_MULTI:
			if (num1 == 0 && num2 == 0) {
				SetDlgItemText(hDlg, ID_RESULT, _T("입력을 해주세요."));
				break;
			}
			_stprintf_s(re, _T("%lf"), num1 * num2);
			SetDlgItemText(hDlg, ID_RESULT, re);
			break;
		case ID_DIV:
			if (num1 == 0 && num2 == 0) {
				SetDlgItemText(hDlg, ID_RESULT, _T("입력을 해주세요."));
				break;
			}
			if (num2 == 0) {
				SetDlgItemText(hDlg, ID_RESULT, _T("나누기 연산이 불가합니다."));
				break;
			}

			_stprintf_s(re, _T("%lf"), num1 / num2);
			SetDlgItemText(hDlg, ID_RESULT, re);
			break;

		}		

		break;
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{

	case WM_CREATE:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_TRY:
			DialogBox(hInst, MAKEINTRESOURCE(ID_DIALOG1), hwnd, Dlg6_3);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}