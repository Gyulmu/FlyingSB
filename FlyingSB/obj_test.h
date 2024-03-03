#pragma once
#include "GameObject.h"
#include <d2d1.h>

class obj_test : public GameObject
{
public:
	obj_test();

private:
	virtual ~obj_test() final;
	virtual void Initialize() final;
	virtual void Render() final;

private:
	ID2D1RenderTarget* m_rendertarget = nullptr;
	ID2D1SolidColorBrush* m_brush = nullptr;
};