#include "gameobject.h"
#include "Game.h"
#include "transform.h"
#include "../render/Renderer.h"

gameobject::gameobject(transform& t, renderinfo& info)
{
	Game::ActiveScene->AddGameObject(this);
	Transform = new transform(t);
	RenderInfo = info;
};

void gameobject::DestroyImmediate()
{
	for(component * c : m_components)
	{
		free(c);
	}

	Transform->DestroyImmediate();
	free(Transform);
}

void gameobject::AddComponent(component* comp)
{
	comp->GameObject = this;
	m_components.push_back(comp);
}

void gameobject::RemoveComponent(const char* name)
{
	for (int i = 0; i < m_components.size(); i++)
	{
		if (m_components[i]->name == name)
		{
			component* c = m_components[i];
			m_components.erase(m_components.begin() + i);
			free(c);
			return;
		}
	}
}

void gameobject::Update()
{
}

void gameobject::Destroy()
{
}