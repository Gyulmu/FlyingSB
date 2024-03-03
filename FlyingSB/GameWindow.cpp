#include "GameWindow.h"
#include "GameBase.h"

HWND GameWindow::s_wnd = nullptr;
ID2D1HwndRenderTarget* GameWindow::s_rendertarget = nullptr;

void GameWindow::Initialize(HINSTANCE instance)
{
    // Index
    // A. 창(Window)을 생성합니다.
    // B. D2D1 RenderTarget을 생성합니다.

    // A. 창(Window)을 생성합니다.
    //    A-1. 창(Window) 클래스를 등록합니다.
    RegisterWindowClass(instance);

    //    A-2. 클라이언트 역영 사이즈 기준으로
    //      창(Window)의 크기를 계산합니다.
    RECT rect = { 0, 0, 800, 600 };
    AdjustWindowRect(&rect, WS_CAPTION | WS_SYSMENU, FALSE);

    //    A-3. 창(Window)을 생성합니다.
    s_wnd = CreateWindowExA(
        0,
        "GameWindow",
        "FlyingSB",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        (GetSystemMetrics(SM_CXSCREEN) - (rect.right - rect.left)) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - (rect.bottom - rect.top)) / 2,
        rect.right - rect.left, 
        rect.bottom - rect.top,
        nullptr, nullptr, 
        instance, 
        nullptr);

    // B. D2D1 RenderTarget을 생성합니다.
    //    B-1. D2D1 Create Factory
    ID2D1Factory* factory = nullptr;
    D2D1CreateFactory(
        D2D1_FACTORY_TYPE_SINGLE_THREADED,
        &factory);

    //    B-2. D2D1 Create RenderTarget
    factory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(
            s_wnd,
            D2D1::SizeU(800, 600)),
        &s_rendertarget);

    factory->Release();
}

void GameWindow::Release()
{
    s_rendertarget->Release();
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

void GameWindow::BeginDraw()
{
    s_rendertarget->BeginDraw();
    s_rendertarget->Clear();
}

void GameWindow::EndDraw()
{
    s_rendertarget->EndDraw();
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
