#include "gameobject.h"
#include "Game.h"

gameobject::gameobject()
{
	Game::ActiveScene->AddGameObject(this);
	Transform = new transform();
}

gameobject::gameobject(transform& t)
{
	Game::ActiveScene->AddGameObject(this);
	Transform = new transform(t);

}

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