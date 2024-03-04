#include "Renderer.h"
#include "GameWindow.h"
#include "GameObject.h"

Renderer::Renderer(GameObject* target) :
	m_target(target),
	m_rendertarget(GameWindow::RenderTarget())
{
}

void Renderer::Render()
{
	m_rendertarget->SetTransform(m_target->Transform());
	RenderImpl();
}