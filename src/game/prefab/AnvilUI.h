#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/AnvilUIBehaviour.h"
class AnvilUI : public GameObject
{
public:
    AnvilUI(transform t) : GameObject(t,
        { new RenderProperties(std::pair<float, float>(2.0f, 19.0f), new Material()),
          new AnvilUIBehaviour(),
        }
    ) {};
};