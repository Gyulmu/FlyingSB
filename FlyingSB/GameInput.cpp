#include "GameInput.h"
#include <Windows.h>

std::vector<GameInput::KeyState*> GameInput::s_input;

struct GameInput::KeyState
{
    bool press = false;
    bool down = false;
    bool up = false;
};

void GameInput::Initialize()
{
    s_input.resize(256);

    for (int i = 0; i < 256; ++i)
        s_input[i] = new KeyState;
}

void GameInput::Release()
{
    for (int i = 0; i < 256; ++i)
        delete s_input[i];
}

void GameInput::Update()
{
    for (int i = 0; i < 256; ++i)
    {
        if (GetAsyncKeyState(i) & 0x8000)
        {
            if (!s_input[i]->down &&
                !s_input[i]->press)
                s_input[i]->down = true;

            else s_input[i]->down = false;

            s_input[i]->press = true;
        }

        else
        {
            if (!s_input[i]->up &&
                s_input[i]->press)
                s_input[i]->up = true;

            else s_input[i]->up = false;

            s_input[i]->press = false;
        }
    }
}

bool GameInput::Press(int key)
{
    return s_input[key]->press;
}

bool GameInput::Down(int key)
{
    return s_input[key]->down;
}

bool GameInput::Up(int key)
{
    return s_input[key]->up;
}

namespace GameUI
{
    bool KeyPress(int key) { return GameInput::Press(key); }
    bool KeyDown(int key) { return GameInput::Down(key); }
    bool KeyUp(int key) { return GameInput::Up(key); }
}