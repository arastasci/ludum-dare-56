#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/gameobject.h"
#include "GameManagerBehaviour.h"
class Enemy : public Behaviour
{
public:
	Enemy() : Behaviour("Enemy") {};
	void Start() override
	{
		GameManagerBehaviour::GetInstance()->IncreaseEnemy();
	}
	void OnDestroy() override
	{
		GameManagerBehaviour::GetInstance()->DecreaseEnemy();
	}

};