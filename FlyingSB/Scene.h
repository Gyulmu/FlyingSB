#pragma once
#include "RefCount.h"
#include <list>

class GameObject;

class Scene : public RefCount
{
protected:
	Scene() {}
	virtual ~Scene() = 0;

public:
	virtual void Initialize() = 0;
	void Update();
	void Render();

protected: 
	
	// List�� �߰��� �� GameObject::Initialize �Լ��� ȣ��˴ϴ�.
	void AddGameObjectToList(GameObject* object);

private:
	std::list<GameObject*> m_object;
};