#pragma once
#include "GridObjectBehaviour.h"
#include "PathFinderBehaviour.h"
class CreatureBehaviour : public GridObjectBehaviour {
    public:
        CreatureBehaviour() :  GridObjectBehaviour("CreatureBehaviour", GridObjectType::Agent) {};
        void Start();
        void Update();
        void OnDestroy();
        void Move(int x, int y);
        PathFinderBehaviour* pathFinder;
        float moveInterval = 1.0f;
        float moveTimer = 0.0f;
};