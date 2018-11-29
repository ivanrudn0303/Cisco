#include <windows.h>
#include <string.h>

#define EXIT_CODE 15

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
int EditCopy(HWND);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd; // дескриптор окна
	MSG msg; // структура сообщения
	WNDCLASS w;
	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc; // имя оконной функции
	w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)(WHITE_BRUSH);
	w.lpszClassName = "My Class";
	RegisterClass(&w);

	hwnd = CreateWindow("My Class", "Окно", WS_OVERLAPPEDWINDOW, 500, 300, 500, 380, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, 0);

	UpdateWindow(hwnd);
	BOOL bRet;
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
			return 1;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
		
		
		int res = EditCopy(hwnd);
		if (res == EXIT_CODE)
			return 0;

	}
	return msg.wParam;
}



LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}


#define ANSWER(question, ans) if(strstr(#question, (char*)buf))\
{\
	const char* str = #ans;\
	size_t len, i;\
	HGLOBAL hMem;\
	len = strlen(str) + 1;\
	hMem = GlobalAlloc(GMEM_MOVEABLE, len);\
	memcpy(GlobalLock(hMem), str, len);\
	GlobalUnlock(hMem);\
	EmptyClipboard();\
	SetClipboardData(CF_TEXT, hMem);\
}\
else


int EditCopy(HWND proc)
{
	Sleep(2000);
	HWND active = GetForegroundWindow();
	SetForegroundWindow(proc);
	HGLOBAL buf = NULL;
	if (IsClipboardFormatAvailable(CF_TEXT) == 0)
		return 0;
	if (OpenClipboard(GetForegroundWindow()) == 0)
		return 1;
	
	if ((buf = (HGLOBAL)GetClipboardData(CF_TEXT)) != NULL)
	{
	#include "Answer.h"
		if (strcmp((char*)buf, "exit") == 0)
		{
			GlobalUnlock(buf);
			CloseClipboard();
			return EXIT_CODE;
		}
		GlobalUnlock(buf);
		CloseClipboard();
		SetForegroundWindow(active);
	}
	return 0;
}
#undef ANSWER
