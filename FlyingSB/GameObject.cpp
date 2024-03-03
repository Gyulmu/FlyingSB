#include "GameObject.h"
#include "Renderer.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	if (m_renderer)
		m_renderer->Release();
}

void GameObject::Initialize()
{
}

void GameObject::Update()
{
}

void GameObject::Render()
{
	if (m_renderer)
		m_renderer->Render();
}

void GameObject::Transform(const D2D1_POINT_2F& point)
{
	m_transform.dx = point.x;
	m_transform.dy = point.y;
}

void GameObject::Transform(const D2D1_MATRIX_3X2_F& transform)
{
	m_transform = transform;
}

void GameObject::AddRenderer(Renderer* renderer)
{
	if (m_renderer)
		m_renderer->Release();

	m_renderer = renderer;
	m_renderer->AddRef();
}
