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
	
	// List에 추가될 때 GameObject::Initialize 함수가 호출됩니다.
	void AddGameObjectToList(GameObject* object);

private:
	std::list<GameObject*> m_object;
};