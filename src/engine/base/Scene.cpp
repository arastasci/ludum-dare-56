#include "Scene.h"

Scene::Scene()
{
	GameObjects = std::vector<gameobject*>(GAMEOBJECT_COUNT);
}

void Scene::Update()
{
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
}

void Scene::AddGameObject(gameobject* go)
{
	for (int i = 0; i < GAMEOBJECT_COUNT; i++)
	{
		if (GameObjects[i] == nullptr)
		{
			GameObjects[i] = go;
			return;
		}
	}
	GameObjects.push_back(go);
}