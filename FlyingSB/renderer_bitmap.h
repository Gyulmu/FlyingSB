#pragma once
#include "Renderer.h"

class renderer_bitmap : public Renderer
{
public:
	renderer_bitmap(GameObject* target);

private:
	virtual ~renderer_bitmap() final;
	virtual void RenderImpl() final;

public:
	void SetBitmap(ID2D1Bitmap* bitmap);

private:
	ID2D1Bitmap* m_bitmap = nullptr;
};