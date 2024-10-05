#pragma once
#include <vector>
#include "Scene.h"
#include "../timer.h"
class Game
{
public:
	Game();
	~Game() = default;
	void Initialize();
	void AddScene(Scene* scene);
	void RemoveScene(Scene* scene);
	void Update();
	static Scene* ActiveScene;
private:
	std::vector<Scene*> m_scenes;
	Timer* m_timer;
};

