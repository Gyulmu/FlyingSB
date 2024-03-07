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

void GameObject::Translate(const D2D1_POINT_2F& point)
{
	m_transform.dx += point.x;
	m_transform.dy += point.y;
}

void GameObject::Translate(const D2D1_SIZE_F& size)
{
	m_transform.dx += size.width;
	m_transform.dy += size.height;
}

void GameObject::Translate(const D2D1_MATRIX_3X2_F& transform)
{
	m_transform.dx += transform.dx;
	m_transform.dy += transform.dy;
	m_transform.m11 += transform.m11;
	m_transform.m12 += transform.m12;
	m_transform.m21 += transform.m21;
	m_transform.m22 += transform.m22;
}

void GameObject::SetRenderer(Renderer* renderer)
{
	if (m_renderer)
		m_renderer->Release();

	m_renderer = renderer;
	m_renderer->AddRef();
}
