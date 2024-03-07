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
	obj_test* test_object = new obj_test;
	AddGameObjectToList(test_object);
	test_object->Release();
}
