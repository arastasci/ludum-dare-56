#pragma once
#include "../../engine/base/behaviour.h"

class CastleBehaviour : public Behaviour {
    public:
        CastleBehaviour() : Behaviour("CastleBehaviour") {};
        void Start();
        void Update();
        void OnDestroy();
};