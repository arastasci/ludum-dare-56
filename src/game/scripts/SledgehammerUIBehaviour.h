#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/renderproperties.h"
class GameManagerBehaviour;
class SledgehammerUIBehaviour : public Behaviour
{
public:
	SledgehammerUIBehaviour() : Behaviour("SledgehammerUIBehaviour") {};
	void Start();
	void Update();
private:
	RenderProperties* m_info;
	GameManagerBehaviour* m_gameManager;
};

