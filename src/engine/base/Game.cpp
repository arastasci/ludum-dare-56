#include "Game.h"

void Game::Update()
{
	ActiveScene->Update();
}

void Game::AddScene(Scene* scene)
{
	m_scenes.push_back(scene);
}

void Game::RemoveScene(Scene* scene)
{
	for (int i = 0; i < m_scenes.size(); i++)
	{
		if (m_scenes[i] == scene)
		{
			m_scenes.erase(m_scenes.begin() + i);
			return;
		}
	}
}

Scene* Game::ActiveScene = nullptr;