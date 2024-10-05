#pragma once
#include <vector>
#include "Scene.h"
#include "../timer.h"
#include "../physics/screen_raycast_handler.h"
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
	ScreenRaycastHandler* m_raycastHandler;
	std::vector<Scene*> m_scenes;
	Timer* m_timer;
	
};

