#pragma once
#include <d2d1.h>

class Scene;

namespace GameUI
{
	void LoadScene(Scene* scene);
	ID2D1RenderTarget* RenderTarget();
	ID2D1Bitmap* D2D1BitmapFromFileName(const wchar_t* file_name);

	bool KeyPress(int key);
	bool KeyDown(int key);
	bool KeyUp(int key);

	float Duration();
}