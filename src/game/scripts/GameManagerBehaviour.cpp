#include "GameManagerBehaviour.h"
#include "../../engine/base/gameobject.h"
#include "GridBehaviour.h"

GameManagerBehaviour* GameManagerBehaviour::instance = nullptr;
GameManagerBehaviour* GameManagerBehaviour::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameManagerBehaviour();
	}
	return instance;
}
void GameManagerBehaviour::Start()
{
}

void GameManagerBehaviour::Awake()
{
}

void GameManagerBehaviour::IncreaseEnemy()
{
	m_enemyCount++;
}
void GameManagerBehaviour::DecreaseEnemy()
{
	m_enemyCount--;
	if (m_enemyCount == 0)
	{
		EndGame(true);
	}
}

void GameManagerBehaviour::OnEnemyReachedTarget()
{
	m_lives--;
	if (m_lives <= 0)
	{
		EndGame(false);
	}
}

void GameManagerBehaviour::EndGame(bool won)
{
	if (won)
	{
		std::cout << "You won!" << std::endl;
	}
	else
	{
		std::cout << "You lost!" << std::endl;
	}
}


