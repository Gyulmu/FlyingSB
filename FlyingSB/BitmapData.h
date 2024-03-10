#pragma once
#include <d2d1.h>
#include <vector>
#include <map>
#include <string>

class BitmapData
{
public:
	static void Initialize();
	static void Release();

	static ID2D1Bitmap* Bitmap(const std::string& name, int idx);

private:
	static void SliceBitmap(ID2D1Bitmap* source, std::vector<ID2D1Bitmap*>& slice, int x_slice, int y_slice);

private:
	static std::map<std::string, std::vector<ID2D1Bitmap*>> s_bitmap;

};