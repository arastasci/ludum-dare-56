#pragma once
#include "../../engine/base/behaviour.h"
class GameManagerBehaviour : public Behaviour
{
public: 
	GameManagerBehaviour() : Behaviour("GameManagerBehaviour") {};
	void Start() override;
	void Update() override;
	void OnDestroy() override;
	void Awake() override;
	void OnRaycastHit() override;
};

