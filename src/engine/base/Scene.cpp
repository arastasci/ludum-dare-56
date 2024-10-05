#include "Scene.h"
#include "../render/Renderer.h"

void Scene::Update()
{
	// PhysicsSolver::Update(Colliders);
	for (int i = 0; i < GameObjects.size(); i++)
	{
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
			renderer->Render(go->RenderInfo, *go->Transform);
		}
	}
}

void Scene::AddGameObject(gameobject* go)
{
}