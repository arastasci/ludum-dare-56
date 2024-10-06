#pragma once
#include "../physics/collider.h"

class GameObject;
class Component;
#define GAMEOBJECT_COUNT 256
#define COLLIDER_COUNT 256

class Scene
{
public:
	Scene();
	~Scene() = default;
	void Awake();
	void Update();
	void AddGameObject(GameObject* go);
	std::vector<GameObject*> GameObjects;
	std::vector<Collider*> Colliders;

	template <typename T, typename = std::enable_if_t<std::is_base_of_v<GameObject, T>>>
	T* FindGameObjectOfType()
	{
		for (auto g : GameObjects)
		{
			T* castedG = static_cast<T*>(g);
			if (castedG != nullptr)
				return castedG;
		}
		return nullptr;
	}

	template <typename T, typename = std::enable_if_t<std::is_base_of_v<Component, T>>>
	T* FindComponentOfType()
	{
		for (auto g : GameObjects)
		{
			auto components = g->GetComponents();
			for (int i = 0; i < components.size(); i++)
			{
				T* component = dynamic_cast<T*>(components[i]);

				if (component)
				{
					return component;
				}
			}
			
		}
		return nullptr;
	}

private:
	std::vector<GameObject*> m_awaitingToStart;
};
