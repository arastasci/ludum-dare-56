#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/ParticleBehaviour.h"

class Particle : public GameObject
{
public:
    Particle(transform t) : GameObject(t,
                                       {
                                           new ParticleBehaviour(),
                                           new RenderProperties(std::pair<float, float>(2.0f, 11.0f)),
                                       }) {};
};