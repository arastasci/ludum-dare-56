#pragma once
#include "../../engine/base/gameobject.h"
#include "../scripts/ExplosionBehaviour.h"

class Explosion : public GameObject
{
public:
    Explosion(transform t) : GameObject(t,
                                        {new RenderProperties(std::pair<float, float>(0.0f, 0.0f), std::pair<int, int>(3, 3)),
                                         new ExplosionBehaviour()}

                             ) {};
};