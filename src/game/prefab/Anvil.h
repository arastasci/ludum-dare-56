#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/AnvilBehaviour.h"

class Anvil : public GameObject
{
public:
    Anvil(transform t) : GameObject(t,
                                   {new RenderProperties(std::pair<float, float>(2.0f, 19.0f)),
                                    new AnvilBehaviour(),
                                    }
                                   ) {};
};