#pragma once
#include "GameObject.h"
#include <d2d1.h>

class obj_test : public GameObject
{
public:
	obj_test();

private:
	virtual ~obj_test() final;
	virtual void Initialize() final;
};