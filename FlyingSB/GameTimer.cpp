#include "GameTimer.h"

std::chrono::steady_clock::time_point GameTimer::s_time;
std::chrono::duration<float> GameTimer::s_duration;

void GameTimer::Initialize()
{
	s_time = std::chrono::steady_clock::now();
}

void GameTimer::Release()
{
}

void GameTimer::Update()
{
	std::chrono::steady_clock::time_point time =
		std::chrono::steady_clock::now();

	s_duration = time - s_time;
	s_time = time;
}

namespace GameUI
{
	float Duration()
	{
		return GameTimer::Duration();
	}
}