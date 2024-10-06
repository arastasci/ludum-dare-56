#include <iostream>
#include "CreatureBehaviour.h"
#include "../prefab/Creature.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../../engine/timer.h"

void CreatureBehaviour::Start() {}

void CreatureBehaviour::Update() {
    // maybe access timer from the game?
    this->gameObject->Transform->position.x += 0.001;
}

void CreatureBehaviour::OnDestroy() {
    std::cout << "CreatureBehaviour OnDestroy" << std::endl;
}