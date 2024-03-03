#pragma once
#include "GameObject.h"
#include <d2d1.h>

class renderer_bitmaps;

class obj_test : public GameObject
{
public:
	obj_test();

private:
	virtual ~obj_test() final;
	virtual void Initialize() final;
	virtual void Update() final;

private:
	renderer_bitmaps* m_renderer = nullptr;
};