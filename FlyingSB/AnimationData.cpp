#include "AnimationData.h"
#include "Animation.h"
#include "AnimationFrame.h"
#include "BitmapData.h"

Animation* AnimationData::s_animation = nullptr;

void AnimationData::Initialize()
{
	s_animation = new Animation;
	std::vector<AnimationFrame*> frames;
	frames.resize(8);
	{   frames[0] = new AnimationFrame;
		frames[0]->bitmap = BitmapData::Bitmap("CMIRO00", 6);
		frames[0]->duration = 0.4f; }
	{	frames[1] = new AnimationFrame;
		frames[1]->bitmap = BitmapData::Bitmap("CMIRO00", 7);
		frames[1]->duration = 0.4f; }
	{	frames[2] = new AnimationFrame;
		frames[2]->bitmap = BitmapData::Bitmap("CMIRO00", 8);
		frames[2]->duration = 0.4f; }
	{	frames[3] = new AnimationFrame;
		frames[3]->bitmap = BitmapData::Bitmap("CMIRO00", 7);
		frames[3]->duration = 0.4f; }
	{	frames[4] = new AnimationFrame;
		frames[4]->bitmap = BitmapData::Bitmap("CMIRO00", 6);
		frames[4]->duration = 0.4f; }
	{	frames[5] = new AnimationFrame;
		frames[5]->bitmap = BitmapData::Bitmap("CMIRO00", 9);
		frames[5]->duration = 0.4f; }
	{	frames[6] = new AnimationFrame;
		frames[6]->bitmap = BitmapData::Bitmap("CMIRO00", 10);
		frames[6]->duration = 0.4f; }
	{	frames[7] = new AnimationFrame;
		frames[7]->bitmap = BitmapData::Bitmap("CMIRO00", 9);
		frames[7]->duration = 0.4f; }
	s_animation->Initialize(frames);
}

void AnimationData::Release()
{
	s_animation->Release();
}

namespace DataUI
{
	Animation* GetAnimation()
	{
		return AnimationData::GetAnimation();
	}
}