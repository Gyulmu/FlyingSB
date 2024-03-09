#include "GameBase.h"	
#include "GameInput.h"
#include "GameTimer.h"
#include "GameWIC.h"
#include "GameWindow.h"
#include "SceneManager.h"

bool GameBase::s_loop = true;

void GameBase::Initialize(HINSTANCE instance)
{
	GameWindow::Initialize(instance);
	GameWIC::Initialize();
	GameInput::Initialize();
	GameTimer::Initialize();
	SceneManager::Initialize();
}

void GameBase::Release()
{
	SceneManager::Release();
	GameTimer::Release();
	GameInput::Release();
	GameWIC::Release();
	GameWindow::Release();
}

void GameBase::Run()
{
	while (s_loop)
	{
		GameWindow::Update();
		GameInput::Update();
		GameTimer::Update();

		if (SceneManager::Update())
			continue;

		// Render
		Render();
	}
}

void GameBase::Render()
{
	GameWindow::BeginDraw();
	SceneManager::Render();
	
	// End Draw
	GameWindow::EndDraw();
}

namespace GameUI
{
	void Exit()
	{
		GameBase::Exit();
	}
}