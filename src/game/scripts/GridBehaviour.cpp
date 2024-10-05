#include <iostream>
#include "GridBehaviour.h"
#include "../prefab/Grid.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"


void GridBehaviour::Start() {
    for (int i = -5; i < 5; i++)
    {
        for (int j = -5; j < 5; j++)
        {
            transform t;
            t.position = {(float) i, (float) j, 0.0};
            GameObject::Instantiate<Tile>(t);
        }
    }
}

void GridBehaviour::Update() {
    std::cout << "GridBehaviour Update" << std::endl;
}

void GridBehaviour::OnDestroy() {
    std::cout << "GridBehaviour OnDestroy" << std::endl;
}