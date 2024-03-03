#include "SceneManager.h"
#include "Scene.h"

Scene* SceneManager::s_scene = nullptr;
Scene* SceneManager::s_loaded = nullptr;

void SceneManager::Initialize()
{
}

void SceneManager::Release()
{
    if (s_scene)
        s_scene->Release();

    if (s_loaded)
        s_loaded->Release();
}

bool SceneManager::Update()
{
    if (s_scene)
        s_scene->Update();

    return s_loaded;
}

void SceneManager::Render()
{
    if (s_scene)
        s_scene->Render();
}

void SceneManager::LoadScene()
{
    if (s_scene)
        s_scene->Release();

    s_scene = s_loaded;
    s_scene->Initialize();

    s_loaded = nullptr;
}

void SceneManager::LoadScene(Scene* scene)
{
    if (s_loaded)
        s_loaded->Release();

    s_loaded = scene;
    s_loaded->AddRef();
}

namespace GameUI
{
    void LoadScene(Scene* scene)
    {
        SceneManager::LoadScene(scene);
    }
}