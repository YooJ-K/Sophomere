#include "resource.h"
#include <windows.h>
#include <TCHAR.H>
#define FONT_SIZE 10

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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); // 메뉴 이름
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
	static int caseN, count, row, i;
	static BOOL Drag;
	static int startX, startY, endX, endY;
	CHOOSECOLOR COLOR;
	static COLORREF tmp[16], color;
	static HBRUSH hBrush, bBrush;
	static HPEN hPen, bPen;
	OPENFILENAME SFN;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T("Every File(*.*) \0*.*\0Text File\0*.txt;*.doc\0");
	static RECT rt;
	static int x, y, k;
	static TCHAR te[100][100];

	typedef struct StoE {
		int startX, startY, endX, endY, Case;
	};

	static StoE shape[30];


	switch (iMsg)
	{
	case WM_CREATE:
		caseN = count = x = y = row = 0;
		startX = startY = endX = endY = 0;
		bBrush = CreateSolidBrush(RGB(0, 0, 0));
		bPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		hBrush = CreateSolidBrush(RGB(255,255,255));
		hPen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
		te[0][0] = NULL;
		i = 0;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (caseN == 4) {
			(HBRUSH)SelectObject(hdc, bBrush);
			(HPEN)SelectObject(hdc, bPen);
		}
		else {
			(HBRUSH)SelectObject(hdc, hBrush);
			(HPEN)SelectObject(hdc, hPen);
		}
		if (caseN == 1) {
			MoveToEx(hdc, startX, startY, NULL);
			LineTo(hdc, endX, endY);
		}
		else if (caseN == 2) {
			Ellipse(hdc, startX, startY, endX, endY);
		}
		else if (caseN == 3 || caseN == 4) {
			Rectangle(hdc, startX, startY, endX, endY);
			if (caseN == 4) {
				k = (endY - startY) / FONT_SIZE;
								
				for(int i=0;i<k;i++) TextOut(hdc, x, y+i*20, te[i], _tcslen(te[i]));
			}
		}
		
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		k = (endX - startX) / FONT_SIZE;
		
		if (wParam == VK_BACK) {
			count--;
			break;
		}

		else if (wParam == VK_RETURN || count == k) {
			row++;
			count = 0;
			break;
		}

		else {
			te[row][count++] = wParam;

		}
		
		te[row][count] = NULL;
		
		InvalidateRgn(hwnd, NULL, FALSE);

		break;

	case WM_LBUTTONDOWN:
		Drag = TRUE;
		startX = endX = LOWORD(lParam);
		startY = endY = HIWORD(lParam);


		x = startX;
		y = startY;
		break;

	case WM_LBUTTONUP:
		Drag = FALSE;
		InvalidateRgn(hwnd, NULL, FALSE);
		break;

	case WM_MOUSEMOVE:
		
		hdc = GetDC(hwnd);
		if (Drag) {
			if (caseN == 1) {
				SetROP2(hdc, R2_XORPEN);
				SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));
				MoveToEx(hdc, startX, startY, NULL);
				LineTo(hdc, endX, endY);
				endX = LOWORD(lParam);
				endY = HIWORD(lParam);
				MoveToEx(hdc, startX, startY, NULL);
				LineTo(hdc, endX, endY);
			}

			else if (caseN == 2) {
				SetROP2(hdc, R2_XORPEN);
				SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));
				Ellipse(hdc, startX, startY, endX, endY);
				endX = LOWORD(lParam);
				endY = HIWORD(lParam);
				Ellipse(hdc, startX, startY, endX, endY);
			}

			else if (caseN == 3 || caseN == 4) {
				SetROP2(hdc, R2_XORPEN);
				SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));
				Rectangle(hdc, startX, startY, endX, endY);
				endX = LOWORD(lParam);
				endY = HIWORD(lParam);
				Rectangle(hdc, startX, startY, endX, endY);
			}


		}
		ReleaseDC(hwnd, hdc);

		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_LINE:
			caseN = 1;
			break;

		case ID_ELLIPSE:
			caseN = 2;
			break;

		case ID_RECTANGLE:
			caseN = 3;
			break;

		case ID_WRITE:
			caseN = 4;
			break;

		case ID_PENCOLOR:
			for (i = 0; i < 16; i++) tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
			memset(&COLOR, 0, sizeof(CHOOSECOLOR));
			COLOR.lStructSize = sizeof(CHOOSECOLOR);
			COLOR.hwndOwner = hwnd;
			COLOR.lpCustColors = tmp;
			COLOR.Flags = CC_FULLOPEN;
			if (ChooseColor(&COLOR) != 0) {
				color = COLOR.rgbResult;
				hPen = CreatePen(PS_SOLID, 1, color);
				startX = startY = endX = endY = 0;
				InvalidateRgn(hwnd, NULL, FALSE);
			}
			break;
		case ID_FACECOLOR:
			for (i = 0; i < 16; i++) tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
			memset(&COLOR, 0, sizeof(CHOOSECOLOR));
			COLOR.lStructSize = sizeof(CHOOSECOLOR);
			COLOR.hwndOwner = hwnd;
			COLOR.lpCustColors = tmp;
			COLOR.Flags = CC_FULLOPEN;
			if (ChooseColor(&COLOR) != 0) {
				color = COLOR.rgbResult;
				hBrush = CreateSolidBrush(color);
				startX = startY = endX = endY = 0;
				InvalidateRgn(hwnd, NULL, FALSE);
			}
			
			break;
		case ID_FILESAVE:
			memset(&SFN, 0, sizeof(OPENFILENAME));
			SFN.lStructSize = sizeof(OPENFILENAME);
			SFN.hwndOwner = hwnd;
			SFN.lpstrFilter = filter;
			SFN.lpstrFile = lpstrFile;
			SFN.nMaxFile = 256;
			SFN.lpstrInitialDir = _T(".");
			if (GetSaveFileName(&SFN) != 0) {
				_stprintf_s(str, _T("%s 파일로 저장하겠습니까?"), SFN.lpstrFile);
				MessageBox(hwnd, str, _T("저장하기 선택"), MB_OKCANCEL);
			}
			break;
		}
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}