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

    CreateObjectAtTile<Castle>(1,6);
    CreateObjectAtTile<Creature>(10, 10);
    CreateObjectAtTile<Obstacle>(2, 2);
    CreateObjectAtTile<Obstacle>(8, 8);
    CreateObjectAtTile<Obstacle>(8, 7);
    CreateObjectAtTile<Obstacle>(8, 6);
    CreateObjectAtTile<Obstacle>(8, 5);
    CreateObjectAtTile<Obstacle>(8, 4);
    CreateObjectAtTile<Obstacle>(8, 3);
    CreateObjectAtTile<Obstacle>(8, 2);
    CreateObjectAtTile<Obstacle>(8, 9);
    CreateObjectAtTile<Obstacle>(8, 10);

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

void GridBehaviour::OnGridChanged()
{
    if (!Game::GetInstance()->m_awakened)
        return;
    for (auto agent : m_agents)
    {
        agent->OnGridChanged();
    }
}

void GridBehaviour::RemoveAgent(AgentBehaviour* a)
{
    // erase from m_agents
    m_agents.erase(std::remove(m_agents.begin(), m_agents.end(), a), m_agents.end());
}
