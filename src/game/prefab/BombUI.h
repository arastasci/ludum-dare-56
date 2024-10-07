#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/BombUIBehaviour.h"
class BombUI : public GameObject
{
public:
    BombUI(transform t) : GameObject(t,
        { new RenderProperties(std::pair<float, float>(0.0f,25.0f), new Material()),
          new BombUIBehaviour(),
        }
    ) {};
};