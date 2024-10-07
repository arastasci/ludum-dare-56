#include "ExplosionBehaviour.h"
#include "../../engine/base/renderproperties.h"
#include "../../engine/base/gameobject.h"

double ExplosionBehaviour::m_duration = 1.0;

void ExplosionBehaviour::Start()
{
    m_startTime = Timer::getInstance().getElapsedTime();
}

void ExplosionBehaviour::Update()
{
    double dt = Timer::getInstance().getElapsedTime() - m_startTime;

    if (dt > m_duration)
    {
        gameObject->Destroy();
    }

    int index = (int)(dt * 3 / m_duration);

    gameObject->GetComponent<RenderProperties>()->SetTextureCoords({index*3, 0});
}