#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/LifeBehaviour.h"
class Life : public GameObject
{

public:
    Life(transform t) : GameObject(t,
        { new RenderProperties(std::pair<float, float>(0.0f, 22.0f)),
         new LifeBehaviour(),
        }
    ) {};
};