#include "Scene.h"

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
}

void Scene::AddGameObject(gameobject* go)
{
}