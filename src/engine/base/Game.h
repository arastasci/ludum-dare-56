#pragma once
#include <vector>
#include "Scene.h"
class Game
{
public:
	Game();
	~Game() = default;
	void AddScene(Scene* scene);
	void RemoveScene(Scene* scene);
	void Update();
	static Scene* ActiveScene;
private:
	std::vector<Scene*> m_scenes;
};

