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

int ObjectKind = 3; // 전역변수들 : 원, 직선, 사각형 지정
int x1, y1, x2, y2; // 입력 문자열에서 뽑은 좌표값 à 10, 10, 100, 100
// 입력 문자열을 분리

void Parsing(TCHAR str[]) { // 전달 문자열 : str = “Ellipse(10, 10, 100, 100)
	TCHAR cmd[20], argNum[20]; // cmd = “Ellipse” argNum = “(10, 10, 100, 100)” 에 저장
	int i = 0, j = 0;
	while (str[i] != '(' ) cmd[j++] = str[i++]; // str 에서 “(“ 전까지 cmd 에 복사
		cmd[j] = NULL;
	j = 0;
	while (str[i] != NULL) argNum[j++] = str[i++]; // str 에서 “(“ 부터 끝까지 argNum 에 복사
	argNum[j] = NULL;
	// argNum 에서 숫자를 찾아 x1, y1, x2, y2 에 저장
	_stscanf_s(argNum, _T("(%d, %d, %d, %d)"), &x1, &y1, &x2, &y2); // 함수 각자 조사
	if (!_tcscmp(cmd, _T("Line"))) ObjectKind = 0;
	else if (!_tcscmp(cmd, _T("Ellipse"))) ObjectKind = 1;
	else if (!_tcscmp(cmd, _T("Rectangle"))) ObjectKind = 2;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR str[100];
	static int len;

	switch (iMsg) {

	case WM_CREATE:
		len = 0;
		break;

	case WM_CHAR:

		if (wParam == VK_BACK && len > 0) {
			len--;
		}
		else if (wParam == VK_RETURN) {
			Parsing(str);
			len = 0;
		}
		else {
			str[len++] = (TCHAR)wParam;
		}

		str[len] = NULL;

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		Rectangle(hdc, 10, 300, 300, 325);
		TextOut(hdc, 11, 305, str, len);

		if (ObjectKind == 0) {
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, x2, y2);
		}
		else if (ObjectKind == 1) {
			Ellipse(hdc, x1, y1, x2, y2);
		}
		else if (ObjectKind == 2) {
			Rectangle(hdc, x1, y1, x2, y2);
		}
		

		EndPaint(hwnd, &ps);

		ObjectKind = 3;

		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
