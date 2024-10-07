#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/renderproperties.h"

class GameEndUIBehaviour : public Behaviour
{
public:
	GameEndUIBehaviour() : Behaviour("GameEndUIBehaviour") {};
	void Start();
	void Initialize(bool won);
	void Update();

private:
	std::vector<std::pair<float, float>> texCoords = { {7.0f, 22.0f}, {0.0f, 22.0f} };
	RenderProperties* info;
	bool m_initialized;
	Vector3 m_initialScale;
	bool m_isAboutToBeDisposed;
	double m_initializationTime;
	const double m_scaleIncreaseDuration = 11.f;

};

