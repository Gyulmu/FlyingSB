#include "GameBase.h"

int WINAPI WinMain(
	_In_ HINSTANCE instance, 
    _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	GameBase::Initialize(instance);
	GameBase::Run();
	GameBase::Release();

	return 0;
}