#include "GameBase.h"
#include "GameData.h"
#include "GameUI.h"
#include <crtdbg.h>

#include "scene_init.h"

int WINAPI WinMain(
	_In_ HINSTANCE instance, 
    _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameBase::Initialize(instance);
	GameData::Initialize();

	// Load Scene
	Scene* scene = new scene_init;
	GameUI::LoadScene(scene);
	scene->Release();

	// Game Run
	GameBase::Run();

	// Release
	GameData::Release();
	GameBase::Release();

	return 0;
}