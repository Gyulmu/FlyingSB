#pragma once
#include <Windows.h>

class GameWindow
{
public:
	static void Initialize(HINSTANCE instance);
	static void Release();
	static void Update();

private:
	static void RegisterWindowClass(HINSTANCE instance);
	static LRESULT CALLBACK WindowProc(HWND wnd, UINT message, WPARAM wparam, LPARAM lparam);

private:
	static HWND s_wnd;
};