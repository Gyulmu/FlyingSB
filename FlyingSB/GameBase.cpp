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
		Sleep(10);
	}
}
