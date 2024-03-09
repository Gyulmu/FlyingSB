#pragma once

class Scene;

class SceneManager
{
public:
	static void Initialize();
	static void Release();
	static bool Update();
	static void Render();

	static void LoadScene(Scene* scene);

private:
	static bool LoadScene();

private:
	static Scene* s_scene;
	static Scene* s_loaded;
};