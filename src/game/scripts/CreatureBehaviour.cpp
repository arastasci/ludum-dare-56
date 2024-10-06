#include <iostream>
#include "CreatureBehaviour.h"
#include "../prefab/Creature.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../../engine/timer.h"
#include "../../engine/input/input.h"
#include "PathFinderBehaviour.h"
void CreatureBehaviour::Start() {}

void CreatureBehaviour::Update() {
    // maybe access timer from the game?
    //this->gameObject->Transform->position.x += 0.001;
    auto time = Timer::getInstance().getElapsedTime();
    if (time - moveTimer > moveInterval && pathFinder->currentNodeIndex != pathFinder->currentPath.size())
    {
        moveTimer = time;
        int i = pathFinder->currentNodeIndex++;
        auto pair = pathFinder->currentPath[i];
        auto x =  pair.first - ParentTile->x;
        auto y = pair.second - ParentTile->y;
        Move(x, y);
    }
}


void CreatureBehaviour::Move(int x, int y) {
    auto nextParent = ParentTile->GetNeighbour(x, y);
    ParentTile->RemoveGridObject(this);
    nextParent->AddGridObject(this);
    ParentTile = nextParent;
    this->gameObject->Transform->position = ParentTile->gameObject->Transform->position;
}

void CreatureBehaviour::OnDestroy() {
    std::cout << "CreatureBehaviour OnDestroy" << std::endl;
}

void CreatureBehaviour::Initialize(TileBehaviour* parentTile, GridBehaviour* gridBehaviour) 
{
    GridObjectBehaviour::Initialize(parentTile, gridBehaviour);
    pathFinder = gameObject->GetComponent<PathFinderBehaviour>();
    pathFinder->Initialize();
}
