#include "renderer_bitmaps.h"

renderer_bitmaps::renderer_bitmaps(GameObject* target) :
	Renderer(target)
{
}

renderer_bitmaps::~renderer_bitmaps()
{
	std::vector<ID2D1Bitmap*>::iterator iter;
	std::vector<ID2D1Bitmap*>::iterator iterEnd = m_bitmap.end();

	for (iter = m_bitmap.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Release();
	}
}

void renderer_bitmaps::Render(const D2D1_MATRIX_3X2_F& transform)
{
	RenderTarget()->SetTransform(transform);
	RenderTarget()->DrawBitmap(m_bitmap[m_frame]);
}

void renderer_bitmaps::SetBitmaps(ID2D1Bitmap* source, int div_x, int div_y)
{
	if (!m_bitmap.empty())
	{
		std::vector<ID2D1Bitmap*>::iterator iter;
		std::vector<ID2D1Bitmap*>::iterator iterEnd = m_bitmap.end();

		for (iter = m_bitmap.begin(); iter != iterEnd; ++iter)
			(*iter)->Release();

		m_bitmap.clear();
	}

	SliceBitmap(source, div_x, div_y);
}

void renderer_bitmaps::SliceBitmap(ID2D1Bitmap* source, int div_x, int div_y)
{
	D2D1_SIZE_F size = source->GetSize();
	size.width /= (float)div_x;
	size.height /= (float)div_y;
	m_bitmap.resize(div_x * div_y);

	// ...
	D2D1_RECT_F rect = D2D1::RectF(
		0, 0,
		size.width,
		size.height);

	// Slice Bitmap
	for (int y = 0; y < div_y; ++y)
	{
		for (int x = 0; x < div_x; ++x)
		{
			ID2D1BitmapRenderTarget* rendertarget = nullptr;
			RenderTarget()->CreateCompatibleRenderTarget(
				size,
				&rendertarget);

			rendertarget->BeginDraw();
			rendertarget->DrawBitmap(
				source,
				rect,
				1.f,
				D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
				D2D1::RectF(
					(float)x * size.width,
					(float)y * size.height,
					(float)(x + 1) * size.width,
					(float)(y + 1) * size.height));

			ID2D1Bitmap* bitmap = nullptr;
			rendertarget->EndDraw();
			rendertarget->GetBitmap(&bitmap);
			rendertarget->Release();

			int frame = x + y * div_x;
			m_bitmap[frame] = bitmap;
		}
	}
}
