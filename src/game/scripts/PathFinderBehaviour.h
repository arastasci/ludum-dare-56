#pragma once
#include "../../engine/base/behaviour.h"
#include "GridObjectBehaviour.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <utility>
class GameObject;
class PathFinderBehaviour : public Behaviour
{
public:
	PathFinderBehaviour();
	void Start() override;
	void Update() override {};
	void Initialize();
	std::vector<std::pair<int, int>> FindPath(std::pair<int, int> start, std::pair<int, int> goal);
	std::vector<std::pair<int, int>> aStar(TileBehaviour* startTile, std::pair<int, int> start, std::pair<int, int> goal);
	void OnDestroy() override {};
	GridObjectBehaviour* gridObjectBehaviour;
	std::vector<std::pair<int, int>> currentPath;
	int currentNodeIndex;
};

