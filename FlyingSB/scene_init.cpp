#include "scene_init.h"

// GameObject
#include "obj_test.h"

scene_init::scene_init()
{
}

scene_init::~scene_init()
{
}

void scene_init::Initialize()
{
	GameObject* object = Create<obj_test>();
	object->Release();
}
