#pragma once
#include "../../engine/base/gameobject.h"
#include "../scripts/BombBehaviour.h"

class Bomb : public GameObject
{   
public:
    Bomb(transform t) : GameObject(t,
                                        {new RenderProperties(std::pair<float, float>(0.0f, 25.0f)),
                                         new BombBehaviour()}
                             ) {};
};