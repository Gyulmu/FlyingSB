#include "GameBase.h"	
#include "GameWindow.h"

bool GameBase::s_loop = true;

void GameBase::Initialize(HINSTANCE instance)
{
	GameWindow::Initialize(instance);
}

void GameBase::Release()
{
	GameWindow::Release();
}

void GameBase::Run()
{
	while (s_loop)
	{
		GameWindow::Update();

		// Update 함수를 삽입해주세요.
		// ...

		// Render
		Render();
	}
}

void GameBase::Render()
{
	GameWindow::BeginDraw();

	// Render 함수를 삽입해주세요.
	// ...
	
	// End Draw
	GameWindow::EndDraw();
}
