#pragma once
#include "../../engine/base/behaviour.h"

class ParticleBehaviour : public Behaviour
{
public: 
	ParticleBehaviour() : Behaviour("ParticleBehaviour") {}
    void Update();
    void Start();
private:
    double m_createdAt;
    static double m_appearAfter;
};