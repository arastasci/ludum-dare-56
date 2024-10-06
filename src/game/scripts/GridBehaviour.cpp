#include <iostream>
#include "GridBehaviour.h"
#include "../prefab/Grid.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../prefab/Castle.h"
#include "../prefab/Creature.h"
#include "../prefab/Obstacle.h"
#include "../prefab/Anvil.h"

void GridBehaviour::Awake()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            this->createTile(i, j);
        }
    }

    CreateObjectAtTile<Castle>(9,9);
    CreateObjectAtTile<Creature>(10, 10);
    CreateObjectAtTile<Obstacle>(2, 2);

    std::cout << "Creating anvil" << std::endl;
    CreateObjectAtTile<Anvil>(3, 3);
}

void GridBehaviour::Start() {
    
}

void GridBehaviour::Update() {
}

void GridBehaviour::createTile(int x, int y)
{
    m_tiles[x][y] = GameObject::Instantiate<Tile>({{(float)x, (float)y, 0.0}, 
        {1.0, 1.0, 1.0}, 
        {0.0, 0.0, 0.0}}, gameObject->Transform)->GetComponent<TileBehaviour>();
    m_tiles[x][y]->Initialize(x, y, this);
}

void GridBehaviour::OnDestroy() {
}


TileBehaviour* GridBehaviour::GetTileAt(int x, int y)
{
    return m_tiles[x][y];
}

std::vector<std::pair<int, int>> GridBehaviour::GetTargetTiles()
{
    std::vector<std::pair<int,int>> targetTiles;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (m_tiles[i][j]->GetObjectsByType(GridObjectType::Target).size() > 0)
            {
				targetTiles.push_back({i, j});
            }
		}
	}
    return targetTiles;
}
