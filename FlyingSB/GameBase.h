#pragma once
#include <Windows.h>

class GameBase
{
public:
	static void Initialize(HINSTANCE instance);
	static void Release();
	static void Run();
};