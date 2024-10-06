#pragma once
#include "../../engine/base/gameobject.h"
#include "../scripts/GridBehaviour.h"
#include "../scripts/StepCount.h"

class Grid : public GameObject
{

public:
    Grid(transform t) : GameObject(t, {
            new GridBehaviour(),
            new StepCount()
    }) {};
};