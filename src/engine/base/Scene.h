#pragma once
#include "gameobject.h"
#include "../physics/collider.h"

class Scene
{
public:
	Scene();
	~Scene();
	void Start();
	void Update();
	void AddGameObject(gameobject* go);
	std::vector<gameobject*> GameObjects;
	std::vector<collider*> Colliders;
};
