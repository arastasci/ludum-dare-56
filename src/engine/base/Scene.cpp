#include "Scene.h"
#include "../render/Renderer.h"
#include "renderproperties.h"
#include "gameobject.h"
#include <iostream>
#include "../physics/screen_raycast_handler.h"
Scene::Scene()
{
	GameObjects = std::vector<GameObject *>(GAMEOBJECT_COUNT);
}

void Scene::Update()
{
	// Start gameobjects
	std::vector<GameObject *> m_awaitingToStartPrev = m_awaitingToStart;
	m_awaitingToStart = std::vector<GameObject *>();

	for (auto go : m_awaitingToStartPrev)
	{
		bool added = false;
		for (int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i] == nullptr)
			{
				GameObjects[i] = go;
				added = true;
			}
		}

		if(!added)
			GameObjects.push_back(go);

		go->Start();
	}

	ScreenRaycastHandler::GetInstance().Colliders = &Colliders;
	for (int i = 0; i < GameObjects.size(); i++)
	{
		if (GameObjects[i] != nullptr)
			GameObjects[i]->Update();
	}
	// TODO: remove destroyed objects or replace them when adding
	for (auto go : GameObjects)
	{
		if (go != nullptr && go->GetWillBeDestroyed())
		{
			go->DestroyImmediate();
			free(go);
		}
	}
	// destroy objects
	// for renderers, render

	Renderer *renderer = Renderer::GetInstance();
	for (auto go : GameObjects)
	{
		if (go != nullptr)
		{
			// If gameobject has a renderinfo, render it
			RenderProperties *info = go->GetComponent<RenderProperties>();

			if (info != nullptr)
			{
				renderer->Render(info, go->Transform);
			}
		}
	}
}

void Scene::AddGameObject(GameObject *go)
{
	m_awaitingToStart.push_back(go);
}