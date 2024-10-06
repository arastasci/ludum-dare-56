#include <iostream>
#include "GridBehaviour.h"
#include "../prefab/Grid.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../prefab/Castle.h"
#include "../prefab/Creature.h"
#include "../prefab/Obstacle.h"
#include "../prefab/Anvil.h"

void GridBehaviour::Start() {
    for (int i = -5; i < 6; i++)
    {
        for (int j = -5; j < 6; j++)
        {
            this->createTile(i, j);
        }
    }

    createObjectAtTile<Castle>(0, 0);
    createObjectAtTile<Creature>(1, 1);
    createObjectAtTile<Obstacle>(-2, -2);
    createObjectAtTile<Anvil>(-3, -3);
}

void GridBehaviour::Update() {
}

void GridBehaviour::createTile(int x, int y)
{
    m_tiles[x + 5][y + 5] = GameObject::Instantiate<Tile>({{(float)x, (float)y, 0.0}, 
        {1.0, 1.0, 1.0}, 
        {0.0, 0.0, 0.0}})->GetComponent<TileBehaviour>();
    m_tiles[x + 5][y + 5]->Initialize(x, y, this);
}

void GridBehaviour::OnDestroy() {
}

TileBehaviour* GridBehaviour::GetTileAt(int x, int y)
{
    return m_tiles[x + 5][y + 5];
}
