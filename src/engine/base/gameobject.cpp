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
	Transform->gameObject = this;
};

GameObject::GameObject(std::vector<Component*> components) : GameObject()
{
	for (Component* c : components)
	{
		this->AddComponent(c);
	}

	Transform->gameObject = this;
};

GameObject::GameObject(transform t, std::vector<Component*> components) : GameObject(t)
{
	for (Component* c : components)
	{
		this->AddComponent(c);
	}
	Transform->gameObject = this;
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
	comp->gameObject = this;
	
	m_components.push_back(comp);
	auto behaviour = dynamic_cast<Behaviour*>(comp);
	if(behaviour != nullptr)
	{
		m_behaviours.push_back(behaviour);
	}
	auto collider = dynamic_cast<Collider*>(comp);
	if (collider != nullptr)
	{
		Game::ActiveScene->Colliders.push_back(collider);
	}
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

void GameObject::Awake()
{
	if (m_awakened)
		return;
	m_awakened = true;
	for (auto i = 0; i < m_behaviours.size(); i++)
	{
		m_behaviours[i]->Awake();
	}
}

void GameObject::Start()
{
	for (Behaviour* b : m_behaviours)
	{
		b->Start();
	}
}

std::vector<Component*> GameObject::GetComponents()
{
	return m_components;
}
