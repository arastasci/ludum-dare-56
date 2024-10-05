#pragma once
#include "object.h"

class Scene;
class Component;
class transform;
class Behaviour;
class gameobject : public Object
{
public:
	gameobject();
	gameobject(transform t);
	~gameobject() = default;
	static void Instantiate(gameobject go, transform t);
	void AddComponent(Component* comp);
	Component* GetComponent(const char* name) const;
	void RemoveComponent(const char* name);
	void Update();

	transform* Transform;
	Scene* Scene;
	void DestroyImmediate();
protected:
private:
	std::vector<Component*> m_components;
	std::vector<Behaviour*> m_behaviours;
};

