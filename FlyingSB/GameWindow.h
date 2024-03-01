#pragma once
#include <d2d1.h>

class GameWindow
{
public:
	static void Initialize(HINSTANCE instance);
	static void Release();
	static void Update();

	static void BeginDraw();
	static void EndDraw();

private:
	static void RegisterWindowClass(HINSTANCE instance);
	static LRESULT CALLBACK WindowProc(HWND wnd, UINT message, WPARAM wparam, LPARAM lparam);

private:
	static HWND s_wnd;
	static ID2D1HwndRenderTarget* s_rendertarget;
};