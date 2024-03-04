#include "renderer_bitmap.h"

renderer_bitmap::renderer_bitmap(GameObject* target) :
	Renderer(target)
{
}

renderer_bitmap::~renderer_bitmap()
{
}

void renderer_bitmap::RenderImpl()
{
	if (m_bitmap)
		RenderTarget()->DrawBitmap(m_bitmap);
}

void renderer_bitmap::SetBitmap(ID2D1Bitmap* bitmap)
{
	m_bitmap = bitmap;
}
