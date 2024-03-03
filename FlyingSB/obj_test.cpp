#include "obj_test.h"
#include "GameUI.h"

// Renderer
#include "renderer_bitmaps.h"

obj_test::obj_test()
{
}

obj_test::~obj_test()
{
}

void obj_test::Initialize()
{
	// Add Renderer
	m_renderer = new renderer_bitmaps(this);
	AddRenderer(m_renderer);
	m_renderer->Release();

	// Set Renderer
	ID2D1Bitmap* source = GameUI::D2D1BitmapFromFileName(L"CMIRO00.png");
	m_renderer->SetBitmaps(source, 6, 4);
	source->Release();
}

void obj_test::Update()
{
	if (GameUI::KeyPress(VK_LEFT))
		Translate(D2D1::SizeF(-1.f, 0.f));

	else if (GameUI::KeyPress(VK_RIGHT))
		Translate(D2D1::SizeF(1.f, 0.f));

	if (GameUI::KeyDown(VK_UP))
		Translate(D2D1::SizeF(0.f, -50.f));

	else if (GameUI::KeyUp(VK_DOWN))
		Translate(D2D1::SizeF(0.f, 50.f));

	for (int i = 0; i < 9; ++i)
	{
		if (GameUI::KeyDown('1' + i))
			m_renderer->Frame(i);
	}
}