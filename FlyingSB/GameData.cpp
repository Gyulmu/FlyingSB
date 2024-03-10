#include "GameData.h"
#include "AnimationData.h"
#include "BitmapData.h"

void GameData::Initialize()
{
	BitmapData::Initialize();
	AnimationData::Initialize();
}

void GameData::Release()
{
	AnimationData::Release();
	BitmapData::Release();
}
