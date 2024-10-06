#include <iostream>
#include "GridBehaviour.h"
#include "../prefab/Grid.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../prefab/Castle.h"
#include "../prefab/Creature.h"
#include "../prefab/Obstacle.h"

void GridBehaviour::Start() {
    for (int i = -5; i < 6; i++)
    {
        for (int j = -5; j < 6; j++)
        {
            transform t;
            t.position = {(float) i, (float) j, 0.0};

            this->createObjectAtTile<Tile>(t);
        }
    }

    // Bu böyle olmayacak, tile coordinatı almalı ama uyumam gerek bunu sabah değiştirebiliriz.
    transform castleTransform = {
        {4.0, 4.0, 0.0}, 
        {1.0, 1.0, 1.0}, 
        {0.0, 0.0, 0.0}
    };

    this->createObjectAtTile<Castle>(castleTransform);

    transform creatureTransform = {
        {-4.0, -4.0, 0.0}, 
        {1.0, 1.0, 1.0}, 
        {0.0, 0.0, 0.0}
    };

    this->createObjectAtTile<Creature>(creatureTransform);

    transform obstacleTransform = {
        {0.0, 0.0, 0.0}, 
        {0.9f, 0.9f, 1.0f}, 
        {0.0, 0.0, 0.0}
    };
    this->createObjectAtTile<Obstacle>(obstacleTransform);
}

void GridBehaviour::Update() {
}

void GridBehaviour::OnDestroy() {
}