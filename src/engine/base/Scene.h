#pragma once
#include "../physics/collider.h"

class GameObject;

#define GAMEOBJECT_COUNT 256
#define COLLIDER_COUNT 256

class Scene
{
public:
	Scene();
	~Scene() = default;
	void Awake();
	void Update();
	void AddGameObject(GameObject* go);
	std::vector<GameObject*> GameObjects;
	std::vector<Collider*> Colliders;

private:
	std::vector<GameObject*> m_awaitingToStart;
	void startGameObject(GameObject* go);
};
