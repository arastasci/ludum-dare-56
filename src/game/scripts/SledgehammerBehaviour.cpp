#include "SledgehammerBehaviour.h"
#include "../../engine/easing.h"
#include "../../engine/timer.h"
#include <iostream>
#include "Enemy.h"

double SledgehammerBehaviour::animationDuration = 0.2f;

void SledgehammerBehaviour::Start() {
    std::cout << "AnvilBehaviour Start" << std::endl;
    m_createdAt = Timer::getInstance().getElapsedTime();
    m_landsTo = this->gameObject->Transform->position;
    m_isFalling = true;

    auto tileBehaviour = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();

    auto agents = tileBehaviour->GetObjectsByType(GridObjectType::Agent);

    for (auto agent : agents) {
        if (agent->gameObject->GetComponent<Enemy>() != nullptr)
        {
            tileBehaviour->RemoveGridObject(agent);
            agent->gameObject->Destroy();
        }

    }
}

void SledgehammerBehaviour::Dispose()
{
    m_landedAt = Timer::getInstance().getElapsedTime();
    this->gameObject->Transform->rotation.z = 180.f;
    m_isFalling = false;
}

void SledgehammerBehaviour::Update() {
    if (m_isFalling)
    {
        double dt = Timer::getInstance().getElapsedTime() - m_createdAt;

        if (dt > animationDuration) {
            Dispose();
            return;
        }

        auto t = dt / animationDuration;
        float landY = m_landsTo.y;
        this->gameObject->Transform->position.y = 1 + landY - easeInBounce(t);


        this->gameObject->Transform->rotation.z = m_initialRotation + (m_targetRotation - m_initialRotation) * t;
    }
    else
    {
        double dt = Timer::getInstance().getElapsedTime() - m_landedAt;
        if (dt > m_stayingStillDuration)
        {
            gameObject->Destroy();
        }
    }
   
}