#include "GameManagerBehaviour.h"
#include "../../engine/base/gameobject.h"
#include "GridBehaviour.h"

GameManagerBehaviour* GameManagerBehaviour::instance = nullptr;
GameManagerBehaviour* GameManagerBehaviour::GetInstance()
{
	if (instance == nullptr)
	{
		auto b = Game::GetInstance()->ActiveScene->FindComponentOfType<GameManagerBehaviour>();
		if (b == nullptr)
		{
			std::cout << "This shouldnt' happen."  << std::endl;
			b = new GameManagerBehaviour();
		}
		instance = b;
	}
	return instance;
}
void GameManagerBehaviour::Start()
{
	for (int i = 0; i < m_lives; i++)
	{
		m_livesUI.push_back(GameObject::Instantiate<Life>({
			{ 5.f + 4.0f * (i - 1) * 0.5f, 12.f, 0.0f },
			{ 1, 1, 1},
		{0, 0, 0} }
		));

	}
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
		endGame(true);
	}
}

void GameManagerBehaviour::OnEnemyReachedTarget()
{
	m_lives--;
	decreaseLife();
	if (m_lives <= 0)
	{
		endGame(false);
	}
}

void GameManagerBehaviour::OnSledgehammerUsed()
{
	m_sledgehammerLastUsedAt = Timer::getInstance().getElapsedTime();
}

bool GameManagerBehaviour::CanUseSledgehammer()
{
	return Timer::getInstance().getElapsedTime() - m_sledgehammerLastUsedAt > m_sledgehammerCooldownDuration;
}

double GameManagerBehaviour::GetSledgehammerLastUsedAt()
{
	return m_sledgehammerLastUsedAt;
}

double GameManagerBehaviour::GetSledgehammerCooldownDuration()
{
	return m_sledgehammerCooldownDuration;
}

void GameManagerBehaviour::endGame(bool won)
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

void GameManagerBehaviour::decreaseLife()
{
	if (m_livesUI.size() > 0)
	{
		m_livesUI[m_livesUI.size() - 1]->GetComponent<LifeBehaviour>()->Dispose();
		m_livesUI.pop_back();
	}
}


