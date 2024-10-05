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
	void AddGameObject(gameobject* go);
	std::vector<gameobject*> GameObjects;
	std::vector<collider*> Colliders;
};
