#pragma once
#include "Scene.h"

class scene_init : public Scene
{
public:
	scene_init();

private:
	virtual ~scene_init() final;
	virtual void Initialize() final;
};