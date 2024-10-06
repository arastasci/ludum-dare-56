#pragma once
#include "../../engine/base/behaviour.h"

class CreatureBehaviour : public Behaviour {
    public:
        CreatureBehaviour() : Behaviour("CreatureBehaviour") {};
        void Start();
        void Update();
        void OnDestroy();
};