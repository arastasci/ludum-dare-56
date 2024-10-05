#pragma once
#include "object.h"
#include "../render/Renderer.h"

class Scene;
class Component;
class transform;
class Behaviour;
class GameObject : public Object
{
public:
	GameObject();
	GameObject(transform t);
	~GameObject() = default;
	static void Instantiate(GameObject go, transform t);
	void AddComponent(Component* comp);
	Component* GetComponent(const char* name) const;
	void RemoveComponent(const char* name);
	void Update();

	transform* Transform;
	Scene* Scene;
	void DestroyImmediate();

	renderinfo RenderInfo;

protected:
private:
	std::vector<Component*> m_components;
	std::vector<Behaviour*> m_behaviours;
};

