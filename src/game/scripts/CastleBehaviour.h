#pragma once
#include "../../engine/base/behaviour.h"
#include "GridObjectBehaviour.h"
class CastleBehaviour : public GridObjectBehaviour{
    public:
        CastleBehaviour() : GridObjectBehaviour("CastleBehaviour", GridObjectType::Target) {};
        void Start();
        void Update();
        void OnDestroy();
};