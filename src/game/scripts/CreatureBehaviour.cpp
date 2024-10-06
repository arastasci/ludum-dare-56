#include <iostream>
#include "CreatureBehaviour.h"
#include "../prefab/Creature.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../../engine/timer.h"
#include "../../engine/input/input.h"
void CreatureBehaviour::Start() {}

void CreatureBehaviour::Update() {
    // maybe access timer from the game?
    //this->gameObject->Transform->position.x += 0.001;
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