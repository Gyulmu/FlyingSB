#pragma once
#include "Renderer.h"

class renderer_test : public Renderer
{
public:
	renderer_test(GameObject* target);

private:
	virtual ~renderer_test() final;
	virtual void Render(const D2D1_MATRIX_3X2_F& transform) final;

public:
	void Color(const D2D1_COLOR_F& color);
	void Size(const D2D1_SIZE_F& size) { m_size = size; }
	void Pivot(const D2D1_POINT_2F& point) { m_pivot = point; }

private:
	ID2D1SolidColorBrush* m_brush = nullptr;
	D2D1_SIZE_F m_size = D2D1::SizeF();
	D2D1_POINT_2F m_pivot = D2D1::Point2F();
};