#pragma once
#include <d2d1.h>
#include <string>

class Animation;

namespace DataUI
{
	ID2D1Bitmap* Bitmap(const std::string& name, int idx);
	Animation* GetAnimation();

}