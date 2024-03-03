#include "renderer_test.h"

renderer_test::renderer_test(GameObject* target) :
	Renderer(target)
{
	RenderTarget()->CreateSolidColorBrush(
		D2D1::ColorF(0), 
		&m_brush);
}

renderer_test::~renderer_test()
{
	m_brush->Release();
}

void renderer_test::Render(const D2D1_MATRIX_3X2_F& transform)
{
	RenderTarget()->DrawRectangle(
		D2D1::RectF(
			transform.dx - m_pivot.x,
			transform.dy - m_pivot.y,
			transform.dx - m_pivot.x + m_size.width,
			transform.dy - m_pivot.y + m_size.height),
		m_brush);
}

void renderer_test::Color(const D2D1_COLOR_F& color)
{
	m_brush->SetColor(color);
}
