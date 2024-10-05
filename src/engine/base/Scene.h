#pragma once
#include "gameobject.h"
#include "../physics/collider.h"

#define GAMEOBJECT_COUNT 256
#define COLLIDER_COUNT 256

class Scene
{
public:
	Scene();
	~Scene() = default;
	void Update();
	void AddGameObject(GameObject* go);
	std::vector<GameObject*> GameObjects;
	std::vector<Collider*> Colliders;
};
