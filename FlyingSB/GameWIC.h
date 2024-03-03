#pragma once
#include <wincodec.h>
#include <d2d1.h>

class GameWIC
{
public:
	static void Initialize();
	static void Release();

public:
	static ID2D1Bitmap* D2D1BitmapFromFileName(const wchar_t* file_name);

private:
	static IWICImagingFactory* s_factory;

};