#pragma once
#include <d2d1.h>

class Scene;

namespace GameUI
{
	void LoadScene(Scene* scene);
	ID2D1RenderTarget* RenderTarget();
}