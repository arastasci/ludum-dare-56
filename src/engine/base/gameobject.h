#pragma once
#include "Game.h"
#include "object.h"
#include "../render/Renderer.h"
#include <type_traits>

class Scene;
class Component;
class transform;
class Behaviour;

class GameObject : public Object
{
public:
	GameObject();
	GameObject(transform t);
	GameObject(std::vector<Component*> components);
	GameObject(transform t, std::vector<Component*> components);

	~GameObject() = default;
	
	template <typename T,typename = std::enable_if_t<std::is_base_of_v<GameObject, T>>>
	static T* Instantiate(transform t)
	{
		T* go = new T(t);
		Game::ActiveScene->AddGameObject(go);

		return go;
	}

	void AddComponent(Component* comp);
	Component* GetComponent(const char* name) const;
	void RemoveComponent(const char* name);
	void Update();

	transform* Transform;
	Scene* Scene;
	void DestroyImmediate();

protected:
	std::vector<Component*> m_components;
	std::vector<Behaviour*> m_behaviours;
};

