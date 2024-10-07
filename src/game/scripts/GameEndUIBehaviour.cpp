#include "GameEndUIBehaviour.h"
#include "../../engine/base/gameobject.h"
#include "GameManagerBehaviour.h"
void GameEndUIBehaviour::Start()
{
	info = gameObject->GetComponent<RenderProperties>();
	bool won = GameManagerBehaviour::GetInstance()->GetWonOrLost();
	if (won)
	{
		info->SetTextureCoords(texCoords[0]);
	}
	else
	{
		info->SetTextureCoords(texCoords[1]);
	}
	info->SetIsEnabled(true);
	m_initialized = true;
	m_initialScale = gameObject->Transform->scale;
	m_initializationTime = Timer::getInstance().getElapsedTime();
}

void GameEndUIBehaviour::Initialize(bool won)
{
	
}

void GameEndUIBehaviour::Update()
{
	if (m_initialized)
	{
		double t = Timer::getInstance().getElapsedTime() - m_initializationTime;
		if (t < m_scaleIncreaseDuration)
		{
			gameObject->Transform->scale = m_initialScale * (t);
		}
	}
}
