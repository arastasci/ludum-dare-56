#include "gameobject.h"
#include "Game.h"
#include "transform.h"
#include "behaviour.h"

void GameObject::Instantiate(GameObject go, transform t)
{
	GameObject* newGo = new GameObject(t);
	for (Component* c : go.m_components)
	{
		newGo->AddComponent(c);
	}
	Game::ActiveScene->AddGameObject(newGo);
}
GameObject::GameObject()
{
	m_components = std::vector<Component*>(0);
	m_behaviours = std::vector<Behaviour*>(0);
}
GameObject::GameObject(transform t) : GameObject()
{
	Transform = new transform(t);
};

void GameObject::DestroyImmediate()
{
	for(Component * c : m_components)
	{
		auto behaviour = dynamic_cast<Behaviour*>(c);
		if (behaviour != nullptr)
		{
			behaviour->OnDestroy();
		}
		free(c);
	}

	Transform->DestroyImmediate();
	free(Transform);
}

void GameObject::AddComponent(Component* comp)
{
	comp->GameObject = this;
	
	m_components.push_back(comp);
	auto behaviour = dynamic_cast<Behaviour*>(comp);
	if(behaviour != nullptr)
	{
		behaviour->Start();
		m_behaviours.push_back(behaviour);
	}
	auto collider = dynamic_cast<Collider*>(comp);
	if (collider != nullptr)
	{
		Game::ActiveScene->Colliders.push_back(collider);
	}
}

Component* GameObject::GetComponent(const char* name) const
{
	for (int i = 0; i < m_components.size(); i++)
	{
		if (m_components[i]->name == name)
		{
			return m_components[i];
		}
	}
	return nullptr;
}

void GameObject::RemoveComponent(const char* name)
{
	for (int i = 0; i < m_components.size(); i++)
	{
		if (m_components[i]->name == name)
		{
			Component* c = m_components[i];
			m_components.erase(m_components.begin() + i);
			free(c);
			return;
		}
	}
}

void GameObject::Update()
{
	for (Behaviour* b : m_behaviours)
	{
		b->Update();
	}
}

