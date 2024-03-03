#pragma once
#include <vector>

class GameInput
{
public:
	static void Initialize();
	static void Release();
	static void Update();

	static bool Press(int key);
	static bool Down(int key);
	static bool Up(int key);

private:
	struct KeyState;
	static std::vector<KeyState*> s_input;
};