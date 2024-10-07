#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/CastleBehaviour.h"

class Castle : public GameObject
{
public:
    Castle(transform t) : GameObject(t,
                                   {new RenderProperties(std::pair<float, float>(7.0f, 22.0f)),
                                    new CastleBehaviour(),
                                    }
                                   ) {};
};