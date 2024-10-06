#include "BombBehaviour.h"
#include "../prefab/Explosion.h"

double BombBehaviour::m_duration = 3.0;

void BombBehaviour::Start()
{
    m_startTime = Timer::getInstance().getElapsedTime();
}

void BombBehaviour::Update()
{
    double dt = Timer::getInstance().getElapsedTime() - m_startTime;

    if (dt > m_duration)
    {
        transform  explosionTransform = {
            gameObject->Transform->position,
            {5.0, 5.0, 1.0},
            {0.0, 0.0, 0.0}
        };
        GameObject::Instantiate<Explosion>(explosionTransform);
     
        gameObject->Destroy();
    }
}