#pragma once
#include <chrono>

class GameTimer
{
public:
	static void Initialize();
	static void Release();
	static void Update();

	static float Duration() { return s_duration.count(); }

private:
	static std::chrono::steady_clock::time_point s_time;
	static std::chrono::duration<float> s_duration;
};