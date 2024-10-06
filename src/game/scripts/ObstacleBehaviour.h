#pragma once
#include "GridObjectBehaviour.h"

class ObstacleBehaviour : public GridObjectBehaviour
{
public: 
	ObstacleBehaviour() : GridObjectBehaviour("ObstacleBehaviour", GridObjectType::Obstacle) {}
};