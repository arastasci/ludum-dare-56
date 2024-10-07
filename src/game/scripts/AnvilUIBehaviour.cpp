#include "AnvilUIBehaviour.h"
#include "../../engine/base/gameobject.h"
void AnvilUIBehaviour::Start()
{

}

void AnvilUIBehaviour::Update()
{
	if (m_isAboutToBeDisposed)
	{
		auto time = Timer::getInstance().getElapsedTime();
		if (time - m_disposalStart > m_disposalDuration)
		{
			m_isAboutToBeDisposed = false;
			gameObject->Destroy();
		}
		if (time - m_disposalTimer > m_disposalInterval)
		{
			m_disposalTimer = time;
			gameObject->GetComponent<RenderProperties>()->SetIsEnabled(m_shouldRender);
			m_shouldRender = !m_shouldRender;
		}
	}
}

void AnvilUIBehaviour::Dispose()
{
	m_isAboutToBeDisposed = true;
	m_disposalStart = Timer::getInstance().getElapsedTime();
}