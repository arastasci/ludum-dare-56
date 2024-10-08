#pragma once
#include "Game.h"
#include "object.h"
#include "../render/Renderer.h"
#include <type_traits>
#include <iostream>

class Scene;
class Component;
class transform;
class Behaviour;

class GameObject : public Object
{
public:
	GameObject();
	GameObject(transform t);
	GameObject(transform t, transform* parent);
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

	template <typename T,typename = std::enable_if_t<std::is_base_of_v<GameObject, T>>>
	static T* Instantiate(transform t, transform* parent)
	{
		T* go = new T(t);
		parent->AddChild(go->Transform);
		Game::ActiveScene->AddGameObject(go);

		return go;
	}

	void AddComponent(Component* comp);

	template <typename T,typename = std::enable_if_t<std::is_base_of_v<Component, T>>>
	T* GetComponent() const
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			T* component = dynamic_cast<T*>(m_components[i]);
			
			if (component)
			{
				return component;
			}
		}

		return nullptr;
	}

	void RemoveComponent(const char* name);
	void Update();
	void Awake();
	void Start();
	std::vector<Component*> GetComponents();

	transform* Transform;
	Scene* Scene;
	void DestroyImmediate();
	void OnRaycastHit();
	bool m_awakened = false;
protected:
	std::vector<Component*> m_components;
	std::vector<Behaviour*> m_behaviours;
};

