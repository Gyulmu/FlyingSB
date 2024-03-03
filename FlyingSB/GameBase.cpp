#include "GameBase.h"	
#include "GameInput.h"
#include "GameWIC.h"
#include "GameWindow.h"
#include "SceneManager.h"

bool GameBase::s_loop = true;

void GameBase::Initialize(HINSTANCE instance)
{
	GameWindow::Initialize(instance);
	GameWIC::Initialize();
	GameInput::Initialize();
	SceneManager::Initialize();
}

void GameBase::Release()
{
	SceneManager::Release();
	GameInput::Release();
	GameWIC::Release();
	GameWindow::Release();
}

void GameBase::Run()
{
	bool is_loaded = false;

	while (s_loop)
	{
		GameWindow::Update();
		GameInput::Update();
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
