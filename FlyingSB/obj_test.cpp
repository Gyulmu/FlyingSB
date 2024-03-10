#include "obj_test.h"
#include "GameUI.h"
#include "DataUI.h"

// Renderer
#include "renderer_bitmap.h"
#include "Animator.h"

obj_test::obj_test()
{
}

obj_test::~obj_test()
{
	if (m_animator)
		m_animator->Release();
}

void obj_test::Initialize()
{
	// Add Renderer
	m_renderer = new renderer_bitmap(this);
	SetRenderer(m_renderer);
	m_renderer->Release();

	// Animator
	m_animator = new Animator(m_renderer);
	m_animator->SetAnimation(DataUI::GetAnimation());
	m_animator->SetPlayType(Animator::PlayType::Repeat);
	m_animator->Play();
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

	m_animator->Update();
	m_renderer->SetBitmap(m_animator->GetBitmapFromFrame());

	if (GameUI::KeyDown(VK_ESCAPE))
		GameUI::Exit();
}