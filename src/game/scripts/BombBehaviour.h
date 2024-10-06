#pragma once
#include "../../engine/base/behaviour.h"
#include "GridObjectBehaviour.h"

class BombBehaviour : public GridObjectBehaviour{
public:
    BombBehaviour() : GridObjectBehaviour("BombBehaviour", GridObjectType::Trap) {};

    void Start();
    void Update();

private:
    double m_startTime;
    static double m_duration;
};