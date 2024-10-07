#pragma once
#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/SledgehammerBehaviour.h"

class Sledgehammer : public GameObject
{
public:
    Sledgehammer(transform t) : GameObject(t,
        { new RenderProperties(std::pair<float, float>(9.0f,9.0f)),
         new SledgehammerBehaviour(),
        }
    ) {};
};