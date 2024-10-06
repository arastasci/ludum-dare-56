#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/transform.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
class GridBehaviour;

enum class GridObjectType
{
    Obstacle,
    Trap,
    Target,
    Agent,
};

class GridObjectBehaviour : public Behaviour
{
public:
    GridObjectBehaviour(const char* name, GridObjectType type) : Behaviour(name), Type(type) {};
    void Start() {};
    void Update() {};
    void OnDestroy(){};

    GridObjectType Type;
};