#include "Scene.h"
#include "GameObject.h"

Scene::~Scene()
{
	std::list<GameObject*>::iterator iter;
	std::list<GameObject*>::iterator iterEnd = m_object.end();

	for (iter = m_object.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Release();
	}
}

void Scene::Update()
{
	std::list<GameObject*>::iterator iter;
	std::list<GameObject*>::iterator iterEnd = m_object.end();

	for (iter = m_object.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Update();
	}
}

void Scene::Render()
{
	std::list<GameObject*>::iterator iter;
	std::list<GameObject*>::iterator iterEnd = m_object.end();

	for (iter = m_object.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render();
	}
}
