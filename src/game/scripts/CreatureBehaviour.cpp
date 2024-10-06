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
    auto nextParent = ParentTile->GetNeighbour(x, y);
    ParentTile->RemoveGridObject(this);
    nextParent->AddGridObject(this);
    ParentTile = nextParent;
    this->gameObject->Transform->position = ParentTile->gameObject->Transform->position;
}

void CreatureBehaviour::OnDestroy() {
    std::cout << "CreatureBehaviour OnDestroy" << std::endl;
}