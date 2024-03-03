#include "GameBase.h"	
#include "GameWindow.h"
#include "SceneManager.h"

bool GameBase::s_loop = true;

void GameBase::Initialize(HINSTANCE instance)
{
	GameWindow::Initialize(instance);
	SceneManager::Initialize();
}

void GameBase::Release()
{
	SceneManager::Release();
	GameWindow::Release();
}

void GameBase::Run()
{
	bool is_loaded = false;

	while (s_loop)
	{
		GameWindow::Update();
		is_loaded = SceneManager::Update();

		// Render
		Render();

		// Load Scene
		if (is_loaded)
			SceneManager::LoadScene();
	}
}

void GameBase::Render()
{
	GameWindow::BeginDraw();
	SceneManager::Render();
	
	// End Draw
	GameWindow::EndDraw();
}
