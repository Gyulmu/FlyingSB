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

private:
	std::list<GameObject*> m_object;

protected:
	template<typename T>
	T* Create()
	{
		T* object = new T;
		object->AddRef();
		((GameObject*)object)->Initialize();
		m_object.emplace_back(object);
		return object;
	}
};