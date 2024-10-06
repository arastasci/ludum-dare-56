#pragma once
#include "../../engine/base/gameobject.h"
#include "../../engine/base/renderproperties.h"
#include "../scripts/TileBehaviour.h"
#include "../../engine/physics/collider.h"

class Tile : public GameObject
{
public:
    Tile(transform t) : GameObject(t,
                                   {new RenderProperties(std::pair<float, float>(1.0f, 17.0f)),
                                    new TileBehaviour(),
                                    new Collider(Vector3(1.0f, 1.0f, 1.0f)),
                                   }
                                   ) {};
};