#pragma once
#include "../../engine/base/behaviour.h"

class ExplosionBehaviour : public Behaviour
{
public:
    ExplosionBehaviour() : Behaviour("ExplosionBehaviour") {};
    void Update();
    void Start();
private:
    double m_startTime;
    static double m_duration;
};