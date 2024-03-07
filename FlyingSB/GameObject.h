#pragma once
#include "RefCount.h"
#include <d2d1.h>

class Renderer;

class GameObject : public RefCount
{
protected:
	GameObject();
	virtual ~GameObject() = 0;

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();

	void Transform(const D2D1_POINT_2F& point);
	void Transform(const D2D1_MATRIX_3X2_F& transform);
	const D2D1_MATRIX_3X2_F& Transform() { return m_transform; }
	void Translate(const D2D1_POINT_2F& point);
	void Translate(const D2D1_SIZE_F& size);
	void Translate(const D2D1_MATRIX_3X2_F& transform);

	void SetRenderer(Renderer* renderer);

private:
	D2D1_MATRIX_3X2_F m_transform = D2D1::Matrix3x2F::Identity();
	Renderer* m_renderer = nullptr;
};