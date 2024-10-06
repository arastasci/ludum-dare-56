#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/CreatureBehaviour.h"
#include "../scripts/PathFinderBehaviour.h"
class Creature : public GameObject
{

public:
    Creature(transform t) : GameObject(t,
                                   {new RenderProperties(std::pair<float, float>(0.0f, 9.0f)),
                                    new PathFinderBehaviour(),
                                    new CreatureBehaviour()
                                   }
                                   ) {};
};