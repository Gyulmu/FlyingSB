#include "BitmapData.h"
#include "GameUI.h"

std::map<std::string, std::vector<ID2D1Bitmap*>> BitmapData::s_bitmap;

void BitmapData::Initialize()
{
	ID2D1Bitmap* bitmap = GameUI::D2D1BitmapFromFileName(L"CMIRO00.png");
	std::vector<ID2D1Bitmap*> vec_bitmap;
	SliceBitmap(bitmap, vec_bitmap, 6, 4);
	s_bitmap.emplace("CMIRO00", vec_bitmap);
}

void BitmapData::Release()
{
	std::map<std::string, std::vector<ID2D1Bitmap*>>::iterator map_iter;
	std::map<std::string, std::vector<ID2D1Bitmap*>>::iterator map_iterEnd = s_bitmap.end();

	for (map_iter = s_bitmap.begin(); map_iter != map_iterEnd; ++map_iter)
	{
		std::vector<ID2D1Bitmap*>::iterator vec_iter;
		std::vector<ID2D1Bitmap*>::iterator vec_iterEnd = map_iter->second.end();

		for (vec_iter = map_iter->second.begin(); vec_iter != vec_iterEnd; ++vec_iter)
		{
			(*vec_iter)->Release();
		}
	}
}

ID2D1Bitmap* BitmapData::Bitmap(const std::string& name, int idx)
{
	return s_bitmap[name][idx];
}

void BitmapData::SliceBitmap(ID2D1Bitmap* source, std::vector<ID2D1Bitmap*>& slice, int div_x, int div_y)
{
	D2D1_SIZE_F size = source->GetSize();
	size.width /= (float)div_x;
	size.height /= (float)div_y;
	slice.resize(div_x * div_y);

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
			GameUI::RenderTarget()->CreateCompatibleRenderTarget(
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
			slice[frame] = bitmap;
		}
	}
}

namespace DataUI
{
	ID2D1Bitmap* Bitmap(const std::string& name, int idx)
	{
		return BitmapData::Bitmap(name, idx);
	}
}