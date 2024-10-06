#pragma once
#include "GridObjectBehaviour.h"

class CreatureBehaviour : public GridObjectBehaviour {
    public:
        CreatureBehaviour() :  GridObjectBehaviour("CreatureBehaviour", GridObjectType::Agent) {};
        void Start();
        void Update();
        void OnDestroy();

        void Move(int x, int y);
};