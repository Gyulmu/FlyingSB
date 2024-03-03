#include "obj_test.h"
#include "GameUI.h"

// Renderer
#include "renderer_test.h"

obj_test::obj_test()
{
}

obj_test::~obj_test()
{
}

void obj_test::Initialize()
{
	renderer_test* renderer = new renderer_test(this);
	renderer->Size(D2D1::SizeF(100.f, 50.f));
	renderer->Color(D2D1::ColorF(D2D1::ColorF::Red));
	AddRenderer(renderer);
	renderer->Release();
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
}
