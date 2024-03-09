#include "SceneManager.h"
#include "Scene.h"

Scene* SceneManager::s_scene = nullptr;
Scene* SceneManager::s_loaded = nullptr;

class TempScene : public Scene
{
public:
    TempScene() {}

private:
    virtual ~TempScene() final {}
    virtual void Initialize() final {}
};

void SceneManager::Initialize()
{
    s_scene = new TempScene;
}

void SceneManager::Release()
{
    s_scene->Release();

    if (s_loaded)
        s_loaded->Release();
}

bool SceneManager::Update()
{
    if (LoadScene())
        return true;

    s_scene->Update();

    return false;
}

void SceneManager::Render()
{
    s_scene->Render();
}

bool SceneManager::LoadScene()
{
    if (!s_loaded)
        return false;

    s_scene->Release();

    s_scene = s_loaded;
    s_scene->Initialize();

    s_loaded = nullptr;

    return true;
}

void SceneManager::LoadScene(Scene* scene)
{
    if (s_loaded)
        s_loaded->Release();

    if (scene)
    {
        s_loaded = scene;
        s_loaded->AddRef();
    }
}

namespace GameUI
{
    void LoadScene(Scene* scene)
    {
        SceneManager::LoadScene(scene);
    }
}