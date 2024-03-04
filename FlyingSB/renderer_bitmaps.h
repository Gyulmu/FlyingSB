#pragma once
#include "Renderer.h"
#include <vector>

// Bitmap을 받아서 div_x, div_y 값을 통해 Slice 후 저장합니다.
// frame을 설정해서 원하는 Bitmap을 출력합니다.
class renderer_bitmaps : public Renderer
{
public:
	renderer_bitmaps(GameObject* target);

private:
	virtual ~renderer_bitmaps() final;
	virtual void RenderImpl() final;

public:
	void SetBitmaps(ID2D1Bitmap* source, int div_x, int div_y);
	void Frame(int frame) { m_frame = frame; }

private:
	void SliceBitmap(ID2D1Bitmap* source, int div_x, int div_y);

private:
	std::vector<ID2D1Bitmap*> m_bitmap;
	D2D1_POINT_2F m_pivot = D2D1::Point2F();
	int m_frame = 0;
};