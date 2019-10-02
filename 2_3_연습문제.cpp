//실습 2-4 WM_CHAR 메시지 처리하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	switch (iMsg) {

	case WM_CREATE:
		break;

	case WM_CHAR:
		hdc = GetDC(hwnd);
		TextOut(hdc, 0, 0, _T("어떤 키를 누를 때 이 문장이 보이나요?"), 22);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
 
//실습 2-5 입력 문자 처리하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static TCHAR str[100];

	switch (iMsg) {

	case WM_CREATE:
		break;

	case WM_CHAR:
		hdc = GetDC(hwnd);
		str[0] = wParam;
		str[1] = NULL;
		TextOut(hdc, 0, 0, str, _tcslen(str));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

//실습 2-6 입력 문자열 처리하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static TCHAR str[100];
	static int count;

	switch (iMsg) {

	case WM_CREATE:
		count = 0;
		break;

	case WM_CHAR:
		hdc = GetDC(hwnd);
		str[count++] = wParam;
		str[count] = NULL;
		TextOut(hdc, 0, 0, str, _tcslen(str));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

//실습 2-7 WM_PAINT 메시지 처리하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR str[100];
	static int count;

	switch (iMsg) {

	case WM_CREATE:
		count = 0;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, str, _tcslen(str));
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		hdc = GetDC(hwnd);
		str[count++] = wParam;
		str[count] = NULL;
		TextOut(hdc, 0, 0, str, _tcslen(str));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

 
//실습 2-8 문자 저장과 출력 구분하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR str[100];
	static int count;

	switch (iMsg) {

	case WM_CREATE:
		count = 0;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, str, _tcslen(str));
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		str[count++] = wParam;
		str[count] = NULL;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

//실습 2-9 BackSpace 키 입력 처리하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR str[100];
	static int count;

	switch (iMsg) {

	case WM_CREATE:
		count = 0;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, str, _tcslen(str));
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		if (wParam == VK_BACK && count > 0) count--;
		else str[count++] = wParam;
		str[count] = NULL;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}


 
//실습 2-10 Enter 키 입력 처리하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR str[100];
	static int count, yPos;

	switch (iMsg) {

	case WM_CREATE:
		count = 0;
		yPos = 0;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, yPos, str, _tcslen(str));
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		if (wParam == VK_BACK && count > 0) count--;
		else if (wParam == VK_RETURN) {
			count = 0;
			yPos += 20;
		}
		else str[count++] = wParam;
		str[count] = NULL;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}


//실습 2-11 DrawText() 함수를 이용해 Enter 키 입력 처리하기

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR str[100];
	static int count, yPos;
	RECT rt = { 0,0,1000,1000 };

	switch (iMsg) {

	case WM_CREATE:
		count = 0;
		yPos = 0;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		DrawText(hdc, str, _tcslen(str), &rt, DT_TOP | DT_LEFT);
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		if (wParam == VK_BACK && count > 0) count--;
		else if (wParam == VK_RETURN) {
			count = 0;
			yPos += 20;
		}
		else str[count++] = wParam;
		str[count] = NULL;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
