#include <iostream>
#include "CreatureBehaviour.h"
#include "../prefab/Creature.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "../../engine/timer.h"
#include "../../engine/input/input.h"
#include "PathFinderBehaviour.h"
#include "../../engine/easing.h"
#include "GridBehaviour.h"
#include <vector>
void CreatureBehaviour::Start() {
    pathFinder = gameObject->GetComponent<PathFinderBehaviour>();
    FindNearestTarget();
}

void CreatureBehaviour::Update() {
    auto time = Timer::getInstance().getElapsedTime();
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();
    
    if (time - moveTimer > moveInterval)
    {
        moveTimer = time;
        auto pair = pathFinder->GetNextNode();
        if (pair != std::make_pair(-1, -1))
        {
            auto x = pair.first - parentTile->x;
            auto y = pair.second - parentTile->y;
            Move(x, y);
        }
       
    }
    if (m_isMovingAnimation) {
        double dt = Timer::getInstance().getElapsedTime() - m_startedMovingAt;

        if (dt < m_animationDuration) 
        {
            this->gameObject->Transform->position = Vector3::lerp(m_startPosition, m_endPosition, easeInOutBack(dt / m_animationDuration));
        }
        else
        {
            m_isMovingAnimation = false;
        }
    }
}


void CreatureBehaviour::Move(int x, int y) {
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();
    auto nextParent = parentTile->GetNeighbour(x, y);
    
    parentTile->RemoveGridObject(this);
    nextParent->AddGridObject(this);
    parentTile = nextParent;
    m_startPosition = this->gameObject->Transform->position;
    m_endPosition = parentTile->gameObject->Transform->position;
    this->gameObject->Transform->position = parentTile->gameObject->Transform->position;
    m_isMovingAnimation = true;
    m_startedMovingAt = Timer::getInstance().getElapsedTime();
}

void CreatureBehaviour::FindNearestTarget()
{
    auto parentTile = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();
    auto targets = gameObject->Transform->GetParent()->GetParent()->gameObject->GetComponent<GridBehaviour>()->GetTargetTiles();
    std::vector<std::vector<std::pair<int, int>>> paths;
    for (auto target : targets)
    {
        paths.push_back(pathFinder->FindPath({ parentTile->x , parentTile->y }, target));
    }
    int min = INT_MAX;
    int index = -1;
    for (int i = 0; i < paths.size(); i++)
    {
        if (paths[i].size() < min)
        {
			min = paths[i].size();
			index = i;
		}
	}

    pathFinder->currentPath = paths[index];
}

void CreatureBehaviour::OnGridChanged()
{
    FindNearestTarget();
}

void CreatureBehaviour::OnDestroy() {
    std::cout << "CreatureBehaviour OnDestroy" << std::endl;
}