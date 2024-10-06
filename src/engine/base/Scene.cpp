#include "Scene.h"
#include "../render/Renderer.h"
#include "renderproperties.h"
#include "gameobject.h"
#include <iostream>
#include "../physics/screen_raycast_handler.h"
Scene::Scene()
{
	GameObjects = std::vector<GameObject*>(GAMEOBJECT_COUNT);
}

void Scene::Update()
{
	ScreenRaycastHandler::GetInstance().Colliders = &Colliders;
	for (int i = 0; i < GameObjects.size(); i++)
	{
		if(GameObjects[i] != nullptr)
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
			RenderProperties* info = go->GetComponent<RenderProperties>();

			if (info != nullptr){
				renderer->Render(info, go->Transform);
			}
		}
	}
}

void Scene::AddGameObject(GameObject* go)
{
	for (int i = 0; i < GameObjects.size(); i++)
	{
		if (GameObjects[i] == nullptr)
		{
			GameObjects[i] = go;
			return;
		}
	}
	GameObjects.push_back(go);
}