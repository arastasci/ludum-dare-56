#pragma once
#include "../../engine/base/behaviour.h"

class GridBehaviour : public Behaviour {
    public:
        GridBehaviour() : Behaviour("GridBehaviour") {};
        void Start();
        void Update();
        void OnDestroy();
};