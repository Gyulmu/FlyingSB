#pragma once
#include "RefCount.h"

class Scene : public RefCount
{
protected:
	Scene() {}
	virtual ~Scene() = 0 {}

public:
	virtual void Initialize() = 0;
	void Update();
	void Render();
};