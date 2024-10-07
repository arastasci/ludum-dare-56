#pragma once
#include "../../engine/base/behaviour.h"
#include "../prefab/Life.h"
#include "../prefab/AnvilUI.h"

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
	void OnSledgehammerUsed();
	void OnAnvilUsed();

	bool CanUseSledgehammer();
	bool CanUseAnvil();
	double GetSledgehammerLastUsedAt();
	double GetSledgehammerCooldownDuration();
	
private:
	int m_enemyCount = 0;
	int m_lives = 3;
	int m_anvils = 3;
	std::vector<AnvilUI*> m_anvilUIs;
	const double m_sledgehammerCooldownDuration = 3.f;
	double m_sledgehammerLastUsedAt = -3.f;
	static GameManagerBehaviour* instance;
	std::vector<Life*> m_livesUI;
	void endGame(bool won);
	void decreaseLife();
	
};

