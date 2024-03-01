#include "GameWindow.h"
#include "GameBase.h"

HWND GameWindow::s_wnd = nullptr;

void GameWindow::Initialize(HINSTANCE instance)
{
    RegisterWindowClass(instance);

    s_wnd = CreateWindowExA(
        0,
        "GameWindow",
        "FlyingSB",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        0, 0, 800, 600,
        nullptr, nullptr, 
        instance, 
        nullptr);
}

void GameWindow::Release()
{
    DestroyWindow(s_wnd);
}

void GameWindow::Update()
{
    MSG msg;

    if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

void GameWindow::RegisterWindowClass(HINSTANCE instance)
{
    WNDCLASSA wc;
    wc.style = 0;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = instance;
    wc.hIcon = nullptr;
    wc.hCursor = LoadCursorA(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = "GameWindow";

    RegisterClassA(&wc);
}

LRESULT GameWindow::WindowProc(HWND wnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message)
    {
    case WM_CLOSE:
        GameBase::Exit();
        break;

    default:
        return DefWindowProcA(wnd, message, wparam, lparam);
    }

    return 0;
}
