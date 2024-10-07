#pragma once
#include "AgentBehaviour.h"
#include "PathFinderBehaviour.h"
class CreatureBehaviour : public AgentBehaviour {
    public:
        CreatureBehaviour() :  AgentBehaviour("CreatureBehaviour") {};
        void Start();
        void Update();
        void OnDestroy();
        void Dispose();
        void OnGridChanged() override;
        void Move(int x, int y);
        void FindNearestTarget();
        PathFinderBehaviour* pathFinder;
        float moveInterval = 1.0f;
        float moveTimer = 0.0f;
        bool m_isMovingAnimation;
        float m_startedMovingAt;
        float m_animationDuration = 0.5f;
        Vector3 m_startPosition;
        Vector3 m_endPosition;
};