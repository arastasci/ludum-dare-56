#pragma once
#include "../../engine/base/behaviour.h"
#include "../prefab/Life.h"

class GameManagerBehaviour : public Behaviour
{
public: 
	GameManagerBehaviour() : Behaviour("GameManagerBehaviour") {};

	static GameManagerBehaviour* GetInstance();
	void Start() override;
	void Awake() override;
	void IncreaseEnemy();
	void DecreaseEnemy();
	void OnEnemyReachedTarget();
private:
	int m_enemyCount = 0;
	int m_lives = 3;
	static GameManagerBehaviour* instance;
	std::vector<Life*> m_livesUI;
	void endGame(bool won);
	void decreaseLife();
	
};

