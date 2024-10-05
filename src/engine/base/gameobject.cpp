#include "Game.h"
#include "gameobject.h"
#include "transform.h"
#include "behaviour.h"
#include <iostream>

GameObject::GameObject(){};

GameObject::GameObject(transform t) : GameObject()
{
	std::cout << "Creating gameobject" << std::endl;
	Transform = new transform(t);
};

GameObject::GameObject(std::vector<Component*> components) : GameObject()
{
	for (Component* c : components)
	{
		this->AddComponent(c);
	}
};

GameObject::GameObject(transform t, std::vector<Component*> components) : GameObject(t)
{
	for (Component* c : components)
	{
		this->AddComponent(c);
	}
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

void GameObject::OnRaycastHit()
{
	for (Behaviour* b : m_behaviours)
	{
		b->OnRaycastHit();
	}
}

void GameObject::AddComponent(Component* comp)
{
	std::cout << "Adding component " << comp->name << std::endl;
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

