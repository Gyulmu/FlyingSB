#include "obj_test.h"
#include "GameUI.h"

obj_test::obj_test()
{
}

obj_test::~obj_test()
{
	m_brush->Release();
}

void obj_test::Initialize()
{
	m_rendertarget = GameUI::RenderTarget();
	m_rendertarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Red),
		&m_brush);
}

void obj_test::Render()
{
	m_rendertarget->DrawRectangle(
		D2D1::RectF(100.f, 50.f, 200.f, 100.f),
		m_brush);
}
