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

	static void Activate(bool activate);

private:
	static void UpdateDefault();
	static void UpdateInactivate();

private:
	struct KeyState;
	static std::vector<KeyState*> s_input;
	static void (*s_update)();
};