#pragma once
#include "RefCount.h"
#include <d2d1.h>

class GameObject;

class Renderer : public RefCount
{
protected:
	Renderer(GameObject* target);
	virtual ~Renderer() = 0 {}

public:
	void Render();

private:
	virtual void Render(const D2D1_MATRIX_3X2_F& transform) = 0;

protected:
	GameObject* Target() { return m_target; }
	ID2D1RenderTarget* RenderTarget() { return m_rendertarget; }

private:
	GameObject* m_target;
	ID2D1RenderTarget* m_rendertarget;
};