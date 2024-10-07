#include "SledgehammerUIBehaviour.h"
#include "../../engine/base/gameobject.h"
void SledgehammerUIBehaviour::Start()
{
	m_info = gameObject->GetComponent<RenderProperties>();
	m_gameManager = GameManagerBehaviour::GetInstance();
}

void SledgehammerUIBehaviour::Update()
{
	m_info->material->floatMap["percentage"] = (Timer::getInstance().getElapsedTime() - m_gameManager->GetSledgehammerLastUsedAt()) / m_gameManager->GetSledgehammerCooldownDuration();
}
