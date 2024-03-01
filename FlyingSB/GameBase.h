#pragma once
#include <Windows.h>

class GameBase
{
public:
	static void Initialize(HINSTANCE instance);
	static void Release();
	static void Run();

	static void Exit() { s_loop = false; }

private:
	static void Render();

private:
	static bool s_loop;
};