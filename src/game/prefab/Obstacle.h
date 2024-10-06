#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"

class Obstacle : public GameObject
{
public:
    Obstacle(transform t) : GameObject({{0, 0, 0},
                                        {.7f, .7f, 1.0f},
                                        {0, 0, 0}},
                                       {
                                           new RenderProperties(std::pair<float, float>(3.0f, 5.0f)),
                                       }) {};
};