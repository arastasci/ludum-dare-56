#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/GameEndUIBehaviour.h"
class GameEndUI : public GameObject
{
public:
    GameEndUI(transform t) : GameObject(t,
        { new RenderProperties(std::pair<float, float>(9.0f,22.0f), new Material()),
          new GameEndUIBehaviour(),
        }
    ) {};
};