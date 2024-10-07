#pragma once
#include "../../engine/base/behaviour.h"
#include "GridObjectBehaviour.h"
#include "Enemy.h"
class SledgehammerBehaviour : public GridObjectBehaviour
{
public:
    SledgehammerBehaviour() : GridObjectBehaviour("SledgehammerBehaviour", GridObjectType::Trap) {};
    void Update();
    void Start();

private:
    void Dispose();
    double m_landedAt;
    const double m_stayingStillDuration = 1.0f;
    double m_createdAt;
    Vector3 m_landsTo;
    static double animationDuration;
    float m_initialRotation;
    const float m_targetRotation = 180.f;
    bool m_isFalling;
};

