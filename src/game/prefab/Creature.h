#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/CreatureBehaviour.h"
#include "../scripts/PathFinderBehaviour.h"
#include "../scripts/Enemy.h"
class Creature : public GameObject
{

public:
    Creature(transform t) : GameObject(t,
                                   {new RenderProperties(std::pair<float, float>(0.0f, 22.0f)),
                                    new PathFinderBehaviour(),
                                    new CreatureBehaviour(),
                                    new Enemy(),
                                   }
                                   ) {};
};