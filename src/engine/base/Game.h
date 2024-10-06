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
	static Game* GetInstance();
	void Initialize();
	void Awake();
	void AddScene(Scene* scene);
	void RemoveScene(Scene* scene);
	void Update();
	static Scene* ActiveScene;
private:
	static Game* instance;
	ScreenRaycastHandler* m_raycastHandler;
	bool m_awakened;
	std::vector<Scene*> m_scenes;
	Timer* m_timer;
	
};

