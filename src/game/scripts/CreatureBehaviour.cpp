#include <iostream>
#include "CreatureBehaviour.h"
#include "../prefab/Creature.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../../engine/timer.h"
#include "../../engine/input/input.h"
#include "PathFinderBehaviour.h"

void CreatureBehaviour::Start() {
    pathFinder = gameObject->GetComponent<PathFinderBehaviour>();
}

void CreatureBehaviour::Update() {
    // maybe access timer from the game?
    //this->gameObject->Transform->position.x += 0.001;
    auto time = Timer::getInstance().getElapsedTime();
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();
    
    if (time - moveTimer > moveInterval && pathFinder->currentNodeIndex != pathFinder->currentPath.size())
    {
        moveTimer = time;
        int i = pathFinder->currentNodeIndex++;
        auto pair = pathFinder->currentPath[i];
        auto x = pair.first - parentTile->x;
        auto y = pair.second - parentTile->y;
        Move(x, y);
    }
}


void CreatureBehaviour::Move(int x, int y) {
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();
    auto nextParent = parentTile->GetNeighbour(x, y);
    
    parentTile->RemoveGridObject(this);
    nextParent->AddGridObject(this);
    parentTile = nextParent;
    this->gameObject->Transform->position = parentTile->gameObject->Transform->position;
}

void CreatureBehaviour::OnDestroy() {
    std::cout << "CreatureBehaviour OnDestroy" << std::endl;
}