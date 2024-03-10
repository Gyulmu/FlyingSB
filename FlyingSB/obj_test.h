#pragma once
#include "GameObject.h"
#include <d2d1.h>

class renderer_bitmap;
class Animator;

class obj_test : public GameObject
{
public:
	obj_test();

private:
	virtual ~obj_test() final;
	virtual void Initialize() final;
	virtual void Update() final;

private:
	renderer_bitmap* m_renderer = nullptr;
	float m_time = 0.f;
	bool m_switch = false;

	Animator* m_animator = nullptr;
};