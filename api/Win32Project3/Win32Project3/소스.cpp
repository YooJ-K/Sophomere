#include <windows.h>
#include <TCHAR.H>
#include "resource.h"
#include <stdio.h>

//비트맵 & MENU only

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

BOOL InRect(int x1, int y1, int x2, int y2, int mx, int my) {
	BOOL yesX=false, yesY=false;

	if ((x1 <= mx) && (mx <= x2)) {
		yesX = true;
	}

	if ((y1 <= my) && (my <= y2)) {
		yesY = true;
	}


	return yesX&&yesY;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int Case, count, row, c;
	static int startX, startY, endX, endY;
	static BOOL Selection;
	static HPEN hPen;
	static HBRUSH hBrush;
	CHOOSECOLOR COLOR;
	static COLORREF tmp[16], color;
	OPENFILENAME OFN, SFN;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T("Every File(*.*) \0*.*\0Text File\0*.txt;*.doc\0");
	int k;
	static TCHAR B[100][100];

	typedef struct Paint {
		int startX, startY, endX, endY, Case;
		HBRUSH hBrush;
		HPEN hPen;
		BOOL Selection = false;
	}Paint;

	static Paint Shape[50];

	switch (iMsg)
	{

	case WM_CREATE:
		Case = count = 0;
		row = c = 0;
		startX = startY = endX = endY = 0;
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		for (int i = 0; i < count; i++) {
			if (Shape[i].Selection) {
				Shape[i].hPen = hPen;
				Shape[i].hBrush = hBrush;
			}

			if (Shape[i].Case==4) {
				Shape[i].hPen = CreatePen(PS_SOLID, 1, BLACK_PEN);
				Shape[i].hBrush = CreateSolidBrush(BLACK_BRUSH);
			}

			SelectObject(hdc, Shape[i].hPen);
			SelectObject(hdc, Shape[i].hBrush);

			switch (Shape[i].Case) {
			case 1:
				MoveToEx(hdc, Shape[i].startX, Shape[i].startY, NULL);
				LineTo(hdc, Shape[i].endX, Shape[i].endY);
				break;

			case 2:
				Ellipse(hdc, Shape[i].startX, Shape[i].startY, Shape[i].endX, Shape[i].endY);
				break;

			case 3:
				
				Rectangle(hdc, Shape[i].startX, Shape[i].startY, Shape[i].endX, Shape[i].endY);
				if (Shape[i].Selection) {
					HPEN A = CreatePen(PS_SOLID, 1, BLACK_PEN);
					(HPEN)SelectObject(hdc, A);
					HBRUSH B = CreateSolidBrush(WHITE_BRUSH);
					(HBRUSH)SelectObject(hdc, B);

					int p = 20;

					Rectangle(hdc, Shape[i].startX - p, Shape[i].startY - p, Shape[i].startX, Shape[i].startY);
					Rectangle(hdc, Shape[i].endX, Shape[i].startY-p, Shape[i].endX+p, Shape[i].startY);
					Rectangle(hdc, Shape[i].startX-p, Shape[i].endY, Shape[i].startX, Shape[i].endY+p);
					Rectangle(hdc, Shape[i].endX, Shape[i].endY, Shape[i].endX+p, Shape[i].endY+p);



					DeleteObject(A);
					DeleteObject(B);
				}
				break;

			case 4:
				
				Rectangle(hdc, Shape[i].startX, Shape[i].startY, Shape[i].endX, Shape[i].endY);

				for (int j = 0; j <= row; j++) {
					TextOut(hdc, Shape[i].startX, Shape[i].startY + 20 * j, B[j], _tcslen(B[j]));
					DrawText
				}

				break;
			}

		}

		
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		if (wParam == VK_RETURN) {
			if ((row+1) * 20 <= Shape[count - 1].endY) {
				row++;
				c = 0;
			}
		}
		else if (wParam == VK_BACK) {
			if (c != 0) {
				B[row][--c] = NULL;
			}
			else if (c == 0) {
				B[row][c] = NULL;
				if (row != 0) {
					k = _tcslen(B[--row]);
					c = k;
				}				
			}
		}

		else {
			B[row][c++] = wParam;
			B[row][c] = NULL;
		}
		
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_WRITE:
			Case = 4;
			break;
		case ID_FILEOPEN:

			memset(&OFN, 0, sizeof(OPENFILENAME));
			OFN.lStructSize = sizeof(OPENFILENAME);
			OFN.hwndOwner = hwnd;
			OFN.lpstrFilter = filter;
			OFN.lpstrFile = lpstrFile;
			OFN.nMaxFile = 100;
			OFN.lpstrInitialDir = _T(".");
			if (GetOpenFileName(&OFN) != 0) {
				_stprintf_s(str, _T("%s 파일을 열겠습니까?"), OFN.lpstrFile);
				MessageBox(hwnd, str, _T("열기 선택"), MB_OK);
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
				MessageBox(hwnd, str, _T("저장하기 선택"), MB_OK);
			}
			break;
		case ID_LINE:
			Case = 1;
			break;

		case ID_ELLIPSE:
			Case = 2;
			break;

		case ID_RECTANGLE:
			Case = 3;

			break;

		case ID_PENCOLOR:
			for (int i = 0; i < 16; i++) tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
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
			for (int i = 0; i < 16; i++) tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
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
		}
		break;

	case WM_LBUTTONDOWN:
		startX =  endX = LOWORD(lParam);
		startY = endY = HIWORD(lParam);

		for (int i = 0; i < count; i++) {
			Shape[i].Selection = false;

			if (InRect(Shape[i].startX, Shape[i].startY, Shape[i].endX, 
				Shape[i].endY, startX, startY)) {
				Shape[i].Selection = true;
				break;
			}

		}
		break;

	case WM_LBUTTONUP:

		k = 0;

		for (int i = 0; i < count; i++) {
			if (Shape[i].Selection) {
				k = 1;
				break;
			}
		}

		if (k == 0) {
			endX = LOWORD(lParam);
			endY = HIWORD(lParam);

			if (Case != 0) {
				if (startX > endX)
				{
					int tmp = startX;
					startX = endX;
					endX = tmp;
				}

				if (startY > endY) {
					int tmp = startY;
					startY = endY;
					endY = tmp;
				}
				Shape[count].startX = startX;
				Shape[count].startY = startY;
				Shape[count].endX = endX;
				Shape[count].endY = endY;
				Shape[count].Case = Case;
				Shape[count].hBrush = hBrush;
				Shape[count++].hPen = hPen;
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
