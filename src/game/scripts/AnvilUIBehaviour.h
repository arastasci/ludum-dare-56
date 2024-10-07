#pragma once
#include "../../engine/base/behaviour.h"

class AnvilUIBehaviour : public Behaviour
{
public:
	AnvilUIBehaviour() : Behaviour("AnvilUIBehaviour") {};
	void Start();
	void Update();
	void Dispose();

private:
	bool m_isAboutToBeDisposed;
	float m_disposalInterval = 0.1f;
	bool m_shouldRender = true;
	float m_disposalTimer;
	float m_disposalDuration = 0.7f;
	float m_disposalStart;
};

