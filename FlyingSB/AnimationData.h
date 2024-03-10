#pragma once

class Animation;

class AnimationData
{
public:
	static void Initialize();
	static void Release();

	static Animation* GetAnimation() { return s_animation; }

private:
	static Animation* s_animation;
};