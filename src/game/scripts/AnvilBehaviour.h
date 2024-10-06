#pragma once
#include "../../engine/base/behaviour.h"
#include "GridObjectBehaviour.h"

class AnvilBehaviour : public GridObjectBehaviour{
    public:
        AnvilBehaviour() : GridObjectBehaviour("AnvilBehaviour", GridObjectType::Target) {};
        void Update();
        void Start();

    private:
        double m_createdAt;
        Vector3 m_landsTo;
        static double animationDuration;
};