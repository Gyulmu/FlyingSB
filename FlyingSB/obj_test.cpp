#include "obj_test.h"

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