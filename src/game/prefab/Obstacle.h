#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"

class Obstacle : public GameObject
{
public:
    Obstacle(transform t) : GameObject(t,
                                   {new RenderProperties(std::pair<float, float>(3.0f, 5.0f)),
                                   }
                                   ) {};
};