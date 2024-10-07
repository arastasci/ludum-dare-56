#pragma once
#include "../../engine/base/behaviour.h"
#include "../prefab/Life.h"
#include "../prefab/AnvilUI.h"
#include "../prefab/BombUI.h"

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
	void OnBombUsed();

	bool CanUseSledgehammer();
	bool CanUseAnvil();
	bool CanUseBomb();
	double GetSledgehammerLastUsedAt();
	double GetSledgehammerCooldownDuration();
	
private:
	int m_enemyCount = 0;
	int m_lives = 3;
	int m_anvils = 3;
	int m_bombs = 1;
	std::vector<BombUI*> m_bombUIs;
	std::vector<AnvilUI*> m_anvilUIs;
	const double m_sledgehammerCooldownDuration = 3.f;
	double m_sledgehammerLastUsedAt = -3.f;
	static GameManagerBehaviour* instance;
	std::vector<Life*> m_livesUI;
	void endGame(bool won);
	void decreaseLife();
	
};

