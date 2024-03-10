#include "Animator.h"
#include "Animation.h"
#include "AnimationFrame.h"
#include "renderer_bitmap.h"
#include "GameUI.h"

Animator::Animator(renderer_bitmap* renderer) :
	m_renderer(renderer)
{
}

Animator::~Animator()
{
	if (m_animation)
		m_animation->Release();
}

void Animator::Update()
{
	if (m_state == State::Stop ||
		m_type == PlayType::None)
		return;

	m_duration += GameUI::Duration();

	while (m_duration > m_frames[m_frameIdx]->duration)
	{
		m_duration -= m_frames[m_frameIdx]->duration;
		++m_frameIdx;

		if (m_frameIdx == m_frames.size())
		{
			switch (m_type)
			{
			case Animator::PlayType::None:
				m_duration = 0.f;
				m_frameIdx = 0;
				m_state = State::Stop;
				return;
				
			case Animator::PlayType::Once:
				m_duration = 0.f;
				m_frameIdx = 0;
				m_state = State::Stop;
				return;

			case Animator::PlayType::Repeat:
				m_frameIdx = 0;
				break;

			default:
				m_frameIdx = 0;
				return;
			}
		}
	}
}

void Animator::SetAnimation(Animation* animation)
{
	if (m_animation)
		m_animation->Release();

	m_animation = animation;
	m_animation->AddRef();
	m_frames = m_animation->Frames();

	m_frameIdx = 0;
	m_duration = 0.f;
}

void Animator::SetPlayType(PlayType type)
{
	m_type = type;
}

void Animator::Play()
{
	m_state = State::Play;
}

void Animator::Stop()
{
	m_state = State::Stop;
}

void Animator::Pause()
{
	m_state = State::Stop;
}

ID2D1Bitmap* Animator::GetBitmapFromFrame()
{
	return m_frames[m_frameIdx]->bitmap;
}
