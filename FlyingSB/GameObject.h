#pragma once
#include "RefCount.h"

class GameObject : public RefCount
{
protected:
	GameObject();
	virtual ~GameObject() = 0;

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};