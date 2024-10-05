#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"

class Tile : public GameObject
{

public:
    Tile(transform t) : GameObject(t,
                                   {new RenderProperties(std::pair<float, float>(1.0f, 4.0f))}
                                   ) {};
};