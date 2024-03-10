#pragma once
#include "RefCount.h"
#include <d2d1.h>
#include <vector>

class renderer_bitmap;
class Animation;
struct AnimationFrame;

class Animator : public RefCount
{
public:
	Animator(renderer_bitmap* renderer);

private:
	virtual ~Animator() final;

public:
	enum class PlayType { None, Once, Repeat };
	void Update();
	void SetAnimation(Animation* animation);
	void SetPlayType(PlayType type);
	void Play();
	void Stop();
	void Pause();
	ID2D1Bitmap* GetBitmapFromFrame();


private:
	enum class State { Stop, Play };
	renderer_bitmap* m_renderer = nullptr;
	Animation* m_animation = nullptr;
	std::vector<AnimationFrame*> m_frames;
	PlayType m_type = PlayType::None;
	State m_state = State::Stop;
	float m_duration = 0.f;
	int   m_frameIdx = 0;
};