#include "Scene.h"
#include "../render/Renderer.h"
#include "renderinfo.h"

Scene::Scene()
{
	GameObjects = std::vector<GameObject*>(GAMEOBJECT_COUNT);
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

	Renderer *renderer = Renderer::GetInstance();
	for (auto go : GameObjects)
	{
		if (go != nullptr)
		{
			// If gameobject has a renderinfo, render it
			RenderInfo* info = dynamic_cast<RenderInfo*>(go->GetComponent("RenderInfo"));

			if (info != nullptr)
				renderer->Render(info, go->Transform);
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