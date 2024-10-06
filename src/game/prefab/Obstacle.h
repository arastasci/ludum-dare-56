#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/ObstacleBehaviour.h"
class Obstacle : public GameObject
{
public:
    Obstacle(transform t) : GameObject(t,
                                       {
                                           new RenderProperties(std::pair<float, float>(3.0f, 18.0f)),
                                           new ObstacleBehaviour()
                                       }) {};
};