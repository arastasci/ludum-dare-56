#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/SledgehammerUIBehaviour.h"
class SledgehammerUI : public GameObject
{
public:
    SledgehammerUI(transform t) : GameObject(t,
        { new RenderProperties(std::pair<float, float>(9.0f,9.0f), new Material("FillShader")),
          new SledgehammerUIBehaviour(),
        }
    ) {};
};